/*Herencia múltiple utilizando las superclases o clases bases : Padre y Madre, 
que hereden sus características a la clase hijo o hija. Proponer la implementación. */
#include<iostream>
using namespace std;

class Madre{ 
	protected: 
		char chr;
	public:
		Madre(char otrochr = 'X'){
			chr = otrochr;
		}
		void imprimeM(){
			cout<<"\n Cromosomas madre: "<<chr<<""<<chr;
		} 
}; 
class Padre{ 
	protected:
		char chr1, chr2; 
	public:
		Padre(char otrochr1 = 'X', char otrochr2 = 'Y'){
			chr1 = otrochr1;
			chr2 = otrochr2;
		}
		void imprimeP(){
			cout<<"\n\n Cromosomas padre: "<<chr1<<""<<chr2;
		}
};
class Hijo:public Madre, public Padre{ 
	public:
		Hijo(char a = 'X', char b = 'X', char c = 'Y'):Madre(a),Padre(b,c){
	
		} 
		void imprimir(){ 
			cout<<"\n Hijo\n Cromosomas: "<<chr<<""<<chr2; 
		} 
};

main(){
	Hijo Juan;
	Juan.imprimir();
	Juan.imprimeP();
	Juan.imprimeM();
}
