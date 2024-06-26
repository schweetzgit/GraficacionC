#include<iostream>
#include<math.h>
using namespace std;

class Elipse{
	private:
		float a, b, pi;
	public :
	    Elipse(float otra_a=5,float otra_b=3,float otra_pi=3.1416){
			a = otra_a;
			b = otra_b;
			pi = otra_pi;
	}
	void calculaArea(){
		cout<<"\n El area del elipse es: "<< (a*b)*pi;
	}
	void calculaPerimetro(){
		cout<<"\n El perimetro del elipse es: "<< (2*pi)*((sqrt(pow(a,2)+pow(b,2)))/(2));
	}
	float get_a(){
		return a;
	}
	float get_b(){
		return b;
	}
	float get_pi(){
		return pi;
	}

};
main(){
	Elipse objE1;
	float mi_pi = 3.141592, mi_a, mi_b;
	cout<<"\n Elipse 1 \n";
	cout<<"\n valor de a: "<<objE1.get_a();
	cout<<"\n valor de b: "<<objE1.get_b();
	cout<<"\n valor de pi: "<<objE1.get_pi();
	objE1.calculaArea();
	objE1.calculaPerimetro();
	
	cout<<"\n\n Elipse 2 \n";
	cout<<"\n Dar valor de a: ";
	cin>>mi_a;
	cout<<" Dar valor de b: ";
	cin>>mi_b;
	Elipse objE2(mi_a,mi_b,mi_pi);
	cout<<"\n valor de a : "<<objE2.get_a();
	cout<<"\n valor de b: "<<objE2.get_b();
	cout<<"\n valor de pi: "<<objE2.get_pi();
	objE2.calculaArea();
	objE2.calculaPerimetro();
}
