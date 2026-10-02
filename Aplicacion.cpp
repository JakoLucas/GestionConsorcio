# include<iostream>
#include "Aplicacion.h"

using namespace std;

Aplicacion::Aplicacion(){

  seleccion = 4;
}

void Aplicacion::run(){
  int opcion;

  do{
    
  system("cls");
  opcion = seleccionOpcion();
  system("cls");
  ejecutarOpcion(opcion);
  
  }while(opcion!=0);
}

void Aplicacion::mostrarOpciones(){
    rlutil::locate(45,3);
    rlutil::setColor(rlutil::GREEN);
    cout << "APP GESTION DE CONSORCIO " << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    rlutil::locate(45,5);
    cout << "1. GESTION " << endl;
    rlutil::locate(45,6);
    cout << "2. INFORMES " << endl;
    rlutil::locate(45,7);
    cout << "3. CONFIGURACION " << endl;
    rlutil::locate(45,8);
    cout << "0. SALIR " << endl;
    cout << endl;    
}

int Aplicacion::seleccionOpcion(){    
    int opc;
    mostrarOpciones();
    rlutil::locate(45,10);
    cout << "INGRESE OPCION: ";
    cin >> opc;
    
    while(opc < 0 || opc > seleccion){
        rlutil::locate(45,9);
        rlutil::setColor(rlutil::RED);
        cout << "SELECCION INCORRECTA " <<endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(45,10);
        cout << "INGRESE OPCION: ";
        cin >> opc;
        rlutil::anykey();
    }
        return opc;
}

void Aplicacion::ejecutarOpcion(int opc){

  switch(opc){
  
case 1:
      menu.mostrar();
  break;
case 2:
      menuInforme.mostrar();
  break;
case 3:
      menuConfig.mostrar();
  break;
case 0:
  rlutil::setColor(rlutil::GREEN);
  rlutil::locate(45,3);
  cout << " GRACIAS POR UTILIZAR MI APP :) " << endl;
  rlutil::setColor(rlutil::WHITE);
  break;
  }
}

