# include<iostream>
# include "Titular.h"
# include <string.h>

using namespace std;


Titular::Titular(): _piso(0), _departamento(" "), _telefono(" "), _email(" "), _eliminado(false){}

void Titular::setPiso(int piso){
_piso = piso;
}
void Titular::setDepartamento(string departamento){
strncpy(_departamento, departamento.c_str(),49);
_departamento[49] = '\0';
}
void Titular::setTelefono(string telefono){
strncpy(_telefono, telefono.c_str(),49);
_telefono[49] = '\0';
}
void Titular::setEmail(string email){
strncpy(_email, email.c_str(),49);
_email[49] = '\0';
}
void Titular::setEliminado(bool eliminado){
_eliminado = eliminado;
}

int Titular::getPiso(){return _piso;}
const char* Titular::getDepartamento(){return _departamento;}
const char* Titular::getTelefono(){return _telefono;}
const char* Titular::getEmail(){return _email;}
bool Titular::getEliminado(){return _eliminado;}

void Titular::cargar(){
int piso;
bool eliminado;
string departamento, telefono, email;

persona::cargar();

cout << "INGRESE PISO: ";
cin >> piso;
cout << "INGRESE DEPARTAMENTO: ";
cin >> departamento;
cout << "INGRESE TELEFONO: ";
cin >> telefono;
cout << "INGRESE EMAIL: ";
cin >> email;

_eliminado = false;
setPiso(piso);
setDepartamento(departamento);
setTelefono(telefono);
setEmail(email);
}

void Titular::mostrar(){

persona::mostrar();
cout << "PISO: " <<_piso << endl;
cout << "DEPARTAMENTO: " <<_departamento << endl;
cout << "TELEFONO: " <<_telefono << endl;
cout << "EMAIL: " <<_email << endl;

}
string Titular::toCsv(){
  return string(getNombre()) + "," + string(getDNI()) + "," + string(getApellido())
  + "," + to_string(getPiso()) + "," + getDepartamento() + "," + getTelefono()
   + "," + getEmail() + "," + to_string(getEliminado());
}
