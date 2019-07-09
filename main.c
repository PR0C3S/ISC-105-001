#include <stdio.h>
#include <stdlib.h>
#include "Pilaestatica.h"

void MostrarEncabezadoHistograma();
void MostrarElementoHistograma(int, float, float);
void MostrarPieHistograma(int, float);

int main(){
   int cantidad=0;
   float nuevoValor, total=0;
    Pila *miPila;
    miPila= IniciarPila(miPila);

    do
    {
       printf("\nDigite un valor: (-1 para terminar): ");
       scanf("%f",&nuevoValor);
       if(nuevoValor >= 0)
       {
            total+=nuevoValor;
          //  cantidad++;
         Push(miPila,nuevoValor);
       }
    }while(nuevoValor >=0);
    // o calcular la cantidad de esta forma cantidad= Size(miPila);
    MostrarEncabezadoHistograma();

    while(!isEmpty(miPila))
    {
       cantidad++;
       nuevoValor= Pop(miPila);
       MostrarElementoHistograma(cantidad, nuevoValor,nuevoValor/total*100);
    }

    MostrarPieHistograma(cantidad,total);
    return 0;
}

void MostrarEncabezadoHistograma()
{
   system("cls");
   printf("HISTOGRAMA\n\n");
   printf("No.: \tValor:\tProporci%con\n",162);

}
void MostrarElementoHistograma(int secuencia, float valor, float proporcion)
{
   int cantidadCaracteres = (int)proporcion;
   printf("%d\t%.2f\t",secuencia, valor);

   while(cantidadCaracteres-- >0)
   {
      printf("%c",219);
   }

   printf(" %2.f%%\n",proporcion);

}
void MostrarPieHistograma(int cantidad, float total)
{
   printf("Se han mostrado %d elementos. Total: %.2f",cantidad ,total);
}
