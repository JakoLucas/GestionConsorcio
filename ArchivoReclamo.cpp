# include<iostream>
# include "ArchivoReclamo.h"

using namespace std;
ArchivoReclamo::ArchivoReclamo(string nombreArchivo, string archivoBackup){
  _nombreArchivo = nombreArchivo;
  _archivoBackup = archivoBackup;
}

bool ArchivoReclamo::agregarReclamo(Reclamo obj){
    FILE *pFile;
    
    pFile = fopen(_nombreArchivo.c_str(),"ab");
    
    if(pFile == nullptr){
      return false;    
    }
    bool registro;
    
    registro = fwrite(&obj,sizeof(Reclamo),1,pFile);
    
    fclose(pFile);
    
    return registro;
}

bool ArchivoReclamo::modificarReclamo(Reclamo obj, int pos){
      FILE *pFile;
      
      pFile = fopen(_nombreArchivo.c_str(),"rb+");
      
      if(pFile == nullptr){
        return false;      
      }
      
      bool registro;
      
      fseek(pFile, pos*sizeof(obj),SEEK_SET);
      
      registro = fwrite(&obj,sizeof(Reclamo),1,pFile);
      
      fclose(pFile);
      
      return registro;

}
Reclamo ArchivoReclamo::leerRegistro(int pos){
      FILE *pFile;
      
      pFile = fopen(_nombreArchivo.c_str(),"rb");
      
      if(pFile == nullptr){
      cout << "NO SE PUDO ABRIR EL ARCHIVO " << endl;
        exit(-1);
      }
      
      Reclamo obj;
      
      fseek(pFile,pos*sizeof(Reclamo),SEEK_SET);
      
      fread(&obj,sizeof(Reclamo),1,pFile);
      
      fclose(pFile);
      
      return obj;
}
void ArchivoReclamo::listarPendiente(int estado){
    FILE *pFile;
    
    pFile = fopen(_nombreArchivo.c_str(),"rb");
    
    if(pFile == nullptr){
    cout << "NO SE PUDO LISTAR REGISTROS" << endl;
      exit(1);
    }
    
    Reclamo obj;
    
    while(fread(&obj,sizeof(Reclamo),1,pFile)){
      if(obj.getEliminado() == false){
        cout << "---------------------" << endl;
              obj.mostrar();
        }
    }
    
    fclose(pFile);
}

bool ArchivoReclamo::isExist(int id){
      FILE *pFile;
      
      pFile = fopen(_nombreArchivo.c_str(),"rb");
      
      Reclamo obj;
      
      while(fread(&obj,sizeof(Reclamo),1,pFile)){
            if(obj.getIDReclamo() == id){
                fclose(pFile);
                return true;
            }      
      }
      fclose(pFile);
      
      return false;
}

int ArchivoReclamo::buscarUnidad(int id){
    FILE *pFile;
    
    pFile = fopen(_nombreArchivo.c_str(),"rb");
    
    if(pFile == nullptr){
      return -1;    
    }
    int pos = 0;
    Reclamo obj;
    while(fread(&obj,sizeof(Reclamo),1,pFile)){
              if(obj.getIDReclamo() == id){
                fclose(pFile);
                return pos;              
              }
          pos++;
    }
    fclose(pFile);
    
    return -1;    
}

int ArchivoReclamo::cantidadRegistros(){
  FILE *pFile;
  int registros = 0;

  pFile = fopen(_nombreArchivo.c_str(),"rb");

  fseek(pFile,0,SEEK_END);

  registros = ftell(pFile)/sizeof(Reclamo);

  fclose(pFile);

  return registros;
}

bool ArchivoReclamo::backupCopia(){
    FILE *pFile, *pBackup;
    Reclamo obj;
    
    pFile = fopen(_nombreArchivo.c_str(),"rb");
    
    pBackup = fopen(_archivoBackup.c_str(),"wb");
    
    if(pFile == nullptr || pBackup == nullptr){
      return false;    
    }
    
    while(fread(&obj, sizeof(Reclamo),1,pFile)){
          fwrite(&obj, sizeof(Reclamo),1,pBackup);    
    }
      
    fclose(pFile);
    fclose(pBackup);
    
    return true;
}

bool ArchivoReclamo::restaurarBackup(){
    FILE *pFile, *pBackup;
    Reclamo obj;
    
    pBackup = fopen(_archivoBackup.c_str(),"rb");
    
    pFile = fopen(_nombreArchivo.c_str(),"wb");
    
    
    if(pFile == nullptr || pBackup == nullptr){
      return false;    
    }
    
    while(fread(&obj, sizeof(Reclamo),1,pBackup)){
          fwrite(&obj, sizeof(Reclamo),1,pFile);    
    }
      
    fclose(pBackup);
    fclose(pFile);
    
    return true;
}

void ArchivoReclamo::listarTitularesBackup(){
  FILE *pBackup;
  Reclamo obj;

  pBackup = fopen(_archivoBackup.c_str(), "rb");

  if(pBackup == nullptr){
    cout << "No se pudo abrir el archivo de backup";
    return;
  }
    while(fread(&obj,sizeof(Reclamo),1,pBackup)){
          if(!obj.getEliminado()){
            cout << "----------" << endl;
            obj.mostrar();
          }
    }
      fclose(pBackup);
}
