# include<iostream>
# include "Servicio.h"
# include <string.h>

using namespace std;

Servicio::Servicio(): _idServicio(0), _tipoServicio(0), _estado(0), _costoMensual(0), _empresaProveedor(" "), _eliminado(false){}

void Servicio::setIDServicio(int id){

  _idServicio = id;  
}
void Servicio::setTipoServicio(int servicio){

  _tipoServicio = servicio;  

}
void Servicio::setEstado(int estado){
  if(estado>0 && estado <3){
  _estado = estado;  
  }
}
void Servicio::setCostoMensual(float costo){
  if(costo>-1){
  _costoMensual = costo;  
  }
}
void Servicio::setEmpresaProveedor(std::string proveedor){
  strncpy(_empresaProveedor,proveedor.c_str(),49);
  _empresaProveedor[49] = '\0';
}
void Servicio::setEliminado(bool eliminado){
  _eliminado = eliminado;
}

int Servicio::getIDServicio(){return _idServicio;}
int Servicio::getTipoServicio(){return _tipoServicio;}
int Servicio::getEstado(){return _estado;}
float Servicio::getCostoMensual(){return _costoMensual;}
const char* Servicio::getEmpresaProveedor(){return _empresaProveedor;}
bool Servicio::getEliminado(){return _eliminado;}

void Servicio::cargar(){
  int servicio, estado;
  float costo;
  string proveedor;
  bool eliminado;

  cout << "INGRESE TIPO SERVICIO: ";
  cin >> servicio;
  cout << "ESTADO (1. ACTIVO - 2. INACTIVO): ";
  cin >> estado;
  cout << "INGRESE COSTO MENSUAL: ";
  cin >> costo;
  cin.ignore();
  cout << "INGRESE NOMBRE EMPRESA PROVEEDOR: ";
  getline(cin, proveedor);
  eliminado = false;
  
  setTipoServicio(servicio);
  setEstado(estado);
  setCostoMensual(costo);
  setEmpresaProveedor(proveedor);
  setEliminado(eliminado);
}
void Servicio::mostrar(){

  cout << "ID SERVICIO: " << _idServicio << endl;
  cout << "TIPO SERVICIO: " << _tipoServicio << endl;
  cout << "ESTADO SERVICIO: " << (_estado ? "ACTIVO" : "INACTIVO") << endl;
  cout << "COSTO MENSUAL: " << _costoMensual << endl;
  cout << "EMPRESA PROVEEDOR: " << _empresaProveedor << endl;
}
