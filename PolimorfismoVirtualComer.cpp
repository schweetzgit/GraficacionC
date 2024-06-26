#include<iostream>
using namespace std;
class SerVivo{
	public:
		virtual void alimentar(){
			cout<<"\n Los seres vivos comen para sobrevivir.\n";
		}
		void comer(){
			alimentar();
		}
};
class Humano:public SerVivo{
	public:
		virtual void alimentar(){
			cout<<"\n Se alimenta de frutas, carne";
			cout<<"\n Utiliza utencilios para comer.\n";
		}
};
class Ave:public SerVivo{
	public:
		virtual void alimentar(){
			cout<<"\n Se alimenta de semillas y frutos";
			cout<<"\n Utiliza el pico para comer.\n";
		}
};
class Felino:public SerVivo{
	public:
		virtual void alimentar(){
			cout<<"\n Se alimenta de carne y presas que casa";
			cout<<"\n Utiliza sus colmillos para comer.\n";
		}
};

main(){
	Humano juan; 
	Felino leon;
	Ave pelicano;
	cout<<"\n Juan ejecuta a la funcion comer: ";
	juan.comer();
	cout<<"\n Leon ejecuta a la funcion comer: ";
	leon.comer();
	cout<<"\n Pelicano ejecuta a la funcion comer: ";
	pelicano.comer();
}

