#include "../DtaHostal.h"

DtaHostal::DtaHostal(){
    
}

DtaHostal::DtaHostal(string nombre,string direccion,int calPromedio)
{

    this->nombre = nombre;
    this->direccion = direccion;;
    this->calPromedio = calPromedio;

}

// int DtaHostal::getCalPromedio(){
//     return this->calPromedio;
// }