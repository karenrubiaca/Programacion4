#ifndef DATACOMENTARIO
#define DATACOMENTARIO
#include <string>
using namespace std;


class DataComentario{
	private:
		//int idComentario;
		int calificacion;
		string comentario;
		
	public:
		DataComentario();
		DataComentario(int,string);
		int getIdComentario();
		string getComentario();
		int getCalificacion();
	//friend ostream &operator<<(ostream &os,DataComentario*); 
	// firend es una funcion global que necesita acceso a mimebros de clases privadas o protegidas
};

#endif
