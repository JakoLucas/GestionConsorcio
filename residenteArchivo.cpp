# include<iostream>
# include "residenteArchivo.h"
# include <string.h>

using namespace std;

residenteArchivo::residenteArchivo(std::string nombreArchivo, std::string archivoBackup){
_residenteArchivoNombre = nombreArchivo;
_archivoBackup = archivoBackup;}

bool residenteArchivo::agregarResidente(Residente obj){
  FILE *pFile;
  bool control;
  
  pFile = fopen(_residenteArchivoNombre.c_str(), "ab");
  
  if(pFile == nullptr){
    return false;  
  }
  
  control = fwrite(&obj,sizeof(Residente),1,pFile);
  
  fclose(pFile);
  
  return control;
}
bool residenteArchivo::buscarResidentePorDNI(const char* dni){
 FILE *pFile;
  pFile = fopen(_residenteArchivoNombre.c_str(),"rb");

  if(pFile == nullptr){
    return false;}
  Residente obj;
  while(fread(&obj,sizeof(Residente),1,pFile)){
        if(strcmp(obj.getDNI(),dni)==0 && obj.getEliminado()==false){
          cout << "SE IDENTIFICO RESIDENTE " << endl;
          cout << endl;
            obj.mostrar();
            fclose(pFile);
            return true;}
          }
      fclose(pFile);
      return false;
}

bool residenteArchivo::modificarResidente(Residente obj, int pos){
  FILE *pFile;
  bool escribio;
  
  pFile = fopen(_residenteArchivoNombre.c_str(),"rb+");
  
  if(pFile==nullptr){
    return false; 
  }
  
  fseek(pFile,pos*sizeof(Residente),SEEK_SET);
  
  escribio = fwrite(&obj,sizeof(Residente),1,pFile);
  
  fclose(pFile);
  
  return escribio;
}

int residenteArchivo::buscarResidente(const char* dni){
    Residente obj;
    
    FILE *pFile;
    
    pFile=fopen(_residenteArchivoNombre.c_str(),"rb");
    
    if(pFile==nullptr){
    return -1;}
    
    int pos = 0;
    while(fread(&obj, sizeof(Residente),1,pFile)){
        if(strcmp(obj.getDNI(),dni)==0){
                cout << "REGISTRO ENCONTRADO " << endl;
                fclose(pFile);
                return pos;
              }
              pos++;
            }
    fclose(pFile);
    return -1;
}

void residenteArchivo::listarResidentes(){
  FILE *pFile;
  Residente obj;
  
  pFile = fopen(_residenteArchivoNombre.c_str(), "rb");
  
  if(pFile == nullptr){
    exit(1);  
  }
    while(fread(&obj,sizeof(Residente),1,pFile)){       
          if(!obj.getEliminado()){
            cout<<"----------------"<<endl;
            obj.mostrar();
          }
    }
      fclose(pFile);
}

int residenteArchivo::eliminarResidente(const char* dni){
  Residente obj;
  int pos;
  pos=buscarResidente(dni);
  if(pos != -1){
  obj=leerResidente(pos);
  obj.setEliminado(true);
  if(modificarResidente(obj,pos)){
  return 1;  
  }
  else { return 0;}
  }
  return 0;
}

int residenteArchivo::cantidadRegistros(){
  FILE *pFile;
  int registros = 0;
  
  pFile = fopen(_residenteArchivoNombre.c_str(),"rb");
  
  if(pFile==nullptr){
    registros = -1;
    return registros;  
  }
  
  fseek(pFile,0,SEEK_END);
  
  registros = ftell(pFile)/sizeof(Residente);
  
  fclose(pFile);
  
  return registros;
}

Residente residenteArchivo::leerResidente(int pos){
    FILE *pFile;
    
    Residente obj;
    
    pFile=fopen(_residenteArchivoNombre.c_str(),"rb");
    
    if(pFile==nullptr){
    exit(1);}
    
    fseek(pFile,pos*sizeof(Residente),SEEK_SET);
    
    fread(&obj, sizeof(Residente),1,pFile);
    
    fclose(pFile);
    
    return obj;
}
bool residenteArchivo::backupCopia(){
    FILE *pFile, *pBackup;
    Residente obj;
    
    pFile = fopen(_residenteArchivoNombre.c_str(),"rb");
    
    pBackup = fopen(_archivoBackup.c_str(),"wb");
    
    if(pFile == nullptr || pBackup == nullptr){
      return false;    
    }
    
    while(fread(&obj, sizeof(Residente),1,pFile)){
          fwrite(&obj, sizeof(Residente),1,pBackup);    
    }
      
    fclose(pFile);
    fclose(pBackup);
    
    return true;
}

bool residenteArchivo::restaurarBackup(){
    FILE *pFile, *pBackup;
    Residente obj;
    
    pBackup = fopen(_archivoBackup.c_str(),"rb");
    
    pFile = fopen(_residenteArchivoNombre.c_str(),"wb");
    
    
    if(pFile == nullptr || pBackup == nullptr){
      return false;    
    }
    
    while(fread(&obj, sizeof(Residente),1,pBackup)){
          fwrite(&obj, sizeof(Residente),1,pFile);    
    }
      
    fclose(pBackup);
    fclose(pFile);
    
    return true;
}

void residenteArchivo::listarTitularesBackup(){
  FILE *pBackup;
  Residente obj;

  pBackup = fopen(_archivoBackup.c_str(), "rb");

  if(pBackup == nullptr){
    cout << "No se pudo abrir el archivo de backup";
    return;
  }
    while(fread(&obj,sizeof(Residente),1,pBackup)){
          if(!obj.getEliminado()){
            cout << "----------" << endl;
            obj.mostrar();
          }
    }
      fclose(pBackup);
}
