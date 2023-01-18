#include "./include/Fabrica.h"
#include "./include/IEstadiaController.h"
#include "./include/IUsuarioController.h"
#include "./include/IReservaController.h"
#include "./include/IHostalController.h"
#include "./include/IReloj.h"
#include "./include/colors/colors.hpp"

#include <iostream>
#include <set>
#include <string>

int main()
{
    Fabrica *fabrica = Fabrica::getInstance();
    // IEstadiaController  *estadia = fabrica->getInstanceEstadiaController();
    IUsuarioController *usuario = fabrica->getInstanceUsuarioController();
    IReservaController *reserva = fabrica->getInstanceReservaController();
    IHostalController *hostal = fabrica->getInstanceHostalController();
    IReloj *reloj = fabrica->getInstanceReloj();
    std::time_t t = std::time(0);
    std::tm *now = std::localtime(&t);
    reloj->modificarFechaSistema(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900, now->tm_hour);

    int opcion;
    // cout << "01: Alta de usuario" << endl;           // FALTA QUE LIBERE BIEN LA MEMORIA//
    // cout << "02: Alta de hostal" << endl;            // HECHO
    // cout << "03: Alta de habitacion" << endl;        // HECHO
    // cout << "04: Asignar empleado a hostal" << endl; // HECHO
    // cout << "05: Realizar reserva" << endl;          // HECHO
    // cout << "06: Consultar top 3 de hostales" << endl;////////////////////////////////////////
    // cout << "07: Registrar estadia" << endl; // anda
    // cout << "08: Finalizar Estadia" << endl; // anda
    // cout << "09: Calificar estadia" << endl; // listooo
    // cout << "10: Comentar calificación" << endl;////////////////////////////////////////////////
    // cout << "11: Consulta de Usuario" << endl; // HECHO
    // cout << "12: Consulta de Hostal" << endl;
    // cout << "13: Consulta de Reserva" << endl; // HECHO
    // cout << "14: Consulta de Estadía" << endl;///////////////////////////////////////////////////mitad
    // cout << "15: Baja de reserva" << endl; // Anda
    // cout << "16: Suscribirse a notificaciones" << endl;
    // cout << "17: Consulta de notificaciones" << endl;
    // cout << "18: Eliminar Suscripción" << endl;
    // cout << "19: Modificar Fecha del Sistema" << endl;
    // cout << "20: Cargar datos" << endl;
    // cout << "00: Salir" << endl;

    do
    {

        cout << endl;
        cout << colors::bright_green << "FUNCIONALIDADES: " << colors::reset << endl;
        cout << "    01: Alta de usuario" << endl;             // FALTA QUE LIBERE BIEN LA MEMORIA//
        cout << "    02: Alta de hostal" << endl;              // HECHO
        cout << "    03: Alta de habitacion" << endl;          // HECHO
        cout << "    04: Asignar empleado a hostal" << endl;   // HECHO
        cout << "    05: Realizar reserva" << endl;            // HECHO
        cout << "    06: Consultar top 3 de hostales" << endl; // PRONTO
        cout << "    07: Registrar estadia" << endl;           // anda
        cout << "    08: Finalizar Estadia" << endl;           // anda
        cout << "    09: Calificar estadia" << endl;           // listooo
        cout << "    10: Comentar calificación" << endl;       // PRONTO
        cout << "    11: Consulta de Usuario" << endl;         // HECHO
        cout << "    12: Consulta de Hostal" << endl;          // PRONTO
        cout << "    13: Consulta de Reserva" << endl;         // HECHO
        cout << "    14: Consulta de Estadía" << endl;
        cout << "    15: Baja de reserva" << endl; // Anda
        cout << "    16: Suscribirse a notificaciones" << endl;
        cout << "    17: Consulta de notificaciones" << endl;
        cout << "    18: Eliminar Suscripción" << endl;
        cout << "    19: Modificar Fecha del Sistema" << endl;
        cout << "    20: Cargar datos" << endl;
        cout << "    00: Salir" << endl;
        cout << "\nIngrese una opcion: ";

        cin >> opcion;
        switch (opcion)
        {
        case 1:
        {
            // ALTA DE USUARIO

            // ingresarDatosAlta

            string nombre;
            string emailUsr;
            string pass;

            cout << colors::bright_green << "Ingrese nombre del Usuario: " << colors::reset;
            cin >> nombre;
            cout << colors::bright_blue << "Ingrese el email del Usuario: " << colors::reset;
            cin >> emailUsr;
            cout << colors::bright_green << "Ingrese la contraseña del Usuario: " << colors::reset;
            cin >> pass;
            usuario->ingresarDatosAlta(nombre, emailUsr, pass);

            // EL USUARIO ES FINGER O EMPLEADO ?
            cout << "----------------------------------------" << endl;
            cout << colors::bright_blue << "Si el usuario es huesped digite 0" << colors::reset << endl;
            cout << colors::bright_green << "Si el usuario es empleado digite 1" << colors::reset << endl;
            cout << "----------------------------------------" << endl;

            int Emp_Hues;
            cin >> Emp_Hues;
            string tipoCargo; // adentro del switch no se puede declarar

            switch (Emp_Hues)
            {
            case 0:
                // ingresarDatosHuesped
                bool finger;
                cout << colors::bright_blue << "Si el huesped es finger digite 1, de lo contrario digite 0: " << colors::reset;
                cin >> finger;
                // cout<< finger;
                usuario->ingresarDatoHuesped(finger);
                break;
            case 1:
                // ingresarDatosEmpleado
                cout << colors::bright_green << "Ingrese el tipo de cargo del empleado: (Administracion,Limpieza,Recepcion,Infraestructura)" << colors::reset << endl;
                cin >> tipoCargo;
                usuario->ingresarDatoEmpleado(tipoCargo);
                break;

            default:
                cout << colors::bright_red << "No ha digitado una opción correcta" << colors::reset << endl;
                break;
            }
            // si el email del usuario no es valido(recorro todos los usuarios
            // en el sistema y reviso el email), reingresar email o cancelar
            // cancelo liberando la memoria del sistema y terminando con el caso de uso

            //----------------------------------------------------------------------
            // usuario->darAltaUsr();
            map<string, Usuario *> usuarios = usuario->obtenerUsuariosRegistrados();

            bool sigoIntentando = true;
            int opcion;
            while (sigoIntentando)
            {

                try
                {
                    if (usuarios.find(emailUsr) == usuarios.end())
                    {
                        cout << colors::bright_blue << "Si desea confirmar el ingreso seleccione 1, de lo contrario seleccione 0: " << colors::reset;
                        cin >> opcion;
                        switch (opcion)
                        {
                        case 1:
                            usuario->darAltaUsr();

                            cout << colors::bright_green << "Operacion realizada con éxito " << colors::reset;
                            sigoIntentando = false;

                            break;
                        case 0:
                            usuario->cancelarAlta();
                            sigoIntentando = false;

                        default:

                            break;
                        }
                    }
                    else
                    {
                        throw(505);
                    }
                }
                catch (int mynum)
                {
                    cout << colors::bright_red << "email ya ingresado" << endl;
                    cout << colors::bright_green << "Si desea volver a ingresar un email seleccione 1, de lo contrario seleccione 0: " << colors::reset;
                    cin >> opcion;
                    switch (opcion)
                    {
                    case 1:

                        cout << colors::bright_red << "reingresar email: " << colors::reset;
                        cin >> emailUsr;
                        usuario->reingresarEmail(emailUsr);

                        break;
                    case 0:
                        sigoIntentando = false;

                    default:

                        break;
                    }
                }
            }
        }
        break;

        case 2:
        {
            cout << colors::bright_magenta << "Ingresar nombre de hostal: " << colors::reset;
            std::string nombre;
            std::getline(std::cin >> std::ws, nombre);
            cout << colors::bright_magenta << "Ingresar direccion de hostal: " << colors::reset;

            std::string direccion;
            std::getline(std::cin >> std::ws, direccion);

            cout << colors::bright_magenta << "Ingresar telefono de hostal: " << colors::reset;
            int telefono;
            cin >> telefono;
            hostal->ingresarDatosHostal(nombre, direccion, telefono);

            cout << "SE DIO DE ALTA EL HOSTAL {" << nombre << "} CORRECTAMENTE";
        }
        break;
            ////////////////////////////////////ALTA DE HABITACION///////////////////////////////////
        case 3:
        {

            cout << "Los hostales disponibles son: " << endl;
            set<string> hostalesRegistrados = hostal->obtenerNombresHostalesRegistrados();
            string selecHostal;
            if (!hostalesRegistrados.empty())
            {

                // seleccionar hostal para asignarle empleados despues

                cout << "Seleccione el hostal al que se le desea asignar la habitacion: ";
                std::getline(std::cin >> std::ws, selecHostal);
                int num;
                try
                {

                    hostal->seleccionarHostal2(selecHostal);
                }
                catch (int mynum)
                {
                    num = mynum;
                }
                if (num == 404)
                {
                    num = 0;
                }
                else
                {
                    int num_hab;
                    int precio;
                    int capacidad;

                    cout << "Ingrese número de habitacion: ";
                    cin >> num_hab;
                    cout << "Ingrese el precio de la habitación: ";
                    cin >> precio;
                    cout << "Ingrese la capacidad de la habitación: ";
                    cin >> capacidad;

                    hostal->ingresarDatosHab(num_hab, precio, capacidad);

                    hostal->darAltaHabitacion();
                }
            }
            else
            {
                cout << "Debe dar de alta un hostal " << endl;
            }

            // IMPRIMIR EL HOSTAL CON LAS HABITACIONES QUE TIENE
        }
        break;

        case 4:
        {

            /////////ASIGNAR EMPLEADO A HOSTAL////////////////////

            cout << "HOSTALES REGISTRADOS: " << endl;
            set<string> hostalesRegistrados = hostal->obtenerNombresHostalesRegistrados();

            // seleccionar hostal para asignarle empleados despues

            cout << "EMPLEADOS: " << endl;
            map<string, Empleado *> empleados_a_mostrar = usuario->obtenerEmpleadosRegistrados();
            for (map<string, Empleado *>::iterator it = empleados_a_mostrar.begin(); it != empleados_a_mostrar.end(); ++it)
            {
                cout << " -" << it->first << endl;
            }
            if (empleados_a_mostrar.size() == 0)
            {
                cout << "No existen empleados en el sistema" << endl;
            }
            else
            {

                string selecHostal;
                cout << "Seleccione el hostal que le desea asignar empleados: ";
                std::getline(std::cin >> std::ws, selecHostal);
                int num;
                try
                {

                    hostal->seleccionarHostal(selecHostal);
                }
                catch (int mynum)
                {
                    num = mynum;
                }
                if (num == 404)
                {
                    num = 0;
                }
                else
                {

                    set<DtEmpleado *> probando2 = hostal->obtenerEmpleadosNoAsignados();
                    // cout<< probando2.begin()->getEmail();
                    string emp;
                    cout << "ingrese el empleado a asignar: ";
                    cin >> emp;
                    string c = "admin"; ////////////////////////// NO LO CAMBIAMOS QUEDA CON EL CARGO ORIGINAL/////////////////////////////////////////////////////////////////////////////////////////////////////////
                    hostal->seleccionarEmpleado(emp, c);

                    for (set<DtEmpleado *>::iterator it = probando2.begin(); it != probando2.end(); ++it)
                    {
                        DtEmpleado *ti = *it;
                        cout << ti->getEmail();
                        cout << "-";
                        cout << ti->getCargo() << endl;
                    }

                    hostal->confirmarAsignacion();

                    map<string, Empleado *> empleados = usuario->obtenerEmpleadosRegistrados();

                    for (map<string, Empleado *>::iterator it = empleados.begin(); it != empleados.end(); ++it)
                    {
                        cout << "entro";
                        cout << "--";
                        cout << it->second->getHostal()->getNombre();
                    }
                }
            }
        }
        break;

        case 5:
        {
            // DataFecha inicio(13,2,2020,12);
            // DataFecha fin(14,2,2020,13);

            int ci_dia, ci_mes, ci_anio, ci_hora, co_dia, co_mes, co_anio, co_hora;

            cout << "Ingrese los datos del check-in: " << endl;
            cout << "       Dia: ";
            cin >> ci_dia;
            cout << "       Mes: ";
            cin >> ci_mes;
            cout << "       Año: ";
            cin >> ci_anio;
            cout << "       Hora: ";
            cin >> ci_hora;

            cout << "Ingrese los datos del check-out: " << endl;
            cout << "       Dia: ";
            cin >> co_dia;
            cout << "       Mes: ";
            cin >> co_mes;
            cout << "       Año: ";
            cin >> co_anio;
            cout << "       Hora: ";
            cin >> co_hora;

            DataFecha inicio(ci_dia, ci_mes, ci_anio, ci_hora);
            DataFecha fin(co_dia, co_mes, co_anio, co_hora);

            set<DtaHostal *> hosales = reserva->obtenerHostalesRegistrados();
            // DtaHostal *current = *hosales.begin();

            cout << "LOS HOSTALES REGISTRADOS SON:" << endl;

            for (set<DtaHostal *>::iterator it = hosales.begin(); it != hosales.end(); ++it)
            {
                DtaHostal *current = *it;
                cout << "-" << current->getNombre() << endl;
            }

            // cout<<"Ingrese la fecha de checkIn que desea reservar: ";
            // cin<<inicio;
            // cout<<"Ingrese la fecha de checkOut: ";
            string hos;
            cout << "Ingrese el hostal: ";
            std::getline(std::cin >> std::ws, hos);

            bool ind_grup;
            cout << "Si la reserva es individual ingrese 1, de lo contrario ingrese 0: ";
            cin >> ind_grup;

            reserva->seleccionarHostal(hos, inicio, fin, ind_grup);
            cout << "Habitaciones disponibles: " << endl;
            set<int> resultado = reserva->obtenerHabitacionesDisponibles();

            if (!resultado.empty())
            {

                //////SELECCIONAR HABITACION///////////////
                int selec_hab;
                cout << "Ingrese la habitacion en la que desea reservar: ";
                cin >> selec_hab;

                reserva->seleccionarHabitacion(selec_hab);

                map<string, Huesped *> huesp = usuario->obtenerHuespedesRegistrados();

                for (map<string, Huesped *>::iterator i = huesp.begin(); i != huesp.end(); ++i)
                {
                    cout << i->second->getNombre() << endl;
                }

                ///////SELECCIONAR HUESPED////////
                int cant;
                string nombre_hues;
                set<string> seleccion;
                cout << "Ingrese la cantidad de huespedes para la reserva: ";
                cin >> cant;

                for (int i = 0; i < cant; i++)
                {

                    cout << "Ingrese el nombre del huesped " << i << " a seleccionar";
                    cin >> nombre_hues;
                    if (huesp.find(nombre_hues) != huesp.end())
                    {
                        cout << "lo inserto???";
                        seleccion.insert(nombre_hues);
                    }
                    else
                    {
                        cout << "El usuario no es un huesped";
                    }
                }

                reserva->seleccionarHuesped(seleccion);
                reserva->confirmarAsignacion();
            }
            else
            {
                cout << "No hay habitaciones disponibles para res ";
            }
        }
        break;

        case 6:
        {
            cout << "Los tres hostales con mejor promedio son:" << endl;
            vector<string> res = hostal->consultarTop3Hostales();
            int cont = 1;
            for (vector<string>::iterator it = res.begin(); it != res.end(); ++it)
            {
                cout << "Hostal numero " << cont << ":" << endl;
                cout << "Nombre: " << *it << endl;
                cont++;
            }
            cout << "Quiere ver detalles de alguno? Ingrese su nombre, de lo contrario ingrese 0" << endl;
            string nombre;
            std::getline(std::cin >> std::ws, nombre);
            if (nombre != "0")
            {
                hostal->verDetalles(nombre);
            }
        }
        break;

        case 7:
        {

            // REGISTRAR ESTADIA

            cout << "Los Hostales registrados son:" << endl;
            set<string> hostalesReg = reserva->obtenerNombresHostalesRegistrados();

            // MUESTRO HOSTALES REGISTRADOS
            set<string>::iterator it;
            for (it = hostalesReg.begin(); it != hostalesReg.end(); ++it)
            {
                cout << *it << endl;
            }

            // SELECCIONO HOSTAL
            cout << "Ingrese el nombre del Hostal seleccionado:" << endl;
            string nombreHostal;
            std::getline(std::cin >> std::ws, nombreHostal);
            reserva->seleccionarNombreHostal(nombreHostal);

            // INGRESO EMAIL HUESPED
            cout << "Ingrese el email del huesped:" << endl;
            string emailHuesped;
            cin >> emailHuesped;
            Huesped *hues = reserva->ingresarEmailHuesped(emailHuesped);

            reserva->MostrarReservasNoCanceladas(hues); // ANDAAAAA

            // MUESTRO RESERVAS
            //         set<int> reservasReg = reserva->listarReservas();
            //         set<int> :: iterator itR;
            //  int i=1;
            //         for (itR=reservasReg.begin();itR!=reservasReg.end();++itR){
            //             cout << "Identificador reserva"<< i << ": " << *itR << endl;
            //      i++;
            //         }

            // reserva->obtenerReservas();

            /// SELECCIONO RESERVA
            cout << "Ingrese el identificador de la reserva: " << endl;
            int idReserva;
            cin >> idReserva;
            // Estadia(string, Huesped *, Reserva *, int, DataFecha, DataFecha, string);
            reserva->seleccionarReserva(nombreHostal, hues, idReserva);
            // TENEMOS HOSTAL, NOMBRE HUESPED, Y CODIGO RESERVA PARA PODER REGISTRAR ESTADIA
        }
        break;

        case 8:
        {
            // REGISTRAR ESTADIA

            cout << "Los Hostales registrados son:" << endl;
            set<string> hostalesReg = reserva->obtenerNombresHostalesRegistrados();

            // MUESTRO HOSTALES REGISTRADOS
            set<string>::iterator it;
            for (it = hostalesReg.begin(); it != hostalesReg.end(); ++it)
            {
                cout << *it << endl;
            }

            // SELECCIONO HOSTAL
            cout << "Ingrese el nombre del Hostal seleccionado:" << endl;
            string nombreHostal;
            std::getline(std::cin >> std::ws, nombreHostal);
            reserva->seleccionarNombreHostal(nombreHostal);

            // INGRESO EMAIL HUESPED
            cout << "Ingrese el email del huesped:" << endl;
            string emailHuesped;
            cin >> emailHuesped;
            Huesped *hues = reserva->ingresarEmailHuesped(emailHuesped);

            reserva->existeEstadiaActiva(hues);
            //          set<Estadia *> estHues = hues->getEstadias(); PARA CORROBORAR QUE EESTE BIEN SETEADO EL CHECK OUT
            // for (set<Estadia *>::iterator i = estHues.begin(); i != estHues.end(); ++i ){
            //    Estadia * current = *i;
            //     cout<<current->getCheckOut().getDia();

            // }
        }
        break;

        case 9:
        {

            cout << "Los Hostales registrados son:" << endl;
            set<string> hostalesReg = reserva->obtenerNombresHostalesRegistrados();

            // MUESTRO HOSTALES REGISTRADOS
            set<string>::iterator it;
            for (it = hostalesReg.begin(); it != hostalesReg.end(); ++it)
            {
                cout << *it << endl;
            }

            // SELECCIONO HOSTAL
            cout << "Ingrese el nombre del Hostal seleccionado:" << endl;
            string nombreHostal;
            std::getline(std::cin >> std::ws, nombreHostal);
            reserva->seleccionarNombreHostal(nombreHostal);

            // INGRESO EMAIL HUESPED
            cout << "Ingrese el email del huesped:" << endl;
            string emailHuesped;
            cin >> emailHuesped;
            Huesped *hues = reserva->ingresarEmailHuesped(emailHuesped);
            reserva->estadiasFinalizadas(hues);
            cout << "Ingrese el codigo de la estadia la cual quiere calificar" << endl;
            int codigoEstadia;
            cin >> codigoEstadia;
            cout << " Ingrese el comentario: " << endl;
            string coment;
            std::getline(std::cin >> std::ws, coment);
            cout << "Ingrese la calificacion:" << endl;
            int calif;
            cin >> calif;

            reserva->calificarEstadia(hues, calif, coment, codigoEstadia);
            ////////COMPROBANDO Q CALIFICA BIEN/////////////////
            //   map<string,Huesped*> huesp = usuario->obtenerHuespedesRegistrados();
            //   for(map<string,Huesped*>::iterator itr = huesp.begin(); itr!= huesp.end(); ++itr){
            //     cout<<"LAS CALIFICACIONES "
            //     cout<<itr->second->getCalificacion()->getCalificacion();
            //   }
        }
        break;

        case 10:
        {
            cout << "Indique el email del empleado" << endl;
            string email;
            cin >> email;
            hostal->seleccionarEmpleado(email, "c");
            hostal->obtenerComentariosSinRespuesta();
            /*cout << "Comentarios sin respuesta" << endl;
            int cont = 0;
            for(vector<DataComentario>::iterator it = coments.begin(); it!=coments.end(); ++it){
                DataComentario actual = *it;
                cout << "Comentario " << cont;
                cout << "El comentario fue: " <<  actual.getComentario() << endl;
                cout << "La calificacion fue:" << actual.getCalificacion() << endl;
                cont++;
            }*/
            cout << "Indique el codigo del comentario al cual quiere responder" << endl;
            int comentario;
            cin >> comentario;
            cout << "Ingrese la respuesta" << endl;
            string com;
            std::getline(std::cin >> std::ws, com);
            hostal->ingresarComentario(com, comentario);
        }
        break;

        case 11:
        {
            map<string, Usuario *> users = usuario->obtenerUsuariosRegistrados();
            for (map<string, Usuario *>::iterator it = users.begin(); it != users.end(); ++it)
            {
                cout << it->second->getEmail() << endl;
            }
            // {

            //     set<string> usuarios = usuario->obtenerUsuariosRegistrados();

            //     for (set<string>::iterator i = usuarios.begin(); i != usuarios.end(); ++i)
            //     {
            //         string current = *i;
            //         std::cout << current << "\n";
            //     }
            string basura;
            cout << "Ingrese el usuario del cual quiere obtener la informacion:";
            cin >> basura;
            usuario->seleccionarUsuario(basura);

            usuario->obtenerInformacionUsuario();
            //}
        }
        break;

        case 12:
        {
            string hostalAselec;
            cout << "Los hostales disponibles son:" << endl;
            set<string> hostalesRegistrados = hostal->obtenerNombresHostalesRegistrados();

            // for (set<string>::iterator it = hostalesRegistrados.begin(); it != hostalesRegistrados.end(); ++it)
            // {

            //     string current = *it;
            //     cout << current;
            // }

            cout << "Seleccione el hostal: " << endl;
            std::getline(std::cin >> std::ws, hostalAselec);
            hostal->seleccionarHostal(hostalAselec);

            try
            {
                DataInfoBasicaHostal aux = hostal->obtenerInformacionBasicaHostal();
                cout << aux << endl;
                /* code */
            }
            catch (int err)
            {
                cout << "No hay ningun hostal registrado" << endl;
            }

            // muestra promedio de calificaciones, asi como los comentarios y calif de las habs

            hostal->verDetallesHabsHostal(hostalAselec);

            // LISTA INFO DE LAS HABITACIONES
            // set<DataHabitacion*> dataHabs = hostal->infoHabitaciones();
            hostal->infoHabitaciones();
            // for (set<DataHabitacion*>::iterator it = dataHabs.begin(); it != dataHabs.end(); ++it){

            //     cout<<"Numero de la Habitacion:"<<it->getNumero()<<endl;
            //     cout<<"Precio:"<<it->getPrecio()<<endl;
            //     cout<<"Capacidad:"<<it->getCapacidad()<<endl;
            // }
            // LISTA RESERVAS DEL HOSTAL
            hostal->darInfoReservas(hostalAselec);
        }
        break;
            ////////////////////////////////////////CONSULTA DE RESERVA///////////////////////////////

        case 13:
        {

            cout << "Los Hostales registrados son:" << endl;
            set<string> hostalesReg = reserva->obtenerNombresHostalesRegistrados();

            // MUESTRO HOSTALES REGISTRADOS
            //set<string>::iterator it;
            //for (it = hostalesReg.begin(); it != hostalesReg.end(); ++it)
            //{
            //    cout << *it << endl;
            //}

            // SELECCIONO HOSTAL
            cout << "Ingrese el nombre del Hostal seleccionado:" << endl;
            string nombreHostal;
            std::getline(std::cin >> std::ws, nombreHostal);
            reserva->seleccionarNombreHostal(nombreHostal);

            reserva->obtenerReservas();
        }
        break;

        case 14:
        {
            cout << "Los hostales registrados son:" << endl;
            hostal->obtenerNombresHostalesRegistrados();
            cout << "Ingrese el nombre del hostal del cual quiere consultar una estadia" << endl;
            string hostaal;
            std::getline(std::cin >> std::ws, hostaal);
            hostal->seleccionarHostal(hostaal);
            // Listar estadias para el hostal seleccionado
            hostal->obtenerEstadiasRegistradas();
            int codigoEstadia;
            cout << "Ingrese el numero de la estadia" << endl;
            cin >> codigoEstadia;
            hostal->datosEstadia(codigoEstadia);
            int op;
            cout << "Ingrese 1 si desea ver la calficiacion y la respuesta de la estadia, 0 en otro caso." << endl;
            cin >> op;
            if (op == 1)
            {
                hostal->verCalificacion(codigoEstadia);
            }
        }
        break;

        case 15:
        {
            // set<DtaHostal*> hosales=  reserva->obtenerHostalesRegistrados();
            // DtaHostal *current = *hosales.begin();
            // cout<<"Los hostales registrados son:" << current->getNombre();

            set<string> hostales = reserva->obtenerNombresHostalesRegistrados();

            if (!hostales.empty())
            {
                // seleccionar hostal para asignarle empleados despues
                cout << "Seleccione el hostal asociado a la reserva que quiere dar de baja: ";
                string selecHostal;
                cin >> ws;
                getline(cin, selecHostal);
                reserva->seleccionarNombreHostal(selecHostal);
                reserva->obtenercodReservas();
                // FALTA MOSTRAR CI Y CO

                // el usuario selecciona el codigo despues que se lo mostramos
                cout << "Ingrese el código de la reserva que quiere dar de baja: ";
                int codigo;
                cin >> codigo;
                bool confirma;
                cout << "Si desea dar de baja digite 1, si desea cancelar digite 0: ";
                cin >> confirma;

                if (confirma)
                {
                    // DAR DE BAJA
                    reserva->confirmarBajaDeReserva(codigo, selecHostal);
                }
                else
                {
                    // CANCELAR
                    cout << "Cancelado";
                }
            }
        }
        break;

        case 16:
        {//Suscribirse a Notificaciones
        cout << "Los empleados asignados son: " << endl;
        set<string> oea=hostal->obtenerEmpleadosAsignados();
		for(set<string>::iterator it = oea.begin(); it!=oea.end(); ++it){
            cout << "El email del empleado es: " << *it << endl;
        }        	               
        string emailEmpleado;
        cout << "Ingrese el email del empleado seleccionado:";
        cin >> emailEmpleado;	  
        Empleado* aux = hostal->obtenerEmpleado(emailEmpleado);           
        hostal->suscribirEmpleado(aux, emailEmpleado);		                
        }
        break;

        case 17:
        {//Consulta de Notificaciones
        cout << "Los empleados asignados son: " << endl;
        set<string> oea=hostal->obtenerEmpleadosAsignados();
		for(set<string>::iterator it = oea.begin(); it!=oea.end(); ++it){
            cout << "El email del empleado es: " << *it << endl;
        }        	               
        string emailEmpleado;
        cout << "Ingrese el email del empleado seleccionado:";
        cin >> emailEmpleado;
        vector<Notificacion> n=hostal->obtenerNotificaciones(emailEmpleado);
        vector<Notificacion> :: iterator it2;
        for (it2=n.begin();it2!=n.end();++it2){
            Notificacion n = *it2;
            cout << n.getAutor() << endl;
            cout << n.getComentario() << endl;
            cout << n.getPuntaje() << endl;
            }
        }
        break;

        case 18:
        { //Eliminar Suscripcion
        cout << "Los empleados asignados son: " << endl;
        set<string> oea=hostal->obtenerEmpleadosAsignados();
		for(set<string>::iterator it = oea.begin(); it!=oea.end(); ++it){
            cout << "El email del empleado es: " << *it << endl;
        }        	               
        string emailEmpleado;
        cout << "Ingrese el email del empleado seleccionado:";
        cin >> emailEmpleado;
        Empleado* aux = hostal->obtenerEmpleado(emailEmpleado);    
        hostal->eliminarEmpleado(aux, emailEmpleado);
        }
        break;

        case 19:
        {
            DataFecha *f = reloj->getFecha();
            cout << "La fecha/hora actual es: " << endl;
            cout << reloj->getFecha() << endl;
            cout << "Ingrese los nuevos datos de fecha/hora:" << endl;
            int dia;
            int mes;
            int anio;
            int hora;
            cout << "Dia:" << endl;
            cin >> dia;
            cout << "Mes:" << endl;
            cin >> mes;
            cout << "Anio:" << endl;
            cin >> anio;
            cout << "Hora:" << endl;
            cin >> hora;
            reloj->modificarFechaSistema(dia, mes, anio, hora);
            cout << "La nueva Fecha/Hora es:" << endl;
            cout << reloj->getFecha() << endl;
        }
        break;

        case 20:
        { // ALTA DE EMPLEADOS
            cout << endl;
            // E1
            usuario->ingresarDatosAlta("Emilia", "emilia@mail.com", "123");
            usuario->ingresarDatoEmpleado("recepcion");
            usuario->darAltaUsr();
            // E2
            usuario->ingresarDatosAlta("Leonardo", "leo@mail.com", "123");
            usuario->ingresarDatoEmpleado("recepcion");
            usuario->darAltaUsr();
            // E3
            usuario->ingresarDatosAlta("Alina", "alina@mail.com", "123");
            usuario->ingresarDatoEmpleado("administracion");
            usuario->darAltaUsr();
            // E4
            usuario->ingresarDatosAlta("Barliman", "barli@mail.com", "123");
            usuario->ingresarDatoEmpleado("recepcion");
            usuario->darAltaUsr();

            // ALTA DE HUESPEDES
            bool Si = 1;
            bool No = 0;
            cout << endl;

            // H1
            usuario->ingresarDatosAlta("Sofia", "sofia@mail.com", "123");
            usuario->ingresarDatoHuesped(Si);
            usuario->darAltaUsr();
            // H2
            usuario->ingresarDatosAlta("Frodo", "frodo@mail.com", "123");
            usuario->ingresarDatoHuesped(Si);
            usuario->darAltaUsr();
            // H3
            usuario->ingresarDatosAlta("Sam", "sam@mail.com", "123");
            usuario->ingresarDatoHuesped(No);
            usuario->darAltaUsr();
            // H4
            usuario->ingresarDatosAlta("Merry", "merry@mail.com", "123");
            usuario->ingresarDatoHuesped(No);
            usuario->darAltaUsr();
            // H5
            usuario->ingresarDatosAlta("Pippin", "pippin@mail.com", "123");
            usuario->ingresarDatoHuesped(No);
            usuario->darAltaUsr();
            // H6
            usuario->ingresarDatosAlta("Seba", "seba@mail.com", "123");
            usuario->ingresarDatoHuesped(Si);
            usuario->darAltaUsr();

            // HOSTALES
            // HO1
            hostal->ingresarDatosHostal("La posada del finger", "Av de la playa 123, Maldonado", 99111111);
            // HO2
            hostal->ingresarDatosHostal("Mochileros", "Rambla Costanera 333, Rocha", 42579512);
            // HO3
            hostal->ingresarDatosHostal("El Pony Pisador", "Bree (preguntar por Gandalf) ", 000);
            // HO4
            hostal->ingresarDatosHostal("Altos de Fing", "Av del Toro 1424", 99892992);
            // HO5
            hostal->ingresarDatosHostal("Caverna Lujosa", "Amaya 2515 ", 233233235);

            // HABITACIONES
            // HA1
            hostal->seleccionarHostal2("La posada del finger");
            hostal->ingresarDatosHab(1, 40, 2);
            hostal->darAltaHabitacion();

            // HA2
            hostal->seleccionarHostal2("La posada del finger");
            hostal->ingresarDatosHab(2, 10, 7);
            hostal->darAltaHabitacion();
            // HA3
            hostal->seleccionarHostal2("La posada del finger");
            hostal->ingresarDatosHab(3, 30, 3);
            hostal->darAltaHabitacion();
            // HA4
            hostal->seleccionarHostal2("La posada del finger");
            hostal->ingresarDatosHab(4, 5, 12);
            hostal->darAltaHabitacion();
            // HA5
            hostal->seleccionarHostal2("Caverna Lujosa");
            hostal->ingresarDatosHab(1, 3, 2);
            hostal->darAltaHabitacion();
            // HA6
            hostal->seleccionarHostal2("El Pony Pisador");
            hostal->ingresarDatosHab(1, 9, 5);
            hostal->darAltaHabitacion();

            // ASIGNACION DE EMPLEADOS A HOSTELS
            // A1
            hostal->seleccionarHostal("La posada del finger");
            hostal->seleccionarEmpleado("emilia@mail.com", "recepcion");
            hostal->confirmarAsignacion();
            // A2
            hostal->seleccionarHostal("Mochileros");
            hostal->seleccionarEmpleado("leo@mail.com", "recepcion");
            hostal->confirmarAsignacion();
            // A3
            hostal->seleccionarHostal("Mochileros");
            hostal->seleccionarEmpleado("alina@mail.com", "administracion");
            hostal->confirmarAsignacion();
            // A4
            hostal->seleccionarHostal("El Pony Pisador");
            hostal->seleccionarEmpleado("barli@mail.com", "recepcion");
            hostal->confirmarAsignacion();

            // RESERVAS
            // R1
            DataFecha checkIn1 = DataFecha(01, 05, 22, 14);
            DataFecha checkOut1 = DataFecha(10, 05, 22, 10);
            reserva->seleccionarHostal("La posada del finger", checkIn1, checkOut1, 1);
            reserva->seleccionarHabitacion(1);
            set<string> add;
            add.insert(add.end(), "sofia@mail.com");
            reserva->seleccionarHuesped(add);
            reserva->confirmarAsignacion();
            add.erase(add.begin());

            // R2
            DataFecha checkIn2 = DataFecha(04, 01, 01, 20);
            DataFecha checkOut2 = DataFecha(05, 01, 01, 2);
            reserva->seleccionarHostal("El Pony Pisador", checkIn2, checkOut2, 0);
            reserva->seleccionarHabitacion(1);

            add.insert(add.end(), "frodo@mail.com");
            add.insert(add.end(), "sam@mail.com");
            add.insert(add.end(), "merry@mail.com");
            add.insert(add.end(), "pippin@mail.com");
            reserva->seleccionarHuesped(add);
            add.erase(add.begin());
            add.erase(add.begin());
            add.erase(add.begin());
            add.erase(add.begin());
            reserva->confirmarAsignacion();

            // R3
            DataFecha checkIn3 = DataFecha(07, 06, 22, 14);
            DataFecha checkOut3 = DataFecha(30, 06, 22, 11);
            reserva->seleccionarHostal("La posada del finger", checkIn3, checkOut3, 1);
            reserva->seleccionarHabitacion(3);

            add.insert(add.end(), "sofia@mail.com");
            reserva->seleccionarHuesped(add);
            add.erase(add.begin());

            reserva->confirmarAsignacion();

            // R4

            DataFecha checkIn4 = DataFecha(10, 06, 22, 14);
            DataFecha checkOut4 = DataFecha(30, 06, 22, 11);
            reserva->seleccionarHostal("Caverna Lujosa", checkIn4, checkOut4, 1);
            reserva->seleccionarHabitacion(1);

            add.insert(add.end(), "seba@mail.com");
            reserva->seleccionarHuesped(add);
            add.erase(add.begin());

            reserva->confirmarAsignacion();

            // ESTADIAS
            // ES1
            DataFecha date1 = DataFecha(01, 05, 22, 18);
            Huesped *hues;
            reserva->seleccionarNombreHostal("La posada del finger");
            hues = reserva->ingresarEmailHuesped("sofia@mail.com");
            reserva->seleccionarReserva("La posada del finger", hues, 0);

            // ES2
            DataFecha date2 = DataFecha(04, 01, 01, 21);

            reserva->seleccionarNombreHostal("El Pony Pisador");
            hues = reserva->ingresarEmailHuesped("frodo@mail.com");
            reserva->seleccionarReserva("El Pony Pisador", hues, 1);

            // ES3
            DataFecha date3 = DataFecha(04, 01, 01, 21);

            reserva->seleccionarNombreHostal("El Pony Pisador");
            hues = reserva->ingresarEmailHuesped("sam@mail.com");
            // reserva->ingresarFechaCarga(date3);
            reserva->seleccionarReserva("El Pony Pisador", hues, 1);

            // ES4
            DataFecha date4 = DataFecha(04, 01, 01, 21);
            reserva->seleccionarNombreHostal("El Pony Pisador");
            hues = reserva->ingresarEmailHuesped("merry@mail.com");
            // reserva->ingresarFechaCarga(date4);
            reserva->seleccionarReserva("El Pony Pisador", hues, 1);
            // ES5
            DataFecha date5 = DataFecha(04, 01, 01, 21);

            reserva->seleccionarNombreHostal("El Pony Pisador");
            hues = reserva->ingresarEmailHuesped("pippin@mail.com");
            // reserva->ingresarFechaCarga(date5);
            reserva->seleccionarReserva("El Pony Pisador", hues, 1);
            // ES6
            DataFecha date6 = DataFecha(07, 06, 22, 18);

            reserva->seleccionarNombreHostal("Caverna Lujosa");
            hues = reserva->ingresarEmailHuesped("seba@mail.com");
            //   reserva->ingresarFechaCarga(date6);//QUE OPINAN DE CREARLA PARA CARGAR?
            reserva->seleccionarReserva("Caverna Lujosa", hues, 3);

            // FINALIZACION DE ESTADIAS
            //  ES1
            reserva->seleccionarNombreHostal("La posada del finger");
            hues = reserva->ingresarEmailHuesped("sofia@mail.com");
            reserva->existeEstadiaActiva(hues);
            DataFecha date7 = DataFecha(10, 05, 22, 9);

            // ES2
            reserva->seleccionarNombreHostal("El Pony Pisador");
            hues = reserva->ingresarEmailHuesped("frodo@mail.com");
            reserva->existeEstadiaActiva(hues);
            DataFecha date8 = DataFecha(05, 01, 01, 2);
            //   usuario->ingresarFechaCarga(datE8);//QUE OPINAN DE CREARLA PARA CARGAR?

            //      ES6
            reserva->seleccionarNombreHostal("Caverna Lujosa");
            hues = reserva->ingresarEmailHuesped("seba@mail.com");
            reserva->existeEstadiaActiva(hues);
            DataFecha date9 = DataFecha(15, 06, 22, 22);
            //   reserva->ingresarFechaCarga(date9);//QUE OPINAN DE CREARLA PARA CARGAR?

            // CALIFICAR ESTADIA
            //     C1reserva
            reserva->seleccionarNombreHostal("La posada del finger");
            hues = reserva->ingresarEmailHuesped("sofia@mail.com");
            reserva->calificarEstadia(hues, 3, "Un poco caro para lo que ofrecen.El famoso gimnasio era una caminadora(que hacia tremendo ruido) y 2 pesas, la piscina parecia el lago del Parque Rod y el desayuno eran 2 tostadas con mermelada. Internet se pasaba cayendo. No vuelvo.", 0);

            // reserva->ingresarFechaCarga(fech1);//QUE OPINAN DE CREARLA PARA CARGAR?
            //      reserva->ingresarMensaje(,3);
            //   C2
            reserva->seleccionarNombreHostal("El Pony Pisador");
            hues = reserva->ingresarEmailHuesped("frodo@mail.com");
            reserva->calificarEstadia(hues, 2, "Se pone peligroso de noche, no recomiendo. Ademas no hay caja fuerte para guardar anillos.", 1);

            //   C3
            reserva->seleccionarNombreHostal("Caverna Lujosa");
            hues = reserva->ingresarEmailHuesped("seba@mail.com");
            reserva->calificarEstadia(hues,1,"Habia pulgas en la habitacion. Que lugar mas mamarracho!!", 5);

            // COMENTAR CALIFICACION
            hostal->seleccionarEmpleado("barli@mail.com","c");
            
            hostal->ingresarComentario("Desaparecio y se fue sin pagar",1);
        }
        break;

        case 0:
        {
        }
        break;
        }
    } while (opcion != 0);
}