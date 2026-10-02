#pragma once
#include "Fecha.h"

class expensaPagada
{
  public:
    expensaPagada();
    
    void setIDExpensa(int idexp);
    void setIDUnidad(int unidad);
    void setMontoPago(float monto);
    void setFechaPago(Fecha fecha);
    void setEliminado(bool eliminado);
        
    int getIDExpensa();
    
    int getIDUnidad();
    bool getEliminado();
    float getMontoPago();
    Fecha getFechaPago();
    
    void cargar();
    void mostrar();

  private:
   int _idExpensa, _idUnidad;
   float _montoPago;
   Fecha _fechaPago;
   bool _eliminado;
};
