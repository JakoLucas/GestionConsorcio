# include<iostream>
# include "ManagerEdificio.h"
using namespace std;


bool managerEdificio::crearRegistro(){
    Edificio obj;
    
    int edificio = 0;
    
    edificio = repo.cantidadRegistros();
    
    if(edificio != 1){
      cout << "PUEDE ASIGNAR UN EDIFICIO..." << endl;
      obj.cargar();
        if(repo.agregarEdificio(obj)){
           cout << "EDIFICIO CARGADO " << endl;   
           }else{
            cout << "NO SE PUDO CARGAR EDIFICIO " << endl;}      
    }
    else {cout << "NO SE PUEDEN AGREGAR MAS EDIFICIOS " << endl;}
}

void managerEdificio::buscarDireccion(){
    Edificio obj;
    int pos;
    string direccion;
    
    cout << "INGRESE DIRECCION " << endl;
    cin >> direccion;
    
      pos = repo.buscarEdificioPorDireccion(direccion);
      if(pos>-1){
      obj = repo.leerEdificio(pos);
      obj.mostrar();
      cout << endl;
      }
      else {cout << "NO SE ENCUENTRA EDIFICIO " << endl;}
}

void managerEdificio::modificarRegistro(){
    
    int pos;
    string dire;
    Edificio reg;
    cout << "INGRESE DIRECCION " << endl;
    cin >> dire;
    cout << endl;
    pos = repo.buscarEdificioPorDireccion(dire);
    cout << endl;
    if(pos == -1){
      cout << "NO SE ENCONTRO EDIFICIO " << endl;
      return;    
    }
    reg = repo.leerEdificio(pos);

    reg.modificarDatos();
    if(repo.modificarEdificio(reg,pos)){
        cout << "SE MODIFICÓ CORRECTAMENTE." << endl;
    }
    else {
        cout << "NO SE IDENTIFICÓ EL REGISTRO." << endl;
    }
}

void managerEdificio::listarRegistro(){
   cout << "--- EDIFICIO ---" << endl;
    repo.listarEdificio();
}

void managerEdificio::eliminarRegistro(){
    string direccion;
    int pos;
    cout << "INGRESE DIRECCION " << endl;
    cin >> direccion;
    
     pos = repo.buscarEdificioPorDireccion(direccion);
     
        if(pos>-1){
            if(repo.eliminarEdificio(direccion,pos)){
                cout << "SE ELIMINO EDIFICIO " << endl;            
            }
            else {cout << "NO SE PUDO ELIMINAR" << endl;}        
        }
        else {cout << "NO SE ENCONTRO EDIFICIO " << endl;}
}
void managerEdificio::altaRegistro() {
    int pos;
    string direccion;
    Edificio reg;

    cout << "INGRESE DIRECCION DEL EDIFICIO PARA DAR DE ALTA: ";
    cin >> direccion;

    pos = repo.buscarEdificioPorDireccion(direccion);

    if (pos == -1) {
        cout << "NO SE ENCONTRO NINGUN EDIFICIO CON ESA DIRECCION." << endl;
        return;
    }
    reg = repo.leerEdificio(pos);
    reg.setEstado(false);
    if(repo.modificarEdificio(reg,pos)){
        cout << "EDIFICIO DE ALTA " << endl;
    }
    else {cout << "NO SE PUDO DAR DE ALTA " << endl;}
}
