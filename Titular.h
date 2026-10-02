#pragma once
#include "persona.h"

class Titular:public persona
{
  public:
    Titular();
    
    void setPiso(int piso);
    void setDepartamento(std::string departamento);
    void setTelefono(std::string telefono);
    void setEmail(std::string email);
    void setEliminado(bool eliminado);
    
    int getPiso();
    const char* getDepartamento();
    const char* getTelefono();
    const char* getEmail();
    bool getEliminado();
    
    void cargar();
    void modificarDatos();
    void mostrar();
    std::string toCsv();

  private:
    int _piso;
    char _departamento[50];
    char _telefono[50];
    char _email[50];
    bool _eliminado;
};
