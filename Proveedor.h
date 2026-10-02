#pragma once

class Proveedor {

public:
  
  Proveedor();
  
  void setCuit(std::string cuit);
  void setNombreEmpresa(std::string nombre);
  void setTelefono(std::string telefono);
  void setEmail(std::string email);
  void setDireccion(std::string direccion);
  void setEliminado(bool eliminado);
  
  const char* getCuit();
  const char* getNombreEmpresa();
  const char* getTelefono();
  const char* getEmail();
  const char* getDireccion();
  bool getEliminado();
  
  void cargar();
  void mostrar();

private:
  
char _cuit[50], _nombreEmpresa[50], _telefono[50], _email[50], _direccion[50];
bool _eliminado;
};
