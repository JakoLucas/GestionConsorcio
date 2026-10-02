# include<iostream>
# include "ArchivoExpensa.h"

using namespace std;

ArchivoExpensa::ArchivoExpensa(std::string nombreArchivo, std::string archivoBackup){
  _nombreArchivo = nombreArchivo;
  _archivoBackup = archivoBackup;
}

bool ArchivoExpensa::agregarRegistro(Expensa obj){
    FILE *pFile;
    
    pFile = fopen(_nombreArchivo.c_str(), "ab");
    
    bool registro;
    
    registro = fwrite(&obj, sizeof(Expensa), 1, pFile);
    
    fclose(pFile);
    
    return registro;
}
int ArchivoExpensa::buscarRegistro(int id){
      FILE *pFile;
      
      pFile = fopen(_nombreArchivo.c_str(), "rb");
      
      if(pFile == nullptr){
        cout << "NO SE PUDO ABRIR EL ARCHIVO " << endl;
        return -1;      
      }
      
      int pos = 0;
      Expensa obj;
      
      while(fread(&obj,sizeof(Expensa),1,pFile)){
            if(obj.getIDExpensa() == id){
                fclose(pFile);
                return pos;            
            }
              pos++;
          }
      fclose(pFile);
      return -1;
}
bool ArchivoExpensa::modificarRegistro(Expensa obj, int pos){
      FILE *pFile;
      
      pFile = fopen(_nombreArchivo.c_str(),"rb+");
      
      if(pFile == nullptr){
        cout << "NO SE PUDO ABRIR EL ARCHIVO " << endl;
        exit(1);      
      }
      
      bool registro;
      
      fseek(pFile, pos*sizeof(obj),SEEK_SET);
      
      registro = fwrite(&obj, sizeof(Expensa),1,pFile);
      
      fclose(pFile);
      
      return registro;
}
void ArchivoExpensa::listarRegistros(){
      FILE *pFile;
      
      pFile = fopen(_nombreArchivo.c_str(),"rb");
      
      if(pFile == nullptr){
        cout << "NO SE PUDIERON LEER LOS REGISTROS" << endl;
        exit(1);      
      }
      
      Expensa obj;
      
      while(fread(&obj,sizeof(Expensa),1,pFile)){
        if(obj.getEliminado() == false){
          cout <<"-----------------"<< endl;
            obj.mostrar();                  
          }  
        }
        
        fclose(pFile);
}
Expensa ArchivoExpensa::leerRegistro(int pos){
      FILE *pFile;
      
      pFile = fopen(_nombreArchivo.c_str(), "rb");
      
      if(pFile == nullptr){
        cout << "NO SE PUDO LEER REGISTRO " << endl;
        exit(1);      
      }
      
      Expensa obj;
      
      fseek(pFile, pos*sizeof(Expensa),SEEK_SET);
      
      fread(&obj, sizeof(Expensa), 1, pFile);
      
      fclose(pFile);
      
      return obj;
}
int ArchivoExpensa::cantidadRegistros(){
  FILE *pFile;
  int registros = 0;

  pFile = fopen(_nombreArchivo.c_str(),"rb");

  if(pFile==nullptr){
    registros = -1;
    return registros;
  }

  fseek(pFile,0,SEEK_END);

  registros = ftell(pFile)/sizeof(Expensa);

  fclose(pFile);

  return registros;
}

bool ArchivoExpensa::backupCopia(){
    FILE *pFile, *pBackup;
    Expensa obj;
    
    pFile = fopen(_nombreArchivo.c_str(),"rb");
    
    pBackup = fopen(_archivoBackup.c_str(),"wb");
    
    if(pFile == nullptr || pBackup == nullptr){
      return false;    
    }
    
    while(fread(&obj, sizeof(Expensa),1,pFile)){
          fwrite(&obj, sizeof(Expensa),1,pBackup);    
    }
      
    fclose(pFile);
    fclose(pBackup);
    
    return true;
}

bool ArchivoExpensa::restaurarBackup(){
    FILE *pFile, *pBackup;
    Expensa obj;
    
    pBackup = fopen(_archivoBackup.c_str(),"rb");
    
    pFile = fopen(_nombreArchivo.c_str(),"wb");
    
    
    if(pFile == nullptr || pBackup == nullptr){
      return false;    
    }
    
    while(fread(&obj, sizeof(Expensa),1,pBackup)){
          fwrite(&obj, sizeof(Expensa),1,pFile);    
    }
      
    fclose(pBackup);
    fclose(pFile);
    
    return true;
}

void ArchivoExpensa::listarTitularesBackup(){
  FILE *pBackup;
  Expensa obj;

  pBackup = fopen(_archivoBackup.c_str(), "rb");

  if(pBackup == nullptr){
    cout << "No se pudo abrir el archivo de backup";
    return;
  }
    while(fread(&obj,sizeof(Expensa),1,pBackup)){
          if(!obj.getEliminado()){
            cout << "----------" << endl;
            obj.mostrar();
          }
    }
      fclose(pBackup);
}
