#include<iostream>
#include<string.h>
using namespace std;

class Persona{
	private:
		int idPersona;
		char nombre[50];
		char apellidos[80];
		char sexo;
		char email[100];
	public:
		Persona();
		void leeDatos();
		void imprimeDatos();
		void getIdentificador();
		void getNombre();
		void getApellidos();
		void getSexo();
		void getEmail();
};
//Se establece la herencia (public/private)
class Estudiante:public Persona{ //Si no lleva nada es privado
	private:
		char universidad[60];
		char carrera[60];
		float promedio;
	public:
		Estudiante();
		void leeEstudiante();
		void imprimeEstudiante();
};

class Trabajador:private Persona{
	private:
		char lugarTrabajo[40];
		char puesto[40];
		float sueldo;
	public:
		Trabajador();
		void leeTrabajador();
		void imprimeTrabajador();
		void verLugarTrabajo();
		void verPuesto();
		void verSueldo();
		void verIdTrabajador();
		void verNombreTrabajador();
		void verApellidoTrabajo();
		void verSexoTrabajo();
		void verEmailTrabajo();
};

Persona::Persona(){
	idPersona = 0;
	strcpy(nombre," ");//strcpy--copiar la cadena a la variable (primera cadena)
	strcpy(apellidos," ");
	sexo = 'N';
	strcpy(email," ");
}
/*El constructor de la clase derivada o subclase  debe invocar
al constructor de la superclase o clasebase*/
Estudiante::Estudiante():Persona(){
	strcpy(universidad," ");
	strcpy(carrera," ");
	promedio = 0.0;
}
Trabajador::Trabajador():Persona(){
	strcpy(lugarTrabajo," ");
	strcpy(puesto," ");
	promedio = 0.0;
}

void Persona::leeDatos(){
	cout<<"\n\n Datos de la persona.";
	cout<<"\n Identificador: ";
	cin>>this->idPersona;
	cout<<" Nombre(s): ";
	fflush(stdin);
	gets(this->nombre);
	cout<<" Apellidos: ";
	fflush(stdin);
	gets(this->apellidos);
	cout<<" Sexo: ";
	cin>>this->sexo;
	cout<<" E-mail: ";
	fflush(stdin);
	gets(this->email);
}
void Estudiante::leeEstudiante(){
	leeDatos();
	cout<<"\n Datos del estudiante.";
	cout<<"\n Universidad: ";
	fflush(stdin);
	gets(this->universidad);
	cout<<" Carrera: ";
	gets(this->carrera);
	cout<<" Promedio: ";
	cin>>promedio;
}
void Trabajador::leeTrabajador(){
	leeDatos();
	cout<<"\n Datos del trabajador.";
	cout<<"\n Lugar de trabajo: ";
	fflush(stdin);
	gets(this->lugarTrabajo);
	cout<<" Puesto: ";
	gets(this->puesto);
	cout<<" Sueldo: ";
	cin>>sueldo;
}

void Persona::imprimeDatos(){
	cout<<"\n Identificador: "<<this->idPersona;
	cout<<"\n Nombre(s): "<<this->nombre;
	cout<<"\n Apellidos: "<<this->apellidos;
	cout<<"\n Sexo: "<<this->sexo;
	cout<<"\n E-mail: "<<this->email;
}
void Estudiante::imprimeEstudiante(){
	imprimeDatos();
	cout<<"\n Universidad: "<<this->universidad;
	cout<<"\n Carrera: "<<this->carrera;
	cout<<"\n Promedio: "<<this->promedio;
}
void Trabajador::imprimeTrabajador(){
	imprimeDatos();
	cout<<"\n Lugar de trabajo: "<<this->lugarTrabajo;
	cout<<"\n Puesto: "<<this->puesto;
	cout<<"\n Sueldo: "<<this->sueldo;
}

void Persona::getNombre(){
	cout<<this->nombre;
}
void Persona::getApellidos(){
	cout<<this->apellidos;
}
void Persona::getSexo(){
	cout<<this->sexo;
}
void Persona::getEmail(){
	cout<<this->email;
}
void Persona::getIdentificador(){
	cout<<this->idPersona;
}

void Trabajador::verLugarTrabajo(){
    cout<<"\n Lugar de trabajo: "<<this->lugarTrabajo;
}

void Trabajador::verPuesto(){
    cout<<"\n Puesto: "<<this->puesto;
}

void Trabajador::verSueldo(){
    cout<<"\n Sueldo: "<<this->sueldo;
}

void Trabajador::verIdTrabajador(){
	getIdentificador();
}
void Trabajador::verNombreTrabajador(){
    getNombre();
}

void Trabajador::verApellidoTrabajo(){
	getApellidos();
}
void Trabajador::verSexoTrabajo(){
	getSexo();
}
void Trabajador::verEmailTrabajo(){
	getEmail();
}

int main(){
	Persona p1, p2;
	/*p1.leeDatos();
	p1.imprimeDatos();
	p2.leeDatos();
	p2.imprimeDatos();*/
	
	Estudiante p3;
	p3.leeEstudiante();
	p3.imprimeEstudiante();
	cout<<"\n";
	//Invocando la función que se hereda de manera publica
	p3.imprimeDatos();//Si fuera class Estudiante:private Persona, NO se podria
	
	Trabajador p4;
	p4.leeTrabajador();
	p4.imprimeTrabajador();
	
	cout<<"\n\n Imprime nombre del trabajador\n";
	p4.ver_nombreTrabajador();
	/*Per4.imprimirDatos(); No se puede ejecutar porque la clase trabajador hereda 
	en forma privada y los clientes de la clase trabajador no tiene acceso a la 
	herencia proporcionada por la clase Persona*/
}


