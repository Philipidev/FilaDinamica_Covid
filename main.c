#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fila.h"

int main(void) {
  Fila fila;
  new_fila(&fila);
  
  for(int i=0;i<10;i++){
    Pessoa p;
    int num = rand()%100 + 30;
    sprintf(p.nome, "P%d", num);
    p.idade = num;
    enqueue(&fila, p);
  }

  Pessoa p;
  int num = 200;
  strcpy(p.nome, "testePrioridade");
  p.idade = num;
  enqueue_fase_1(&fila, p);
  print_fila(&fila);
}