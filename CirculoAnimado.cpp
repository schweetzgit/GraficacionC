#include<iostream>
#include<graphics.h>
#include<dos.h>
using namespace std;

class Circulo{
	private:
		float pi;
		float radio;
		float x;
		float y;
		int visible;
	public:
		Circulo(float, float, float );
		void calcula_area();
		void calcula_perimetro();
		float get_radio();
		float get_x();
		float get_y();
		float get_pi();
		void mueve(int, int);
		void oculta();
		void pinta();
};

float Circulo::get_radio(){
	return this->radio;
}

void Circulo::calcula_perimetro(){
	cout<<"\n El perimetro del circulo es "<< pi*2*radio;
}

void Circulo::calcula_area(){
	cout<<"\n El area del circulo es "<< pi*radio*radio;
}

Circulo::Circulo(float otro_y = 300, float otro_x = 200, float otro_radio = 50){
	pi = 3.1416;
	radio = otro_radio;
	x = otro_x;
	y = otro_y ;
	visible = 0;
}

float Circulo::get_x(){
	return this->x;
}
float Circulo::get_y(){
	return this->y;
}
float Circulo::get_pi(){
	return this->pi;
}

void Circulo::mueve(int nuevaX, int nuevaY){
	if(visible){
		oculta();
		x = nuevaX;
		y = nuevaY;
		pinta();
	} else{
		x = nuevaX;
		y = nuevaY;	
	}
}

void Circulo::oculta(){
	unsigned guardaColor = getcolor();
	if(visible){ //implicito que es verdader (==1)
		setcolor(getbkcolor());
		circle((int)x,(int)y,(int)radio);
		visible = 0;
		setcolor(guardaColor);		
	}
}
void Circulo::pinta(){ // :: para indicar que pertenece a la clase circulo
	circle((int)x,(int)y,(int)radio);
	visible = 1;
}
//cliente
main(){
	int gd=DETECT, gm;
	initgraph(&gd, &gm,"c:\\TC\\BGI");
	
	Circulo objCir1;
	objCir1.pinta();
	getch();
	for(int i = 1; i < 100; i++){
		objCir1.mueve(200+i,0);
		delay(20);
	}
	
	Circulo objCir2(550,50,100);
	cout<<"\n x: "<<objCir2.get_x();
	cout<<"\n y: "<<objCir2.get_y();
	cout<<"\n radio: "<<objCir2.get_radio();
	cout<<"\n pi: "<<objCir2.get_pi();
	objCir2.calcula_area();
	objCir2.calcula_perimetro();
	objCir2.pinta();
	getch();
	for(int i = 550; i > 0; i--){
		objCir2.mueve(550-i,50-i);
		delay(30);
	}
	getch();
	system("pause");
	closegraph();
}
