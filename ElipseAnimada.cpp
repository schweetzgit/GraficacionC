#include<iostream>
#include<graphics.h>
#include<dos.h>
using namespace std;

//Se crea la clase Elipse
class Elipse{ 
  private: 
  	float pi;
	float radioX; 
	float radioY;
	/*Se denomina radioX y radioY por la posición horizontal 
	o vertical que puede tener la elipse*/
	float anguloIn;
	float anguloFn;
	/*En este caso debe ser de 0 a 360, para que sea una elipse
	de otro modo quedaría un arco*/
	float x;
	float y;
	int visible;
	
public:
	Elipse(float, float, float, float, float, float);
	void calcula_area();
	void calcula_perimetro();
	float get_radioX();
	float get_radioY();
	float get_x();
	float get_y();
	float get_pi();
	int get_visible();
	void pinta();
	void oculta();
	void mueve(int, int);
};
/*Se crea el constructor, teniendo en cuenta el orden de 
los datos: ellipse(x,y,anguloInicial,anguloFinal,radioX,radioY)*/
Elipse::Elipse(float otro_x = 300, float otro_y = 300, float otro_anguloIn = 0, float otro_anguloFn = 360, float otro_radioX = 60, float otro_radioY = 150){
	this->pi = 3.1416;
	this->anguloIn = 0;
	this->anguloFn = 360;
	this->radioX = otro_radioX;
	this->radioY = otro_radioY;
	this->x = otro_x;
	this->y = otro_y ;
	this->visible = 0;
}
//Se calcula el área
void Elipse::calcula_area(){
	cout<<"\n El area de la elipse es: "<< this->pi * this->radioX * this->radioY;
}
//Se calcula el perimetro
void Elipse::calcula_perimetro(){
	cout<<"\n El perimetro de la elipse es: "<< this->pi * (this->radioX + this->radioY);
}
float Elipse::get_pi(){
	return this->pi;
}

float Elipse::get_radioX(){
	return this->radioX;
}

float Elipse::get_radioY(){
	return this->radioY;
}

float Elipse::get_x(){
	return this->x;
}

float Elipse::get_y(){
	return this->y;
}

int Elipse::get_visible(){
	return this->visible;
}
/*Se pinta y oculta la elipse de acuerdo a el orden de los datos
	ellipse(x,y,anguloInicial,anguloFinal,radioX,radioY)*/
void Elipse::pinta(){
	ellipse((float)this->x,(float)this->y,(float)this->anguloIn,(float)this->anguloFn,(float)this->radioX,(float)this->radioY);
	this->visible = 1;
}

void Elipse::oculta(){
	unsigned guardaColor = getcolor();
	if(this->visible){
		setcolor(getbkcolor());
		ellipse((float)this->x,(float)this->y,(float)this->anguloIn,(float)this->anguloFn,(float)this->radioX,(float)this->radioY);
	    this->visible = 0;
	    setcolor(guardaColor);
	} 
}
// Se mueve el centro
void Elipse::mueve(int nx, int ny){
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
	
	/*Primera Elipse
	Se mueve horizontalmente hacia la derecha*/
	Elipse e1(150,100,0,360,120,50);
	e1.pinta();
	getch();
	for(int i = 1; i < 300; i++){
		e1.mueve(150+i,100);
		delay(20);
	}
	getch();
	
	/*Segunda Elipse
	Se mueve en diagonal hacia abajo y después a la derecha*/
	Elipse e2(150,150,0,360,50,90);
	//Se imprimen los datos de la elipse
	cout<<" Segunda Elipse";
	cout<<"\n x: "<< e2.get_x()<<"\n y: "<< e2.get_y();
	cout<<"\n Radio en x: "<< e2.get_radioX();
	cout<<"\n Radio en y: "<< e2.get_radioY();
	cout<<"\n Pi: "<<e2.get_pi();
	cout<<"\n Visible: "<< e2.get_visible();
	e2.calcula_area();
	e2.calcula_perimetro();
	e2.pinta();
	getch();
	for(int i = 1; i < 200; i++){
		e2.mueve(150+i, 150+i);
		delay(30);
	}
	/*Se toma el centro anterior para que continues el movimiento*/
	Elipse e22(349,349,0,360,50,90);
	e22.pinta();
	for(int j = 1; j < 200 ; j++){
			e22.mueve(349+j, 349);
			delay(30);
	}
	getch();
	
	/*Tercera Elipse
	Se mueve de abajo hacia arriba*/
	Elipse e3(150,320,0,360,60,110);
	e3.pinta();
	getch();
	for(int i = 1; i < 170; i++){
		e3.mueve(150,320-i);
		delay(30);
	}
	getch();
	closegraph();
}
