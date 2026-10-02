# include<iostream>
#include "managerTitulares.h"
# include <string.h>

using namespace std;

bool managerTitulares::crearRegistro(){
Titular obj;
obj.cargar();
  if(repo.agregarTitular(obj)){
    cout << "SE AGREGO TITULAR " << endl;
  }
  else{cout << "NO SE PUDO AGREGAR TITULAR " << endl;}
}

void managerTitulares::buscarRegistroDNI(){
    char dni[30];

    cout << "INGRESE DNI DEL TITULAR A BUSCAR " << endl;
    cin >> dni;

    if(!repo.buscarTitularPorDNI(dni)){
        cout << "NO SE PUDO ENCONTRAR EL DNI INGRESADO" << endl;
    }
}

void managerTitulares::buscarRegistroApellido(){
    char apellido[30];

    cout << "INGRESE EL APELLIDO DEL TITULAR A BUSCAR " << endl;
    cin >> apellido;

    if(!repo.buscarTitularPorApellido(apellido)){
        cout << "NO SE PUDO ENCONTRAR EL APELLIDO INGRESADO" << endl;
    }
}

void managerTitulares::modificarRegistro(){
    char dni[30];
    int registro;
    Titular reg;
    cout << "INGRESE DNI PARA IDENTIFICAR REGISTRO " << endl;
    cin >> dni;
    cout << endl;
    registro = repo.buscarTitular(dni);
    cout << endl;
    reg = repo.leerTitular(registro);

    if(strcmp(reg.getDNI(),dni)==0 && reg.getEliminado()==false){
    reg.cargar();
    if(repo.modificarTitular(reg,registro)){
        cout << "SE MODIFICO CORRECTAMENTE" << endl;
        }
    }
    else{cout << "NO SE IDENTIFICO EL REGISTRO" << endl;}
}

void managerTitulares::listarRegistro(){
    repo.listarTitulares();
}

void managerTitulares::eliminarRegistro(){
    char dni[30];
    cout << "DNI A ELIMINAR: " << endl;
    cin >> dni;

    if(repo.eliminarTitular(dni)){
        cout << "SE ELIMINO CORRECTAMENTE" << endl;
    }
    else {cout << "NO SE ENCONTRO DNI INGRESADO" << endl;}
}
void managerTitulares::altaRegistro(){
    char dni[30];
    int pos;
    Titular reg;
    cout << "INGRESE DNI PARA DAR DE ALTA" << endl;
    cin >> dni;

    pos = repo.buscarTitular(dni);
    if(pos == -1){
    cout << "NO SE ENCONTRO DNI " << endl;
    return;    
    }
    
    reg = repo.leerTitular(pos);
    
    if(reg.getEliminado() == true){
    reg.setEliminado(false);
    if(repo.modificarTitular(reg,pos)){
        cout << "REGISTRO DADO DE ALTA CORRECTAMENTE" << endl;
    }
    else { cout << "NO SE PUDO DAR DE ALTA EL REGISTRO " << endl;}
  }
}
