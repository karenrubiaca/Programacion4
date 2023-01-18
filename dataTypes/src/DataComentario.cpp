#include "../DataComentario.h"
#include <iostream>

DataComentario::DataComentario(int cal, string texto){
    this->calificacion = cal;
    this->comentario = texto;
}

//int DataComentario::getIdComentario(){
  //  return this->idComentario;
//}

int DataComentario::getCalificacion(){
	return this->calificacion;
}


string DataComentario::getComentario(){
    return this->comentario;
}


//ostream &operator<< (ostream &os, DataComentario* comment) {

//	os 	<< "----------------------------------------\n"
//		<< "ID del comentario: " << comment->getIdComentario() << endl
//		<< "Comentario: " << comment->getComentario() << endl;
//	os	<< "----------------------------------------\n";

//	return os;
//}
