#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;

int determinante(float m[][2]);
void mostrarMatriz(float m[][2], int filas,int col);
void newton2x2(float matriz[][2],float f[],int filas,int col);
void ejercicio1(float x,float y,float tol);
float x0[3];
void imprimirvector(float f[],int n);
void mostarResultados(int n,float f[],float m[],float j[],float x[][2],float error);
int main(){

ejercicio1(1,1,1);
}


void imprimirvector(float f[],int n){
	for (int i=0;i<n;i++)
{
	printf("%0.5f " ,f[i]);
		cout<<"\n";
}
}
void mostarResultados(int n,float f[],float m[],float j[],float x[][2],float error){
	printf("\n");
	cout<<"--------------------------------------------------------------\n";
	cout<<"iteracion "<<n<<"\n";
	cout<<"--------------------------------------------------------------\n";
	cout<<"(x,y,z) "<<"\n";
	imprimirvector(f,2);
	cout<<"F(x,y) "<<"\n";
	imprimirvector(m,2);
	cout<<"Matriz Jacobiana"<<"\n";
	mostrarMatriz(x,2,2);
	cout<<"J(X)^-1F(X)"<<"\n";
	imprimirvector(j,2);
	cout<<"Error Absoluto"<<"\n";
	printf("%0.5f " ,error);
	
	
	
}
void mostrarMatriz(float m[][2],int filas,int col)
{

for (int i=0;i<filas;i++)
{
for(int j=0;j<col;j++)
{
printf("%0.5f " ,m[i][j]);

		}	
		printf("\n");			
	}
}

int determinante(float m[][2]){
	int det;
	det = (m[0][0]*m[1][1])-(m[1][0]*m[0][1]);
	return det;
	
}
void ejercicio1(float x,float y,float tol){
float x0[2]={x,y};
x0[0]=x;
x0[1]=y;
int k=0;
do{


float tolerancia=1;
int error;
float	fx1[2]={(x0[0]*x0[0])+(x0[0]*x0[1])-10,x0[1]-50+3*(x0[0]*x0[1]*x0[1])};
float	jaco1[2][2]={{(2*x0[0])+x0[1],x0[0]},{3*(x0[1]*x0[1]),6*(x0[0]*x0[1])+1}};
int detm;
	float jinv[2];
	float adj[2][2];

	adj[0][0] = jaco1[1][1];
	adj[0][1] = -jaco1[0][1];
	adj[1][0] = -jaco1[1][0];
	adj[1][1] = jaco1[0][0];

	detm=determinante(jaco1);

for (int i=0;i<2;i++)
{
for(int j=0;j<2;j++)
{
	jinv[i]=jinv[i]+fx1[j]*(adj[i][j]/detm);

		}	
			
	}
	
	mostarResultados(k,x0,fx1,jinv,jaco1,1);
	k++;
	for (int p=0;p<2;p++)
{

	x0[p]=x0[p]-jinv[p];
}
}
while(k<5);
}

