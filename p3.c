#include <stdio.h>
#include <pthread.h>

void* print_numbers(void* threadid) {
    long tid = (long)threadid;
    for (int i = 1; i <= 5; i++) {
        printf("Thread %ld: %d\n", tid, i);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3];
    for (long i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, print_numbers, (void*)i);
    }
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}
