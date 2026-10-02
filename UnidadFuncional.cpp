# include<iostream>
# include "UnidadFuncional.h"
# include <string.h>

using namespace std;

UnidadFuncional::UnidadFuncional(): _idUnidad(0), _piso(0), _dniTitular(" "), _letra(" "), _ocupado(false), _eliminado(false){}
void UnidadFuncional::setIDUnidad(int unidad){

  _idUnidad = unidad;  

}
void UnidadFuncional::setPiso(int piso){
  if(piso>-1){
  _piso = piso;  
  }
}
void UnidadFuncional::setDniTitular(string dni){
  strncpy(_dniTitular,dni.c_str(),49);
  _dniTitular[49] = '\0'; 
}
void UnidadFuncional::setLetra(std::string letra){
  strncpy(_letra,letra.c_str(),4);
  _letra[4] = '\0';
}
void UnidadFuncional::setOcupado(bool ocupado){
  _ocupado = ocupado;
}
void UnidadFuncional::setEliminado(bool eliminado){
  _eliminado = eliminado;
}
int UnidadFuncional::getIDUnidad(){return _idUnidad;}
int UnidadFuncional::getPiso(){return _piso;}
const char* UnidadFuncional::getDniTitular(){return _dniTitular;}
const char* UnidadFuncional::getLetra(){return _letra;}
bool UnidadFuncional::getOcupado(){return _ocupado;}
bool UnidadFuncional::getEliminado(){return _eliminado;}

void UnidadFuncional::cargar(){
  int piso;
  string letra, dni;
  bool ocupado, eliminado;

  cout << "INGRESE PISO: ";
  cin >> piso;
  cout << "INGRESE DNI TITULAR: ";
  cin >> dni;
  cout << "INGRESE LETRA DEPTO: ";
  cin >> letra;
  ocupado = true;
  eliminado = false;
  
  setPiso(piso);
  setDniTitular(dni);
  setLetra(letra);
  setOcupado(ocupado);
  setEliminado(eliminado);
}

void UnidadFuncional::mostrar(){
  cout << "LA ID DE LA UNIDAD ES: " << _idUnidad << endl;
  cout << "EL PISO ES: " << _piso << endl;
  cout << "DNI TITULAR: " << _dniTitular << endl;
  cout << "LETRA DEPTO: " << _letra << endl;
  cout << "OCUPADO: " << (_ocupado ? "SI" : "NO") << endl;
}
