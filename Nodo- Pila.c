#include<stdio.h>
#include<stdlib.h>

typedef struct nodo
{
   float dato;
   struct nodo *siguiente;
}nodo;
nodo* primero = NULL;

nodo* insertarNodo(nodo*,float);
void desplegarNodo(nodo*,int cantidad, int total);
void MostrarEncabezadoHistograma();
void MostrarElementoHistograma(int, float, float);
void MostrarPieHistograma(int, float);





nodo* insertarNodo(nodo*enlace, float valor)
{
   nodo* nuevo = (nodo*)malloc(sizeof(nodo));
   nuevo->dato = valor;
   nuevo->siguiente = enlace;
   primero = nuevo;
   return nuevo;
}

void desplegarNodo(nodo* primero,int cantidad, int total)
{
   nodo* actual = (nodo*)malloc(sizeof(nodo));
   actual = primero;

   if(primero != NULL)
   {
      MostrarEncabezadoHistograma();
         while( actual != NULL)
         {

             MostrarElementoHistograma(cantidad, actual->dato,(actual->dato/total*100));
              cantidad--;


            actual= actual->siguiente;
         }
   }

   else
   {
      MostrarPieHistograma(cantidad, total);
   }
}

int main(){

int  cantidad=0;
float valor, total= 0;

do{
   printf("\nIngrese un valor (-1) para salir: ");
   scanf("%f",&valor);

   if(valor >= 0){
      total+=valor;
      cantidad++;
      primero= insertarNodo(primero,valor);
     }

}while(valor!= -1);
desplegarNodo(primero,cantidad,total);



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
