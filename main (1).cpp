#include <iostream>
using namespace std;

const int tam=50;
struct Reserva {
    string clase;
    string ubicacion;
    string disponibilidad;
    string fecha;
    int idPasajero;
};
struct DatosPasajero{
    int cedulaPasajero;
    string nombre;
};

int main() {
    Reserva listasillas[tam]; // Crear arreglo fijo de 50 sillas
    DatosPasajero listaPasajeros[tam];
    int cantidad;
    cout << "Ingrese el número de sillas a registrar (máximo " << tam << "): ";
    cin >> cantidad;
    if (cantidad > tam) {
        cout << "Número excede el límite de " << tam << ". Se ajustará al máximo permitido.\n";
        cantidad = tam;
    }

    int opcion, iddes, cedula, cantidaddepasajero;
    string posicion, clase, nombre;
    int sillasRegistradas = 0, reservasRegistradas = 0; // Para llevar control de datos ingresados

    do {
        cout << "\nMenú de opciones:\n";
        cout << "1. Registrar sillas\n";
        cout << "2. Mostrar información de sillas\n";
        cout << "3. Registrar reservas\n";
        cout << "4. Mostrar información de reservas\n";
        cout << "5. Calcular el porcentaje de ocupación del avión\n";
        cout << "6. Consultar el valor total de ventas por sillas ocupadas\n";
        cout << "7. Consultar el promedio de venta por pasajero\n";
        cout << "8. Salir del programa\n";
        cout << "Ingrese su opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                if (cantidad <= tam) {  
                    for (int i = 0; i < cantidad; i++){
                        cout << "Ingrese los datos para la silla " << i <<endl;
                        cout << "Clase de la silla (Ejecutiva/Económica): ";
                        cin >> listasillas[i].clase;
                        cout << "Ubicación de la silla (Ventana/Centro/Pasillo): ";
                        cin >> listasillas[i].ubicacion;
                        cout << "Disponibilidad (si/no): ";
                        cin >> listasillas[i].disponibilidad;
                    }
                } else {
                    cout << "No se pueden registrar más sillas. Capacidad máxima alcanzada.\n";
                }
                break;

            case 2:
                if (cantidad <= tam) {  
                    cout << "\nInformación de las sillas registradas:\n";
                    for (int i = 0; i < cantidad; i++) {
                        cout << "Silla " << i <<endl;
                        cout << "Clase: " << listasillas[i].clase << endl;
                        cout << "Ubicación: " << listasillas[i].ubicacion << endl;
                        cout << "Disponibilidad: " << listasillas[i].disponibilidad << endl;
                    }
                } else {
                    cout << "No hay sillas registradas aún.\n";
                }
                break;

            case 3:
                int sillaEscogida;
                if (cantidad <= tam) {  
                    cout << "Ingrese el número de la silla escogida: ";
                    cin >> sillaEscogida;
                    if (sillaEscogida < 1 || sillaEscogida > cantidad) {  
                        cout << "Número de silla inválido.\n";
                        break;
                    }
                    cout << "Ingrese la fecha de la reserva (dd/mm/aa): ";
                    cin >> listasillas[sillaEscogida - 1].fecha;
                    cout << "Ingrese el número del pasajero: ";
                    cin >> listasillas[sillaEscogida - 1].idPasajero;
                    reservasRegistradas++;
                } else {
                    cout << "No se pueden registrar más reservas. Capacidad máxima alcanzada.\n";
                }
                break;

            case 4:
                if (cantidad <= tam) {  
                    for (int i = 0; i < cantidad; i++) {
                        cout << "\nIngrese los datos del pasajero " << i + 1 << ":\n";
                        cout << "Número de cédula: ";
                        cin >> listaPasajeros[i].cedulaPasajero;
                        cout << "Nombre: ";
                        cin >> listaPasajeros[i].nombre;
                    }
                } else {
                    cout << "No hay reservas registradas aún.\n";
                }
                break;

            case 5:
                cout << "Calcular el porcentaje de ocupación del avión (pendiente de implementación)\n";
                break;

            case 6:
                cout << "Consultar el valor total de ventas por sillas ocupadas (pendiente de implementación)\n";
                break;

            case 7:
                cout << "Consultar el promedio de venta por pasajero (pendiente de implementación)\n";
                break;

            case 8:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opción no válida. Intente nuevamente.\n";
        }
    } while (opcion != 8);

    return 0;
}

