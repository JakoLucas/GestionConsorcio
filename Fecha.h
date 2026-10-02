#pragma once

class Fecha
{
  public:
    Fecha();
    
    void setAnio(int anio);
    void setMes(int mes);
    void setDia(int dia);
    
    int getAnio();
    int getMes();
    int getDia();
    
    void cargar();
    void mostrar();

  private:
    int _anio;
    int _mes;
    int _dia;
};
