#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define TAM 100
using namespace std;

typedef struct tipo_item{
	int chave;
}item;

typedef struct tipo_deque{
	int direita, esquerda;
	struct tipo_item dados[TAM];
}deque;

void inicializa(deque* d){
	d->direita = 0;
	d->esquerda = 0;
}

int proximo(int pos){
	return (pos+1)%TAM;
}

int anterior(int pos){
	return (pos+(TAM-1))%TAM;
}

int vazio(deque* d){
	return d->direita == d->esquerda;
}

int cheio(deque* d){
	return proximo(d->direita) == d->esquerda;
}

int insere_dir(deque* d, item x){
	if(!cheio(d)){
		d->dados[d->direita] = x;
		d->direita = proximo(d->direita);
		return 1;
	}
	return 0;
}

int insere_esq(deque* d, item x){
	if(!cheio(d)){
		d->esquerda = anterior(d->esquerda);
		d->dados[d->esquerda] = x;
		return 1;
	}
	return 0;
}

int remove_dir(deque* d, item* retorno){
	if(!vazio(d)){
		d->direta = anterior(d->direta);
		*retorno = d->dados[d->direta];
		return 1;
	}
	return 0;
}

int remove_esq(deque* d, item* retorno){
	if(!vazio(d)){
		*retorno = d->dados[d->esquerda];
		d->esquerda = proximo(d->esquerda);
		return 1;
	}
	return 0;
}

void escreve_deque(deque* d){
	for(int i=d->esquerda; i!=d->direta; i=proximo(i)){
		cout << d->dados[i].chave << " ";
	}
	cout << endl;
}

int main(){

}