#include<iostream>
#include<string.h>
using namespace std;
class Persona{
	public:
		~Persona(); //destructor
		Persona();
		void leerPersona();
		void imprimePersona();
		void guardarPersona();
		void listarPersonasAlmacenadas();
		void buscarPersona();
		void borrarRegistroPersona();
		void modificarRegistroPersona();
		void leeRutaNombre();
	private:
		int idPersona;
		char nombre[60];
		char apellido1[60];
		char apellido2[60];
		char direccion[80];
		int edad;
		float talla;
		char nombreArchivo[120];
};
void Persona::leeRutaNombre(){
	cout<<"\n Ingresar la ruta y nombre del archivo: ";
	// Al dar la ruta es: c:/.../NombreArchivo.extension
	fflush(stdin);
	gets(nombreArchivo);
}
Persona::~Persona(){
	//Sin cuerpo porque no estamos tomando memoria del monticulo
}
// Constructor
Persona::Persona(){ // inicializar las cosas, sin valor
	idPersona = 0;
	strcpy(nombre,"Sin nombre por el momento");
	strcpy(apellido1,"Sin primer apellido por el momento");
	strcpy(apellido2,"Sin segundo apellido por el momento");
	strcpy(direccion,"Sin direccion por el momento");
	edad = 0;
	talla = 0.0;
}

void Persona::leerPersona(){
	cout<<"\n Lectura de un registro Persona\n";
	cout<<"\n Identificador: ";
	cin>>idPersona;
	cout<<" Nombre: ";
	fflush(stdin);
	gets(nombre);
	cout<<" Primer apellido: ";
	fflush(stdin);
	gets(apellido1);
	cout<<" Segundo apellido: ";
	fflush(stdin);
	gets(apellido2);
	cout<<" Direccion: ";
	fflush(stdin);
	gets(direccion);
	cout<<" Edad: ";
	cin>>edad;
	cout<<" Talla: ";
	cin>>talla;
}
void Persona::imprimePersona(){
	cout<<"\n\n Identificador: "<<idPersona;
	cout<<"\n Nombre: "<<nombre;
	cout<<" Primer apellido: "<<apellido1;
	cout<<" Segundo apellido: "<<apellido2;
	cout<<" Direccion: "<<direccion;
	cout<<" Edad: "<<edad;
	cout<<"\n Talla: "<<talla;
}
void Persona::guardarPersona(){
	FILE *archivo;
	archivo = fopen(nombreArchivo,"a");
	// r=solo lectura, w=borrar, leer, a=abrir, leer y guardar
	if(archivo == NULL){
		cout<<"\n Error en apertura de archivo";
		cin.get();
		return;
	}
	fprintf(archivo,"\n %d", idPersona);
	fprintf(archivo,"\n %s", nombre);
	fprintf(archivo,"\n %s", apellido1);
	fprintf(archivo,"\n %s", apellido2);
	fprintf(archivo,"\n %s", direccion);
	fprintf(archivo,"\n %d", edad);
	fprintf(archivo,"\n %f", talla);
	cout<<"\n Registro almacenado con exito.\n";
	fclose(archivo);
}

void Persona::listarPersonasAlmacenadas(){
	FILE *archivo;
	Persona aux;
	archivo = fopen(nombreArchivo,"r");
	if(archivo == NULL){
		cout<<"\n Error en apertura de archivo";
		cin.get();
		return;
	}
	while(!feof(archivo)){ // Mientras no acabe el archivo
		fscanf(archivo,"%d\n",&aux.idPersona);
		fflush(stdin);
		fgets(aux.nombre,60,archivo);
		fgets(aux.apellido1,60,archivo);
		fgets(aux.apellido2,60,archivo);
		fgets(aux.direccion,80,archivo);
		fscanf(archivo,"%d\n",&aux.edad);
		fscanf(archivo,"%f\n",&aux.talla);
		aux.imprimePersona();
	}
	fclose(archivo);
}

void Persona::buscarPersona(){
	FILE *archivo;
	int idBuscado;
	Persona aux;
	archivo = fopen(nombreArchivo,"r");
	if(archivo == NULL){
		cout<<"\n Error en apertura de archivo. \nPulse tecla para continuar";
		cin.get();
		return;
	}
	
	cout<<"\n Ingresar el identificador de la persona a buscar: ";
	cin>>idBuscado;
	
	while(!feof(archivo)){
		fscanf(archivo,"%d\n",&aux.idPersona);
		fflush(stdin);
		fgets(aux.nombre,60,archivo);
		fgets(aux.apellido1,60,archivo);
		fgets(aux.apellido2,60,archivo);
		fgets(aux.direccion,80,archivo);
		fscanf(archivo,"%d\n",&aux.edad);
		fscanf(archivo,"%f\n",&aux.talla);
		
		if(idBuscado == aux.idPersona){
			cout<<"\n El registro con identificador "<<aux.idPersona<<" se ha encontrado.";
			aux.imprimePersona();
			cin.get();
			fclose(archivo);
			return;
		}
	}
	cout<<"\n El registro no se encuentra almacenado.";	
	cin.get();
	fclose(archivo);
	return;
}

void Persona::borrarRegistroPersona(){
	FILE *original;
	FILE *auxiliar;
	Persona aux;
	int idBorrar;
	int centinela = 0;
		
	cout<<"\n Borrado del registro persona por identificador.\n";
	original = fopen(nombreArchivo,"r");
	if(original == NULL){
		cout<<"\n Error en apertura de archivo. \nPulse tecla para continuar";
		cin.get();
		return;
	}
		
	auxiliar = fopen("c:/borrame/auxiliarPersona.txt","w");
	if(auxiliar == NULL){
		cout<<"\n Error en apertura de archivo. \nPulse tecla para continuar";
		cin.get();
		fclose(original);
		return;
	}
		
	cout<<" Ingresar el identificador del registro persona que desea borrar: ";
	cin>>idBorrar;
		
	while(!feof(original)){
		fscanf(original,"%d\n",&aux.idPersona);
		fflush(stdin);
		fgets(aux.nombre,60,original);
		fgets(aux.apellido1,60,original);
		fgets(aux.apellido2,60,original);
		fgets(aux.direccion,80,original);
		fscanf(original,"%d\n",&aux.edad);
		fscanf(original,"%f\n",&aux.talla);
			
		if(idBorrar == aux.idPersona){
			centinela = 1;
			cout<<"\n El registro con identificador "<<aux.idPersona<<" fue eliminado con exito.";
		}
		else{
			fprintf(auxiliar,"%d\n",aux.idPersona);
			fprintf(auxiliar,"%s",aux.nombre);
			fprintf(auxiliar,"%s",aux.apellido1);
			fprintf(auxiliar,"%s",aux.apellido2);
			fprintf(auxiliar,"%s",aux.direccion);
			fprintf(auxiliar,"%d\n",aux.edad);
			fprintf(auxiliar,"%f\n",aux.talla);
		}
	}
	
	fclose(original);
	fclose(auxiliar);

	if(centinela == 0){
		cout<<"\n El registro con identificador "<<idBorrar<<" no se encuentra en la base de datos.";
		remove("c:/borrame/auxiliarPersona.txt");
		return;
	}
	//cout<<"\n Revisar los archivos";
	cin.get();
	//elimina el archivo origen
    remove(nombreArchivo);
	
	//Renombrando el archivo auxiliar por el nombre del archivo Origen 
	rename("c:/borrame/auxiliarPersona.txt", nombreArchivo);
	cin.get();
}
void Persona::modificarRegistroPersona(){
	FILE *original;
	FILE *auxiliar;
	Persona aux;
	int idModificar;
	int centinela = 0;
	char respModifica;
	
	cout<<"\n Modificar registros persona por identificador.";
	       
	original = fopen(nombreArchivo,"r");
	if(original == NULL){
		cout<<"\n Error en apertura de archivo. \nPulse tecla para continuar";
		cin.get();
		return;
	}
	
	auxiliar = fopen("c:/borrame/auxiliarPersona.txt","w");
	if(auxiliar == NULL){
		cout<<"\n Error en apertura de archivo. \nPulse tecla para continuar";
		cin.get();
		fclose(original);
		return;
	}
	
	printf("\n\n Ingresar el identificador del registro Persona que desea modificar: ");
	cin>>idModificar;
	
	while(!feof(original)){
		fscanf(original,"%d\n",&aux.idPersona);
		fflush(stdin);
		fgets(aux.nombre,60, original);
		fgets(aux.apellido1,60, original);
		fgets(aux.apellido2,60, original);
		fgets(aux.direccion,80, original);
		fscanf(original ,"%d\n",&aux.edad);
		fscanf(original,"%f\n",&aux.talla);
			
		if(idModificar == aux.idPersona){
				centinela = 1;
				cout<<" Desea modificar el identificador [s->Si]: ";
				cin>>respModifica;
				if(tolower(respModifica) == 's'){
					cout<<"\n Ingresar el nuevo identificador: ";
					cin>>aux.idPersona;
				}
				cout<<" El registro con identificador "<<aux.idPersona<<" fue modificado con exito.";
		
				fprintf(auxiliar,"%d\n",aux.idPersona);
				fprintf(auxiliar,"%s",aux.nombre);
				fprintf(auxiliar,"%s",aux.apellido1);
				fprintf(auxiliar,"%s",aux.apellido2);
				fprintf(auxiliar,"%s",aux.direccion);
				fprintf(auxiliar,"%d\n",aux.edad);
				fprintf(auxiliar,"%f\n",aux.talla);
		}
		else{
			fprintf(auxiliar,"%d\n",aux.idPersona);
			fprintf(auxiliar,"%s",aux.nombre);
			fprintf(auxiliar,"%s",aux.apellido1);
			fprintf(auxiliar,"%s",aux.apellido2);
			fprintf(auxiliar,"%s",aux.direccion);
			fprintf(auxiliar,"%d\n",aux.edad);
			fprintf(auxiliar,"%f\n",aux.talla);
		}
	}
	fclose(original);
	fclose(auxiliar);
	
	if(centinela == 0){
		cout<<"\n El registro con identificador "<<idModificar<<" no se encuentra en la base de datos.";
		remove("c:/borrame/auxiliarPersona.txt");
		return;
	}
	//cout<<"\n Revisar los Archivos";
	cin.get();
	//elimina el archivo origen
    remove(nombreArchivo);

	//Renombrando el archivo auxiliar por el nombre del archivo Origen 
	rename("c:/borrame/auxiliarPersona.txt", nombreArchivo);
	cin.get();
}

main(){
	Persona x1;
	int opc;
	x1.leeRutaNombre();
	do{
		cout<<"\n\n 1. Leer un registro";
		cout<<"\n 2. Imprimir un registro";
		cout<<"\n 3. Guardar registro";
		cout<<"\n 4. Listar personas almacenadas";
		cout<<"\n 5. Buscar persona";
		cout<<"\n 6. Eliminar registro";
		cout<<"\n 7. Modificar un registro";
		cout<<"\n 8. Salir";
		cout<<"\n Elija una opcion: ";
		cin>>opc;
		switch(opc){
			case 1:
				x1.leerPersona();
				break;
			case 2:
				x1.imprimePersona();
				break;
			case 3:
				x1.guardarPersona();
				break;
			case 4:
				x1.listarPersonasAlmacenadas();
				break;
			case 5:
				x1.buscarPersona();
				break;
			case 6:
				x1.borrarRegistroPersona();
				break;
			case 7: 
				x1.modificarRegistroPersona();
			    break;   
			case 8: 
				cout<<"\n Hasta la vista";
				cin.get();
				break;
			default: 
				cout<<"\n Opcion incorrecta. Vuelva a elegir";			
				cin.get();
		}
	}while(opc!=8);
}

