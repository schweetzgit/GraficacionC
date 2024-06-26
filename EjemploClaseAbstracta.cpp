#include<iostream>
#include<conio.h>
using namespace std;

class Campeones{
	protected:
		int utilidad, dano, dureza, movilidad, control, dificultad;//niveles de habilidades
	public:
		Campeones(int,int,int,int,int,int);
		virtual void nombre() = 0;
		virtual void rol() = 0;
		void getNvlUtilidad();	
		void getNvlDano();
		void getNvlDureza();
		void getNvlMovilidad();
		void getNvlControl();
		void getNvlDificultad();
};
Campeones::Campeones(int utl = 0,int dno = 0,int drza = 0,int mov = 0,int ctrl = 0, int dif = 0){
  	this->utilidad = utl;
  	this->dano = dno;
  	this->dureza = drza;
  	this->movilidad = mov;
  	this->control = ctrl;
  	this->dificultad = dif;
}
void Campeones::getNvlUtilidad(){
	cout<<"\n Utilidad: "<<this->utilidad;
}
void Campeones::getNvlDano(){
	cout<<"\n Dano: "<<this->dano;
}
void Campeones::getNvlDureza(){
	cout<<"\n Dureza: "<<this->dureza;
}
void Campeones::getNvlMovilidad(){
	cout<<"\n Movilidad: "<<this->movilidad;
}
void Campeones::getNvlControl(){
	cout<<"\n Control de masas: "<<this->control;
}
void Campeones::getNvlDificultad(){
	cout<<"\n Nivel de dificultad: "<<this->dificultad<<"\n";
}

//----------------------------------------------------
class Volibear:public Campeones{
	public:
		Volibear(int utl = 1,int dno = 2,int drza = 3,int mov = 2,int ctrl = 2, int dif = 1):Campeones(utl,dno,drza,mov,ctrl,dif){
		
		}
		void nombre();
		void rol();
};
void Volibear::nombre(){cout<<"\n ----- VOLIBEAR, LA TORMENTA IMPLACABLE -----";}
void Volibear::rol(){cout<<" Rol: Luchador\n";}

//----------------------------------------------------
class LeBlanc:public Campeones{
	public:
		LeBlanc(int utl = 1,int dno = 3,int drza = 1,int mov = 2,int ctrl = 3, int dif = 3):Campeones(utl,dno,drza,mov,ctrl,dif){
		
		}
		void nombre();
		void rol();
};
void LeBlanc::nombre(){cout<<"\n\n ----- LEBLANC, LA MAQUIAVELICA -----";}
void LeBlanc::rol(){cout<<" Rol: Asesino\n";}

//----------------------------------------------------
class Orianna:public Campeones{
	public:
		Orianna(int utl = 2,int dno = 2,int drza = 1,int mov = 2,int ctrl = 1, int dif = 2):Campeones(utl,dno,drza,mov,ctrl,dif){
		
		}
		void nombre();
		void rol();	
};
void Orianna::nombre(){cout<<"\n\n ----- ORIANNA, LA DONCELLA MECANICA -----";}
void Orianna::rol(){cout<<" Rol: Mago\n";}

main(){
	cout<<"\n Descripcion breve de campeones de League of Legends\n";
	Volibear jugador1;
	jugador1.nombre();
	jugador1.getNvlDificultad();
	jugador1.rol();
	cout<<"\n Nivel de habilidades:";
	jugador1.getNvlUtilidad();
	jugador1.getNvlDano();
	jugador1.getNvlDureza();
	jugador1.getNvlMovilidad();
	jugador1.getNvlControl();
	getch();
	
	LeBlanc jugador2;
	jugador2.nombre();
	jugador2.getNvlDificultad();
	jugador2.rol();
	cout<<"\n Nivel de habilidades:";
	jugador2.getNvlUtilidad();
	jugador2.getNvlDano();
	jugador2.getNvlDureza();
	jugador2.getNvlMovilidad();
	jugador2.getNvlControl();
	getch();
	
	Orianna jugador3;
	jugador3.nombre();
	jugador3.getNvlDificultad();
	jugador3.rol();
	cout<<"\n Nivel de habilidades:";
	jugador3.getNvlUtilidad();
	jugador3.getNvlDano();
	jugador3.getNvlDureza();
	jugador3.getNvlMovilidad();
	jugador3.getNvlControl();
	getch();	
}
