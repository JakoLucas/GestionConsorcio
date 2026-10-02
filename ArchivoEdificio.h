#pragma once
#include "Edificio.h"

class ArchivoEdificio
{
  public:
    ArchivoEdificio(std::string nombre = "edificio.dat", std::string archivoBackup = "edificio.bak");
    bool agregarEdificio(Edificio obj);
    int buscarEdificioPorDireccion(std::string direccion);
    bool modificarEdificio(Edificio obj, int pos);
    Edificio leerEdificio(int id);
    void listarEdificio();
    bool eliminarEdificio(std::string direccion, int pos);
    int cantidadRegistros();
    bool backupCopia();
    bool restaurarBackup();
    void listarTitularesBackup();

  private:
    std::string _nombreArchivo, _archivoBackup;
};
