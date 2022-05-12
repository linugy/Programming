### 1.元对象系统
#### 元对象系统提供
（1）信号槽机制（最重要的特性）
（2）动态属性系统
（3）运行时类型识别
#### 元对象的实现基于
（1）QObject类：作为使用元对象类的基类
（2）Q_OBJECT宏：用于启动元对象系统
（3）MOC（Meta-Object Compiler，元对象编译器）：为每个QObject子类提供必要的代码

#### qobject_cast
对QObject类执行类型转换，举例：
```
QObject *obj = new MyWidget;// 假设MyWidget基础自QWidget，并包含Q_OBJECT宏

QWidget *widget = qobject_cast<QWidget *>(obj);// 转QWidget，正常转换

MyWidget *myWidget = qobject_cast<MyWidget *>(obj);// 转MyWidget，正常转换

QLabel *label = qobject_cast<QLabel *>(obj);// 转QLabel，转换失败，label置为0
```

```
// 可以通过转换失败置为0的特点，来进行类型判断
if (QLabel *label = qobject_cast<QLabel *>(obj)) {
    label->setText(tr("Ping"));
} else if (QPushButton *button = qobject_cast<QPushButton *>(obj)) {
    button->setText(tr("Pong!"));
}
```

注意：
如果类继承自QObject，但是没有使用Q_OBJECT宏，那意味着类无法使用元对象系统的特性。所以建议所有的类继承自QObject，同时使用Q_OBJECT宏，不管是不是要使用元对象系统的特性。

### 2.信号槽
(1)号槽机制是类型安全的：信号和槽的参数总是匹配的（实际上槽的参数可以比信号少）。
(2)信号可以连接槽，信号可以连接信号（此时会立即发射第二个信号）

#### 信号：
信号发出后，槽会立即执行，除了使用queued connections（此时槽会稍后执行）
一个信号连接多个槽的时候，按connect的顺序，依次执行槽函数
信号不能在.cpp文件中实现，也没有返回值（为void）

#### 槽：
槽函数是普通的C++函数。然而，作为槽，它们可以被任何组件调用，不管其访问级别如何，通过信号槽连接。这意味着从任意类的实例发出的信号可以在不相关类的实例中调用私有槽。
注意：可以将插槽定义为虚拟的（virtual）

```
  #include <QObject>

  class Counter : public QObject
  {
      Q_OBJECT

  public:
      Counter() { m_value = 0; }

      int value() const { return m_value; }

  public slots:
      void setValue(int value);

  signals:
      void valueChanged(int newValue);

  private:
      int m_value;
  };
```

```
  void Counter::setValue(int value)
  {
      if (value != m_value) {
          m_value = value;
          emit valueChanged(value);
      }
  }
```

```
    Counter a, b;
    QObject::connect(&a, &Counter::valueChanged, &b, &Counter::setValue);

    a.setValue(12);     // a.value() == 12, b.value() == 12
    b.setValue(48);     // a.value() == 12, b.value() == 48
```

注意：
（1）默认情况下，对于建立的每个连接，都会发出一个信号；对于重复的连接，会发出两个信号。
（2）可以通过一个disconnect（）调用断开所有这些连接。如果传递Qt:：UniqueConnection类型，则只有在它不是重复的情况下才会建立连接。如果已经有一个重复的，连接将失败，connect将返回false

#### 信号槽连接方式：
##### （1）使用函数指针：
connect(sender, &QObject::destroyed, this, &MyObject::objectDestroyed);
##### （2）使用lambda：
connect(sender, &QObject::destroyed, [=](){ this->m_objects.remove(sender); });
##### （3）使用SIGNAL和SLOT宏，此时信号的参数不能比槽的参数少，举例：
```
  connect(sender, SIGNAL(destroyed(QObject*)), this, SLOT(objectDestroyed(Qbject*)));
  connect(sender, SIGNAL(destroyed(QObject*)), this, SLOT(objectDestroyed()));
  connect(sender, SIGNAL(destroyed()), this, SLOT(objectDestroyed()));

//错误：信号的参数比槽的参数少
  connect(sender, SIGNAL(destroyed()), this, SLOT(objectDestroyed(QObject*)));
```

### 3.Qt::ConnectionType
#### （1）Qt::AutoConnection
默认连接方式，如果接收者和发送者在同一线程，那么就是Qt::DirectConnection。如果接受者和发送者不在同一个线程，那么就是Qt::QueuedConnection。当信号发送时决定为哪一个方式。
举例：见综合举例
#### （2）Qt::DirectConnection
当信号发送后，立即调用槽函数，槽函数运行在发送者线程（依附发送者线程）。
举例：见综合举例
#### （3）Qt::QueuedConnection
在控制回到接收者所在线程的事件循环时，槽函数被调用，运行在接收者线程（依附接受者线程）。
举例：见综合举例
#### （4）Qt::BlockingQueuedConnection
槽函数的调用时机与Qt::QueuedConnection一致，不过发送完信号后发送者所在线程会阻塞，直到槽函数运行完。接收者和发送者不能在一个线程。在多线程间同步的场合使用。
举例：见综合举例
#### （5）Qt::UniqueConnection
可以和上面的type用or连接。当使用该type时，如果连接了已存在的信号槽连接，
那么会失败。
举例：
```
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QPushButton *btn = new QPushButton(this);
    connect(btn, SIGNAL(clicked(bool)), this, SLOT(onBtnClicked()), Qt::UniqueConnection);
    // connect(btn, SIGNAL(clicked(bool)), this, SLOT(onBtnClicked()), Qt::UniqueConnection);
}

MainWindow::~MainWindow()
{

}

void MainWindow::onBtnClicked()
{
    qDebug() << "============";
}

输出：
（1）只有一个connect，不加Qt::UniqueConnection时，输出
============
============

（2）两个connect，加了Qt::UniqueConnection，输出
============
```

#### 综合举例1（和thread一起使用）：
```
// 主函数
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug() << QString("main thread id:") << QThread::currentThreadId();

    MainWindow object;
    QThread thread;
    object.moveToThread(&thread);
    
    QObject::connect(&thread, SIGNAL(started()), &object, SLOT(onStart()));
    thread.start();

    return a.exec();
}

// 工作线程类
void MainWindow::onStart()
{
    qDebug() << QString("obj thread id:") << QThread::currentThreadId();
}

```

情况1：默认情况下，代码如上，结果为：
```
"main thread id:" 0x2b40
"obj thread id:" 0x273c

分析：
连接方式为默认连接方式，此时thread和object都在次线程，所以用的是Qt::DirectConnection。
object在次线程中运行，id和主线程不同
```

情况2：使用Qt::DirectConnection，此时不移动object到次线程
```
    MainWindow object;
    QThread thread;
//    object.moveToThread(&thread);

    QObject::connect(&thread, SIGNAL(started()), &object, SLOT(onStart()), Qt::DirectConnection);
    thread.start();
```

结果为：
```
"main thread id:" 0x2730
"obj thread id:" 0x2050

分析：
连接方式为Qt::DirectConnectio，object依附于发送者线程，发送者thread在次线程，所以object也在次线程
```

情况3：使用Qt::QueuedConnection，此时不移动object到次线程
```
    MainWindow object;
    QThread thread;
//    object.moveToThread(&thread);

    QObject::connect(&thread, SIGNAL(started()), &object, SLOT(onStart()), Qt::QueuedConnection);
    thread.start();

```

结果为：
```
"main thread id:" 0x17dc
"obj thread id:" 0x17dc

分析：
连接方式为Qt::QueuedConnection，object依附于接受者线程，也就是主线程，所以object在主线程执行
```

情况4：使用默认连接方式，此时不移动object到次线程
```
    MainWindow object;
    QThread thread;
//    object.moveToThread(&thread);

    QObject::connect(&thread, SIGNAL(started()), &object, SLOT(onStart()));
    thread.start();
```

结果为：
```
"main thread id:" 0x2118
"obj thread id:" 0x2118

分析：
因为object和thread不在一个线程，所以连接方式为Qt::QueuedConnection，所以object依附于接受者线程，
接受者就是object，object在主线程
```

#### 总结：
（1）先看连接方式
（2）如果是默认连接方式，判断发送者和接受者是否在同一个线程，如果在，那么同Qt::DirectConnection；如果不在，同Qt::QueuedConnection
（3）如果是Qt::DirectConnection，那么槽函数执行的线程和发送者的线程一样（假如发送者在次线程，那么槽函数也在次线程，反正和发送者线程保持一致）
（4）如果是Qt::QueuedConnection，那么槽函数执行的线程和接受者的线程一样（假如接受者在次线程，那么槽函数也在次线程，反正和接受者线程保持一致）

### 4.多线程
#### moveToThread
（1）对象移动到线程时不能有parent
（2）将对象移动到当前线程：
```
  myObject->moveToThread(QApplication::instance()->thread());
```

#### QThread
#### 使用moveToTHread
举例：
```
// 工作线程类，继承自QObject
class Worker : public QObject
  {
      Q_OBJECT
      
  public slots:
      void doWork(const QString &parameter) {
          QString result;
          // 执行耗时操作
          emit resultReady(result);// 发送完成信号
      }

  signals:
      void resultReady(const QString &result);
  };

// ====================================================
// 主类
  class Controller : public QObject
  {
      Q_OBJECT
      // 创建一个private的成员变量
      QThread workerThread;
  public:
      Controller() {
      	  // 创建工作线程，然后移动到线程中
          Worker *worker = new Worker;
          worker->moveToThread(&workerThread);
          
          // 销毁thread
          connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
          
          // 调用线程，此时dowork函数在次线程执行
          connect(this, &Controller::operate, worker, &Worker::doWork);
          
          // 当线程执行完，将结果返回
          connect(worker, &Worker::resultReady, this, &Controller::handleResults);
          
          // 手动调用开启线程
          workerThread.start();
      }
      ~Controller() {
      	  // 析构时退出线程 
          workerThread.quit();
          workerThread.wait();
      }
  public slots:
      void handleResults(const QString &);
  signals:
      void operate(const QString &);
  };
```

#### 继承QThread，重新实现run函数
不建议使用，此时只有run函数是在次线程，而槽函数都在主线程。
举例：
```
  class WorkerThread : public QThread
  {
      Q_OBJECT
      void run() Q_DECL_OVERRIDE {
          QString result;
          // 耗时操作
          emit resultReady(result);
      }
  signals:
      void resultReady(const QString &s);
  };

//==============================================

  void MyObject::startWorkInAThread()
  {
      WorkerThread *workerThread = new WorkerThread(this);
      connect(workerThread, &WorkerThread::resultReady, this, &MyObject::handleResults);
      connect(workerThread, &WorkerThread::finished, workerThread, &QObject::deleteLater);
      workerThread->start();
  }
```

#### 线程同步
#### QMutex
举例：
```
  QMutex mutex;
  int number = 6;

  void method1()
  {
      mutex.lock();
      number *= 5;
      number /= 4;
      mutex.unlock();
  }

  void method2()
  {
      mutex.lock();
      number *= 3;
      number /= 2;
      mutex.unlock();
  }
```

#### QMutexLocker
简化了加锁和释放锁的步骤，当QMutexLocker销毁时，即可自动释放锁。
举例：
```
  int complexFunction(int flag)
  {
      // 函数结束时，自动释放锁
      QMutexLocker locker(&mutex);

      int retVal = 0;

      switch (flag) {
      case 0:
      case 1:
          return moreComplexFunction(flag);
      default:
          if (flag > 10)
              return -1;
          break;
      }
      return retVal;
  }
```

#### QReadWriteLock
举例：
```
  QReadWriteLock lock;

  void ReaderThread::run()
  {
      ...
      lock.lockForRead();
      read_file();
      lock.unlock();
      ...
  }

  void WriterThread::run()
  {
      ...
      lock.lockForWrite();
      write_file();
      lock.unlock();
      ...
  }
```

#### QSemaphore
用户保护多个资源，方法acquire（n）和release（n）用于获取和释放多个资源。
举例：
```
  QSemaphore sem(5);      // sem.available() == 5

  sem.acquire(3);         // sem.available() == 2
  sem.acquire(2);         // sem.available() == 0
  sem.release(5);         // sem.available() == 5
  sem.release(5);         // sem.available() == 10

  sem.tryAcquire(1);      // sem.available() == 9, returns true
  sem.tryAcquire(250);    // sem.available() == 9, returns false
```

#### QWaitCondition
提供了条件变量用于同步线程
举例：见综合举例2

#### 综合举例1（Semaphores Example）
初始变量：
```
const int DataSize = 100000;

const int BufferSize = 8192;
char buffer[BufferSize];

QSemaphore freeBytes(BufferSize);
QSemaphore usedBytes;
```

生产者：
```
class Producer : public QThread
{
public:
    void run() Q_DECL_OVERRIDE
    {
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        for (int i = 0; i < DataSize; ++i) {
            freeBytes.acquire();
            buffer[i % BufferSize] = "ACGT"[(int)qrand() % 4];
            usedBytes.release();
        }
    }
};
```

消费者：
```
class Consumer : public QThread
{
    Q_OBJECT
public:
    void run() Q_DECL_OVERRIDE
    {
        for (int i = 0; i < DataSize; ++i) {
            usedBytes.acquire();
            fprintf(stderr, "%c", buffer[i % BufferSize]);
            freeBytes.release();
        }
        fprintf(stderr, "\n");
    }

signals:
    void stringConsumed(const QString &text);

protected:
    bool finish;
};
```

调用：
```
int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    Producer producer;
    Consumer consumer;
    producer.start();
    consumer.start();
    producer.wait();
    consumer.wait();
    return 0;
}
```

总结：
（1）free和used和的大小始终等于缓冲器（BufferSize）的大小
（2）生产者和消费者都是DataSize的大小进行循环，表示要生产DataSize大小和消费DataSize大小
（3）buffer作为缓冲器，被保护起来了。
（4）acquire表示-1，release表示+1
（5）缓冲器没有动，总数据在变化

#### 综合举例2（Wait Conditions Example）
初始变量：
```
  const int DataSize = 100000;

  const int BufferSize = 8192;
  char buffer[BufferSize];

  QWaitCondition bufferNotEmpty;
  QWaitCondition bufferNotFull;
  QMutex mutex;
  int numUsedBytes = 0;
```

生产者：
```
  class Producer : public QThread
  {
  public:
      Producer(QObject *parent = NULL) : QThread(parent)
      {
      }

      void run() Q_DECL_OVERRIDE
      {
          qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

          for (int i = 0; i < DataSize; ++i) {
              mutex.lock();
              if (numUsedBytes == BufferSize)
                  bufferNotFull.wait(&mutex);
              mutex.unlock();

              buffer[i % BufferSize] = "ACGT"[(int)qrand() % 4];

              mutex.lock();
              ++numUsedBytes;
              bufferNotEmpty.wakeAll();
              mutex.unlock();
          }
      }
  };
```

消费者：
```
  class Consumer : public QThread
  {
      Q_OBJECT
  public:
      Consumer(QObject *parent = NULL) : QThread(parent)
      {
      }

      void run() Q_DECL_OVERRIDE
      {
          for (int i = 0; i < DataSize; ++i) {
              mutex.lock();
              if (numUsedBytes == 0)
                  bufferNotEmpty.wait(&mutex);
              mutex.unlock();

              fprintf(stderr, "%c", buffer[i % BufferSize]);

              mutex.lock();
              --numUsedBytes;
              bufferNotFull.wakeAll();
              mutex.unlock();
          }
          fprintf(stderr, "\n");
      }

  signals:
      void stringConsumed(const QString &text);
  };
```

调用：
```
  int main(int argc, char *argv[])
  {
      QCoreApplication app(argc, argv);
      Producer producer;
      Consumer consumer;
      producer.start();
      consumer.start();
      producer.wait();
      consumer.wait();
      return 0;
  }
```

总结：
（1）加入了不为空和不为满的判断，一旦发现缓存满了，就通知消费者；一旦发现缓存空了，就通知生产者

### 5.防止界面冻结的方法：
参考：https://www.cryfeifei.cn
（1）QCoreApplication::postEvent
（2）QtConcurrent::run
（3）QObject::moveToThread

### 6.释放线程资源方法：
（1）官方文档（QThread定义在栈上）：
```
class Controller : public QObject
  {
      Q_OBJECT
      QThread workerThread;
  public:
      Controller() {
          Worker *worker = new Worker;
          worker->moveToThread(&workerThread);
          
          // 2.thread销毁完成后，销毁work对象
          connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
          
          connect(this, &Controller::operate, worker, &Worker::doWork);
          connect(worker, &Worker::resultReady, this, &Controller::handleResults);
          workerThread.start();
      }
      ~Controller() {
      	  // 1.thread定义在栈上，类销毁时，thread开始销毁
          workerThread.quit();
          workerThread.wait();
      }
  };
```

（2）QTread定义在堆上：
当工作完成后，发射信号告知线程，线程先quit和wait（此时没有销毁）。
接着线程完成了（quit了但没有销毁），就告诉work，让他先销毁。
work销毁后，在让线程销毁。
```
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    thread = new QThread();
    MyThread *worker = new MyThread();
    worker->moveToThread(thread);

    // 当工作线程工作完，让线程停止、等待
    connect(worker, &MyThread::workFinished, [this](){
        thread->quit();
        thread->wait();
    });

    // 线程完成停止后，销毁worker
    connect(thread, &QThread::finished, worker, &MyThread::deleteLater);

    // worker销毁完后，在销毁thread本身
    connect(worker, &MyThread::destroyed, thread, &QThread::deleteLater);
}
```


### 13.插件管理器
https://blog.csdn.net/kenfan1647/category_9967854.html

### 16.插件之间通信
https://blog.csdn.net/kenfan1647/category_9967854.html
