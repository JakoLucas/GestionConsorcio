# include<iostream>
# include "ManagerInformes.h"

using namespace std;
void ManagerInformes::informeAnual(){
      /// SE UTILIZA DE LA CLASE EXPENSAPAGA UN OBJETO PUNTERO
      /// HACEMOS UNA COPIA DE REGISTROS expensaPaga.dat
      int registrosExpensaPaga;
      ArchivoExpensaPagada expensaPaga;
      expensaPagada *vecExpensaPaga;
      
      registrosExpensaPaga = expensaPaga.cantidadRegistros();
      
      vecExpensaPaga = new expensaPagada[registrosExpensaPaga];
      
      if(vecExpensaPaga == nullptr){
        cout << "NO SE PUDO ASIGNAR MEMORIA ";
        return;      
      }
    
      for(int i = 0; i < registrosExpensaPaga; i++){
        vecExpensaPaga[i] = expensaPaga.leerRegistro(i);      
      }
      int anio;
      rlutil::locate(53,3);
      rlutil::setColor(rlutil::GREEN);
      cout << "INFORME RECAUDACION ANUAL " << endl;
      rlutil::setColor(rlutil::WHITE);
      rlutil::locate(53,4);
      cout << "--------------------------" << endl;
      
      rlutil::locate(46,7); 
      cout << "INGRESE ANIO A CONSULTAR LOS 4 DIGITOS: ";
      cin>> anio;
      cout << endl;
      if(anio<999){
        rlutil::locate(46,8); 
        rlutil::setColor(rlutil::RED);
        cout << "ANIO INCORRECTO" << endl;
        rlutil::setColor(rlutil::WHITE);
        return;
      
      }
      ///VARIABLE ENTERA PARA CALCULAR REGISTROS DE AÑO INGRESADO
      int registrosAnios=0;
      ///VECTOR FLOTANTE
      ///LO UTILIZO PARA GUARDAR EN CADA POSICION DEL MES EL MONTO ACUMULADO
      float acuMensual[12]{};
      for(int i = 0; i < registrosExpensaPaga; i++){
         if(vecExpensaPaga[i].getFechaPago().getAnio() == anio){
        acuMensual[vecExpensaPaga[i].getFechaPago().getMes() -1] += vecExpensaPaga[i].getMontoPago();
          registrosAnios++;
          }
      }
      ///CHEQUEAMOS SI HAY REGISTROS
      if(registrosAnios==0){
        rlutil::locate(56,12);
        rlutil::setColor(rlutil::RED);
        cout << "NO HAY REGISTROS " << endl;
        rlutil::setColor(rlutil::WHITE);
      }
      
      ///VARIABLE FLOTANTE
      /// ACUMULAMOS EL TOTAL ANUAL
      float acuAnual = 0;
      for(int i = 0; i < 12; i++){
        acuAnual += acuMensual[i];
      }
      /// VECTOR STRING
      string vecMeses[12] = {"ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO"
      ,"JULIO", "AGOSTO", "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE"};
      ///RECORREMOS EL VECTOR ANUAL
      rlutil::locate(47,10); 
      cout << "MES ";
      rlutil::locate(76,10);
      cout << "TOTAL";
      rlutil::locate(46,11);
      cout << "---------------------------------------";
      int x = 46;
      int y = 12;
      for(int i = 0; i < 12; i++){
        if(acuMensual[i]>0){
          rlutil::locate(x,y);
          cout << vecMeses[i];
          rlutil::locate(x+15,y);
          cout << "RECAUDO ";
          rlutil::locate(x+30,y);
          cout <<"$"<< acuMensual[i];
            y++;
          }
       }
       cout << endl;
      ///MOSTRAMOS LO ACUMULADO EN EL AÑO
      rlutil::locate(46,22);
      rlutil::setColor(rlutil::GREEN);
      cout << "RECAUDACION TOTAL ANUAL:" <<" $"<< acuAnual << endl;
      rlutil::setColor(rlutil::WHITE);
      cout << endl;
      ///ELIMINAMOS LA MEMORIA DINAMICA PEDIDA
      delete[] vecExpensaPaga;
}




void ManagerInformes::rankingDeudores(){
      
      /// objeto archivos;
      ArchivoExpensa expensaArchi;
      ArchivoExpensaPagada expensaPagaArchi; 
      ArchivoUnidadFuncional registroUnidad;
      
      ///objeto puntero de las clases
      UnidadFuncional *departamentos;
      Expensa *FacturaExpensa;
      expensaPagada *expensaPagos;
      
      ///enteros para guardar cantidad de registros
      int cantidadFacturas, cantidadPagos, registroDeptos;
      
      cantidadFacturas = expensaArchi.cantidadRegistros();
      cantidadPagos = expensaPagaArchi.cantidadRegistros();
      registroDeptos = registroUnidad.cantidadRegistros();
      
      ///asignación dinamica de memoria
      FacturaExpensa = new Expensa[cantidadFacturas];
      expensaPagos = new expensaPagada[cantidadPagos];
      departamentos = new UnidadFuncional[registroDeptos];
      
      if(FacturaExpensa == nullptr || expensaPagos == nullptr || departamentos == nullptr){
          cout << "NO SE PUDO ASIGNAR ESPACIO EN MEMORIA " <<endl;
          return;      
      }
      
      ///cargamos los vectores con los registros de cada archivo correspondiente
      for(int i = 0; i < cantidadFacturas; i++){
          FacturaExpensa[i] = expensaArchi.leerRegistro(i);      
      }
      for(int i = 0; i < cantidadPagos; i++){
          expensaPagos[i] = expensaPagaArchi.leerRegistro(i);      
      }
      for(int i = 0 ; i < registroDeptos; i++){
        departamentos[i] = registroUnidad.leerRegistro(i);      
      }
      ///PUNTERO FLOAT
      ///CARGADO CON EL TAMAÑO ARCHIVO EXPENSA
      float *vecDeudas;
      vecDeudas = new float [cantidadFacturas];
      
      if(vecDeudas == nullptr){
        cout << "ERROR EN VEC DEUDAS" << endl;
        system("pause");
        return;      
      }
      for(int i = 0; i < cantidadFacturas; i++){
        vecDeudas[i] = 0;      
      }
      ///usamos un triple bucle for.
      ///bucle mas externo cargamos en el vector dinamico el monto total de las expensas
      ///en el mas interno descontamos cada pago en el registro de la unidad correspondiente
      ///y el intermedio nos fijamos si la unidad es la misma que el vector dinamico de registro departamentos para mostrar el dni titular
      
      rlutil::locate(46,3);
      rlutil::setColor(rlutil::GREEN);
      cout << "RANKING DEUDORES " << endl;
      rlutil::setColor(rlutil::WHITE);
      rlutil::locate(46,4);
      cout << "-----------------" << endl;
      cout << endl;
      for(int i = 0; i <cantidadFacturas; i++){
          int unidad;
          vecDeudas[i] = FacturaExpensa[i].getMontoTotal();
        for(int j = 0; j <cantidadPagos; j++){
          if(FacturaExpensa[i].getIDUnidad() == expensaPagos[j].getIDUnidad()){
                 vecDeudas[i] -= expensaPagos[j].getMontoPago();
                 unidad = FacturaExpensa[i].getIDUnidad();              
          }
        } 
          rlutil::locate(25,7);
            cout << "-----------------------------------------------------------";
            rlutil::locate(26,6);
            rlutil::setColor(rlutil::GREEN);
            cout << "UNIDAD ";
            rlutil::locate(49,6);
            cout << "TITULAR ";
            rlutil::locate(72,6);
            cout << "TOTAL ";
            rlutil::setColor(rlutil::WHITE);
            cout << endl;
            int x = 25;
            int y = 8;
          for(int k = 0; k <registroDeptos; k++){
            if(vecDeudas[k]>0 && departamentos[k].getIDUnidad() == unidad){
            rlutil::locate(x,y);
            rlutil::setColor(rlutil::YELLOW);
            cout << "DEPARTAMENTO: ";
            rlutil::setColor(rlutil::WHITE);
            cout << unidad;
            rlutil::locate(x+23,y);
            rlutil::setColor(rlutil::YELLOW);
            cout << "DNI: ";
            rlutil::setColor(rlutil::WHITE);
            cout << departamentos[k].getDniTitular();
            rlutil::locate(x+45,y);
            rlutil::setColor(rlutil::YELLOW);
            cout << "DEUDA: ";
            rlutil::setColor(rlutil::WHITE);
            cout << "$";
            cout << vecDeudas[k];
            }
               y++;
          }
        
      }
        rlutil::locate(35,12);
        rlutil::anykey();
      ///hacemos la eliminación de la memoria utilizada en la heap
      delete[] vecDeudas;
      delete[] FacturaExpensa;
      delete[] expensaPagos;
      delete[] departamentos;
}

void ManagerInformes::informeEficiencia(){
      ///USO DE ARCHIVO - RECLAMO Y SERVICIO
      ArchivoReclamo reclamosArchivo;
      ArchivoServicio servicioArchivo;
      Reclamo *constanciaReclamo;
      Servicio *servicioPrestado;
      
      int cantidadReclamos, cantidadServicios;
      
      cantidadReclamos = reclamosArchivo.cantidadRegistros();
      
      cantidadServicios = servicioArchivo.cantidadRegistros();
      ///PEDIMOS MEMORIA
      constanciaReclamo = new Reclamo[cantidadReclamos];
      
      servicioPrestado = new Servicio[cantidadServicios];
      
      if(constanciaReclamo == nullptr || servicioPrestado == nullptr){
        cout << "NO SE PUDO CARGAR VECTORES DINAMICOS " << endl;
          return;}
      ///CARGAMOS LOS VECTORES
     for(int i = 0; i < cantidadServicios; i++){
        servicioPrestado[i] = servicioArchivo.leerRegistro(i);
     }
     
    for(int i = 0; i < cantidadReclamos; i++){
        constanciaReclamo[i] = reclamosArchivo.leerRegistro(i);
     }
     
     ///DECLARAMOS UN VECTOR STRING CON SERVICIOS YA ASIGNADOS
     string vecEmpresas[5]={" ASCENSOR ", " PLOMERIA   ", " CRISTALERIA ", " ELECTRICISTA ", " PILETERO  "};
     /// DECLARAMOS UN VECTOR Y ENTERO
      int reclamo = 0;
      int vectorTipoServicio[5]{};
      /// BUSCAMOS EL TIPO DE PROBLEMA Y LO ASIGNAMOS AL ENTERO Y LUEGO LO GUARDAMOS EN EL VECTOR EN LA POSICION SERVICIO CORRESPONDIENTE EL RECLAMO
      for(int i = 0; i <cantidadReclamos; i++){
          reclamo = constanciaReclamo[i].getTipoProblema();
          vectorTipoServicio[reclamo-1]++;
      }
      rlutil::locate(40,3);
      rlutil::setColor(rlutil::GREEN);
      cout << "INFORME EFICIENCIA PROVEEDORES " << endl;
      rlutil::setColor(rlutil::WHITE);
      rlutil::locate(40,4);
      cout << "------------------------------ " <<endl;
      cout << endl;
      int x = 15;
      int y = 8;     
     /// MOSTRAMOS LOS SERVICIOS CON RECLAMOS
      for(int i = 0; i < 5; i++){
          if(vectorTipoServicio[i]>0){
        rlutil::locate(x,y);
        rlutil::setColor(rlutil::YELLOW);
        cout << "PROVEEDOR: ";
        rlutil::setColor(rlutil::WHITE);
        cout << servicioPrestado[i].getEmpresaProveedor();
        rlutil::locate(x+28,y);
        rlutil::setColor(rlutil::YELLOW);
        cout << " SERVICIO PRESTADO: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecEmpresas[i];
        rlutil::locate(x+60,y);
        rlutil::setColor(rlutil::YELLOW);
        cout << " RECLAMOS ";
        rlutil::setColor(rlutil::WHITE);
        cout << vectorTipoServicio[i];    
          y++;
          }
      }
      cout << endl;
      cout << endl;
      ///ELIMINACION DE PEDIDO MEMORIA
      delete[] constanciaReclamo;
      delete[] servicioPrestado;
}

void ManagerInformes::reporte(){
      ///DECLARACION DE ENTEROS PARA OBTENER LA CANTIDAD DE REGISTROS EN LOS ARCHIVOS
      int cantidadRegistrosResidente, cantidadRegistrosTitular, unidadesEdificio;
      float promedio=0;
      
      residenteArchivo archivoResidente;
      archivoTitular titularArchivo;
      ArchivoEdificio edificioArchivo;
      
      Edificio edificioReg;
      Titular titu;
      /// PUNTERO OBJ RESIDENTE - OBJ
      Residente *vecResidente, integrante;
      
      edificioReg = edificioArchivo.leerEdificio(0);
      unidadesEdificio = edificioReg.getCantidadUnidades();
      
      cantidadRegistrosTitular = titularArchivo.cantidadRegistros();
      cantidadRegistrosResidente = archivoResidente.cantidadRegistros();
      
      /// PEDIMOS MEMORIA PARA EL PUNTERO OBJ
      vecResidente = new Residente[cantidadRegistrosResidente];
      
      if(vecResidente == nullptr){
        cout << "NO SE PUDO ASIGNAR MEMORIA AL PUNTERO RESIDENTE " << endl;
        return;      
      }
      ///LO CARGAMOS
      for(int i = 0; i < cantidadRegistrosResidente; i++){
          vecResidente[i] = archivoResidente.leerResidente(i);      
      }
      
      ///PROMEDIO PERSONAL POR UNIDAD, CASTEAMOS EL FLOAT
      promedio = (float)cantidadRegistrosResidente / unidadesEdificio;
      
      ///DECLARACION VARIABLES Y VECTOR
      int vecRangoEdades[3]={};
      int anio = 2025;
      int nacimientoIntegrante, edad;
            ///BUSCAMOS EL AÑO DE NACIMIENTO INTEGRANTE
            ///LO DESCONTAMOS CON EL AÑO ACTUAL
            ///LO ASIGNAMOS EN EL RANGO DE EDAD CORRESPONDIENTE
            for(int j = 0; j < cantidadRegistrosResidente; j++){
              
              nacimientoIntegrante = vecResidente[j].getFechaNacimiento().getAnio();
              edad = anio - nacimientoIntegrante;
              
              if(edad>60){
                vecRangoEdades[2]++;              
              }
              if(edad>=19 && edad<= 60){
                  vecRangoEdades[1]++;              
              }
              if(edad>0 && edad<19){
                  vecRangoEdades[0]++;             
              }
            }
        ///MOSTRAMOS RESLTADOS
        rlutil::locate(40,3);
        rlutil::setColor(rlutil::GREEN);
        cout << "REPORTE DE OCUPACION Y DEMOGRAFIA " << endl;
        rlutil::locate(40,4);
        rlutil::setColor(rlutil::WHITE);
        cout << "----------------------------------" << endl;
        cout << endl;
        rlutil::locate(40,6);
        rlutil::setColor(rlutil::YELLOW);
        cout << "RESIDENTES: ";
        rlutil::setColor(rlutil::WHITE);
        cout << cantidadRegistrosResidente;
        rlutil::locate(40,7);
        rlutil::setColor(rlutil::YELLOW);
        cout << "PROMEDIO POR UNIDAD: ";
        rlutil::setColor(rlutil::WHITE);
        cout << promedio;
        cout << endl;
        rlutil::locate(40,8);
        rlutil::setColor(rlutil::YELLOW);
        cout << "RESIDENTES EDAD (1-18): ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecRangoEdades[0];
        rlutil::locate(40,9);
        rlutil::setColor(rlutil::YELLOW);
        cout << "RESIDENTES EDAD (19-60): ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecRangoEdades[1];
        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(40,10);
        cout << "RESIDENTES EDAD (+60): ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecRangoEdades[2];
        cout << endl;
        ///ELIMINAMOS MEMORIA DINAMICA
        delete[] vecResidente;     
}
void ManagerInformes::informeIncidencia(){
      ///DECLARACION DE ENTEROS - PUNTEROS - OBJTS
      int unidades, pisos, registrosReclamo, registrosExpensa, registrosExpensaPaga, *vecUnidadesTotal;
      float *vecMontoDeudaUnidades;
      Edificio edificioReg;
      ArchivoEdificio edificioArchivo;
      Reclamo *vecReclamo;
      ArchivoReclamo reclamoArchivo;
      Expensa *vecExpensa;
      ArchivoExpensa expensaArchivo;
      expensaPagada *vecExpensaPaga;
      ArchivoExpensaPagada expensaPagaArchivo;
      
      edificioReg = edificioArchivo.leerEdificio(0);
      ///ASIGNACION CANTIDAD REGISTROS
      unidades = edificioReg.getCantidadUnidades();
      pisos = edificioReg.getCantidadPisos();
      registrosReclamo = reclamoArchivo.cantidadRegistros();
      registrosExpensa = expensaArchivo.cantidadRegistros();
      registrosExpensaPaga = expensaPagaArchivo.cantidadRegistros();
      ///PEDIDO DE MEMORIA DINAMICA
      vecExpensa = new Expensa[registrosExpensa];
      vecExpensaPaga = new expensaPagada[registrosExpensaPaga];
      vecReclamo = new Reclamo[registrosReclamo];
      vecUnidadesTotal = new int [unidades]();
      vecMontoDeudaUnidades = new float [unidades]();
      
      if(vecReclamo == nullptr || vecUnidadesTotal == nullptr || vecExpensa == nullptr || vecExpensaPaga == nullptr || vecMontoDeudaUnidades == nullptr){
        cout << "PUNTEROS VACIOS" << endl;
        return;      
      }
      ///CARGA DE REGISTROS EN VECTORES
      for(int i = 0; i < registrosExpensa; i++){
        vecExpensa[i] = expensaArchivo.leerRegistro(i);      
      }
      
      for(int i = 0; i < registrosExpensaPaga; i++){
          vecExpensaPaga[i] = expensaPagaArchivo.leerRegistro(i);      
      }
      ///CARGA DE VECTOR Y ASIGNACION
      ///CONTAMOS RECLAMO UNIDAD CORRESPONDIENTE
      int unidad;
      for(int i = 0; i < registrosReclamo; i++){
        vecReclamo[i] = reclamoArchivo.leerRegistro(i);    
          unidad = vecReclamo[i].getIDUnidad();
            vecUnidadesTotal[unidad-1]++;                
      }
      ///ASIGNAMOS EL MONTO FACTURA EXPENSA EN CADA UNIDAD
      for(int i = 0; i <registrosExpensa; i++){
              
          vecMontoDeudaUnidades[vecExpensa[i].getIDUnidad()-1] = vecExpensa[i].getMontoTotal(); 
      }
      ///DESCONTAMOS EL MONTO PAGADO POR UNIDAD
      for(int i = 0; i <registrosExpensaPaga; i++){
          vecMontoDeudaUnidades[vecExpensaPaga[i].getIDUnidad()-1] -= vecExpensaPaga[i].getMontoPago();      
      }
      ///MOSTRAMOS LA CANTIDAD DE RECLAMOS Y DEUDA POR PISO
      int piso = pisos/pisos;
      rlutil::locate(43,3);
      rlutil::setColor(rlutil::GREEN);
      cout << "INCIDENCIAS POR PISO " << endl;
      rlutil::locate(43,4);
      rlutil::setColor(rlutil::WHITE);
      cout << "---------------------" << endl;
      cout << endl;
      int x = 28;
      int y = 6;
      for(int i = 0; i < unidades; i++){
            if(vecUnidadesTotal[i]){
            rlutil::locate(x,y);
            rlutil::setColor(rlutil::YELLOW);
            cout << "DEPARTAMENTO: ";
            rlutil::setColor(rlutil::WHITE);
            cout << i+1;
            rlutil::locate(x+18,y);
            rlutil::setColor(rlutil::YELLOW);
            cout << "CANTIDAD DE RECLAMOS: ";
            rlutil::setColor(rlutil::WHITE);
            cout << vecUnidadesTotal[i];
            rlutil::locate(x+42,y);
            rlutil::setColor(rlutil::YELLOW);
            cout << "DEUDA: ";
            rlutil::setColor(rlutil::WHITE);
            cout << "$";
            cout << vecMontoDeudaUnidades[i]; 
            y++;         
            }
        }
        cout << endl;
        cout << endl;
      ///ELIMINAMOS MEMORIA DINAMICA
      delete[] vecExpensa;
      delete[] vecExpensaPaga;
      delete[] vecReclamo;
      delete[] vecUnidadesTotal;
      delete[] vecMontoDeudaUnidades;
}
