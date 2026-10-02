#pragma once
#include "UnidadFuncional.h"

class ArchivoUnidadFuncional
{
  public:
  ArchivoUnidadFuncional(std::string nombreArchivo="unidadFuncinal.dat", std::string archivoBackup = "unidadFuncional.bak");
  
  bool agregarRegistro(UnidadFuncional obj);
  int buscarUnidad(int unidad);
  int buscarUnidadPorDni(const char* dni);
  void listarUnidades();
  UnidadFuncional leerRegistro(int pos);
  bool modificarRegistro(UnidadFuncional obj, int pos);
  bool eliminarRegistro(int pos);
  bool isExist(int unidad, const char* letra);
  int cantidadRegistros();
  bool backupCopia();
  bool restaurarBackup();
  void listarTitularesBackup();


  private:
    std::string _nombreArchivo, _archivoBackup;
};
