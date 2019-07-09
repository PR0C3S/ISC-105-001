#include <stdio.h>
#include <stdlib.h>
#include "versionPuntero.h"
#include "versionMatriz.h"


int main()
{

    int filaReina, columnaReina;

    printf("Digite la posicion inicial de la reina:");
    scanf("%d %d", &filaReina, &columnaReina);

    //mainMatriz(filaReina, columnaReina);
    mainPuntero(filaReina, columnaReina);

    return 0;
}
