#pragma once
# include "Fecha.h"

class Reclamo
{
  public:
    Reclamo();
    
    void setIDReclamo(int reclamo);
    void setIDUnidad(int unidad);
    void setTipoProblema(int problema);
    void setEstado(int estado);
    void setEliminado(bool eliminado);
    void setFechaReclamo(Fecha fecha);
    
    int getIDReclamo();
    int getIDUnidad();
    int getTipoProblema();
    int getEstado();
    bool getEliminado();
    Fecha getFechaReclamo();
    
    void cargar();
    void mostrar();
    
  private:
    int _idReclamo, _idUnidad, _tipoProblema, _estado;
    bool _eliminado;
    Fecha _fechaReclamo;
};
