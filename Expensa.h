#pragma once
# include "Fecha.h"

class Expensa
{
  public:
    Expensa();

    void setIDExpensa(int id);
    void setIDUnidad(int unidad);
    void setMontoTotal(float monto);
    void setFechaInicio(Fecha fecha);
    void setFechaFin(Fecha fecha);
    void setEliminado(bool eliminado);
    
    int getIDExpensa();
    int getIDUnidad();
    float getMontoTotal();
    Fecha getFechaInicio();
    Fecha getFechaFin();
    bool getEliminado();
    
    void cargar();
    void mostrar();

  private:
   int _idExpensa, _idUnidad;
   float _montoTotal;
   Fecha _fechaInicio, _fechaFin;
   bool _eliminado;
};
