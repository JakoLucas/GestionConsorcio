#pragma once
#include "Titular.h"
#include "fstream"

class archivoTitular
{
  public:
    archivoTitular(std::string titularArchivo = "titular.dat", std::string archivoBackup = "titular.bak", std::string titularCsv = "titular.csv");
    bool agregarTitular(Titular obj);
    bool buscarTitularPorDNI(const char* dni);
    bool buscarTitularPorApellido(const char* apellido);
    bool buscarApellido(std::string apellido);
    int buscarTitular(const char* dni);
    bool modificarTitular(Titular obj, int pos);
    Titular leerTitular(int pos);
    void listarTitulares();
    int eliminarTitular(const char* dni);
    int cantidadRegistros();
    bool backupCopia();
    bool restaurarBackup();
    void listarTitularesBackup();
    bool exportarToCsv();
  private:
    std::string _titularArchivoNombre;
    std::string _archivoBackup;
    std::string _titularCsv;
};

