# include<iostream>
# include "menuResidente.h"
# include "rlutil.h"

using namespace std;

menuResidente::menuResidente(){

  seleccionOpcionMenu = 7;
}

void menuResidente::mostrar(){
  int opcion;

  do{

  system("cls");
  opcion = seleccionOpcion();
  system("cls");
  ejecutarOpcion(opcion);
  system("pause");

  }while(opcion!=0);
}

void menuResidente::mostrarOpciones(){
    rlutil::locate(45,3);
    rlutil::setColor(rlutil::GREEN);
    cout << " MENU RESIDENTE " << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    rlutil::locate(45,5);
    cout << "1. CREAR REGISTRO RESIDENTE " << endl;
    rlutil::locate(45,6);
    cout << "2. BUSCAR POR DNI " << endl;
    rlutil::locate(45,7);
    cout << "3. MODIFICAR RESIDENTE " << endl;
    rlutil::locate(45,8);
    cout << "4. ELIMINAR RESIDENTE " << endl;
    rlutil::locate(45,9);
    cout << "5. ALTA RESIDENTE " << endl;
    rlutil::locate(45,10);
    cout << "6. LISTAR TODOS " << endl;
    cout << endl;
    rlutil::locate(45,11);
    cout << "0. SALIR " << endl;
    cout << endl;
}

int menuResidente::seleccionOpcion(){
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

void menuResidente::ejecutarOpcion(int opc){

  switch(opc){

case 1:
        obj.crearRegistro();
  break;
case 2:
        obj.buscarRegistroDNI();
  break;
  case 3:
        obj.modificarRegistro();
  break;
  case 4:
       obj.eliminarRegistro();
  break;
  case 5:
        obj.altaRegistro();
    break;
  case 6:
        obj.listarRegistro();
  break;
  case 0:
        rlutil::locate(45,3);
        rlutil::setColor(rlutil::GREEN);
        cout << "VOLVIENDO AL MENU PRINCIPAL " << endl;
        rlutil::setColor(rlutil::WHITE);
        return;

  }
}
