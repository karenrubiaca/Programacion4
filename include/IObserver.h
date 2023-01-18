#ifndef IOBSERVER
#define IOBSERVER
#include "Notificacion.h"
#include <vector>

class IObserver
{
public:
	virtual void Notificar(Notificacion n) = 0;
	virtual vector<Notificacion> getNotificaciones() = 0;
	virtual void borrarNotificaciones() = 0;
};

#endif
