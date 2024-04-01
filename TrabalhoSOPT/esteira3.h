
#ifndef ESTEIRA3_H
#define ESTEIRA3_H

#include <pthread.h>

typedef struct {
    int count;
    float weight;
    pthread_mutex_t mutex;
} Esteira3Data;

void esteira3(voidarg);

#endif
