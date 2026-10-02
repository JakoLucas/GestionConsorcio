#pragma once
#include "Expensa.h"
#include "Titular.h"
#include "Reclamo.h"
#include "Servicio.h"
#include "expensaPagada.h"
#include "UnidadFuncional.h"
#include "Residente.h"
#include "Edificio.h"

#include "ArchivoExpensa.h"
#include "ArchivoExpensaPagada.h"
#include "ArchivoUnidadFuncional.h"
#include "archivoTitular.h"
#include "ArchivoReclamo.h"
#include "ArchivoServicio.h"
#include "residenteArchivo.h"
#include "ArchivoEdificio.h"
#include "rlutil.h"

class ManagerInformes
{
  public:
    void informeAnual();
    void rankingDeudores();
    void informeEficiencia();
    void reporte();
    void informeIncidencia();
};

