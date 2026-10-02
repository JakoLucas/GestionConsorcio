#pragma once
#include "Reclamo.h"

class ArchivoReclamo
{
  public:
  ArchivoReclamo(std::string nombreArchivo = "reclamo.dat", std::string archivoBackup = "reclamo.bak");
  
  bool agregarReclamo(Reclamo obj);
  int buscarUnidad(int id);
  bool modificarReclamo(Reclamo obj, int idReclamo);
  Reclamo leerRegistro(int pos);
  void listarPendiente(int estado);
  bool isExist(int id);
  int cantidadRegistros();
  bool backupCopia();
  bool restaurarBackup();
  void listarTitularesBackup();

  private:
    std::string _nombreArchivo, _archivoBackup;
};
