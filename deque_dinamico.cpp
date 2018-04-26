#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef struct tipo_item{
	int chave;
}item;

typedef struct tipo_celula{
	struct tipo_item item;
	struct tipo_celula *prox;
	struct tipo_celula *ant;
}celula;

typedef struct tipo_deque{
	struct tipo_celula *sentinela;
}deque;

void inicializa(deque* d){
	d->sentinela = (celula*)malloc(sizeof(celula));
	d->sentinela->prox = d->sentinela;
	d->sentinela->ant = d->sentinela;
}

int vazio(deque* d){
	return d->sentinela->prox = d->sentinela;
}

void insere_dir(deque* d, item x){
	celula *novo = (celula*)malloc(sizeof(celula));

	novo->item = x;
	novo->ant = d->sentinela->ant;
	novo->prox = d->sentinela
	d->sentinela->ant->prox = novo;
	d->sentinela->ant = novo;
}

void insere_esq(deque* d, item x){
	celula *novo = (celula*)malloc(sizeof(celula));

	novo->item = x;
	novo->prox = d->sentinela->prox;
	novo->ant = d->sentinela;
	d->sentinela->prox->ant = novo;
	d->sentinela->prox = novo;
}

int remove_dir(deque* d, item* retorno){
	celula *aux;

	if(!vazio(d)){
		aux = d->sentinela->ant;
		*retorno = aux->item;
		aux->ant->prox = aux->prox;
		d->sentinela->ant = aux->ant;
		free(aux);
		return 1;
	}
	return 0;
}

int remove_esq(deque* d, item* retorno){
	celula *aux;

	if(!vazio(d)){
		aux = d->sentinela->prox;
		*retorno = aux->item;
		d->sentinela->prox = aux->prox;
		aux->prox->ant = aux->ant;
		free(aux);
		return 1;
	}
	return 0;
}
