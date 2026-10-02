#pragma once
#include "menuTitular.h"
#include "menuResidente.h"
#include "MenuEdificio.h"
#include "MenuUnidadFuncional.h"
#include "MenuReclamo.h"
#include "MenuExpensas.h"
#include "MenuServicio.h"

class gestionMenu
{
  public:

    gestionMenu();
    void mostrar();

  protected:

    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opc);

  private:
      int seleccionOpcionMenu;
      menuTitular menuTitular;
      menuResidente menuResidente;
      MenuEdificio menuEdificio;
      MenuUnidadFuncional menuUnidad;
      MenuReclamo menuReclamo;
      MenuExpensas menuExpensas;
      MenuServicio menuServicio;
};
