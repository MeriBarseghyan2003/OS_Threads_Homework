#include <stdio.h>
#include <pthread.h>

#define ARRAY_SIZE 5
int array[ARRAY_SIZE] = {1, 2, 3, 4, 5};

void* calculate_square(void* num) {
    int n = *(int*)num;
    printf("Square of %d is %d\n", n, n * n);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        pthread_create(&threads[i], NULL, calculate_square, &array[i]);
    }
    for (int i = 0; i < ARRAY_SIZE; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}
