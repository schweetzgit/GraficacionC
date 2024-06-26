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
		virtual void teclaQ() = 0;
	    virtual void teclaW() = 0;	
	    virtual void teclaE() = 0;
	    virtual void teclaR() = 0;	
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
	cout<<"\n Nivel de utilidad: "<<this->utilidad;
}
void Campeones::getNvlDano(){
	cout<<"\n Nivel de dano: "<<this->dano;
}
void Campeones::getNvlDureza(){
	cout<<"\n Nivel de dureza: "<<this->dureza;
}
void Campeones::getNvlMovilidad(){
	cout<<"\n Nivel de movilidad: "<<this->movilidad;
}
void Campeones::getNvlControl(){
	cout<<"\n Nivel de control de masas: "<<this->control;
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
		void teclaQ();
	    void teclaW();	
	    void teclaE();
	    void teclaR();	
};
void Volibear::nombre(){cout<<"\n ----- VOLIBEAR, LA TORMENTA IMPLACABLE -----";}
void Volibear::rol(){cout<<" Rol: Luchador\n";}
void Volibear::teclaQ(){cout<<"\n Tecla Q. Choque estrenduoso";}
void Volibear::teclaW(){cout<<"\n Tecla W. Zarpazo frenetico";}
void Volibear::teclaE(){cout<<"\n Tecla E. Rompecielos";}
void Volibear::teclaR(){cout<<"\n Tecla R. Invocador de tormentas\n";}

//----------------------------------------------------
class LeBlanc:public Campeones{
	public:
		LeBlanc(int utl = 1,int dno = 3,int drza = 1,int mov = 2,int ctrl = 3, int dif = 3):Campeones(utl,dno,drza,mov,ctrl,dif){
		
		}
		void nombre();
		void rol();
		void teclaQ();
	    void teclaW();	
	    void teclaE();
	    void teclaR();	
};
void LeBlanc::nombre(){cout<<"\n\n ----- LEBLANC, LA MAQUIAVELICA -----";}
void LeBlanc::rol(){cout<<" Rol: Asesino\n";}
void LeBlanc::teclaQ(){cout<<"\n Tecla Q. Sello de maldad";}
void LeBlanc::teclaW(){cout<<"\n Tecla W. Distorsion";}
void LeBlanc::teclaE(){cout<<"\n Tecla E. Cadenas etereas";}
void LeBlanc::teclaR(){cout<<"\n Tecla R. Mimica\n";}

//----------------------------------------------------
class Orianna:public Campeones{
	public:
		Orianna(int utl = 2,int dno = 2,int drza = 1,int mov = 2,int ctrl = 1, int dif = 2):Campeones(utl,dno,drza,mov,ctrl,dif){
		
		}
		void nombre();
		void rol();
		void teclaQ();
	    void teclaW();	
	    void teclaE();
	    void teclaR();	
};
void Orianna::nombre(){cout<<"\n\n ----- ORIANNA, LA DONCELLA MECANICA -----";}
void Orianna::rol(){cout<<" Rol: Mago\n";}
void Orianna::teclaQ(){cout<<"\n Tecla Q. Orden:Atacar";}
void Orianna::teclaW(){cout<<"\n Tecla W. Orden:Disonancia";}
void Orianna::teclaE(){cout<<"\n Tecla E. Orden:Proteger";}
void Orianna::teclaR(){cout<<"\n Tecla R. Orden:Onda de choque\n";}

main(){
	cout<<"\n Descripcion breve de campeones de League of Legends\n";
	Volibear jugador1;
	jugador1.nombre();
	jugador1.getNvlDificultad();
	jugador1.rol();
	cout<<"\n Habilidades:";
	jugador1.teclaQ();
	jugador1.teclaW();
	jugador1.teclaE();
	jugador1.teclaR();
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
	cout<<"\n Habilidades:";
	jugador2.teclaQ();
	jugador2.teclaW();
	jugador2.teclaE();
	jugador2.teclaR();
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
	cout<<"\n Habilidades:";
	jugador3.teclaQ();
	jugador3.teclaW();
	jugador3.teclaE();
	jugador3.teclaR();
	jugador3.getNvlUtilidad();
	jugador3.getNvlDano();
	jugador3.getNvlDureza();
	jugador3.getNvlMovilidad();
	jugador3.getNvlControl();
	getch();	
}
