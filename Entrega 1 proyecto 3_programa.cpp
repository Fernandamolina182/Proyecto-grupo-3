#include <iostream>
using namespace std;
int main()
{
    
    int opcion;
    cout<< "Elija una opcion'1','2','3','4','5','6','7','8','9':";
    cin>>opcion;
    switch (opcion)
    {
        case 1:
        cout<< "Entrar al programa" ; 
        break; 
        case 2:
        cout<<"Asignar una silla a un pasajero"; 
        break;
        case 3:
        cout<<"Consultar una reserva";
        break;
        case 4:
        cout<<"Eliminar reserva";
        break;
        case 5:
        cout<<"Buscar pasajero";
        break;
        case 6:
        cout<<"Calcular el porcentaje de ocupacion de avion";
        break;
        case 7:
        cout<<"consultar el valor total de ventas por concepto de sillas ocupadas en el avion";
       break; 
       case 8:
       cout<<"Consultar el promedio de venta por concepto de sillas ocupadas / pasajero en el avion";
       break;
       case 9:
       cout<<"Salir del programa";
       break;
     
       default: 
        cout<<"Opcion no valida";
       break;
    }
           
        
}
