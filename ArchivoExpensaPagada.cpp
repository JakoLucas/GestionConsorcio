# include<iostream>
# include "ArchivoExpensaPagada.h"

using namespace std;

ArchivoExpensaPagada::ArchivoExpensaPagada(std::string nombreArchivo, std::string archivoBackup){
  _nombreArchivo = nombreArchivo;
  _archivoBackup = archivoBackup;
}

bool ArchivoExpensaPagada::agregarRegistro(expensaPagada obj){
    FILE *pFile;
    
    pFile = fopen(_nombreArchivo.c_str(), "ab");
    
    bool registro;
    
    registro = fwrite(&obj, sizeof(expensaPagada), 1, pFile);
    
    fclose(pFile);
    
    return registro;
}
int ArchivoExpensaPagada::buscarRegistro(int id){
      FILE *pFile;
      
      pFile = fopen(_nombreArchivo.c_str(), "rb");
      
      if(pFile == nullptr){
        return -1;      
      }
      
      int pos = 0;
      expensaPagada obj;
      
      while(fread(&obj,sizeof(expensaPagada),1,pFile)){
            if(obj.getIDExpensa() == id){
                fclose(pFile);
                return pos;            
            }
              pos++;
          }
      fclose(pFile);
      return -1;
}
bool ArchivoExpensaPagada::modificarRegistro(expensaPagada obj, int pos){
      FILE *pFile;
      
      pFile = fopen(_nombreArchivo.c_str(),"rb+");
      
      if(pFile == nullptr){
        cout << "NO SE PUDO ABRIR EL ARCHIVO " << endl;
        exit(1);      
      }
      
      bool registro;
      
      fseek(pFile, pos*sizeof(obj),SEEK_SET);
      
      registro = fwrite(&obj, sizeof(expensaPagada),1,pFile);
      
      fclose(pFile);
      
      return registro;
}
void ArchivoExpensaPagada::listarRegistros(){
      FILE *pFile;
      
      pFile = fopen(_nombreArchivo.c_str(),"rb");
      
      if(pFile == nullptr){
        cout << "NO SE PUDIERON LEER LOS REGISTROS" << endl;
        exit(1);      
      }
      
      expensaPagada obj;
      
      while(fread(&obj,sizeof(expensaPagada),1,pFile)){
        if(obj.getEliminado() == false){
          cout <<"-----------------"<< endl;
            obj.mostrar();                  
          }  
        }
        
        fclose(pFile);
}
expensaPagada ArchivoExpensaPagada::leerRegistro(int pos){
      FILE *pFile;
      
      pFile = fopen(_nombreArchivo.c_str(), "rb");
      
      if(pFile == nullptr){
        cout << "NO SE PUDO LEER REGISTRO " << endl;
        exit(1);      
      }
      
      expensaPagada obj;
      
      fseek(pFile, pos*sizeof(expensaPagada),SEEK_SET);
      
      fread(&obj, sizeof(expensaPagada), 1, pFile);
      
      fclose(pFile);
      
      return obj;
}
int ArchivoExpensaPagada::cantidadRegistros(){
  FILE *pFile;
  int registros = 0;

  pFile = fopen(_nombreArchivo.c_str(),"rb");

  if(pFile==nullptr){
    registros = -1;
    return registros;
  }

  fseek(pFile,0,SEEK_END);

  registros = ftell(pFile)/sizeof(expensaPagada);

  fclose(pFile);

  return registros;
}
bool ArchivoExpensaPagada::backupCopia(){
    FILE *pFile, *pBackup;
    expensaPagada obj;
    
    pFile = fopen(_nombreArchivo.c_str(),"rb");
    
    pBackup = fopen(_archivoBackup.c_str(),"wb");
    
    if(pFile == nullptr || pBackup == nullptr){
      return false;    
    }
    
    while(fread(&obj, sizeof(expensaPagada),1,pFile)){
          fwrite(&obj, sizeof(expensaPagada),1,pBackup);    
    }
      
    fclose(pFile);
    fclose(pBackup);
    
    return true;
}

bool ArchivoExpensaPagada::restaurarBackup(){
    FILE *pFile, *pBackup;
    expensaPagada obj;
    
    pBackup = fopen(_archivoBackup.c_str(),"rb");
    
    pFile = fopen(_nombreArchivo.c_str(),"wb");
    
    
    if(pFile == nullptr || pBackup == nullptr){
      return false;    
    }
    
    while(fread(&obj, sizeof(expensaPagada),1,pBackup)){
          fwrite(&obj, sizeof(expensaPagada),1,pFile);    
    }
      
    fclose(pBackup);
    fclose(pFile);
    
    return true;
}

void ArchivoExpensaPagada::listarTitularesBackup(){
  FILE *pBackup;
  expensaPagada obj;

  pBackup = fopen(_archivoBackup.c_str(), "rb");

  if(pBackup == nullptr){
    cout << "No se pudo abrir el archivo de backup";
    return;
  }
    while(fread(&obj,sizeof(expensaPagada),1,pBackup)){
          if(!obj.getEliminado()){
            cout << "----------" << endl;
            obj.mostrar();
          }
    }
      fclose(pBackup);
}
