#include<iostream>
#include<graphics.h>
#include<dos.h>
#include<math.h>
using namespace std;

class Triangulo{
	private:
		int x1, x2, x3, y1, y2, y3;
		int vect[8];
		int visible;
	public:
		Triangulo(int, int, int, int, int, int);
		int get_x1();
		int get_y1();
		int get_x2();
		int get_y2();
		int get_x3();
		int get_y3();
		int get_visible();
		void trasladar(int, int);
		void oculta();
		void pinta();
};

Triangulo::Triangulo(int cox1=300, int coy1=100, int cox2=50, int coy2=250,int cox3=400, int coy3=250){
	x1 = cox1;
	y1 = coy1;
	x2 = cox2;
	y2 = coy2;
	x3 = cox3;
	y3 = coy3;
	vect[0]=x1;
	vect[1]=y1;
	vect[2]=x2;
	vect[3]=y2;
	vect[4]=x3;
	vect[5]=y3;
	vect[6]=x1;
	vect[7]=y1;
}

int Triangulo::get_x1(){return x1;}
int Triangulo::get_y1(){return y1;}
int Triangulo::get_x2(){return x2;}
int Triangulo::get_y2(){return y2;}
int Triangulo::get_x3(){return x3;}
int Triangulo::get_y3(){return y3;}
int Triangulo::get_visible(){return visible;}	

void Triangulo::pinta(){
	visible = 1;
	setfillstyle(2,MAGENTA);
	fillpoly(3,vect);
}	

void Triangulo::oculta(){
	unsigned guardacolor = getcolor();
	if(visible){
		visible = 0;
		setcolor(getbkcolor());
		setfillstyle(2,getbkcolor());
		fillpoly(3,vect);
		setcolor(guardacolor);
	}
}
void Triangulo::trasladar(int nx, int ny){
	if(visible){
		oculta();
		int difx = abs(x1 - nx);
		int dify = abs(y1 - ny);
		vect[0]=x1+difx;
		vect[1]=y1+dify;
		vect[2]=x2+difx;
		vect[3]=y2+dify;
		vect[4]=x3+difx;
		vect[5]=y3+dify;
		vect[6]=x1+difx;
		vect[7]=y1+dify;
		pinta();
	}
}
main(){
	int gd=DETECT, gm;
	initgraph(&gd, &gm,"c:\\TC\\BGI");
	Triangulo t1;
	t1.pinta();
	getch();
	for(int i = 1; i < 300; i++){
		t1.trasladar(300+i,100);
		delay(50);
	}
	getch();
	closegraph();
}
