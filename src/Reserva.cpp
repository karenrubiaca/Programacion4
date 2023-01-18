#include "../include/Reserva.h"

// Reserva::Reserva(){
    
// }


DataFecha Reserva::getCheckIn(){
    return this->checkIn;
}

DataFecha Reserva::getCheckOut(){
    return this->checkOut;
}
int Reserva::getCodigo(){
    return this->codigo;
}
EstadoReserva Reserva::getEstado(){
     
 
    // Creating Gender type variable
    EstadoReserva aux = this->estado;
 
    switch (aux)
    {
    case Cerrada:
        cout << "Cerrada";
        break;
    case Abierta:
        cout << "Abierta";
        break;
    
        
    }
    return this->estado;
}

set<string> Reserva::getHuesped(){
    return this->huesped;
}

// DataFecha Reserva::setCheckIn(DataFecha d){
//     this->checkIn = d;
// }

// DataFecha Reserva::setCheckOut(DataFecha d){
//     this->checkOut = d;
// }

void Reserva::setEstado(EstadoReserva e){
    this->estado = e;
}

// int Reserva::obtenerIdReserva(){
//     return this->codigo;
// }

// void Reserva::cerrarReserva(){
//     this->estado = Cerrada;
// }

void Reserva::agregarEstadia(Estadia* e){
    this->estadias.insert(pair<string,Estadia*>(e->getCodigoEstadia(), e));
}

map<string, Estadia*> Reserva::getEstadias(){
    return this->estadias;
}

