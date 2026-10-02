#pragma once
#include "Expensa.h"

class ArchivoExpensa
{
  public:
    ArchivoExpensa(std::string nombreArchivo = "expensas.dat", std::string archivoBackup = "expensas.bak");
    
    bool agregarRegistro(Expensa obj);
    int buscarRegistro(int id);
    bool modificarRegistro(Expensa obj, int pos);
    void listarRegistros();
    Expensa leerRegistro(int pos);
    int cantidadRegistros();
    bool backupCopia();
    bool restaurarBackup();
    void listarTitularesBackup();
    
  private:
    std::string _nombreArchivo, _archivoBackup;
};
