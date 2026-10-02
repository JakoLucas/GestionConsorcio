# include<iostream>
# include "Expensa.h"
# include <string.h>

using namespace std;

Expensa::Expensa(): _idExpensa(0), _idUnidad(0), _montoTotal(0), _fechaInicio(), _fechaFin(), _eliminado(false){}
void Expensa::setIDExpensa(int expensa){
  if(expensa>-1){
  _idExpensa = expensa;  
  }
}

void Expensa::setIDUnidad(int unidad){
    _idUnidad = unidad;
}

void Expensa::setMontoTotal(float monto){
  if(monto>-1){
  _montoTotal = monto;  
  }
}
void Expensa::setFechaInicio(Fecha fecha){
  _fechaInicio = fecha;
}
void Expensa::setFechaFin(Fecha fecha){
  _fechaFin = fecha;
}
void Expensa::setEliminado(bool eliminado){
  _eliminado = eliminado;
}
int Expensa::getIDUnidad(){return _idUnidad;}
int Expensa::getIDExpensa(){return _idExpensa;}
float Expensa::getMontoTotal(){return _montoTotal;}
Fecha Expensa::getFechaInicio(){return _fechaInicio;}
Fecha Expensa::getFechaFin(){return _fechaFin;}
bool Expensa::getEliminado(){return _eliminado;}

void Expensa::cargar(){
  int expensa, unidad;
  float monto;
  Fecha fecIni, fechaF;
  bool eliminado;
  cout << "INGRESE LA UNIDAD FUNCIONAL: ";
  cin >> unidad;
  cout << "INGRESE MONTO TOTAL: ";
  cin >> monto;
  cout << "FECHA INICIO: " << endl;
  fecIni.cargar();
  cout << "FECHA VENCIMIENTO: " << endl;
  fechaF.cargar();
  eliminado = false;
  
  setIDUnidad(unidad);
  setMontoTotal(monto);
  setFechaInicio(fecIni);
  setFechaFin(fechaF);
  setEliminado(eliminado);
}
void Expensa::mostrar(){

  cout << "UNIDAD FUNCIONAL: " << _idUnidad << endl;
  cout << "ID EXPENSA: " << _idExpensa << endl;
  cout << "MONTO TOTAL: " << _montoTotal << endl;

  cout << "FECHA: " << endl;
  _fechaInicio.mostrar();
  cout << "VENCIMIENTO: " << endl;
  _fechaFin.mostrar();
}
