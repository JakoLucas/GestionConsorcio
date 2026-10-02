#pragma once
#include "ArchivoEdificio.h"

class managerEdificio
{
    public:
        bool crearRegistro();
        void buscarRegistro();
        void buscarDireccion();
        void modificarRegistro();
        void eliminarRegistro();
        void altaRegistro();
        void listarRegistro();

    private:
        ArchivoEdificio repo;
};

