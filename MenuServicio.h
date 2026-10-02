#pragma once
#include "ManagerServicio.h"

class MenuServicio
{
  public:

    MenuServicio();
    void mostrar();

  protected:

    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opc);

  private:
    
    int seleccionOpcionMenu;
      ManagerServicio obj;
};
