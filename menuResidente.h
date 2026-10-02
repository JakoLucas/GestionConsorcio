#pragma once
#include <managerIntegrante.h>

class menuResidente
{
  public:

    menuResidente();
    void mostrar();

  protected:

    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opc);

  private:
      int seleccionOpcionMenu;
      managerIntegrante obj;

};
