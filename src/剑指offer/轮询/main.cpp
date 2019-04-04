#include <unistd.h>
#include <iostream>
#include <pthread.h>

static int i = 0;
int j;

void *th1(void *arg)
{
    while(i > 0) {
        while(j != 1);
        write(1, "A\n", 2);
        j = 2;
        i--;
    }
    return NULL;
}

void *th2(void *arg)
{
    while(i > 0) {
        while(j != 2);
        write(1, "B\n", 2);
        j = 3;
    }
    return NULL;
}

void *th3(void *arg)
{
    while(i > 0) {
        while(j != 3);
        write(1, "C\n", 2);
        j = 1;
    }
    return 0;
}


int main()
{
    i = 10;
    j = 1;
    pthread_t t1, t2, t3;
    pthread_create(&t1, NULL, th1, NULL);
    pthread_create(&t2, NULL, th2, NULL);
    pthread_create(&t3, NULL, th3, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    //pthread_exit(NULL);
    return 0;
}
