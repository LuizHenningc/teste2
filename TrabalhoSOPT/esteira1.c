
#include <stdio.h>
#include <pthread.h>
#include "esteira1.h"
#include "esteira2.h"
#include "esteira3.h"

#define NUM_THREADS 3

int main() {
    pthread_t threads[NUM_THREADS];
    Esteira1Data esteira1_data;
    Esteira2Data esteira2_data;
    Esteira3Data esteira3_data;
    int i;

    // Inicialização dos dados compartilhados e dos mutexes
    esteira1_data.count = 0;
    esteira1_data.weight = 0.0;
    pthread_mutex_init(&esteira1_data.mutex, NULL);

    esteira2_data.count = 0;
    esteira2_data.weight = 0.0;
    pthread_mutex_init(&esteira2_data.mutex, NULL);

    esteira3_data.count = 0;
    esteira3_data.weight = 0.0;
    pthread_mutex_init(&esteira3_data.mutex, NULL);

    // Criação das threads para cada esteira
    pthread_create(&threads[0], NULL, esteira1, (void )&esteira1_data);
    pthread_create(&threads[1], NULL, esteira2, (void)&esteira2_data);
    pthread_create(&threads[2], NULL, esteira3, (void *)&esteira3_data);

    // Aguarda a finalização das threads
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Liberação dos mutexes
    pthread_mutex_destroy(&esteira1_data.mutex);
    pthread_mutex_destroy(&esteira2_data.mutex);
    pthread_mutex_destroy(&esteira3_data.mutex);

    return 0;
}
