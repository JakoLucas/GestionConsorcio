#pragma once
#include "archivoTitular.h"


class managerTitulares
{
    public:
        bool crearRegistro();
        void buscarRegistroDNI();
        void buscarRegistroApellido();
        void modificarRegistro();
        void eliminarRegistro();
        void altaRegistro();
        void listarRegistro();

    private:
        archivoTitular repo;
};
