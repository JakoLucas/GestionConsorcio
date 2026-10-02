#pragma once
#include "ManagerInformes.h"
#include "rlutil.h"

class MenuInformes
{
  public:
    MenuInformes();
    void mostrar();

  protected:
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opc);

  private:
      int seleccionOpcionMenu;
      ManagerInformes obj;
};
