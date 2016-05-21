void bubleSort( int vetorDesordenado[], int tamanhoVetor )
{
   int i, j;
   for( i = 0; i < ( tamanhoVetor -1 );  i++ )
   {
      for( j=0; j <( tamanhoVetor -( i +1 ) ); j++ )
      {
         if( vetorDesordenado[j] > vetorDesordenado[j+1] )
         {
            trocarPosicaoValores( &vetorDesordenado[j], &vetorDesordenado[j+1] );
         }
      }
   }
}

void trocarPosicaoValores( int *posicaoA, int *posicaoB )
{
   int temporario;
   temporario = *posicaoA;
   *posicaoA = *posicaoB;
   *posicaoB = temporario;
}
