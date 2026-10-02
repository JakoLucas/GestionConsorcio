# include<iostream>
# include "ArchivoServicio.h"

using namespace std;

ArchivoServicio::ArchivoServicio(std::string nombreArchivo, std::string archivoBackup){
  _nombreArchivo = nombreArchivo;
  _archivoBackup = archivoBackup;
}
bool ArchivoServicio::agregarRegistro(Servicio obj){
    FILE *pFile;
    
    pFile = fopen(_nombreArchivo.c_str(), "ab");
    
    bool registro;
    
    registro = fwrite(&obj, sizeof(Servicio), 1, pFile);
    
    fclose(pFile);
    
    return registro;
}
int ArchivoServicio::buscarRegistro(int id){
      FILE *pFile;
      
      pFile = fopen(_nombreArchivo.c_str(), "rb");
      
      int pos = 0;
      Servicio obj;
      
      while(fread(&obj,sizeof(Servicio),1,pFile)){
            if(obj.getIDServicio() == id){
                fclose(pFile);
                return pos;            
            }
              pos++;
          }
      fclose(pFile);
      return -1;
}
bool ArchivoServicio::modificarRegistro(Servicio obj, int pos){
      FILE *pFile;
      
      pFile = fopen(_nombreArchivo.c_str(),"rb+");
      
      if(pFile == nullptr){
        cout << "NO SE PUDO ABRIR EL ARCHIVO " << endl;
        exit(1);      
      }
      
      bool registro;
      
      fseek(pFile, pos*sizeof(obj),SEEK_SET);
      
      registro = fwrite(&obj, sizeof(Servicio),1,pFile);
      
      fclose(pFile);
      
      return registro;
}
void ArchivoServicio::listarRegistros(){
      FILE *pFile;
      
      pFile = fopen(_nombreArchivo.c_str(),"rb");
      
      if(pFile == nullptr){
        cout << "NO SE PUDIERON LEER LOS REGISTROS" << endl;
        exit(1);      
      }
      
      Servicio obj;
      
      while(fread(&obj,sizeof(Servicio),1,pFile)){
        if(obj.getEliminado() == false){
          cout <<"-----------------"<< endl;
            obj.mostrar();                  
          }  
        }
        
        fclose(pFile);
}
Servicio ArchivoServicio::leerRegistro(int pos){
      FILE *pFile;
      
      pFile = fopen(_nombreArchivo.c_str(), "rb");
      
      if(pFile == nullptr){
        cout << "NO SE PUDO LEER REGISTRO " << endl;
        exit(1);      
      }
      
      Servicio obj;
      
      fseek(pFile, pos*sizeof(Servicio),SEEK_SET);
      
      fread(&obj, sizeof(Servicio), 1, pFile);
      
      fclose(pFile);
      
      return obj;
}

int ArchivoServicio::cantidadRegistros(){
  FILE *pFile;
  int registros = 0;

  pFile = fopen(_nombreArchivo.c_str(),"rb");

  fseek(pFile,0,SEEK_END);

  registros = ftell(pFile)/sizeof(Servicio);

  fclose(pFile);

  return registros;
}

bool ArchivoServicio::backupCopia(){
    FILE *pFile, *pBackup;
    Servicio obj;
    
    pFile = fopen(_nombreArchivo.c_str(),"rb");
    
    pBackup = fopen(_archivoBackup.c_str(),"wb");
    
    if(pFile == nullptr || pBackup == nullptr){
      return false;    
    }
    
    while(fread(&obj, sizeof(Servicio),1,pFile)){
          fwrite(&obj, sizeof(Servicio),1,pBackup);    
    }
      
    fclose(pFile);
    fclose(pBackup);
    
    return true;
}

bool ArchivoServicio::restaurarBackup(){
    FILE *pFile, *pBackup;
    Servicio obj;
    
    pBackup = fopen(_archivoBackup.c_str(),"rb");
    
    pFile = fopen(_nombreArchivo.c_str(),"wb");
    
    
    if(pFile == nullptr || pBackup == nullptr){
      return false;    
    }
    
    while(fread(&obj, sizeof(Servicio),1,pBackup)){
          fwrite(&obj, sizeof(Servicio),1,pFile);    
    }
      
    fclose(pBackup);
    fclose(pFile);
    
    return true;
}

void ArchivoServicio::listarTitularesBackup(){
  FILE *pBackup;
  Servicio obj;

  pBackup = fopen(_archivoBackup.c_str(), "rb");

  if(pBackup == nullptr){
    cout << "No se pudo abrir el archivo de backup";
    return;
  }
    while(fread(&obj,sizeof(Servicio),1,pBackup)){
          if(!obj.getEliminado()){
            cout << "----------" << endl;
            obj.mostrar();
          }
    }
      fclose(pBackup);
}
