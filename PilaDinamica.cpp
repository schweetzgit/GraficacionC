#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct nodo{
	int num;
	struct nodo *ptr;
}nod;

class Pila{
	private:
		nod *inicio;
	public:
		Pila();
		void insertarPila(int);
		void imprimirPila();
		void sacarPila();
		~Pila();
};

//constructor
Pila::Pila(){
	inicio = NULL;
}

void Pila::insertarPila(int ndato){
	nod *nuevo; //apuntar a nod
	nuevo = (nod*)malloc(sizeof(nod)); //byte para num e inicio
	nuevo->num = ndato;
	
	if(inicio == NULL){
		nuevo->ptr = NULL;
		inicio = nuevo; //el primer nodo
		return;
	}
	
	nuevo->ptr = inicio;	
	inicio = nuevo;
}

void Pila::imprimirPila(){
	nod *aux = inicio;
	
	if(inicio == NULL){// la pila esta vacia si es cierto
		cout<<"\n Pila vacia";
		cin.get();
		return;
	}
	
	while(aux != NULL){
		cout<<"\n "<<aux->num;
		aux = aux->ptr; 
	}
}

void Pila::sacarPila(){
	nod *aux = inicio;
	
	if(inicio == NULL){
		cout<<"\n Pila vacia";
		cin.get();
		return;
	}
	
	cout<<"\n Sale: "<<aux->num;
	inicio = aux->ptr;
	free(aux);
}

Pila::~Pila(){
	while(inicio != NULL){
		sacarPila();
	}
}

main(){
	Pila pili;
	int opc, nuevoDato;
	do{
		cout<<"\n 1. Insertar elemento a la pila";
		cout<<"\n 2. Imprimir la pila";
		cout<<"\n 3. Borrar de la pila";
		cout<<"\n 4. Salir";
		cout<<"\n Elija una opcion: ";
		cin>>opc;
		switch(opc){
			case 1:
				cout<<"\n Dato a insertar: ";
				cin>>nuevoDato;
				pili.insertarPila(nuevoDato);
				break;
			case 2:
				pili.imprimirPila();
				break;
			case 3:
				pili.sacarPila();
				break;
			case 4:
				cout<<"\n Hasta la vista";
				cin.get();
				break;
			default: 
				cout<<"\n Opcion incorrecta. Vuelva a elegir";			
				cin.get();
		}
	}while(opc!=4);
}
