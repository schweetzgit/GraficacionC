#include<iostream>
using namespace std;

class Base1{ 
	protected: 
		int b1; 
	public:
		Base1(int otrob1 = 100){
			b1 = otrob1;
		}
		void set (int i){ 
			b1 = i;
		} 
		void imprime(){
			cout<<"\n Valor de la variable protegida b1: "<<b1;
		}
}; 
class Base2{ 
	private: 
		int b2;
	public:
		Base2(int otrob2 = 50){
			b2 = otrob2;
		}
		void set (int i){ 
			b2 = i;
		} 
		int dar(){
			return b2;
		} 
};
class Derivada:public Base1, private Base2{ 
	public:
		Derivada(int a = 200, int b = 250):Base1(a),Base2(b){
	
		} 
		void imprimir(){ 
			cout<<"\n b1 = "<<b1<<"\n b2 = "<<dar(); 
		} 
};

main(){
	Derivada objetoDeriv(10,15);
	objetoDeriv.imprimir();
	objetoDeriv.imprime();
	//cout<<objetoDeriv.dar();  Error porque deviba recibe la herencia de Base2 en forma privada
}
