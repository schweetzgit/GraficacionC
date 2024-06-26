#include<iostream>
using namespace std;

class Complejo{
	float real;
	float img;
	
	public:
		Complejo(float, float);
		void imprimir();
		
		Complejo operator + (Complejo &);// complejo +compplejo
		Complejo operator + (float x);// complejo + flotante
		friend  Complejo operator + (float x, Complejo &); //flotante + complejo--> Es candidata a ser función amiga
		
		Complejo operator += (Complejo &);
		Complejo operator += (float x);
		
		Complejo operator - (Complejo &);
		Complejo operator - (float x);
		friend  Complejo operator - (float x, Complejo &);
		Complejo operator -= (Complejo &);
		Complejo operator -= (float x);
	
		Complejo operator * (Complejo &);
		Complejo operator * (float x);
		friend  Complejo operator * (float x, Complejo &);
		Complejo operator *= (Complejo &);
		Complejo operator *= (float x);
		
		Complejo operator / (Complejo &);
		Complejo operator / (float x);
		friend Complejo operator / (float x, Complejo &);
		Complejo operator /= (Complejo &);
		Complejo operator /= (float x);
		
		Complejo operator = (Complejo &);
		Complejo operator = (float);
};

Complejo::Complejo(float otro_real = 0, float otro_img = 0){
	this->real =otro_real;
	this->img = otro_img;
}

void Complejo::imprimir(){
	cout<<" (("<<real<<") + "<< img<<"i)";
}

/*Complejo Complejo::operator + (Complejo &z2){
	return Complejo (this->real + z2.real, this->img + z2.img);
}*/
Complejo Complejo::operator + (Complejo &z2){
	Complejo result;
	result.real = this->real + z2.real;
	result.img = this->img + z2.img;
	return result;
}

Complejo Complejo::operator + (float x){
	Complejo result;
	result.real = this->real + x;
	result.img = this->img;
	return result;
}

Complejo operator + (float x, Complejo &z2){
	Complejo result;
	result.real = z2.real + x;
	result.img = z2.img;
	return result;
}
/*Complejo Complejo::operator - (Complejo &z2){
	return Complejo (this->real - z2.real, this->img - z2.ima);
}*/
Complejo Complejo::operator - (Complejo &z2){
	Complejo result;
	result.real = this->real - z2.real;
	result.img = this->img - z2.img;
	return result;
}

Complejo Complejo::operator - (float x){
	Complejo result;
	result.real = this->real - x;
	result.img = this->img;
	return result;
}

Complejo operator - (float x, Complejo &z2){
	Complejo result;
	result.real = z2.real - x;
	result.img = z2.img;
	return result;
}
/*Complejo Complejo::operator * (Complejo &z2){
	//(a+bi)*(c+di) = (a*c-b*d) + (a*d+b*c)i
	return Complejo (this->real *z2.real - this->ima * z2.ima, this->real * z2.ima + this->ima*z2.real);
}*/

Complejo Complejo::operator * (Complejo &z2){
	Complejo result;
	result.real = this->real * z2.real - this->img * z2.img;
	result.img = this->real * z2.img + this->img *z2.real;
	return result;
}

Complejo Complejo::operator * (float x){
	Complejo result;
	result.real = this->real * x;
	result.img = this->img * x;
	return result;
}

Complejo operator * (float x, Complejo &z2){
	Complejo result;
	result.real = z2.real * x;
	result.img = z2.img * x;
	return result;
}

/*Complejo Complejo::operator / (Complejo &z2){
	// (a+bi)/(c+di) = (a+bi)/(c+di) * (c-di)/(c-di) = (a*c-b*d) + (a*d+b*c)i / c*c+d*d =
	// = (a*c-b*d)/c*c+d*d +(a*d+b*c)i/c*c+d*d 
	return Complejo ((this->real *z2.real + this->ima * z2.ima) / (z2.real*z2.real+z2.ima*z2.ima), (this->real * z2.ima - this->ima*z2.real)/(z2.real*z2.real+z2.ima*z2.ima));
}*/

Complejo Complejo::operator / (Complejo &z2){
	Complejo result;
	result.real = (this->real * z2.real + this->img * z2.img)/(z2.real * z2.real +z2.img * z2.img);
	result.img = this->img * z2.real - this->real * z2.img/ (z2.real * z2.real +z2.img * z2.img);
	return result;
}

Complejo Complejo::operator / (float x){
	Complejo result;
	result.real = this->real / x;
	result.img = this->img / x;
	return result;
}

Complejo operator / (float x, Complejo &z2){
	Complejo result;
	result.real = (x * z2.real) / ((z2.real*z2.real)+(z2.img*z2.img));
	result.img = (-(x * z2.img))/((z2.real*z2.real)+(z2.img*z2.img));
	return result;
}

//Otros operadores
Complejo Complejo::operator += (Complejo &z2){
	this->real = this->real + z2.real;
	this->img = this->img + z2.img;
	return *this;
}

Complejo Complejo::operator += (float x){
	this->real = this->real + x;
	this->img = this->img;
	return *this;
}

Complejo Complejo::operator -= (Complejo &z2){
	this->real = this->real - z2.real;
	this->img = this->img - z2.img;
	return *this;
}

Complejo Complejo::operator -= (float x){
	this->real = this->real - x;
	this->img = this->img;
	return *this;
}

Complejo Complejo::operator *= (Complejo &z2){
	this->real = (this->real * z2.real) - (this->img * z2.img);
	this->img = (this->real * z2.img) + (this->img * z2.real);
	return *this;
}

Complejo Complejo::operator *= (float x){
	this->real = this->real * x;
	this->img = this->img * x;
	return *this;
}

Complejo Complejo::operator /= (Complejo &z2){
	this->real = ((this->real *z2.real) + (this->img * z2.img)) / ((z2.real*z2.real)+(z2.img*z2.img));
	this->img = ((this->img*z2.real) - (this->real*z2.img))/((z2.real*z2.real)+(z2.img*z2.img));
	return *this;
}

Complejo Complejo::operator /= (float x){
	this->real = this->real / x;
	this->img = this->img / x;
	return *this;
}

Complejo Complejo::operator = (Complejo &z2){
	if (&z2 == this) return *this;
	this->real = z2.real;
	this->img = z2.img;
	return (*this);
	
}
Complejo Complejo::operator = (float x){
	this->real = x;
	this->img = 0;
	return (*this);
}

main(){
	Complejo z1(2,3), z2(5,6), zresul;
	float r, i;
	int x;
	
	cout<<"\n Dar el dato real: ";
	cin>>r;
	cout<<"\n Dar el dato imaginario: ";
	cin>>i;
	Complejo z3(r,i);
	cout<<"\n Numeros complejos instanciados:";
	cout<<"\n ";
	z1.imprimir();
	cout<<"\n ";
	z2.imprimir();
	cout<<"\n ";
	z3.imprimir();
	
	cout<<"\n\n Asinacion de complejos";
	zresul = z1;
	cout<<"\n zresul = z1\n";
	zresul.imprimir();
	
	cout<<"\n\n Asinacion de un real a un complejo";
	zresul= 9.5;
	cout<<"\n zresul = 9.5\n";
	zresul.imprimir();
	
	//Suma de complejos
	cout<<endl;
	cout<<endl;
	z1.imprimir();
	cout<<" + ";
	z2.imprimir();
	cout<<" = ";
	(z1 + z2).imprimir();  //z1.operator + (z2) 
						   //z1 + real -> z1.operator + (real)
						   //real + z2 -> friend operator (real, z2)
	
	cout<<endl;
	z1.imprimir();
	cout<<" + ";
	z3.imprimir();
	cout<<" = ";
	(z1 + z3).imprimir();
	
	cout<<endl;
	z2.imprimir();
	cout<<" + ";
	z3.imprimir();
	cout<<" = ";
	(z2 + z3).imprimir();
	
	//Resta de complejos
	cout<<endl;
	cout<<endl;
	z1.imprimir();
	cout<<" - ";
	z2.imprimir();
	cout<<" = ";
	(z1 - z2).imprimir();
	
	cout<<endl;
	z1.imprimir();
	cout<<" - ";
	z3.imprimir();
	cout<<" = ";
	(z1 - z3).imprimir();
	
	cout<<endl;
	z2.imprimir();
	cout<<" - ";
	z3.imprimir();
	cout<<" = ";
	(z2 - z3).imprimir();
	
	//Multiplicacion de complejos
	cout<<endl;
	cout<<endl;
	z1.imprimir();
	cout<<" * ";
	z2.imprimir();
	cout<<" = ";
	(z1 * z2).imprimir();
	
	cout<<endl;
	z1.imprimir();
	cout<<" * ";
	z3.imprimir();
	cout<<" = ";
	(z1 * z3).imprimir();
	
	cout<<endl;
	z2.imprimir();
	cout<<" * ";
	z3.imprimir();
	cout<<" = ";
	(z2 * z3).imprimir();
	
	//División de complejos
	cout<<endl;
	cout<<endl;
	z1.imprimir();
	cout<<" / ";
	z2.imprimir();
	cout<<" = ";
	(z1 / z2).imprimir();
	
	cout<<endl;
	z1.imprimir();
	cout<<" / ";
	z3.imprimir();
	cout<<" = ";
	(z1 / z3).imprimir();
	
	cout<<endl;
	z2.imprimir();
	cout<<" / ";
	z3.imprimir();
	cout<<" = ";
	(z2 / z3).imprimir();
	
	cout<<endl;
	cout<<endl;
	
	cout<<"\n Dar un numero entero: ";
	cin>> x;
	
	//Suma de un complejo con un entero
	cout<<endl;
	z1.imprimir();
	cout<<" + ("<<x<<")";
	cout<<" = ";
	(z1 + x).imprimir();
	
	cout<<endl;
	cout<<"  ("<<x<<")";
	cout<<" + ";
	z1.imprimir();
	cout<<" = ";
	(x + z1).imprimir();
	
	cout<<endl;
	z2.imprimir();
	cout<<" + ("<<x<<")";
	cout<<" = ";
	(z2 + x).imprimir();
	
	cout<<"  ("<<x<<")";
	cout<<" + ";
	z2.imprimir();
	cout<<" = ";
	(x + z2).imprimir();
	
	cout<<endl;
	z3.imprimir();
	cout<<" + ("<<x<<")";
	cout<<" = ";
	(z3 + x).imprimir();
	
	cout<<"  ("<<x<<")";
	cout<<" + ";
	z3.imprimir();
	cout<<" = ";
	(x + z3).imprimir();
	
	//Resta de un complejo con un entero
	cout<<endl;
	cout<<endl;
	z1.imprimir();
	cout<<" - ("<<x<<")";
	cout<<" = ";
	(z1 - x).imprimir();
	
	cout<<endl;
	z2.imprimir();
	cout<<" - ("<<x<<")";
	cout<<" = ";
	(z2 - x).imprimir();
	
	cout<<endl;
	z3.imprimir();
	cout<<" - ("<<x<<")";
	cout<<" = ";
	(z3 - x).imprimir();
	
	//Multiplicación de un complejo con un entero
	cout<<endl;
	cout<<endl;
	z1.imprimir();
	cout<<" * ("<<x<<")";
	cout<<" = ";
	(z1 * x).imprimir();
	
	cout<<endl;
	z2.imprimir();
	cout<<" * ("<<x<<")";
	cout<<" = ";
	(z2 * x).imprimir();
	
	cout<<endl;
	z3.imprimir();
	cout<<" * ("<<x<<")";
	cout<<" = ";
	(z3 * x).imprimir();
	
	//División de un complejo con un entero
	cout<<endl;
	cout<<endl;
	z1.imprimir();
	cout<<" / ("<<x<<")";
	cout<<" = ";
	(z1 / x).imprimir();
	
	cout<<endl;
	z2.imprimir();
	cout<<" / ("<<x<<")";
	cout<<" = ";
	(z2 / x).imprimir();
	
	cout<<endl;
	z3.imprimir();
	cout<<" / ("<<x<<")";
	cout<<" = ";
	(z3 / x).imprimir();
	
	//Division de un entero con un complejo
	cout<<endl;
	cout<<endl;
	cout<<"("<<x<<") / ";
	z1.imprimir();
	cout<<" = ";
	(x / z1).imprimir();
	
	cout<<endl; 
	cout<<"("<<x<<") / ";
	z2.imprimir();
	cout<<" = ";
	(x / z2).imprimir();
	
	cout<<endl;
	cout<<"("<<x<<") / ";
	z3.imprimir();
	cout<<" = ";
	(x / z3).imprimir();
	
		// +=
	cout<<endl;
	cout<<endl;
	z1.imprimir();
	cout<<" += ";
	z2.imprimir();
	cout<<" = ";
	(z1 += z2).imprimir();
	
	cout<<endl;
	z1.imprimir();
	cout<<" += ("<< x<<")";
	cout<<" = ";
	(z1 += x).imprimir();
	
		// -=
	cout<<endl;
	cout<<endl;
	z1.imprimir();
	cout<<" -= ";
	z2.imprimir();
	cout<<" = ";
	(z1 -= z2).imprimir();
	
	cout<<endl;
	z1.imprimir();
	cout<<" -= ("<< x<<")";
	cout<<" = ";
	(z1 -= x).imprimir();
	
		// *=
	cout<<endl;
	cout<<endl;
	z1.imprimir();
	cout<<" *= ";
	z2.imprimir();
	cout<<" = ";
	(z1 *= z2).imprimir();
	
	cout<<endl;
	z1.imprimir();
	cout<<" *= ("<< x<<")";
	cout<<" = ";
	(z1 *= x).imprimir();
	
		// /=
	cout<<endl;
	cout<<endl;
	z1.imprimir();
	cout<<" /= ";
	z2.imprimir();
	cout<<" = ";
	(z1 /= z2).imprimir();
	
	cout<<endl;
	z1.imprimir();
	cout<<" /= ("<< x<<")";
	cout<<" = ";
	(z1 /= x).imprimir();
}
