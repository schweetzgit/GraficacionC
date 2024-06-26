#include<iostream>
#include<conio.h>
#include<math.h>
#include <graphics.h>

using namespace std;

class AbstractaFigurasGeometricas{
	private:
		
	protected:
		int visible;
		int x,y;
	public:
		AbstractaFigurasGeometricas(int, int);
		virtual void pintar()=0;
	    virtual void ocultar()=0;	
	    void trasladar(int, int);//polimorfica
		int get_x();	
		int get_y();
		int get_visible();
	
};

AbstractaFigurasGeometricas::AbstractaFigurasGeometricas(int inic_x=100, int inic_y=200)
{
  	this->x=inic_x;
  	this->y=inic_y;
  	this->visible=0;
}
void AbstractaFigurasGeometricas::trasladar(int nx, int ny)
{
	if(this->visible)
	{
		ocultar();
		this->x=nx;
		this->y=ny;
		pintar();
	} else
	{
		this->x=nx;
		this->y=ny;
	}
}
int AbstractaFigurasGeometricas::get_x()
{ return this->x;}
	
int AbstractaFigurasGeometricas::get_y()
{return this->y;}

int AbstractaFigurasGeometricas::get_visible()
{return this->visible;}

////////////////////////////////////////////////////

class Circulo: public AbstractaFigurasGeometricas
{
  private:
  	float radio,pi;
  public:
  	//constructor (lleva el mismo nombre de la clase)
  	Circulo(int, int,float);
	void calculaArea();//tiene acceso a las variables privadas ya que es una funcion de la misma clase
	void calculaPerimetro();	
	void pintar();
	void ocultar();	
	float get_radio();
	float get_pi();
	
};

void Circulo::calculaArea(){
    cout<<"\nEl area del circulo es "<<this->pi*this->radio*this->radio;
}

void Circulo::calculaPerimetro(){
	cout<<"\nEl perimetro del circulo es "<<this->pi*2*this->radio;
}
void Circulo::pintar(){
	this->visible=1;
	circle(this->x,this->y,this->radio);
}
void Circulo::ocultar(){
	unsigned guardacolor=getcolor();//tomo el color que esta activo y lo guardo en get
	if(this->visible)
	{
		setcolor(getbkcolor());
		circle(this->x,this->y,this->radio);
		this->visible=0;
		setcolor(guardacolor);
	}
}

float Circulo::get_radio()
{return this->radio;}
	
float Circulo::get_pi()
{return this->pi;}
	
Circulo::Circulo(int inic_x=100, int inic_y=200,float inic_radio=50): AbstractaFigurasGeometricas(inic_x, inic_y)
{
  	this->radio=inic_radio;
  	this->pi=3.1416;
}


/////////////////////////////////

class Rectangulo:public AbstractaFigurasGeometricas{
   private:
	float base,altura;
	
   public:
	Rectangulo(float inicb=100, float inica=50,int inicx=300,int inicy=300): AbstractaFigurasGeometricas(inicx, inicy)
	{
		this->base=inicb;
		this->altura=inica;
	}
	void calculaArea();
	void calculaPerimetro();
	void pintar();	
	void ocultar();
    float get_base();	 
    float get_altura();
};
	
void Rectangulo::calculaArea(){
	cout<<"El area del rectanguloes "<< base*altura;
}

void Rectangulo::calculaPerimetro(){
	cout<<"El perimetro del rectanguloes "<< 2*base+ 2*altura;
}
	
void Rectangulo::pintar(){
	this->visible=1;
	rectangle(this->x,this->y,this->x + this->base,this->y + this->altura);
}

void Rectangulo::ocultar(){
	unsigned guardacolor=getcolor();
		
	if (this->visible){
	   setcolor(getbkcolor());
	   rectangle(this->x,this->y,this->x + this->base,this->y + this->altura);
	   this->visible=0;
	   setcolor(guardacolor);
	}
}

float Rectangulo::get_base(){
	return this->base;
}
float Rectangulo::get_altura(){
	return this->altura;
}

/////////////////////////////

class Elipse: public AbstractaFigurasGeometricas{
          float radmay,radmen;
    public:
           Elipse(int ox, int oy, float rmay, float rmen): AbstractaFigurasGeometricas(ox,oy)
           {
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


           
void Elipse:: calculaArea(){
     cout<< "\nEl area de la elipse de radio mayor"<< radmay << "y radio menor" << radmen << "es" << 3.1416 * radmay * radmen;
}

void Elipse:: calculaPerimetro(){
     cout<< "\nEl perimetro de la elipse de radio mayor"<< radmay << "y radio menor" << radmen << "es" << 2* 3.1416 * (sqrt (radmay*radmay+radmen*radmen)/2);
}

void Elipse:: pintar()
{
     visible = 1;
     ellipse((int)x,(int)y,0,360,(int)radmay,(int)radmen);
}

void Elipse :: ocultar()
{
      if (visible)
      {
              unsigned int guardacolor;
              guardacolor = getcolor();
              setcolor (getbkcolor());
              ellipse((int)x,(int)y,0,360,(int)radmay,(int)radmen);
              visible = 0;
              setcolor(guardacolor);
      }
}

float Elipse::get_radmay(){
  return radmay;
}
float Elipse::get_radmen(){
  return radmen;
}

///////////////////////////

class Linea: public AbstractaFigurasGeometricas{
   private:
	int x2,y2;
   public:
	Linea(int inicx=100, int inicy=50,int inicx2=300,int inicy2=300):AbstractaFigurasGeometricas(inicx, inicy)
	{	
		this->x2=inicx2;
		this->y2=inicy2;
	}
	void pintar();	
	void trasladar(int, int);
	void ocultar();
	int get_x2();
	int get_y2();
};


void Linea:: trasladar(int nx, int ny)
{
     if(visible)
     {
            ocultar();
            x += nx;
            y += ny;
            x2+= nx;
            y2+= ny;
            pintar();
     }
     else
     {
         x = nx;
         y = ny;
     }
}




void Linea:: pintar()
{
     visible = 1;
     line(x, y, x2, y2);
}

void Linea :: ocultar()
{
      if (visible)
      {
              unsigned int guardacolor;
              guardacolor = getcolor();
              setcolor (getbkcolor());
              line(x, y, x2, y2);
              visible = 0;
              setcolor(guardacolor);
      }
}

int Linea::get_x2(){return x2;}
int Linea::get_y2(){return y2;}

/////////////////////////


class Punto: public AbstractaFigurasGeometricas{
   private:
	
   public:
	Punto(int inicx=10,int inicy=10): AbstractaFigurasGeometricas(inicx,inicy)
	{
		
	}
	void pintar();	
	void ocultar();

};
void Punto:: pintar()
{
     visible = 1;
     putpixel(x, y, YELLOW);
}
void Punto :: ocultar()
{
      if (visible)
      {
              putpixel(x, y, getbkcolor());
              visible = 0;
      }
}


main(){
	
	int pantalla=DETECT, modo;
	initgraph(&pantalla, &modo,"c:\\TC\\BGI");
	
	Circulo c1(100,100,80);
	c1.pintar();
	getch();
	c1.trasladar(400,400);
	getch();
	
	Rectangulo r1(200,200,100, 50);
	r1.pintar();
	getch();
	
	r1.trasladar(300,300);
	getch();
	
	Elipse e1(100,100,100, 70);
	e1.pintar();
	getch();
	
	e1.trasladar(400,400);
	getch();
	
	Linea lin1(50,50,180,70);
	lin1.pintar();
	getch();
	
	lin1.trasladar(50,50);
	
	getch();
	Punto p1;
	p1.pintar();
	getch();
	p1.trasladar(50,100);
	getch();
	
	closegraph();
}
