#include<iostream>
using namespace std;

class Rectangulo{
	private:
		float base, altura, x, y;
	public:	
		Rectangulo(float otraBase = 100, float otraAltura = 50, float otraX = 200, float otraY = 200){
			this -> base = otraBase;
			this -> altura = otraAltura;	
			this -> x = otraX;
			this -> y = otraY;	
		}
		void calculaArea(){
			cout<<"\n El area del rectangulo es: "<< base * altura;
		}
		void calculaPerimetro(){
			cout<<"\n El perimetro del rectangulo es: "<< 2 * base + 2 * altura;
		}
		float getBase(){
			return this -> base;
		}
		float getAltura(){
			return this -> altura;
		}
		float getX(){
			return this -> x;
		}
		float getY(){
			return this -> y;
		}
};
//Cliente es toda funcion que crea objetos de la clase
main(){
	Rectangulo objR1; //Se invoca al constructor, se instancia (se crea) el objeto
	float miBase, miAltura, miX, miY;
	
	cout<<"\n Rectangulo 1\n";
	cout<<"\n Base: "<< objR1.getBase();
	cout<<"\n Altura: "<< objR1.getAltura();
	cout<<"\n X: "<< objR1.getX();
	cout<<"\n Y: "<< objR1.getY();
	objR1.calculaArea();
	objR1.calculaPerimetro();
	
	cout<<"\n\n Rectangulo 2\n\n Dar la base: ";
	cin>>miBase;
	cout<<" Dar la altura";
	cin>>miAltura;
	cout<<" Dar la x";
	cin>>miX;
	cout<<" Dar la y";
	cin>>miY;

	Rectangulo objR2(miBase, miAltura, miX, miY);

	cout<<"\n Base: "<< objR2.getBase();
	cout<<"\n Altura: "<< objR2.getAltura();
	cout<<"\n X: "<< objR2.getX();
	cout<<"\n Y: "<< objR2.getY();
	objR2.calculaArea();
	objR2.calculaPerimetro();
}
