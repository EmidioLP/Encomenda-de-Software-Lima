#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <cstdlib>

using namespace std;

typedef struct Dados{
	char nome[30];
	int telefone;
}agenda;

typedef struct Reg{
	agenda info;
	Reg *prox, *ant;
}No;

typedef struct Lista{
	Reg *inicio, *fim;
	int tam;
}ListaD;

ListaD *inicializa(ListaD *LD){
	LD->inicio=LD->fim=NULL;
	LD->tam=0;
	return LD;
}

bool listaVazia(ListaD *LD){
	return ((LD->inicio == LD->fim) && (LD->tam==0));
}

bool comparaInfo(string a, string b){
return a>b;
}

bool igualNome(string a, string b){
	return a == b;
}

bool nomeMenor(string a, string b){
	return a < b;
}
/*ListaD *insereInicio(ListaD *LD){
	system("cls");
	No *novo;
	novo = new No;
	cout << "Qual o nome do usuario? "<<endl;
	cin.ignore();
	cin.getline(novo->info.nome,30);
	cout << "Qual o numero do telefone?"<<endl;
	cin>>novo->info.telefone;
	novo->ant = NULL;
	if(listaVazia(LD)){
		novo->prox=NULL;
		LD->inicio=LD->fim = novo;
		LD->tam++;
	}else{
		novo->prox = LD->inicio;
		LD->inicio->ant = novo;
		LD->inicio = novo;
		LD->tam++;
	}
	system("cls");
	return LD;
}

/*ListaD *insereFim(ListaD *LD){
	system("cls");
	No *novo;
	novo = new No;
	cout << "Qual o nome do usuario? "<<endl;
	cin.ignore();
	cin.getline(novo->info.nome,30);
	cout << "Qual o numero do telefone?"<<endl;
	cin>>novo->info.telefone;
	novo->prox = NULL;
	if(listaVazia(LD)){
		novo->ant=NULL;
		LD->inicio=LD->fim = novo;
		LD->tam++;
	}else{
		novo->ant = LD->fim;
		LD->fim->prox = novo;
		LD->fim = novo;
		LD->tam++;
	}
	system("cls");
	return LD;
}*/

ListaD *insere(ListaD *LD){
    No *novo;
	novo = new No;
	cout << "Qual o nome do usuario? "<<endl;
	cin.ignore();
	cin.getline(novo->info.nome,30);
	cout << "Qual o numero do telefone?"<<endl;
	cin>>novo->info.telefone;
	if(listaVazia(LD)){
	novo->prox=NULL;
	LD->inicio=LD->fim = novo;
	LD->tam++;
	return LD;
	}else {
		novo->ant=NULL;
		novo->prox = LD->inicio;
		LD->inicio->ant = novo;
		LD->inicio = novo;
		LD->tam++;
	}
		
	
	return LD;
}

/*void OrdenaLista(ListaD *LD){
	No *copia;
	string auxiliar;
	for(copia = LD->inicio; copia!=NULL; copia=copia->prox){
		string a = copia->info.nome;
		string b = copia->prox->info.nome;
		if(comparaInfo(b,a)){
			auxiliar = b;
			b = a;
			a = auxiliar;			
		}
			
	}
}


/*ListaD *excluirInicio(ListaD *LD){
	No *CP;
	CP = LD->inicio;
	LD->inicio = CP->prox;
	CP->prox->ant = NULL;
	LD->tam--;
	delete CP;
	cout << "--------------------" << endl;
	cout << " Elemento excluido!" << endl;
	cout << "--------------------" << endl;
return LD;
}

ListaD *excluirFim(ListaD *LD){
	No *CP;
	CP = LD->fim;
	LD->fim = CP->ant;
	CP->ant->prox = NULL;
	LD->tam--;
	delete CP;
	cout << "--------------------" << endl;
	cout << " Elemento excluido!" << endl;
	cout << "--------------------" << endl;
return LD;
}*/

ListaD *excluirQualquerLugar(ListaD *LD){
	char n[30];
	cout << "Digite o nome da pessoa que voce quer excluir: ";
	cin.ignore();
	cin.getline(n,30);
	No *CP;
	CP = LD->inicio;
	while((CP!=NULL)&&(CP->info.nome!=n)){
		if(CP==NULL){
			cout << "Elemento nao esta na lista!" << endl;
			break;
			}
        else if(igualNome(n,CP->info.nome) && CP->ant == CP->prox){
            LD = inicializa(LD);
            break;
            }
        else if(igualNome(n,CP->info.nome) && CP->ant == NULL){
            LD->inicio = CP->prox;
            CP->prox->ant = NULL;
            LD->tam--;
            break;
        }
        else if(igualNome(n,CP->info.nome) && CP->prox == NULL){
            LD->fim = CP->ant;
            CP->ant->prox = NULL;
            LD->tam--; 
            break;
            }
		else if(igualNome(n,CP->info.nome)){
			CP->ant->prox = CP->prox;
			CP->prox->ant = CP->ant;
			LD->tam--;
			break;
			}
			CP = CP->prox;
		}
	return LD;	
	}



void Imprime(ListaD *LD){
	
	No *copia;
	copia = LD->inicio;
	int cont = 1;
	if(listaVazia(LD)){
		cout << "Lista vazia!" << endl;
	}else{
		cout << "===== LISTA =====" << endl;
		while(copia!=NULL){
			cout << "[" << cont <<"]:"<< "Nome = " << copia->info.nome << endl;
			cout << "[" << cont <<"]:" << "Telefone = "<< copia->info.telefone << endl;
			copia = copia->prox;
			cont++;
		}
		cout << "=================" << endl;
        delete copia;
	}
	

}

void busca(ListaD *LD){
	system("cls");
	No *copia;
	copia = LD->inicio;
	char n[30];
	cout << "Qual o nome da pessoa?"<<endl;
	cin.ignore();
	cin.getline(n,30);
	if(listaVazia(LD)){
		cout << "Lista vazia!" << endl;
	}else{
		while(copia!=NULL){
			if (igualNome(n, copia->info.nome)){
				cout<<"Telefone: "<<copia->info.telefone<<endl;
					break;
			}
			copia = copia->prox;
			}
		if(copia==NULL){
		cout<<"Nome nao esta na lista!"<<endl;	
	}
		
	}
}

void MudaTelefone(ListaD *LD){
	char nome[30];
	cout<<"Qual o nome da pessoa?"<<endl;
	cin.ignore();
	cin.getline(nome,30);
	No *copia;
	copia=LD->inicio;
	if(listaVazia(LD)){
		cout << "Lista vazia!" << endl;
	}else{
		while(copia!=NULL){
			if (igualNome(nome, copia->info.nome)){
				int telefone;
				cout<< "Digite o novo numero de telefone: "<<endl;
				cin>>telefone;
				copia->info.telefone = telefone;
					break;
				}
				copia = copia->prox;
				if(copia==NULL){
					cout<<"Nome nao esta na lista!"<<endl;
					break;
				}
	}
	
	}
}

int main(){
	ListaD *L1;
	L1 = new ListaD;
	L1 = inicializa(L1);
	
	int opcao;
	do{
		
		cout << "=================================================" << endl;
		cout << "                       MENU" << endl;
		cout << "=================================================" << endl;
		cout << " 1) Inserir elemento."<<endl;
		cout << " 2) Excluir elemento."<< endl;
		cout << " 3) Imprime lista." << endl;
		cout << " 4) Busca telefone."<<endl;
		cout << " 5) Modificar telefone."<< endl;
		cout << " 0) Sair." << endl;
		cout << "_________________________________________________" << endl;
		cout << " Escolha uma opcao: ";
		cin >> opcao;
		
		switch(opcao){
			case 1: L1 = insere(L1);
					break;
			case 2: excluirQualquerLugar(L1);
					break;
			case 3: Imprime(L1); 
					break;
			case 4: busca(L1);
					break;
			case 5: MudaTelefone(L1);
					break;
		}
	}while(opcao!=0);
		
return 0;
}
