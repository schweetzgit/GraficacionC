#include<iostream>
#include<conio.h>
#include<graphics.h>
using namespace std;

class Circulo{
	private:
  		float pi;
  		float x,y;
  		int visible;
	protected:
  		float radio;
	public:
	  	//constructor (lleva el mismo nombre de la clase)
	  	Circulo(float, float ,float);
		void calculaArea();//tiene acceso a las variables privadas ya que es una funcion de la misma clase
		void calculaPerimetro();	
		virtual void pintar();
		void ocultar();	
		void trasladar(int, int);//Polimorfismo
		int get_x();	
		int get_y();
		float get_radio();
		float get_pi();
		int get_visible();
};
Circulo::Circulo(float otroX = 100, float otroY = 200, float otroRadio = 50){
  	this->x = otroX;
  	this->y = otroY;
  	this->radio = otroRadio;
  	this->visible = 0;
  	this->pi = 3.1416;
}

class CirculoColor:public Circulo{
	private:
		unsigned color;
	public:
		//Clase hija. Datos para inicializar la superclase y a la misma
		CirculoColor(float otraX = 100, float otraY = 100, float otroRadio = 50, int otroColor = YELLOW):Circulo(otraX, otraY, otroRadio){
			color = otroColor;
		}
		virtual void pintar();
};
class CirculoInflable:public Circulo{
	private:

	public:
		CirculoInflable(float otraX = 100, float otraY = 100, float otroRadio = 50):Circulo(otraX, otraY, otroRadio){
			
		}
		void inflar(int);
		void desinflar(int en_cuanto_crece);
};

void Circulo::pintar(){
	this->visible = 1;
	circle((int)this->x,(int)this->y,(int)this->radio);
}
void CirculoColor::pintar(){
	unsigned guardaColor = getcolor();
	setcolor(color);
	Circulo::pintar();
	setcolor(guardaColor);	
}

void CirculoInflable::inflar(int en_cuanto_crece){
	ocultar();
	radio = radio + en_cuanto_crece;
	pintar();
}
void CirculoInflable::desinflar(int en_cuanto_crece){
	inflar(-en_cuanto_crece);
}

void Circulo::calculaArea(){
    cout<<"\n\n El area del circulo es: "<<this->pi*this->radio*this->radio;
}
void Circulo::calculaPerimetro(){
	cout<<"\n El perimetro del circulo es: "<<this->pi*2*this->radio;
}

void Circulo::ocultar(){
	unsigned guardacolor=getcolor();//tomo el color que esta activo y lo guardo en get
	if(this->visible){
		setcolor(getbkcolor());
		circle((int)this->x,(int)this->y,(int)this->radio);
		this->visible=0;
		setcolor(guardacolor);
	}
}
void Circulo::trasladar(int nx, int ny){
	if(this->visible)	{
		ocultar();
		this->x=nx;
		this->y=ny;
		pintar();
	} else{
		this->x=nx;
		this->y=ny;
}
}
int Circulo::get_x()
{ return this->x;}
	
int Circulo::get_y()
{return this->y;}
	
float Circulo::get_radio()
{return this->radio;}
	
float Circulo::get_pi()
{return this->pi;}

int Circulo::get_visible()
{return this->visible;}

main(){   //activamos los graficos:
	int pantalla=DETECT;
	int modo;
	initgraph(&pantalla,&modo,"c:\\TC\\BGI");
	
  	Circulo cirobj(350,280,70);
  	cirobj.calculaArea();
  	cirobj.calculaPerimetro();
  	cirobj.pintar();
  	getch();
  	for(int i = 1; i < 30; i++){
		cirobj.trasladar(cirobj.get_x() + i,cirobj.get_y());
		delay(50);
	}
	getch();

	CirculoColor cirColor(200, 150, 90, CYAN);
	cirColor.calculaArea();
	cirColor.calculaPerimetro();
	cirColor.pintar();
	getch();
	for(int i = 1; i < 50; i++){
		cirColor.trasladar(cirColor.get_x() ,cirColor.get_y() + i);
		delay(50);
	}
	getch();
	
	CirculoColor cirColor2;
	cirColor2.calculaArea();
	cirColor2.calculaPerimetro();
	cirColor2.pintar();
	getch();
  	for(int i = 1; i < 50; i++){
		cirColor2.trasladar(cirColor2.get_x()+i ,cirColor2.get_y() + i);
		delay(50);
	}
	getch();
	
	CirculoInflable circInfla;
	circInfla.calculaArea();
	circInfla.calculaPerimetro();
	circInfla.pintar();
	getch();
	for(int i = 1; i < 40; i++){
		circInfla.trasladar(circInfla.get_x()+i ,circInfla.get_y());
		delay(50);
	}
	getch();
	for(int i = 1; i < 20; i++){
		circInfla.inflar(i);
		delay(50);
	}
	getch();
	for(int i = 1; i < 20; i++){
		circInfla.desinflar(i);
		delay(50);
	}
	getch();
	closegraph();
}
