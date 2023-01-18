#include "../include/Estadia.h"

Estadia::Estadia(string nom,Huesped *h, Reserva *res, int numH, DataFecha *ci, DataFecha* co, string cod_est)
{
    this->hostal = nom;
    this->huesped = h;
    this->reserva = res;
    this->habitacion = numH;
    this->checkIn = ci;
    this->checkOut = co;
    this->codigoEstadia = cod_est;


}
string Estadia::getHostal()
{
    return this->hostal;
}
Huesped *Estadia::getHuesped()
{
    return this->huesped;
}
Reserva *Estadia::getReserva()
{
    return this->reserva;
}
// Calificacion *getCalificacion();
int Estadia::getHabitacion()
{
    return this->habitacion;
}
DataFecha* Estadia::getCheckIn()
{
    return this->checkIn;
}
DataFecha *Estadia::getCheckOut()
{
    return this->checkOut;
}
string Estadia::getCodigoEstadia()
{
    return this->codigoEstadia;
}

void Estadia::setCheckOut(DataFecha* co)
{
    this->checkOut = co;
}
    
void Estadia::getDatos(){
    cout << "El hostal donde ese realizo la estadia es: " << this->hostal << endl;
    cout << "El huesped asociado a esta estadia es: " << this->huesped->getNombre() << endl;
    cout << "La estadia se realizo en la habitacion: " << this->habitacion << endl;
    DataFecha *data = this->getCheckIn();
    cout << "El checkIn de la estadia es: " << endl;
    cout << "El " << data->getDia()
       << " de " << data->getMes()
       << " de " << data->getAnio()
       << " a las " << data->getHora()
       << endl;
    if (this->checkOut->getDia() != 0){
        DataFecha *data = this->getCheckOut();
        cout << "El checkOut de la estadia es: " << endl;
        cout << "El " << data->getDia()
        << " de " << data->getMes()
        << " de " << data->getAnio()
        << " a las " << data->getHora()
        << endl;
    } else {
        cout << "La estadia aun no ha finalizado" << endl;
    }
    cout << "El codigo de la reserva es: " << this->reserva->getCodigo() << endl;
}
