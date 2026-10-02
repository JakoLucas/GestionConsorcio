# include<iostream>
# include <string.h>
# include "persona.h"


using namespace std;

persona::persona(): _dni(" "), _nombre(" "), _apellido(" "){}
void persona::setDNI(string dni){
strncpy(_dni,dni.c_str(),49);
_dni[49] = '\0';
}
void persona::setNombre(string nombre){
strncpy(_nombre,nombre.c_str(),49);
_nombre[49] = '\0';
}
void persona::setApellido(string apellido){
strncpy(_apellido,apellido.c_str(),49);
_apellido[49] = '\0';
}

const char* persona::getDNI(){return _dni;}
const char* persona::getNombre(){return _nombre;}
const char* persona::getApellido(){return _apellido;}

void persona::cargar(){
string dni, nombre, apellido;

cout << "INGRESE DNI: ";
cin >> dni;
cout << "INGRESE NOMBRE: ";
cin >> nombre;
cout << "INGRESE APELLIDO: ";
cin >> apellido;

setDNI(dni);
setNombre(nombre);
setApellido(apellido);

}
void persona::mostrar(){
cout << "DNI: " << _dni << endl;
cout << "NOMBRE: " << _nombre << endl;
cout << "APELLIDO: " << _apellido << endl;
}
