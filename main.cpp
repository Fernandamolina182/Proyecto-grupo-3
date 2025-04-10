#include <iostream>
using namespace std;

struct avión
{
    //atributo
    int idSillas;
    //métodos o funciones
    void registrarcantidaddesillas();
};
void avión::registrarcantidaddesillas() 
{
    cout<<"Registre la cantidad de sillas";
    cin>>idSillas;
};

struct reserva
{
    //atributo
    int idReserva;
    int idSillas;
    int fecha;
    int idPasajero;
    //métodos o funciones
    void registrarfecha();
    void consultaridReserva();
    void consultaridPasajero();
    void consultaridSillas();
};
void reserva:: registrarfecha()
{
    cout<<"Registrar fecha";
    cin>> fecha;
};
void reserva::consultaridReserva()
{
    cout<<idReserva;
};
void reserva:: consultaridPasajero()
{
    cout<< idPasajero;
};
void reserva:: consultaridSillas()
{
    cout<<idSillas;
};
struct sillas
{
    //atributo
    string clase;
    string ubicacion;
    string disponibilidad;
    //métodos o funciones
    void asignarclaseSilla();
    void elegirubicaciondesilla();
    void consultardisponibilidad();
};
void sillas:: asignarclaseSilla()
{
    cout<<"Elija la clase de su silla";
    cin>>clase;
};
void sillas:: elegirubicaciondesilla()
{
    cout<<"Elija la ubicacion de la silla ";
    cin>>ubicacion;
};
void sillas:: consultardisponibilidad()
{
    cout<<disponibilidad;
};
struct pasajero
{
    //atributo
    int cedulaPasajero;
    string Nombre;
    //métodos o funciones 
    void ingresarcedulaPasajero();
    void ingresarsuNombre();
};
void pasajero:: ingresarcedulaPasajero()
{
    cout<<"ingrese numero de cedula";
    cin>>cedulaPasajero;
};
void pasajero:: ingresarsuNombre()
{
    cout<<Nombre;
};
struct datos 
{
    //atributo
    int cedulaPasajero;
    string Nombre;
    //métodos o funciones 
    void ingresarcedulaPasajero();
    void ingresarsuNombre();
};
void datos:: ingresarcedulaPasajero()
{
    cout<<"ingrese numero de celula";
    cin>>cedulaPasajero;
};
void datos:: ingresarsuNombre()
    {
    cout<<Nombre;
};
int main()
{
    pasajero barbara,camila,danna;
    reserva reserva1,reserva2,reserva3;
    sillas ejecutiva,economica;
    sillas pasillo,ventana,centro;
    cout<<"ingrese nombre del pasajero 1";
    cin>>barbara.Nombre;
    cout<<"elija la clase de silla";
    cin>> ejecutiva.clase;
    cout<<"elijala ubicacion de la silla";
    cin>> ventana.ubicacion;
}


