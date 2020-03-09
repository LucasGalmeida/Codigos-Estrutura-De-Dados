#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Tamanho_Vetor = 14;

void ExibeVetor(int *vet);

int GeraVetor(int *vet){
    
    int i;
    for(i=0; i < Tamanho_Vetor; i ++){
        
        vet[i] = rand()%100;
        
    }
    
    system("cls");
    ExibeVetor(vet);
    return *vet;
    
}

int BubbleSort(int *vet){
    
    int aux;
    int i,j;
    
    system("cls");
    ExibeVetor(vet);
    system("pause");
    
    for(i = 0; i < Tamanho_Vetor; i++){        
        
        for(j = 0; j < Tamanho_Vetor - 1; j++){
            
            if(vet[j] > vet[j+1]){
            	
                aux = vet[j+1];
                vet[j+1] = vet[j];
                vet[j] = aux;
                
                ExibeVetor(vet);
       			system("pause");
       			
            }            
        }
    }    
    
    return *vet;
}

int SelectionSort(int *vet){
	
	int i,j, menor;
	int aux;
	
	system("cls");
    ExibeVetor(vet);
    system("pause");
	
	for(i = 0; i <= Tamanho_Vetor - 1; i++){
		menor = i;
		
		for(j = i + 1; j <= Tamanho_Vetor; j++){
			if(vet[j] < vet[menor]){
				menor = j;
			}
		}
		
		aux = vet[menor];
		vet[menor] = vet[i];
		vet[i] = aux;
		
		ExibeVetor(vet);
       	system("pause");
		
	}
	
	return *vet;
}

int Insercao(int *vet){
	
	int i, j;
	int aux;
	
	system("cls");
    ExibeVetor(vet);
    system("pause");
	
	for(i = 1; i <= Tamanho_Vetor; i++){
		
		aux = vet[i];
		j = i - 1;
		
		while(aux < vet[j]){
			vet[j+1] = vet[j];
			j--;
			       		
		}
		
		vet[j+1] = aux;
		
	
		ExibeVetor(vet);
   		system("pause");
			
	}
	
	return *vet;
	
}

void Particao(int Esq, int Dir, int *i, int *j, int *vet){
	
	int aux, aux2;
	*i = Esq; *j = Dir;
	
	aux = vet[(*i + *j)/2];
		
	do{
		
		while(aux > vet[*i]){
			(*i)++;
		}
		
		while(aux < vet[*j]){
			(*j)--;
		}
		
		if(*i <= *j){
			
			aux2 = vet[*i];
			vet[*i] = vet[*j];
			vet[*j] = aux2;
			(*i)++;
			(*j)--;
			
		}
		
	} while (*i <= *j);
	
}

void Ordena(int Esq, int Dir, int *vet){
	
	int i, j;
	Particao(Esq, Dir, &i, &j, vet);
	
	ExibeVetor(vet);
    system("pause");
		
	if(Esq < j) Ordena(Esq, j, vet);
	if(i < Dir) Ordena(i, Dir, vet);
		
}

int QuickSort(int *vet){
	
	system("cls");
    ExibeVetor(vet);
    system("pause");
	
	Ordena(0, Tamanho_Vetor - 1, vet);
	
	return *vet;
}

int Refaz(int Esq, int Dir, int *vet){
	
	int i = Esq;
	int j;
	int aux;
	
	j = i * 2;
	aux = vet[i];
	
	while(j <= Dir){
		
		if(j < Dir){
			
			if(vet[j] < vet[j+1]){
				j++;
			}
			
		}
		
		if (aux >= vet[j]){
			break;
		}
		
		vet[i] = vet[j];
		i = j;
		j = i * 2;
		
	}
	
	vet[i] = aux;
	
	return *vet;
	
}

int Constroi(int *vet){
	
	int Esq;
	Esq = (Tamanho_Vetor - 1)/2 + 1;
	
	while(Esq > 0){
		Esq --;
		Refaz(Esq,Tamanho_Vetor-1,vet);
	}
	
	ExibeVetor(vet);
    system("pause");
	
	return *vet;
	
}

int HeapSort(int *vet){
	
	int Esq, Dir;
	int aux;
	
	system("cls");
    ExibeVetor(vet);
    system("pause");
	
	*vet = Constroi(vet);
	
	Esq = 0; Dir = Tamanho_Vetor - 1;
	
	while(Dir > 0){
		
		aux = vet[0];
		vet[0] = vet[Dir];
		vet[Dir] = aux;
		Dir --;
		
		*vet = Refaz(Esq, Dir, vet);
		ExibeVetor(vet);
    	system("pause");
		
			
	}
	
	return *vet;
}

void ExibeVetor(int *vet){
    
    int i;
    for(i=0; i < Tamanho_Vetor; i ++){        
        printf("|%d|",vet[i]);        
    }
    
    printf("\n");
    
}

void menu(int *vet){
	
	int op;
    do{
    	    
    	printf("-----------------------------\n");
    	printf("- 1 - Gerar novo vetor      -\n");
    	printf("- 2 - Exibir vetor          -\n");
    	printf("- 3 - Bubble Sort           -\n");
    	printf("- 4 - Selection Sort        -\n");
    	printf("- 5 - Insercao              -\n");
    	printf("- 6 - Heap Sort             -\n");
    	printf("- 7 - Quick Sort            -\n");
    //	printf("- 8 - Passo a Passo |%s|    -\n",P);
    	printf("- 0 - Sair                  -\n");
    	printf("-----------------------------\n");
    	scanf ("%d",&op);
    		
    	switch (op){
    	case 1:
    		*vet = GeraVetor(vet);
    	break;
    	case 2:
    		ExibeVetor(vet);
    	break;
    	case 3:
    		*vet = BubbleSort(vet);
    	break;
    	case 4:
    		*vet = SelectionSort(vet);	
    	break;
    	case 5:
    		*vet = Insercao(vet);
    	break;
    	case 6:
    		*vet = HeapSort(vet);
    	break;
    	case 7:
    		*vet = QuickSort(vet);
    	break;    
    	case 0:
    		return;
    	break;
		default:
			printf("Digite uma opcao valida!!!");
    		scanf ("%d",&op);
		}
    	
	} while(op != 0);
    
    
}

int main(void){
	
    srand(time(NULL));
    
    
    //printf("Digite o tamanho do vetor:\n");
    //scanf ("%d",&Tamanho_Vetor);
    
    int vet[Tamanho_Vetor];
    *vet = GeraVetor(vet);
    
    menu(vet);
    

    return 0;
}

