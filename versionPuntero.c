#include <stdio.h>
#include <stdlib.h>

#ifndef _mainPunteros
#define _mainPunteros

void mainPuntero(int filaReina, int columnaReina)
{
    const int FIL = 8, COL = 8;
    int **tablero = calloc(FIL, sizeof(int*));
    int i, j;

    for(i = 0; i<FIL; i++)
    {
        *(tablero+i) = calloc(COL, sizeof(int));

        for(j = 0; j<COL; j++)
        {
            if(i == filaReina || j == columnaReina)
                *(*(tablero+i)+j) = '*';
            else if(i-j == filaReina-columnaReina || i+j == filaReina+columnaReina)
            {
                *(*(tablero+i)+j) = '*';
            }else
                *(*(tablero+i)+j) = '0';
        }
    }

    *(*(tablero+filaReina)+columnaReina) = 'R';

    for(i = 0; i<FIL; i++)
    {
        for(j = 0; j<COL; j++)
        {
            printf("%c", *(*(tablero+i)+j));
            printf("\t");
        }
        printf("\n");
    }
}

#endif // _mainPunteros
