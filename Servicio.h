#pragma once

class Servicio
{
  public:
    Servicio();
    
    void setIDServicio(int id);
    void setTipoServicio(int servicio);
    void setEstado(int estado);
    void setCostoMensual(float costo);
    void setEmpresaProveedor(std::string proveedor);
    void setEliminado(bool eliminado);
    
    int getIDServicio();
    int getTipoServicio();
    int getEstado();
    float getCostoMensual();
    const char* getEmpresaProveedor();
    bool getEliminado();
    
    void cargar();
    void mostrar();

  private:
    int _idServicio, _tipoServicio, _estado;
    float _costoMensual;
    char _empresaProveedor[50];
    bool _eliminado;
};

