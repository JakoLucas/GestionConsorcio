# include<iostream>
# include "MenuServicio.h"
# include "rlutil.h"
using namespace std;

MenuServicio::MenuServicio(){

  seleccionOpcionMenu = 6;
}

void MenuServicio::mostrar(){
  int opcion;

  do{

  system("cls");
  opcion = seleccionOpcion();
  system("cls");
  ejecutarOpcion(opcion);
  system("pause");

  }while(opcion!=0);
}

void MenuServicio::mostrarOpciones(){
    rlutil::locate(45,3);
    rlutil::setColor(rlutil::GREEN);
    cout << " MENU SERVICIO PROVEEDOR " << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    rlutil::locate(45,5);
    cout << "1. AGREGAR SERVICIO " << endl;
    rlutil::locate(45,6);
    cout << "2. BUSCAR SERVICIO " << endl;
    rlutil::locate(45,7);
    cout << "3. ELIMINAR REGISTRO " <<endl;
    rlutil::locate(45,8);
    cout << "4. ALTA REGISTRO " << endl;
    rlutil::locate(45,9);
    cout << "5. LISTAR PROVEEDORES " << endl;
    cout << endl;
    rlutil::locate(45,11);
    cout << "0. SALIR " << endl;
}

int MenuServicio::seleccionOpcion(){
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

void MenuServicio::ejecutarOpcion(int opc){

  switch(opc){

case 1:
        obj.crearServicio();
  break;
case 2:
        obj.buscarRegistro();
  break;
case 3:
        obj.eliminarRegistro();
  break;
  case 4:
        obj.altaRegistro();
  break;
  case 5:
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
