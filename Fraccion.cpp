#include<iostream>
#include<stdlib.h>
using namespace std;

class Fraccion{
	int num, den;
	public:
		Fraccion(int, int); //constructor
		void imprimir();
		Fraccion simplifica();
		
		/*Fraccion operator + (Fraccion f2);
		Fraccion operator - (Fraccion f2);
		Fraccion operator * (Fraccion f2);
		Fraccion operator / (Fraccion f2);*/
		
		Fraccion & operator + (Fraccion &);
		Fraccion operator + (int x);
		friend Fraccion operator + (int x, Fraccion &f2);
		/*La funcion amiga es necesaria porque ya no será posible
		aplicar objeto.operator+(f2)
		La funcion amiga es ajena a la clase, pero tiene acceso a los
		elemenos privados*/
		Fraccion operator += (Fraccion &f2);
		Fraccion operator += (int);
		/*friend Fraccion operator += (int,Fraccion f2); No es posible, 
		ya que del lado izq. de la asignacion no puede haber una costante: 5+=c es invalido 5=5+c*/
		
		Fraccion operator - (Fraccion &f2);
		Fraccion operator - (int x);
		friend Fraccion operator - (int x, Fraccion &f2);
		Fraccion operator -= (Fraccion &f2);
		Fraccion operator -= (int);
		
		Fraccion operator * (Fraccion &f2);
		Fraccion operator * (int x);
		friend Fraccion operator * (int x, Fraccion &f2);
		Fraccion operator *=(Fraccion &f2);
		Fraccion operator *=(int);
		
		Fraccion operator / (Fraccion &f2);
		Fraccion operator / (int x);
		friend Fraccion operator / (int x, Fraccion &f2);
		Fraccion operator /= (Fraccion &f2);
		Fraccion operator /= (int x);
		
		Fraccion & operator = (Fraccion &);
		Fraccion & operator = (int x);
		
		int operator == (Fraccion &);
		int operator == (int);
		friend int operator == (int, Fraccion &);
};

Fraccion::Fraccion(int otro_num = 0, int otro_den = 1){
	this->num = otro_num;
	if (otro_den == 0){
		this->den = 1;
	}
	else{
		this->den = otro_den;
	}
}

void Fraccion::imprimir(){
	cout<<" "<<num<<"/"<<den;
}

Fraccion Fraccion::simplifica(){
 	if (den<0){
 		num = -num;
 		den = -den;
 	}
 	for (int i = abs(num)<den ? abs(num):den; (i>=2) && (den>1); i--){
 		if ((num%i) == 0 && (den%i)==0){
			num /= i;
			den /= i;
 		}
 	}
 	return *this;
}

/*Paso por valor: copyconstructor para crear a f2
Fraccion Fraccion::operator + (Fraccion f2){  
	Fraccion resultado;
	resultado.num = this->num*f2.den + this->den*f2.num;
	resultado.den = this->den*f2.den;
	return resultado;
}

Fraccion Fraccion::operator - (Fraccion f2){
	Fraccion resultado;
	resultado.num = this->num*f2.den - this->den*f2.num;
	resultado.den = this->den*f2.den;
	return resultado;
}
Fraccion Fraccion::operator * (Fraccion f2){
	Fraccion resultado;
	resultado.num = num*f2.num;
	resultado.den = den*f2.den;
	return resultado;
}
Fraccion Fraccion::operator / (Fraccion f2){
	Fraccion resultado;
	resultado.num = this->num*f2.den;
	resultado.den = this->den*f2.num;
	return resultado;
}*/

//Por referencia: ya no se invoca copyconstructor 
Fraccion & Fraccion::operator + (Fraccion &f2){
	Fraccion result;
	result.num = this->num*f2.den + this->den*f2.num;
	result.den = this->den*f2.den;
	return result;
}

/*Fraccion Fraccion::operator + (Fraccion &f2){
	return Fraccion(this->num * f2.den + this->den*f2.num, this->den * f2.den);
}*/

Fraccion Fraccion::operator - (Fraccion &f2){
	return Fraccion(this->num*f2.den - this->den*f2.num,this->den*f2.den);
}

Fraccion Fraccion::operator * (Fraccion &f2){
	return Fraccion(num*f2.num, den*f2.den);
}

Fraccion Fraccion::operator / (Fraccion &f2){
	return Fraccion(this->num*f2.den,this->den*f2.num);
}

//Fraccion y entero
Fraccion Fraccion::operator + (int x){
	Fraccion resultado;
	resultado.num = this->num + den*x;
	resultado.den = this->den;
	return resultado;
}

Fraccion Fraccion::operator - (int x){
	Fraccion resultado;
	resultado.num = this->num - den*x;
	resultado.den = this->den;
	return resultado;
}

Fraccion Fraccion::operator * (int x){
	Fraccion resultado;
	resultado.num = this->num*x;
	resultado.den = this->den;
	return resultado;
}

Fraccion Fraccion::operator / (int x){
	Fraccion resultado;
	resultado.num = num;
	resultado.den = den*x;
	return resultado;
}

/*Definicion del cuerpo de una funcion amiga
  No lleva Fraccion:: porque no es miembro de la clase, es ajena
  Amigas, no llevan this->, porque no hay objeto apuntado*/
Fraccion operator + (int x, Fraccion &f2){
	Fraccion resultado;
	resultado.num = f2.num + f2.den*x;
	resultado.den = f2.den;
	return resultado;
}

Fraccion operator - (int x, Fraccion &f2){
	Fraccion resultado;
	resultado.num = f2.num - f2.den*x;
	resultado.den = f2.den;
	return resultado;
}

Fraccion operator * (int x, Fraccion &f2){
	Fraccion resultado;
	resultado.num = f2.num*x;
	resultado.den = f2.den;
	return resultado;
}

Fraccion operator / (int x, Fraccion &f2){
	Fraccion resultado;
	resultado.num = f2.den/x;
	resultado.den = f2.num;
	return resultado;
}

//Fracciones
Fraccion Fraccion::operator += (Fraccion &f2){
	this->num = this->num * f2.den + this->den*f2.num;
	this->den = this->den * f2.den;
	return *this; //el cambio afecta a quien invoco
}

Fraccion Fraccion::operator -= (Fraccion &f2){
	this->num = this->num * f2.den - this->den*f2.num;
	this->den = this->den * f2.den;
	return *this; 
}

Fraccion Fraccion::operator *= (Fraccion &f2){
	this->num = this->num * f2.num;
	this->den = this->den * f2.den;
	return *this;
}

Fraccion Fraccion::operator /= (Fraccion &f2){
	this->num = this->num *f2.den;
	this->den = this->den * f2.num;
	return *this;
}
	
//Enteros
Fraccion Fraccion::operator += (int x){
	this->num = this->num + this->den*x;
	this->den = this->den;
	return *this;
}

Fraccion Fraccion::operator -= (int x){
	this->num = this->num - this->den*x;
	this->den = this->den;
	return *this;
}

Fraccion Fraccion::operator *= (int x){
	this->num = this->num * x;
	this->den = this->den;
	return *this;
}

Fraccion Fraccion::operator /= (int x){
	this->num = this->num;
	this->den = this->den * x;
	return *this;
}

//Operador igual (=)
Fraccion & Fraccion::operator = (Fraccion &f2){
	if (&f2 == this) return *this;
	this->num = f2.num ;
	this->den = f2.den ;
	return *this;
}

Fraccion & Fraccion::operator = (int x){
	this->num = x ;
	this->den = 1 ;
	return *this;
}

int Fraccion::operator == (Fraccion &f2){
	this->simplifica();
	f2.simplifica();
	if (this->num == f2.num && this->den == f2.den)
	   return 1;
	else
	   return 0;
}
 
int Fraccion::operator == (int x){
	Fraccion aux;
	this->simplifica();
	aux=x;
	if (this->num == aux.num && this->den == aux.den)
	   return 1;
	else
	   return 0;
}

int operator == (int x, Fraccion &f2){
	Fraccion aux;
	f2.simplifica();
	aux=x;
	if (f2.num == aux.num && f2.den == aux.den)
	   return 1;
	else
	   return 0;
}

main(){
	int n, d, x;
	Fraccion frac1(2,3), frac2(5,6), fracResul;
	
	cout<<"\n Primera fraccion: ";
	frac1.imprimir();
	cout<<endl;
	cout<<" Segunda fraccion: ";
	frac2.imprimir();
	
	cout<<"\n\n Dar el numerador: ";
	cin>>n;
	cout<<" Dar el denominador: ";
	cin>>d;
	Fraccion frac3(n,d);
	cout<<" Tercera fraccion: ";
	frac3.imprimir();
	
	//Fracciones
	cout<<endl;
	cout<<endl;
	frac1.imprimir();
	cout<<" + ";
	frac2.imprimir();
	cout<<" = ";
	fracResul = frac1 + frac2;
	(fracResul.simplifica()).imprimir();
	//((frac1 + frac2).simplifica()).imprimir();
	
	cout<<endl;
	frac1.imprimir();
	cout<<" + ";
	frac3.imprimir();
	cout<<" = ";
	fracResul = frac1 + frac3;
	fracResul.simplifica().imprimir();
	
	cout<<endl;
	frac2.imprimir();
	cout<<" + ";
	frac3.imprimir();
	cout<<" = ";
	fracResul = frac2 + frac3;
	fracResul.simplifica().imprimir();
	//(frac2 + frac3).imprimir(); 
	//frac2.operator +(frac3)
	
	cout<<endl;
	cout<<endl;
	frac1.imprimir();
	cout<<" - ";
	frac2.imprimir();
	cout<<" = ";
	(frac1 - frac2).imprimir();
	
	cout<<endl;
	frac1.imprimir();
	cout<<" - ";
	frac3.imprimir();
	cout<<" = ";
	(frac1 - frac3).imprimir();
	
	cout<<endl;
	frac2.imprimir();
	cout<<" - ";
	frac3.imprimir();
	cout<<" = ";
	(frac2 - frac3).imprimir();
	
	cout<<endl;
	cout<<endl;
	frac1.imprimir();
	cout<<" * ";
	frac2.imprimir();
	cout<<" = ";
	(frac1 * frac2).imprimir();
	
	cout<<endl;
	frac1.imprimir();
	cout<<" * ";
	frac3.imprimir();
	cout<<" = ";
	(frac1 * frac3).imprimir();
	
	cout<<endl;
	frac2.imprimir();
	cout<<" * ";
	frac3.imprimir();
	cout<<" = ";
	(frac2 * frac3).imprimir();
	
	cout<<endl;
	cout<<endl;
	frac1.imprimir();
	cout<<" / ";
	frac2.imprimir();
	cout<<" = ";
	(frac1 / frac2).imprimir();
	
	cout<<endl;
	frac1.imprimir();
	cout<<" / ";
	frac3.imprimir();
	cout<<" = ";
	(frac1 / frac3).imprimir();
	
	cout<<endl;
	frac2.imprimir();
	cout<<" / ";
	frac3.imprimir();
	cout<<" = ";
	(frac2 / frac3).imprimir();
	
	//Fraccion y entero
	cout<<endl;
	cout<<endl;
	cout<<" Dar un numero entero: ";
	cin>>x;
	
	cout<<endl;
	frac1.imprimir();
	cout<<" + "<<x;
	cout<<" = ";
	(frac1 + x).imprimir();
	
	cout<<endl;
	frac2.imprimir();
	cout<<" + "<<x;
	cout<<" = ";
	(frac2 + x).imprimir();
	
	cout<<endl;
	frac3.imprimir();
	cout<<" + "<<x;
	cout<<" = ";
	(frac3 + x).imprimir();
	
	cout<<endl;
	cout<<endl;
	frac1.imprimir();
	cout<<" - "<< x;
	cout<<" = ";
	(frac1 - x).imprimir();
	
	cout<<endl;
	frac2.imprimir();
	cout<<" - "<< x;
	cout<<" = ";
	(frac2 - x).imprimir();
	
	cout<<endl;
	frac3.imprimir();
	cout<<" - "<< x;
	cout<<" = ";
	(frac3 - x).imprimir();
	
	cout<<endl;
	cout<<endl;
	frac1.imprimir();
	cout<<" * "<< x;
	cout<<" = ";
	(frac1 * x).imprimir();
	
	cout<<endl;
	frac2.imprimir();
	cout<<" * "<< x;
	cout<<" = ";
	(frac2 * x).imprimir();
	
	cout<<endl;
	frac3.imprimir();
	cout<<" * "<< x;
	cout<<" = ";
	(frac3 * x).imprimir();
	
	cout<<endl;
	cout<<endl;
	frac1.imprimir();
	cout<<" / "<< x;
	cout<<" = ";
	(frac1 / x).imprimir();
	
	cout<<endl;
	frac2.imprimir();
	cout<<" / "<< x;
	cout<<" = ";
	(frac2 / x).imprimir();
	
	cout<<endl;
	frac3.imprimir();
	cout<<" / "<< x;
	cout<<" = ";
	(frac3 / x).imprimir();
	
	//Entero y fraccion
	cout<<endl;
	cout<<"\n Entero y fraccion\n\n";
	cout<<" "<<x<<" +";
	frac1.imprimir();
	cout<<" = ";
	(x + frac1).imprimir();
	
	cout<<endl;
	cout<<" "<<x<<" +";
	frac2.imprimir();
	cout<<" = ";
	(x + frac2).imprimir();
	
	cout<<endl;
	cout<<" "<<x<<" +";
	frac3.imprimir();
	cout<<" = ";
	(x + frac3).imprimir();
	
	cout<<endl;
	cout<<endl;
	cout<<" "<<x<<" -";
	frac1.imprimir();
	cout<<" = ";
	(x - frac1).imprimir();
	
	cout<<endl;
	cout<<" "<<x<<" -";
	frac2.imprimir();
	cout<<" = ";
	(x - frac2).imprimir();
	
	cout<<endl;
	cout<<" "<<x<<" -";
	frac3.imprimir();
	cout<<" = ";
	(x - frac3).imprimir();
	
	cout<<endl;
	cout<<endl;
	cout<<" "<<x<<" *";
	frac1.imprimir();
	cout<<" = ";
	(x * frac1).imprimir();
	
	cout<<endl;
	cout<<" "<<x<<" *";
	frac2.imprimir();
	cout<<" = ";
	(x * frac2).imprimir();
	
	cout<<endl;
	cout<<" "<<x<<" *";
	frac3.imprimir();
	cout<<" = ";
	(x * frac3).imprimir();
	
	cout<<endl;
	cout<<endl;
	cout<<" "<<x<<" /";
	frac1.imprimir();
	cout<<" = ";
	(x / frac1).imprimir();
	
	cout<<endl;
	cout<<" "<<x<<" /";
	frac2.imprimir();
	cout<<" = ";
	(x / frac2).imprimir();
	
	cout<<endl;
	cout<<" "<<x<<" /";
	frac3.imprimir();
	cout<<" = ";
	(x / frac3).imprimir();
	
	cout<<endl;
	cout<<endl;
	frac1.imprimir();
	cout<<" +=";
	frac2.imprimir();
	cout<<" = ";
	(frac1 += frac2).imprimir();
	cout<<"\n Demostracion de que frac1 cambio su valor: \n";
	frac1.imprimir();  
	
	cout<<endl;
	frac1.imprimir();
	cout<<" += "<< x;
	cout<<" = ";
	(frac1 += x).imprimir();
	
	cout<<endl;
	cout<<endl;
	frac1.imprimir();
	cout<<" -=";
	frac2.imprimir();
	cout<<" = ";
	(frac1 -= frac2).imprimir();
	
	cout<<endl;
	frac1.imprimir();
	cout<<" -= "<< x;
	cout<<" = ";
	(frac1 -= x).imprimir();
	
	cout<<endl;
	cout<<endl;
	frac1.imprimir();
	cout<<" *=";
	frac2.imprimir();
	cout<<" = ";
	(frac1 *= frac2).imprimir();
	
	cout<<endl;
	frac1.imprimir();
	cout<<" *= "<< x;
	cout<<" = ";
	(frac1 *= x).imprimir();
	
	cout<<endl;
	cout<<endl;
	frac1.imprimir();
	cout<<" /=";
	frac2.imprimir();
	cout<<" = ";
	(frac1 /= frac2).imprimir();
	
	cout<<endl;
	frac1.imprimir();
	cout<<" /= "<< x;
	cout<<" = ";
	(frac1 /= x).imprimir();
	cout<<endl;
	cout<<" Fraccion simplificada: ";
	frac1.simplifica();
	frac1.imprimir();   
	
	
	cout<<"\n Asignación de un entero a una Fraccion: ";
	cout<<endl;
	fracResul = 8 ;
	fracResul.imprimir();
	
	cout<<endl;
	cout<<endl;
	cout<<"\n Frac1: ";
	frac1.imprimir();
	cout<<"\n fracResul antes de operator =: ";
	fracResul.imprimir();
	cout<<"\n fracResul despues de operator =: ";
	fracResul = frac1 ;
	fracResul.imprimir();
	
	if(frac1 == fracResul)
		cout<<"\n Son iguales.";
	else
		cout<<"\n Son diferentes.";
		
	cout<<"\n\n fracResul despues de operator =: ";
	fracResul = 3;
	fracResul.imprimir();
    if(fracResul == x)
		cout<<"\n Son iguales.";
	else
		cout<<"\n Son diferentes.";
		
	cout<<"\n\n fracResul despues de operator =: ";
	fracResul = 4;
	fracResul.imprimir();
    if(x == fracResul)
		cout<<"\n Son iguales.";
	else
		cout<<"\n Son diferentes.";
		
	cout<<"\n\n fracResul = frac1 = frac2";
	fracResul = frac1 = frac2;
	cout<<"\n fracResul =";
	fracResul.imprimir();
	cout<<"\n frac1 =";
	frac1.imprimir();
	cout<<"\n frac2 =";
	frac2.imprimir();
	
	cout<<"\n\n fracResul = frac1 = x";
	fracResul = frac1 = x;
	cout<<"\n fracResul =";
	fracResul.imprimir();
	cout<<"\n frac1 =";
	frac1.imprimir();
	cout<<"\n x = "<<x; 
}


