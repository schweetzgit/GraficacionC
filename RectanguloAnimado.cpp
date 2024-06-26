#include<iostream>
#include<graphics.h>
#include<dos.h>
using namespace std;

class Rectangulo{
	private:
		float altura;
		float base;
		float x;
		float y;
		int visible;
		
	public:
		Rectangulo(float, float, float, float);
		void calcula_area();
		void calcula_perimetro();
		float get_base();
		float get_altura();
		float get_x();
		float get_y();
		int get_visible();
		void pinta();
		void oculta();
		void mueve(int, int);
};

Rectangulo::Rectangulo(float otro_x = 200,float otro_y = 300 , float otro_base = 100, float otro_altura = 60){
	this->base = otro_base;
	this->altura = otro_altura;
	this->x = otro_x;
	this->y = otro_y ;
	this->visible = 0;
}

void Rectangulo::calcula_area(){
	cout<<"\n El area del rectangulo es: "<< this->base * this->altura;
}

void Rectangulo::calcula_perimetro(){
	cout<<"\n El perimetro del rectangulo es: "<< 2 * this->base + 2 * this->altura;
}

float Rectangulo::get_base(){
	return this->base;
}

float Rectangulo::get_altura(){
	return this->altura;
}

float Rectangulo::get_x(){
	return this->x;
}

float Rectangulo::get_y(){
	return this->y;
}

int Rectangulo::get_visible(){
	return this->visible;
}

void Rectangulo::pinta(){
	rectangle((int)this->,(int)this->y,(int)(this->x+base),(int)(this->y+altura));
	this->visible = 1;
}

void Rectangulo::oculta(){
	unsigned guardaColor = getcolor();
	if(this->visible){
		setcolor(getbkcolor());
		rectangle((int)this->x,(int)this->y,(int)(this->x+base),(int)(this->y+altura));
	    this->visible = 0;
	    setcolor(guardaColor);
	} 
}

void Rectangulo::mueve(int nx, int ny){
	if(visible){
		oculta();
		this->x = nx;
		this->y = ny;
		pinta();
	}
	else{
		this->x = nx;
		this->y = ny;
	}
	
}
//cliente
main(){
	int gd=DETECT, gm;
	initgraph(&gd, &gm,"c:\\TC\\BGI");
	
	Rectangulo r1(50,50,150,80);
	r1.pinta();
	getch();
	for(int i = 1; i < 300; i++){
		r1.mueve(50+i,50);
		delay(20);
	}
	getch();
	
	Rectangulo r2(150,150, 80, 150);
	cout<<"\n x: "<<r2.get_x()<<"\n y: "<<r2.get_y();
	cout<<"\n Base: "<< r2.get_base();
	cout<<"\n Altura: "<< r2.get_altura();
	cout<<"\n Visible: "<< r2.get_visible();
	r2.calcula_area();
	r2.calcula_perimetro();
	r2.pinta();
	getch();
	for(int i = 1; i < 300; i++){
		//cout<<"\nRepite r2";
		r2.mueve(150+i, 150+i);
		delay(30);
	}
	getch();
	
	Rectangulo r3(350,250,180,95);
	r3.pinta();
	getch();
	for(int i = 1; i < 300; i++){
		//cout<<"Repite r3";
		r3.mueve(350, 250+i);
		delay(30);
	}
	getch();
	closegraph();
}
