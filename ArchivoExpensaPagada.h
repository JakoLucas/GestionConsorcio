#pragma once
#include "expensaPagada.h"

class ArchivoExpensaPagada
{
  public:
    ArchivoExpensaPagada(std::string nombreArchivo = "expensasPagadas.dat", std::string archivoBackup = "expensasPagadas.bak");
    
    bool agregarRegistro(expensaPagada obj);
    int buscarRegistro(int id);
    bool modificarRegistro(expensaPagada obj, int pos);
    void listarRegistros();
    expensaPagada leerRegistro(int pos);
    int cantidadRegistros();
    bool backupCopia();
    bool restaurarBackup();
    void listarTitularesBackup();

  private:
    std::string _nombreArchivo, _archivoBackup;
};

