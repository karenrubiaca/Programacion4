#ifndef EMPLEADO
#define EMPLEADO
#include <string>
#include "Usuario.h"
#include <set>
#include <vector>
#include "Cargo.h"
#include "bits/stdc++.h"
#include "Responde.h"
#include "Notificacion.h"
#include "Hostal.h"
#include "IObserver.h"
#include "../dataTypes/DataEmpleado.h"

using namespace std;

class Hostal;
class Responde;
class Notificacion;
class Reserva;
class Estadia;
class Calificacion;
class Habitacion;
class DataReserva;
class Usuario;
class IObserver;

// agregar public observer
class Empleado : public Usuario, public IObserver
{
private:
	string cargo; // estaba de tipo cargo pero es un tipo enumerado asi q lo puse string pero hay q revisar
	vector<Notificacion> notificaciones;
	Hostal *hostal;
	vector<Responde> respuestas;

public:
	Empleado(string, string, string, string, Hostal*);
	string getCargo();
	void setCargo(string);
	Hostal *getHostal();
	void setHostal(Hostal*);
	
	vector<Responde> getRespuestas();
	void setRespuestas(Responde);
	// set<Notificacion> getNotificaciones();
	// void setNotificaciones(Notificacion);
	// void Notificar(Notificacion n);
	// DataReserva *getDatos();
	DataEmpleado *getDataUsuario();
	// ~Empleado();

//	DataEmpleado obtenerDatosEmpleado();
	vector<Notificacion> getNotificaciones();
	void borrarNotificaciones();
	//void setNotificaciones();
	void Notificar(Notificacion n);
};

#endif
