#include <iostream>
using namespace std;
struct Reserva{
    //atributos
   int idReserva;
    int idSillas;
    int fecha;
    int idPasajero;
};
main()
{
    int tam;
    int a;
    cout<<"ingresa el número de reservas:";
    cin>>tam;

    Reserva listaReservas[tam];

    {
        
        cout<<" Elije el número de la reserva:";
        cin>>a;
        cout<<"Ingrese el número de la silla escogida:"<<endl;
        cin>>listaReservas[a].idSillas;
        cout<<"Ingrese la fecha en que se hizo la reserva(dd/mm/aa):"<<endl;
        cin>>listaReservas[a].fecha;
        cout<<"Ingrese el número del pasajero:"<<endl;
        cin>>listaReservas[a].idPasajero;

    }
     // las posiciones van desde cero hasta el tamaño de reserva.
     cout<<" La informacíon de reserva registrada es:"<<" N° de reserva: "<<a<<" N° de silla:" <<
     listaReservas[a].idSillas<<" fecha: "<<listaReservas[a].fecha<<" N° de pasajero: "<<listaReservas[a].idPasajero;
}