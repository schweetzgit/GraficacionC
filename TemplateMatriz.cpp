#include<iostream>
using namespace std;
#define n 3 //renglones
#define m 3 //columnas

//const: de acceso
template<class T> // T es un parametro generico
class Matrix{
	private:
		T mat[n][m];
	public:
		Matrix();
		~Matrix();
		void leeMatrix();
		void imprimeMatrix() const;
		Matrix operator + (Matrix &) const;
		Matrix operator - (Matrix &) const;
		Matrix operator * (Matrix &) const;
		//Implementar las funciones que se crean convenientes 
};
template<class T> Matrix<T>::Matrix(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
		   mat[i][j] = 0;
	}
}
template<class T> Matrix<T>::~Matrix(){
	
}
template<class T> void Matrix<T>::leeMatrix(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
		   cout<<" ["<<i<<","<<j<<"]: ";
		   cin>>mat[i][j];
		}
	}
}
template<class T> void Matrix<T>::imprimeMatrix() const{
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
    }
}

template<class T> Matrix<T> Matrix<T>::operator + (Matrix &matB)const{
	Matrix matResul;
	for(int i = 0; i < n; i++)
	   for(int j = 0; j < m; j++)
	   	  matResul.mat[i][j] = mat[i][j] + matB.mat[i][j];
	return matResul;
}

template<class T> Matrix<T> Matrix<T>::operator - (Matrix &matB)const{
	Matrix matResul;
	for(int i = 0; i < n; i++)
	   for(int j = 0; j < m; j++)
	   	  matResul.mat[i][j] = this->mat[i][j] - matB.mat[i][j];
	return matResul;
}

template<class T>Matrix<T> Matrix<T>::operator * (Matrix &matB)const{
	Matrix matResult;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			matResult.mat[i][j] = 0;
			for(int k = 0; k < n; k++){
				matResult.mat[i][j] = matResult.mat[i][j] + this->mat[i][k]*matB.mat[k][j];
			}	
		}
	}
	return matResult;
}

main(){
	Matrix<int> A;
	Matrix<float> B;
	Matrix<char> C;
	const Matrix<int> D;
	cout<<"\n Lectura de el arreglo matricial A de enteros:\n";
	A.leeMatrix();
	cout<<"\n Lectura de el arreglo matricial B de flotantes:\n";
	B.leeMatrix();
	cout<<"\n Lectura de el arreglo matricial C de caracteres:\n ";
	C.leeMatrix();
	cout<<"\n A:\n";
	A.imprimeMatrix();
	cout<<"\n B:\n";
	B.imprimeMatrix();
	cout<<"\n C:\n";
	C.imprimeMatrix();
	/****cout<<"\n Lectura de el arreglo matricial constante D de enteros:\n";
	D.leeMatrix();****///No se puede con  void imprimeMatrix()
	cout<<"\n Arreglo matricia constante D:\n";
	D.imprimeMatrix();
	cout<<"\n A + D:\n";
	(D+A).imprimeMatrix();
}
