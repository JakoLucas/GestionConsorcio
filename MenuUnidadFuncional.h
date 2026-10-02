#pragma once
#include "ManagerUnidadFuncional.h"

class MenuUnidadFuncional
{
  public:
     public:

    MenuUnidadFuncional();
    void mostrar();

  protected:

    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opc);


  private:
    ManagerUnidadFuncional obj;
    int seleccionOpcionMenu;
};
