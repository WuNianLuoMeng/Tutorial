#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <iostream>
#include <pthread.h>
struct MyThread
{
    pthread_t th;
    int threadID;
};

class Example
{
private:
    static Example *obj;
    static pthread_mutex_t mutex;
    Example();
public:
    ~Example();
    static Example *getObject();
};

Example *Example::obj = nullptr;
pthread_mutex_t Example::mutex = PTHREAD_MUTEX_INITIALIZER;
Example::Example()
{
    const char *buf = "First time create Object\n";
    write(STDOUT_FILENO, buf, strlen(buf));
}
Example::~Example()
{
    if(obj != nullptr) {
        delete obj;
    }
    pthread_mutex_destroy(&mutex);
}
Example *Example::getObject()
{
    if(obj == nullptr) {
        pthread_mutex_lock(&mutex);
        if(obj == nullptr) {
            obj = new Example();
        }
        pthread_mutex_unlock(&mutex);
    }

    return obj;
}

pthread_mutex_t printMutex = PTHREAD_MUTEX_INITIALIZER;

void *run(void *arg)
{
    MyThread *th = (MyThread *)arg;
    Example *obj = Example::getObject();
    if(obj != nullptr) {
        pthread_mutex_lock(&printMutex);
        printf("Thread: %-5d get Object success\n", th -> threadID);
        pthread_mutex_unlock(&printMutex);
    }
    //pthread_exit(NULL);
    return nullptr;
}

MyThread thread[10];

int main()
{
    for(int i = 0; i < 10; i++) {
        thread[i].threadID = i + 1;
        pthread_create(&thread[i].th, nullptr, run, (void *)&thread[i]);

    }
    pthread_exit(NULL);
    return 0;
}
