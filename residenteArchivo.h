#pragma once
#include "Residente.h"

class residenteArchivo
{
  public:
    residenteArchivo(std::string nombreArchivo = "residente.dat", std::string archivoBackup = "residente.bak");
    bool agregarResidente(Residente obj);
    bool buscarResidentePorDNI(const char* dni);
    int buscarResidente(const char* dni);
    bool modificarResidente(Residente obj, int pos);
    Residente leerResidente(int pos);
    void listarResidentes();
    int eliminarResidente(const char* dni);
    int cantidadRegistros();
    bool backupCopia();
    bool restaurarBackup();
    void listarTitularesBackup();
    

  private:
    std::string _residenteArchivoNombre, _archivoBackup;
};

