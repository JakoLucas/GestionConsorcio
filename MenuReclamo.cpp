# include<iostream>
# include "MenuReclamo.h"
# include "rlutil.h"
using namespace std;

MenuReclamo::MenuReclamo(){
  seleccionOpcionMenu = 6;
}

void MenuReclamo::mostrar(){
  int opcion;

  do{

  system("cls");
  opcion = seleccionOpcion();
  system("cls");
  ejecutarOpcion(opcion);
  system("pause");

  }while(opcion!=0);
}

void MenuReclamo::mostrarOpciones(){
    rlutil::locate(45,3);
    rlutil::setColor(rlutil::GREEN);
    cout << " MENU RECLAMO " << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    rlutil::locate(45,5);
    cout << "1. CREAR REGISTRO RECLAMO " << endl;
    rlutil::locate(45,6);
    cout << "2. ACTUALIZAR ESTADO " << endl;
    rlutil::locate(45,7);
    cout << "3. ELIMINAR RECLAMO " <<endl;
    rlutil::locate(45,8);
    cout << "4. ALTA RECLAMO " << endl;
    rlutil::locate(45,9);
    cout << "5. LISTAR PENDIENTES " << endl;
    cout << endl;
    rlutil::locate(45,11);
    cout << "0. SALIR " << endl;
    cout << endl;
}

int MenuReclamo::seleccionOpcion(){
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

void MenuReclamo::ejecutarOpcion(int opc){

  switch(opc){

case 1:
        objeto.crearRegistro();
  break;
case 2:
        objeto.actualizarRegistro();
  break;
case 3:
        objeto.eliminarRegistro();
  break;
  case 4:
        objeto.altaRegistro();
  break;
  case 5:
       objeto.listarPendientes();
  break;
  case 0:
        rlutil::locate(45,3);
        rlutil::setColor(rlutil::GREEN);
        cout << "VOLVIENDO AL MENU PRINCIPAL " << endl;
        rlutil::setColor(rlutil::WHITE);
        return;
  }
}
