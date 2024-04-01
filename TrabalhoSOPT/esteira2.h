
#ifndef ESTEIRA2_H
#define ESTEIRA2_H

#include <pthread.h>

typedef struct {
    int count;
    float weight;
    pthread_mutex_t mutex;
} Esteira2Data;

void esteira2(voidarg);

#endif
