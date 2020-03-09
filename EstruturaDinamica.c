#include "EstruturaDinamica.h"

TLista Inicia_Lista(TLista L) {

	L.Prim = (TipoApontador) malloc(sizeof(TipoCelula));
	L.Ult = L.Prim;
	L.Prim->Prox = NULL;
	L.tam = 0;

	return L;

}

int Vazia(TLista L) {

	return (L.Prim == L.Ult);

}

TLista Insere_Dado_Lista(TLista L) {

	TDado D;
	printf("Qual numero deseja inserir na lista?\n");
	scanf ("%d",&D.X);

	L.Ult->Prox = (TipoApontador) malloc(sizeof(TipoCelula));
	L.Ult = L.Ult->Prox;
	L.Ult->Dado = D;
	L.Ult->Prox = NULL;
	L.tam++;

	return L;
}

TipoApontador Pesquisa_Lista(TLista L) {

	TDado D;
	printf("Digite o elemento contido na lista:\n");
	scanf ("%d",&D.X);

	TipoApontador aux;
	aux = L.Prim;
	while(aux->Prox != NULL) {

		if(aux->Prox->Dado.X == D.X) {

			return aux;

		}

		aux = aux->Prox;

	}

	printf("Elemento nao encontrado na lista.\n");
	return NULL;

}

TLista Remove_Dado_Lista(TLista L) {

	if(Vazia(L)) {

		printf("ERRO, A lista esta vazia!!!");
		return L;

	} else {

		TipoApontador X;
		X = Pesquisa_Lista(L);

		if(X != NULL) {

			TipoApontador aux;

			aux = X->Prox;
			X->Prox = aux->Prox;
			free(aux);

			if(X->Prox == NULL) L.Ult = X;

			L.tam--;

		}

		return L;
	}

}

void Exibe_Lista(TLista L) {

	if(Vazia(L)) {

		printf("A lista esta vazia!!!\n");
		return;

	} else {

		TipoApontador aux;
		aux = L.Prim->Prox;

		while(aux != NULL) {

			printf("|%d", aux->Dado.X);
			aux = aux->Prox;

		}

		printf("| Tamanho da Lista: %d\n",L.tam);

		return;
	}

}

TLista Menu_Lista(TLista L) {

	int op;

	do {
		system("pause");
		system("cls");
		printf("------------------------\n");
		printf("- 1 Inserir Dado       -\n");
		//	printf("- 2 Inserir Dado (Ord) -\n");
		printf("- 3 Remover Dado       -\n");
		//printf("- 4 Alterar Dado       -\n");
		printf("- 5 Exibir Lista       -\n");
		printf("- 0 Voltar             -\n");
		printf("------------------------\n");
		scanf("%d",&op);

		switch(op) {

			case 1:
				L = Insere_Dado_Lista(L);
				break;
			case 2:
				//	L = Insere_Dado_Lista_Ordenado(L);
				break;
			case 3:
				L = Remove_Dado_Lista(L);
				break;
			case 4:
				//	L = Altera_Dado_Lista(L);
				break;
			case 5:
				Exibe_Lista(L);
				break;
			case 0:
				return L;
				break;
			default:
				printf("ERRO, opcao invalida!!!\n");
				scanf ("%d",&op);
		}

	} while(op != 0);



}

int main() {

	TLista L1;
	L1 = Inicia_Lista(L1);

	L1 = Menu_Lista(L1);


}
