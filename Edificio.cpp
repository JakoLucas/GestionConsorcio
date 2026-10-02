#include <iostream>
#include "Edificio.h"
#include <string.h>

using namespace std;


Edificio::Edificio(): _cantidadPisos(0), _cantidadUnidades(0), _nombre(" "), _direccion(" "), _estado(false){}



void Edificio::setCantidadPisos(int pisos){
  if(pisos>-1){
    _cantidadPisos = pisos;  
  }
}
void Edificio::setCantidadUnidades(int unidades){
  if(unidades>-1){
  _cantidadUnidades = unidades;  
  }
}
void Edificio::setNombre(std::string nombre){
  strncpy(_nombre,nombre.c_str(),49);
  _nombre[49] = '\0';
}
void Edificio::setDireccion(std::string direccion){
  strncpy(_direccion,direccion.c_str(),49);
  _direccion[49] = '\0';
}
void Edificio::setEstado(bool estado){
  _estado = estado;
}

int Edificio::getCantidadPisos(){return _cantidadPisos;}
int Edificio::getCantidadUnidades(){return _cantidadUnidades;}
const char* Edificio::getNombre(){return _nombre;}
const char* Edificio::getDireccion(){return _direccion;}
bool Edificio::getEstado(){return _estado;}

void Edificio::cargar(){
  int pisos, unidades;
  string nombre, direccion;
  bool estado;
  cout << "INGRESE LA CANTIDAD DE PISOS: ";
  cin >> pisos;
  cout << "DEPARTAMENTOS: ";
  cin >> unidades;
  cin.ignore();
  cout << "INGRESE EL NOMBRE DEL EDIFICIO: ";
  getline(cin, nombre);
  cout << "INGRESE LA DIRECCION DEL EDIFICIO: ";
  getline(cin, direccion);
  estado = false;
  
  setCantidadPisos(pisos);
  setCantidadUnidades(unidades);
  setNombre(nombre);
  setDireccion(direccion);
  setEstado(estado);
}
void Edificio::modificarDatos(){
  string nombre, direccion;
  
  cin.ignore();
  cout << "INGRESE NOMBRE ";
  getline(cin, nombre);
  cout << "INGRESE DIRECCION ";
  getline(cin, direccion);
  
  setNombre(nombre);
  setDireccion(direccion);

}
void Edificio::mostrar(){
  cout << "PISOS DEL EDIFICIO: " << _cantidadPisos << endl;
  cout << "DEPARTAMENTOS: " << _cantidadUnidades << endl;
  cout << "EL NOMBRE DEL EDIFICIO: " << _nombre << endl;
  cout << "LA DIRECCION ES: " << _direccion << endl;
  cout << "ESTADO: " << _estado << endl;
  cout << endl;
}
