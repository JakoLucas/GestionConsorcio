# include<iostream>
# include "MenuInformes.h"

using namespace std;

MenuInformes::MenuInformes(){

  seleccionOpcionMenu = 6;
}

void MenuInformes::mostrar(){
  int opcion;

  do{

  system("cls");
  opcion = seleccionOpcion();
  system("cls");
  ejecutarOpcion(opcion);
  system("pause");

  }while(opcion!=0);
}

void MenuInformes::mostrarOpciones(){
    rlutil::locate(45,3);
    rlutil::setColor(rlutil::GREEN);
    cout << " MENU INFORME " << endl;
    cout << endl;
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(45,5);
    cout << "1. INFORME RECAUDACION ANUAL " << endl;
    rlutil::locate(45,6);
    cout << "2. RANKING DE DEUDORES " << endl;
    rlutil::locate(45,7);
    cout << "3. INFORME DE EFICIENCIA DE PROVEEDORES " <<endl;
    rlutil::locate(45,8);
    cout << "4. REPORTE DE OCUPACION Y DEMOGRAFIA " << endl;
    rlutil::locate(45,9);
    cout << "5. INFORME DE INCIDENCIA POR PISO " << endl;
    cout << endl;
    rlutil::locate(45,11);
    cout << "0. VOLVER AL MENU PRINCIPAL " << endl;
    cout << endl;
}

int MenuInformes::seleccionOpcion(){
    int opc;
    mostrarOpciones();
    rlutil::locate(45,13);
    cout << "INGRESE OPCION: ";
    cin >> opc;

    while(opc < 0 || opc > seleccionOpcionMenu){
        rlutil::locate(45,12);
        rlutil::setColor(rlutil::RED);
        cout << "SELECCION INCORRECTA " <<endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(45,13);
        cout << "INGRESE OPCION: ";
        cin >> opc;
    }
        return opc;
}

void MenuInformes::ejecutarOpcion(int opc){

  switch(opc){

case 1:
        obj.informeAnual();
  break;
case 2:
        obj.rankingDeudores();
  break;
case 3:
        obj.informeEficiencia();
  break;
  case 4:
        obj.reporte();
  break;
  case 5:
       obj.informeIncidencia();
  break;
  case 0:
        rlutil::locate(45,3);
        rlutil::setColor(rlutil::GREEN);
        cout << "VOLVIENDO AL MENU PRINCIPAL " << endl;
        rlutil::setColor(rlutil::WHITE);
        return;

  }
}
