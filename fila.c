#include "fila.h"
//========================================
void print_pessoa(Pessoa p)
{
    printf("{nome: %s, idade: %d}\n", p.nome, p.idade);
}
//========================================
Celula *new_celula()
{
    Celula *tmp = (Celula *)malloc(sizeof(Celula));
    tmp->prox = NULL;
    return tmp;
}
//========================================
void new_fila(Fila *f)
{
    Celula *nova = new_celula();

    f->inicio = nova;
    f->fim = nova;
    f->tam = 0;
}
//========================================
void enqueue(Fila *f, Pessoa dado)
{
    Celula *nova = new_celula();
    nova->dado = dado;

    f->fim->prox = nova;
    f->fim = nova;
    f->tam++;
}
//========================================
void print_fila(Fila *f)
{
    Celula *tmp = f->inicio->prox;

    while (tmp != NULL)
    {
        print_pessoa(tmp->dado);
        tmp = tmp->prox;
    }
}
//========================================
int size_fila(Fila *f)
{
    return f->tam;
}
//========================================
Pessoa dequeue(Fila *f)
{
    if (f->tam == 0)
    {
        Pessoa p = {"Invalido", -1};
        return p;
    }

    Celula *tmp = f->inicio;

    f->inicio = f->inicio->prox;

    free(tmp);

    f->tam--;

    return f->inicio->dado;
}
//========================================
void enqueue_prioridade(Fila *f, Pessoa dado){
  Celula *nova = (Celula*)malloc(sizeof(Celula));
  nova->prox = NULL;
  nova->dado = dado;
  
  Celula *ant = f->inicio;
  
  while(ant->prox != NULL && (ant->prox->dado.idade > 75  || ant->prox->dado.ehSaude)) {
    ant = ant->prox;
  }

  nova->prox = ant->prox;
  ant->prox = nova;

  if(nova->prox == NULL)
    f->fim = nova;

  f->tam++;
}
//========================================
void enqueue_fase_1(Fila *f, Pessoa dado){
  Celula *nova = (Celula*)malloc(sizeof(Celula));
  nova->prox = NULL;
  nova->dado = dado;
  
  Celula *ant = f->inicio;
  
  if(ant->prox->dado.idade > 75  || ant->prox->dado.ehSaude)
    while(ant->prox != NULL && (ant->prox->dado.idade > 75  || ant->prox->dado.ehSaude)) {
      ant = ant->prox;
    }
  else if(ant->prox->dado.idade >= 60)
    while(ant->prox != NULL && ant->prox->dado.idade >= 60) {
      ant = ant->prox;
    }
  else if(ant->prox->dado.ehComorbidade)
    while(ant->prox != NULL && ant->prox->dado.idade >= 60) {
      ant = ant->prox;
    }
  else if(ant->prox->dado.idade >= 60)
    while(ant->prox != NULL && ant->prox->dado.idade >= 60) {
      ant = ant->prox;
    }  

  nova->prox = ant->prox;
  ant->prox = nova;

  if(nova->prox == NULL)
    f->fim = nova;

  f->tam++;
}
//========================================
void enqueue_fase_2(Fila *f, Pessoa dado){
  Celula *nova = (Celula*)malloc(sizeof(Celula));
  nova->prox = NULL;
  nova->dado = dado;
  
  Celula *ant = f->inicio;
  
  while(ant->prox != NULL && (ant->prox->dado.idade >= 60)) {
    ant = ant->prox;
  }

  nova->prox = ant->prox;
  ant->prox = nova;

  if(nova->prox == NULL)
    f->fim = nova;

  f->tam++;
}
//========================================
void enqueue_fase_3(Fila *f, Pessoa dado){
  Celula *nova = (Celula*)malloc(sizeof(Celula));
  nova->prox = NULL;
  nova->dado = dado;
  
  Celula *ant = f->inicio;
  
  while(ant->prox != NULL && ant->prox->dado.ehComorbidade > 75) {
    ant = ant->prox;
  }

  nova->prox = ant->prox;
  ant->prox = nova;

  if(nova->prox == NULL)
    f->fim = nova;

  f->tam++;
}
//========================================
void enqueue_fase_4(Fila *f, Pessoa dado){
  Celula *nova = (Celula*)malloc(sizeof(Celula));
  nova->prox = NULL;
  nova->dado = dado;
  
  Celula *ant = f->inicio;
  
  while(ant->prox != NULL && ant->prox->dado.idade > 75) {
    ant = ant->prox;
  }

  nova->prox = ant->prox;
  ant->prox = nova;

  if(nova->prox == NULL)
    f->fim = nova;

  f->tam++;
}
//========================================
