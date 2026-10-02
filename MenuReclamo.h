#pragma once
#include "ManagerReclamo.h"

class MenuReclamo
{
  public:
    MenuReclamo();
    void mostrar();

  protected:

    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opc);

  private:
      int seleccionOpcionMenu;
      
      ManagerReclamo objeto;
};


