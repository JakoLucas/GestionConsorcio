# include<iostream>
# include "MenuUnidadFuncional.h"
# include "rlutil.h"

using namespace std;

MenuUnidadFuncional::MenuUnidadFuncional(){

  seleccionOpcionMenu = 6;
}

void MenuUnidadFuncional::mostrar(){
  int opcion;

  do{

  system("cls");
  opcion = seleccionOpcion();
  system("cls");
  ejecutarOpcion(opcion);
  system("pause");

  }while(opcion!=0);
}

void MenuUnidadFuncional::mostrarOpciones(){
    rlutil::locate(45,3);
    rlutil::setColor(rlutil::GREEN);
    cout << " MENU UNIDAD FUNCIONAL " << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    rlutil::locate(45,5);
    cout << "1. CREAR REGISTRO UNIDAD FUNCIONAL " << endl;
    rlutil::locate(45,6);
    cout << "2. BUSCAR POR DNI" <<endl;
    rlutil::locate(45,7);
    cout << "3. ELIMINAR UNIDAD" << endl;
    rlutil::locate(45,8);
    cout << "4. ALTA UNIDAD" << endl;
    rlutil::locate(45,9);
    cout << "5. LISTAR TODOS" << endl;
    cout << endl;
    rlutil::locate(45,11);
    cout << "0. SALIR " << endl;
    cout << endl;
}

int MenuUnidadFuncional::seleccionOpcion(){
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

void MenuUnidadFuncional::ejecutarOpcion(int opc){

  switch(opc){

case 1:
        obj.crearRegistro();
  break;
case 2:
        obj.buscarRegistroDNI();
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
        rlutil::setColor(rlutil::GREEN);
        rlutil::locate(45,3);
        cout << "VOLVIENDO AL MENU PRINCIPAL " << endl;
        rlutil::setColor(rlutil::WHITE);
        return;
  }
}
