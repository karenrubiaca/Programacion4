#include "../include/Calificacion.h"

Calificacion::Calificacion( int cal,int id, string com, DataFecha* nueva){
    this->idCalificacion = id;
    this->calificacion = cal;
    this->comentario = com;
    this->Respuesta = NULL;
    this->hora = nueva;
}

int Calificacion::getCalificacion(){
    return this->calificacion;
}

int Calificacion::getIdCalificacion(){
    return this->idCalificacion;
}


string Calificacion::getComentario(){
     return this->comentario;
}

void Calificacion::setRespuesta(string com){
    Responde* r = new Responde(com);
    this->Respuesta = r;
}

Responde* Calificacion::getRespuesta(){
    return this->Respuesta;
}



// set<Responde> Calificacion::getRespuestas(){
//     return this->Respuestas;
// }

// void Calificacion::setRespuestas(set<Responde> r){
//     this->Respuestas = r;
// }

bool Calificacion::noRespuesta(){
    return (this->Respuesta == NULL);
}

// DataComentario Calificacion::darDatos(){
//     DataComentario res(this->idCalificacion, this->comentario);
// }

// void Calificacion::responder(string respuesta){
// }

// int Calificacion::getIdCalificacion(){
//     return this->idCalificacion;
// }

// void Calificacion::borrarRespuestas(){
//     //llamar al destructor de Responde?
//     set<Responde>::iterator it;
//     for (it = this->Respuestas.begin(); it != this->Respuestas.end(); ++it){
//         this->Respuestas.erase(it);
//     }
// }

// Calificacion::~Calificacion(){
    
// }
