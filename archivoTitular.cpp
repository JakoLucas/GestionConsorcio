# include<iostream>
# include "archivoTitular.h"
# include <string.h>

using namespace std;

archivoTitular::archivoTitular(std::string titularArchivo, std::string archivoBackup, std::string titularCsv){
_titularArchivoNombre = titularArchivo;
_archivoBackup = archivoBackup;
_titularCsv = titularCsv;
}

bool archivoTitular::agregarTitular(Titular obj){
  FILE *pFile;
  bool control;

  pFile = fopen(_titularArchivoNombre.c_str(), "ab");

  if(pFile == nullptr){
    return false;
  }

  control = fwrite(&obj,sizeof(Titular),1,pFile);

  fclose(pFile);

  return control;
}

bool archivoTitular::buscarTitularPorDNI(const char* dni){
 FILE *pFile;
  pFile = fopen(_titularArchivoNombre.c_str(),"rb");

  if(pFile == nullptr){
    return false;}
  Titular obj;
  while(fread(&obj,sizeof(Titular),1,pFile)){
        if(strcmp(obj.getDNI(),dni)==0 && obj.getEliminado()==false){
          cout << "SE IDENTIFICO TITULAR " << endl;
          cout << endl;
            obj.mostrar();
            fclose(pFile);
            return true;}
          }
      fclose(pFile);
      return false;
}

bool archivoTitular::buscarTitularPorApellido(const char* apellido){
 FILE *pFile;
  pFile = fopen(_titularArchivoNombre.c_str(),"rb");

  if(pFile == nullptr){
    return false;}
  Titular obj;
  while(fread(&obj,sizeof(Titular),1,pFile)){
        if(strcmp(obj.getApellido(),apellido)==0 && obj.getEliminado()==false){
          cout << "SE IDENTIFICO TITULAR POR APELLIDO " << endl;
          cout << endl;
            obj.mostrar();
            fclose(pFile);
            return true;}
          }
      fclose(pFile);
      return false;
}

bool archivoTitular::modificarTitular(Titular obj, int pos){
  FILE *pFile;
  bool escribio;

  pFile = fopen(_titularArchivoNombre.c_str(),"rb+");

  if(pFile==nullptr){
    return false;
  }

  fseek(pFile,pos*sizeof(Titular),SEEK_SET);

  escribio = fwrite(&obj,sizeof(Titular),1,pFile);

  fclose(pFile);

  return escribio;
}

int archivoTitular::buscarTitular(const char* dni){
    Titular obj;

    FILE *pFile;

    pFile=fopen(_titularArchivoNombre.c_str(),"rb");

    if(pFile==nullptr){
    return -1;}

    int pos = 0;
    while(fread(&obj, sizeof(Titular),1,pFile)){
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

void archivoTitular::listarTitulares(){
  FILE *pFile;
  Titular obj;

  pFile = fopen(_titularArchivoNombre.c_str(), "rb");

  if(pFile == nullptr){
    exit(1);
  }
    while(fread(&obj,sizeof(Titular),1,pFile)){
          if(!obj.getEliminado()){
            cout << "----------" << endl;
            obj.mostrar();
          }
    }
      fclose(pFile);
}
int archivoTitular::eliminarTitular(const char* dni){
  Titular obj;
  int pos;
  pos=buscarTitular(dni);
  if(pos != -1){
  obj=leerTitular(pos);
  obj.setEliminado(true);
  return modificarTitular(obj,pos);
  }
  return 0;
}

int archivoTitular::cantidadRegistros(){
  FILE *pFile;
  int registros = 0;

  pFile = fopen(_titularArchivoNombre.c_str(),"rb");

  if(pFile==nullptr){
    registros = -1;
    return registros;
  }

  fseek(pFile,0,SEEK_END);

  registros = ftell(pFile)/sizeof(Titular);

  fclose(pFile);

  return registros;
}
Titular archivoTitular::leerTitular(int pos){
  FILE *pFile;

  Titular obj;

  pFile = fopen(_titularArchivoNombre.c_str(),"rb");

  if(pFile==nullptr){
    exit(1);
  }

  fseek(pFile,pos*sizeof(Titular),SEEK_SET);

  fread(&obj,sizeof(Titular),1,pFile);

  fclose(pFile);

  return obj;

}

bool archivoTitular::buscarApellido(string apellido){
 FILE *pFile;
  pFile = fopen(_titularArchivoNombre.c_str(),"rb");

  if(pFile == nullptr){
    return false;}
  Titular obj;
  while(fread(&obj,sizeof(Titular),1,pFile)){
        if(strcmp(obj.getApellido(),apellido.c_str())==0 && obj.getEliminado()==false){
            fclose(pFile);
            return true;}
          }
      fclose(pFile);
      return false;
}

bool archivoTitular::backupCopia(){
    FILE *pFile, *pBackup;
    Titular obj;
    
    pFile = fopen(_titularArchivoNombre.c_str(),"rb");
    
    pBackup = fopen(_archivoBackup.c_str(),"wb");
    
    if(pFile == nullptr || pBackup == nullptr){
      return false;    
    }
    
    while(fread(&obj, sizeof(Titular),1,pFile)){
          fwrite(&obj, sizeof(Titular),1,pBackup);    
    }
      
    fclose(pFile);
    fclose(pBackup);
    
    return true;
}

bool archivoTitular::restaurarBackup(){
    FILE *pFile, *pBackup;
    Titular obj;
    
    pBackup = fopen(_archivoBackup.c_str(),"rb");
    
    pFile = fopen(_titularArchivoNombre.c_str(),"wb");
    
    
    if(pFile == nullptr || pBackup == nullptr){
      return false;    
    }
    
    while(fread(&obj, sizeof(Titular),1,pBackup)){
          fwrite(&obj, sizeof(Titular),1,pFile);    
    }
      
    fclose(pBackup);
    fclose(pFile);
    
    return true;
}

void archivoTitular::listarTitularesBackup(){
  FILE *pBackup;
  Titular obj;

  pBackup = fopen(_archivoBackup.c_str(), "rb");

  if(pBackup == nullptr){
    cout << "No se pudo abrir el archivo de backup";
    return;
  }
    while(fread(&obj,sizeof(Titular),1,pBackup)){
          if(!obj.getEliminado()){
            cout << "----------" << endl;
            obj.mostrar();
          }
    }
      fclose(pBackup);
}
bool archivoTitular::exportarToCsv(){
      FILE *pFile;
      
      pFile = fopen(_titularArchivoNombre.c_str(), "rb");
      
      if(pFile == nullptr){
        return false;      
      }
      
      ofstream csv(_titularCsv);
      if(!csv.is_open()){
          fclose(pFile);
          return false;    
      }
      
      Titular obj;
      
    while(fread(&obj, sizeof(Titular), 1, pFile) == 1){

        if (!obj.getEliminado()) {
          
           csv << obj.toCsv() << "\n";
          }
      }
  
    fclose(pFile);
    csv.close();
    return true;
}
