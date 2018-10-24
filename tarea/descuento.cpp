// CARLOS ADIEL DIAZ DEL CID
// DD18003
// PROGRAMACION 1
// ING. LIGIA ASTRID HERNANDEZ


#include<iostream>//Libreria de entrada y salida de datos.
#include <iomanip>//Libreria para utilizar set presition.

// Para ahorrar tiempo escribiendo std en cada linea del codigo
using namespace std; 



//Estructura para la definicon del numero de empleados
struct Empleados{
	char cod[5];
	char nombre[50];
	int edad;
	float salbase;
	float salliquido;
	float afp;
	float isss;
	float renta;
	float totalprestamo;
	char departamento[60];
	char puesto;
	
};

//Estructura para las sucursales que puede visitar
struct Sucursal{
	int numsucursal;
	char nombresucural[60];
};



// Funcion para calcular ISSS
//Float calisss es el nombre de la funcion
float calisss(float sal, float tope) {
	float isss = 0;//Variable de ISSS

	
	isss = sal * 0.03;//Calculo del descuento por ISSS
	return isss;//Retorno de la funcion:ISSS

}



// Funcion para el calculo de AFP
//Float calAfp es el nombre de la funcion
float calAfp(float sal, float tope){//Definicion de la funcion
	float afp;//Variable de AFP
	
	afp = sal * 0.0625;//Calculo del descuento de AFP
	return afp;//Retorno de la funcion:AFP
	
}



// Funcion para el calculo de Renta
//Float calRenta es el nombre de la funcion
float calRenta (float sal, float isss, float afp, float renta){
	float res;//Variable de lafuncion
	float pors;//Variable del porsentaje de descuento
	float resf; //Variable del resultado
	
	
	
	//condicion 1 para calculo de la renta
	if (renta > 0.01 && renta <= 472){
		
		return renta;//Retorno de la funcion en caso de cumplir la condicion
	}


	
	//condicion 2 para calculo de la renta
	if (renta > 472.01 && renta <= 895.24){
	
		resf = ((renta - 472) * 0.1) + 17.67;//Calculo del resultado 
		
		return resf;//Retorno de la funcion en caso de cumplir la condicion
	} 


	
	//condicion 3 para calculo de la renta
	else if (renta > 895.25 && renta <= 2098.10){
		resf = ((renta - 895.24) * 0.2 )+ 60.00;//Calculo del resultado
		
		return resf;//Retorno de la funcion en caso de cumplir la condicion
	} 
	



	//condicion 4 para calculo de la renta
	else if (renta > 2038.11 ){
		resf = ((renta - 2038.10) * 0.3 )+ 288.57;//Calculo del resultado
		
		return resf;//Retorno de la funcion en caso de cumplir la condicion
	}
	
	 
}


//Cuerpo del programa (codigo estructurado)
int main(){
	int n;//Variable 1
	float sf;//Variable flotante 
	float renta;//Variable flotante de renta
	
	
	
	system("color 4C");//Agrega color a fondo y fuentes del ejecutable
	
	
	
	cout<<"       BIENVENIDO      "<<endl;//se imprime en pantalla 
	cout<<"CALCULADOR DE DESCUENTO"<<endl;//se imprime en pantalla
    system("pause");

	
	
	//ciclo para ingresar la cantidad de empleados
	do{
	cin.clear();
	system("cls");//Limpia la pantalla antes de mostras nuevas lineas de texto
	cin.ignore(1000,'\n');
	cout<<"Cuantos empleados tiene: "; cin>>n;//se imprime en pantalla y se almacena el dato
	} while (n <= 0 || cin.fail());



	
	Empleados e[n];//Numero de empleados de los que desea calcular la renta
	Sucursal s[2];//Sucursal a la que asiste
	
	system("cls");//limpia la pantalla antes de mostrar nuevas lineas de texto



	
//Operador para volver a mostrar los datos segun la cantidad de empleados introducidos
	for (int i=0; i<n; i++){
	cout<<"COLECTOR DE DATOS PARA LAS OPERACIONES"<<endl;//se imprime en pantalla	
	cout<< "     EMPLEADO"<<i+1<<endl;//se imprime en pantalla
	cout<<"cod: "; cin>>e[i].cod;//se imprime en pantalla y guarda el codigo del empleado
	cout<<"nombre:  "; cin>>e[i].nombre;//se imprime en pantalla y guarda el nombre del empleado
	cout<<"edad: "; cin>>e[i].edad;	//se imprime en pantalla y se guarda el dato de edad
	cout<<"Salario: "; cin>>e[i].salbase;//se imprime en pantalla y se guarda el dato del salario base
	e[i].isss = calisss(e[i].salbase,0.03);//Calculo de ISS
	e[i].afp = calAfp (e[i].salbase,7.25);//Calculo de salario base
	renta = e[i].salbase - ( e[i].isss + e[i].afp);//Aplicacion de la renta
	cout<<endl<<endl;//salto de linea
}



//Genera una pequeña pausa en el ejecutador
	system("pause");
	//Limpia la pantalla para mostrar nuevas lineas de texto
	system("cls");
	
	cout<<"OPERACIONES REALIZADAS"<<endl;
	cout<<"\n  RESULTADOS \n";




// Ciclo for para mostrar los resultados
	for (int i=0; i<n; i++){
	cout<<"cod: "<<e[i].cod<<endl;//se imprime en pantalla
	cout<<"nombre: "<<e[i].nombre<<endl;//se imprime en pantalla
	cout<<"edad: "<<e[i].edad<<endl;//se imprime en pantalla
	cout<<"Salario: "<<e[i].salbase<<endl;//se imprime en pantalla
	cout<<"ISSS: "<<e[i].isss<<endl;//se imprime en pantalla
	cout<< "AFP: "<<e[i].afp<<endl;//se imprime en pantalla
	cout<<"Salario -(isss+afp): "<<renta<<endl;//se imprime en pantalla
	if (renta > 0.01 && renta <= 472){
		cout<<"No se aplica renta..."<<endl;//se imprime en pantalla
	}



	
	else{
	e[i].renta = calRenta (e[i].salbase, e[i].afp, e[i].isss, renta);
	cout<<"Renta: "<<e[i].renta<<endl;//se imprime en pantalla
	sf = e[i].salbase - e[i].renta;
	cout<<"Salario - (renta): "<<sf<<endl;//se imprime en pantalla
	}


	
	cout<<"\n\n";//se imprime en pantalla
}




	return 0;//no retorna ningun valor
}
