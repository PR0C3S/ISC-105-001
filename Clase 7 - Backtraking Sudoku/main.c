#include <stdio.h>
#include <stdlib.h>

const int DIM= 9;

void CapturarMatriz(short matrizSudoku[DIM][DIM]);
void MostrarMatriz(short matrizSudoku[DIM][DIM]);
short ResolverSudoku(short matrizSudoku[DIM][DIM]);
short ResolverSudokuBT(short matrizSudoku[DIM][DIM], int, int);
short esValido(short matrizSudoku[DIM][DIM],int,int);

int main()
{
   short matrizSudoku[9][9] = { {0,6,0,0,0,0, 0,0,8},
                                {9,0,0,3,0,0, 0,6,0},
                                {8,7,0,0,0,0, 0,0,0},
                                {7,0,0,0,5,0, 0,0,0},
                                {0,0,0,7,0,3, 0,0,0},
                                {0,0,4,2,8,0, 0,3,0},
                                {3,9,0,4,0,0, 0,0,0},
                                {0,0,7,0,0,0, 5,0,6},
                                {0,0,5,0,0,1, 2,9,0}};

    //CapturarMatriz(matrizSudoku);
    printf("\n\nValidez: %d\n\n",esValido(matrizSudoku, 3,0));
    MostrarMatriz(matrizSudoku);
    if(!ResolverSudoku(matrizSudoku))
      printf("\nSudoku no es v%calido. \n",160);

    else
    {
       printf("\n\nMatriz Resuelta: \n\n\n\n");
      MostrarMatriz(matrizSudoku);

    }




    return 0;
}

void CapturarMatriz(short matrizSudoku[DIM][DIM])
{
   int i, j;
   for(i=0;i<DIM;i++)
   {
      for(j=0;j<DIM;j++)
      {
         printf("%d, %d: ",i+1,j+1);
         scanf("%d",&matrizSudoku[i][j]);
      }
   }
}


void MostrarMatriz(short matrizSudoku[DIM][DIM])
{
   int i, j;
   for(i=0;i<DIM;i++)
   {
      for(j=0;j<DIM;j++)
      {
         printf("%d\t",matrizSudoku[i][j]);
      }
      printf("\n");
   }

}

short ResolverSudoku(short matrizSudoku[DIM][DIM])
{
   return ResolverSudokuBT(matrizSudoku, 0,0);
}

short ResolverSudokuBT(short matrizSudoku[DIM][DIM], int x, int y)
{
   int tanteoActual;
   if( y >= DIM)
      return 1;

   if(x >= DIM)
      return ResolverSudokuBT(matrizSudoku, 0, y+1);

   if(matrizSudoku[y][x] != 0)
      return ResolverSudokuBT(matrizSudoku, x+1, y);

   for(tanteoActual =1;tanteoActual<=DIM;tanteoActual++)
   {
      matrizSudoku[y][x]= tanteoActual;
      if(esValido(matrizSudoku,x,y))
      {
         if(ResolverSudokuBT(matrizSudoku,x+1,y))
            return 1;
      }
   }

   matrizSudoku[y][x]=0;

   return 0;
}

short esValido(short matrizSudoku[DIM][DIM],int x,int y)
{
   int i,j;
   short encontrado=0;
   /// fila:
   for(i=0;i<DIM; i++)
   {
      encontrado+= matrizSudoku[y][i] == matrizSudoku[y][x] ? 1 : 0;
      if(encontrado>1)
         return 0;

   }

   ///columna:
   encontrado= 0;
   for(i=0;i<DIM; i++)
   {
      encontrado+= matrizSudoku[i][x] == matrizSudoku[y][x] ? 1 : 0;
      if(encontrado>1)
         return 0;

   }

   ///bloque:
   encontrado=0;
   for(i= y -(y % 3); i< (y- (y % 3)+3);i++)
   {
      for(j=x-(x % 3); j<(x- (x % 3)+3); j++)
      {
         encontrado+= matrizSudoku[i][j] == matrizSudoku[y][x] ? 1 : 0;
      }
   }

   if(encontrado > 1)
      return 0;

   return 1;


}
