# include<iostream>
# include "ArchivoUnidadFuncional.h"
# include <string.h>

using namespace std;

ArchivoUnidadFuncional::ArchivoUnidadFuncional(string nombreArchivo, string archivoBackup){
  _nombreArchivo = nombreArchivo;
  _archivoBackup = archivoBackup;
}

bool ArchivoUnidadFuncional::agregarRegistro(UnidadFuncional obj){
    FILE *pFile;
    
    pFile = fopen(_nombreArchivo.c_str(),"ab");
    
    /*if(pFile == nullptr){
      return false;    
    }*/
    bool registro;
    
    registro = fwrite(&obj,sizeof(UnidadFuncional),1,pFile);
    
    fclose(pFile);
    
    return registro;
}
int ArchivoUnidadFuncional::buscarUnidad(int unidad){
    FILE *pFile;
    
    pFile = fopen(_nombreArchivo.c_str(),"rb");
    
    if(pFile == nullptr){
      return -1;    
    }
    
    int pos = 0;
    
    UnidadFuncional obj;
    
    while(fread(&obj,sizeof(UnidadFuncional),1,pFile)){
          if(obj.getIDUnidad() == unidad){
              fclose(pFile);
              return pos;
            }
            pos++;
    }
    
    fclose(pFile);
    
    return -1;
}
int ArchivoUnidadFuncional::buscarUnidadPorDni(const char* dni){
    FILE *pFile;
    
    pFile = fopen(_nombreArchivo.c_str(),"rb");
    
    if(pFile == nullptr){
      return -1;    
    }
    int pos = 0;
    UnidadFuncional obj;
    while(fread(&obj,sizeof(UnidadFuncional),1,pFile)){
              if(strcmp(obj.getDniTitular(),dni)==0){
                fclose(pFile);
                return pos;              
              }
          pos++;
    }
    fclose(pFile);
    
    return -1;    
}
bool ArchivoUnidadFuncional::modificarRegistro(UnidadFuncional obj, int pos){
      FILE *pFile;
      
      pFile = fopen(_nombreArchivo.c_str(),"rb+");
      
      if(pFile == nullptr){
        return false;      
      }
      
      bool registro;
      
      fseek(pFile, pos*sizeof(obj),SEEK_SET);
      
      registro = fwrite(&obj,sizeof(UnidadFuncional),1,pFile);
      
      fclose(pFile);
      
      return registro;
}
void ArchivoUnidadFuncional::listarUnidades(){
      FILE *pFile;
      
      pFile = fopen(_nombreArchivo.c_str(),"rb");
      
      if(pFile == nullptr){
      cout << "NO SE PUDO ABRIR EL ARCHIVO " << endl;
        exit(-1);
      }
      
      UnidadFuncional obj;
      
      while(fread(&obj,sizeof(UnidadFuncional),1,pFile)){ 
            if(obj.getEliminado()==false){
            cout << "--------------" << endl;
                obj.mostrar();
            }
      }
      
      fclose(pFile);     
}
UnidadFuncional ArchivoUnidadFuncional::leerRegistro(int pos){
      FILE *pFile;
      
      pFile = fopen(_nombreArchivo.c_str(),"rb");
      
      if(pFile == nullptr){
      cout << "NO SE PUDO ABRIR EL ARCHIVO " << endl;
        exit(-1);
      }
      
      UnidadFuncional obj;
      
      fseek(pFile,pos*sizeof(UnidadFuncional),SEEK_SET);
      
      fread(&obj,sizeof(UnidadFuncional),1,pFile);
      
      fclose(pFile);
      
      return obj;
}
bool ArchivoUnidadFuncional::eliminarRegistro(int pos){
      FILE *pFile;
      
      pFile = fopen(_nombreArchivo.c_str(),"rb+");
      
      if(pFile == nullptr){
          return false;
      }
      
      bool registro;
      
      UnidadFuncional obj;
      
      fseek(pFile,pos*sizeof(UnidadFuncional),SEEK_SET);
      
      registro = fwrite(&obj,sizeof(UnidadFuncional),1,pFile);
      
      fclose(pFile);
      
      return registro;
}
bool ArchivoUnidadFuncional::isExist(int unidad, const char* letra){
      FILE *pFile;
      
      pFile = fopen(_nombreArchivo.c_str(),"rb");
      
      UnidadFuncional obj;
      
      while(fread(&obj,sizeof(UnidadFuncional),1,pFile)){
            if(obj.getIDUnidad() == unidad && obj.getLetra() == letra){
                fclose(pFile);
                return true;
            }      
      }
      fclose(pFile);
      
      return false;
}

int ArchivoUnidadFuncional::cantidadRegistros(){
  FILE *pFile;
  int registros = 0;

  pFile = fopen(_nombreArchivo.c_str(),"rb");

  if(pFile == nullptr){
    return -1;  
  }
  fseek(pFile,0,SEEK_END);

  registros = ftell(pFile)/sizeof(UnidadFuncional);
  
  fclose(pFile);

  return registros;
}
bool ArchivoUnidadFuncional::backupCopia(){
    FILE *pFile, *pBackup;
    UnidadFuncional obj;
    
    pFile = fopen(_nombreArchivo.c_str(),"rb");
    
    pBackup = fopen(_archivoBackup.c_str(),"wb");
    
    if(pFile == nullptr || pBackup == nullptr){
      return false;    
    }
    
    while(fread(&obj, sizeof(UnidadFuncional),1,pFile)){
          fwrite(&obj, sizeof(UnidadFuncional),1,pBackup);    
    }
      
    fclose(pFile);
    fclose(pBackup);
    
    return true;
}

bool ArchivoUnidadFuncional::restaurarBackup(){
    FILE *pFile, *pBackup;
    UnidadFuncional obj;
    
    pBackup = fopen(_archivoBackup.c_str(),"rb");
    
    pFile = fopen(_nombreArchivo.c_str(),"wb");
    
    
    if(pFile == nullptr || pBackup == nullptr){
      return false;    
    }
    
    while(fread(&obj, sizeof(UnidadFuncional),1,pBackup)){
          fwrite(&obj, sizeof(UnidadFuncional),1,pFile);    
    }
      
    fclose(pBackup);
    fclose(pFile);
    
    return true;
}

void ArchivoUnidadFuncional::listarTitularesBackup(){
  FILE *pBackup;
  UnidadFuncional obj;

  pBackup = fopen(_archivoBackup.c_str(), "rb");

  if(pBackup == nullptr){
    cout << "No se pudo abrir el archivo de backup";
    return;
  }
    while(fread(&obj,sizeof(UnidadFuncional),1,pBackup)){
          if(!obj.getEliminado()){
            cout << "----------" << endl;
            obj.mostrar();
          }
    }
      fclose(pBackup);
}
