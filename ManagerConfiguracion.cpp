# include<iostream>
# include "ManagerConfiguracion.h"

using namespace std;

void ManagerConfiguracion::crearCopia(){
      int num, contador = 0;
      
      num = textoCopia();
      
      if(num==1){
      
      if(aEdificio.backupCopia()){
          contador++;      
      }
      
      if(aTitular.backupCopia()){
          contador++;
      }
      if(aResidente.backupCopia()){
          contador++;
      }
      if(aUnidad.backupCopia()){
          contador++;      
      }
      if(aExpensa.backupCopia()){
          contador++;      
      }
      if(aExpensaPagada.backupCopia()){
          contador++;      
      }
      if(aReclamo.backupCopia()){
          contador++;      
      }
      if(aServicio.backupCopia()){
          contador++;      
      }
      
      if(contador==8){
          rlutil::locate(35,7);
          rlutil::setColor(rlutil::GREEN);
          cout << "SE REALIZO COPIA DE SEGURIDAD CON EXITO!!" << endl;
          rlutil::setColor(rlutil::WHITE);
      }
      else{
          rlutil::locate(35,7);
          rlutil::setColor(rlutil::RED);
          cout << "NO SE PUDO HACER LA COPIA DE SEGURIDAD DE LOS ARCHIVOS " << endl;
          rlutil::setColor(rlutil::WHITE);
      }
    }else{
      rlutil::setColor(rlutil::RED);
      rlutil::locate(45,6);
      cout << "NO SE REALIZO COPIA " << endl;
      rlutil::setColor(rlutil::RED);}
}

void ManagerConfiguracion::restaurarCopia(){
      int contador = 0;
  if(textoRestauracion()){
      
      if(aEdificio.restaurarBackup()){
          contador++;      
      }
      if(aTitular.restaurarBackup()){
          contador++;      
      }
      if(aResidente.restaurarBackup()){
          contador++;      
      }
      if(aUnidad.restaurarBackup()){
          contador++;      
      }
      if(aExpensa.restaurarBackup()){
          contador++;      
      }
      if(aExpensaPagada.restaurarBackup()){
          contador++;      
      }
      if(aReclamo.restaurarBackup()){
          contador++;      
      }
      if(aServicio.restaurarBackup()){
          contador++;      
      }
      
        if(contador==8){
          rlutil::locate(35,9);
          rlutil::setColor(rlutil::GREEN);
          cout << "PROCESO DE RESTAURACION FINALIZADO CON EXITO." << endl;
          rlutil::setColor(rlutil::WHITE);
          }
        else {
            rlutil::locate(35,9);
            rlutil::setColor(rlutil::RED);
            cout << "FALLO LA RESTAURACION..." << endl;
            rlutil::setColor(rlutil::WHITE);}
          }
else{ 
      rlutil::locate(35,9);
      rlutil::setColor(rlutil::RED);
      cout << "INTENTELO NUEVAMENTE " << endl;
      rlutil::setColor(rlutil::WHITE);}
      cout << endl;
}

bool ManagerConfiguracion::textoRestauracion(){
      int codigo;
      rlutil::locate(45,2);
      rlutil::setColor(rlutil::GREEN);
      cout << " CONFIGURACION " << endl;
      rlutil::locate(45,3);
      rlutil::setColor(rlutil::GREY);
      cout <<"----------------"<< endl;
      cout << endl;
      rlutil::locate(35,5);
      rlutil::setColor(rlutil::YELLOW);
      cout << "INGRESE EL SIGUIENTE CODIGO PARA RESTAURAR TODOS LOS ARCHIVOS " << endl;
      rlutil::locate(35,6);
      rlutil::setColor(rlutil::YELLOW);
      cout << "CODIGO: ";
      rlutil::setColor(rlutil::GREY);
      cout <<"28109" << endl;
      rlutil::locate(35,7);
      rlutil::setColor(rlutil::WHITE);
      cin >> codigo;
    if(codigo != 28109){
        rlutil::locate(35,7);
        rlutil::setColor(rlutil::RED);
        cout << "CODIGO INCORRECTO... " << endl;
        rlutil::setColor(rlutil::WHITE);
        return false;      
      }
    else{rlutil::locate(35,7);
        rlutil::setColor(rlutil::YELLOW);
        cout << "REALIZANDO RESTAURACION..." << endl;
        rlutil::setColor(rlutil::WHITE);
        return true;}
}

int ManagerConfiguracion::textoCopia(){
      int confirmacion;
      rlutil::locate(45,3);
      rlutil::setColor(rlutil::GREEN);
      cout << " CONFIGURACION " << endl;
      rlutil::locate(45,4);
      rlutil::setColor(rlutil::GREY);
      cout <<"----------------"<< endl;
      rlutil::locate(35,5);
      cout << "QUIERE REALIZAR LA COPIA DE SEGURIDAD ";
      rlutil::setColor(rlutil::GREEN);
      cout <<" (1. SI - 2. NO)" << endl;
       rlutil::locate(35,6);
      cin >> confirmacion;
      if(confirmacion == 1){
      rlutil::locate(35,6);
      rlutil::setColor(rlutil::YELLOW);
      cout << "REALIZANDO UNA COPIA DE TODOS LOS ARCHIVOS..." << endl;
      rlutil::setColor(rlutil::WHITE);
      cout << endl;
      system("pause");
      return confirmacion;
      }
      
      return confirmacion;
}

void ManagerConfiguracion::toCsv(){
      int opc;
      opc = textoCsv();
      if(opc == 1){
      
          if(aTitular.exportarToCsv()){
            cout << endl;
            rlutil::locate(35,8);
            rlutil::setColor(rlutil::GREEN);
            cout << "SE EXPORTO CSV CON EXITO!" << endl;
            cout << endl;
            rlutil::setColor(rlutil::WHITE);
            }
          else {
              cout << endl;
              rlutil::locate(35,8);
              rlutil::setColor(rlutil::RED);
              cout << "FALLO LA EXPORTACION " << endl;
              cout << endl;}
        }
      else{
          cout << endl;
          rlutil::locate(35,8);
          rlutil::setColor(rlutil::YELLOW);
          cout << "VOLVIENDO AL MENU DE CONFIGURACION " << endl;
          rlutil::setColor(rlutil::WHITE);
          cout << endl;
          return;}
}

int ManagerConfiguracion::textoCsv(){
    int confirmacion;
    rlutil::locate(45,3);
    rlutil::setColor(rlutil::GREEN);
    cout << "CONFIGURACION " << endl;
    rlutil::locate(45,4);
    rlutil::setColor(rlutil::GREY);
    cout <<"----------------" << endl;
    rlutil::locate(35,6);
    rlutil::setColor(rlutil::GREY);
    cout << "Quiere exportar los titulares a un archivo CSV ";
    rlutil::setColor(rlutil::YELLOW);
    cout << "1. SI - 2. NO";
    rlutil::locate(35,8);
    rlutil::setColor(rlutil::GREY);
    cin >> confirmacion;
    rlutil::setColor(rlutil::WHITE);
    if(confirmacion != 1){
        return 2;
    }
    else {return 1;}
}
