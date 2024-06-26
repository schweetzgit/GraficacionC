#include<iostream>
#include<conio.h>
#include<math.h>
#include <graphics.h>
using namespace std;

class AbstractaFigurasGeometricas{
	protected:
		int visible,x,y;
	public:
		AbstractaFigurasGeometricas(int,int);
		virtual void pintar() = 0;
	    virtual void ocultar() = 0;	
	    void trasladar(int,int);//polimorfica
		int get_x();	
		int get_y();
		int get_visible();
};
AbstractaFigurasGeometricas::AbstractaFigurasGeometricas(int inic_x = 100, int inic_y = 200){
  	this->x = inic_x;
  	this->y = inic_y;
  	this->visible = 0;
}
void AbstractaFigurasGeometricas::trasladar(int nx, int ny){
	if(this->visible){
		ocultar();
		this->x = nx;
		this->y = ny;
		pintar();
	} 
	else{
		this->x = nx;
		this->y = ny;
	}
}
int AbstractaFigurasGeometricas::get_x(){return this->x;}
int AbstractaFigurasGeometricas::get_y(){return this->y;}
int AbstractaFigurasGeometricas::get_visible(){return this->visible;}

//----------------------------Circulo---------------------------------
class Circulo:public AbstractaFigurasGeometricas{
	private:
	  	float radio,pi;
	public:
	  	//constructor (lleva el mismo nombre de la clase)
	  	Circulo(int inic_x = 100, int inic_y = 200,float inic_radio = 50):AbstractaFigurasGeometricas(inic_x, inic_y){
			this->radio = inic_radio;
			this->pi = 3.1416;
		}
		void calculaArea(); //tiene acceso a las variables privadas ya que es una funcion de la misma clase
		void calculaPerimetro();	
		void pintar();
		void ocultar();	
		float get_radio();
		float get_pi();
};
void Circulo::calculaArea(){
    cout<<"\n El area del circulo es: "<<this->pi*this->radio*this->radio;
}
void Circulo::calculaPerimetro(){
	cout<<"\n El perimetro del circulo es: "<<this->pi*2*this->radio;
}
void Circulo::pintar(){
	this->visible = 1;
	circle(this->x,this->y,this->radio);
}
void Circulo::ocultar(){
	unsigned guardacolor = getcolor();//tomo el color que esta activo y lo guardo en get
	if(this->visible){
		setcolor(getbkcolor());
		circle(this->x,this->y,this->radio);
		this->visible = 0;
		setcolor(guardacolor);
	}
}	
float Circulo::get_radio(){return this->radio;}
float Circulo::get_pi(){return this->pi;}

//-----------------------------Rectangulo---------------------------
class Rectangulo:public AbstractaFigurasGeometricas{
	private:
		float base, altura;
	public:
		Rectangulo(int otrox = 100, int otroy=150, float otraBase = 100, float otraAltura = 60):AbstractaFigurasGeometricas(otrox, otroy){
			this->base = otraBase;
			this->altura = otraAltura;
		}
		void calculaArea();
		void calculaPerimetro();
		void pintar();
		void ocultar();
		float get_base();
		float get_altura();
};
void Rectangulo::calculaArea(){
    cout<<"\n El area del Rectangulo es: "<<this->base*this->altura;
}
void Rectangulo::calculaPerimetro(){
	cout<<"\n El perimetro del Rectangulo es: "<<2*base +2*altura;
}
void Rectangulo::pintar(){
	this->visible = 1;
	rectangle(this->x,this->y,x+base, y+altura);
}
void Rectangulo::ocultar(){
	unsigned guardacolor = getcolor();//tomo el color que esta activo y lo guardo en get
	if(this->visible){
		setcolor(getbkcolor());
		rectangle(this->x,this->y,x+base, y+altura);
		this->visible = 0;
		setcolor(guardacolor);
	}
}	
float Rectangulo::get_base(){return base;}	
float Rectangulo::get_altura(){return altura;}

//-----------------------------Elipse-------------------------------
class Elipse:public AbstractaFigurasGeometricas{
	private:
    	int radmay, radmen, ang1, ang2;
    public:
		Elipse(int ox, int oy, float rmay, float rmen): AbstractaFigurasGeometricas(ox,oy){
            radmay = rmay;
            radmen = rmen;
        }
        void calculaArea();
        void calculaPerimetro();
        void pintar();
        void ocultar(); 
    	float get_radmay();
        float get_radmen();   
};     
void Elipse::calculaArea(){
     cout<<"\n El area de la elipse de radio mayor: "<<radmay<<" y radio menor "<<radmen<<" es "<<3.1416*radmay*radmen;
}
void Elipse::calculaPerimetro(){
     cout<<"\n El perimetro de la elipse de radio mayor: "<<radmay<<" y radio menor "<<radmen<<" es "<<2*3.1416*(sqrt(radmay*radmay+radmen*radmen)/2);
}
void Elipse::pintar(){
     visible = 1;
     ellipse((int)x,(int)y,0,360,(int)radmay,(int)radmen);
}
void Elipse::ocultar(){
    if (visible){
	  	unsigned int guardacolor;
		guardacolor = getcolor();
		setcolor (getbkcolor());
		ellipse((int)x,(int)y,0,360,(int)radmay,(int)radmen);
		visible = 0;
		setcolor(guardacolor);
    }
}
float Elipse::get_radmay(){return radmay;}
float Elipse::get_radmen(){return radmen;}

//-----------------------------Linea-------------------------------
class Linea:public AbstractaFigurasGeometricas{
   private:
	int x2,y2;
   public:
	Linea(int inicx = 100, int inicy = 50,int inicx2 = 300,int inicy2 = 300):AbstractaFigurasGeometricas(inicx,inicy){	
		this->x2 = inicx2;
		this->y2 = inicy2;
	}
	void pintar();	
	void trasladar(int,int);
	void ocultar();
	int get_x2();
	int get_y2();
};
void Linea::trasladar(int nx, int ny){
	if(visible){
        ocultar();
        x += nx;
        y += ny;
        x2 += nx;
        y2 += ny;
        pintar();
    }
    else{
         x = nx;
         y = ny;
    }
}
void Linea::pintar(){
     visible = 1;
     line(x,y,x2,y2);
}
void Linea::ocultar(){
    if (visible){
        unsigned int guardacolor;
        guardacolor = getcolor();
        setcolor(getbkcolor());
        line(x, y, x2, y2);
        visible = 0;
        setcolor(guardacolor);
    }
}
int Linea::get_x2(){return x2;}
int Linea::get_y2(){return y2;}

//-----------------------------Punto---------------------------------
class Punto:public AbstractaFigurasGeometricas{
	public:
		Punto(int otrox = 100, int otroy = 150):AbstractaFigurasGeometricas(otrox, otroy){
		}
		void ocultar();
		void pintar();
};
void Punto::pintar(){
	this->visible = 1;
	putpixel(this->x,this->y,YELLOW);
}
void Punto::ocultar(){
	unsigned guardacolor = getcolor();//tomo el color que esta activo y lo guardo en get
	if(this->visible){
		setcolor(getbkcolor());
		putpixel(this->x,this->y,getbkcolor());
		this->visible = 0;
		setcolor(guardacolor);
	}
}

main(){
	//activamos los graficos:
	int gd=DETECT, gm;
	initgraph(&gd, &gm,"c:\\TC\\BGI");
	
	//----------------------Circulo------------------------
  	Circulo cirobj(150,150,70);
  	cirobj.pintar();
  	cirobj.get_x();
  	getch();
  	for(int i = 1; i < 30; i++){
		cirobj.trasladar(cirobj.get_x() + i,cirobj.get_y());
		delay(50);
	}
	getch();
	
	//----------------------Rectangulo------------------------
	Rectangulo r1(150,230,80,50);
  	r1.pintar();
  	getch();
  	for(int i = 1; i < 30; i++){
		r1.trasladar(r1.get_x() + i,r1.get_y());
		delay(50);
	}
	getch();
	
	//----------------------Elipse------------------------
  	Elipse e1(100,100,100,70);
  	e1.pintar();
  	getch();
	e1.trasladar(400,400);
	getch();
	
	//-----------------------Punto------------------------
	Punto p1(150, 350);	
  	p1.pintar();
  	getch();
  	for(int i = 1; i < 30; i++)	{
		p1.trasladar(p1.get_x() + i,p1.get_y());
		delay(50);
	}
	getch();
	closegraph();
	
	//-----------------------Linea------------------------
	Linea lin1(50,50,180,70);	
  	lin1.pintar();
  	getch();
  	lin1.trasladar(50,50);
  	getch();
	closegraph();
}
