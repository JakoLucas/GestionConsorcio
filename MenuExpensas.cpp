# include<iostream>
# include "MenuExpensas.h"
# include "rlutil.h"

using namespace std;
MenuExpensas::MenuExpensas(){

  seleccionOpcionMenu = 11;
}

void MenuExpensas::mostrar(){
  int opcion;

  do{

  system("cls");
  opcion = seleccionOpcion();
  system("cls");
  ejecutarOpcion(opcion);
  system("pause");

  }while(opcion!=0);
}

void MenuExpensas::mostrarOpciones(){
    rlutil::locate(45,3);
    rlutil::setColor(rlutil::GREEN);
    cout << " MENU FACTURAS DE EXPENSAS Y GESTION PAGOS " << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    rlutil::locate(45,5);
    cout << "1. AGREGAR EXPENSA " << endl;
    rlutil::locate(45,6);
    cout << "2. BUSCAR EXPENSA " << endl;
    rlutil::locate(45,7);
    cout << "3. ELIMINAR EXPENSA " <<endl;
    rlutil::locate(45,8);
    cout << "4. ALTA EXPENSA " << endl;
    rlutil::locate(45,9);
    cout << "5. LISTAR EXPENSAS " << endl;
    cout << endl;
    rlutil::locate(45,11);
    rlutil::setColor(rlutil::GREEN);
    cout << "------------------------" << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    rlutil::locate(45,13);
    cout << "6. CREAR REGISTRO EXPENSA PAGO " << endl;
    rlutil::locate(45,14);
    cout << "7. BUSCAR EXPENSA PAGA " << endl;
    rlutil::locate(45,15);
    cout << "8. ELIMINAR EXPENSA PAGA " << endl;
    rlutil::locate(45,16);
    cout << "9. ALTA EXPENSA PAGA " << endl;
    rlutil::locate(45,17);
    cout <<"10. LISTAR EXPENSAS PAGADAS " << endl;
    cout << endl;
    rlutil::locate(45,19);
    cout << "0. SALIR " << endl;
    cout << endl;
}

int MenuExpensas::seleccionOpcion(){
    int opc;
    mostrarOpciones();
    rlutil::locate(45,21);
    cout << "INGRESE OPCION: ";
    cin >> opc;

    while(opc < 0 || opc > seleccionOpcionMenu){
        rlutil::locate(45,20);
        rlutil::setColor(rlutil::RED);
        cout << "SELECCION INCORRECTA " <<endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(45,21);
        cout << "INGRESE OPCION: ";
        cin >> opc;
    }
        return opc;
}

void MenuExpensas::ejecutarOpcion(int opc){

  switch(opc){

case 1:
        obj.crearExpensa();
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
  case 6:
        obj.crearExpensaPagada();
    break;
  case 7:
        obj.buscarExpensaPagada();
  break;
  case 8:
        obj.eliminarExpensaPagada();
  break;
  case 9:
        obj.altaExpensaPagada();
  break;
  case 10:
        obj.listarExpensaPagada();
  break;
  case 0:
        rlutil::locate(45,3);
        rlutil::setColor(rlutil::GREEN);
        cout << "VOLVIENDO AL MENU PRINCIPAL " << endl;
        rlutil::setColor(rlutil::WHITE);
        return;

  }
}
