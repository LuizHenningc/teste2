#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "esteira2.h"

#define MAX_ITEMS 1500

void esteira2(voidarg) {
    Esteira2Data data = (Esteira2Data)arg;
    float weight = 2.0; // Peso da esteira 2
    int items_processed = 0;

    while (1) {
        usleep(500000); // Simula a passagem de itens

        pthread_mutex_lock(&data->mutex);
        data->count++;
        data->weight += weight;
        items_processed++;

        if (items_processed >= MAX_ITEMS) {
            printf("Esteira 2: Peso total processado: %.2f Kg\n", data->weight);
            items_processed = 0;
        } else {
            printf("Esteira 2: Passou %.2f Kg\n", weight);
        }

        pthread_mutex_unlock(&data->mutex);
    }

    pthread_exit(NULL);
}
