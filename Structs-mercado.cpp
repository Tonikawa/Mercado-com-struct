//Fabio Silveira Tanikawa TIA:32092563, 
//Gabriel Batista Cristiano TIA:32090722, 
//Guilherme de Souza Valente | TIA: 32034008
//Julia Carvalho de Souza Castro TIA: 32022298
//Mercado de 5 produtos 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//Criando a struct 
typedef struct{
    int codigo;
    char nome[30];
    float valor_unitario;
    int qtde_estoque;
}PRODUTO;

void insertionSort(PRODUTO *vetor);
void estoque(PRODUTO *vetor);
void compra(PRODUTO *vetor);
int verificaEntrada(int entrada, PRODUTO *vetor);
float atualizaEstoque(int retorno, PRODUTO *vetor);

int main(void)
{
  /* Criando a variável produtos que será um vetor do
  tipo struct PRODUTO */ 
  PRODUTO produtos[4], p;
  int i;
  
  printf("\n---------- Leitura de Produtos -----------\n\n\n");

  for(i = 0; i<3; i++)
    {
      printf("Digite o codigo do %d produto: ", i+1);
      scanf(" %d", &p.codigo);
      printf("Digite o nome do %d produto: ", i+1);
      scanf(" %s", &p.nome);
      printf("Digite o valor unitario do %d produto: ", i+1);
      scanf(" %f", &p.valor_unitario);
      printf("Digite o numero de unidades do %d produto a ser armazenada: ", i+1);
      scanf(" %d", &p.qtde_estoque);

      produtos[i] = p;  
      printf("\n\n");      
    }

  insertionSort(produtos);
  estoque(produtos);
  compra(produtos);
  estoque(produtos);
  

  return(0);
}

void insertionSort(PRODUTO *vetor)
{
  PRODUTO aux;
  int j;
  for(int i = 1; i < 3; i++)
    {
      aux = vetor[i];
      for(j = i; (j>0) && (aux.codigo < vetor[j - 1].codigo); j--)
        vetor[j] = vetor[j - 1];
      vetor[j] = aux;
    }
}

void estoque(PRODUTO *vetor)
{
  printf("\n---------- ESTOQUE -----------\n\n\n");

  for(int i = 0; i<3; i++)
    {
      printf("Codigo do produto: %d\n", vetor[i].codigo);
      printf("Nome do produto: %s\n", vetor[i].nome);
      printf("Valor do produto: %2.f\n", vetor[i].valor_unitario);
      printf("Quantidade do produto: %d\n", vetor[i].qtde_estoque);
      printf("\n\n");
    }
  
}

void compra(PRODUTO *vetor)
{
  int entrada, valor1, valor2, valor3;
  int retorno = 5;
  float totalP, total;
  bool control;
  printf("---------- COMPRA  -----------\n\n\n");
  for(int x = 0; x < 3; x++)
    {      
      while (retorno == 5)
        {
          printf("Digite um codigo válido do produto a ser comprado: ");
          scanf(" %d", &entrada);
          retorno = verificaEntrada(entrada, vetor);
          if (retorno != 5)
          {
            totalP = atualizaEstoque(retorno, vetor);
            total = total + totalP;
          }
        }
        retorno = 5;
    }
  printf("Valor total da compra: %2.f", total); 
}

int verificaEntrada(int entrada, PRODUTO *vetor)
{
  for (int i = 0; i < 3; i++)
    {
      if (vetor[i].codigo == entrada)
      {
        return i;
      }
    }
  return 5;
}

float atualizaEstoque(int retorno, PRODUTO *vetor)
{
  int qtde = 0;
  float valCompra;
  while (qtde == 0 || qtde > vetor[retorno].qtde_estoque)
    {
       printf("Digite uma quantidade válida de unidades a ser comprada: ");
       scanf(" %d", &qtde);     
    }
  vetor[retorno].qtde_estoque = vetor[retorno].qtde_estoque - qtde;
  valCompra = vetor[retorno].valor_unitario * qtde;
  printf("Valor da compra: %2.f \n", valCompra);
  return valCompra;
}
// ---------- REFERENCIAS ---------- 
// http://linguagemc.com.br/struct-em-c/
// https://www.youtube.com/watch?v=3Iqe7oUDuQE