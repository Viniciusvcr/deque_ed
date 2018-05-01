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
	return d->sentinela->prox == d->sentinela;
}

void insere_dir(deque* d, item x){
	celula *novo = (celula*)malloc(sizeof(celula));

	novo->item = x;
	novo->ant = d->sentinela->ant;
	novo->prox = d->sentinela;
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

void escreve_dir(deque* d){ //exercício 1
	celula *aux = d->sentinela->prox;

	while(aux != d->sentinela){
		cout << aux->item.chave << " ";
		aux = aux->prox;
	}
	cout << endl << endl;
}

int extremidade_dir(deque* d){ //exercício 3a
	return d->sentinela->ant->item.chave;
	//Caso o deque esteja vazio, a função irá
	//retornar o valor da sentinela, que é considerado
	//lixo de memória
}

int extremidade_esq(deque* d){ //exercício 3b
	return d->sentinela->prox->item.chave;
	//Caso o deque esteja vazio, a função irá
	//retornar o valor da sentinela, que é considerado
	//lixo de memória
}

void clear_screen(){
	system("clear");
}

int main(){
	deque A;
	int opt;
	char c;
	item insere, retorno;

	inicializa(&A);
	do{
		fflush(stdin);
		cout << "[1] Vazio?" << endl;
		cout << "[2] Inserir na direita" << endl;
		cout << "[3] Inserir na esquerda" << endl;
		cout << "[4] Remover na direita" << endl;
		cout << "[5] Remover na esquerda" << endl;
		cout << "[6] Escrever direita p/ esquerda" << endl;
		cout << "[7] Extremidade direita" << endl;
		cout << "[8] Extremidade esquerda" << endl;
		cin >> opt;
		switch(opt){
			case 1:
				if(vazio(&A))
					cout << "Deque Vazio!\n" << endl;
				else cout << "Deque nao vazio\n" << endl;
				getchar();
			break;

			case 2:
				clear_screen();
				cout << "Digite o elemento a ser inserido: ";
				cin >> insere.chave;
				insere_dir(&A, insere);
				cout << "ELEMENTO INSERIDO COM SUCESSO!\n" << endl;
			break;

			case 3:
				clear_screen();
				cout << "Digite o elemento a ser inserido: ";
				cin >> insere.chave;
				insere_esq(&A, insere);
				cout << "ELEMENTO INSERIDO COM SUCESSO!\n" << endl;
			break;

			case 4:
				if(remove_dir(&A, &retorno))
					cout << retorno.chave << " REMOVIDO COM SUCESSO\n" << endl;
				else cout << "ERRO NA REMOCAO\n" << endl;
			break;

			case 5:
				if(remove_esq(&A, &retorno))
					cout << retorno.chave << " REMOVIDO COM SUCESSO\n" << endl;
				else cout << "ERRO NA REMOCAO\n" << endl;
			break;

			case 6:
				cout << "DEQUE COMPLETO:" << endl;
				escreve_dir(&A);
			break;

			case 7:
				cout << "Extremidade direita: " << extremidade_dir(&A) << endl << endl;
			break;

			case 8:
				cout << "Extremidade esquerda: " << extremidade_esq(&A) << endl << endl;
			break;
		}
	}while(opt != 0);
}
