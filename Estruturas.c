#include <stdio.h>
#include <stdlib.h>

#define MAXTAM 100

typedef int Apontador;

// Tipos Abstratos de Dados //

// Dado
typedef struct{
	
	int ID;
	
}TDado;

//Lista
typedef struct{
	
	Apontador Prim, Ult;
	TDado Item[MAXTAM];
	
} TLista;

//Fila
typedef struct{
	
	Apontador Prim, Ult;
	int Numero_Elementos;
	TDado Item[MAXTAM];
	
} TFila;

//Pilha
typedef struct{
	
	Apontador Topo;
	TDado Item[MAXTAM];
	
} TPilha;

///////////////////////////////////////////////////////////////////////////

// Definicoes da lista //
TLista Inicia_Lista(TLista L){
	
	L.Prim = 0;
	L.Ult = 0;
	
	return L;
	
	
}

TLista Insere_Dado_Lista(TLista L){
			
	if(L.Ult == MAXTAM){
		
		printf("ERRO, a lista esta cheia!!!\n");
		
	} else {
		
		TDado D;
		printf("Digite o ID a ser inserido:\n");
		scanf("%d",&D.ID);		
		L.Item[L.Ult] = D;		
        L.Ult++;
	}	
	
	return L;
	
}

int Pesquisa_Dado_Lista(TLista L){
	
	int i, ID;
	
	printf("Digite o ID que deseja encontrar:\n");
	scanf ("%d",&ID);
	
	int aux = L.Prim;
	
	while(aux < L.Ult && L.Item[aux].ID != ID){
		
		aux++;
		
	}
	
	if(L.Item[aux].ID == ID){
		
		return aux;
		
	} else {
		
		printf("Dado nao encontrado na lista!!!\n");
		return -1;	
		
	}
		
}

TLista Remove_Dado_Lista(TLista L){
	
	if(L.Prim == L.Ult){
		
		printf("ERRO, a lista esta vazia!!!\n");
		
	} else {
		
		printf("Pesquise o dado que deseja remover\n");
		int Dado = Pesquisa_Dado_Lista(L);
		
		while(Dado + 1 < L.Ult){
			
			L.Item[Dado] = L.Item[Dado+1];
			Dado++;
			
		}		
		
		L.Ult--;
		
	}
	
	return L;
		
}

TLista Altera_Dado_Lista(TLista L){
	
	int aux = Pesquisa_Dado_Lista(L);
	
	if(aux > -1){
		
		TDado D;
		printf("Digite o ID que deseja alterar:\n");
		scanf ("%d",&L.Item[aux]);
				
	} else {
		
		printf("A lista esta vazia!!!\n");
		return L;
		
	}
	
	return L;
	
}

void Exibe_Lista(TLista L){
	
	int aux = L.Prim;
	
	while(aux < L.Ult){
		
		printf("|%d",L.Item[aux].ID);
		aux++;
		
	}
	printf("|\n");
	
}

void Menu_Lista(TLista L){
	
	int op;
	
	do{
		
		printf("--------------------\n");
		printf("- 1 Inserir Dado   -\n");
		printf("- 2 Remover Dado   -\n");
		printf("- 3 Alterar Dado   -\n");
		printf("- 4 Exibir Lista   -\n");
		printf("- 0 Voltar         -\n");
		printf("--------------------\n");	
		scanf("%d",&op);
		
		switch(op){
			
			case 1:
				L = Insere_Dado_Lista(L);
			break;
			case 2:
				L = Remove_Dado_Lista(L);
			break;
			case 3:
				L = Altera_Dado_Lista(L);
			break;
			case 4:
				Exibe_Lista(L);
			break;
			case 0:
				return;
			break;
			default:
				printf("ERRO, opcao invalida!!!\n");
				scanf ("%d",&op);			
		}
		
	} while(op != 0);
				
}

///////////////////////////////////////////////////////////////////////////

// Definicoes da Fila //

TFila Inicia_Fila(TFila F){
	
	F.Prim = 1;
	F.Ult = F.Prim;
	F.Numero_Elementos = 0;
	
	return F;
	
}

TFila Insere_Dado_Fila(TFila F){
	
	if(F.Ult % MAXTAM + 1 == F.Prim){
		
		printf("ERRO, a fila esta cheia!!!\n");
		
	} else {
		
		TDado D;
		printf("Digite o dado a ser inserido na fila:\n");
		scanf ("%d",&D.ID);
		
		F.Item[F.Ult] = D; // -1?
		F.Ult = F.Ult % MAXTAM + 1;
		
		F.Numero_Elementos++;
		
	}
	
	return F;
}

TFila Remove_Dado_Fila(TFila F){ //Possivel implementacao de auxiliar para armazenar o registro removido.
	
	if(F.Numero_Elementos == 0){
		
		printf("ERRO, a fila esta vazia !!!\n");
		
	} else {
		
		F.Prim = (F.Prim + 1) % MAXTAM;
		F.Numero_Elementos--;
		
	}
	
	return F;
}

void Exibe_Fila(TFila F){
	
	int i;
	int aux = F.Prim;
	for(i = 0; i < F.Numero_Elementos; i++){
		printf("|%d",F.Item[aux].ID);
		aux = (aux + 1) % MAXTAM;
	}
	printf("|\n");
}

void Menu_Fila(TFila F){
	
	int op;
	
	do{
		
		printf("--------------------\n");
		printf("- 1 Inserir Dado   -\n");
		printf("- 2 Remover Dado   -\n");
		//printf("- 3 Alterar Dado   -\n");
		printf("- 3 Exibir Fila    -\n");
		printf("- 0 Voltar         -\n");
		printf("--------------------\n");	
		scanf("%d",&op);
		
		switch(op){
			
			case 1:
				F = Insere_Dado_Fila(F);
			break;
			case 2:
				F = Remove_Dado_Fila(F);
			break;
			/*case 3:
				L = Altera_Dado_Lista(L);
			break;*/
			case 3:
				Exibe_Fila(F);
			break;
			case 0:
				return;
			break;
			default:
				printf("ERRO, opcao invalida!!!\n");
				scanf ("%d",&op);			
		}
		
	} while(op != 0);
				
}

///////////////////////////////////////////////////////////////////////////

// Definicoes da Pilha //

TPilha Inicia_Pilha(TPilha P){
	
	P.Topo = 0;
	return P;
	
}

TPilha Insere_Dado_Pilha(TPilha P){
	
	if(P.Topo == MAXTAM){
		printf("ERRO, a pilha esta cheia!!!\n");
	} else {
		
		TDado D;
		printf("Digite o dado a ser inserido na pilha:\n");
		scanf ("%d",&D.ID);
		
		P.Item[P.Topo] = D;
		P.Topo++;
	}
	
	return P;
	
}

TPilha Remove_Dado_Pilha(TPilha P){ //Possivel implementacao de auxiliar para armazenar o registro removido.
	
	if(P.Topo == 0){
		printf("ERRO, a pilha esta vazia!!!");
	} else {
		
		P.Topo--;
		
	}
	
	return P;
	
}

void Exibe_Pilha(TPilha P){
	
	if(P.Topo == 0){
		printf("ERRO, a pilha esta vazia!!!");
	} else {
		
		int aux = P.Topo;
		while(aux > 0){
			
			printf("|%d|\n",P.Item[aux-1]);
			aux--;
			
		}
		
	}
	
}

void Menu_Pilha(TPilha P){
	
	int op;
	
	do{
		
		printf("--------------------\n");
		printf("- 1 Inserir Dado   -\n");
		printf("- 2 Remover Dado   -\n");
		//printf("- 3 Alterar Dado   -\n");
		printf("- 3 Exibir Pilha   -\n");
		printf("- 0 Voltar         -\n");
		printf("--------------------\n");	
		scanf("%d",&op);
		
		switch(op){
			
			case 1:
				P = Insere_Dado_Pilha(P);
			break;
			case 2:
				P = Remove_Dado_Pilha(P);
			break;
			/*case 3:
				L = Altera_Dado_Lista(L);
			break;*/
			case 3:
				Exibe_Pilha(P);
			break;
			case 0:
				return;
			break;
			default:
				printf("ERRO, opcao invalida!!!\n");
				scanf ("%d",&op);			
		}
		
	} while(op != 0);
				
}

int main(){
	
	/* Lista L1;
	L1 = Inicia_Lista(L1);
	Menu_Lista(L1); */
	
	/* TFila F1;
	F1 = Inicia_Fila(F1);
	Menu_Fila(F1); */
	
	/* TPilha P1;
	P1 = Inicia_Pilha(P1);
	Menu_Pilha(P1); */
	
	
}



