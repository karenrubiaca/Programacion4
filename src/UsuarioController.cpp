#include "../include/UsuarioController.h"
#include <iostream>
#include <cstddef>

using namespace std;

class Fabrica;

UsuarioController *UsuarioController::instancia = NULL;

UsuarioController *UsuarioController::getInstance()
{
    if (instancia == NULL)
        instancia = new UsuarioController();

    return instancia;
}



//----------------------------------
string null = "Vacia";
class DatosAlta
{
public:
    DatosAlta(){
        this->cargo ="null";

    };
    string nombre;
    string mail;
    string pass;
    bool *finger = NULL;
    string cargo = null;
    
   
};

DatosAlta *Obj = new DatosAlta();

//----------------------------------
void UsuarioController::ingresarDatosAlta(string nombre, string mail, string pass)
{
Obj->cargo = "null";
    Obj->nombre = nombre;
    Obj->mail = mail;
    Obj->pass = pass;
}

void UsuarioController::ingresarDatoEmpleado(string cargo)
{

    
    Obj->cargo = cargo;
    cout<<"--------------------------------------"<<endl;
    cout << "Nombre: " << Obj->nombre << endl;
    cout << "Email: " << Obj->mail << endl;
    cout << "Contraseña: " << Obj->pass << endl;
    cout<<"Cargo: " <<Obj->cargo<<endl;
    cout<<"--------------------------------------"<<endl;
}

void UsuarioController::ingresarDatoHuesped(bool finger)
{

    bool *it = &finger;
    cout<<"----------------------------------------"<<endl;
    Obj->finger = it;
    cout << "Nombre: " << Obj->nombre << endl;
    cout << "Email: " << Obj->mail << endl;
    cout << "Contraseña: " << Obj->pass << endl;
    switch (finger)
    {
    case 1:
    
        /* code */
        cout<<"El usuario es finger"<<endl;
        break;
    case 0: 
        cout<<"El usuario no es finger"<<endl;
    
    default:
        break;
    }
    cout<<"-----------------------------------------"<<endl;
}

//////////////////NUEVA FUNCION/////////////////////////////////

map<string,Empleado*> UsuarioController::obtenerEmpleadosRegistrados(){
// cout<<"entra"<<empleados.begin()->first<<"andaaaaaaaa"
    //  map<string,Empleado*> res;
    // for (map<string, Empleado*>::iterator it = empleados.begin(); it != empleados.end(); ++it)
    // {
        
    //     //Usuario *bp = dynamic_cast<Usuario*>(&it->second);
    //     res.insert(pair<string, Empleado*>(it->first, it->second));
        
    //     //cout<< res[it->second.getNombre().].getCargo();
    // }
    return this->empleados;

}
map<string,Huesped*> UsuarioController::obtenerHuespedesRegistrados(){

     map<string,Huesped*> res;
    for (map<string, Huesped*>::iterator it = huespedes.begin(); it != huespedes.end(); ++it)
    {
        
        //Usuario *bp = dynamic_cast<Usuario*>(&it->second);
        res.insert(pair<string, Huesped*>(it->first, it->second));
        
        //cout<< res[it->second.getNombre().].getCargo();
    }
    return res;

}




/////////////////////////////////////////////////

map<string,Usuario*> UsuarioController::obtenerUsuariosRegistrados()
{
    map<string,Usuario*> res;
    
    
    for (std::map<string, Huesped*>::iterator it = huespedes.begin(); it != huespedes.end(); ++it)
    {
        
        //Usuario *bp = dynamic_cast<Usuario*>(&it->second);
        res.insert(pair<string, Usuario*>(it->first,it->second));
        
        // cout << "huespedes:";
        // cout << it->first << endl;
        // cout<<it->first<<endl;
    }
    for (std::map<string, Empleado*>::iterator it = empleados.begin(); it != empleados.end(); ++it)
    {
        
        //Usuario *bp = dynamic_cast<Usuario*>(&it->second);
        res.insert(pair<string, Usuario*>(it->first, it->second));
       
        
    }
    
    return res;
}

void UsuarioController::cancelarAlta()
{

    
}

void UsuarioController::reingresarEmail(string nuevoMail)
{
    Obj->mail = nuevoMail;
}

void UsuarioController::darAltaUsr() 
{
    
    if (Obj->cargo == "null")
    {
         //cout<<"Es huesped";
        Huesped *huesped = new Huesped(Obj->nombre, Obj->mail, Obj->pass, Obj->finger);
        huespedes.insert(std::pair<string, Huesped*>(Obj->mail, huesped));
    }
    else 
    {
         // cout<<"Es Empleado";
        Hostal *aux= new Hostal();
        Empleado *empleado = new Empleado(Obj->nombre, Obj->mail, Obj->pass, Obj->cargo,aux );
        empleados.insert(std::pair<string, Empleado*>(Obj->mail, empleado));
        
       
    }
    // this->cancelarAlta();
}
string mailAConsultar;
void UsuarioController::seleccionarUsuario(string mail)
{
    mailAConsultar = mail;
}

void UsuarioController::obtenerInformacionUsuario()
{

    map<string, Huesped*>::iterator itr = huespedes.find(mailAConsultar);
    if (itr != huespedes.end())
    { // lo encontre es un huesped
      
        DataHuesped *aux = new DataHuesped();
        aux = itr->second->getDataUsuario();
        cout<<"Nombre: " <<aux->getNombre()<<endl;
        cout<<"Email: "<<aux->getEmail()<<endl;
        bool fing = aux->esFinger();
        switch (fing)
        {
        case 1:
            cout<< "Es finger"<<endl;
            break;
        
        case 0:
            cout<<"No es finger"<<endl;
            break;
        }
    }
    else
    {
        map<string, Empleado*>::iterator itr2 = empleados.find(mailAConsultar);
        if (itr2 != empleados.end())
        { // lo encontre es un huesped
           
            cout<<"Nombre: "<<itr2->second->getNombre()<<endl;
            cout<<"Email: "<<itr2->second->getEmail()<<endl;
            cout<<"Cargo: " << itr2->second->getCargo() << endl;
            Hostal* h = itr2->second->getHostal();
            if (h != NULL){
             cout<<"Hostal: "<<itr2->second->getHostal()->getNombre()<<endl;
        } else {
            cout<<"No tiene asignado un hostal"<<endl;
        }
    }
   
}
}


void UsuarioController::asignaReservas(Reserva *r, set<string> abuscar){

    for(set<string>::iterator it = abuscar.begin(); it != abuscar.end();++it){
        string current = *it;
      Huesped* nuevo=  huespedes.find(current)->second;
      nuevo->setReserva(r);
    }


}

// void UsuarioController::bajaReservaDeHuesp(int cod,set<string> huesp){
//      for(set<string>::iterator it = huesp.begin(); it != huesp.end();++it){
//         string current = *it;
//       Huesped* nuevo=  huespedes.find(current)->second;
//       nuevo->;
//     }

// }
void UsuarioController::MostrarReservasNoCanceladas(string huespedAConsultar){
    Huesped * h =huespedes.find(huespedAConsultar)->second;
     if(huespedes.find(huespedAConsultar)!= huespedes.end()){
    h->getReservasNoCanceladas();
     }

}
void UsuarioController::setEstadia(Estadia* nueva,string mail,int codRes){
     Huesped* registrado = huespedes.find(mail)->second;
     if( huespedes.find(mail) != huespedes.end() ){
        registrado->setEstadia(nueva,codRes);
     }
}

string UsuarioController::darHostalTrabaja(string emailEmp){
    Empleado* aux = this->empleados.find(emailEmp)->second;
    string nomHostal = aux->getHostal()->getNombre();
    return nomHostal;
}

set<string> UsuarioController :: obtenerEmpleadosAsignados(){
    map<string,Empleado*> :: iterator itE;
    set<string> ret;
    
    for(itE=empleados.begin();itE!=empleados.end();++itE){
        if(itE->second->getHostal()!=NULL){
           ret.insert(itE->second->getEmail());
        }
    }
return ret;
} 

Empleado* UsuarioController ::obtenerEmpleados(string email){
    return this->empleados.find(email)->second;
}
