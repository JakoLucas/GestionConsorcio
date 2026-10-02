#pragma once
#include "ArchivoExpensa.h"
#include "ArchivoExpensaPagada.h"

class ManagerExpensas
{
  public:
        
        void crearExpensa();
        void buscarRegistro();
        void eliminarRegistro();
        void altaRegistro();
        void listarRegistro();
        
        void crearExpensaPagada();
        void buscarExpensaPagada();
        void eliminarExpensaPagada();
        void altaExpensaPagada();
        void listarExpensaPagada();

  private:
        ArchivoExpensa expensa;
        ArchivoExpensaPagada expensaP;
};

