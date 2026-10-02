#pragma once
class CopiaSeguridadMenu
{
  public:

    CopiaSeguridadMenu();
    void mostrar();

  protected:

    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opc);

  private:
      int seleccionOpcionMenu;
};

