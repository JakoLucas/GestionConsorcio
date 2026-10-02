# include<iostream>


using namespace std;

CopiaSeguridadMenu::CopiaSeguridadMenu(){

  seleccionOpcionMenu = 4;
}

void CopiaSeguridadMenu::mostrar(){
  int opcion;

  do{

  system("cls");
  opcion = seleccionOpcion();
  system("cls");
  ejecutarOpcion(opcion);
  system("pause");

  }while(opcion!=0);
}

void CopiaSeguridadMenu::mostrarOpciones(){
    rlutil::locate(45,3);
    rlutil::setColor(rlutil::GREEN);
    cout << " CONFIGURACION SISTEMA " << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    rlutil::locate(45,5);
    cout << "1. Copia de Seguridad " << endl;
    rlutil::locate(45,6);
    cout << "2. Restaurar copia de Seguridad " << endl;
    rlutil::locate(45,7);
    cout << "3. Exportar datos (CSV) " << endl;
    cout << endl;
    rlutil::locate(45,9);
    cout << "0. SALIR " << endl;
    cout << endl;
}

int CopiaSeguridadMenu::seleccionOpcion(){
    int opc;
    mostrarOpciones();
    rlutil::locate(45,11);
    cout << "INGRESE OPCION: ";
    cin >> opc;

    while(opc < 0 || opc > seleccionOpcionMenu){
        rlutil::locate(45,10);
        rlutil::setColor(rlutil::RED);
        cout << "SELECCION INCORRECTA " <<endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(45,11);
        cout << "INGRESE OPCION: ";
        cin >> opc;
    }
        return opc;
}

void CopiaSeguridadMenu::ejecutarOpcion(int opc){

  switch(opc){

case 1:
      
  break;
case 2:
       
  break;
case 3:
      
  break;
case 0:
        cout << "VOLVIENDO AL MENU PRINCIPAL " << endl;
        return;

  }
}

