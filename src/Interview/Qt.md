## Ŀ¼
### Ԫ����ϵͳ
#### QObject
#### qmake
### �źŲ�
#### �źŲ�ԭ��
#### �źŲ���ȱ��
#### �źŲ��÷�
#### �źŲ۵��������
### ���߳�
#### ���߳��÷�
#### ���߳�ͬ��
### �źŲۺͶ��߳�
### �¼�����
### Qt��TCPͨ�Ź���
### Qt��UDPͨ�Ź���
### MVD
### Qt����
### ����
#### Qt�����ģʽ
#### Qt����ָ�룬��C++����ָ�������
#### qָ���dָ�룬�����Ƽ���
#### ��α�ֻ֤��һ��exe
#### show() exec()����
#### Qt Android
   
//================================================================================================================

#### 1.qt��QObject������ʲô�ģ�����Щ����?
QObject��Qtʵ��Ԫ����ϵͳ�Ļ�����Ԫ����ϵͳ��...

#### 2.�˽�Ԫ����ϵͳ��
Ԫ����ϵͳ��Qt�Ա�׼��C++���е���չ���ṩ�ˣ�1���źŲۻ��ƣ�2����̬����ϵͳ��3������ʱ����ʶ�� ��4����������5���¼� �ȹ��ܣ�
Ϊ��ʹ��ԭ����ϵͳ����Ҫ��1��QObject�ࣺ��Ϊʹ��Ԫ������Ļ��ࣨ2��Q_OBJECT�꣺��������Ԫ����ϵͳ��3��MOC��Meta-Object Compiler��Ԫ�������������Ϊÿ��QObject�����ṩ��Ҫ�Ĵ���
moc�������̣���ȡԴ�ļ���⵽���а�����Q_OBJECT��ʱ����ᴴ��һ��moc��ͷ��C++Դ�ļ������а��������Ԫ������롣��Щ������Դ�ļ����������Դ�ļ��У�һ����б��롣

##### 2.1 �źŲۻ���(������ϸ��)

##### 2.2 ��̬����ϵͳ
QObject::setProperty()��QObject::property()ͨ����������̬���û��߻�ȡ�������ԣ�

##### 2.3 ����ʱ����ʶ��
RTTI ��Runtime Type Information������ʱ������Ϣ�������ṩ������ʱȷ���������͵ķ���,
�����ܹ�ʹ�û����ָ����������������Щָ���������ָ�Ķ����ʵ���������͡�

QObject::metaObject()�������Է���һ�����Ԫ��������QMetaObject��Ķ���
QMetaObject::className()����������ʱ���ַ�����ʽ����������������ҪC++�༭��ԭ��������ʱ������Ϣ��RTTI����֧�֣�

##### 2.4 ������
Qt��ʹ�ö�������object tree�����������е�QObject�༰������Ķ��󡣵�����һ��QObjectʱ�����ʹ���������Ķ�����Ϊ�丸����parent����
��ô���QObject�ͻᱻ��ӵ��������children()�б��У�����������������ʱ�����QObjectҲ�ᱻ���١�

##### 2.5 Qt����ʱ����ʶ�� �� C++����ʱ������Ϣ
https://blog.csdn.net/songsong2017/article/details/103604885

##### 2.6 qobject_cast �� C++��cast
ʹ��qobject_cast()��������QObject����ж�̬����ת������������Ĺ��������ڱ�׼C++�е�dynamic_cast()����������������ҪRTTI��֧�֡�

#### 3.qmake,make,makefile
https://blog.csdn.net/lvdepeng123/article/details/79007988

//================================================================================================================

#### 1.�źŲ�ԭ��
�źŲ�ʵ�ʾ��ǹ۲���ģʽ

##### 1.2 �Զ���ṹ�嵽�ź����Ҫע��ʲô
##### 1.3 ��ô�Լ�ʵ�� Qt ���ź���ۣ�
##### 1.4 �ź���۵ĵײ�ԭ���ź������ô���������Ż�
##### 1.5 Qtʹ���źŲ۴��ݴ������ݵ�Ч�����⣬��ʽ����

#### 2.�źŲ���ȱ��
�ŵ㣺
1.���Ͱ�ȫ���źŵĲ������ͺ͸�������շ���һ�¡�
2.��϶ȵ͡����ͷ����ùܽ��շ���˭��ֻ��Ҫ�����źż��ɡ�ͬ�����շ�Ҳ����֪�����ͷ���˭��ֻҪ�źŵ��˾Ϳ���ִ�вۺ�����
3.ʹ�����ɡ�һ���ź����Ӷ���ۣ�һ�������Ӷ���źš��źſ��������źţ���ʱ����������ڶ����źţ�
ȱ�㣺
1.�ٶȽ�������ص�������ȣ��źźͲۻ��������ٶȱ�ֱ�ӵ��÷��麯����10����
ԭ��1.��Ҫ��λ�����źŵĶ���2.��ȫ�ر������й����ۡ�3.���顢���鴫�ݲ�����4.���̵߳�ʱ���ź���Ҫ�Ŷӵȴ���
��Ȼ�����봴�������new������ɾ�������delete������ȣ��źźͲ۵����д���ֻ�����Ǻ��ٵ�һ���֡��źźͲۻ��Ƶ��µ����������ģ���ʵʱӦ�ó����ǿ��Ժ��Եġ���


#### 2.1.�ź�����뺯��ָ��ıȽ�


#### 3.�źŲ��÷�
���ӷ�ʽ��
��1��ʹ��SIGNAL��SLOT�꣬��ʱ�źŵĲ������ܱȲ۵Ĳ����٣�������
```
  connect(sender, SIGNAL(destroyed(QObject*)), this, SLOT(objectDestroyed(Qbject*)));
  connect(sender, SIGNAL(destroyed(QObject*)), this, SLOT(objectDestroyed()));
  connect(sender, SIGNAL(destroyed()), this, SLOT(objectDestroyed()));
```

��2��ʹ�ú���ָ�룺
connect(sender, &QObject::destroyed, this, &MyObject::objectDestroyed);

��3��ʹ��lambda��
connect(sender, &QObject::destroyed, [=](){ this->m_objects.remove(sender); });

##### 3.1 lambda
lambda���ʽ��Ҫ���岿��:[�����������]��(���������غ�������)��mutable�� ������->����ֵ���͡�{������} [�����б�] (�����б�) ����ѡ�� -> ����ֵ���� {������}
[&]:�����õķ�ʽ�����ⲿ�����б���������ں������ڸı��ⲿ����ֵ���ⲿ����ֵ�ͻ���֮�ı䣻
[=]:��ֵ�ķ�ʽ�����ⲿ�����б���������ں������ڸı䡰�ⲿ����ֵ�����ⲿ����ֵ����ı䣻

#### 4.�źŲ۵��������

1. Qt::AutoConnection���źŵķ��������źŵĽ�������ͬһ�̣߳���Ĭ��ʹ��Qt::DirectConnection���������ͬһ�̣߳���Ĭ��ʹ��Qt::QueuedConnection��
       
2. Qt::DirectConnection���źŵķ��������źŵĽ�������ͬһ�߳���ִ�У��������źź󣬻����Ͻ���ۺ���������ȥ�������ź�  
����λ�õ����˲ۺ������ڶ��߳��»�Ƚ�Σ�գ�������ɱ�����
       
3. Qt::QueuedConnection���źŵķ��������źŵĽ����߲���ͬһ�߳���ִ�У�
�ۺ����������źŵĽ������̣߳��������źź�  �ۺ����������ϱ����ã��ȴ��źŵĽ����߰ѵ�ǰ����ִ���꣬�����¼�ѭ��֮�󣬲ۺ����Żᱻ���á�
���̻߳�����һ���������

4. Qt::BlockingQueuedConnection���ۺ����ĵ���ʱ����Qt::QueuedConnectionһ�£�
�����������źź����������̻߳�������ֱ���ۺ��������ꡣ�����ߺͷ����߾��Բ�����һ���̣߳����������������ڶ��̼߳���Ҫͬ���ĳ��Ͽ�����Ҫ�����
        
5. Qt::UniqueConnection������ͨ����λ��|���������ĸ������һ��ʹ�á������ô˲���ʱ����ĳ���źźͲ��Ѿ�����ʱ���ٽ����ظ������Ӿͻ�ʧ�ܣ�
Ҳ���Ǳ������ظ����ӡ�


//================================================================================================================

#### 1.���߳��÷�
##### ����1��1.����һ�����QThread������;2.�����߳�������д run ����, ���������д��ú����� 3.�����߳��д������̶߳���, �������߳�, ����start()����
�ŵ㣺ʵ�ּ򵥣��������źŲ�ͨ�š�
ȱ�㣺��Ҫ�Լ������̵߳Ĵ����ͷţ�Ƶ���ش����ͷ�Ч�ʲ��ߡ������ʺϳ�פ������߳�ʹ�á�������ΪQThread�������ڸ��̣߳����Զ����еĲۺ���������еĻ�����ʵ���ڸ��߳�ִ�С�
        
##### ����2��1.��ҵ��������һ��ҵ����, �ڸ����д���һ��ҵ������;2.�����߳��д���һQThread�����;3.�����߳��д���һ��ҵ�������;4.��ҵ��������ƶ������߳���;5.�����߳����������߳�;6.ͨ���źŲ۵ķ�ʽ, ִ��ҵ�����е�ҵ������
�ŵ㣺ʵ�ּ򵥣�ʹ���ڱȽϸ��ӵ�ҵ�񳡾���
ȱ�㣺ֻ��ͨ���źŲ۵ķ�ʽ����ҵ�����Ľӿڡ��Ҳ��ܸ��˶���ָ��������

##### ����3��QThreadPool��QRunnable���̳�QRunnableʵ��run�������ҵ���ഴ������QThreadPool����ҵ���ࡣ
�ŵ㣺�����ע�߳���Դ��������Ƶ���������ͷ��̡߳�����������ҪƵ�����������̵߳�ҵ�񳡾���
        
##### ����4��QtConcurrent::run()ֱ�ӽ����񶪽����߳�ִ�С�
�ŵ㣺���ü򵥣������ע�߳���Դ��������Ƶ���������ͷ��̡߳�

##### ���߳�ʹ��ע������:��1��ҵ�����, �����ʱ����ָ�������󣻣�2�����߳���ֻ�ܴ���һЩ������صĲ���, �����漰ui����(ui��ص���)

#### moveToThread
��1�������ƶ����߳�ʱ������parent
��2���������ƶ�����ǰ�̣߳�
```
  myObject->moveToThread(QApplication::instance()->thread());
```

#### QThread
#### ʹ��moveToTHread
������
```
// �����߳��࣬�̳���QObject
class Worker : public QObject
  {
      Q_OBJECT
      
  public slots:
      void doWork(const QString &parameter) {
          QString result;
          // ִ�к�ʱ����
          emit resultReady(result);// ��������ź�
      }

  signals:
      void resultReady(const QString &result);
  };

// ====================================================
// ����
  class Controller : public QObject
  {
      Q_OBJECT
      // ����һ��private�ĳ�Ա����
      QThread workerThread;
  public:
      Controller() {
      	  // ���������̣߳�Ȼ���ƶ����߳���
          Worker *worker = new Worker;
          worker->moveToThread(&workerThread);
          
          // ����thread
          connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
          
          // �����̣߳���ʱdowork�����ڴ��߳�ִ��
          connect(this, &Controller::operate, worker, &Worker::doWork);
          
          // ���߳�ִ���꣬���������
          connect(worker, &Worker::resultReady, this, &Controller::handleResults);
          
          // �ֶ����ÿ����߳�
          workerThread.start();
      }
      ~Controller() {
      	  // ����ʱ�˳��߳� 
          workerThread.quit();
          workerThread.wait();
      }
  public slots:
      void handleResults(const QString &);
  signals:
      void operate(const QString &);
  };
```

#### �̳�QThread������ʵ��run����
������ʹ�ã���ʱֻ��run�������ڴ��̣߳����ۺ����������̡߳�
������
```
  class WorkerThread : public QThread
  {
      Q_OBJECT
      void run() Q_DECL_OVERRIDE {
          QString result;
          // ��ʱ����
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

#### 2.���߳�ͬ��
##### QMutex
������
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
���˼������ͷ����Ĳ��裬��QMutexLocker����ʱ�������Զ��ͷ�����
������
```
  int complexFunction(int flag)
  {
      // ��������ʱ���Զ��ͷ���
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
������
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
�û����������Դ������acquire��n����release��n�����ڻ�ȡ���ͷŶ����Դ��
������
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
�ṩ��������������ͬ���߳�
���������ۺϾ���2


#### �ۺϾ���1��Semaphores Example��
��ʼ������
```
const int DataSize = 100000;

const int BufferSize = 8192;
char buffer[BufferSize];

QSemaphore freeBytes(BufferSize);
QSemaphore usedBytes;
```

�����ߣ�
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

�����ߣ�
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

���ã�
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

�ܽ᣺
��1��free��used�͵Ĵ�Сʼ�յ��ڻ�������BufferSize���Ĵ�С
��2�������ߺ������߶���DataSize�Ĵ�С����ѭ������ʾҪ����DataSize��С������DataSize��С
��3��buffer��Ϊ�������������������ˡ�
��4��acquire��ʾ-1��release��ʾ+1
��5��������û�ж����������ڱ仯

#### �ۺϾ���2��Wait Conditions Example��
��ʼ������
```
  const int DataSize = 100000;

  const int BufferSize = 8192;
  char buffer[BufferSize];

  QWaitCondition bufferNotEmpty;
  QWaitCondition bufferNotFull;
  QMutex mutex;
  int numUsedBytes = 0;
```

�����ߣ�
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

�����ߣ�
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

���ã�
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

�ܽ᣺
��1�������˲�Ϊ�պͲ�Ϊ�����жϣ�һ�����ֻ������ˣ���֪ͨ�����ߣ�һ�����ֻ�����ˣ���֪ͨ������


#### 3.��ֹ���涳��ķ���
�ο���https://www.cryfeifei.cn
��1��QCoreApplication::postEvent
��2��QtConcurrent::run
��3��QObject::moveToThread


### 6.�ͷ��߳���Դ������
��1���ٷ��ĵ���QThread������ջ�ϣ���
```
class Controller : public QObject
  {
      Q_OBJECT
      QThread workerThread;
  public:
      Controller() {
          Worker *worker = new Worker;
          worker->moveToThread(&workerThread);
          
          // 2.thread������ɺ�����work����
          connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
          
          connect(this, &Controller::operate, worker, &Worker::doWork);
          connect(worker, &Worker::resultReady, this, &Controller::handleResults);
          workerThread.start();
      }
      ~Controller() {
      	  // 1.thread������ջ�ϣ�������ʱ��thread��ʼ����
          workerThread.quit();
          workerThread.wait();
      }
  };
```

��2��QTread�����ڶ��ϣ�
��������ɺ󣬷����źŸ�֪�̣߳��߳���quit��wait����ʱû�����٣���
�����߳�����ˣ�quit�˵�û�����٣����͸���work�����������١�
work���ٺ������߳����١�
```
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    thread = new QThread();
    MyThread *worker = new MyThread();
    worker->moveToThread(thread);

    // �������̹߳����꣬���߳�ֹͣ���ȴ�
    connect(worker, &MyThread::workFinished, [this](){
        thread->quit();
        thread->wait();
    });

    // �߳����ֹͣ������worker
    connect(thread, &QThread::finished, worker, &MyThread::deleteLater);

    // worker�������������thread����
    connect(worker, &MyThread::destroyed, thread, &QThread::deleteLater);
}
```


//================================================================================================================

#### 1.�źŲۺͶ��߳�
#### Qt::ConnectionType
#### ��1��Qt::AutoConnection
Ĭ�����ӷ�ʽ����������ߺͷ�������ͬһ�̣߳���ô����Qt::DirectConnection����������ߺͷ����߲���ͬһ���̣߳���ô����Qt::QueuedConnection�����źŷ���ʱ����Ϊ��һ����ʽ��
���������ۺϾ���
#### ��2��Qt::DirectConnection
���źŷ��ͺ��������òۺ������ۺ��������ڷ������̣߳������������̣߳���
���������ۺϾ���
#### ��3��Qt::QueuedConnection
�ڿ��ƻص������������̵߳��¼�ѭ��ʱ���ۺ��������ã������ڽ������̣߳������������̣߳���
���������ۺϾ���
#### ��4��Qt::BlockingQueuedConnection
�ۺ����ĵ���ʱ����Qt::QueuedConnectionһ�£������������źź����������̻߳�������ֱ���ۺ��������ꡣ�����ߺͷ����߲�����һ���̡߳��ڶ��̼߳�ͬ���ĳ���ʹ�á�
���������ۺϾ���
#### ��5��Qt::UniqueConnection
���Ժ������type��or���ӡ���ʹ�ø�typeʱ������������Ѵ��ڵ��źŲ����ӣ�
��ô��ʧ�ܡ�
������
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

�����
��1��ֻ��һ��connect������Qt::UniqueConnectionʱ�����
============
============

��2������connect������Qt::UniqueConnection�����
============
```

#### �ۺϾ���1����threadһ��ʹ�ã���
```
// ������
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

// �����߳���
void MainWindow::onStart()
{
    qDebug() << QString("obj thread id:") << QThread::currentThreadId();
}

```

���1��Ĭ������£��������ϣ����Ϊ��
```
"main thread id:" 0x2b40
"obj thread id:" 0x273c

������
���ӷ�ʽΪĬ�����ӷ�ʽ����ʱthread��object���ڴ��̣߳������õ���Qt::DirectConnection��
object�ڴ��߳������У�id�����̲߳�ͬ
```

���2��ʹ��Qt::DirectConnection����ʱ���ƶ�object�����߳�
```
    MainWindow object;
    QThread thread;
//    object.moveToThread(&thread);

    QObject::connect(&thread, SIGNAL(started()), &object, SLOT(onStart()), Qt::DirectConnection);
    thread.start();
```

���Ϊ��
```
"main thread id:" 0x2730
"obj thread id:" 0x2050

������
���ӷ�ʽΪQt::DirectConnectio��object�����ڷ������̣߳�������thread�ڴ��̣߳�����objectҲ�ڴ��߳�
```

���3��ʹ��Qt::QueuedConnection����ʱ���ƶ�object�����߳�
```
    MainWindow object;
    QThread thread;
//    object.moveToThread(&thread);

    QObject::connect(&thread, SIGNAL(started()), &object, SLOT(onStart()), Qt::QueuedConnection);
    thread.start();

```

���Ϊ��
```
"main thread id:" 0x17dc
"obj thread id:" 0x17dc

������
���ӷ�ʽΪQt::QueuedConnection��object�����ڽ������̣߳�Ҳ�������̣߳�����object�����߳�ִ��
```

���4��ʹ��Ĭ�����ӷ�ʽ����ʱ���ƶ�object�����߳�
```
    MainWindow object;
    QThread thread;
//    object.moveToThread(&thread);

    QObject::connect(&thread, SIGNAL(started()), &object, SLOT(onStart()));
    thread.start();
```

���Ϊ��
```
"main thread id:" 0x2118
"obj thread id:" 0x2118

������
��Ϊobject��thread����һ���̣߳��������ӷ�ʽΪQt::QueuedConnection������object�����ڽ������̣߳�
�����߾���object��object�����߳�
```

#### �ܽ᣺
��1���ȿ����ӷ�ʽ
��2�������Ĭ�����ӷ�ʽ���жϷ����ߺͽ������Ƿ���ͬһ���̣߳�����ڣ���ôͬQt::DirectConnection��������ڣ�ͬQt::QueuedConnection
��3�������Qt::DirectConnection����ô�ۺ���ִ�е��̺߳ͷ����ߵ��߳�һ�������緢�����ڴ��̣߳���ô�ۺ���Ҳ�ڴ��̣߳������ͷ������̱߳���һ�£�
��4�������Qt::QueuedConnection����ô�ۺ���ִ�е��̺߳ͽ����ߵ��߳�һ��������������ڴ��̣߳���ô�ۺ���Ҳ�ڴ��̣߳������ͽ������̱߳���һ�£�


//================================================================================================================

#### 1.�¼��Ĵ��ݡ��ַ��봦
https://blog.csdn.net/luolaihua2018/article/details/110797592

#### 2.�¼�ѭ��
Qt�����¼�ѭ���ܹ����¼������л�ȡ���ش���ϵͳ�¼���Ȼ���ж��¼����ͣ������¼��ַ����ض��Ľ��ն���
���¼�ѭ��ͨ������QCoreApplication::exec()����������QCoreApplication::exit()���������ص��¼�ѭ����������QEventLoop������

#### 3.ignore()��accept()

#### 4.�¼�������

#### 5.Qt ���¼������������
��1����дpaintEvent()��mousePressEvent()���¼�����������������ͨ����򵥵���ʽ��ͬʱ����Ҳ��򵥡�
��2����дevent()������event()���������ж�����¼���ڣ�QObject��QWidget�е�ʵ�֣�Ĭ���ǰ��¼����ݸ��ض����¼���������
��3�����ض��������氲װ�¼����������ù����������˸ö�����յ����¼���
��4����QCoreApplication::instance()���氲װ�¼����������ù��������������ж���������¼�����˺�notify()����һ��ǿ�󣬵�����������Ϊ���԰�װ�����������ȫ�ֵ��¼����������Կ��� disabled ������淢��������¼���ȫ�ֹ�������һ�����⣺ֻ���������̡߳�
��5����дQCoreApplication::notify()������������ǿ��ģ���ȫ���¼�������һ���ṩ��ȫ���ƣ����Ҳ����̵߳����ơ�����ȫ�ַ�Χ��ֻ����һ����ʹ�ã���ΪQCoreApplication�ǵ����ģ���

#### 6.�źŲۡ����¼�������


//================================================================================================================

#### 1.Qt��TCPͨ�Ź���
https://zhuanlan.zhihu.com/p/393113128

����ˣ���QTcpServer��
(1)����QTcpServer����
(2)����list��Ҫ�Ĳ����ǵ�ַ�Ͷ˿ں�
(3)�����µĿͻ������ӳɹ��ط���newConnect�ź�
(4)��newConnection�źŲۺ����У�����nextPendingConnection������ȡ������QTcpSocket����
(5)����QTcpSocket�����readRead�ź�
(6)��readRead�źŵĲۺ���ʹ��read��������
(7)����write��Ա������������

�ͻ��ˣ���QTcpSocket��
(1)����QTcpSocket����
(2)��������Server���ӳɹ�ʱ�ᷢ��connected �ź�
(3)���ó�Ա����connectToHost���ӷ���������Ҫ�Ĳ����ǵ�ַ�Ͷ˿ں�
(4)connected�źŵĲۺ���������������
(5)ʹ��write�������ݣ�read��������

//================================================================================================================

#### 1.Qt��UDPͨ�Ź���
https://blog.csdn.net/m0_57266121/article/details/118942661
           
UDP��User Datagram Protocol���û����ݱ�Э�飩��һ���������ģ����ɿ��ģ��������ݱ���������Э�顣
��������������ʮ�ֲ�����Ļ����£�UDPЭ�����ݰ���ʧ���ء�
����UDP�����ԣ���������������Э�飬���������Դ����С�������ٶȿ���ŵ㣬����ͨ����Ƶ��
��Ƶ����ͨ�����ڴ���ʱʹ��UDP�϶࣬��Ϊ���Ǽ�ʹż����ʧһ�������ݰ���Ҳ����Խ��ս������̫��Ӱ�졣
����QQ���ֶԱ���Ҫ�󲢲�̫�ߵ�����������ʹ�õ�UDPЭ�顣
  
��Qt���ṩ��QUdpSocket ��������UDP���ݱ���datagrams���ķ��ͺͽ��ա�Socket�򵥵�˵������һ��IP��ַ��һ��port�˿�  ��
���̣�(1)����QUdpSocket�׽��ֶ��� (2)�����Ҫ�������ݣ�����󶨶˿� (3)����������writeDatagram������������ readDatagram ��

//================================================================================================================

1.Qt�е�MVD
Qt��MVD������������Model��ģ�ͣ���View����ͼ��������Delegate����
Model���򱣴����ݣ�View����չʾ���ݣ�Delegate����Item��ʽ���ƻ������롣
��������ͨ���źŲ�������ͨ�ţ���Model�����ݷ����仯ʱ���ᷢ���źŵ�View����View�б༭����ʱ��
Delegate���𽫱༭״̬���͸�Model�㡣����ֱ�ΪQAbstractItemModel��QAbstractItemView��QAbstractItemDelegate��
Qt���ṩ��Ĭ��ʵ�ֵ�MVD�࣬��QTableWidget��QListWidget��QTreeWidget�ȡ�

//================================================================================================================

#### 1.Qt��������
https://blog.csdn.net/weibuu/article/details/108802258

#### 1.���裺
��1��pro�ļ�������"TRANSLATIONS"������Ŀ������������Ӷ��".ts"�ļ���
```
TRANSLATIONS += a_cn.ts
TRANSLATIONS += a_en.ts
```
��2��ִ��lupdate��λ�ã�����-�ⲿ-Qt���Լ�-���·��롣����ts��������������룬ֻ��Ҫ�ٴ�ִ��lupdate��
��3����linguist���򣬷���ts�ļ���������ɺ�ִ��lrelease��λ�ã�linguist���-�ļ�-����������qm�ļ���
��4������qm�ļ���ָ��Ŀ¼������������
```
#�ѱ�Ŀ¼�µ�qm�ļ����Ƶ�language�ļ�
QM_LIST = mywidget_zh_CN.qm
DEST_LANGUAGE_PATH = $$system_path($$PWD/../../../../dist/qt5.6.3-win32-msvc2015/language)
!exists($${DEST_LANGUAGE_PATH}) {
    mkpath($${DEST_LANGUAGE_PATH})
}
for(qm, QM_LIST) {
    system(copy $$system_path($${qm}) $${DEST_LANGUAGE_PATH})
}
```
��5�����ض�Ӧ��qm�ļ������������
```
QDir qmDir(QApplication::applicationDirPath());
qmDir.cdUp();
qmDir.cd("language");
foreach (QFileInfo file, qmDir.entryInfoList(QDir::Files)) {
    if (file.suffix() == "qm") {
        QTranslator *translator = new QTranslator;
        if (translator->load(file.absoluteFilePath())) {
            a.installTranslator(translator);
        }
    }
}
```
��6�����ر�����л��������ԣ����ֶ�����ؼ�������ѡ��
```
void updateLanguage() 
{
	mLabel.setText(tr("name"));
	mBtn.setText(tr("name"));
}
```

//================================================================================================================

1.qt�ж��õ�����Щ���ģʽ
��1������ģʽ��qApp
��2���۲���ģʽ���źŲ�

//================================================================================================================

 Qt����ָ����C++����ָ�������
https://blog.csdn.net/iriczhao/article/details/122117218
https://zhuanlan.zhihu.com/p/364014571?ivk_sa=1024320u

//================================================================================================================

#### 7.q��dָ��Ϊ�˽��ʲô���⣿
Ϊ��������Ƽ���
��ν�����Ƽ��ݶ�̬�⣬ָ����һ�����ϰ汾�������еĳ����ڲ��������������£���Ȼ�ܹ����µİ汾�������У�
��Ҫ��������������°汾�����У�������Ҫ�޸ĸó���Դ���룬���Ǿ�˵�ö�̬����Դ������ݵ�;

//================================================================================================================

1.��α�ֻ֤��һ��exe
ʹ�� ϵͳ�ź��� QSystemSemaphore �� �����ڴ� QSharedMemory
```
    QSystemSemaphore sema("JAMKey",1,QSystemSemaphore::Open);
    sema.acquire();//���ٽ������������ڴ�  SharedMemory
    QSharedMemory mem("SystemObject");//ȫ�ֶ�����
    if (!mem.create(1))//���ȫ�ֶ����Դ������˳�
    {
        sema.release();//�����Unixϵͳ�����Զ��ͷš�
        return 0;
    }
    sema.release();//�ٽ���
```

//================================================================================================================

1.show() exec()����

ģʽ���ڣ����ڻ�ԭ��������ֻ�ܲ����ô��ڣ����ര�ڲ����ٲ�����ֻ�йرոô��ں󣬴��봦�Ż��÷���ֵ������ֹͣ���Ϳ��Բ������������ˣ�

��ģʽ���ڣ����ڻ�ԭ��α��������ȻҲ��ֻ�ܲ����ô��ڣ����ര�ڲ����ٲ��������Ǵ��������������У�����˵��α������

��ģʽ���ڣ����ڲ����������������������

ģʽ���ڣ�Dlg->exec();
��ģʽ���ڣ� Dlg->setModal(true); Dlg->show();
��ģʽ���ڣ�Dlg->show();

//================================================================================================================

#### Qt Android

//================================================================================================================

֪ʶ�㣺http://shouce.jb51.net/qt-beginning/48.html

�����⣺https://www.zhihu.com/question/451327108


#### 1.������� qt��QObject������ʲô�ģ�����Щ����?
�ܶ���ֻ֪�����źŲۻ����й�ϵ
������ܴ�� �������ڵ���� �������㼰��
�����ܻش�� rtti ��ʱ�� ����ϵͳ �Ⱦ�������
#### 2.���ϸ����� ��˵��qt�ĸ������ڵ�������
#### 3.�����ʣ�����qt������������������ܹ�������������ڣ�������Щ�����ڴ�й¶�Ļ���?
#### 4.�󲿷����ܴ������ָ�룬�Ϳ�������std::shared_ptr��ʵ�ֻ��ơ�
#### 5.���ܻش�� �������ü���������Ϊ0�����㣬��������¹���ʽָ���ȱ����ʲô?


#### 6.����˵�� ������ʧ��ѭ�����ã������������ƽ�ѭ�����á��������ָ�롣
#### 7.������3 ����ܴ���ڴ�أ����б�Ҫ�����ڴ�ص�ʵ�ֻ��ƺ����ڴ���з���������Ҫע�������? ���������ܻش����ʽ���ù��������������
#### 8.���ģʽ�����˵��qt�ж��õ�����Щ���ģʽ ����ܴ�� �۲���ģʽ ���÷�
���ܻش�� ���� ���� ������ ״̬�� ����¼ ��Ԫ װ���� ���������������ʹ�õ���?  ����ģʽ��ȱ��ʲô?
����8����������������ش�4������ ��˵��c++������ ������������ƺ����ģʽ�����յĲ���