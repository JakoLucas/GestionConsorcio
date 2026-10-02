#pragma once
#include "gestionMenu.h"
#include "MenuInformes.h"
#include "MenuConfiguracion.h"
#include "rlutil.h"

class Aplicacion
{
  public:
    
    Aplicacion();
    void run();

  protected:

    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opc);

  private:
      int seleccion;
      gestionMenu menu;
      MenuInformes menuInforme;
      MenuConfiguracion menuConfig;
};
