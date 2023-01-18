#ifndef RELOJ
#define RELOJ
#include <string>
#include <iostream>
#include "../dataTypes/DataFecha.h"
#include "IReloj.h"

class Reloj : public IReloj
{
private:
	static Reloj *instancia;
	DataFecha *fecha;
	Reloj();

public:
	static Reloj *getInstanceReloj();
	void modificarFechaSistema(int, int, int, int);
	DataFecha *getFecha();
};

#endif
