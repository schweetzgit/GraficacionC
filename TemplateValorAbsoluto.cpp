#include<iostream>
#include<stdlib.h>
using namespace std;

typedef union tipoDato{
	int a;
	float b;
	double c;
}dato;

template<class Tipo> 
class ValorAbsoluto{
	public:
		ValorAbsoluto();
		void mostrarAbs(Tipo);
		~ValorAbsoluto();
};
template<class Tipo> ValorAbsoluto<Tipo>::ValorAbsoluto(){
	
}
template<class Tipo> void ValorAbsoluto<Tipo>::mostrarAbs(Tipo numero){
	if(numero<0){
		numero = numero * -1;
	}
	cout<<"El valor absoluto es: "<<numero<<endl;
}

template<class Tipo> ValorAbsoluto<Tipo>::~ValorAbsoluto(){
	
}
	
main(){
	ValorAbsoluto<int> vabsInt;	
	ValorAbsoluto<float> vabsFloat;
	ValorAbsoluto<double> vabsDouble;
	dato num;
	char tipoLeido;
	
	cout<<"Tipo de Dato que desea manejar: [E:entero, F:flotante, D:double]: ";
	cin>>tipoLeido;
	cout<<"\nIngrese un numero: ";
	if(tipoLeido=='e'||tipoLeido=='E'){
		cin>>num.a;
		vabsInt.mostrarAbs(num.a);
	}
	else if (tipoLeido=='f'||tipoLeido=='F'){
		cin>>num.b;
		vabsFloat.mostrarAbs(num.b);
	}
	else if (tipoLeido=='d'||tipoLeido=='D'){
		cin>>num.c;
		vabsFloat.mostrarAbs(num.c);
	}
}
