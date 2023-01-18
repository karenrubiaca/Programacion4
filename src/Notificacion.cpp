#include "../include/Notificacion.h"
#include <string>
#include <iostream>
using namespace std;
Notificacion :: Notificacion(){}
Notificacion :: Notificacion(string autor, string comentario,int puntaje){
	this->autor=autor;
	this->comentario=comentario;
	this->puntaje=puntaje;
}
string Notificacion :: getAutor(){
		return (this->autor);
}
string Notificacion :: getComentario(){	
	return (this->comentario);
}
int Notificacion :: getPuntaje(){
		return (this->puntaje);
}

Notificacion :: ~Notificacion(){
}
		 

ostream &operator<<(ostream &os, Notificacion &f)
{
   os << "Notificacion:" << endl;
   os << "Autor: " << f.getAutor() << endl;
   os << "Direccion: " << f.getComentario() << endl;
   os << "Calificacion Promedio: " << f.getPuntaje() << endl;
   return os;
}