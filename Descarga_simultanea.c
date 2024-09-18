#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>  // Para usar sleep()

// Función para simular la descarga de un archivo
void* descargarArchivo(void* arg) {
    char* nombreArchivo = (char*)arg;
    for (int i = 1; i <= 5; ++i) {
        printf("Descargando %s: Bloque %d\n", nombreArchivo, i);
        sleep(1);  // Simula el tiempo de descarga
    }
    printf("Descarga completada: %s\n", nombreArchivo);
    return NULL;
}

int main() {
    pthread_t hilo1, hilo2;

    // Crear hilos para descargar archivos simultáneamente
    pthread_create(&hilo1, NULL, descargarArchivo, (void*)"archivo1.zip");
    pthread_create(&hilo2, NULL, descargarArchivo, (void*)"archivo2.zip");

    // Esperar a que ambos hilos terminen
    pthread_join(hilo1, NULL);
    pthread_join(hilo2, NULL);

    printf("Todas las descargas han terminado.\n");
    return 0;
}
