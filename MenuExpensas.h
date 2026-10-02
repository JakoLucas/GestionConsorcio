#pragma once
#include "ManagerExpensas.h"

class MenuExpensas
{
  public:

    MenuExpensas();
    void mostrar();

  protected:

    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opc);

  private:
      int seleccionOpcionMenu;
      
      ManagerExpensas obj;
};

