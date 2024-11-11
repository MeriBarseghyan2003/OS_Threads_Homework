#include <stdio.h>
#include <pthread.h>

#define ARRAY_SIZE 6

int array[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6};
int sum1 = 0, sum2 = 0;

void* calculate_sum(void* arg) {
    int start = *(int*)arg;
    int end = start + ARRAY_SIZE / 2;
    int* sum = (start == 0) ? &sum1 : &sum2;

    for (int i = start; i < end; i++) {
        *sum += array[i];
    }
    printf("Partial sum calculated by thread %d is %d\n", start / (ARRAY_SIZE / 2), *sum);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[2];
    int args[2] = {0, ARRAY_SIZE / 2};

    for (int i = 0; i < 2; i++) {
        pthread_create(&threads[i], NULL, calculate_sum, &args[i]);
    }
    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("Total sum: %d\n", sum1 + sum2);
    return 0;
}
