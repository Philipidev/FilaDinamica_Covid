#ifndef FILA_H
#define FILA_H
//========================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//========================================
typedef struct Pessoa
{
    char nome[100];
    int idade;
    //char profissao[100];
    bool ehComorbidade;
    bool ehSaude;
} Pessoa;
void print_pessoa(Pessoa p);
//========================================
typedef struct Celula
{
    Pessoa dado;
    struct Celula *prox;
} Celula;
//========================================
typedef struct Fila
{
    Celula *inicio;
    Celula *fim;
    int tam;
} Fila;
//========================================
Celula *new_celula();
//========================================
void new_fila(Fila *f);
//========================================
void enqueue(Fila *f, Pessoa dado);
//========================================
void print_fila(Fila *f);
//========================================
int size_fila(Fila *f);
//========================================
Pessoa dequeue(Fila *f);
//========================================
void enqueue_fase_1(Fila *f, Pessoa dado);
//========================================
void enqueue_fase_2(Fila *f, Pessoa dado);
//========================================
void enqueue_fase_3(Fila *f, Pessoa dado);
//========================================
void enqueue_fase_4(Fila *f, Pessoa dado);
#endif