# include<iostream>
# include "MenuEdificio.h"
# include "rlutil.h"

using namespace std;

MenuEdificio::MenuEdificio(){

  seleccionOpcionMenu = 7;
}

void MenuEdificio::mostrar(){
  int opcion;

  do{

  system("cls");
  opcion = seleccionOpcion();
  system("cls");
  ejecutarOpcion(opcion);
  system("pause");

  }while(opcion!=0);
}

void MenuEdificio::mostrarOpciones(){
    rlutil::locate(45,3);
    rlutil::setColor(rlutil::GREEN);
    cout << " MENU EDIFICIO " << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    rlutil::locate(45,5);
    cout << "1. CREAR REGISTRO EDIFICIO " << endl;
    rlutil::locate(45,6);
    cout << "2. BUSCAR POR DIRECCION " <<endl;
    rlutil::locate(45,7);
    cout << "3. MODIFICAR EDIFICIO " << endl;
    rlutil::locate(45,8);
    cout << "4. ELIMINAR EDIFICIO " << endl;
    rlutil::locate(45,9);
    cout << "5. ALTA EDIFICIO " << endl;
    rlutil::locate(45,10);
    cout << "6. LISTAR TODOS " << endl;
    cout << endl;
    rlutil::locate(45,12);
    cout << "0. SALIR " << endl;
    cout << endl;
}

int MenuEdificio::seleccionOpcion(){
    int opc;
    mostrarOpciones();
    rlutil::locate(45,14);
    cout << "INGRESE OPCION: ";
    cin >> opc;

    while(opc < 0 || opc > seleccionOpcionMenu){
        rlutil::locate(45,13);
        rlutil::setColor(rlutil::RED);
        cout << "SELECCION INCORRECTA " <<endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(45,14);
        cout << "INGRESE OPCION: ";
        cin >> opc;
    }
        return opc;
}

void MenuEdificio::ejecutarOpcion(int opc){

  switch(opc){

  case 1:
        obj.crearRegistro();
  break;
  case 2:
        obj.buscarDireccion();
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
        rlutil::setColor(rlutil::GREEN);
        rlutil::locate(45,3);
        cout << "VOLVIENDO AL MENU PRINCIPAL " << endl;
        rlutil::setColor(rlutil::WHITE);
        return;

  }
}
