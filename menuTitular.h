#pragma once
#include <managerTitulares.h>

class menuTitular
{
  public:

    menuTitular();
    void mostrar();

  protected:

    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opc);

  private:
      int seleccionOpcionMenu;
      managerTitulares obj;

};

