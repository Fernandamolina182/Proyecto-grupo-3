#include <iostream>
using namespace std;
// primer requerimiento funcional

struct silla {
    string clase;
    string ubicacion;
    string disponibilidad;
  
};

int main() {
      int a;
      cout<<"Ingrese el numero de sillas a registrar:";
      cin>>a;
      int tam = a; // definir tamaño de la cantidad de sillas
       int b,i;
    cout<<"Ingrese el numero de reservas a registrar:";
    cin>>b;
    int tam1=b;
    
    silla listasillas[tam];

    for (int i = 0; i < tam; i++) {
        cout << "Ingrese los datos para la silla " << i <<endl;
        cout << "Clase de la silla (Ejecutiva/Económica): ";
        cin >> listasillas[i].clase;
        cout << "Ubicación de la silla (Ventana/Centro/Pasillo): ";
        cin >> listasillas[i].ubicacion;
        cout << "Disponibilidad (si/no): ";
        cin >> listasillas[i].disponibilidad;
    }
//Las posiciones inician desde 0
    cout << "Información de las sillas registradas:"<<endl;
    for (int i = 0; i < tam; i++) {
        cout << "Silla " << i <<endl;
        cout << "Clase: " << listasillas[i].clase << endl;
        cout << "Ubicación: " << listasillas[i].ubicacion << endl;
        cout << "Disponibilidad: " << listasillas[i].disponibilidad << endl;
    }



// segundo requerimiento funcional
struct Reserva{
    //atributos
   int idReserva;
    int idSillas;
    int fecha;
    int idPasajero;
};


   
    

    Reserva listaReservas[tam1];

    {
       for(int i=0; i<tam1; i++){
        cout<<" Elije el número de la reserva:";
        cin>>b;
        cout<<"Ingrese el número de la silla escogida:"<<endl;
        cin>>listaReservas[i].idSillas;
        cout<<"Ingrese la fecha en que se hizo la reserva(dd/mm/aa):"<<endl;
        cin>>listaReservas[i].fecha;
        cout<<"Ingrese el número del pasajero:"<<endl;
        cin>>listaReservas[i].idPasajero;
        };
    }
    
// las posiciones van desde cero hasta el tamaño de reserva.
     cout<<" La informacíon de reserva registrada es:";
      for(int i=0;i<tam1;i++){
     cout<<" N° de reserva: "<<b<<" N° de silla:" <<listaReservas[i].idSillas<<" fecha: "
     <<listaReservas[i].fecha<<" N° de pasajero: "<<listaReservas[i].idPasajero;
    };
         return 0;     
}

