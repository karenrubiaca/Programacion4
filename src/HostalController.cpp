#include "../include/HostalController.h"
#include "../include/Fabrica.h"
#include <map>
#include <set>
#include <iostream>
#include "../include/colors/colors.hpp"

using namespace std;

class DataDescripcion;

HostalController::HostalController(){
    nueva = Notificacion();
}

HostalController *HostalController::instancia = NULL;

HostalController *HostalController::getInstance()
{
    if (instancia == NULL)
        instancia = new HostalController();

    return instancia;
}

void HostalController::ingresarDatosHostal(string nom, string dir, int tel)
{

    // el controlador se encarga de decirle a
    // la clase hostal que cree una instancia de hostal
    // Hostal h = Hostal(nom, dir, tel); // alta de hostal solo pide los primeros 3 parametros,
    Hostal *haux = new Hostal(nom, dir, tel); // lo otro se va a ir agregando a medida que avanza
                                              // hostales.insert(pair<string, Hostal*>(nom, &h));

    // creada la instancia h
    // se agrega a la coleccion de hostales
    hostales.insert(pair<string, Hostal *>(nom, haux)); // hay que ver si tenemos un arreglo de objetos o un arreglo de punteros a objetos,
                                                        // en este caso tengo un arreglo de punteros a objetos, por eso en el parametro
                                                        // de push_back le paso la direccion de memoria donde apunta h (el objeto)
                                                        // no estoy seguro de esto que puse.
}

vector<string> HostalController::consultarTop3Hostales()
{
    //     //Fabrica *fabrica = Fabrica::getInstance();
    ReservaController *r = ReservaController::getInstance();
    set<Hostal *> CalifHostales = r->obtener_Hostales_Registrados();
    vector<string> resultado;
    set<Hostal *>::iterator it = CalifHostales.begin();
    Hostal *primero;
    Hostal *segundo;
    Hostal *tercero;
    Hostal *actual; // recorro los primero tres hostales
    primero = *it;

    ++it;
    actual = *it;
    if (primero->getPromedio() >= actual->getPromedio())
        segundo = actual;
    else
    {
        segundo = primero;
        primero = actual;
    }
    ++it;
    actual = *it;
    if (actual->getPromedio() > primero->getPromedio())
    {
        tercero = segundo;
        segundo = primero;
        primero = *it;
    }
    else if (actual->getPromedio() > segundo->getPromedio())
    {
        tercero = segundo;
        segundo = *it;
    }
    else
        tercero = *it;

    ++it; // termine de asignar los primero tres que se que existen

    for (set<Hostal *>::iterator i = it; i != CalifHostales.end(); ++i)
    { // para los que quedan
        actual = *i;
        // cout << "El promedio de " << actual->getNombre() << " es " << actual->getPromedio() << endl;
        if (actual->getPromedio() > tercero->getPromedio())
        {
            if (actual->getPromedio() > segundo->getPromedio())
            {
                if (actual->getPromedio() > primero->getPromedio())
                {
                    tercero = segundo;
                    segundo = primero;
                    primero = *i;
                }
                else
                {
                    tercero = segundo;
                    segundo = *i;
                }
            }
            else
            {
                tercero = *i;
            }
        }
    }
    string nombre1 = primero->getNombre();
    string nombre2 = segundo->getNombre();
    string nombre3 = tercero->getNombre();
    resultado.push_back(nombre1);
    resultado.push_back(nombre2);
    resultado.push_back(nombre3);
    // esto accede al nombre del hostal?
    // necesito saber como inserta, si no puede ser que primero no quede primero
    //     //vector<string> resultado;
    return resultado;
}

void HostalController::verDetalles(string nombreHostal)
{
    std::map<string, Hostal *>::iterator it;
    it = hostales.find(nombreHostal);
    Hostal *h = it->second;
    map<int, Calificacion *> cal = h->getCalificaciones();
    //     set<int> calificaciones;
    //     set<string> comentarios;
    //     //recorrer el set de calificaciones
    int cont = 1;
    for (std::map<int, Calificacion *>::iterator it = cal.begin(); it != cal.end(); ++it)
    {
        Calificacion *c = it->second;
        cout << "Calificacion numero " << cont << ":" << endl;
        int cal = c->getCalificacion();
        string com = c->getComentario();
        cout << "La calificacion es: " << cal << " y el comentario " << com << endl;
        cont++;
        //         calificaciones.insert(cal);
        //         comentarios.insert(com);
    }
    //     DataHabitacion hab;
    //     float f = -1;
    //     DataDescripcion d(comentarios,calificaciones,f,hab);
    //     return d;
}

set<string> HostalController::obtenerNombresHostalesRegistrados()
{
    set<string> res;

    for (std::map<string, Hostal *>::iterator it = hostales.begin(); it != hostales.end(); ++it)
    {
        res.insert(it->first);
        cout << "-" << (it->first) << endl;
        // cout << "huespedes:";
        // cout << it->first << endl;
        // cout<<it->first<<endl;
    }
    return res;
}

string hostalAconsultar;
void HostalController::seleccionarHostal(string nomhost)
{
    map<string, Hostal *>::iterator itr = hostales.find(nomhost);
    if (itr != hostales.end())
    {

        hostalAconsultar = nomhost;
    }
    else
    {
        cout << nomhost << " no encontrado\n";
        throw(404);
    }
}

Hostal *seleccionado;
void HostalController::seleccionarHostal2(string aSeleccionar)
{
    map<string, Hostal *>::iterator itr = hostales.find(aSeleccionar);

    if (itr != hostales.end())
    {
        seleccionado = itr->second;
        // cout << "2"+ seleccionado->getNombre()<<endl;
        // cout << seleccionado->getDireccion()<<endl;
        // cout << seleccionado->getTelefono() <<endl;
    }
    else
    {
        cout << aSeleccionar << " no encontrado\n";
        throw(404);
    }
}

set<DtEmpleado *> HostalController::obtenerEmpleadosNoAsignados()
{

    set<DtEmpleado *> empleadosNuevos;
    UsuarioController *u = UsuarioController::getInstance();
    map<string, Empleado *> empleadosaux = u->obtenerEmpleadosRegistrados();

    // // obtengo los nombres de los usuarios registrados

    for (map<string, Empleado *>::iterator i = empleadosaux.begin(); i != empleadosaux.end(); ++i)
    {
        //    cout<< "PRIMER EMPLEADO: "<<i->second->getHostal()->getNombre();

        if (i->second->getHostal()->getTelefono() == 0)
        {
            DtEmpleado *nuevo = new DtEmpleado(i->second->getNombre(), i->first, i->second->getCargo());
            cout << "EMPLEADOS NO ASIGNADOS: " << endl;
            cout << nuevo->getNombre() << endl;
            empleadosNuevos.insert(nuevo);
            //    cout<<nuevo->getEmail();
        }
        // return empleadosNuevos;
        // // Base class pointer holding
        // // Derived1 Class object
        //     Usuario* bp = dynamic_cast<Usuario*>(&);

        // // Dynamic_casting
        //     Empleado* dp2 = dynamic_cast<Empleado*>(bp);

        //     char *cargo = bp->getCargo();
        //      string nombre = i->first;
        //      string email = i->second.getEmail();
        //      DtEmpleado *dt = new DtEmpleado(nombre,email,NULL);
        //     // empleadosNuevos.insert(*dt);
        //     //destruir aca pq sino perdemos la memoria del anterior cada vez que entra al for

        //  }
    }
    return empleadosNuevos;
}

string empleadoSelec, cargo;

void HostalController::seleccionarEmpleado(string empleado, string cargo)
{
    empleadoSelec = empleado;
}

void HostalController::confirmarAsignacion()
{
    // cout<<"si";
    UsuarioController *aux = UsuarioController::getInstance();
    map<string, Empleado *> empAux = aux->obtenerEmpleadosRegistrados();
    Empleado *selec = empAux.find(empleadoSelec)->second;

    Hostal *auxHost;
    for (map<string, Hostal *>::iterator itr = hostales.begin(); itr != hostales.end(); ++itr)
    {
        // set<Reserva> getReservas(DataFecha, DataFecha);
        if (itr->second->getNombre() == hostalAconsultar)
        {
            selec->setHostal(itr->second);
        }

        // cout << //selec->getHostal()->getNombre();
        //  empAux.erase(empleadoSelec);
    }
}
int numeroHab;
float precioHabitacion;
int capacidadHab;
void HostalController::ingresarDatosHab(int numHab, float precioHab, int capHab)
{
    numeroHab = numHab;
    precioHabitacion = precioHab;
    capacidadHab = capHab;
}

void HostalController::darAltaHabitacion()
{
    //   Hostal *seleccionado = new Hostal("xx","aca",986);
    //  Habitacion *nueva = new Habitacion(5,5,2,seleccionado);
    Habitacion *nueva = new Habitacion(numeroHab, precioHabitacion, capacidadHab, seleccionado);
    map<int, Habitacion *> aux = seleccionado->getHabitaciones();
    if (aux.find(numeroHab) != aux.end())
    {
        cout << colors::bright_red << "La habitacion ya se encontraba dada de alta en el sistema" << endl;
    }
    else
    {
        seleccionado->setHabitacion(numeroHab, nueva);
        //map<int, Habitacion *> habaux = seleccionado->getHabitaciones();
        cout << "\nLa habitacion numero " << numeroHab << " fue dada de alta correctamente" << endl;
    }
}

// void HostalController::cancelarAlta(){
//     delete seleccionado; //??????????
// }

DataInfoBasicaHostal HostalController::obtenerInformacionBasicaHostal()
{
    bool existe = false;
    ;

    for (std::map<string, Hostal *>::iterator it = hostales.begin(); it != hostales.end(); ++it)
    {
        if (it->second->getNombre() == hostalAconsultar)
        {
            DataInfoBasicaHostal nuevo(it->first, it->second->getDireccion(), it->second->getTelefono());
            existe = true;
            return nuevo;
        }
    }
    if (!existe)
    {
        throw(404);
    }
}

///////////////////////////////REALIZAR RESERVA////////////////////////

set<Hostal *> HostalController::obtener_Hostales_Registrados()
{
    set<Hostal *> res;
    for (std::map<string, Hostal *>::iterator it = hostales.begin(); it != hostales.end(); ++it)
    {
        Hostal *actual = it->second;

        res.insert(actual);
    }
    return res;
}

set<DtaHostal *> HostalController::obtenerHostalesRegistrados()
{
    set<DtaHostal *> res;
    for (std::map<string, Hostal *>::iterator it = hostales.begin(); it != hostales.end(); ++it)
    {
        string nombre = it->second->getNombre();
        string direccion = it->second->getDireccion();

        // float promCal = it->second->getPromedio();	bool operator<(DataFecha);
        // DtaHostal d(nombre, direccion, promCal);
        DtaHostal *d = new DtaHostal(nombre, direccion, 55);

        res.insert(d);
    }
    return res;
}

set<int> HostalController::obtenerHabitacionesDisponibles(string hostalAconsultar, DataFecha ci, DataFecha co)
{
    set<int> aDevolver;

    for (std::map<string, Hostal *>::iterator it = hostales.begin(); it != hostales.end(); ++it)
    {

        if (it->second->getNombre() == hostalAconsultar)
        {

            map<int, Habitacion *> hab = it->second->getHabitaciones();

            for (map<int, Habitacion *>::iterator itr = hab.begin(); itr != hab.end(); ++itr)
            {

                bool disponible = itr->second->getReservasDisponibles(ci, co);
                if (disponible)
                {

                    aDevolver.insert(itr->first);
                }
            }
        }
    }
    // for (set<int>::iterator itr = aDevolver.begin(); itr != aDevolver.end(); ++itr)
    // {
    //     int current = *itr;
    //     cout << current << endl;
    // }
    return aDevolver;
}

void HostalController::setReservaHabitacion(Reserva *nueva, string nombreHostal, int numHabitacion)
{
    this->ress.insert(pair<int, Reserva *>(nueva->getCodigo(), nueva));
    Hostal *asett = hostales.find(nombreHostal)->second;
    map<int, Habitacion *> habi = asett->getHabitaciones();
    for (map<int, Habitacion *>::iterator itr = habi.begin(); itr != habi.end(); ++itr)
    {
        if (itr->first == numHabitacion)
        {
            itr->second->setReservas(nueva->getCodigo(), nueva);
            map<int, Reserva *> auxx = itr->second->getReservas();
            Reserva *ver = auxx.find(nueva->getCodigo())->second;
        }
    }
}
//////me da todas las reservas de las habitaciones de un hostal///////////////
void HostalController::darInfoReservas(string aConsultar)
{

    Hostal *consulta = hostales.find(aConsultar)->second;
    map<int, Habitacion *> hab = consulta->getHabitaciones();
    for (map<int, Habitacion *>::iterator itr = hab.begin(); itr != hab.end(); ++itr)
    {
        map<int, Reserva *> reservasHab = itr->second->getReservas();
        if (!reservasHab.empty())
        {
            cout << "La habitacion con numero de habitacion  " << itr->first << "  tiene las siguientes reservas" << endl;
            for (map<int, Reserva *>::iterator i = reservasHab.begin(); i != reservasHab.end(); ++i)
            {
                cout << "el codigo de la reserva es: " << i->second->getCodigo() << endl;
                set<string> h = i->second->getHuesped();
                cout << "los huespedes son: ";
                for (set<string>::iterator iit = h.begin(); iit != h.end(); ++iit)
                {
                    string current = *iit;
                    cout << "- " << current << endl;
                }
            }
        }
    }
}

void HostalController::darcodReservas(string aConsultar)
{
    int contr = 0;
    Hostal *consulta = hostales.find(aConsultar)->second;
    map<int, Habitacion *> hab = consulta->getHabitaciones();
    cout << "Los codigos de las reservas disponibles son:";
    for (map<int, Habitacion *>::iterator itr = hab.begin(); itr != hab.end(); ++itr)
    {
        map<int, Reserva *> reservasHab = itr->second->getReservas();
        for (map<int, Reserva *>::iterator i = reservasHab.begin(); i != reservasHab.end(); ++i)
        {
            cout << "Reserva" << contr << ": " << i->second->getCodigo() << endl;
            contr++;
        }
    }
}
void HostalController::bajaReservaDeHab(int codigoBaja, string nombreHostal)
{

    Hostal *h = this->hostales.find(nombreHostal)->second;
    map<int, Habitacion *> habi = h->getHabitaciones();
    for (map<int, Habitacion *>::iterator itr = habi.begin(); itr != habi.end(); ++itr)
    {
        map<int, Reserva *> reservasHab = itr->second->getReservas();
        if (!reservasHab.empty())
        {
            std::map<int, Reserva *>::iterator itr2 = reservasHab.find(codigoBaja);
            if (itr2 != reservasHab.end())
            {
                //    delete itr2->second;
                reservasHab.erase(itr2);
                itr->second->setReservas2(reservasHab);
            }
        }
        map<int, Reserva *> reservasHab2 = itr->second->getReservas();
        if (!reservasHab2.empty())
        {
            std::map<int, Reserva *>::iterator itr3 = reservasHab2.find(codigoBaja);
            if (itr3 != reservasHab2.end())
            {
                cout << "sigue estando" << itr3->first;
            }
        }
    }

    ////////////////////////////borro de hostalcontroller/////////////////////////////
    std::map<int, Reserva *>::iterator itr2 = ress.find(codigoBaja);
    if (itr2 != ress.end())
    {
        // found it - delete it
        delete itr2->second;
        ress.erase(itr2);
    }
    std::map<int, Reserva *>::iterator itr3 = ress.find(codigoBaja);
    if (itr3 == ress.end())
    {
    }
}

Hostal *HostalController::obtenerInstanciaHostal(string inst_hos)
{
    map<string, Hostal *>::iterator itr = hostales.find(inst_hos);

    if (itr != hostales.end())
    {
        return itr->second;
    }
    else
    {
        cout << inst_hos << " no encontrado\n";
        return 0;
    }
}

void HostalController::setCalificacion(Calificacion *c, string nombre)
{
    Hostal *h = this->hostales.find(nombre)->second;
    h->agregarCalificacion(c);
}

void HostalController::obtenerComentariosSinRespuesta()
{
    UsuarioController *u = UsuarioController::getInstance();
    string hostal = u->darHostalTrabaja(empleadoSelec);
    // cout << "Trabaja en:" << hostal << endl;
    Hostal *aux = this->hostales.find(hostal)->second;
    hostalAconsultar = aux->getNombre();
    aux->darComSinResp();
}

void HostalController::ingresarComentario(string com, int idCom)
{
    Hostal *aux = this->hostales.find(hostalAconsultar)->second;
    aux->ingresarCom(com, idCom);
}

void HostalController::obtenerEstadiasRegistradas()
{
    Hostal *h = this->hostales.find(hostalAconsultar)->second;

    map<int, Habitacion *> habs = h->getHabitaciones();
    for (map<int, Habitacion *>::iterator itr = habs.begin(); itr != habs.end(); ++itr)
    {
        Habitacion *a = itr->second;
        map<int, Reserva *> reservas = a->getReservas();
        for (map<int, Reserva *>::iterator it = reservas.begin(); it != reservas.end(); ++it)
        {
            Reserva *ac = it->second;
            map<string, Estadia *> estadias = ac->getEstadias();
            for (map<string, Estadia *>::iterator i = estadias.begin(); i != estadias.end(); ++i)
            {
                Estadia *act = i->second;
                cout << "Estadia: " << act->getCodigoEstadia() << endl;
            }
        }
    }
}

void HostalController::datosEstadia(int codigo)
{
    string cod = "estadia" + to_string(codigo);
    Hostal *h = this->hostales.find(hostalAconsultar)->second;
    map<int, Habitacion *> habs = h->getHabitaciones();
    for (map<int, Habitacion *>::iterator itr = habs.begin(); itr != habs.end(); ++itr)
    {
        Habitacion *a = itr->second;
        map<int, Reserva *> reservas = a->getReservas();
        for (map<int, Reserva *>::iterator it = reservas.begin(); it != reservas.end(); ++it)
        {
            Reserva *ac = it->second;
            map<string, Estadia *> estadias = ac->getEstadias();
            for (map<string, Estadia *>::iterator i = estadias.begin(); i != estadias.end(); ++i)
            {
                Estadia *act = i->second;
                if (act->getCodigoEstadia() == cod)
                    act->getDatos();
            }
        }
    }
}

void HostalController::verCalificacion(int codigo)
{
    Hostal *h = this->hostales.find(hostalAconsultar)->second;
    map<int, Calificacion *> aux = h->getCalificaciones();
    int cal = aux.find(codigo)->second->getCalificacion();
    string com = aux.find(codigo)->second->getComentario();
    cout << "La calificacion de la estadia es: " << cal << endl;
    cout << "El comentario de la estadia es: " << com << endl;
    if (aux.find(codigo)->second->getRespuesta() != NULL)
    {
        string resp = aux.find(codigo)->second->getRespuesta()->getComentario();
        cout << "La respuesta asociada al comentario es: "<< resp <<endl;
    }
}

////////////////consulta hostal///////////////////////
void HostalController::verDetallesHabsHostal(string nombreHostal)
{
    // muestra promedio de calificaciones
    map<string, Hostal *>::iterator it = hostales.find(nombreHostal);
    float promedioCalif = it->second->getPromedio();
    cout << "La calificacion promedio del hostal es: " << promedioCalif << endl;

    // Muestra comentarios y calif de las habs
    map<int, Calificacion *> cal = it->second->getCalificaciones();
    map<int, Habitacion *> habs = it->second->getHabitaciones();
    int i = 1;
    for (map<int, Habitacion *>::iterator ith = habs.begin(); ith != habs.end(); ++ith)
    { // para cada hab yo quiero las reservas
        map<int, Reserva *> reservas = ith->second->getReservas();
        for (map<int, Reserva *>::iterator itr = reservas.begin(); itr != reservas.end(); ++itr)
        { // para cada reserva yo quiero las estadias
            map<string, Estadia *> estadias = itr->second->getEstadias();
            for (map<string, Estadia *>::iterator ite = estadias.begin(); ite != estadias.end(); ++ite)
            { // quiero las calificaciones con id= codigoestadia
                // Estadia * actual = *ite;
                for (map<int, Calificacion *>::iterator itc = cal.begin(); itc != cal.end(); ++itc)
                { // muestro comentarios y calif de las estadias
                    cout << "Calificacion " << i << " de la habitacion numero " << ith->first << " : " << itc->second->getCalificacion() << endl;
                    cout << "Comentario: " << itc->second->getComentario() << endl;
                    i++;
                }
            }
        }
    }
    // tednria q retornar un data descripcion pero hay q cambiar ahi para q sea set<DataHabitacion>
}

void HostalController::infoHabitaciones()
{
    map<string, Hostal *>::iterator itr = hostales.find(hostalAconsultar);
    map<int, Habitacion *> habs = itr->second->getHabitaciones();
    // set<DataHabitacion*> ret;
    for (map<int, Habitacion *>::iterator it = habs.begin(); it != habs.end(); ++it)
    {
        // DataHabitacion nuevo = DataHabitacion(it->second->getNumHab(),it->second->getPrecio(), it->second->getCapacidad());
        // ret.insert(nuevo);
        // cout<<nuevo<<endl;
        cout << "La Habitacion de numero " << it->second->getNumHab() << " tiene precio " << it->second->getPrecio() << " y capacidad para " << it->second->getCapacidad() << " personas." << endl;
    }
    // return ret;
}

void HostalController::suscribirEmpleado(IObserver* e, string email)  {
    suscriptos.insert(std::pair<string,IObserver*>(email,e));
}//agrega el empleado a los suscriptos
//---------------------------------------------------------------------
//ingreso el email del que se va a suscribir, busco el Empleado y lo suscribo con agregar
//---------------------------------------------------------------------

void HostalController::eliminarEmpleado(IObserver *e, string email)  {
    suscriptos.erase(email);
}//elimina el empleado de los suscriptos

//---------------------------------------------------------------------


//---------------------------------------------------------------------

//vector <DataEmpleado> HostalController:: obtenerEmpleadosSuscriptos(){
  //  map<string,Empleado*> :: iterator itS;
    //vector<DataEmpleado> ret;
    //vector<DataEmpleado> :: iterator it;
   // for (itS=suscriptos.begin();itS!=suscriptos.end();++itS){
     //   DataEmpleado de= itS->second->obtenerDatosEmpleado();
       // ret.push_back(de);
    //}
//return ret;

//}
//-------------------------------------------------------------------------------------

vector<Notificacion> HostalController::obtenerNotificaciones(string emailEmpleado){
    vector<Notificacion> ret = suscriptos.find(emailEmpleado)->second->getNotificaciones();
 suscriptos.find(emailEmpleado)->second->borrarNotificaciones();
    return ret;
}

//-------------------------------------------------------------------------------------
//void HostalController::setNotificacion(Notificacion notif){
//	nueva=notif;
//}

//---------------------------------------------------------------------

void HostalController::Modificar(Notificacion nueva) {//activo Notificar a los suscriptos
    map<string,IObserver*> :: iterator itS;

//Obtengo la Notificacion
    for(itS=suscriptos.begin();itS!=suscriptos.end();++itS){
        itS->second->Notificar(nueva);
    }
}

set<string> HostalController::obtenerEmpleadosAsignados(){
    UsuarioController *u = UsuarioController::getInstance();
    set<string> ret =u->obtenerEmpleadosAsignados();
    return ret;
}

Empleado* HostalController::obtenerEmpleado(string mail){
    UsuarioController *u = UsuarioController::getInstance();
    Empleado* ret =u->obtenerEmpleados(mail);
    return ret;
}

