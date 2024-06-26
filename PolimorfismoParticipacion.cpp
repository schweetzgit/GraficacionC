#include<iostream>
using namespace std;

class Oso{
	public:
		 virtual void carcatericaticas(){
		 	cout<<"\n Los osos tienen pelaje de diferente color y viven en diferentes lugares:\n";
		 }
		 void Especies(){ 
		 	carcatericaticas();
		 }
};

class Panda:public Oso{
	void carcatericaticas(){
	 	cout<<"\n Los osos panda son blanco y negro";
	 	cout<<"\n Viven en los bosques de Bambu al oeste de China\n";
	}
};
class Polar:public Oso{
	void carcatericaticas(){
	 	cout<<"\n Los osos polares son blancos";
	 	cout<<"\n Viven en el oceano Artico\n";
	}
};
class Pardo:public Oso{
	void carcatericaticas(){
	 	cout<<"\n Los osos pardo son cafe";
	 	cout<<"\n Viven en bosques y mantanas de Europa, Asia y Norteamerica\n";
	}
};
class Perezoso:public Oso{
	void carcatericaticas(){
	 	cout<<"\n Los osos perezosos son entre verde, cafe, gris o blanco";
	 	cout<<"\n Viven en el Centro y Sur de America\n";
	}
};
main(){
	Oso s1;
	Panda osoPanda;
	Polar osoPolar;
	Pardo osoPardo;
	Perezoso osoPer;
	
	s1.Especies();
	osoPanda.Especies();
	osoPolar.Especies();
	osoPardo.Especies();
	osoPer.Especies();
}
