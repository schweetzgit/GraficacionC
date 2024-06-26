#include<iostream>
using namespace std;

#define n 3 //renglones
#define m 3 //columnas

class Matrix{
	private:
		int mat[n][m];
	public:
		Matrix();
		~Matrix();
		void leeMatrix();
		void imprimeMatrix();
		Matrix operator + (Matrix &);
		Matrix operator - (Matrix &);
		Matrix operator * (Matrix &);
		//Matrix operator * (int x);
		//friend Matrix operator * (int x, Matrix &); 
		//Matrix operator = (Matrix &);
		//Matrix operator = (int);
		//Transpuesta
		//Inversa
		//Implementar las funciones que se crean convenientes 
};
Matrix::Matrix(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
		   mat[i][j] = 0;
	}
}
Matrix::~Matrix(){
	
}
void Matrix::leeMatrix(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
		   cout<<" ["<<i<<","<<j<<"]: ";
		   cin>>mat[i][j];
		}
	}
}
void Matrix::imprimeMatrix(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
    }
}
Matrix Matrix::operator + (Matrix &matB){
	Matrix matResul;
	for(int i = 0; i < n; i++)
	   for(int j = 0; j < m; j++)
	   	  matResul.mat[i][j] = mat[i][j] + matB.mat[i][j];
	return matResul;
}
Matrix Matrix::operator - (Matrix &matB){
	Matrix matResul;
	for(int i = 0; i < n; i++)
	   for(int j = 0; j < m; j++)
	   	  matResul.mat[i][j] = this->mat[i][j] - matB.mat[i][j];
	return matResul;
}
Matrix Matrix::operator * (Matrix &matB){
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
	Matrix A, B;
	cout<<"\n Lectura de el arreglo matricial A:\n";
	A.leeMatrix();
	cout<<"\n Lectura de el arreglo matricial B:\n";
	B.leeMatrix();
	cout<<"\n A:\n";
	A.imprimeMatrix();
	cout<<"\n B:\n";
	B.imprimeMatrix();
	
	cout<<"\n A + B:\n";
	(A+B).imprimeMatrix();
	
	cout<<"\n A - B:\n";
	(A-B).imprimeMatrix();
	
	cout<<"\n A * B:\n";
	(A*B).imprimeMatrix();
	
}
