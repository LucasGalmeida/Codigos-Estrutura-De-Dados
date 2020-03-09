#include "AVL.h"

void Cria_Arvore(Apont *Raiz) {

	(*Raiz) = NULL;

}

void Rotacao_Esquerda(Apont *Raiz) {

	Apont aux;
	aux = (*Raiz)->Esq;
	(*Raiz)->Esq = aux->Dir;
	aux->Dir = (*Raiz);

	(*Raiz)->alt = maior(Altura_NO((*Raiz)->Esq),Altura_NO((*Raiz)->Dir)) + 1;
	aux->alt = maior(Altura_NO(aux->Esq),(*Raiz)->alt) + 1;

	(*Raiz) = aux;

}

void Rotacao_Direita(Apont *Raiz) {

	Apont aux;
	aux = (*Raiz)->Dir;
	(*Raiz)->Dir = aux->Esq;
	aux->Esq = (*Raiz);

	(*Raiz)->alt = maior(Altura_NO((*Raiz)->Esq),Altura_NO((*Raiz)->Dir)) + 1;
	aux->alt = maior(Altura_NO(aux->Dir),(*Raiz)->alt) + 1;

	(*Raiz) = aux;

}

void Rotacao_Esquerda_Direita(Apont *Raiz) {

	Rotacao_Direita(&(*Raiz)->Esq);
	Rotacao_Esquerda(Raiz);

}

void Rotacao_Direita_Esquerda(Apont *Raiz) {

	Rotacao_Esquerda(&(*Raiz)->Dir);
	Rotacao_Direita(Raiz);

}

int FB_NO(Apont Raiz) {

	return labs(Altura_NO(Raiz->Esq) - Altura_NO(Raiz->Dir));

}

int Altura_NO(Apont Raiz) {

	if(Raiz == NULL)
		return -1;
	else
		return Raiz->alt;

}

int maior(int x, int y) {
	if(x > y)
		return x;
	else
		return y;
}

void InOrdem(Apont Raiz) {

	if(Raiz != NULL) {

		InOrdem(Raiz->Esq);
		printf("|%d|",Raiz->info);
		InOrdem(Raiz->Dir);

	}

}

int Insere_AVL(Apont *Raiz, int x) {

	int res;

	if(*Raiz == NULL) {

		Apont aux;

		aux = (Apont) malloc(sizeof(arvore));
		if(aux == NULL)
			return 0;

		aux->info = x;
		aux->alt = 0;
		aux->Dir = NULL;
		aux->Esq = NULL;

		*Raiz = aux;

		return 1;
	}

	Apont aux;
	aux = (*Raiz);

	if(x < aux->info) {

		if((res = Insere_AVL(&(aux->Esq),x)) == 1) {

			if(FB_NO(aux) >= 2) {

				if(x < (*Raiz)->Esq->info) {

					Rotacao_Esquerda(Raiz);

				} else {
					//
					Rotacao_Esquerda_Direita(Raiz);

				}

			}

		}

	} else {

		if(x >= aux->info) {

			if((res = Insere_AVL(&(aux->Dir),x)) == 1) {

				if(FB_NO(aux) >= 2) {

					if((*Raiz)->Dir->info < x) {

						Rotacao_Direita(Raiz);

					} else {

						Rotacao_Direita_Esquerda(Raiz);

					}

				}

			}


		}

	}

		aux->alt = maior(Altura_NO(aux->Esq),Altura_NO(aux->Dir)) + 1;

		return res;
	}

	int main() {

		Apont Raiz;
		Cria_Arvore(&Raiz);

		InOrdem(Raiz);
		Insere_AVL(&Raiz, 10);
		InOrdem(Raiz);
		Insere_AVL(&Raiz, 10);
		InOrdem(Raiz);
		Insere_AVL(&Raiz, 10);
		InOrdem(Raiz);
		Insere_AVL(&Raiz, 10);

		InOrdem(Raiz);

	}
