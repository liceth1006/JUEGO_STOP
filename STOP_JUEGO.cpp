#include <iostream>
#include <fstream>//guardar archivo
#include <ctime>//calculo de tiempo letra aleatoria
#include <iomanip> //ordenar con setw las salidas de datos
#include <time.h>// calculo tiempo
#include <chrono>//tiempo

using namespace std;
//constantes
const int fila=50;
const int columna=50;
//prototipo
void instrucciones();
void cantidad_jugadores(int cantidad);
void ingreso_categorias(string stop[0][50], int,int,int categorias);
void llenar_matriz(string stop[0][50], int,int,int categorias,int jugadas);
void puntos_final(string stop[0][50], int,int,int jugadas, int categorias, string stop_mayuscula);
void imprimir_matriz(string stop[0][50], int,int,int categorias,int jugadas);
void evaluar_respuesta(int faltas,int descuentos,int puntaje_final);

//variables globales
int cantidad,i,jugadas,categorias,puntaje_final;
string stop[fila][columna];
string jugador[fila];
string stop_mayuscula;
int suma_tiempo;
int final_tiempo;
int main() {
//variables locales
int acepta,confirmacion,faltas,descuento;
//datos constantes en matriz
stop[0][0]="LETRA";
  //inicio
instrucciones();
cout << "Aceptas las instruciones: "<<endl;
cout<<"1. SI"<<endl;
cout<<"2. NO" << endl;
cin >> acepta;
if ( acepta==1 ) {
    cantidad_jugadores(cantidad);
    cout << " " << endl;
    cout << "INGRESA LA CANTIDAD DE JUGADAS PARA ESTA PARTIDA MAXIMO 10: "<< endl;
    cin >> jugadas;
    if (jugadas >= 10) {
      cout << "ingresa un valor valido" << endl;
      return jugadas;
    }
    cout << "INGRESA LA CANTIDAD DE CATEGORIAS PARA ESTA PARTIDA MINIMO 3 MAXIMO 10:" << endl;
    cin >> categorias;
    if (categorias < 3) {
      cout << "ingresa un valor valido" << endl;
      return 0;
    } 
    else if (categorias > 10) {
      cout << "ingresa un valor valido" << endl;
      return categorias;
    } 
    ingreso_categorias( stop, fila,columna,categorias);
    cout<< "_____________________________________________________________________________"<< endl;
    cout<<"Confirma que estan bien las categorias ingresadas?"<<endl;
    cout<<"1. SI"<<endl;
    cout<<"2. NO" << endl;
    cin>>confirmacion;
    while (confirmacion ==2 ){
      cout << "INGRESA DE NUEVO LAS CATEGORIAS"<<endl;
      ingreso_categorias( stop, fila,columna,categorias);
      cout<<"CONFIRMA QUE ESTAN BIEN LAS CATEGORIAS INGRESADAS?"<<endl;
      cout<<"1. SI"<<endl;
      cout<<"2. NO" << endl;
      cin>>confirmacion;
    }
    if (confirmacion==1){
      llenar_matriz(stop, fila,columna,categorias,jugadas);
      puntos_final(stop,fila,columna,jugadas,categorias, stop_mayuscula);
      imprimir_matriz(stop, fila,columna,categorias,jugadas);
      cout<<"___________________________________________________________________________"<<endl;
  cout<<"PUNTOS DE LA PARTIDA: "<< puntaje_final<<endl;
  cout<<"_____________________________________________________________________________"<<endl;
      cout<<"TIEMPO FINAL PARTIDA:  "<< suma_tiempo<<"  SEGUNDOS"<<endl;
      evaluar_respuesta(faltas,descuento,puntaje_final); 
    }
}
else if (acepta ==2) {
    cout << "gracias por participar";
    cout << " " << endl;
    return 0;
    
  } 
  else {
    cout << "ingesa un valor valido" << endl;
    cout << " " << endl; 
    return 0;
  }
}
void instrucciones(){
  cout<<"_____________________________________________________________________________\n";
  cout<<"                          BIENVENIDO AL JUEGO STOP                    \n ";
  cout<<"_____________________________________________________________________________\n";
  cout<<"1. Lea las instrucciones del juego STOP, si esta de acuerdo acepta las instrucciones.\n";
  cout<<"2. Ingresa la cantidad de jugadores para esta partida.\n";
  cout<<"3. Ingresa el nombre de los jugadores.\n";
  cout<<"4. Seleccione la cantidad de jugadas para esta partida maximo 10.\n";
  cout<<"5. Seleccione la cantidad de categorias para esta partida minimo 3 maximo 10.\n";
  cout<<"6. El sistema genera una letra al azar de la A - Z .\n";
  cout<<"7. Cada acierto suma 100 puntos, si queda en blanco o ingresa menos de 3 carateres es 0.\n";
  cout<<"8. El jugador ganador es el que tenga mayor puntuacion y menor tiempo.\n";
  cout<<"9. Al final se evalua si las respuesta son acordes a la lengua espanola, si se considera que no existe se puede descontar por cada palabra mal 100 puntos.\n";
  cout<<"10.al final realizara la comparacion de los resultado de los jugadores. \n";
  cout<<"_____________________________________________________________________________\n";
}
void cantidad_jugadores(int cantidad){
  while (i <= cantidad) {
    cout << "ingresa el nombre del jugador " << endl;
    cin >> jugador[i];
    i++;
  }
}
void ingreso_categorias(string stop[0][50], int,int,int categorias){
  cout<< "_____________________________________________________________________________"<< endl;
  cout << "INGRESE LAS CATEGORIAS PARA ESTA PARTIDA:" << endl;
  int i = 1;
  while (i <= categorias) {
    cin >> stop[0][i];
    i++;
  }
}
void llenar_matriz(string stop[0][50], int,int,int categorias,int jugadas){
  suma_tiempo=0;
  char letra1;
  srand(time(NULL));
  char letras[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I','J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R','S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  //ingreso de datos
  int cont3,cont2;
  for (cont3 = 1; cont3 <= jugadas; cont3++) {
   auto start = chrono::steady_clock::now();//calculo de tiempo inicial
    for (int i = 0; i < 1; i++) {
      letra1 = letras[rand() % 26];
      stop[cont3][0]= stop[cont3][0]+letra1;
      cout << "LETRA GENERADA  ES: " << letra1 << " " << endl; 
    }
    for (cont2 = 1; cont2 <= categorias; cont2++) {
      cout<<stop[0][cont2]<<" : "; 
      cin >> (stop[cont3][cont2]);
    } 
    auto end = chrono::steady_clock::now();//calculo tiempo final
    final_tiempo=chrono::duration_cast<chrono::seconds>(end - start).count();
    suma_tiempo +=final_tiempo;
    stop[cont3][cont2]=to_string(final_tiempo);
    }     
    
}
void puntos_final(string stop[0][50], int,int,int jugadas, int categorias,string stop_mayuscula){
  stop[0][categorias+1]="TIEMPO";
  stop[0][categorias+2]="PUNTAJE";
  int cont3,cont2;
  string stop_aleatoria,pri_letra;
  int recorrido,puntaje,total_puntaje;  
  puntaje_final=0;
  for (cont3 = 1; cont3 <= jugadas; cont3++) {
    puntaje=0;
    total_puntaje=0;
    for (cont2 = 1; cont2 <= categorias; cont2++) {
      stop_aleatoria=stop[cont3][0];
      stop_mayuscula = stop[cont3][cont2];
      recorrido=stop_mayuscula.size();
      pri_letra=stop_mayuscula[0];
      for(int letra=0; letra < 1; letra++){
        pri_letra[letra] = toupper(pri_letra[letra]);//pasar a mayuscula
      }  
      if (recorrido >= 3 && pri_letra!=stop_aleatoria){
        puntaje -=100;  
      } 
      else if( recorrido >= 3 && pri_letra==stop_aleatoria){  
        puntaje +=100;
      }
    }
    total_puntaje +=puntaje;
    stop[cont3][cont2+1]=to_string(total_puntaje);  
    puntaje_final+=total_puntaje;
  }  
}
void imprimir_matriz(string stop[0][50], int,int,int categorias,int jugadas){
  int cont3,cont2;
  //imprimir 
  cout << "_____________________________________________________________________________"<< endl;
  cout << "_______________________RESULTADOS PARA ESTA PARTIDA__________________________"<< endl;
  cout << "_____________________________________________________________________________"<< endl;
  cout << " " << endl;
  cout<<endl;
  for (cont3 = 1; cont3 <= jugadas+2; cont3++) {
    cout << "_____________________________________________________________________________"<< endl;
    for (cont2 = 1; cont2 <= categorias+3; cont2++) {
      cout<<" | "<<left<<setw(10)<< stop[cont3-1][cont2-1]<<left<<setw(3);
    } 
    cout<<endl;
  }
}
void evaluar_respuesta(int faltas,int descuento,int puntaje_final){
  int resultado;
  cout<<"*************************EVALUAR RESPUESTA***********************************"<<endl;
  cout<<"_____________________________________________________________________________"<<endl;
  cout<<"tienes faltas ortografica?"<<endl;
  cout<<"1. SI" <<endl;
  cout<<"2. NO" <<endl;
  cin>>faltas;
  if ( faltas==1 ) {
    cout<<"ingresa la cantidad de palabras que tengan falta ortograficas. evaluar respuesta"<<endl;
    cin>>descuento;
    resultado=descuento*100;
    cout<<"_____________________________________________________________________________"<<endl;
    cout<<"PUNTOS TOTAL PARTIDA: "<<puntaje_final-resultado<<endl;
    cout<<"_____________________________________________________________________________"<<endl;
  } 
  else if (faltas ==2) {
    cout<<"_____________________________________________________________________________"<<endl;
    cout<<"PUNTOS TOTAL PARTIDA: "<<puntaje_final<<endl;
    cout<<"_____________________________________________________________________________"<<endl;

  } 
  else {
    cout << "ingesa un valor valido" << endl;
    cout << " " << endl; 
  }
}
  
