#include <stdio.h>
#include <stdlib.h>


/* realice un programa que, utilizando punteros permita desde una funcion capturar el tamano de un arreglo, y desde
otra capture dichos valores en el arreglo. los valores deben ser positivos. Al final, se deberan imprimir los valores.

puede modificar el programa anterior para que ordene los eleentos del arreglo, empleando sintaxis de punteros, con
el algoritmo de ordennacion por insercion*/

 void espaciosPunteros(int*);
 void llenaPunteros(int*, int*);
 void ordenamientoINSERCION(int *,int*);
 void ordenamientoBURBUJA(int *,int *,int *);
 void ordenamientoSELECCION(int *,int *, int *);
 void impresion(int*, int *);
int main()
{
    int *pPuntero;
    int *tam;
    int numero;
    tam= (int *) malloc(sizeof(int));
    espaciosPunteros(tam);

    pPuntero= (int*)calloc(*tam,sizeof(int));
    llenaPunteros(tam, pPuntero);

    int *acum;
    acum= (int*)malloc(sizeof(int));

    printf("\n\t\tMenu:\n1- ordenamiento por insercion\n2- ordenamiento por burbuja \n3- ordenamiento por seleccion\n\nDigite un n%cmero entre (1-3):",163);
	scanf("%i",&numero);
switch(numero){
   case 1: ordenamientoINSERCION(tam,pPuntero);break;
    case 2: ordenamientoBURBUJA(tam,pPuntero,acum);break;
      case 3:ordenamientoSELECCION(tam,pPuntero,acum);break;
      default: printf("\nN%cmero incorrecto solo se mostraran segun el orden que los introdujo\n",163);
    }
    impresion(tam, pPuntero);
    return 0;
}


void espaciosPunteros(int *tam)
{
    do
    {
        printf("\nIngrese el tama%co que desea: ",164);
        scanf("%d",tam);

        if (*tam<=0)
        {
            printf("\nRango erroneo, vuelve a intentarlo");
        }
    }
    while (*tam<=0);


}
void llenaPunteros(int *tam, int *pPuntero)
{
    int i;
    for(i=0; i<*tam; i++)
    {
        do{
            printf("Ingrese el valor del espacio %i de %i: ",i+1, *tam);
            scanf("%d",(pPuntero+i));
        }while(*(pPuntero+i)<=0);
    }

}

void ordenamientoINSERCION(int *tam,int *arreglo)
{
    int i,j, saveValor;
    for(i=1; i<*tam; i++)
    {
        saveValor= *(arreglo+i);
        j=i-1;
        while(j>=0 && *(arreglo+j)>saveValor)
        {
            *(arreglo+j+1) = *(arreglo+j);
            j--;
        }
        *(arreglo+j+1)= saveValor;
    }
}

void ordenamientoBURBUJA(int *tam,int *array, int *acum)
{
    int i,j;


    for(i=0;i<*tam; i++)
    {
        for(j=0;j<*tam-1; j++)
        {
            if(*(array+j) > *(array+j+1))
            {
                *acum= *(array+j);
                *(array+j)= *(array+j+1);
                *(array+j+1)=*acum;
            }
        }
    }
}
void ordenamientoSELECCION(int *tam,int *array, int *acum)
{
    int i,j,sumando;

    for(i=0; i<*tam; i++)
    {
        sumando= i;

        for(j=i; j<*tam; j++)
        {
            if(*(array+j) < *(array+sumando))
        {
            sumando=j;
        }
    }
    *acum=*(array+i);
        *(array+i)= *(array+sumando);
        *(array+sumando)=*acum;

    }
}
void impresion(int *tam, int *pPuntero){
    int i;
    for(i = 0; i<*tam; i++)
    {
        printf("%d",*(pPuntero+i));
        printf("\n");
    }
}


