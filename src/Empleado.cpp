#include "../include/Empleado.h"
string xD;
//Hostal x(xD,xD,6,NULL,NULL,NULL);
Empleado::Empleado(string nombre,string email,string pass,string cargo,Hostal *h){

    this->nombre = nombre;
    this->email = email;
    this->password = pass;
    this->cargo = cargo ;
    this->hostal = h;

}

string Empleado::getCargo(){
    return this->cargo;
}

void Empleado::setCargo(string cargo){
    this->cargo = cargo;
}
Hostal* Empleado::getHostal(){
    return this->hostal;
}

void Empleado::setHostal(Hostal *h){
    this->hostal = h;
}

DataEmpleado* Empleado::getDataUsuario(){
    Cargo aux;
    if (this->cargo == "Administracion")
        aux = Administracion;
    if (this->cargo == "Limpieza")
        aux = Limpieza;
    if (this->cargo == "Infraestructura")
        aux = Infraestructura;
    if (this->cargo == "Recepcion")
        aux = Recepcion;
    DataEmpleado *aux2 = new DataEmpleado(this->getNombre(),this->getEmail(),this->hostal->getNombre(),aux);

    return aux2;
}


/*DataEmpleado Empleado::obtenerDatosEmpleado(){
    Hostal *h=this->hostal;
    DataEmpleado ret(this->nombre, this->email, h->getNombre(), this->cargo);
    return ret;
}*/

vector<Notificacion> Empleado::getNotificaciones(){
    return notificaciones;
}

//void Empleado::setNotificaciones(){
  //  while (!notificaciones.empty())
	//notificaciones.pop_back();

//}

vector<Responde> Empleado::getRespuestas(){
	return respuestas;}

void Empleado::setRespuestas(Responde r){
	respuestas.push_back(r);
	}

void Empleado::Notificar(Notificacion n){//agrega n a las notificaciones del empleado
    notificaciones.push_back(n);
}

void Empleado::borrarNotificaciones(){
    vector<Notificacion> res;
    this->notificaciones = res;
}
