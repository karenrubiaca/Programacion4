#ifndef HOSTALCONTROLLER
#define HOSTALCONTROLLER
#include <string>
#include <map>
#include <vector>
#include "../dataTypes/DataEstadia.h"
#include "../dataTypes/DataInfoBasicaHostal.h"
#include "../dataTypes/DtaHostal.h"
#include "Hostal.h"
#include "IObserver.h"
#include "../dataTypes/DataComentario.h"
#include "../dataTypes/DataEmpleado.h"
#include "../dataTypes/DtEmpleado.h"
#include "Cargo.h"
#include "../dataTypes/DataDescripcion.h"
#include "IHostalController.h"

using namespace std;

class Hostal;


class HostalController : public IHostalController
{
private:
	map<string, Hostal*> hostales;
	map<string, Hostal> hostales2;
	map<int,Reserva*> ress;
	static HostalController *instancia;

	vector<Calificacion*> calificaciones;
	map<string,IObserver*> suscriptos;
	Notificacion nueva;
	HostalController();


public:
	static HostalController *getInstance();
	void ingresarDatosHostal(string, string, int);
	set<string> obtenerNombresHostalesRegistrados();
	set<DtaHostal*> obtenerHostalesRegistrados();
	set<Hostal*> obtener_Hostales_Registrados();
	void seleccionarHostal(string);
void  seleccionarHostal2(string);
	void ingresarDatosHab(int, float, int);
	void darAltaHabitacion();
	// void cancelarAlta();
	void darInfoReservas(string);
	set<DtEmpleado*> obtenerEmpleadosNoAsignados();
	void seleccionarEmpleado(string, string);
	// void cancelarAsignacion();
	void confirmarAsignacion();
	vector<string> consultarTop3Hostales();
	void verDetalles(string);
	// void ingresarEmailHuesped(string);
	// set<DataEstadia> obtenerEstadiasFinalizadasHuesped();
	// void seleccionarEstadia(int);
	// void ingresarMensaje(string, int);
	// void ingresarEmail(string);
	void obtenerComentariosSinRespuesta();
	// void seleccionComentario(int);
	DataInfoBasicaHostal obtenerInformacionBasicaHostal();
	// // set<DataHostal> obtenerHostalesRegistrados();
	// void seleccionarHostal(string, DataFecha, DataFecha, bool);
	set<int> obtenerHabitacionesDisponibles(string,DataFecha,DataFecha);
	void setReservaHabitacion(Reserva*,string,int);
	void darcodReservas(string aConsultar);
	void bajaReservaDeHab(int, string);
	Hostal* obtenerInstanciaHostal(string);
	void setCalificacion(Calificacion*, string);
	void ingresarComentario(string, int);
	void obtenerEstadiasRegistradas();
	void verDetallesHabsHostal(string);
	void infoHabitaciones();
	void verCalificacion(int);
	void datosEstadia(int);


	//void agregar(Empleado);//agrega el empleado a los suscriptos
	//void eliminar(Empleado);//elimina el empleado de los suscriptos
	void suscribirEmpleado(IObserver*, string);//ingreso el email del que se va a suscribir, busco el Empleado y lo suscribo con agregar
	void eliminarEmpleado(IObserver*, string);//ingreso el email del que se va a suscribir, busco el Empleado y lo borro con eliminar
	void agregarCalificacion(Calificacion*);
	//vector<DataEmpleado> obtenerEmpleadosSuscriptos();	
	//void setNotificacion(Notificacion n); //notifico a todos
	void Modificar(Notificacion n);//activo Notificar a los suscriptos
	vector<Notificacion> obtenerNotificaciones(string);
	set<string> obtenerEmpleadosAsignados();
	Empleado* obtenerEmpleado(string);

};

#endif
