#pragma once
# include "rlutil.h"
# include "ArchivoEdificio.h"
# include "archivoTitular.h"
# include "residenteArchivo.h"
# include "ArchivoUnidadFuncional.h"
# include "ArchivoExpensa.h"
# include "ArchivoExpensaPagada.h"
# include "ArchivoReclamo.h"
# include "ArchivoServicio.h"

class ManagerConfiguracion
{
  public:
    ManagerConfiguracion(){}
    void crearCopia();
    void restaurarCopia();
    int textoCopia();
    bool textoRestauracion();
    int textoCsv();
    void toCsv();

  private:
      ArchivoEdificio aEdificio;
      archivoTitular aTitular;
      residenteArchivo aResidente;
      ArchivoUnidadFuncional aUnidad;
      ArchivoExpensa aExpensa;
      ArchivoExpensaPagada aExpensaPagada;
      ArchivoReclamo aReclamo;
      ArchivoServicio aServicio;
};

