# include<iostream>
# include "menuTitular.h"
# include "rlutil.h"

using namespace std;

menuTitular::menuTitular(){

  seleccionOpcionMenu = 8;
}

void menuTitular::mostrar(){
  int opcion;

  do{

  system("cls");
  opcion = seleccionOpcion();
  system("cls");
  ejecutarOpcion(opcion);
  system("pause");

  }while(opcion!=0);
}

void menuTitular::mostrarOpciones(){
    rlutil::locate(45,3);
    rlutil::setColor(rlutil::GREEN);
    cout << " MENU TITULAR " << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    rlutil::locate(45,5);
    cout << "1. CREAR REGISTRO TITULAR " << endl;
    rlutil::locate(45,6);
    cout << "2. BUSCAR POR DNI " << endl;
    rlutil::locate(45,7);
    cout << "3. BUSCAR POR APELLIDO " << endl;
    rlutil::locate(45,8);
    cout << "4. MODIFICAR TITULAR " << endl;
    rlutil::locate(45,9);
    cout << "5. ELIMINAR TITULAR " << endl;
    rlutil::locate(45,10);
    cout << "6. ALTA TITULAR " << endl;
    rlutil::locate(45,11);
    cout << "7. LISTAR TODOS " << endl;
    cout << endl;
    rlutil::locate(45,13);
    cout << "0. SALIR " << endl;
    cout << endl;
}

int menuTitular::seleccionOpcion(){
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

void menuTitular::ejecutarOpcion(int opc){

  switch(opc){

case 1:
        obj.crearRegistro();
  break;
case 2:
        obj.buscarRegistroDNI();
  break;
case 3:
        obj.buscarRegistroApellido();
  break;
  case 4:
        obj.modificarRegistro();
  break;
  case 5:
       obj.eliminarRegistro();
  break;
  case 6:
        obj.altaRegistro();
    break;
  case 7:
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
