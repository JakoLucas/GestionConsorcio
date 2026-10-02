#pragma once
#include "ArchivoReclamo.h"

class ManagerReclamo{
  
  public:
    
        void crearRegistro();
        void eliminarRegistro();
        void altaRegistro();
        void actualizarRegistro();
        void listarPendientes();

  private:
    
    ArchivoReclamo archivoReclamo;
};

