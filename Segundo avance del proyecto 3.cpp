#include <iostream>
using namespace std;
int main()
{
    
    int opcion, iddes, cedula, cantidaddepasajero;
    string posición, clase,nombre;
    cout<<"Número de silla:";
    cin>> iddes;
   cout<<"Digite la cedula del pasajero:";
   cin>>cedula;
   cout<<"Ingrese el nombre del pasajero:";
   cin>>nombre;
   cout<<"Ingrese la cantidad de pasajeros:";
   cin>>cantidaddepasajero;
   cout<<" Posición de la silla:";
   cin>>posición;
   cout<<" Elija la clase se la ubicación de la silla:";
   cin>>clase;
  
    do
    {
        cout<<"\nElija una opcion'1','2','3','4','5','6','7','8':\n";
    cin>>opcion;
        switch (opcion)
        {
        
            case 1:
            cout<<"Asignar una silla a un pasajero"; 
            break;
            case 2:
            cout<<"Consultar una reserva";
            break;
            case 3:
            cout<<"Eliminar reserva";
            break;
            case 4:
            cout<<"Buscar pasajero";
            break;
            case 5:
            cout<<"Calcular el porcentaje de ocupacion de avion";
            break;
            case 6:
            cout<<"consultar el valor total de ventas por concepto de sillas ocupadas en el avion";
           break; 
           case 7:
           cout<<"Consultar el promedio de venta por concepto de sillas ocupadas / pasajero en el avion";
           break;
           case 8:
           cout<<"Salir del programa";
           break;
         
           default: 
            cout<<"Opcion no valida";
           break;
        }
           
    } while(opcion!= 8);  
}
