#include <stdio.h>
#include <pthread.h>

void* print_message(void* threadid) {
    long tid = (long)threadid;
    printf("Thread %ld is running\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3];
    int rc;
    for (long i = 0; i < 3; i++) {
        rc = pthread_create(&threads[i], NULL, print_message, (void*)i);
        if (rc) {
            printf("Error: unable to create thread %d\n", rc);
            return -1;
        }
    }
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("All threads completed.\n");
    return 0;
}
