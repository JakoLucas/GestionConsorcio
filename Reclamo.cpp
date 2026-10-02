# include<iostream>
# include "Reclamo.h"

using namespace std;

Reclamo::Reclamo(): _idReclamo(0), _idUnidad(0), _tipoProblema(0), _estado(0), _eliminado(false), _fechaReclamo() {}

void Reclamo::setIDReclamo(int reclamo){
  if(reclamo>-1){
    _idReclamo = reclamo;  
  }
}
void Reclamo::setIDUnidad(int unidad){
  if(unidad>-1){
    _idUnidad = unidad;  
  }
}
void Reclamo::setTipoProblema(int problema){
    _tipoProblema = problema;
}
void Reclamo::setEstado(int estado){
  if(estado>0 && estado<4){
    _estado = estado;  
  }
}
void Reclamo::setEliminado(bool eliminado){
  _eliminado = eliminado;
}
void Reclamo::setFechaReclamo(Fecha fecha){
  _fechaReclamo = fecha;
}

int Reclamo::getIDReclamo(){return _idReclamo;}
int Reclamo::getIDUnidad(){return _idUnidad;}
int Reclamo::getTipoProblema(){return _tipoProblema;}
int Reclamo::getEstado(){return _estado;}
bool Reclamo::getEliminado(){return _eliminado;}
Fecha Reclamo::getFechaReclamo(){return _fechaReclamo;}

void Reclamo::cargar(){
  int unidad, problema, estado;
  bool eliminado;
  Fecha fecha;
  
  cout << "INGRESE ID DE UNIDAD: " << endl;
  cin >> unidad;
  cout << "INGRESE TIPO DE PROBLEMA: " << endl;
  cin >> problema;
  cout << "INGRESE ESTADO DEL PROBLEMA - 1.PENDIENTE, 2. EN PROCESO, 3. RESUELTO - : " << endl;
  cin >> estado;
  cout << "FECHA DE RECLAMO: " << endl;
  fecha.cargar();
  eliminado = false;
  
  setIDUnidad(unidad);
  setTipoProblema(problema);
  setEstado(estado);
  setFechaReclamo(fecha);
  setEliminado(eliminado);
}
void Reclamo::mostrar(){
  cout << "ID DE RECLAMO: " << _idReclamo << endl;
  cout << "ID DE UNIDAD: " << _idUnidad << endl;
  cout << "TIPO DE PROBLEMA (1. ASCENSOR, 2. PLOMERIA, 3. CRISTALERIA, 4. ELECTRICISTA, 5. PILETERO):  " << _tipoProblema << endl;
  cout << "ESTADO (1.PENDIENTE, 2. EN PROCESO, 3. RESUELTO) " << _estado << endl;
  cout << "FECHA DE RECLAMO: ";
  _fechaReclamo.mostrar();
}
