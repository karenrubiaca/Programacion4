#include "../include/Hostal.h"

Hostal::Hostal(){
    
}
 Hostal::Hostal(string nombre,string direccion,int telefono){
        this->nombre = nombre;
        this->direccion = direccion;
        this->telefono = telefono;
        //this->calificaciones = NULL;
        //this->reservas = reservas;
 }

 string Hostal::getDireccion(){
     return this->direccion;
 };

string Hostal::getNombre(){
    return this->nombre;
}

int Hostal::getTelefono(){
    return this->telefono;
}
void Hostal::setHabitacion(int h,Habitacion *aSett)
{
    this->habitaciones.insert(pair<int, Habitacion*>(h,aSett));
   
}

// set<Empleado> Hostal::setEmpleado(Empleado h){
//     this->empleados_Hostal.insert( h);
// }

map<int,Habitacion*> Hostal::getHabitaciones(){

    return this->habitaciones;
}

// set<Calificacion> Hostal::getCalificaciones(){

// }

// set<DataComentario> Hostal::darComSinResp(){

// }

// void Hostal::ingresarCom(string com){
    
// }

// DataHostal Hostal::getDataInfoBasicaHostal(){

// }

// void Hostal::crearCalificacion(string com,int cal ){

// }

// set<Reserva> Hostal::getReservas(){

// }

//HACER DESTRUCTOR 


// float Hostal::getPromedio(){
//     int contador = 0;
//     float total = 0;
//     for (std::set<Calificacion>::iterator it = calificaciones->begin(); it != calificaciones->end(); ++it){
//         contador++;
//         Calificacion actual = *it;
//         total += actual.getCalificacion();
//     }
//     return total/contador;
// }

void Hostal::darComSinResp(){
    map<int,Calificacion*> aux = this->calificaciones;

    for (map<int,Calificacion*>::iterator it=aux.begin(); it!=aux.end(); ++it){
        Calificacion* actual = it->second;
        if (actual->noRespuesta()){
            cout << "Calificacion codigo: " << actual->getIdCalificacion() << endl;
            cout << "Puntaje calificacion: " << actual->getCalificacion() << endl;
            cout << "Comentario: " << actual->getComentario() << endl; 
        }
    }
}

void Hostal::agregarCalificacion(Calificacion* c){
    this->calificaciones.insert(pair<int,Calificacion*>(c->getIdCalificacion(),c));
}

void Hostal::ingresarCom(string com, int idCom){
    map<int,Calificacion*> aux = this->calificaciones;
    Calificacion* actual = this->calificaciones.find(idCom)->second;
    actual->setRespuesta(com);
}

Calificacion* Hostal::getCalificacion(int cod){
    return this->calificaciones.find(cod)->second;
}

float Hostal::getPromedio(){
    float res = 0;
    int cont = 0;
    map<int,Calificacion*> aux = this->calificaciones;
    for (map<int,Calificacion*>::iterator it=aux.begin(); it!=aux.end(); ++it){
        Calificacion* actual = it->second;
        res = res + actual->getCalificacion();
        cont++;
    }
    if (cont != 0){
        res = res / cont;
    }
    return res;
}

map<int, Calificacion*> Hostal::getCalificaciones(){
    return this->calificaciones;
}

