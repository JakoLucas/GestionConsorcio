# include<iostream>
# include "Proveedor.h"
# include <string.h>

using namespace std;

Proveedor::Proveedor(): _cuit(" "), _nombreEmpresa(" "), _telefono(" "), _email(" "), _direccion(" "), _eliminado(false){}

void Proveedor::setCuit(std::string cuit){
  strncpy(_cuit,cuit.c_str(),49);
  _cuit[49] = '\0';
}
void Proveedor::setNombreEmpresa(std::string nombre){
  strncpy(_nombreEmpresa,nombre.c_str(),49);
  _nombreEmpresa[49] = '\0';
}
void Proveedor::setTelefono(std::string telefono){
  strncpy(_telefono,telefono.c_str(),49);
  _telefono[49] = '\0';
}
void Proveedor::setEmail(std::string email){
  strncpy(_email,email.c_str(),49);
  _email[49] = '\0';
}
void Proveedor::setDireccion(std::string direccion){
  strncpy(_direccion,direccion.c_str(),49);
  _direccion[49] = '\0';
}
void Proveedor::setEliminado(bool eliminado){
  _eliminado = eliminado;
}

const char* Proveedor::getCuit(){return _cuit;}
const char* Proveedor::getNombreEmpresa(){return _nombreEmpresa;}
const char* Proveedor::getTelefono(){return _telefono;}
const char* Proveedor::getEmail(){return _email;}
const char* Proveedor::getDireccion(){return _direccion;}
bool Proveedor::getEliminado(){return _eliminado;}

void Proveedor::cargar(){
  string cuit, nombre, telefono, email, direccion;
  bool eliminado;
  
  cout << "INGRESE CUIT PROVEEDOR: ";
  cin >> cuit;
  cout << "INGRESE NOMBRE EMPRESA: ";
  cin >> nombre;
  cout << "INGRESE TELEFONO: ";
  cin >> telefono;
  cout << "INGRESE EMAIL: ";
  cin >> email;
  cout << "INGRESE DIRECCION: ";
  cin >> direccion;
  eliminado = false;
  
  setCuit(cuit);
  setNombreEmpresa(nombre);
  setTelefono(telefono);
  setEmail(email);
  setDireccion(direccion);
  setEliminado(eliminado);
  
}
void Proveedor::mostrar(){
  cout << "CUIT PROVEEDOR: " << _cuit << endl;
  cout << "NOMBRE EMPRESA: " << _nombreEmpresa << endl;
  cout << "TELEFONO: " << _telefono << endl;
  cout << "EMAIL: " << _email << endl;
  cout << "DIRECCION: " << _direccion << endl;
  cout << "ELIMINADO: " << (_eliminado ? "SI" : "NO") << endl;
}
