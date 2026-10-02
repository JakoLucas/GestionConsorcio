# include<iostream>
# include "Fecha.h"

using namespace std;

Fecha::Fecha(): _anio(0), _mes(0), _dia(0){}

void Fecha::setAnio(int anio){
if(anio>1900 && anio<2030){
   _anio = anio;}
}
void Fecha::setMes(int mes){
  if(mes>0 && mes<13){
  _mes = mes;  
  }
}
void Fecha::setDia(int dia){
  if(dia>0 && dia<34){
  _dia = dia;  
  }
}

int Fecha::getAnio(){return _anio;}
int Fecha::getMes(){return _mes;}
int Fecha::getDia(){return _dia;}

void Fecha::cargar(){
int anio,mes,dia;
cout << "INGRESE ANIO: ";
cin >> anio;
cout << "INGRESE MES: ";
cin >> mes;
cout << "INGRESE DIA: ";
cin >> dia;

setAnio(anio);
setMes(mes);
setDia(dia);
}
void Fecha::mostrar(){
cout <<_dia<<"/"<<_mes<<"/"<<_anio<<endl;
}


