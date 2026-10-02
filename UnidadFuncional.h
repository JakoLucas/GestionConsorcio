#pragma once

class UnidadFuncional
{
  public:
    UnidadFuncional();
    void setIDUnidad(int unidad);
    void setPiso(int piso);
    void setDniTitular(std::string dni);
    void setLetra(std::string letra);
    void setOcupado(bool ocupado);
    void setEliminado(bool eliminado);
    
    int getIDUnidad();
    int getPiso();
    const char* getDniTitular();
    const char* getLetra();
    bool getOcupado();
    bool getEliminado();
    
    void cargar();
    void mostrar();

  private:
    int _idUnidad, _piso;
    char _letra[5], _dniTitular[50];
    bool _ocupado, _eliminado;
};
