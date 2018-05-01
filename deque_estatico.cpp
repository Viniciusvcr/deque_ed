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
		d->direita = anterior(d->direita);
		*retorno = d->dados[d->direita];
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
	for(int i=d->esquerda; i!=d->direita; i=proximo(i)){
		cout << d->dados[i].chave << " ";
	}
	cout << endl;
}

void escreve_dir(deque* d){ //exercício 1
	for(int i=anterior(d->direita); i!=anterior(d->esquerda); i=anterior(i)){
		cout << d->dados[i].chave << " ";
	}
	cout << endl << endl;
}

int extremidade_dir(deque* d){ //exercício 2a
	return d->dados[anterior(d->direita)].chave;
	//caso o deque esteja vazio, um lixo de memória será retornado
}

int extremidade_esq(deque* d){ //exercício 2b
	return d->dados[d->esquerda].chave;
	//caso o deque esteja vazio, um lixo de memória será retornado
}

void clear_screen(){
	system("clear");
}

int main(){
	deque A;
	int opt;
	item insere, retorno;

	inicializa(&A);
	do{
		fflush(stdin);
		cout << "[1] Status do deque" << endl;
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
					cout << "Deque Vazio!" << endl;
				else cout << "Deque nao vazio" << endl;
				
				if(cheio(&A))
					cout << "Deque cheio" << endl;
				else cout << "Deque nao cheio" << endl;
				cout << endl;
			break;

			case 2:
				clear_screen();
				cout << "Digite o elemento a ser inserido: ";
				cin >> insere.chave;
				if(insere_dir(&A, insere))
					cout << "ELEMENTO INSERIDO COM SUCESSO!\n" << endl;
				else cout << "LISTA CHEIA!\n" << endl;
			break;

			case 3:
				clear_screen();
				cout << "Digite o elemento a ser inserido: ";
				cin >> insere.chave;
				if(insere_esq(&A, insere))
					cout << "ELEMENTO INSERIDO COM SUCESSO!\n" << endl;
				else cout << "LISTA CHEIA\n" << endl;
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
				cout << "DEQUE COMPLETO (DIR->ESQ):" << endl;
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