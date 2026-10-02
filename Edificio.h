#pragma once
#include <string>


class Edificio
{
  public:
    Edificio();
    void setCantidadPisos(int pisos);
    void setCantidadUnidades(int unidades);
    void setNombre(std::string nombre);
    void setDireccion(std::string direccion);
    void setEstado(bool estado);
    
    int getCantidadPisos();
    int getCantidadUnidades();
    const char* getNombre();
    const char* getDireccion();
    bool getEstado();
    
    void cargar();
    void mostrar();
    void modificarDatos();
  
  private:
    int _cantidadPisos;
    int _cantidadUnidades;
    char _nombre[50];
    char _direccion[50];
    bool _estado;
};

