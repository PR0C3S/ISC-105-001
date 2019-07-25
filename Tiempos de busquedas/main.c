#include <stdio.h>
#include <stdlib.h>

void GenerarValorees(int [],int);
long GenerarValoresRecursivos(int [],int,int);
void MetodoBurbuja(int [], int);
void MetodoSeleccion(int[], int);
void Insercion(int[], int);
long MergeSortRecursivo(int[],int,int, long);
long Merge(int[], int, int,int [], int, int [], int, long);
void QuickSort(int[],int);
void QuicksortRecursivo(int[],int,int);
int Particionar(int[],int,int);
void Swap(int[],int, int);

const int MAX = 15000, MIN = 0;

int main()
{
   srand(time(NULL));


    int n=15000,arreglo[n];

    GenerarValorees(arreglo,n);
    //Insercion(arreglo,n);
   // pasos = MergeSortRecursivo(arreglo, 0, n-1,pasos);
   QuickSort(arreglo,n);

    printf("\nacabe");
    return 0;
}


void GenerarValorees(int arreglo[],int tamano)
{
    long sumatoria = GenerarValoresRecursivos(arreglo, tamano, 0);

}

long GenerarValoresRecursivos(int arreglo[],int tamano,int pos)
{
    if( pos >= tamano)
        return 0;

    arreglo[pos] = rand() % (MAX - MIN + 1) + MIN;    // se puede colocar esto en una funcion
    return arreglo[pos]+GenerarValoresRecursivos(arreglo,tamano, pos+1);

}

void MetodoBurbuja(int array[], int MAXe){
	int ind, cont,change=0;
	long pasos=0;

	for(ind=0;ind<MAXe;ind++,pasos++){
		for(cont=0;cont<(MAXe-1);cont++,pasos++){
			if(array[cont]>array[cont+1]){
				change = array[cont];
				array[cont] = array[cont+1];
				array[cont+1] = change;
			}
		}
	}
	printf(" pasos: %ld",pasos);
}

void MetodoSeleccion(int  x[], int n){

  int minimo=0,i,j;
  long pasos=0;
  int swap;
  for(i=0 ; i<n-1 ; i++,pasos++)
  {
     minimo=i;
     for(j=i+1 ; j<n ; j++,pasos++){
        if (x[minimo] > x[j]){
         minimo=j;
         pasos++;}
     }

     swap=x[minimo];
     x[minimo]=x[i];
     x[i]=swap;
  }
  printf(" pasos: %ld",pasos);
  }

void Insercion(int numbers[], int array_size) {
  int i, a, index;
  long pasos=0;
  for (i=1; i < array_size; i++,pasos++) {
    index = numbers[i];
    a = i-1;
    while (a >= 0 && numbers[a] > index) {
      numbers[a + 1] = numbers[a];
      a--;
      pasos++;
    }
    numbers[a+1] = index;

  }
  printf(" pasos: %ld",pasos);
}

long MergeSortRecursivo(int arreglo[],int limI,int limS, long pasos)
{

    if(limI == limS){
         pasos++;
        return;}

    int TamanoIzquierdo, TamanoDerecho,i;

    if(((limS - limI) +1)% 2)
    {
        //si es impar
        TamanoIzquierdo = ((limS - limI)/2);
        TamanoDerecho = ((limS - limI)/2) +1;
        pasos++;

    }

    else{
        TamanoIzquierdo = TamanoDerecho = ((limS - limI)/2) +1;
     pasos++;
    }

    int izquierdo[TamanoIzquierdo], derecho[TamanoDerecho];


    // copiando la mitad izquierda:
    for(i=limI; i<TamanoIzquierdo; i++){
        izquierdo[i-limI] = arreglo[i];
        pasos++;
    }

    // copiando la mitad derecha:
    for(; i<=limS; i++){
        derecho[i-limI-TamanoIzquierdo]=arreglo[i];
pasos++;
    }
    MergeSortRecursivo(izquierdo,0,TamanoIzquierdo-1,pasos);
    MergeSortRecursivo(derecho, 0, TamanoDerecho-1,pasos);

    pasos+= Merge(arreglo, limI, limS, izquierdo, TamanoIzquierdo, derecho, TamanoDerecho,pasos);
    return pasos;
}

long Merge(int arreglo[], int limI, int limS,int izq[], int tamanoI, int der[], int tamanoD, long pasos)
{
    int i=0, j=0;

    while( i < tamanoI && j< tamanoD)
    {

        if(izq[i]<= der[j]){
            arreglo[limI] = izq[i++];
        pasos++;
        }


        else
       {arreglo[limI] = der[j++];

        limI++;
        pasos++;

        }
    }

    // Copiando los rematentes:
    while(i<tamanoI){
        arreglo[limI++] = izq[i++];
        pasos++;
    }

    while(j<tamanoD){
        arreglo[limI++] = der[j++];
        pasos++;
    }

    return pasos;
}

void QuickSort(int arreglo[],int tamano)
{

   QuicksortRecursivo(arreglo, 0, tamano-1);

}

void QuicksortRecursivo(int arreglo[],int limI,int limS)
{
   int indicePivote;

   if(limI >= limS)
      return;

   indicePivote = Particionar(arreglo, limI, limS);

   QuicksortRecursivo(arreglo, limI, indicePivote-1);
   QuicksortRecursivo(arreglo, indicePivote+1, limS);


}

int Particionar(int arreglo[],int limI,int limS)
{
   int pivote = arreglo[limI];
   long pasos=0;

   int i= limI+1;
   int j=i;

   for(; i<=limS; i++,pasos++)
   {
      if(arreglo[i] < pivote)
      {
         Swap(arreglo, i, j);
         j++;
         pasos++;
      }
   }
   // printf("\n Pasos: %d",pasos);

   //SwapPunteros(&arreglo[limI], &arreglo[j-1]);
   Swap(arreglo,limI,j-1);

   return j-1;
}

void Swap(int arreglo[],int Inicio, int Final)
{
   int burbuja;
   burbuja = arreglo[Inicio];
   arreglo[Inicio] = arreglo[Final];
   arreglo[Final] = burbuja;
}
