#pragma once
#include "ArchivoServicio.h"

class ManagerServicio
{
  public:
      void crearServicio();
      void buscarRegistro();
      void eliminarRegistro();
      void altaRegistro();
      void listarRegistro();

  private:
      ArchivoServicio archiReg;
};

