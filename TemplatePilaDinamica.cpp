#include<iostream>
#include<stdlib.h>
using namespace std;

typedef union tipoDato{
	int a;
	float b;
	char c;
}uniTipo;

template<class Tipo>
class Pila{
	private:
		typedef struct nodo{
			Tipo num;
			struct nodo *ptr;
		}nod;
		nod *inicio;
	public:
		Pila();
		void insertarPila(Tipo);
		void imprimirPila();
		void sacarPila();
		~Pila();
};

//constructor
template<class Tipo> Pila<Tipo>::Pila(){
	inicio = NULL;
}

template<class Tipo> void Pila<Tipo>::insertarPila(Tipo ndato){
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

template<class Tipo> void Pila<Tipo>::imprimirPila(){
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

template<class Tipo> void Pila<Tipo>::sacarPila(){
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

template<class Tipo> Pila<Tipo>::~Pila(){
	while(inicio != NULL){
		sacarPila();
	}
}

main(){
	uniTipo tipoDeseado;
	Pila<int>piliInt;
	Pila<float>piliFloat;
	Pila<char>piliChar;
	int opc;
	char tipoLeido;
	do{
		cout<<"\n Tipo de dato a manejar[e:entero,f:flotante,c:char]: ";
		cin>>tipoLeido;
		cout<<"\n 1. Insertar elemento a la pila generica";
		cout<<"\n 2. Imprimir pila generica";
		cout<<"\n 3. Borrar de la pila generica";
		cout<<"\n 4. Salir";
		cout<<"\n Elija una opcion: ";
		cin>>opc;
		switch(opc){
			case 1:
				cout<<"\n Dato a insertar: ";
				if(tipoLeido == 'e'){
					cin>>tipoDeseado.a;
					piliInt.insertarPila(tipoDeseado.a);
				}
				else if(tipoLeido == 'f'){
					cin>>tipoDeseado.b;
					piliFloat.insertarPila(tipoDeseado.b);
				}
				else if(tipoLeido == 'c'){
					cin>>tipoDeseado.c;
					piliChar.insertarPila(tipoDeseado.c);
				}
				break;
			case 2:
				if(tipoLeido == 'e'){
					piliInt.imprimirPila();
				}
				else if(tipoLeido == 'f'){
					piliFloat.imprimirPila();
				}
				else if(tipoLeido == 'c'){
					piliChar.imprimirPila();
				}	
				break;
			case 3:
				if(tipoLeido == 'e'){
					piliInt.sacarPila();
				}
				else if(tipoLeido == 'f'){
					piliFloat.sacarPila();
				}
				else if(tipoLeido == 'c'){
					piliChar.sacarPila();
				}
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
