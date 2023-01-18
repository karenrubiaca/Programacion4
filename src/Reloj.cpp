#include <string>
#include <iostream>
#include <ctime>

using namespace std;
#include "../dataTypes/DataFecha.h"
#include "../include/IReloj.h"
#include "../include/Reloj.h"
class Fabrica;
class DataFecha;
Reloj * Reloj :: instancia = NULL;


Reloj::Reloj(){
fecha = NULL; }

Reloj * Reloj :: getInstanceReloj(){
	if (instancia == NULL){
	instancia = new Reloj();
	
	}
	return instancia;
}

void Reloj :: modificarFechaSistema(int dia, int mes, int anio, int hora){
	DataFecha *anterior=fecha;
        fecha = new DataFecha(dia,mes,anio,hora);
	delete anterior;
}

DataFecha *Reloj :: getFecha(){
	return fecha;
}