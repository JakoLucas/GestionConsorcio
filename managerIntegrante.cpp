# include<iostream>
#include "managerIntegrante.h"
# include <string.h>

using namespace std;

bool managerIntegrante::crearRegistro(){

Residente obj;

obj.cargar();

if(repo.agregarResidente(obj)){
  cout << "SE AGREGO CORRECTAMENTE " << endl;
}
  else{cout << "NO SE PUDO AGREGAR RESIDENTE" << endl;}

}

void managerIntegrante::buscarRegistroDNI(){
    char dni[30];

    cout << "INGRESE DNI DEL RESIDENTE A BUSCAR " << endl;
    cin >> dni;

    if(!repo.buscarResidentePorDNI(dni)){
        cout << "NO SE PUDO ENCONTRAR EL DNI INGRESADO" << endl;
    }
}

void managerIntegrante::modificarRegistro(){
    char dni[30];
    int registro;
    Residente reg;
    cout << "INGRESE DNI PARA IDENTIFICAR REGISTRO " << endl;
    cin >> dni;
    cout << endl;
    registro = repo.buscarResidente(dni);
    cout << endl;
    reg = repo.leerResidente(registro);

    if(strcmp(reg.getDNI(),dni)==0 && reg.getEliminado()==false){
    reg.cargar();
    if(repo.modificarResidente(reg,registro)){
        cout << "SE MODIFICO CORRECTAMENTE" << endl;
        }
    }
    else{cout << "NO SE IDENTIFICO EL REGISTRO" << endl;}
}

void managerIntegrante::listarRegistro(){
    repo.listarResidentes();
}

void managerIntegrante::eliminarRegistro(){
    char dni[30];
    cout << "DNI A ELIMINAR: " << endl;
    cin >> dni;

    if(repo.eliminarResidente(dni)){
        cout << "SE ELIMINO CORRECTAMENTE" << endl;
    }
    else {cout << "NO SE PUDO ELIMINAR EL DNI RESIDENTE" << endl;}
}
void managerIntegrante::altaRegistro(){
    char dni[30];
    int pos;
    Residente reg;
    cout << "INGRESE DNI PARA DAR DE ALTA" << endl;
    cin >> dni;

    pos = repo.buscarResidente(dni);
    if(pos == -1){
      cout << "NO SE ENCONTRO DNI INTEGRANTE " << endl;
      return;    
    }
    
    reg = repo.leerResidente(pos);
    
    if(reg.getEliminado()== true){
    
      reg.setEliminado(false);
      
    if(repo.modificarResidente(reg,pos)){
        
    cout << "REGISTRO DADO DE ALTA CORRECTAMENTE" << endl;
    }else { cout << "NO SE PUDO DAR DE ALTA EL REGISTRO " << endl;}
    
  }
}
