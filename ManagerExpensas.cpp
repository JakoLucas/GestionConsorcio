# include<iostream>
# include "ManagerExpensas.h"

using namespace std;

void ManagerExpensas::crearExpensa(){
      Expensa obj;
      int id;
      id = expensa.cantidadRegistros();
      if(id != -1){
      obj.setIDExpensa(id+1);
      cout << "ID #" <<id+1 << endl;
      obj.cargar();
      }
      else {id = 1;
       obj.setIDExpensa(id);
      cout << "ID #" <<id<< endl;
      obj.cargar();}
      
      if(expensa.agregarRegistro(obj)){
        cout << "SE AGREGO REGISTRO CORRECTAMENTE " << endl;      
      }
      else {cout << "FALLO LA CARGA DE REGISTRO " << endl;}
}
void ManagerExpensas::buscarRegistro(){
    int id, pos;
    Expensa obj;
    
    cout << "INGRESE ID: ";
    cin >> id;
    
    pos = expensa.buscarRegistro(id);
    if(pos == -1){
      cout << "NO SE ENCONTRO REGISTRO " << endl;
      return;    
    }
    obj = expensa.leerRegistro(pos);
    obj.mostrar();
}

void ManagerExpensas::eliminarRegistro(){
    int id, pos;
    Expensa obj;
    
    cout << "INGRESE ID: ";
    cin >> id;
    
    pos = expensa.buscarRegistro(id);
    if(pos == -1){
      cout << "NO SE ENCONTRO REGISTRO " << endl;
      return;    
    }

    obj = expensa.leerRegistro(pos);
    
    obj.setEliminado(true);
    
    if(expensa.modificarRegistro(obj,pos)){
      cout << "SE MODIFICO REGISTRO " << endl;
    }
    else {cout << "NO SE PUDO MODIFICAR REGISTRO " << endl;}
}
void ManagerExpensas::altaRegistro(){
        int id, pos;
    Expensa obj;
    
    cout << "INGRESE ID: ";
    cin >> id;
    
    pos = expensa.buscarRegistro(id);
    if(pos == -1){
      cout << "NO SE ENCONTRO REGISTRO " << endl;
      return;    
    }

    obj = expensa.leerRegistro(pos);
    
    obj.setEliminado(false);
    
    if(expensa.modificarRegistro(obj,pos)){
      cout << "SE MODIFICO REGISTRO " << endl;
    }
    else {cout << "NO SE PUDO MODIFICAR REGISTRO " << endl;}
}
void ManagerExpensas::listarRegistro(){
    expensa.listarRegistros();
}

void ManagerExpensas::crearExpensaPagada(){
      expensaPagada obj;
      int id;
      
      id = expensaP.cantidadRegistros();
      if(id != -1){
      obj.setIDExpensa(id+1);
      cout << "ID #"<<id+1<<endl;
      obj.cargar();
      }
      else {id = 1;
      obj.setIDExpensa(id);
      cout << "ID #"<<id<<endl;
      obj.cargar();}
      
        if(expensaP.agregarRegistro(obj)){
          cout << "SE AGREGO REGISTRO CORRECTAMENTE " << endl;
          }
          else{cout << "NO SE PUDO AGREGAR REGISTRO " << endl;}
}
void ManagerExpensas::buscarExpensaPagada(){
    int id, pos;
    expensaPagada obj;
    
    cout << "INGRESE ID: ";
    cin >> id;
    
    pos = expensaP.buscarRegistro(id);
    if(pos == -1){
      cout << "NO SE ENCONTRO REGISTRO " << endl;
      return;    
    }
    obj = expensaP.leerRegistro(pos);
    obj.mostrar();
}
void ManagerExpensas::eliminarExpensaPagada(){
    int id, pos;
    expensaPagada obj;
    
    cout << "INGRESE ID: ";
    cin >> id;
    
    pos = expensaP.buscarRegistro(id);
    if(pos == -1){
      cout << "NO SE ENCONTRO REGISTRO " << endl;
      return;    
    }

    obj = expensaP.leerRegistro(pos);
    
    obj.setEliminado(true);
    
    if(expensaP.modificarRegistro(obj,pos)){
      cout << "SE MODIFICO REGISTRO " << endl;
    }
    else {cout << "NO SE PUDO MODIFICAR REGISTRO " << endl;}
}

void ManagerExpensas::altaExpensaPagada(){
    int id, pos;
    expensaPagada obj;
    
    cout << "INGRESE ID: ";
    cin >> id;
    
    pos = expensaP.buscarRegistro(id);
    if(pos == -1){
      cout << "NO SE ENCONTRO REGISTRO " << endl;
      return;    
    }

    obj = expensaP.leerRegistro(pos);
    
    obj.setEliminado(false);
    
    if(expensaP.modificarRegistro(obj,pos)){
      cout << "SE MODIFICO REGISTRO " << endl;
    }
    else {cout << "NO SE PUDO MODIFICAR REGISTRO " << endl;}
}

void ManagerExpensas::listarExpensaPagada(){
    expensaP.listarRegistros();
}
