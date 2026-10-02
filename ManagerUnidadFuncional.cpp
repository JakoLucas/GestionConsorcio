# include<iostream>
# include "ManagerUnidadFuncional.h"

using namespace std;

bool ManagerUnidadFuncional::crearRegistro(){
    int id;
    UnidadFuncional obj;
     
    id = archivoUnidad.cantidadRegistros();
    if(id!= -1){
    cout << "ID #"<<id+1<<endl;
    obj.setIDUnidad(id+1);
    obj.cargar();
    }
    else{
    id = 1;
    cout << "ID #"<<id<<endl;
    obj.setIDUnidad(id);
    obj.cargar();}
    
    if(archivoUnidad.agregarRegistro(obj)){
    
    cout << "REGISTRO CARGADO CORRECTAMENTE " << endl;
    }
    else {cout << "NO SE PUDO CARGAR REGISTRO" << endl;}
}
void ManagerUnidadFuncional::buscarRegistroDNI(){
    string dni;
    int pos;
    cout << "INGRESE DNI A BUSCAR ";
    cin >> dni;
    
    pos = archivoUnidad.buscarUnidadPorDni(dni.c_str());
      if(pos != -1){
            UnidadFuncional obj;
            obj = archivoUnidad.leerRegistro(pos);
            cout << endl;
            obj.mostrar();
        }
      else {cout << "EL DNI NO SE ENCONTRO " << endl;}   
}

void ManagerUnidadFuncional::eliminarRegistro(){
      string dni;
      int pos;
      UnidadFuncional obj;
      
      cout << "INGRESE DNI REGISTRO A ELIMINAR ";
      cin >> dni;
      pos = archivoUnidad.buscarUnidadPorDni(dni.c_str());
      
      if(pos == -1){
        cout << "NO SE ENCONTRO DNI " << endl;
        return;      
      }
      obj = archivoUnidad.leerRegistro(pos);
      obj.setEliminado(true);
      if(archivoUnidad.modificarRegistro(obj,pos)){
        cout << "SE ELIMINO CORRECTAMENTE " << endl;      
      }
      
    else{ cout << "FALLO EN ELIMINAR EL REGISTRO CON EL DNI INGRESADO " << endl; }
      
}
void ManagerUnidadFuncional::altaRegistro(){
      string dni;
      int pos;
      UnidadFuncional obj;
      
      cout << "INGRESE DNI: ";
      cin >> dni;
      pos = archivoUnidad.buscarUnidadPorDni(dni.c_str());
      
      if(pos == -1){
        cout << "NO SE ENCONTRO DNI " << endl;
        return;      
      }
      obj = archivoUnidad.leerRegistro(pos);
    if(obj.getEliminado()==true){
      obj.setEliminado(false);
      if(archivoUnidad.modificarRegistro(obj,pos)){
        cout << "SE DIO DE ALTA CORRECTAMENTE " << endl;      
      }
      else{ cout << "FALLO EN ELIMINAR EL REGISTRO CON EL DNI INGRESADO " << endl;}
}
    else{ cout << "EL DNI ESTA DE ALTA " << endl;}
}
void ManagerUnidadFuncional::listarRegistro(){
    archivoUnidad.listarUnidades();
}
