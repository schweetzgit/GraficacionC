#include<iostream>
using namespace std;

class Circulo{ //con mayúscula pra indicar que es una clase
	private: 
		float radio;
		float x;
		float y;	
	public:
		//Constructor: crear objetos y mismo nombre de la clase
		Circulo(float otroRadio = 50.00, float otra_x = 100.00, float otra_y = 100.00){
			radio = otroRadio;
			x = otra_x;
			y = otra_y;
		}
		void calculaArea(){
			cout<<"\n El area del circulo de radio "<< radio <<" es: "<< 3.1416 * radio * radio;
		}
		void calculaPerimetro(){
			cout<<"\n El perimetro del circulo de radio "<< radio <<" es: "<< 3.1416 * 2 * radio;
		}
		float get_radio(){
			return radio;
		}
		float get_x(){
			return x;
		}
		float get_y(){
			return y;
		}
};

main(){ 
	float miradio;
	float mi_x;
	float mi_y;

	cout<<"\n Creacion del objeto1\n";
	Circulo objC1; //aqui se crea el objeto (se invoca al constructor automaticamente)
	objC1.calculaArea();
	objC1.calculaPerimetro();
	
	cout<<"\n\n Creacion del objeto2\n";
	Circulo objC2(100,230,220);
	objC2.calculaArea();
	objC2.calculaPerimetro();
	
	cout<<"\n\n Creacion del objeto3\n";
	Circulo objC3(1,230);
	objC3.calculaArea();
	objC3.calculaPerimetro();
	
	cout<<"\n\n Creacion del objeto4\n";
	Circulo objC4(10);
	objC4.calculaArea();
	objC4.calculaPerimetro();
	
	cout<<"\n\n Creacion del objeto5\n";
	cout<<" Dar el radio: ";
	cin>>miradio;
	cout<<"\n Dar el valor de x: ";
	cin>>mi_x;
	cout<<"\n Dar el valor de y: ";
	cin>>mi_y;
	
	Circulo objC5(miradio, mi_x, mi_y);
	objC5.calculaArea();
	objC5.calculaPerimetro();
	cout<<"\n El radio del circulo C5 es: "<< objC5.get_radio();
	cout<<"\n El valor de x del circulo C5 es: "<< objC5.get_x();
	cout<<"\n El valor de y del circulo C5 es: "<< objC5.get_y();
}

