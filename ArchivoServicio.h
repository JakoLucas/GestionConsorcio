#pragma once
#include "Servicio.h"

class ArchivoServicio
{
  public:
    
    ArchivoServicio(std::string nombreArchivo = "servicio.dat", std::string archivoBackup = "servicio.bak");
    bool agregarRegistro(Servicio obj);
    int buscarRegistro(int id);
    bool modificarRegistro(Servicio obj, int pos);
    void listarRegistros();
    Servicio leerRegistro(int pos);
    int cantidadRegistros();
    bool backupCopia();
    bool restaurarBackup();
    void listarTitularesBackup();
    
  private:
    std::string _nombreArchivo, _archivoBackup;
};
