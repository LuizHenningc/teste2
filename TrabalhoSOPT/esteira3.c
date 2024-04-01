#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "esteira3.h"

#define MAX_ITEMS 1500

void esteira3(voidarg) {
    Esteira3Data data = (Esteira3Data)arg;
    float weight = 0.5; // Peso da esteira 3
    int items_processed = 0;

    while (1) {
        usleep(100000); // Simula a passagem de itens

        pthread_mutex_lock(&data->mutex);
        data->count++;
        data->weight += weight;
        items_processed++;

        if (items_processed >= MAX_ITEMS) {
            printf("Esteira 3: Peso total processado: %.2f Kg\n", data->weight);
            items_processed = 0;
        } else {
            printf("Esteira 3: Passou %.2f Kg\n", weight);
        }

        pthread_mutex_unlock(&data->mutex);
    }

    pthread_exit(NULL);
}
