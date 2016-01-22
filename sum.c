#include <stdio.h>
#include <pthread.h>

int i = 0;

pthread_mutex_t lock; 

void* add(){
    for(int x = 0; x < 1000000; x++){
        pthread_mutex_lock(&lock);
        i++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void* sub(){
    for(int x = 0; x < 1000000; x++){
        pthread_mutex_lock(&lock);
        i--;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main(){
    pthread_mutex_init(&lock, NULL);

    pthread_t thread1;
    pthread_create(&thread1, NULL, add, NULL);

    pthread_t thread2;
    pthread_create(&thread2, NULL, sub, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("The sum is: %i\n", i);

    return 0;
};



