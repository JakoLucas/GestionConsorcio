# include<iostream>
# include "expensaPagada.h"

using namespace std;

expensaPagada::expensaPagada(): _idExpensa(0), _idUnidad(0), _montoPago(0), _fechaPago(), _eliminado(false){}

void expensaPagada::setIDExpensa(int idexp){
  _idExpensa = idexp;
}
void expensaPagada::setIDUnidad(int unidad){
  _idUnidad = unidad;
}
void expensaPagada::setMontoPago(float monto){
  _montoPago = monto;
}
void expensaPagada::setFechaPago(Fecha fecha){
  _fechaPago = fecha;
}
void expensaPagada::setEliminado(bool eliminado){
  _eliminado = eliminado;
}
int expensaPagada::getIDExpensa(){return _idExpensa;}
int expensaPagada::getIDUnidad(){return _idUnidad;}
float expensaPagada::getMontoPago(){return _montoPago;}
Fecha expensaPagada::getFechaPago(){return _fechaPago;}
bool expensaPagada::getEliminado(){return _eliminado;}

void expensaPagada::cargar(){
  int unidad;
  bool eliminado;
  float monto;
  Fecha f;
  
  cout << "INGRESE ID DE LA UNIDAD FUNCIONAL: ";
  cin >> unidad;
  cout << "INGRESE MONTO PAGADO: ";
  cin >> monto;
  cout << "FECHA PAGO: " << endl;
  f.cargar();
  eliminado = false;

  setIDUnidad(unidad);
  setMontoPago(monto);
  setFechaPago(f);
  setEliminado(eliminado);
}
void expensaPagada::mostrar(){
  cout << "ID EXPENSA: " << _idExpensa << endl;
  cout << "ID UNIDAD FUNCIONAL: " << _idUnidad << endl;
  cout << "MONTO PAGADO: " << _montoPago << endl;
  cout << "FECHA PAGO: ";
  _fechaPago.mostrar();
}
