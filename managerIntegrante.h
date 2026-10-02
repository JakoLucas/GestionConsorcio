#include "residenteArchivo.h"

class managerIntegrante
{
    public:
        bool crearRegistro();
        void buscarRegistroDNI();
        void modificarRegistro();
        void eliminarRegistro();
        void altaRegistro();
        void listarRegistro();

    private:
        residenteArchivo repo;
};

