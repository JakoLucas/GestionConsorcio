#pragma once
#include "ArchivoUnidadFuncional.h"

class ManagerUnidadFuncional
{
  public:
  
        bool crearRegistro();
        void buscarRegistroDNI();
        void eliminarRegistro();
        void altaRegistro();
        void listarRegistro();

  private:
    ArchivoUnidadFuncional archivoUnidad;
};

