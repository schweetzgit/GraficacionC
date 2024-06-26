#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <dos.h>
#include <graphics.h>
#include <windows.h>
#include <time.h>
using namespace std;

void switch1();
void menu2();
void gotoxy (int x, int y);

/**** Clase Usuario ****/
class Usuario{
	private:
		char login1[10];
		char login2[10];
		char login3[10];
		char login4[10];
		char password1[10];
		char password2[10];
		char password3[10];
		char password4[10];
		char nombre[150];
		char comentarios[300];
		char nombreArchivo[120];
		int edad;
	public: 
		Usuario();
		void validarAcceso();
		void leeRutaNombre();
		void leeUsuario();
		void imprimeUsuario();
		void guardarUsuario();
		void listarUsuarios();
		void getNombreArchivo();
		virtual void nota(){
			cout<<"\n Existen diversos precios y caracteristicas para diferentes usuarios.";
		}
		void precio(){
			nota();
		}
};
void Usuario::leeRutaNombre(){
	cout<<"\n Ingresar la ruta y nombre del archivo: ";
	fflush(stdin);
	gets(nombreArchivo);
}

void Usuario::getNombreArchivo(){
	cout<<"\n\n Revisar "<<nombreArchivo<<" para ver comentarios\n";
}
Usuario::Usuario(){ 
	strcpy(login1,"");
	strcpy(login2,"");
	strcpy(login3,"");
	strcpy(login4,"");
	strcpy(password1,"");
	strcpy(password2,"");
	strcpy(password3,"");
	strcpy(password4,"");
	strcpy(nombre,"Sin nombre por el momento");
	strcpy(comentarios,"Sin comentarios por el momento");
	edad = 0;
}
void Usuario::validarAcceso(){
	char log[10], pass[10];
	strcpy(login1,"geslava");
	strcpy(login2,"acceso20");
	strcpy(login3,"usuario");
	strcpy(login4,"login");
	strcpy(password1,"mac1301");
	strcpy(password2,"proy1301");
	strcpy(password3,"acceso&");
	strcpy(password4,"password");
	do{
		cout<<"\n *** Bienvenido a Acuarium ***";
		cout<<"\n\n Ingrese claves de acceso\n";	
		cout<<"\n Usuario: ";
		fflush(stdin);
		gets(log);
		fflush(stdin);
		cout<<" Password: ";
		fflush(stdin);
		gets(pass);
		fflush(stdin);
		if((strcmp(log,login1) != 0 || strcmp(pass,password1) != 0) && (strcmp(log,login2) != 0 || strcmp(pass,password2) != 0) && (strcmp(log,login3) != 0 || strcmp(pass,password3) != 0) && (strcmp(log,login4) != 0 || strcmp(pass,password4) != 0)){
			cout<<"\n Login y/o contrasena incorrecta.\n Pulse tecla para continuar.";
			cin.get();
			system("cls");
		}
	}while((strcmp(log,login1) != 0 || strcmp(pass,password1) != 0) && (strcmp(log,login2) != 0 || strcmp(pass,password2) != 0) && (strcmp(log,login3) != 0 || strcmp(pass,password3) != 0) && (strcmp(log,login4) != 0 || strcmp(pass,password4) != 0));
	cout<<"\n --> Acceso autorizado\n Pulse tecla para continuar --> ";
	cin.get();
}
void Usuario::leeUsuario(){
	cout<<"\n Edad: ";
	cin>>edad;
	cout<<" Nombre: ";
	fflush(stdin);
	gets(nombre);
	cout<<" Comentarios: ";
	fflush(stdin);
	gets(comentarios);
}
void Usuario::imprimeUsuario(){
	cout<<"\n Edad: "<<edad;
	cout<<"\n Nombre: "<<nombre;
	cout<<" Comentarios: "<<comentarios;
}
void Usuario::guardarUsuario(){
	FILE *archivo;
	archivo = fopen(nombreArchivo,"a");
	if(archivo == NULL){
		cout<<"\n Error en apertura de archivo.\n";
		cin.get();
		return;
	}
	fprintf(archivo,"\n %d", edad);
	fprintf(archivo,"\n %s", nombre);
	fprintf(archivo,"\n %s", comentarios);
	fclose(archivo);
	cout<<"\n Gracias por su aportacion.";
	cin.get();
}
void Usuario::listarUsuarios(){
	FILE *archivo;
	Usuario aux;
	archivo = fopen(nombreArchivo,"r");
	if(archivo == NULL){
		cout<<"\n No hay comentarios almacenados\n Pulse tecla para continuar.";
		cin.get();
		cin.get();
		return;
	}
	cout<<"\n *** Empleado ***";
	cout<<"\n\n Visitantes de Acuarium\n";
	while(!feof(archivo)){ 
		fscanf(archivo,"%d\n",&aux.edad);
		fflush(stdin);
		fgets(aux.nombre,150,archivo);
		fgets(aux.comentarios,300,archivo);
		aux.imprimeUsuario();
	}
	cout<<endl;
	cout<<endl;
	cout<<"\n Pulse tecla para continuar.";
	cin.get();
	fclose(archivo);
}
/**** Clases hijas de Usuarios ****/
class Publico:public Usuario{
	void nota(){
		srand(time(NULL));
		int  cliente = 1 + rand() % 10000;
		cout<<"\n Publico general.";
		printf("\n Visitante # %d\n",cliente);
		printf("\n Precio general: $250");
		cout<<"\n No hay descuento.";
		printf("\n\n A pagar: $250\n\n");
	}
};
class Estudiante:public Usuario{
	void nota(){	
		srand(time(NULL));
		int desc = 1 + rand() % 100, cliente = 1 + rand() % 10000;
		cout<<"\n Estudiantes.";
		printf("\n Visitante # %d\n",cliente);
		printf("\n Precio general: $250");
		printf("\n Descuento aleatorio: %d%c",desc,37);
		printf("\n\n A pagar: $%d\n\n",250 - ((desc*250)/100));
	}
};
class AdultoMayor:public Usuario{
	void nota(){
		srand(time(NULL));
		int  cliente = 1 + rand() % 10000;
		cout<<"\n Adultos mayores.";
		printf("\n Visitante # %d\n",cliente);
		printf("\n Precio general: $250");
		printf("\n Descuento: 20%c",37);
		printf("\n\n A pagar: $%d\n\n",250 - ((20*250)/100));
	}
};
class Empleados:public Usuario{
	private:
		char login1[10];
		char login2[10];
		char login3[10];
		char login4[10];
		char password1[10];
		char password2[10];
		char password3[10];
		char password4[10];
	public:
		void nota(){
			srand(time(NULL));
			int desc = 1 + rand() % 100;
			cout<<"\n Empleados.\n";
			printf("\n Precio general: $250");
			printf("\n Descuento con credencial: %d%c",desc,37);
			printf("\n A pagar: $%d\n\n",250 - ((desc*250)/100));
			printf("\n Descuento a familiares: 5%c",37);
			printf("\n A pagar: $%d\n\n",250 - ((5*250)/100));
			cin.get();
		}
		void validarEmpleado();
		void inventario();
};
/**** Funciones Empleados ****/
void Empleados::validarEmpleado(){
	char log[10], pass[10];
	int bandera;
	strcpy(login1,"Lina");
	strcpy(login2,"Itzel");
	strcpy(login3,"Ricardo");
	strcpy(login4,"Georgina");
	strcpy(password1,"hello123");
	strcpy(password2,"6789Abril");
	strcpy(password3,"Rch1999");
	strcpy(password4,"mac1301");
	do{
		cout<<"\n *** Empleado ***";
		cout<<"\n\n Ingrese claves de acceso de empleado\n";	
		cout<<"\n Usuario: ";
		fflush(stdin);
		gets(log);
		fflush(stdin);
		cout<<" Password: ";
		fflush(stdin);
		gets(pass);
		fflush(stdin);
		if((strcmp(log,login1) != 0 || strcmp(pass,password1) != 0) && (strcmp(log,login2) != 0 || strcmp(pass,password2) != 0) && (strcmp(log,login3) != 0 || strcmp(pass,password3) != 0) && (strcmp(log,login4) != 0 || strcmp(pass,password4) != 0)){
			cout<<"\n Usuario y/o contrasena incorrecta.\n Pulse tecla para continuar.";
			cin.get();
			system("cls");
		}
	}while((strcmp(log,login1) != 0 || strcmp(pass,password1) != 0) && (strcmp(log,login2) != 0 || strcmp(pass,password2) != 0) && (strcmp(log,login3) != 0 || strcmp(pass,password3) != 0) && (strcmp(log,login4) != 0 || strcmp(pass,password4) != 0));
	cout<<"\n --> Acceso autorizado\n Pulse tecla para continuar --> ";
	cin.get();
}
/**** Template ****/
typedef union tipoDato{
	int codigo;
	float peso;
	char clave;
}tipo;
template<class Tipo>
class Pila{
	private:
		typedef struct nodo{
			Tipo num;
			struct nodo *ptr;
		}nod;
		nod *inicio;
	public:
		Pila();
		void leer(Tipo);
		void imprime();
		void sacar();
};
template<class Tipo> Pila<Tipo>::Pila(){
	inicio = NULL;
}
template<class Tipo> void Pila<Tipo>::leer(Tipo ndato){
	nod *nuevo; 
	nuevo = (nod*)malloc(sizeof(nod)); 
	nuevo->num = ndato;
	if(inicio == NULL){
		nuevo->ptr = NULL;
		inicio = nuevo; 
		cout<<"\n Pulse tecla para continuar.";
		cin.get();
		return;
	}
	nuevo->ptr = inicio;	
	inicio = nuevo;
	cout<<"\n Pulse tecla para continuar.";
	cin.get();
}
template<class Tipo> void Pila<Tipo>::imprime(){
	nod *aux = inicio;
	if(inicio == NULL){
		cout<<"\n Sin cajas de productos.\n Pulse tecla para continuar.";
		cin.get();
		return;
	}
	while(aux != NULL){
		cout<<"\n "<<aux->num;
		aux = aux->ptr; 
	}
	cout<<"\n\n Pulse tecla para continuar.";
	cin.get();
}
template<class Tipo> void Pila<Tipo>::sacar(){
	nod *aux = inicio;
	if(inicio == NULL){
		cout<<"\n Sin cajas de productos. \n Pulse tecla para continuar.";
		cin.get();
		return;
	}
	cout<<"\n En uso: "<<aux->num;
	inicio = aux->ptr;
	free(aux);
	cout<<"\n\n Pulse tecla para continuar.";
	cin.get();
}
void Empleados::inventario(){
	tipo tipoDeseado;
	Pila<int>pilaCod;
	Pila<float>pilaPeso;
	Pila<char>pilaClave;
	int opc, datoLee;
	do{
		cout<<"\n *** Inventario Souvenirs ***";
		cout<<"\n Apilacion de cajas de productos nuevos";
		cout<<"\n\n 1) Codigo de caja";
		cout<<"\n 2) Peso aproximado";
		cout<<"\n 3) Tipo (letra)";
		cout<<"\n 4) Regresar";
		cout<<"\n\n Dato a registrar: ";
		cin>>datoLee;
		if(datoLee == 4){}
		else if(datoLee == 1 || datoLee == 2 || datoLee == 3){
			do{
				system("cls");
				cout<<"\n *** Inventario Souvenirs Acuarium  ***\n";
				cout<<"\n 1. Agregar";
				cout<<"\n 2. Mostrar";
				cout<<"\n 3. Quitar caja";
				cout<<"\n 4. Regresar";
				cout<<"\n\n Elija una opcion: ";
				cin>>opc;
				switch(opc){
					case 1:
						if(datoLee == 1){
							cout<<"\n Codigo de caja: ";
							cin>>tipoDeseado.codigo;
							pilaCod.leer(tipoDeseado.codigo);
						}
						else if(datoLee == 2){
							cout<<"\n Peso: ";
							cin>>tipoDeseado.peso;
							pilaPeso.leer(tipoDeseado.peso);
						}
						else if(datoLee == 3){
							cout<<"\n Tipo (letra): ";
							cin>>tipoDeseado.clave;
							pilaClave.leer(tipoDeseado.clave);
						}
						cin.get();
						break;
					case 2:
						if(datoLee == 1){
							cout<<"\n Codigo de cajas\n";
							pilaCod.imprime();
						}
						else if(datoLee == 2){
							cout<<"\n Peso\n";
							pilaPeso.imprime();
						}
						else if(datoLee == 3){
							cout<<"\n Tipo de caja\n";
							pilaClave.imprime();	
						}
						cin.get();
						break;
					case 3:
						if(datoLee == 1){
							cout<<"\n Codigo de caja";
							pilaCod.sacar();
						}
						else if(datoLee == 2){
							cout<<"\n Peso";
							pilaPeso.sacar();
						}
						else if(datoLee == 3){
							cout<<"\n Tipo de caja";
							pilaClave.sacar();
						}
						cin.get();
						break;
					case 4:
						system("cls");
						cin.get();
						break;
					default: 
						cout<<"\n Eleccion invalida. \n Intente nuevamente. ";
						system("pause");
				}
			}while(opc!=4);
		}
		else{
			cout<<"\n Eleccion invalida. \n Intente nuevamente. ";
			system("pause");
			system("cls");
		}
	}while(datoLee!=4);
}
/******* fIGURAS ******/
class AbstractaFormasPez{
	private:
	protected:
		int visible;
		int x,y;
	public:
		AbstractaFormasPez(int,int);
		virtual void pintar() = 0;
	    virtual void ocultar() = 0;	
	    void trasladar(int,int);//polimorfica
		int get_visible();
		int get_x();
		int get_y();
};
AbstractaFormasPez::AbstractaFormasPez(int otraX = 100, int otraY = 200){
  	this->x = otraX;
  	this->y = otraY;
  	this->visible = 0;
}
void AbstractaFormasPez::trasladar(int nx, int ny){
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
int AbstractaFormasPez::get_x(){return this->x;}
int AbstractaFormasPez::get_y(){return this->y;}
int AbstractaFormasPez::get_visible(){return this->visible;}

/****Elipse****/
class ElipsePez:public AbstractaFormasPez{
	private:
		float radmay,radmen;
	public:
		ElipsePez(int ox, int oy, float rmay, float rmen):AbstractaFormasPez(ox,oy){
			radmay = rmay;
            radmen = rmen;
		}
		void pintar();
		void ocultar();
};
class ElipsePezColor:public ElipsePez{
	private:
		unsigned color;
	public:
		ElipsePezColor(int ox, int oy, float rmay, float rmen, int otroColor = CYAN):ElipsePez(ox,oy,rmay,rmen){
			color = otroColor;
		}
		virtual void pintar();
};
void ElipsePez::pintar(){
	visible = 1;
    ellipse((int)x,(int)y,0,360,(int)radmay,(int)radmen);
    fillellipse((int)x,(int)y,(int)radmay,(int)radmen);
}
void ElipsePezColor::pintar(){
	unsigned guardaColor = getcolor();
	setcolor(color);
	setfillstyle(1,color);
	ElipsePez::pintar();
	setcolor(guardaColor);	
}
void ElipsePez::ocultar(){
	unsigned guardacolor = getcolor();
	if(this->visible){
		setcolor(getbkcolor());
		setfillstyle(1,getbkcolor());
		ellipse((int)x,(int)y,0,360,(int)radmay,(int)radmen);
		fillellipse((int)x,(int)y,(int)radmay,(int)radmen);
		this->visible = 0;
		setcolor(guardacolor);
	}
}

/****Triángulo****/
class TrianguloPezColor:public AbstractaFormasPez{
	private:
		unsigned color;
		int x2, x3, y2, y3;
		int vect[8];
	public:
		TrianguloPezColor(int ox1, int oy1, int ox2, int oy2, int ox3, int oy3, int otroColor = WHITE):AbstractaFormasPez(ox1,oy1){
			color = otroColor;
			x = ox1;
			y = oy1;
			x2 = ox2;
			y2 = oy2;
			x3 = ox3;
			y3 = oy3;
			vect[0] = x;
			vect[1] = y;
			vect[2] = x2;
			vect[3] = y2;
			vect[4] = x3;
			vect[5] = y3;
			vect[6] = x;
			vect[7] = y;
		}
		void pintar();
		void ocultar();
		void trasladar(int,int);
};
void TrianguloPezColor::pintar(){
	unsigned guardaColor = getcolor();
	setcolor(color);
	visible = 1;
	setfillstyle(1,color);
	fillpoly(3,vect);
	setcolor(guardaColor);	
}
void TrianguloPezColor::ocultar(){
	unsigned guardacolor = getcolor();
	if(visible){
		visible = 0;
		setcolor(getbkcolor());
		setfillstyle(1,getbkcolor());
		fillpoly(3,vect);
		setcolor(guardacolor);
	}
}
void TrianguloPezColor::trasladar(int nx, int ny){
	if(visible){
		ocultar();
		int difx = abs(x - nx);
		int dify = abs(y - ny);
		vect[0] = x + difx;
		vect[1] = y + dify;
		vect[2] = x2 + difx;
		vect[3] = y2 + dify;
		vect[4] = x3 + difx;
		vect[5] = y3 + dify;
		vect[6] = x + difx;
		vect[7] = y + dify;
		pintar();
	}
}

/****Rectangulo****/
class RectanguloPezColor:public AbstractaFormasPez{
	private:
		unsigned color;
		int x2, x3, x4, y2, y3, y4;
		int vect[10];
	public:
		RectanguloPezColor(int ox1, int oy1, int ox2, int oy2, int ox3, int oy3, int ox4, int oy4, int otroColor = WHITE):AbstractaFormasPez(ox1,oy1){
			color = otroColor;
			x = ox1;
			y = oy1;
			x2 = ox2;
			y2 = oy2;
			x3 = ox3;
			y3 = oy3;
			x4 = ox4;
			y4 = oy4;
			vect[0] = x;
			vect[1] = y;
			vect[2] = x2;
			vect[3] = y2;
			vect[4] = x3;
			vect[5] = y3;
			vect[6] = x4;
			vect[7] = y4;
			vect[8] = x;
			vect[9] = y;
		}
		void pintar();
		void ocultar();
		void trasladar(int,int);
};
void RectanguloPezColor::pintar(){
	unsigned guardaColor = getcolor();
	setcolor(color);
	visible = 1;
	setfillstyle(1,color);
	fillpoly(4,vect);
	setcolor(guardaColor);	
}
void RectanguloPezColor::ocultar(){
	unsigned guardacolor = getcolor();
	if(visible){
		visible = 0;
		setcolor(getbkcolor());
		setfillstyle(1,getbkcolor());
		fillpoly(4,vect);
		setcolor(guardacolor);
	}
}
void RectanguloPezColor::trasladar(int nx, int ny){
	if(visible){
		ocultar();
		int difx = abs(x - nx);
		int dify = abs(y - ny);
		vect[0] = x + difx;
		vect[1] = y + dify;
		vect[2] = x2 + difx;
		vect[3] = y2 + dify;
		vect[4] = x3 + difx;
		vect[5] = y3 + dify;
		vect[6] = x4 + difx;
		vect[7] = y4 + dify;
		vect[8] = x + difx;
		vect[9] = y + dify;
		pintar();
	}
}

/**** Peces ****/
void PezCirujanoAzul(){
	srand(time(NULL));
	int ejemplar = 1 + rand() % 26;
	system("cls");
	cout<<"\n *** Pez Cirujano Azul ***";
	printf("\n\n Especimen %d de 26\n",ejemplar);
	printf("\n Tama%co: 25.4 a 30 cm",164);
	printf("\n Promedio de vida: 8 a 20 a%cos",164);
	printf("\n Alimentacion: Plancton");
	printf("\n Estado de conservacion: Procuracion menor\n\n");
	system("pause");
	int gd=DETECT, gm;
	initgraph(&gd, &gm,"c:\\TC\\BGI");
	
	RectanguloPezColor r1(0,0,0,700,1500,700,1500,0,3);
	ElipsePezColor aletaDelante(185,100,10,20,14);
	TrianguloPezColor cola(70,100,40,75,40,125,14);
	ElipsePezColor cuerpo(150,100,85,40,9);
	ElipsePezColor cuerpo2(145,80,62,20,0);
	ElipsePezColor cuerpo3(145,85,20,10,9);
	ElipsePezColor ojoInt(210,92,11,8,0);
	
	cola.pintar();
	cuerpo.pintar();
	cuerpo2.pintar();
	cuerpo3.pintar();
	aletaDelante.pintar();
	ojoInt.pintar();
	r1.pintar();
	
	for(int i = 1; i < 600; i++){
		r1.pintar();
		r1.pintar();
		cola.trasladar(70+i,100);
		cuerpo.trasladar(150+i,100);
		cuerpo2.trasladar(145+i,80);
		cuerpo3.trasladar(145+i,85);
		cuerpo3.trasladar(145+i,85);
		aletaDelante.trasladar(185+i,100);
		ojoInt.trasladar(210+i,92);
		delay(4);
	}
	settextstyle(4,0,1);
	setbkcolor(CYAN);
	setcolor(BLACK);
	outtextxy(260,440,"Pulse tecla para continuar...");
	getch();
	closegraph();
}
void PezMariposa(){
	srand(time(NULL));
	int ejemplar = 1 + rand() % 30;
	system("cls");
	cout<<"\n *** Pez Mariposa ***";
	printf("\n\n Especimen %d de 30.\n",ejemplar);
	printf("\n Tama%co: 12 a 22 cm",164);
	printf("\n Promedio de vida: 7 a 10 a%cos",164);
	printf("\n Alimentacion: Crustaceos, gusanos, plantas");
	printf("\n Estado de conservacion: Procuracion menor\n\n");
	system("pause");
	int gd=DETECT, gm;
	initgraph(&gd, &gm,"c:\\TC\\BGI");
	
	RectanguloPezColor r1(0,0,0,700,1500,700,1500,0,3);
	ElipsePezColor aletaArriba(96,70,50,25,14);
	ElipsePezColor aletaAbajo(96,130,50,25,14);
	TrianguloPezColor cola(70,100,40,75,40,125,14);
	TrianguloPezColor boca(175,119,146,105,146,130,14);
	ElipsePezColor cuerpo(115,100,55,48,14);
	ElipsePezColor ojo(146,105,13,15,1);
	ElipsePezColor ojoInt(152,99,8,8,0);
	
	aletaArriba.pintar();
	aletaAbajo.pintar();
	cuerpo.pintar();
	cola.pintar();	
	boca.pintar();
	ojo.pintar();	
	ojoInt.pintar();
	r1.pintar();
	for(int i = 1; i < 300; i++){
		r1.pintar();
		aletaArriba.trasladar(96+i,70);
		aletaAbajo.trasladar(96+i,130);
		boca.trasladar(175+i,119);
		cuerpo.trasladar(115+i,100);
		ojo.trasladar(146+i,105);
		ojoInt.trasladar(152+i,99);
		cola.trasladar(70+i,100);
		delay(5);
	}
	settextstyle(4,0,1);
	setbkcolor(CYAN);
	setcolor(BLACK);
	outtextxy(260,440,"Pulse tecla para continuar...");
	getch();
	closegraph();
}
void PezDorado(){
	srand(time(NULL));
	int ejemplar = 1 + rand() % 25;
	system("cls");
	cout<<"\n *** Pez Dorado ***";
	printf("\n\n Especimen %d de 25.\n",ejemplar);
	printf("\n Tama%co: 18cm",164);
	printf("\n Promedio de vida: 20 a%cos, en buenas condiciones",164);
	printf("\n Alimentacion: Crustaceos, gusanos, plantas");
	printf("\n Estado de conservacion: Procuracion menor\n\n");
	system("pause");
	int gd=DETECT, gm;
	initgraph(&gd, &gm,"c:\\TC\\BGI");
	
	RectanguloPezColor r1(0,0,0,700,1500,700,1500,0,3);
	TrianguloPezColor aletaArriba(115,70,90,40,50,85,12);
	TrianguloPezColor aletaAbajo(115,130,85,85,75,170,12);
	TrianguloPezColor aletaAbajo2(142,110,123,143,136,150,12);
	TrianguloPezColor aletaAbajo3(75,105,55,100,45,145,12);
	RectanguloPezColor cola3(15,100,15,110,60,100,60,95,12);
	TrianguloPezColor cola(60,95,-10,70,15,100,12);
	TrianguloPezColor cola2(60,100,-10,150,15,110,12);
	ElipsePezColor cuerpo(115,100,60,30,12);
	ElipsePezColor ojo(152,99,9,9,7);
	ElipsePezColor ojoInt(152,99,6,6,0);
	
	r1.pintar();
	aletaArriba.pintar();
	aletaAbajo.pintar();
	aletaAbajo2.pintar();
	aletaAbajo3.pintar();
	cola.pintar();	
	cola2.pintar();
	cola3.pintar();
	cuerpo.pintar();
	ojo.pintar();	
	ojoInt.pintar();

	for(int i = 1; i < 300; i++){
		r1.pintar();
		aletaArriba.trasladar(115+i,70);
		aletaAbajo.trasladar(115+i,130);
		aletaAbajo2.trasladar(142+i,110);
		aletaAbajo3.trasladar(75+i,105);
		cola.trasladar(60+i,95);
		cola2.trasladar(60+i,100);
		cola3.trasladar(15+i,100);
		cuerpo.trasladar(115+i,100);
		ojo.trasladar(152+i,99);
		ojoInt.trasladar(152+i,99);
		delay(5);
	}
	settextstyle(4,0,1);
	setbkcolor(CYAN);
	setcolor(BLACK);
	outtextxy(260,440,"Pulse tecla para continuar...");
	getch();
	closegraph();
}
void PezVela(){
	srand(time(NULL));
	int ejemplar = 1 + rand() % 3;	
	system("cls");
	cout<<"\n *** Pez Vela ***";
	printf("\n\n Especimen %d de 3.\n",ejemplar);
	printf("\n Tama%co: 3 m",164);
	printf("\n Peso: 100 kg");
	printf("\n Promedio de vida: 4 a%cos",164);
	printf("\n Alimentacion: Peces y calamares");
	printf("\n Estado de conservacion: En peligro de extincion.");
	printf("\n Habitad: Especialmente en el Oceano Atlantico\n\n");
	system("pause");
	int gd=DETECT, gm;
	initgraph(&gd, &gm,"c:\\TC\\BGI");
	
	RectanguloPezColor r1(0,0,0,700,1500,700,1500,0,3);
	RectanguloPezColor al1(270,115,260,115,260,80,270,80,1);
	RectanguloPezColor al2(260,115,250,115,250,75,260,75,1);
	RectanguloPezColor al3(250,115,240,115,240,70,250,70,1);
	RectanguloPezColor al4(240,115,230,115,230,65,240,65,1);
	RectanguloPezColor al5(230,115,220,115,220,60,230,60,1);
	RectanguloPezColor al6(220,115,210,115,210,50,220,50,1);
	RectanguloPezColor al7(210,115,200,115,200,40,210,40,1);
	RectanguloPezColor al8(200,115,190,115,190,30,200,30,1);
	RectanguloPezColor al9(190,115,180,115,180,25,190,25,1);
	RectanguloPezColor al10(180,115,160,115,160,25,180,25,1);
	RectanguloPezColor al11(160,115,150,115,150,30,160,30,1);
	RectanguloPezColor al12(150,115,140,115,140,40,150,40,1);
	RectanguloPezColor al13(140,115,130,115,130,50,140,50,1);
	RectanguloPezColor al14(130,115,120,115,120,60,130,60,1);
	RectanguloPezColor al15(120,115,110,115,110,70,120,70,1);
	RectanguloPezColor al16(110,115,100,115,100,80,110,80,1);
	RectanguloPezColor al17(100,115,90,115,90,90,100,90,1);
	RectanguloPezColor al18(90,115,80,115,80,95,90,95,1);
	RectanguloPezColor al19(80,115,70,115,70,100,80,100,1);
	TrianguloPezColor aletaAbajo(60,125,80,125,55,140,1);
	TrianguloPezColor aletaAbajo2(100,125,140,125,90,160,1);
	TrianguloPezColor aletaAbajo3(250,125,253,125,170,150,1);
	TrianguloPezColor aletaAbajo4(250,125,253,125,185,150,1);
	TrianguloPezColor boca(295,116,295,122,400,119,15);
	TrianguloPezColor boca2(295,116,295,119,400,119,1);
	TrianguloPezColor boca3(295,119,295,122,400,119,14);
	TrianguloPezColor cola(25,110,55,110,-10,50,1);
	TrianguloPezColor cola2(25,125,55,125,-10,190,1);
	RectanguloPezColor cola3(25,110,25,125,55,125,55,110,15);
	RectanguloPezColor franja1(25,110,25,119,300,119,300,110,1);//270->55
	RectanguloPezColor franja2(25,119,25,125,300,125,300,119,14);//270->55
	ElipsePezColor cuerpo(170,120,130,20,15);
	ElipsePezColor cuerpo2(170,110,130,10,1);
	ElipsePezColor ojo(290,110,6,6,7);
	ElipsePezColor ojoInt(290,110,3,3,0);
	
	r1.pintar();
	al1.pintar();
	al2.pintar();
	al3.pintar();
	al4.pintar();
	al5.pintar();
	al6.pintar();
	al7.pintar();
	al8.pintar();
	al9.pintar();
	al10.pintar();
	al11.pintar();
	al12.pintar();
	al13.pintar();
	al14.pintar();
	al15.pintar();
	al16.pintar();
	al17.pintar();
	al18.pintar();
	al19.pintar();
	aletaAbajo.pintar();
	aletaAbajo2.pintar();
	aletaAbajo3.pintar();
	aletaAbajo4.pintar();
	boca.pintar();
	boca3.pintar();
	boca2.pintar();
	cola.pintar();	
	cola3.pintar();
	cola2.pintar();
	franja1.pintar();
	franja2.pintar();
	cuerpo.pintar();
	cuerpo2.pintar();
	ojo.pintar();	
	ojoInt.pintar();

	for(int i = 1; i < 320; i++){
		r1.pintar();
		al1.trasladar(270+i,115);
		al2.trasladar(260+i,115);
		al3.trasladar(250+i,115);
		al4.trasladar(240+i,115);
		al5.trasladar(230+i,115);
		al6.trasladar(220+i,115);
		al7.trasladar(210+i,115);
		al8.trasladar(200+i,115);
		al9.trasladar(190+i,115);
		al10.trasladar(180+i,115);
		al11.trasladar(160+i,115);
		al12.trasladar(150+i,115);
		al13.trasladar(140+i,115);
		al14.trasladar(130+i,115);
		al15.trasladar(120+i,115);
		al16.trasladar(110+i,115);
		al17.trasladar(100+i,115);
		al18.trasladar(90+i,115);
		al19.trasladar(80+i,115);
		aletaAbajo.trasladar(60+i,125);
		aletaAbajo2.trasladar(100+i,125);
		aletaAbajo3.trasladar(250+i,125);
		aletaAbajo4.trasladar(250+i,125);
		boca.trasladar(295+i,116);
		boca3.trasladar(295+i,119);
		boca2.trasladar(295+i,116);
		cola.trasladar(25+i,110);
		cola2.trasladar(25+i,125);
		cola3.trasladar(25+i,110);
		cuerpo.trasladar(170+i,120);
		cuerpo2.trasladar(170+i,110);
		franja1.trasladar(25+i,110);
		franja2.trasladar(25+i,119);
		ojo.trasladar(270+i,115);
		ojoInt.trasladar(270+i,115);
		delay(5);
	}
	settextstyle(4,0,1);
	setbkcolor(CYAN);
	setcolor(BLACK);
	outtextxy(260,440,"Pulse tecla para continuar...");
	getch();
	closegraph();
}
void PezGlobo(){
	srand(time(NULL));
	int ejemplar = 1 + rand() % 7;
	system("cls");
	cout<<"\n *** Pez Globo ***";
	printf("\n\n Especimen %d de 7.\n",ejemplar);
	printf("\n Tama%co: 2.5 cm y puede crecer hasta 61 cm",164);
	printf("\n Promedio de vida: 8 a 10 a%cos",164);
	printf("\n Alimentacion: animales Invertebrados y algas");
	printf("\n Estado de conservacion: Preocupacion menor\n\n");
	system("pause");
	int gd=DETECT, gm;
	initgraph(&gd, &gm,"c:\\TC\\BGI");
	
	RectanguloPezColor r1(0,0,0,700,1500,700,1500,0,3);
	TrianguloPezColor cola(80,150,30,100,30,200,14);
	ElipsePezColor cuerpo(170,150,100,100,14);
	TrianguloPezColor aletaDelante(210,150,180,130,180,170,4);
	ElipsePezColor ojoInt(230,120,8,8,0);
	TrianguloPezColor boca1(280,120,250,120,250,190,14);
	TrianguloPezColor boca2(280,170,250,170,250,110,14);
	//En medio
    TrianguloPezColor p1(80,150,100,145,100,155,12);
	TrianguloPezColor p2(110,150,130,145,130,155,12);
	TrianguloPezColor p3(140,150,160,145,160,155,12);
	
	//Abajo
	TrianguloPezColor p4(90,180,110,175,110,185,12);
	TrianguloPezColor p5(120,180,140,175,140,185,12);
	TrianguloPezColor p6(150,180,170,175,170,185,12);
	TrianguloPezColor p7(180,180,200,175,200,185,12);
	TrianguloPezColor p8(105,210,125,205,125,215,12);
	TrianguloPezColor p9(135,210,155,205,155,215,12);
	TrianguloPezColor p10(165,210,185,205,185,215,12);
	TrianguloPezColor p11(195,210,215,205,215,215,12);
	TrianguloPezColor p12(140,240,160,235,160,245,12);
	TrianguloPezColor p13(170,240,190,235,190,245,12);
	
	//Arriba
	TrianguloPezColor p14(90,120,110,115,110,125,12);
	TrianguloPezColor p15(120,120,140,115,140,125,12);
	TrianguloPezColor p16(150,120,170,115,170,125,12);
	TrianguloPezColor p17(180,120,200,115,200,125,12);
	TrianguloPezColor p18(105,90,125,85,125,95,12);
	TrianguloPezColor p19(135,90,155,85,155,95,12);
	TrianguloPezColor p20(165,90,185,85,185,95,12);
	TrianguloPezColor p21(195,90,215,85,215,95,12);
	TrianguloPezColor p22(140,60,160,55,160,65,12);
	TrianguloPezColor p23(170,60,190,55,190,65,12);
	
	cola.pintar();
	boca1.pintar();
	boca2.pintar();
	cuerpo.pintar();
	aletaDelante.pintar();
	p1.pintar();
	p2.pintar();
	p3.pintar();
	p4.pintar();
	p5.pintar();
	p6.pintar();
	p7.pintar();
	p8.pintar();
	p9.pintar();
	p10.pintar();
	p11.pintar();
	p12.pintar();
	p13.pintar();
	p14.pintar();
	p15.pintar();
	p16.pintar();
	p17.pintar();
	p18.pintar();
	p19.pintar();
	p20.pintar();
	p21.pintar();
	p22.pintar();
	p23.pintar();
	ojoInt.pintar();
	r1.pintar();
	
	for(int i = 1; i < 300; i++){
		r1.pintar();
		cola.trasladar(80+i,150);
		boca1.trasladar(280+i,120);
		boca2.trasladar(280+i,170);
		cuerpo.trasladar(170+i,150);
		aletaDelante.trasladar(210+i,150);
		p1.trasladar(80+i,150);
		p2.trasladar(110+i,150);
		p3.trasladar(140+i,150);
		p4.trasladar(90+i,180);
		p5.trasladar(120+i,180);
		p6.trasladar(150+i,180);
		p7.trasladar(180+i,180);
		p8.trasladar(105+i,210);
		p9.trasladar(135+i,210);
		p10.trasladar(165+i,210);
		p11.trasladar(195+i,210);
		p12.trasladar(140+i,240);
		p13.trasladar(170+i,240);
		p14.trasladar(90+i,120);
		p15.trasladar(120+i,120);
		p16.trasladar(150+i,120);
		p17.trasladar(180+i,120);
		p18.trasladar(105+i,90);
		p19.trasladar(135+i,90);
		p20.trasladar(165+i,90);
		p21.trasladar(195+i,90);
		p22.trasladar(140+i,60);
		p23.trasladar(170+i,60);
		ojoInt.trasladar(230+i,120);
		delay(4);
	}
	settextstyle(4,0,1);
	setbkcolor(CYAN);
	setcolor(BLACK);
	outtextxy(260,440,"Pulse tecla para continuar...");
	getch();
	closegraph();
}
void PezLeon(){
	srand(time(NULL));
	int ejemplar = 1 + rand() % 20;
	system("cls");
	cout<<"\n *** Pez Leon ***";
	printf("\n\n Especimen %d de 20.\n",ejemplar);
	printf("\n Tama%co: 30 a 40 cm",164);
	printf("\n Promedio de vida: Hasta 15 a%cos con las condiciones adecuadas",164);
	printf("\n Alimentacion: Pequeños peces y crustaceos, se puede adaptar a nuevas presas");
	printf("\n Estado de conservacion: Preocupacion menor\n\n");
	system("pause");
	int gd=DETECT, gm;
	initgraph(&gd, &gm,"c:\\TC\\BGI");
	
	RectanguloPezColor r1(0,0,0,700,1500,700,1500,0,3);
	ElipsePezColor cuerpo(170,120,70,40,12);
	ElipsePezColor cola1(120,120,50,20,12);
	ElipsePezColor ojo(155,200,9,9,7);
	ElipsePezColor ojoInt(155,200,6,6,0);
	RectanguloPezColor al1(210,100,205,100,200,45,205,45,12);
	RectanguloPezColor al2(195,100,190,100,185,50,190,50,12);
	RectanguloPezColor al3(180,100,175,100,170,55,175,55,12);
	RectanguloPezColor al4(165,100,160,100,155,60,160,60,12);
	RectanguloPezColor al5(150,100,145,100,140,65,145,65,12);
	RectanguloPezColor al6(135,100,130,100,125,70,130,70,12);
	RectanguloPezColor al7(120,100,115,100,110,75,115,75,12);
	ElipsePezColor aletaAbajo(120,135,20,40,12);
	ElipsePezColor cuerpo2(160,90,50,20,12);
	TrianguloPezColor boca1(250,110,230,110,230,130,12);
	TrianguloPezColor boca2(250,130,230,130,230,110,12);
	
	r1.pintar();
	al1.pintar();
	al2.pintar();
	al3.pintar();
	al4.pintar();
	al5.pintar();
	al6.pintar();
	al7.pintar();
	aletaAbajo.pintar();
	cola1.pintar();	
	boca1.pintar();
	boca2.pintar();
	cuerpo2.pintar();
	cuerpo.pintar();
	ojo.pintar();	
	ojoInt.pintar();

	for(int i = 1; i < 320; i++){
		r1.pintar();
		cola1.trasladar(120+i,120);
		al1.trasladar(210+i,100);
		al2.trasladar(195+i,100);
		al3.trasladar(180+i,100);
		al4.trasladar(165+i,100);
		al5.trasladar(150+i,100);
		al6.trasladar(135+i,100);
		al7.trasladar(120+i,100);
		aletaAbajo.trasladar(120+i,135);
		boca1.trasladar(250+i,110);
		boca2.trasladar(250+i,130);
		cuerpo2.trasladar(163+i,93);
		cuerpo.trasladar(170+i,120);
		
		ojo.trasladar(210+i,110);
		ojoInt.trasladar(210+i,110);
		delay(5);
	}
	settextstyle(4,0,1);
	setbkcolor(CYAN);
	setcolor(BLACK);
	outtextxy(260,440,"Pulse tecla para continuar...");
	getch();
	closegraph();
}
void PezTiburon(){ 
	srand(time(NULL));	 
	int ejemplar = 1 + rand() % 8;
	system("cls");
	cout<<"\n *** Tiburon gris ***";
	printf("\n\n Especimen %d de 8.\n",ejemplar);
	printf("\n Tama%co: 0.5 a 2.0 m de largo",164);
	printf("\n Peso: 19 kg",164);
	printf("\n Promedio de vida: Maximo 25 a%cos",164);
	printf("\n Alimentacion: Peces oseos, elasmobranquios, cefalopodos, crustaceos");
	printf("\n Estado de conservacion: En peligro de amenaza");
	printf("\n Habitad: Mar Rojo, las Maldivas, la India, Madagascar, China, Nueva Zelanda, Filipinas Tailandia, Indonesia y Australia\n\n");
	system("pause");
	int gd=DETECT, gm;
	initgraph(&gd, &gm,"c:\\TC\\BGI");
	
	RectanguloPezColor r1(0,0,0,700,1500,700,1500,0,3);
	TrianguloPezColor cola(-80,100,-110,30,-40,90,8);
	TrianguloPezColor cola2(-80,100,-110,170,-40,110,8);
	RectanguloPezColor cola3(-80,90,-80,110,20,110,50,90,8);
	ElipsePezColor cuerpo(115,100,170,40,7);
	ElipsePezColor branquia1(180,100,10,20,7);
	ElipsePezColor branquia2(185,100,10,20,7);
	ElipsePezColor branquia3(190,100,10,20,7);
	ElipsePezColor branquia4(195,100,10,20,7);
	ElipsePezColor ojoInt(230,2,3,3,0);
	ElipsePezColor ojo(230,92,6,6,7);
	TrianguloPezColor aletaArriba1(100,20,110,70,155,70,8);
	TrianguloPezColor aletaArriba2(-35,40,15,70,-30,75,8);
	TrianguloPezColor aletaAbajo1(142,110,180,110,130,150,8);
	TrianguloPezColor aletaAbajo2(-25,120,15,120,-35,145,8);
	TrianguloPezColor aletaAbajo3(15,120,50,120,5,145,8);
	TrianguloPezColor boca(255,105,285,100,285,103,3);
	
	cola.pintar();
	cuerpo.pintar();
	ojoInt.pintar();
	ojo.pintar();
	cola2.pintar();
	cola3.pintar();
	aletaArriba1.pintar();
	aletaArriba2.pintar();
	aletaAbajo1.pintar();
	aletaAbajo2.pintar();
	aletaAbajo3.pintar();
	boca.pintar();
	branquia1.pintar();
	branquia2.pintar();
	branquia3.pintar();
	branquia4.pintar();
	
	for(int i = 1; i < 370; i++){
		r1.pintar();
		aletaAbajo2.trasladar(-25+i,120);
		aletaAbajo3.trasladar(15+i,120);
		cola3.trasladar(-80+i,90);
		cola.trasladar(-80+i,100);
		cola2.trasladar(-80+i,100);
		aletaArriba1.trasladar(110+i,20);
		aletaArriba2.trasladar(-25+i,20);
		cuerpo.trasladar(115+i,100);
		branquia1.trasladar(180+i,100);
		branquia2.trasladar(185+i,100);
		branquia3.trasladar(190+i,100);
		branquia4.trasladar(195+i,100);
		aletaAbajo1.trasladar(142+i,110);
		boca.trasladar(255+i,100);
		ojo.trasladar(230+i,92);
		ojoInt.trasladar(232+i,92);
		delay(5);
	}
	settextstyle(4,0,1);
	setbkcolor(CYAN);
	setcolor(BLACK);
	outtextxy(260,440,"Pulse tecla para continuar...");
	getch();
	closegraph();
}
void PezAngelCaraAzul(){
	srand(time(NULL));
	int ejemplar = 1 + rand() % 25;
	system("cls");
	cout<<"\n *** Pez angel de cara azul ***";
	printf("\n\n Especimen %d de 25.\n",ejemplar);
	printf("\n Tama%co: 15 cm",164);
	printf("\n Promedio de vida: 5 a 8 a%cos",164);
	printf("\n Alimentacion: Peces pequeños -> pancton");
	printf("\n               Peces grandes -> tunicados y esponjas");
	printf("\n Estado de conservacion: Menor preocupacion"); 
	printf("\n Habitad: Arrecifes coralinos soleados, dónde están solos o en pareja \n\n"); 
	system("pause");
	int gd=DETECT, gm;
	initgraph(&gd, &gm,"c:\\TC\\BGI");
	
	RectanguloPezColor r1(0,0,0,700,1500,700,1500,0,3);
	TrianguloPezColor cola(100,100,15,75,15,125,14);
	TrianguloPezColor boca(205,119,155,105,155,130,1);
	RectanguloPezColor aletaAbajo2(120,110,120,115,95,110,105,95,14);
	ElipsePezColor cuerpo(115,100,80,48,1);
	ElipsePezColor ojo(146,105,20,15,14);
	ElipsePezColor ojoInt(152,99,9,9,0);
	ElipsePezColor ojoInt1(163,115,5,5,15);
	ElipsePezColor aletaArriba(78,70,50,25,14);
	ElipsePezColor aletaAbajo(78,130,50,25,1);
	
	aletaAbajo2.pintar();
	aletaArriba.pintar();
	aletaAbajo.pintar();
	boca.pintar();
	cuerpo.pintar();
	ojo.pintar();	
	ojoInt.pintar();
	ojoInt1.pintar();
	cola.pintar();
	r1.pintar();
	
	for(int i = 1; i < 300; i++){
		r1.pintar();
		aletaArriba.trasladar(78+i,70);
		aletaAbajo.trasladar(78+i,130);
		boca.trasladar(205+i,119);
		cola.trasladar(100+i,100);
		cuerpo.trasladar(115+i,100);
		aletaAbajo2.trasladar(120+i,110);
		ojo.trasladar(146+i,105);
		ojoInt.trasladar(152+i,99);
		ojoInt1.trasladar(152+i,99);
		delay(5);
	}
	settextstyle(4,0,1);
	setbkcolor(CYAN);
	setcolor(BLACK);
	outtextxy(260,440,"Pulse tecla para continuar...");
	getch();
	closegraph();
	
}
void PezUnicornioDelMar(){
	srand(time(NULL));	   
    int ejemplar = 1 + rand() % 19;
    system("cls");
	cout<<"\n *** Unicornio de mar ****";
	printf("\n\n Especimen %d de 19.\n",ejemplar);
	printf("\n Tama%co: 4.5 m sin su cuerno",164);
	printf("\n Peso: 1 600 kg");
	printf("\n Promedio de vida: Hasta 50 a%cos",164);
	printf("\n Alimentacion: Peces y crustaceos de aguas frias");
	printf("\n Estado de conservacion: Casi amenazado");
	printf("\n Habitad: Viven en el Artico\n\n");
	system("pause");
	int gd=DETECT, gm;
	initgraph(&gd, &gm,"c:\\TC\\BGI");
	
	RectanguloPezColor r1(0,0,0,700,1500,700,1500,0,3);
	ElipsePezColor cuerpo(230,130,200,50,7);
	TrianguloPezColor cola1(-20,120,35,130,-30,50,8);
	RectanguloPezColor cola2(-20,120,-20,140,50,150,50,110,7);
	TrianguloPezColor cola3(-20,140,35,130,-30,210,8);
	TrianguloPezColor aletaAbajo1(290,130,330,130,270,200,8);
	ElipsePezColor c1(210,100,8,8,8);
	ElipsePezColor c2(230,107,8,8,8);
	ElipsePezColor c3(230,93,8,8,8);
	ElipsePezColor c4(230,93,5,5,8);
	ElipsePezColor c5(230,93,8,8,8);
	ElipsePezColor c6(230,93,5,5,8);
	ElipsePezColor c7(230,93,8,8,8);
	ElipsePezColor c8(230,93,8,8,8);
	ElipsePezColor c9(230,93,5,5,8);
	ElipsePezColor c10(230,93,5,5,8);
	ElipsePezColor c11(230,93,5,5,8);
	ElipsePezColor c12(230,93,5,5,8);
	ElipsePezColor c13(230,93,5,5,8);
	ElipsePezColor c14(230,93,5,5,8);
	ElipsePezColor c15(230,93,8,8,8);
	ElipsePezColor c16(230,93,5,5,8);
	ElipsePezColor c17(230,93,5,5,8);
	ElipsePezColor c18(230,93,5,5,8);
	ElipsePezColor c19(230,93,5,5,8);
	ElipsePezColor c20(230,93,8,8,8);
	ElipsePezColor c21(230,93,8,8,8);
	ElipsePezColor c22(230,93,8,8,8);
	ElipsePezColor c23(230,93,8,8,8);
	ElipsePezColor c24(230,93,5,5,8);
	ElipsePezColor c25(230,93,5,5,8);
	TrianguloPezColor boca(430,127,430,133,600,130,6);
	ElipsePezColor ojo(390,110,6,6,7);
	ElipsePezColor ojoInt(390,110,3,3,0);
	
	cola1.pintar();
	cola2.pintar();	
	cola3.pintar();
	cuerpo.pintar();
	c1.pintar();
	c2.pintar();
	c3.pintar();
	c4.pintar();
	c5.pintar();
	c6.pintar();
	c7.pintar();
	c8.pintar();
	c9.pintar();
	c10.pintar();
	c11.pintar();
	c12.pintar();
	c13.pintar();
	c14.pintar();
	c15.pintar();
	c16.pintar();
	c17.pintar();
	c18.pintar();
	c19.pintar();
	c20.pintar();
	c21.pintar();
	c22.pintar();
	c23.pintar();
	c24.pintar();
	c25.pintar();
	aletaAbajo1.pintar();
	boca.pintar();
	ojo.pintar();
	ojoInt.pintar();
		
	for(int i = 1; i < 500; i++){
		r1.pintar();
		cola3.trasladar(-20+i,140);
		cola1.trasladar(-20+i,120);
		cola2.trasladar(-20+i,120);
		cuerpo.trasladar(230+i,130);
		c1.trasladar(210+i,100);
		c2.trasladar(230+i,107);
		c3.trasladar(224+i,90);
		c3.trasladar(175+i,93);	
		c3.trasladar(185+i,110);	
		c4.trasladar(194+i,93);
		c5.trasladar(157+i,97);	
		c5.trasladar(134+i,99);	
		c6.trasladar(167+i,110);
		c7.trasladar(115+i,103);	
		c7.trasladar(145+i,113);
		c8.trasladar(-8+i,130);	
		c8.trasladar(28+i,125);	
		c9.trasladar(10+i,125);
		c9.trasladar(12+i,137);
		c10.trasladar(28+i,140);
		c11.trasladar(50+i,140);
		c12.trasladar(70+i,147);
		c13.trasladar(85+i,150);
		c14.trasladar(76+i,135);
		c15.trasladar(55+i,120);
		c15.trasladar(80+i,113);
		c14.trasladar(98+i,108);
		c16.trasladar(95+i,125);
		c17.trasladar(110+i,120);
		c18.trasladar(100+i,156);
		c19.trasladar(95+i,125);
		c20.trasladar(250+i,93);
		c21.trasladar(275+i,95);
		c21.trasladar(265+i,110);
		c22.trasladar(295+i,97);
		c23.trasladar(320+i,98);
		c24.trasladar(248+i,111);
		c24.trasladar(285+i,115);
		c25.trasladar(305+i,113);
		aletaAbajo1.trasladar(290+i,130);
		boca.trasladar(430+i,127);
		ojo.trasladar(390+i,115);
		ojoInt.trasladar(390+i,115);
		delay(5);
	}
	settextstyle(4,0,1);
	setbkcolor(CYAN);
	setcolor(BLACK);
	outtextxy(260,440,"Pulse tecla para continuar...");
	getch();
	closegraph();
}
void tienda(){
	char r2;
	int p1 = 0, p2 = 0, p3 = 0, p4 = 0, p5 = 0, p6 = 0, p7 = 0, p8 = 0, p9 = 0, p10 = 0, p11 = 0;
	int totalpago = 0, tp, ty, s1 = 17; 
	system("cls");
	gotoxy(5,1);
    printf("Introduzca el id y cantidad del/los art%cculos comprados\n\n",161);
    printf("       Id.      Descripci%cn      Precio\n",162);
    printf("       1       Vaso met%clico      $50\n",160);
	printf("       9       Gorra              $150\n");
    printf("       16      Sudadera           $350\n");
	printf("       54      Lapicera           $50\n");
	printf("       96      Mochila            $300\n");
	printf("       3       Aud%cfonos          $250\n",161);
	printf("       18      Bocina             $500\n");
	printf("       34      Peluche            $300\n");
	printf("       89      Alcanc%ca           $150\n",161);
    printf("       5       Termo              $250\n");
    printf("       8       Bolsa              $350\n\n\n");
    gotoxy(5,16);
	printf("Id. Art%cculo",161);
	gotoxy(19,16);
	printf("Cantidad");
	gotoxy(30,16);
	printf("Item",161);
	gotoxy(52,16);
	printf("Total a pagar");                   
	do{
		int numitem = 0, cant = 0, total = 0;
		gotoxy(5,s1);
		scanf("%d",&numitem);
		gotoxy(19,s1);
		scanf("%d",&cant);
		if (cant >= 0){
			switch(numitem){
				case 1:
					gotoxy(30,s1);
					fflush(stdin);
					printf("Vaso met%clico",160);
					total = 50 * cant;
					gotoxy(52,s1);
					printf("$%d",total);
					p1 = 1;
					break;
				case 9:
					gotoxy(30,s1);
					fflush(stdin);
					printf("Gorra");
					total = 150 * cant;
					gotoxy(52,s1);
					printf("$%d",total);
					p2 = 1;
					break;
				case 16:
					gotoxy(30,s1);
					fflush(stdin);
					printf("Sudadera");
					total = 350 * cant;
					gotoxy(52,s1);
					printf("$%d",total);
					p3 = 1;
					break;
				case 54:
					gotoxy(30,s1);
					fflush(stdin);
					printf("Lapicera");
					total = 50 * cant;
					gotoxy(52,s1);
					printf("$%d",total);
					p4 = 1;
					break;
				case 96:
					gotoxy(30,s1);
					fflush(stdin);
					printf("Mochila");
					total = 300 * cant;
					gotoxy(52,s1);
					printf("$%d",total);
					p5 = 1;
					break;
				case 3:
					gotoxy(30,s1);
					fflush(stdin);
					printf("Aud%cfonos",161);
					total = 250 * cant;
					gotoxy(52,s1);
					printf("$%d",total);
					p6 = 1;
					break;
				case 18:
					gotoxy(30,s1);
					fflush(stdin);
					printf("Bocina");
					total = 500 * cant;
					gotoxy(52,s1);
					printf("$%d",total);
					p7 = 2;
					break;
				case 34:
					gotoxy(30,s1);
					fflush(stdin);
					printf("Peluche");
					total = 300 * cant;
					gotoxy(52,s1);
					printf("$%d",total);
					p8 = 1;
					break;
				case 89:
					gotoxy(30,s1);
					fflush(stdin);           		
					printf("Alcanc%ca",161);
					total = 150 * cant;
					gotoxy(52,s1);
					printf("$%d",total);
					p9 = 1;
					break;
				case 5:
					gotoxy(30,s1);
					fflush(stdin);
					printf("Termo");
					total = 250 * cant;
					gotoxy(52,s1);
					printf("$%d",total);
					p10 = 1;
					break;
				case 8:
					gotoxy(30,s1);
					fflush(stdin);
					printf("Bolsa");
					total = 350 * cant;
					gotoxy(52,s1);
					printf("$%d",total);
					p11 = 1;
					break;
				default:
					gotoxy(30,s1);
					fflush(stdin);
					printf("\a");
					printf("Art%cculo inexistente",161);
					break;		           				          		 
			}
			totalpago = total + totalpago; 
			} else{
				printf("\a");
				gotoxy(5,s1);
				printf("         ");
				gotoxy(19,s1);
				printf("         ");	
			}  	
			s1 = s1 + 1;
			do{
				gotoxy(70,16);	
				fflush(stdout);
				printf("%cDesea agregar otro art%cculo? s/n: ",168,161);
				gotoxy(105,16);		
				fflush(stdin);
				scanf("%c",&r2);
            	if (tolower(r2) == 's'|| tolower(r2) == 'n'){ 
            		tp = 1;
                   	gotoxy(70,18);
                	printf("                                          ");
				} else if (tolower(r2) != 's'|| tolower(r2) != 'n'){
					tp = 2;
                	gotoxy(70,18);
                	printf("\a");
                	printf("Respuesta inv%clida, intente nuevamente",160);
				}
			} while (tp != 1);
			gotoxy(105,16);
			printf("      ");
	} while (tolower(r2) == 's');				
	gotoxy(45,s1+1);
	printf("Total: $%d",totalpago);	
	gotoxy(70,16);							
	system("pause");
}
void menu2(){
	cout<<"\n *** Aquarium ***\n\n";
	cout<<" 1) Pez Cirujano Azul\n";
	cout<<" 2) Pez Mariposa\n";
	cout<<" 3) Pez Dorado\n";
	cout<<" 4) Pez Vela \n";
	cout<<" 5) Pez Globo\n";
	cout<<" 6) Pez Leon\n";
	cout<<" 7) Tiburon gris\n";
	cout<<" 8) Pez angel de cara azul\n";
	cout<<" 9) Unicornio del Mar\n";	
	cout<<" 10) Regresar\n";
}
void switch1(){
	int opc;
	do{
		menu2();
		cout<<"\n Seleccione un pez: ";
		cin>>opc;
		switch(opc){
			case 1:
				PezCirujanoAzul();
				system("cls");
				break;
			case 2:
				PezMariposa();
				system("cls");
				break;
			case 3: 
				PezDorado();
				system("cls");
				break;
			case 4:
				PezVela();
				system("cls");
				break;
			case 5: 
				PezGlobo();
				system("cls");
				break;
			case 6: 
				PezLeon();
				system("cls");
				break;
			case 7: 
				PezTiburon();
				system("cls");
				break;
			case 8: 
				PezAngelCaraAzul();
				system("cls");
				break;
			case 9:
				PezUnicornioDelMar();
				system("cls");
				break;
			case 10:
				system("cls");
				cout<<"\n Gracias por visitar *** Acuarium ***\n";
				return;
				break;
			default:
				cout<<"\n Eleccion invalida. \n Intente nuevamente. ";
				system("pause");
				system("cls");
				break;	
		}
	}while(opc != 10);
}

main(){
	time_t timeIn, timeFn;
	srand(time(NULL));
	timeIn = time(NULL);
	Publico persona;
	Estudiante student;
	AdultoMayor elder;
	Usuario us;
	Empleados per;
	int opc, opc2;
	char bandera;
	us.validarAcceso();
	us.leeRutaNombre();	
	do{
		do{
			system("cls");
			cout<<"\n *** Bienvenido a Acuarium ***\n";
			us.nota();
			cout<<"\n\n [1] Publico general";
			cout<<"\n [2] Estudiante";
			cout<<"\n [3] Adulto mayor";
			cout<<"\n [4] Personal del acuario";
			cout<<"\n [5] Souvenirs";
			cout<<"\n\n Seleccione: ";
			cin>>opc;
			if(opc == 1 || opc == 2 || opc == 3){
				printf("\n Una vez seleccionado no se puede cambiar.\n %cContinuar? Si->[s], No->[n]: ",168);
				fflush(stdin);
				cin>>bandera;
			}
		}while (tolower(bandera) == 'n');	
		switch(opc){
			case 1:
				system("cls");
				cout<<"\n *** Acuarium ***\n";
				persona.precio();
				break;
			case 2:
				system("cls");
				cout<<"\n *** Acuarium ***\n";
				student.precio();
				break;
			case 3: 
				system("cls");
				cout<<"\n *** Acuarium ***\n";
				elder.precio();
				break;
			case 4:
				system("cls");
				per.validarEmpleado();
				system("cls");
				do{
					system("cls");
					cout<<"\n *** Empleado ***";
					cout<<"\n\n 1. Cometarios de visitantes";
					cout<<"\n 2. Inventario de cajas";
					cout<<"\n 3. Descuentos";
					cout<<"\n 4. Salir";
					cout<<"\n\n Elejir opcion: ";
					cin>>opc2;
					switch(opc2){
						case 1:
							system("cls");
							us.listarUsuarios();
							break;
						case 2:
							system("cls");
							per.inventario();
							break;
						case 3:
							system("cls");
							cout<<"\n *** Acuarium ***\n";
							per.precio();
							cout<<"\n Pulse tecla para continuar.";
							cin.get();
							break;			
						case 4:
							break;
						default: 
							cout<<"\n Eleccion invalida. \n Intente nuevamente. ";
							system("pause");
					}
				}while(opc2 != 4);
				break;
			case 5:
				do{
					system("cls");
					cout<<"\n *** Souvenirs ***\n";
					cout<<"\n [1] Tienda";
					cout<<"\n [2] Salir";
					cout<<"\n\n Seleccione: ";
					cin>>opc2;
					switch(opc2){
						case 1:
							tienda();
							break;
						case 2:
							system("cls");
							cout<<"\n Gracias por visitar *** Acuarium ***\n";
							cout<<"\n Para ayudarnos a mejorar, deje un comentario.\n";
							us.leeUsuario();
							us.guardarUsuario();
							us.getNombreArchivo();
							timeFn = time(NULL);
							printf("\n Fecha de entrada. %s",asctime(localtime(&timeIn)));
							printf(" Fecha de salida. %s",asctime(localtime(&timeFn)));
							printf("\n Tiempo de permanencia. %.2f minutos\n",difftime(timeFn,timeIn)/60);
							exit(0);
						default:
							cout<<"\n Eleccion invalida. \n Intente nuevamente. ";
							system("pause");
							break;	
					}
				}while(opc2 != 2);
			default:
				cout<<"\n Eleccion invalida. \n Intente nuevamente. ";
				system("pause");
				break;	
		}
		if(opc == 1 || opc == 2 || opc == 3){
			system("pause");
			system("cls");
			switch1();
		}
	}while(opc != 5);
}
void gotoxy(int x, int y){
	HANDLE lina;
	lina = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordenadas;
	coordenadas.X = x;
	coordenadas.Y = y;
	SetConsoleCursorPosition(lina,coordenadas); 
}
