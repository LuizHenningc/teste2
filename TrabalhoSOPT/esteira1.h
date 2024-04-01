
#ifndef ESTEIRA1_H
#define ESTEIRA1_H

#include <pthread.h>

typedef struct {
    int count;
    float weight;
    pthread_mutex_t mutex;
} Esteira1Data;

void esteira1(voidarg);

#endif
