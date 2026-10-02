# include<iostream>
# include "ManagerServicio.h"

using namespace std;


void ManagerServicio::crearServicio(){
      Servicio obj;
      int registros;
      registros = archiReg.cantidadRegistros();
      obj.setIDServicio(registros+1);
      cout << "ID #"<<registros+1<<endl;
      obj.cargar();
      
        if(archiReg.agregarRegistro(obj)){
            cout << "Servicio CARGADO CON EXITO " <<endl;        
      }
      else {cout << "NO SE PUDO CARGAR SERVICIO " << endl;}
}
void ManagerServicio::buscarRegistro(){
    int id, pos;
    Servicio obj;
    
    cout << "INGRESE ID: ";
    cin >> id;
    
    pos = archiReg.buscarRegistro(id);
    if(pos == -1){
      cout << "NO SE ENCONTRO REGISTRO " << endl;
      return;    
    }
    obj = archiReg.leerRegistro(pos);
    obj.mostrar();
}

void ManagerServicio::eliminarRegistro(){
    int id, pos;
    Servicio obj;
    
    cout << "INGRESE ID: ";
    cin >> id;
    
    pos = archiReg.buscarRegistro(id);
    if(pos == -1){
      cout << "NO SE ENCONTRO REGISTRO " << endl;
      return;    
    }

    obj = archiReg.leerRegistro(pos);
    
    obj.setEliminado(true);
    
    if(archiReg.modificarRegistro(obj,pos)){
      cout << "SE MODIFICO REGISTRO " << endl;
    }
    else {cout << "NO SE PUDO MODIFICAR REGISTRO " << endl;}
}

void ManagerServicio::altaRegistro(){
      int id, pos;
    Servicio obj;
    
    cout << "INGRESE ID: ";
    cin >> id;
    
    pos = archiReg.buscarRegistro(id);
    if(pos == -1){
      cout << "NO SE ENCONTRO REGISTRO " << endl;
      return;    
    }

    obj = archiReg.leerRegistro(pos);
    
    obj.setEliminado(false);
    
    if(archiReg.modificarRegistro(obj,pos)){
      cout << "SE MODIFICO REGISTRO " << endl;
    }
    else {cout << "NO SE PUDO MODIFICAR REGISTRO " << endl;}
}

void ManagerServicio::listarRegistro(){
    archiReg.listarRegistros();
}
