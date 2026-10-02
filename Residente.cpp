# include<iostream>
# include "Residente.h"
# include <string.h>

using namespace std;

Residente::Residente(): _idUnidad(0), _fechaNacimiento(), _parentesco(" "), _piso(0), _departamento(" "), _eliminado(false){}
void Residente::setIDUnidad(int unidad){
_idUnidad = unidad;
}

void Residente::setFecha(Fecha fecha){
_fechaNacimiento = fecha;
}
void Residente::setParentesco(string parentesco){
strncpy(_parentesco, parentesco.c_str(),49);
_parentesco[49] = '\0';
}
void Residente::setPiso(int piso){
_piso = piso;
}
void Residente::setDepartamento(string departamento){
strncpy(_departamento, departamento.c_str(),49);
_departamento[49] = '\0';
}
void Residente::setEliminado(bool eliminado){
_eliminado = eliminado;
}

int Residente::getIDUnidad(){return _idUnidad;}
Fecha Residente::getFechaNacimiento(){return _fechaNacimiento;}
const char* Residente::getParentesco(){return _parentesco;}
int Residente::getPiso(){return _piso;}
const char* Residente::getDepartamento(){return _departamento;}
bool Residente::getEliminado(){return _eliminado;}

void Residente::cargar(){
Fecha fecha;
string parentesco, departamento;
int piso, unidad;
bool eliminado;

persona::cargar();
fecha.cargar();
cout << "UNIDAD: ";
cin >> unidad;
cin.ignore();
cout << "INGRESE PARENTESCO: ";
getline(cin, parentesco);
cout << "INGRESE PISO: ";
cin >> piso;
cout<< "INGRESE DEPARTAMENTO: ";
cin >> departamento;
_eliminado = false;

setIDUnidad(unidad);
setFecha(fecha);
setParentesco(parentesco);
setPiso(piso);
setDepartamento(departamento);
}
void Residente::mostrar(){

persona::mostrar();
_fechaNacimiento.mostrar();
cout << "UNIDAD: " << _idUnidad << endl;
cout << "PARENTESCO: " << _parentesco << endl;
cout << "PISO: " << _piso << endl;
cout << "DEPARTAMENTO: " << _departamento << endl;

}
