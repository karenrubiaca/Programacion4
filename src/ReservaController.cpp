#include "../include/ReservaController.h"
#include "../include/colors/colors.hpp"


//#include "../include/ReservaIndividual.h"

#include <map>
#include <set>

using namespace std;
#include <iostream>
#include <string>

class DtaHostal;


ReservaController *ReservaController::instancia = NULL;

ReservaController *ReservaController::getInstance()
{
    if (instancia == NULL)
        instancia = new ReservaController();

    return instancia;
}

set<Hostal*> ReservaController::obtener_Hostales_Registrados(){
    HostalController *h = HostalController::getInstance();
    set<Hostal *> res = h->obtener_Hostales_Registrados();
    return res;
}


set<DtaHostal *> ReservaController::obtenerHostalesRegistrados()
{
    HostalController *h = HostalController::getInstance();
    set<DtaHostal *> res = h->obtenerHostalesRegistrados();
    return res;
}

set<string> ReservaController::obtenerNombresHostalesRegistrados()
{
    HostalController *h = HostalController::getInstance();
    set<string> ret = h->obtenerNombresHostalesRegistrados();
    return ret;
}

string nombreh;
DataFecha ci, co;
bool tipoRes;
void ReservaController::seleccionarNombreHostal(string nombre)
{
    // HostalController *h = HostalController::getInstance();
    nombreh = nombre;
}

void ReservaController::seleccionarHostal(string nombre, DataFecha checkIn, DataFecha checkOut, bool tipo)
{

    nombreh = nombre;
    ci = checkIn;
    co = checkOut;
    tipoRes = tipo;

    // cout<<checkIn.getDia()<<endl;
    // cout<<checkOut.getDia()<<endl;

    // this->codigo = 0;
}
set<int> ReservaController::obtenerHabitacionesDisponibles()
{

    HostalController *h = HostalController::getInstance();
    set<int> aux = h->obtenerHabitacionesDisponibles(nombreh, ci, co);

    for (set<int>::iterator itr = aux.begin(); itr != aux.end(); ++itr)
    {
        int current = *itr;
        cout <<colors::bright_cyan<<  "Habitacion numero"<< current <<colors::reset<< endl;
    }

    return aux;
}

int hab_selec;

void ReservaController::seleccionarHabitacion(int numHabASelec)
{
    hab_selec = numHabASelec;
}
set<string> conjuntoHuespedesSeleccionados;
void ReservaController::seleccionarHuesped(set<string> seleccion)
{
    conjuntoHuespedesSeleccionados = seleccion;
}
// tipoRes = 1 ----> Reserva Individual
// tipoRes = 0 ----> Reserva Grupal
int codigores = 0;
HostalController *aux = HostalController::getInstance();

UsuarioController *usrs = UsuarioController::getInstance();

void ReservaController::confirmarAsignacion()
{

    if (tipoRes == 1)
    {
        // tengo q crear reservaIndividual
        ReservaIndividual *nueva = new ReservaIndividual(codigores, ci, co, Abierta, 1000, conjuntoHuespedesSeleccionados);
        reservasIndividuales.insert(pair<int, ReservaIndividual *>(codigores, nueva));
        reservas.insert(pair<int, ReservaIndividual *>(codigores, nueva));
        aux->setReservaHabitacion(nueva, nombreh, hab_selec);
        codigores++;

        usrs->asignaReservas(nueva, conjuntoHuespedesSeleccionados);
        map<string, Huesped *> huesp = usrs->obtenerHuespedesRegistrados();
        map<int, Reserva *> corroborar = huesp.begin()->second->getReservas();
        Reserva *mierda = corroborar.begin()->second;
    }
    else
    {
        ReservaGrupal *nueva = new ReservaGrupal(codigores, ci, co, Abierta, 2000, conjuntoHuespedesSeleccionados.size(), conjuntoHuespedesSeleccionados);
        reservasGrupales.insert(pair<int, ReservaGrupal *>(codigores, nueva));
        reservas.insert(pair<int, ReservaGrupal *>(codigores, nueva));
        codigores++;
        aux->setReservaHabitacion(nueva, nombreh, hab_selec);
        usrs->asignaReservas(nueva, conjuntoHuespedesSeleccionados);
        map<string, Huesped *> huesp = usrs->obtenerHuespedesRegistrados();
        map<int, Reserva *> corroborar = huesp.begin()->second->getReservas();
        Reserva *mierda = corroborar.begin()->second;
    }
}
void ReservaController::obtenerReservas()
{
    aux->darInfoReservas(nombreh);
}
void ReservaController::obtenercodReservas()
{

    aux->darcodReservas(nombreh);
}

void ReservaController::confirmarBajaDeReserva(int codigoBaja, string hos)
{
    aux->bajaReservaDeHab(codigoBaja, hos);
    // usrs->bajaReservaDeHuesp(codigoBaja,conjuntoHuespedesSeleccionados);

    // CALIFICACIONES TAMBIEN DESPUES
}

string mail;
//------------------------------
string emailHuespedNotificar;
Huesped *ReservaController::ingresarEmailHuesped(string emailHuesped)
{

    emailHuespedNotificar=emailHuesped;

    UsuarioController *u = UsuarioController::getInstance();
    map<string, Huesped *> buscar = u->obtenerHuespedesRegistrados();
    Huesped *res = buscar.find(emailHuesped)->second;
    mail = emailHuesped;
    return res;
}

void ReservaController::MostrarReservasNoCanceladas(Huesped *emailHues)
{
    usrs->MostrarReservasNoCanceladas(emailHues->getEmail());
}

///////////////////////////REGISTRAR ESTADIA//////////////////////////////////////////////////////////////////
int i = 0;
int numeroHabitacion;
void ReservaController::seleccionarReserva(string nombreHost, Huesped *huespedEstadia, int reserva)
{
    HostalController *h = HostalController::getInstance();
    Hostal *res = h->obtenerInstanciaHostal(nombreHost);
    Reserva *buscada = reservas.find(reserva)->second;
    map<int, Habitacion *> aux = res->getHabitaciones();
    for (map<int, Habitacion *>::iterator i = aux.begin(); i != aux.end(); ++i)
    {
        map<int, Reserva *> reservas = i->second->getReservas();
        if (reservas.find(reserva) != reservas.end())
        { //////esta la reserva en esa habitacion me tengo q quedar con el numero
            numeroHabitacion = i->second->getNumHab();
        }
    }

    string codigo;
    codigo = "estadia" + to_string(i);
    DataFecha *coInicio = new DataFecha(0, 0, 0, 0);
    Reloj *r = Reloj::getInstanceReloj();
    DataFecha *inicio = r->getFecha();
    Estadia *nueva = new Estadia(nombreHost, huespedEstadia, buscada, numeroHabitacion, inicio, coInicio, codigo);
    codigo = "estadia" + to_string(i);
    buscada->agregarEstadia(nueva);
    usrs->setEstadia(nueva, mail, reserva);
    i= i+1;
}

void ReservaController::existeEstadiaActiva(Huesped *hues)
{


    Reloj *r = Reloj::getInstanceReloj();
    set<Estadia *> estHues = hues->getEstadias();
    for (set<Estadia *>::iterator i = estHues.begin(); i != estHues.end(); ++i ){
       Estadia * current = *i;
        if(current->getCheckOut()->getDia() == 0){
            DataFecha *co_fin = r->getFecha();
            current->setCheckOut(co_fin);
        }
        else{
            cout<<"No existe estadia activa para el huesped"<<hues->getNombre()<<endl;
        }
    }
}

void ReservaController::estadiasFinalizadas(Huesped *hues)
{
    set<Estadia *> estHues = hues->getEstadias();
    for (set<Estadia *>::iterator i = estHues.begin(); i != estHues.end(); ++i ){
       Estadia * current = *i;
        if(current->getCheckOut()->getDia() != 0){
            cout<<"Estadia de codigo"<<current->getCodigoEstadia()<<"finalizada"<<endl;
        }
        else{
            cout<<"No existe estadia cerrada para el huesped"<<hues->getNombre()<<endl;
        }
    }
}

void ReservaController::calificarEstadia(Huesped* hues,int calif,string coment, int idCal){
    Reloj *r = Reloj::getInstanceReloj();
    DataFecha *asiganr = r->getFecha();
    Calificacion *nuevacalif = new Calificacion(calif,idCal,coment,asiganr);
    hues->setCalificacion(nuevacalif);
    //nombreh
    HostalController *h = HostalController::getInstance();
    h->setCalificacion(nuevacalif, nombreh);

    //---------------------MODIFICAR (OBSERVER)
    Notificacion nuevaNotificacion = Notificacion(emailHuespedNotificar,coment,calif);
    //h->setNotificacion(nuevaNotificacion);
    h->Modificar(nuevaNotificacion);
    //------------------------------------------
}

