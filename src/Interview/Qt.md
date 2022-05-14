## 目录
### 元对象系统
#### QObject
#### qmake
### 信号槽
#### 信号槽原理
#### 信号槽优缺点
#### 信号槽用法
#### 信号槽第五个参数
### 多线程
#### 多线程用法
#### 多线程同步
### 信号槽和多线程
### 事件传递
### Qt下TCP通信过程
### Qt下UDP通信过程
### MVD
### Qt翻译
### 其他
#### Qt中设计模式
#### Qt智能指针，与C++智能指针的区别
#### q指针和d指针，二进制兼容
#### 如何保证只打开一个exe
#### show() exec()区别
#### Qt Android
   
//================================================================================================================

#### 1.qt中QObject类是做什么的，有哪些功能?
QObject是Qt实现元对象系统的基础，元对象系统是...

#### 2.了解元对象系统吗？
元对象系统是Qt对标准的C++进行的扩展，提供了（1）信号槽机制（2）动态属性系统（3）运行时类型识别 （4）对象树 等功能，
为了使用原对象系统，需要（1）QObject类：作为使用元对象类的基类（2）Q_OBJECT宏：用于启动元对象系统（3）MOC（Meta-Object Compiler，元对象编译器）：为每个QObject子类提供必要的代码
moc工作流程：读取源文件检测到类中包含有Q_OBJECT宏时，则会创建一个moc开头的C++源文件，其中包含了类的元对象代码。这些产生的源文件包含进类的源文件中，一起进行编译。

##### 2.1 信号槽机制(后面详细讲)

##### 2.2 动态属性系统
QObject::setProperty()和QObject::property()通过名字来动态设置或者获取对象属性；

##### 2.3 运行时类型识别
RTTI （Runtime Type Information，运行时类型信息），它提供了运行时确定对象类型的方法,
程序能够使用基类的指针或引用来检查着这些指针或引用所指的对象的实际派生类型。

QObject::metaObject()函数可以返回一个类的元对象，它是QMetaObject类的对象；
QMetaObject::className()可以在运行时以字符串形式返回类名，而不需要C++编辑器原生的运行时类型信息（RTTI）的支持；

##### 2.4 对象树
Qt中使用对象树（object tree）来管理所有的QObject类及其子类的对象。当创建一个QObject时，如果使用了其他的对象作为其父对象（parent），
那么这个QObject就会被添加到父对象的children()列表中，这样当父对象被销毁时，这个QObject也会被销毁。

##### 2.5 Qt运行时类型识别 和 C++运行时类型信息
https://blog.csdn.net/songsong2017/article/details/103604885

##### 2.6 qobject_cast 和 C++的cast
使用qobject_cast()函数来对QObject类进行动态类型转换，这个函数的功能类似于标准C++中的dynamic_cast()函数，但它不再需要RTTI的支持。

#### 3.qmake,make,makefile
https://blog.csdn.net/lvdepeng123/article/details/79007988

//================================================================================================================

#### 1.信号槽原理
信号槽实际就是观察者模式

##### 1.1 信号与槽、和事件的区别
##### 1.2 自定义结构体到信号与槽要注意什么
##### 1.3 怎么自己实现 Qt 的信号与槽？
##### 1.4 信号与槽的底层原理；信号与槽怎么做到性能优化
##### 1.5 Qt使用信号槽传递大量数据的效率问题，隐式共享

#### 2.信号槽优缺点
优点：
1.类型安全。信号的参数类型和个数与接收方的一致。
2.耦合度低。发送方不用管接收方是谁，只需要发送信号即可。同理，接收方也不用知道发送方是谁，只要信号到了就可以执行槽函数。
3.使用自由。一个信号连接多个槽，一个槽连接多个信号。信号可以连接信号（此时会立即发射第二个信号）
缺点：
1.速度较慢。与回调函数相比，信号和槽机制运行速度比直接调用非虚函数慢10倍。
原因：1.需要定位接收信号的对象。2.安全地遍历所有关联槽。3.编组、解组传递参数。4.多线程的时候，信号需要排队等待。
（然而，与创建对象的new操作及删除对象的delete操作相比，信号和槽的运行代价只是他们很少的一部分。信号和槽机制导致的这点性能损耗，对实时应用程序是可以忽略的。）


#### 2.1.信号与槽与函数指针的比较


#### 3.信号槽用法
连接方式：
（1）使用SIGNAL和SLOT宏，此时信号的参数不能比槽的参数少，举例：
```
  connect(sender, SIGNAL(destroyed(QObject*)), this, SLOT(objectDestroyed(Qbject*)));
  connect(sender, SIGNAL(destroyed(QObject*)), this, SLOT(objectDestroyed()));
  connect(sender, SIGNAL(destroyed()), this, SLOT(objectDestroyed()));
```

（2）使用函数指针：
connect(sender, &QObject::destroyed, this, &MyObject::objectDestroyed);

（3）使用lambda：
connect(sender, &QObject::destroyed, [=](){ this->m_objects.remove(sender); });

##### 3.1 lambda
lambda表达式主要分五部分:[函数对象参数]、(操作符重载函数参数)、mutable或 声明、->返回值类型、{函数体} [捕获列表] (参数列表) 函数选项 -> 返回值类型 {函数体}
[&]:以引用的方式捕获外部的所有变量，如果在函数体内改变外部变量值，外部变量值就会随之改变；
[=]:以值的方式捕获外部的所有变量，如果在函数体内改变“外部变量值”，外部变量值不会改变；

#### 4.信号槽第五个参数

1. Qt::AutoConnection：信号的发送者与信号的接收者在同一线程，则默认使用Qt::DirectConnection；如果不在同一线程，则默认使用Qt::QueuedConnection。
       
2. Qt::DirectConnection：信号的发送者与信号的接收者在同一线程中执行，当发出信号后，会马上进入槽函数，看上去就像在信号  
发送位置调用了槽函数，在多线程下会比较危险，容易造成崩溃。
       
3. Qt::QueuedConnection：信号的发送者与信号的接收者不在同一线程中执行，
槽函数运行于信号的接收者线程，当发送信号后，  槽函数不会马上被调用，等待信号的接收者把当前函数执行完，进入事件循环之后，槽函数才会被调用。
多线程环境下一般用这个。

4. Qt::BlockingQueuedConnection：槽函数的调用时机与Qt::QueuedConnection一致，
不过发送完信号后发送者所在线程会阻塞，直到槽函数运行完。接收者和发送者绝对不能在一个线程，否则程序会死锁。在多线程间需要同步的场合可能需要这个。
        
5. Qt::UniqueConnection：可以通过按位或（|）与以上四个结合在一起使用。当设置此参数时，当某个信号和槽已经连接时，再进行重复的连接就会失败，
也就是避免了重复连接。


//================================================================================================================

#### 1.多线程用法
##### 方法1：1.创建一个类从QThread类派生;2.在子线程类中重写 run 函数, 将处理操作写入该函数中 3.在主线程中创建子线程对象, 启动子线程, 调用start()函数
优点：实现简单，可以用信号槽通信。
缺点：需要自己管理线程的创建释放，频繁地创建释放效率不高。所以适合常驻程序的线程使用。另外因为QThread对象属于父线程，所以对象中的槽函数（如果有的话）其实会在父线程执行。
        
##### 方法2：1.将业务处理抽象成一个业务类, 在该类中创建一个业务处理函数;2.在主线程中创建一QThread类对象;3.在主线程中创建一个业务类对象;4.将业务类对象移动到子线程中;5.在主线程中启动子线程;6.通过信号槽的方式, 执行业务类中的业务处理函数
优点：实现简单，使用于比较复杂的业务场景。
缺点：只能通过信号槽的方式调用业务对象的接口。且不能给此对象指定父对象。

##### 方法3：QThreadPool与QRunnable，继承QRunnable实现run方法完成业务类创建，由QThreadPool启动业务类。
优点：无需关注线程资源管理，不会频繁创建与释放线程。所以适用需要频繁创建销毁线程的业务场景。
        
##### 方法4：QtConcurrent::run()直接将任务丢进子线程执行。
优点：调用简单，无需关注线程资源管理，不会频繁创建与释放线程。

##### 多线程使用注意事项:（1）业务对象, 构造的时候不能指定父对象；（2）子线程中只能处理一些数据相关的操作, 不能涉及ui窗口(ui相关的类)

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

#### 2.多线程同步
##### QMutex
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
##### QMutexLocker
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
##### QReadWriteLock
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

##### QSemaphore
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


##### QWaitCondition
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


#### 3.防止界面冻结的方法
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


//================================================================================================================

#### 1.信号槽和多线程
#### Qt::ConnectionType
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


//================================================================================================================

https://blog.csdn.net/luolaihua2018/article/details/110797592

1.事件传递
15.qt 的消息传递机制
17.Qt的事件过滤器 （事件的传递是由子类往父类上传的）
事件系统（自定义事件处理函数3种方式）
https://www.cnblogs.com/xiaobingqianrui/p/9547924.html

2.事件循环
Qt的主事件循环能够从事件队列中获取本地窗口系统事件，然后判断事件类型，并将事件分发给特定的接收对象。
主事件循环通过调用QCoreApplication::exec()启动，随着QCoreApplication::exit()结束，本地的事件循环可用利用QEventLoop构建。

//================================================================================================================

1.Qt下TCP通信过程
服务端：（QTcpServer）
        ①创建QTcpServer对象

        
②监听list需要的参数是地址和端口号

        
③当有新的客户端连接成功回发送newConnect信号

        
④在newConnection信号槽函数中，调用nextPendingConnection函数获取新连接QTcpSocket对象

        
⑤连接QTcpSocket对象的readRead信号

        ⑥在readRead信号的槽函数使用read接收数据

        
⑦调用write成员函数发送数据

客户端：（QTcpSocket）

        ①创建QTcpSocket对象

        ②当对象与Server连接成功时会发送connected 信号

       
 ③调用成员函数connectToHost连接服务器，需要的参数是地址和端口号

        
④connected信号的槽函数开启发送数据

        ⑤使用write发送数据，read接收数据

//================================================================================================================

1.Qt下UDP通信过程
           
UDP（User Datagram Protocol即用户数据报协议）是一个轻量级的，不可靠的，面向数据报的无连接协议。
在网络质量令人十分不满意的环境下，UDP协议数据包丢失严重。
由于UDP的特性：它不属于连接型协议，因而具有资源消耗小，处理速度快的优点，所以通常音频、
视频和普通数据在传送时使用UDP较多，因为它们即使偶尔丢失一两个数据包，也不会对接收结果产生太大影响。
所以QQ这种对保密要求并不太高的聊天程序就是使用的UDP协议。

        
在Qt中提供了QUdpSocket 类来进行UDP数据报（datagrams）的发送和接收。Socket简单地说，就是一个IP地址加一个port端口  。

        
流程：①创建QUdpSocket套接字对象 ②如果需要接收数据，必须绑定端口 ③发送数据用writeDatagram，接收数据用 readDatagram 。

//================================================================================================================

1.Qt中的MVD
Qt的MVD包含三个部分Model（模型），View（视图），代理（Delegate）。
Model否则保存数据，View负责展示数据，Delegate负责Item样式绘制或处理输入。
这三部分通过信号槽来进行通信，当Model中数据发生变化时将会发送信号到View，在View中编辑数据时，
Delegate负责将编辑状态发送给Model层。基类分别为QAbstractItemModel、QAbstractItemView、QAbstractItemDelegate。
Qt中提供了默认实现的MVD类，如QTableWidget、QListWidget、QTreeWidget等。

//================================================================================================================

1.Qt翻译流程
https://blog.csdn.net/weibuu/article/details/108802258

//================================================================================================================

1.qt中都用到了哪些设计模式
（1）单例模式：qApp
（2）观察者模式：信号槽

//================================================================================================================

 Qt智能指针与C++智能指针的区别
https://blog.csdn.net/iriczhao/article/details/122117218
https://zhuanlan.zhihu.com/p/364014571?ivk_sa=1024320u

//================================================================================================================

#### 7.q、d指针为了解决什么问题？
为解决二进制兼容
所谓二进制兼容动态库，指的是一个在老版本库下运行的程序，在不经过编译的情况下，仍然能够在新的版本库下运行；
需要经过编译才能在新版本下运行，而不需要修改该程序源代码，我们就说该动态库是源代码兼容的;

//================================================================================================================

1.如何保证只打开一个exe
使用 系统信号量 QSystemSemaphore 与 共享内存 QSharedMemory
```
    QSystemSemaphore sema("JAMKey",1,QSystemSemaphore::Open);
    sema.acquire();//在临界区操作共享内存  SharedMemory
    QSharedMemory mem("SystemObject");//全局对象名
    if (!mem.create(1))//如果全局对象以存在则退出
    {
        sema.release();//如果是Unix系统，会自动释放。
        return 0;
    }
    sema.release();//临界区
```

//================================================================================================================

1.show() exec()区别

模式窗口：窗口会原地阻塞，只能操作该窗口，其余窗口不能再操作；只有关闭该窗口后，代码处才会获得返回值，阻塞停止，就可以操作其它界面了；

半模式窗口：窗口会原地伪阻塞，虽然也是只能操作该窗口，其余窗口不能再操作，但是代码会继续往下运行，所以说是伪阻塞；

非模式窗口：窗口不会阻塞，可以随意操作；

模式窗口：Dlg->exec();
半模式窗口： Dlg->setModal(true); Dlg->show();
非模式窗口：Dlg->show();

//================================================================================================================

#### Qt Android

//================================================================================================================

知识点：http://shouce.jb51.net/qt-beginning/48.html

面试题：https://www.zhihu.com/question/451327108


#### 1.请介绍下 qt中QObject类是做什么的，有哪些功能?
很多人只知道和信号槽机制有关系
如果还能答出 父子树节点管理 基本就算及格。
若还能回答出 rtti 定时器 属性系统 等就算优秀
#### 2.接上个问题 请说下qt的父子树节点管理机制
#### 3.接上问，除了qt父子树管理机制能智能管理对象生命周期，还有哪些避免内存泄露的机制?
#### 4.大部分人能答出智能指针，就可以问下std::shared_ptr的实现机制。
#### 5.如能回答出 基于引用计数，计数为0则清零，则可以问下共享式指针的缺点是什么?


#### 6.如能说出 性能损失和循环引用，则可以问如何破解循环引用。会带出弱指针。
#### 7.接问题3 如果能答出内存池，则有必要问下内存池的实现机制和在内存池中分配对象的需要注意的事项? 很少有人能回答出显式调用构造和析构函数。
#### 8.设计模式相关请说下qt中都用到了哪些设计模式 如何能答出 观察者模式 不得分
如能回答出 单例 工厂 责任链 状态机 备忘录 享元 装饰器 等则可以问下哪里使用到了?  此类模式优缺点什么?
以上8个问题如果能完整回答4个以上 则说明c++基本功 面向对象分析设计和设计模式都掌握的不错。