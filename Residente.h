#pragma once
#include "persona.h"
#include "Fecha.h"

class Residente:public persona
{
  public:
    Residente();
    void setIDUnidad(int unidad);
    void setFecha(Fecha fecha);
    void setParentesco(std::string parentesco);
    void setPiso(int piso);
    void setDepartamento(std::string departamento);
    void setEliminado(bool eliminado);
    
    int getIDUnidad();
    Fecha getFechaNacimiento();
    const char* getParentesco();
    int getPiso();
    const char* getDepartamento();
    bool getEliminado();
    
    void cargar();
    void mostrar();
    
  private:
  Fecha _fechaNacimiento;
  char _parentesco[50];
  int _piso, _idUnidad;
  char _departamento[50];
  bool _eliminado;
};
