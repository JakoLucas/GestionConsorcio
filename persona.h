#pragma once
#include <string>
class persona
{
  public:
    persona();
    void setDNI(std::string dni);
    void setNombre(std::string nombre);
    void setApellido(std::string apellido);

    const char* getDNI();
    const char* getNombre();
    const char* getApellido();

    void cargar();
    void mostrar();

  protected:
  char _dni[50];
  char _nombre[50];
  char _apellido[50];
};

