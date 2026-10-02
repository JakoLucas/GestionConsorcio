# include<iostream>
# include "gestionMenu.h"
# include "rlutil.h"

using namespace std;

gestionMenu::gestionMenu(){

  seleccionOpcionMenu = 8;
}

void gestionMenu::mostrar(){
  int opcion;

  do{
  system("cls");
  opcion = seleccionOpcion();
  system("cls");
  ejecutarOpcion(opcion);
  system("pause");

  }while(opcion!=0);
}

void gestionMenu::mostrarOpciones(){
    rlutil::locate(45,3);
    rlutil::setColor(rlutil::GREEN);
    cout << " MENU GESTION " << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    rlutil::locate(45,5);
    cout << "1. GESTION DE EDIFICIOS " << endl;
    rlutil::locate(45,6);
    cout << "2. GESTION DE UNIDADES " << endl;
    rlutil::locate(45,7);
    cout << "3. GESTION DE TITULARES " << endl;
    rlutil::locate(45,8);
    cout << "4. GESTION DE INTEGRANTES " << endl;
    rlutil::locate(45,9);
    cout << "5. GESTION DE EXPENSAS " << endl;
    rlutil::locate(45,10);
    cout << "6. GESTION DE RECLAMOS " << endl;
    rlutil::locate(45,11);
    cout << "7. GESTION DE SERVICIOS " << endl;
    cout << endl;
    rlutil::locate(45,13);
    cout << "0. SALIR " << endl;
    cout << endl;
}

int gestionMenu::seleccionOpcion(){
    int opc;
    mostrarOpciones();
    rlutil::locate(45,15);
    cout << "INGRESE OPCION: ";
    cin >> opc;

    while(opc < 0 || opc > seleccionOpcionMenu){
        rlutil::locate(45,14);
        rlutil::setColor(rlutil::RED);
        cout << "SELECCION INCORRECTA " <<endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(45,15);
        cout << "INGRESE OPCION: ";
        cin >> opc;
    }
        return opc;
}

void gestionMenu::ejecutarOpcion(int opc){

  switch(opc){

case 1:
        menuEdificio.mostrar();
  break;
case 2:
        menuUnidad.mostrar();
  break;
case 3:
        menuTitular.mostrar();
  break;
case 4:
        menuResidente.mostrar();
  break;
case 5:
        menuExpensas.mostrar();
  break;
case 6:
        menuReclamo.mostrar();
  break;
case 7:
        menuServicio.mostrar();
  break;
case 0: 
        rlutil::setColor(rlutil::GREEN);
        rlutil::locate(45,3);
        cout << "VOLVIENDO AL MENU PRINCIPAL " << endl;
        rlutil::setColor(rlutil::WHITE);
        return;

  }
}
