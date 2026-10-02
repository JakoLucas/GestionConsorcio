#pragma once
#include "ManagerEdificio.h"

class MenuEdificio
{
  public:

    MenuEdificio();
    void mostrar();

  protected:

    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opc);

  private:
      int seleccionOpcionMenu;
      managerEdificio obj;

};
