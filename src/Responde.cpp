#include "../include/Responde.h"

Responde::Responde(string com){
    this->comentario = com;
}

string Responde::getComentario(){
    return this->comentario;
}
