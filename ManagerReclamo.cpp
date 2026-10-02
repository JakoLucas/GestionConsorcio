# include<iostream>
# include "ManagerReclamo.h"

using namespace std;

void ManagerReclamo::crearRegistro(){
    Reclamo obj;
    int registros;
    registros = archivoReclamo.cantidadRegistros();
    obj.setIDReclamo(registros+1);
    cout << "ID #"<<registros+1<<endl;
    obj.cargar();
    
    if(archivoReclamo.agregarReclamo(obj)){
      cout << "SE AGREGO REGISTRO CON EXITO" << endl;    
    }
    else {cout << "NO SE PUDO AGREGAR REGISTRO" << endl;}
}

void ManagerReclamo::eliminarRegistro(){
      int id,pos;
      Reclamo obj;
      
      cout << "INGRESE ID RECLAMO A ELIMINAR ";
      cin >> id;
      if(archivoReclamo.isExist(id)){
        pos = archivoReclamo.buscarUnidad(id);  
        obj = archivoReclamo.leerRegistro(pos);
        obj.setEliminado(true);
        if(archivoReclamo.modificarReclamo(obj,pos)){
        cout << "SE ELIMINO CORRECTAMENTE " << endl;      
        }
      
    else{ cout << "FALLO EN ELIMINAR EL REGISTRO CON EL DNI INGRESADO " << endl;}
      }
      
      else {cout << "NO EXISTE EL ID DE RECLAMO " << endl;}
}
void ManagerReclamo::altaRegistro(){
      int id, pos;
      Reclamo obj;
      
      cout << "INGRESE ID: ";
      cin >> id;
      if(archivoReclamo.isExist(id)){
       pos = archivoReclamo.buscarUnidad(id);
       obj = archivoReclamo.leerRegistro(pos);
         if(obj.getEliminado()==true){
          obj.setEliminado(false);
             if(archivoReclamo.modificarReclamo(obj,pos)){
        cout << "SE DIO DE ALTA CORRECTAMENTE " << endl;      
      }
        else{ cout << "NO SE PUDO DAR DE ALTA AL REGISTRO " << endl;}
    }
            else{ cout << "EL ID RECLAMO YA ESTA EN ALTA " << endl;}
      }
      else {cout << "EL ID NO EXISTE" << endl;}
      
}
void ManagerReclamo::actualizarRegistro(){
      int pos, id, estado;
      
      Reclamo obj;
      
      cout << "INGRESE ID DE ESTADO A MODIFICAR ";
      cin >> id;
      
      if(archivoReclamo.isExist(id)){
          
          pos = archivoReclamo.buscarUnidad(id);
          obj = archivoReclamo.leerRegistro(pos);   
          cout << "INGRESE ESTADO: 1. PENDIENTE - 2. EN PROCESO - 3. RESUELTO ";
          cin >> estado;
          if(estado >= 1 && estado <=3){
          obj.setEstado(estado);
            if(archivoReclamo.modificarReclamo(obj, pos)){
            cout << "ESTADO MODIFICADO " << endl;          
            }
            else{cout << "SURGIO UN ERROR EN LA MODIFICACION" << endl;}
          }
          else {cout << "ESTADO ERRONEO " << endl;}   
      }
      else{ cout << "LA ID INGRESADA NO EXISTE " << endl;}
}
void ManagerReclamo::listarPendientes(){
    archivoReclamo.listarPendiente(1);
}
