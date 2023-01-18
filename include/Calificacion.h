#ifndef CALIFICACION
#define CALIFICACION
#include <set>
#include <vector>
// #include "../dataTypes/DataComentario.h"
#include "Responde.h"
// #include "Hostal.h"
class DataFecha;
class Responde;
#include <string>
using namespace std;

class Calificacion{
	private:
		int idCalificacion;
		int calificacion;
	 	string comentario;
	 	Responde* Respuesta;
		DataFecha *hora;
	public:
	
		Calificacion(int, int, string,DataFecha*);
		int getCalificacion();
	 	string getComentario();
		void setRespuesta(string);
	 	Responde* getRespuesta();
	// 	void setRespuestas(set<Responde>);
	 	bool noRespuesta();
		void setHora(DataFecha);
	// 	DataComentario darDatos();
	// 	void responder(string);
	 	int getIdCalificacion();
	// 	float obtenerPromedioCalificaciones();
	// 	void borrarRespuestas();
	// 	 ~Calificacion();
};

#endif
