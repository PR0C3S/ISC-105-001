#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAX = 1000, MIN = 0;
void CapturarValores(int [],int);
void MostrarValores(int [],int);
void GenerarValorees(int [],int);
long GenerarValoresRecursivos(int [],int,int);
int busquedaLinealNoRecursirva(int [],int, int);
int BusquedaLinealRecursiva(int [],int, int,int);
int BusquedaBinaria(int[], int, int);
int BusquedaBinariaRecuersiva(int [], int, int,int);
void MergeSortRecursivo(int[],int,int);
void Merge(int[], int, int,int [], int, int [], int) ;
void QuickSort(int[],int);
void QuicksortRecursivo(int[],int,int);
int Particionar(int[],int,int);
void Swap(int[],int, int);
void SwapPunteros(int*,int*);



int main()
{
    srand(time(NULL));
    int n, destino,posicion;
    printf("Digite el tama%co del arreglo:",164);
    scanf("%d",&n);
    int arreglo[n];

    // CapturarValores(arreglo,n);
    GenerarValorees(arreglo,n);
    MostrarValores(arreglo,n);
    printf("\n\nDigite el valor que desea buscar: ");
    scanf("%d",&destino);

    QuickSort(arreglo, n);

    //MergeSortRecursivo(arreglo, 0, n-1);
    MostrarValores(arreglo,n);

    posicion= busquedaLinealNoRecursirva(arreglo,n,destino);

    if(posicion>=0)
        printf("\nUsando b%csqueda Lineal fue encontrado en: %d",163,posicion+1);
    else
        printf("\nUsando b%csqueda lineal el valor %d no existe en el listado",163,destino);

    posicion= BusquedaBinaria(arreglo, n,destino);
    if(posicion>=0)
        printf("\n\nUsando b%csqueda Binario fue encontrado en: %d",163,posicion+1);
    else
        printf("\n\nUsando b%csqueda Binaria el valor %d no existe en el listado",163,destino);

    return 0;
}

void CapturarValores(int arreglo[],int tamano)
{
    int i;
    for(i=0; i<tamano; i++)
    {
        printf("%d: ",i+1);
        scanf("%d",&arreglo[i]);
    }
}

void GenerarValorees(int arreglo[],int tamano)
{
    long sumatoria = GenerarValoresRecursivos(arreglo, tamano, 0);
    printf("\nLa sumatoria de los aleatorios es: %ld\n",sumatoria);
}

long GenerarValoresRecursivos(int arreglo[],int tamano,int pos)
{
    if( pos >= tamano)
        return 0;

    arreglo[pos] = rand() % (MAX - MIN + 1) + MIN;    // se puede colocar esto en una funcion
    return arreglo[pos]+GenerarValoresRecursivos(arreglo,tamano, pos+1);

}

void MostrarValores(int arreglo[],int tamano)
{
    int i;
    printf("\nValores:\n\n");

    for(i=0; i<tamano; i++)
    {
        printf("%d\t",arreglo[i]);
    }
}


int busquedaLinealNoRecursirva(int arreglo[],int tamano, int destino)
{
    return BusquedaLinealRecursiva(arreglo,tamano,destino,0);
}


int BusquedaLinealRecursiva(int arreglo[],int tamano, int destino, int pos)
{
    ///AXIOMA

    if(pos >= tamano)
        return -1;

///                 CUERPO                   y       LLAMADA RECURSIVA
    return arreglo[pos] == destino ? pos : BusquedaLinealRecursiva(arreglo, tamano, destino, pos+1);

}

int BusquedaBinaria(int arreglo[], int tamano, int destino)
{
    return BusquedaBinariaRecuersiva(arreglo,destino, 0, tamano-1);
}
int BusquedaBinariaRecuersiva(int arreglo[],int destino, int limI,int limS)
{
    int centro;

    if(limI >limS)
        return -1;

    centro = (float)limI/2 + (float)limS;

    if(arreglo[centro] == destino)
        return centro;

    else if(arreglo[centro] > destino) // asumiendo que estan en orden creciente
        BusquedaBinariaRecuersiva(arreglo, destino, limI, centro-1);

    else
        return BusquedaBinariaRecuersiva(arreglo, destino, centro+1, limS);
}

void MergeSortRecursivo(int arreglo[],int limI,int limS)
{

    if(limI == limS)
        return;

    int TamanoIzquierdo, TamanoDerecho,i;

    if(((limS - limI) +1)% 2)
    {
        //si es impar
        TamanoIzquierdo = ((limS - limI)/2);
        TamanoDerecho = ((limS - limI)/2) +1;

    }

    else
        TamanoIzquierdo = TamanoDerecho = ((limS - limI)/2) +1;

    int izquierdo[TamanoIzquierdo], derecho[TamanoDerecho];


    // copiando la mitad izquierda:
    for(i=limI; i<TamanoIzquierdo; i++)
        izquierdo[i-limI] = arreglo[i];

    // copiando la mitad derecha:
    for(; i<=limS; i++)
        derecho[i-limI-TamanoIzquierdo]=arreglo[i];

    MergeSortRecursivo(izquierdo,0,TamanoIzquierdo-1);
    MergeSortRecursivo(derecho, 0, TamanoDerecho-1);

    Merge(arreglo, limI, limS, izquierdo, TamanoIzquierdo, derecho, TamanoDerecho);
}

void Merge(int arreglo[], int limI, int limS,int izq[], int tamanoI, int der[], int tamanoD)
{
    int i=0, j=0;

    while( i < tamanoI && j< tamanoD)
    {

        if(izq[i]<= der[j])
            arreglo[limI] = izq[i++];

        else
            arreglo[limI] = der[j++];

        limI++;
    }

    // Copiando los rematentes:
    while(i<tamanoI)
        arreglo[limI++] = izq[i++];

    while(j<tamanoD)
        arreglo[limI++] = der[j++];
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

   int i= limI+1;
   int j=i;

   for(; i<=limS; i++)
   {
      if(arreglo[i] < pivote)
      {
         Swap(arreglo, i, j);
         j++;
      }
   }

   SwapPunteros(&arreglo[limI], &arreglo[j-1]);
  // Swap(arreglo,limI,j-1);

   return j-1;
}

void Swap(int arreglo[],int Inicio, int Final)
{
   int burbuja;
   burbuja = arreglo[Inicio];
   arreglo[Inicio] = arreglo[Final];
   arreglo[Final] = burbuja;
}

void SwapPunteros(int *a,int *b)
{
   int *burbuja = (int*)malloc(sizeof(int));
   *burbuja = *a;
   *a = *b;
   *b = *burbuja;
}
