#ifndef IHOSTALCONTROLLER
#define IHOSTALCONTROLLER
#include <string>
using namespace std;

#include <vector>
#include <set>
#include "../dataTypes/DataEstadia.h"
#include "../dataTypes/DataComentario.h"
#include "../dataTypes/DataEmpleado.h"
#include "../dataTypes/DataUsuario.h"
#include "Cargo.h"
#include "../dataTypes/DataDescripcion.h"
#include "../dataTypes/DataComentario.h"
#include "../dataTypes/DtaHostal.h"
#include "../dataTypes/DtEmpleado.h"
#include "../dataTypes/DatasHostal.h"
#include "../dataTypes/DataInfoBasicaHostal.h"
#include "Notificacion.h"

class IHostalController
{
public:
	virtual void ingresarDatosHostal(string, string, int) = 0;
	virtual set<string> obtenerNombresHostalesRegistrados() = 0;
	virtual set<DtaHostal*> obtenerHostalesRegistrados() = 0;
	virtual void seleccionarHostal(string) = 0;
	virtual void seleccionarHostal2(string) = 0;
	virtual void ingresarDatosHab(int, float, int) = 0;
	virtual void darAltaHabitacion() = 0;
	// virtual void cancelarAlta() = 0;
	virtual set<DtEmpleado*> obtenerEmpleadosNoAsignados() = 0;
	virtual void seleccionarEmpleado(string, string) = 0;
	// virtual void cancelarAsignacion() = 0;
	virtual void confirmarAsignacion() = 0;
	virtual void darcodReservas(string ) = 0;
	virtual void darInfoReservas(string) = 0;
	virtual vector<string> consultarTop3Hostales() = 0;//cambie aca tenia set
	virtual void verDetalles(string) = 0;
	virtual void verDetallesHabsHostal(string) =0;
	// virtual void ingresarEmailHuesped(string) = 0;
	// virtual set<DataEstadia> obtenerEstadiasFinalizadasHuesped() = 0;
	// virtual void seleccionarEstadia(int) = 0;
	// virtual void ingresarMensaje(string, int) = 0;
	// virtual void ingresarEmail(string) = 0;
	virtual void obtenerComentariosSinRespuesta() = 0;
	// virtual void seleccionComentario(int) = 0;
	virtual void ingresarComentario(string, int) = 0;
	// virtual void setReservaHabitacion(Reserva*,string,int);
	virtual void infoHabitaciones() = 0;
	virtual DataInfoBasicaHostal obtenerInformacionBasicaHostal() = 0;
	virtual void obtenerEstadiasRegistradas() = 0;
	virtual void verCalificacion(int) = 0;
	virtual void datosEstadia(int) = 0;
	
	
	virtual void suscribirEmpleado(IObserver*, string)=0;
	//virtual vector<DataEmpleado> obtenerEmpleadosSuscriptos() = 0;
	virtual void eliminarEmpleado(IObserver*, string) = 0;
	virtual vector<Notificacion> obtenerNotificaciones(string) = 0;
	virtual set<string> obtenerEmpleadosAsignados() = 0;
	virtual Empleado* obtenerEmpleado(string) = 0;
};

#endif
