#include "PraticaABB.h"

void Criar(Apont *Raiz){
	
	(*Raiz) = NULL;	
	
}

void Vazia(Apont Raiz){
	
	if(Raiz == NULL){
		
		printf("A arvore esta vazia.\n");
		
	} else printf("A arvore nao esta vazia.\n");
	
	
}

void Inserir(Apont *Raiz, Reg Dado){
	
	if(*Raiz == NULL){
		
		*Raiz = (Apont) malloc(sizeof(Celula));
		(*Raiz)->Esq = NULL;
		(*Raiz)->Dir = NULL;
		(*Raiz)->Info = Dado;		
		
	}
	
	else
	
	{
		
		if(Dado.codigo < (*Raiz)->Info.codigo){
			
			Inserir((&(*Raiz)->Esq),Dado);
			
		}
		
		else if(Dado.codigo >= (*Raiz)->Info.codigo){
			
			Inserir((&(*Raiz)->Dir),Dado);			
			
		}
		
	}
	
}

void MenuInsercao(Apont *Raiz){
	
	int op = 0;
	do {
		
		printf("-------------------------------------\n");
		printf("- Deseja inserir um registro?       -\n");
		printf("- 1 - Sim                           -\n");
		printf("- 0 - Nao                           -\n");
		printf("-------------------------------------\n");
		scanf("%d",&op);		
		
		if(op != 1 && op != 0){
			
			system("cls");
			printf("\nDigite uma opcao valida!!!\n\n");
			
		}
		
		if(op == 1){
			
			Reg Dado;
			
			printf("Digite o codigo do dado:\n");
			scanf ("%d",&Dado.codigo);
			
			fflush(stdin);
			
			printf("Digite o Nome do registro:\n");
			scanf ("%[^\n]s",Dado.Nome);
			
			Inserir(&(*Raiz),Dado);
			
		}
		
	} while(op != 0);
	
}

void PorID(Apont Raiz, int N){
	
	
	if(Raiz == NULL){
		
		printf("Nao encontrado.\n");
		return;
		
	} else if(Raiz->Info.codigo == N){
	
		printf("Encontrado.\n");
	
	} else if(Raiz->Info.codigo < N){
		
		PorID(Raiz->Dir,N);
		
	} else if(Raiz->Info.codigo > N){
		
		PorID(Raiz->Esq,N);
		
	}
		
}

void PorString(Apont Raiz, char *nome){ // Alterar depois
	
	
	if(Raiz == NULL){
		
		printf("Nao encontrado.\n");
		return;
		
	} else if(strcmp(Raiz->Info.Nome,nome) == 0){
	
		printf("Encontrado.\n");
	
	} else if(strcmp(Raiz->Info.Nome,nome) < 0){
		
		PorString(Raiz->Dir,nome);
		
	} else if(strcmp(Raiz->Info.Nome,nome) > 0){
		
		PorString(Raiz->Esq,nome);
		
	}
		
}

void Presente(Apont Raiz){
	
	int op = 0;
	do {
		
		printf("-------------------------------------\n");
		printf("- Como deseja pesquisar?            -\n");
		printf("- 1 - Por ID                        -\n");
		printf("- 2 - Por Nome                      -\n");
		printf("- 0 - Voltar                        -\n");
		printf("-------------------------------------\n");
		scanf("%d",&op);		
		
		if(op > 2 || op < 0){
			
			system("cls");
			printf("\nDigite uma opcao valida!!!\n\n");
			
		}
		
		if(op == 1){
			
			int n;
			printf("Digite o ID a ser pesquisado.\n");
			scanf ("%d",&n);
			
			PorID(Raiz,n);
			
		}
		else if(op == 2){
			/*
			fflush(stdin);
			char nome[60];
			printf("Digite o nome a ser pesquisado.\n");
			scanf("%[^\n]s",nome);
			PorString(Raiz,nome);
			*/
			printf("nao implementado\n");
			
		} else if (op == 0){
			
			return;
			
		}
		
	} while(op != 0);
		
}

Apont MaiorDireita(Apont *No){

	if((*No)->Dir != NULL){
		
		return MaiorDireita(&(*No)->Dir);
		
	}
	
	else
	
	{
		
		Apont aux = *No;
		
		if((*No)->Esq != NULL){
			
			*No = (*No)->Esq;			
			
		}
		
		else
		
		{
			
			*No = NULL;
			return aux;
			
		}
		
	}
	
	
}

Apont MenorEsquerda(Apont *No){
	
	if((*No)->Esq != NULL){
		
		return MenorEsquerda(&(*No)->Esq);
		
	}
	
	else
	
	{
		
		Apont aux = *No;
		
		if((*No)->Dir != NULL){
			
			*No = (*No)->Dir;			
			
		}
		
		else
		
		{
			
			*No = NULL;
			return aux;
			
		}
		
	}
	
}

void Retirar(Apont *Raiz, Reg info){
	
	if((*Raiz) == NULL){
		
		printf("Numero nao contido na arvore.\n");
		getch();
		return;
		
	}
	
	if(info.codigo < (*Raiz)->Info.codigo)
	
		Retirar(&(*Raiz)->Esq, info);
		
	else if(info.codigo > (*Raiz)->Info.codigo)
	
		Retirar(&(*Raiz)->Dir, info);
		
	else
	
	{
		
		Apont aux;
		aux = (*Raiz);
		
		if(((*Raiz)->Esq == NULL) && ((*Raiz)->Dir == NULL)){
			free(aux);
			(*Raiz) = NULL;
		}
		
		else
		
		{
		
			if((*Raiz)->Esq == NULL){
				
				(*Raiz) = (*Raiz)->Dir;
				aux->Dir = NULL;
				free(aux);
				aux = NULL;
								
			} else {
				
				if((*Raiz)->Esq == NULL){
					
					(*Raiz) = (*Raiz)->Dir;
					aux->Dir = NULL;
					free(aux);
					aux = NULL;
										
 				}
 				else{
 					
 					if((*Raiz)->Dir == NULL){
 						
 						(*Raiz) = (*Raiz)->Esq;
 						aux->Esq = NULL;
 						free(aux);
 						aux = NULL;
 						
					}
 					
 					else
 					
 					{
 						
 						aux = MaiorDireita(&(*Raiz)->Esq);
 						aux->Esq = (*Raiz)->Esq;
 						aux->Dir = (*Raiz)->Dir;
 						(*Raiz)->Esq = NULL;
 						(*Raiz)->Dir = NULL;
 						free((*Raiz));
 						(*Raiz) = aux;
 						aux = NULL;
					 	
					}
 					
				 }
				
			}
			
		}
		
	}
	
}

void MenuRemocao(Apont *Raiz){
	
	int op = 0;
	do {
		
		printf("-------------------------------------\n");
		printf("- Deseja remover um registro?       -\n");
		printf("- 1 - Sim                           -\n");
		printf("- 0 - Nao                           -\n");
		printf("-------------------------------------\n");
		scanf("%d",&op);		
		
		if(op != 1 && op != 0){
			
			system("cls");
			printf("\nDigite uma opcao valida!!!\n\n");
			
		}
		
		if(op == 1){
			
			Reg Dado;
			
			printf("Digite o codigo do dado:\n");
			scanf ("%d",&Dado.codigo);
			
			/*fflush(stdin);
			
			printf("Digite o Nome do registro:\n");
			scanf ("%[^\n]s",Dado.Nome);
			*/
			
			Retirar(&(*Raiz),Dado);
			
		}
		
	} while(op != 0);
	
	
}

void ImprimirInOrdem(Apont Raiz){
	
	if(Raiz != NULL){
		
		ImprimirInOrdem(Raiz->Esq);
		printf("|%d| ---- |%s|\n",Raiz->Info.codigo, Raiz->Info.Nome);
		ImprimirInOrdem(Raiz->Dir);
		
	}
	
}

int main(){
	
	Apont Raiz;
	Criar(&Raiz);
	
	int op = 0;
	
	do{
		
		
				
		printf("-------------------------------------\n");
		printf("- Digite uma opcao                  -\n");
		printf("- 1 - Inserir                       -\n");
		printf("- 2 - Remover                       -\n");
		printf("- 3 - Verificar Vazia               -\n");
		printf("- 4 - Verificar Elemento            -\n");
		printf("- 5 - Exibir in Ordem               -\n");
		printf("- 0 - Sair                          -\n");
		printf("-------------------------------------\n");
		scanf("%d",&op);		
			
		switch(op){
			
			case 1:
				MenuInsercao(&Raiz);
			break;
			case 2:
				MenuRemocao(&Raiz);
			break;
			case 3:
				Vazia(Raiz);
			break;
			case 4:
				Presente(Raiz);
			break;
			case 5:
				ImprimirInOrdem(Raiz);
			break;
			default:
				printf("Digite uma opcao valida.\n");
			
		}		
		
	} while(op != 0);
	
}
