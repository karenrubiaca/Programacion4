#include "../DataEmpleado.h"

DataEmpleado::DataEmpleado(){

}


DataEmpleado::DataEmpleado(string nombre,string email,string hostal,Cargo tipoCargo)
{
    this->nombre = getNombre();
    this->email = getEmail();
    this->hostal = hostal;
    this->tipoCargo = tipoCargo;
}


string DataEmpleado::getHostal(){
    return this->hostal;
}

Cargo DataEmpleado::getCargo(){
    Cargo aux = this->tipoCargo;
 
    switch (aux)
    {
    case Administracion:
        cout << "Administracion";
        break;
    case Limpieza:
        cout << "Limpieza";
        break;
      case Recepcion:
        cout << "Recepcion";
        break;
      case Infraestructura:
        cout << "Infraestructura";
        break;
    
        
    }
    
    return this->tipoCargo;
}

DataEmpleado::~DataEmpleado()
{
}