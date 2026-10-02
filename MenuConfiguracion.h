#pragma once
#include "ManagerConfiguracion.h"

class MenuConfiguracion
{
  public:

    MenuConfiguracion();
    void mostrar();

  protected:
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opc);

  private:
      int seleccionOpcionMenu;
      ManagerConfiguracion manager;
};
