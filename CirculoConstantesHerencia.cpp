#include<iostream>
#include<graphics.h>
#include<dos.h>
using namespace std;

class Circulo
{
  private:
	static const float pi=3.1416;
	static int contador;
	float radio;
	float x;
	float y;
	int visible;
	
public:
	Circulo(float, float, float);
	void calcula_area() const;
	void calcula_perimetro() const;
	float get_radio() const;
	float get_x() const;
	float get_y() const;
	float get_pi() const;
	int get_contador()const;
	void mueve(int, int);
	void oculta();
	void pinta();
};

Circulo::Circulo(float otro_x = 200,float otro_y = 300 , float otro_radio = 50){
	
	this->radio= otro_radio;
	this->x= otro_x;
	this->y= otro_y ;
	this->visible=0;
	contador++;
}

float Circulo::get_pi() const{
	return this->pi;
}
int Circulo::get_contador() const{
	return this->contador;
}

float Circulo::get_radio() const{
	return this->radio;
}

void Circulo::calcula_perimetro() const{
	cout<<"\nEl perimetro del circulo es "<< this->pi*2*this->radio;
}

void Circulo::calcula_area() const{
	cout<<"\nEl area del circulo es "<< this->pi*this->radio*this->radio;
}



float Circulo::get_x() const{
	return this->x;
}

float Circulo::get_y()const{

	return this->y;
}

int Circulo::contador=0;

void Circulo::mueve(int nx, int ny){
	if(visible){
		oculta();
		this->x= nx;
		this->y= ny;
		pinta();
	}
	else{
		this->x= nx;
		this->y= ny;
	}
	
}

void Circulo::oculta(){
	unsigned guardaColor= getcolor();
	if(this->visible){
		setcolor(getbkcolor());
		circle((int)this->x,(int)this->y,(int)this->radio);
	    this->visible=0;
	    setcolor(guardaColor);
	} 
}

void Circulo::pinta(){
	circle((int)this->x,(int)this->y,(int)this->radio);
	this->visible=1;
}

//cliente
main(){
	
	int gd=DETECT, gm;
	initgraph(&gd, &gm,"c:\\TC\\BGI");
	
	Circulo objCir1(50,50, 50);
	
	objCir1.pinta();
	getch();
	for(int i=1;i<300; i++ ){
		objCir1.mueve(50+i,50+i);
		delay(20);
	}
	
	cout<<"\nEl coooooontador= "<<objCir1.get_contador();
	
	const Circulo objCir3(50,50, 50);
	cout<<"\n radio del circulo CONSTANTE es: "<<objCir3.get_radio() ;
	cout<<"\n radio del circulo CONSTANTE es: "<<objCir3.get_contador() ;
	
	getch();


	Circulo objCir2(550,50, 100);
	cout<<"\n x: "<<objCir2.get_x()<<"\n y: "<<objCir2.get_y();
	cout<<"\n radio: "<< objCir2.get_radio();
	cout<<"\n pi: "<< objCir2.get_pi();
	objCir2.calcula_area();
	objCir2.calcula_perimetro();
	objCir2.pinta();
	getch();
	for(int i= 550; i>0; i--){
		objCir2.mueve(550-i, 50);
		delay(30);
	}
	cout<<"\nEl coooooontador= "<<objCir2.get_contador();
	
	
	getch();
	
	
	closegraph();
}
