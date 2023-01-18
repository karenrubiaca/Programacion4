#ifndef IRELOJ
#define IRELOJ
#include <string>
#include "../dataTypes/DataFecha.h"

class IReloj
{
public:
	virtual void modificarFechaSistema(int, int, int, int) = 0;
	virtual DataFecha * getFecha() = 0;
	virtual ~IReloj(){};

};

#endif
