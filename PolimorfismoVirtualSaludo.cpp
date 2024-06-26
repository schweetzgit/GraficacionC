//Polimorfismo utilizando funciones virtuales-Saludos en diferentes idiomas
#include<iostream>
using namespace std;

class Nacionalidad{
	public:
		 virtual void saludo(){
		 	cout<<"\n Entre las personas de diferentes nacionalidades se saludan asi\n";
		 }
		 void SaludaAsi(){ //Funcion polimorfica
		 	saludo();
		 }
};
class NacionalidadMexicana:public Nacionalidad{
	void saludo(){
	 	cout<<"\n Los mexiacanos saludan: Hola, que tal";
	}
};
class NacionalidadItaliana:public Nacionalidad{
	void saludo(){
	 	cout<<"\n Los italianos saludan: Buon giorno amici";
	}
};
class NacionalidadEstadoUnidense:public Nacionalidad{
	void saludo(){
	 	cout<<"\n Los estadounidenses saludan: Hello world";
	}
};
main(){
	Nacionalidad persona1;
	NacionalidadMexicana personaMex;
	NacionalidadItaliana personaIta;
	NacionalidadEstadoUnidense personaEU;
	persona1.SaludaAsi();	
	personaMex.SaludaAsi();
	personaIta.SaludaAsi();
	personaEU.SaludaAsi();
}
