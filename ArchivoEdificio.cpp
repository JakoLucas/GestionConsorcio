# include<iostream>
#include "ArchivoEdificio.h"
# include <string.h>

using namespace std;

ArchivoEdificio::ArchivoEdificio(string nombre, string archivoBackup){
  _nombreArchivo = nombre;
  _archivoBackup = archivoBackup;
}
bool ArchivoEdificio::agregarEdificio(Edificio obj){
  FILE *pFile;
  bool control;

  pFile = fopen(_nombreArchivo.c_str(), "ab");

  if(pFile == nullptr){
    return false;
  }

  control = fwrite(&obj,sizeof(Edificio),1,pFile);

  fclose(pFile);

  return control;
  }

int ArchivoEdificio::buscarEdificioPorDireccion(string direccion){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile==nullptr){ return -2;}

    Edificio obj;
    int pos = 0;

    while(fread(&obj, sizeof(Edificio), 1, pFile)){
        if(strcmp(obj.getDireccion(),direccion.c_str())){
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}

bool ArchivoEdificio::modificarEdificio(Edificio obj, int pos){
  FILE *pFile;
  bool escribio;
  
  pFile = fopen(_nombreArchivo.c_str(),"rb+");
  
  if(pFile==nullptr){
    return false; 
  }
  
  fseek(pFile,pos*sizeof(Edificio),SEEK_SET);
  
  escribio = fwrite(&obj,sizeof(Edificio),1,pFile);
  
  fclose(pFile);
  
  return escribio;
}
void ArchivoEdificio::listarEdificio(){
 FILE *pFile;
  Edificio obj;
  
  pFile = fopen(_nombreArchivo.c_str(), "rb");
  
  if(pFile == nullptr){
    exit(1);  
  }
    while(fread(&obj,sizeof(Edificio),1,pFile)){       
          if(obj.getEstado()==false){
            cout<<"----------------"<<endl;
            obj.mostrar();
          }
    }
      fclose(pFile);
}
bool ArchivoEdificio::eliminarEdificio(string direccion, int pos){
  Edificio obj;

  obj=leerEdificio(pos);
  obj.setEstado(true);
  return modificarEdificio(obj,pos);
  }

int ArchivoEdificio::cantidadRegistros(){
  FILE *pFile;
  int registros = 0;
  
  pFile = fopen(_nombreArchivo.c_str(),"rb");
  
  fseek(pFile,0,SEEK_END);
  
  registros = ftell(pFile)/sizeof(Edificio);
  
  fclose(pFile);
  
  return registros;
}

Edificio ArchivoEdificio::leerEdificio(int pos){
    FILE *pFile;
    
    Edificio obj;
    
    pFile=fopen(_nombreArchivo.c_str(),"rb");
    
    if(pFile==nullptr){
    exit(1);}
    
    fseek(pFile,pos*sizeof(Edificio),SEEK_SET);
    
    fread(&obj, sizeof(Edificio),1,pFile);
    
    fclose(pFile);
    
    return obj;
}
bool ArchivoEdificio::backupCopia(){
    FILE *pFile, *pBackup;
    Edificio obj;
    
    pFile = fopen(_nombreArchivo.c_str(),"rb");
    
    pBackup = fopen(_archivoBackup.c_str(),"wb");
    
    if(pFile == nullptr || pBackup == nullptr){
      return false;    
    }
    
    while(fread(&obj, sizeof(Edificio),1,pFile)){
          fwrite(&obj, sizeof(Edificio),1,pBackup);    
    }
      
    fclose(pFile);
    fclose(pBackup);
    
    return true;
}

bool ArchivoEdificio::restaurarBackup(){
    FILE *pFile, *pBackup;
    Edificio obj;
    
    pBackup = fopen(_archivoBackup.c_str(),"rb");
    
    pFile = fopen(_nombreArchivo.c_str(),"wb");
    
    
    if(pFile == nullptr || pBackup == nullptr){
      return false;    
    }
    
    while(fread(&obj, sizeof(Edificio),1,pBackup)){
          fwrite(&obj, sizeof(Edificio),1,pFile);    
    }
      
    fclose(pBackup);
    fclose(pFile);
    
    return true;
}

void ArchivoEdificio::listarTitularesBackup(){
  FILE *pBackup;
  Edificio obj;

  pBackup = fopen(_archivoBackup.c_str(), "rb");

  if(pBackup == nullptr){
    cout << "No se pudo abrir el archivo de backup";
    return;
  }
    while(fread(&obj,sizeof(Edificio),1,pBackup)){
            cout << "----------" << endl;
            obj.mostrar();
          }
    
      fclose(pBackup);
}
