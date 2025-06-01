#include <iostream>
#include <string>
#include <iomanip> // Para std::fixed y std::setprecision

using namespace std;

// --- CONSTANTES GLOBALES ---
const int MAX_EXECUTIVE_ROWS = 2;
const int MAX_EXECUTIVE_COLS = 4;
const int MAX_ECONOMY_ROWS = 6;
const int MAX_ECONOMY_COLS = 7;
const int TOTAL_AIRCRAFT_CAPACITY = (MAX_EXECUTIVE_ROWS * MAX_EXECUTIVE_COLS) + (MAX_ECONOMY_ROWS * MAX_ECONOMY_COLS);

// --- MATRICES GLOBALES PARA REPRESENTAR LOS ASIENTOS (0 = Disponible, 1 = Ocupado) ---
int executiveSeats[MAX_EXECUTIVE_ROWS][MAX_EXECUTIVE_COLS];
int economySeats[MAX_ECONOMY_ROWS][MAX_ECONOMY_COLS];

// --- ESTRUCTURAS ---
struct sillas { // Se mantiene por originalidad, pero no es la principal fuente de verdad
    string clase;
    string ubicacion;
    string disponibilidad;
};

struct DatosPasajero {
    int cedulaPasajero;
    string nombre;
};

struct Reserva {
    string clase; // "Ejecutiva" o "Economica"
    int fila;     // Fila en la matriz correspondiente
    int columna;  // Columna en la matriz correspondiente
    string fecha;
    int idPasajero; // Cédula del pasajero
    bool activa;    // true si la reserva está activa, false si ha sido eliminada
};

// --- ARRAYS PARA ALMACENAR DATOS DE RESERVAS Y PASAJEROS ---
Reserva todasLasReservas[TOTAL_AIRCRAFT_CAPACITY];
DatosPasajero todosLosPasajeros[TOTAL_AIRCRAFT_CAPACITY];

// Contadores para el número actual de reservas y pasajeros registrados
int numReservasActivas = 0;
int numPasajerosRegistrados = 0;

// --- PROTOTIPOS DE FUNCIONES ---
void inicializarSistema(); // Una función para inicializar matrices y structs
void mostrarMapaAsientos(); // Muestra el estado de las matrices

// main function with integrated matrix logic
int main() {
    cout << "Bienvenid@ a nuestra app ===== AEREOLÌNEA =====\n";

    inicializarSistema(); // Inicializa las matrices y las reservas al inicio

    int opcion;
    do {
        cout << "\n--- Menú de opciones ---\n";
        cout << "1. Mostrar mapa de asientos\n";
        cout << "2. Registrar reserva de asiento\n"; // La lógica de la matriz va aquí
        cout << "3. Registrar datos de pasajero\n";
        cout << "4. Eliminar reserva\n";
        cout << "5. Consultar valor total de ventas\n";
        cout << "6. Consultar promedio de venta por pasajero\n";
        cout << "7. Buscar pasajero\n";
        cout << "8. Calcular el porcentaje de ocupación del avión\n";
        cout << "9. Salir\n";
        cout << "Ingrese su opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarMapaAsientos();
                break;

            case 2: // Registrar reserva de asiento (aquí se integra la matriz)
            {
                cout << "\n--- Registrar Reserva de Asiento ---\n";
                int cantidadReservas;
                cout << "¿Cuántas reservas desea registrar en esta sesión? ";
                cin >> cantidadReservas;

                if (cantidadReservas <= 0) {
                    cout << "Cantidad de reservas inválida.\n";
                    break;
                }

                for (int i = 0; i < cantidadReservas; ++i) {
                    cout << "\n--- Registrando reserva " << (i + 1) << " de " << cantidadReservas << " ---\n";

                    if (numReservasActivas >= TOTAL_AIRCRAFT_CAPACITY) {
                        cout << "El avión está completamente reservado. No se pueden añadir más reservas.\n";
                        break; // Sale del bucle for si el avión está lleno
                    }

                    // Mostrar el mapa de asientos actual antes de pedir la selección
                    mostrarMapaAsientos();

                    int tipoClase;
                    int fila, columna;
                    string claseStr;

                    cout << "\nSeleccione la clase de asiento para reservar:\n";
                    cout << "1. Ejecutiva\n";
                    cout << "2. Económica\n";
                    cout << "Ingrese su opción: ";
                    cin >> tipoClase;

                    bool asientoOcupadoEnMatriz = false;

                    if (tipoClase == 1) { // Clase Ejecutiva
                        claseStr = "Ejecutiva";
                        cout << "Ingrese la fila (0-" << MAX_EXECUTIVE_ROWS - 1 << "): ";
                        cin >> fila;
                        cout << "Ingrese la columna (0-" << MAX_EXECUTIVE_COLS - 1 << "): ";
                        cin >> columna;

                        if (fila < 0 || fila >= MAX_EXECUTIVE_ROWS || columna < 0 || columna >= MAX_EXECUTIVE_COLS) {
                            cout << "Error: Fila o columna fuera de rango para Clase Ejecutiva. Intente con otra reserva.\n";
                            continue; // Salta a la siguiente iteración del bucle for
                        }

                        if (executiveSeats[fila][columna] == 0) {
                            executiveSeats[fila][columna] = 1; // Marcar como ocupado en la matriz
                        } else {
                            cout << "El asiento Ejecutiva F" << fila << "C" << columna << " ya está ocupado. Intente con otra reserva.\n";
                            asientoOcupadoEnMatriz = true;
                        }
                    } else if (tipoClase == 2) { // Clase Económica
                        claseStr = "Economica";
                        cout << "Ingrese la fila (0-" << MAX_ECONOMY_ROWS - 1 << "): ";
                        cin >> fila;
                        cout << "Ingrese la columna (0-" << MAX_ECONOMY_COLS - 1 << "): ";
                        cin >> columna;

                        if (fila < 0 || fila >= MAX_ECONOMY_ROWS || columna < 0 || columna >= MAX_ECONOMY_COLS) {
                            cout << "Error: Fila o columna fuera de rango para Clase Económica. Intente con otra reserva.\n";
                            continue; // Salta a la siguiente iteración del bucle for
                        }

                        if (economySeats[fila][columna] == 0) {
                            economySeats[fila][columna] = 1; // Marcar como ocupado en la matriz
                        } else {
                            cout << "El asiento Económica F" << fila << "C" << columna << " ya está ocupado. Intente con otra reserva.\n";
                            asientoOcupadoEnMatriz = true;
                        }
                    } else {
                        cout << "Opción de clase no válida. Intente con otra reserva.\n";
                        continue; // Salta a la siguiente iteración del bucle for
                    }

                    if (asientoOcupadoEnMatriz) {
                        continue; // Salta a la siguiente iteración del bucle for si el asiento ya estaba ocupado
                    }

                    // Si llegamos aquí, el asiento fue marcado como ocupado en la matriz
                    // Ahora, registrar los detalles de la reserva en el array de structs
                    int indiceReserva = -1;
                    for(int j = 0; j < TOTAL_AIRCRAFT_CAPACITY; ++j) { // Usar 'j' para evitar conflicto con 'i' del bucle externo
                        if (!todasLasReservas[j].activa) { // Buscar el primer espacio disponible
                            indiceReserva = j;
                            break;
                        }
                    }

                    if (indiceReserva == -1) {
                        cout << "Error interno: No se pudo encontrar espacio para la reserva en la lista. Por favor, contacte soporte.\n";
                        // En un caso más robusto, aquí revertiríamos la marca en la matriz.
                        break; // Sale del bucle for
                    }

                    todasLasReservas[indiceReserva].clase = claseStr;
                    todasLasReservas[indiceReserva].fila = fila;
                    todasLasReservas[indiceReserva].columna = columna;

                    cout << "Ingrese la fecha de la reserva (dd/mm/aa): ";
                    cin >> todasLasReservas[indiceReserva].fecha;

                    int cedulaPasajero;
                    cout << "Ingrese el ID del pasajero (Cédula): ";
                    cin >> cedulaPasajero;
                    todasLasReservas[indiceReserva].idPasajero = cedulaPasajero;
                    todasLasReservas[indiceReserva].activa = true;
                    numReservasActivas++;
                    cout << "Asiento " << claseStr << " F" << fila << "C" << columna << " reservado exitosamente.\n";
                } // Fin del bucle for para cantidadReservas
                break;
            }

            case 3: // Registrar datos de pasajero
            {
                // Este caso sigue siendo para registrar datos de un pasajero en general.
                // Si quieres que el usuario pueda registrar múltiples pasajeros aquí,
                // se necesitaría un bucle similar al de la opción 2.
                if (numPasajerosRegistrados >= TOTAL_AIRCRAFT_CAPACITY) {
                    cout << "Capacidad máxima de pasajeros alcanzada.\n";
                    break;
                }

                cout << "\nIngrese los datos del pasajero #" << numPasajerosRegistrados + 1 << ":\n";
                cout << "Número de cédula: ";
                cin >> todosLosPasajeros[numPasajerosRegistrados].cedulaPasajero;
                cout << "Nombre: ";
                cin.ignore(); // Limpiar el buffer de entrada
                getline(cin, todosLosPasajeros[numPasajerosRegistrados].nombre);

                numPasajerosRegistrados++;
                cout << "Datos de pasajero registrados exitosamente.\n";
                break;
            }

            case 4: // Eliminar reserva
            {
                if (numReservasActivas == 0) {
                    cout << "No hay reservas activas para eliminar.\n";
                    break;
                }

                cout << "\n--- Eliminar Reserva ---\n";
                cout << "Reservas activas:\n";
                for (int i = 0; i < TOTAL_AIRCRAFT_CAPACITY; ++i) {
                    if (todasLasReservas[i].activa) {
                        cout << "  [" << i << "] Clase: " << todasLasReservas[i].clase
                             << ", Asiento: F" << todasLasReservas[i].fila << "C" << todasLasReservas[i].columna
                             << ", Pasajero ID: " << todasLasReservas[i].idPasajero << ", Fecha: " << todasLasReservas[i].fecha << endl;
                    }
                }

                int indiceAEliminar;
                cout << "Ingrese el número de índice de la reserva a eliminar: ";
                cin >> indiceAEliminar;

                if (indiceAEliminar < 0 || indiceAEliminar >= TOTAL_AIRCRAFT_CAPACITY || !todasLasReservas[indiceAEliminar].activa) {
                    cout << "Índice de reserva inválido o reserva no activa.\n";
                    break;
                }

                // Liberar el asiento en la matriz
                if (todasLasReservas[indiceAEliminar].clase == "Ejecutiva") {
                    executiveSeats[todasLasReservas[indiceAEliminar].fila][todasLasReservas[indiceAEliminar].columna] = 0;
                } else { // Economica
                    economySeats[todasLasReservas[indiceAEliminar].fila][todasLasReservas[indiceAEliminar].columna] = 0;
                }

                // Marcar la reserva como inactiva en el array de structs
                todasLasReservas[indiceAEliminar].activa = false;
                // Opcional: limpiar los datos de la struct si es necesario
                todasLasReservas[indiceAEliminar].clase = "";
                todasLasReservas[indiceAEliminar].fecha = "";
                todasLasReservas[indiceAEliminar].idPasajero = 0;
                todasLasReservas[indiceAEliminar].fila = -1; // Valores inválidos
                todasLasReservas[indiceAEliminar].columna = -1; // Valores inválidos

                numReservasActivas--;
                cout << "Reserva eliminada exitosamente.\n";
                break;
            }

            case 5: // Consultar valor total de ventas
            {
                int totalVentas = 0;
                for (int i = 0; i < TOTAL_AIRCRAFT_CAPACITY; ++i) {
                    if (todasLasReservas[i].activa) {
                        if (todasLasReservas[i].clase == "Economica") {
                            totalVentas += 100;
                        } else if (todasLasReservas[i].clase == "Ejecutiva") {
                            totalVentas += 200;
                        }
                    }
                }
                cout << "El valor total de ventas por sillas ocupadas es: $" << totalVentas << endl;
                break;
            }

            case 6: // Consultar promedio de venta por pasajero
            {
                int totalVentas = 0;
                int pasajerosConReserva = 0;

                for (int i = 0; i < TOTAL_AIRCRAFT_CAPACITY; ++i) {
                    if (todasLasReservas[i].activa) {
                        if (todasLasReservas[i].clase == "Economica") {
                            totalVentas += 100;
                        } else if (todasLasReservas[i].clase == "Ejecutiva") {
                            totalVentas += 200;
                        }
                        pasajerosConReserva++;
                    }
                }

                if (pasajerosConReserva > 0) {
                    double promedio = static_cast<double>(totalVentas) / pasajerosConReserva;
                    cout << fixed << setprecision(2);
                    cout << "El promedio de venta por pasajero es: $" << promedio << endl;
                } else {
                    cout << "No hay pasajeros con reservas para calcular el promedio.\n";
                }
                break;
            }

            case 7: // Buscar pasajero
            {
                int cedulaBuscada;
                bool pasajeroEncontrado = false;
                cout << "Ingrese la cédula del pasajero a buscar: ";
                cin >> cedulaBuscada;

                string nombrePasajeroEncontrado = "Desconocido";

                // Buscar en la lista de pasajeros registrados
                for (int i = 0; i < numPasajerosRegistrados; ++i) {
                    if (todosLosPasajeros[i].cedulaPasajero == cedulaBuscada) {
                        pasajeroEncontrado = true;
                        nombrePasajeroEncontrado = todosLosPasajeros[i].nombre;
                        break;
                    }
                }

                if (pasajeroEncontrado) {
                    cout << "Pasajero encontrado: " << nombrePasajeroEncontrado << " (Cédula: " << cedulaBuscada << ")\n";
                    cout << "Reservas asociadas:\n";
                    bool tieneReservas = false;
                    for (int i = 0; i < TOTAL_AIRCRAFT_CAPACITY; ++i) {
                        if (todasLasReservas[i].activa && todasLasReservas[i].idPasajero == cedulaBuscada) {
                            tieneReservas = true;
                            cout << "  - Clase: " << todasLasReservas[i].clase
                                 << ", Asiento: F" << todasLasReservas[i].fila << "C" << todasLasReservas[i].columna
                                 << ", Fecha: " << todasLasReservas[i].fecha << endl;
                        }
                    }
                    if (!tieneReservas) {
                        cout << "  No tiene reservas activas.\n";
                    }
                } else {
                    cout << "Pasajero con cédula " << cedulaBuscada << " no encontrado en los registros.\n";
                }
                break;
            }

            case 8: // Calcular el porcentaje de ocupación del avión
            {
                int asientosOcupados = 0;
                // Contar asientos ocupados en la matriz Ejecutiva
                for (int i = 0; i < MAX_EXECUTIVE_ROWS; i++) {
                    for (int j = 0; j < MAX_EXECUTIVE_COLS; j++) {
                        if (executiveSeats[i][j] == 1) {
                            asientosOcupados++;
                        }
                    }
                }
                // Contar asientos ocupados en la matriz Económica
                for (int i = 0; i < MAX_ECONOMY_ROWS; i++) {
                    for (int j = 0; j < MAX_ECONOMY_COLS; j++) {
                        if (economySeats[i][j] == 1) {
                            asientosOcupados++;
                        }
                    }
                }

                double porcentaje = 0.0;
                if (TOTAL_AIRCRAFT_CAPACITY > 0) {
                    porcentaje = (static_cast<double>(asientosOcupados) * 100.0) / TOTAL_AIRCRAFT_CAPACITY;
                }
                cout << fixed << setprecision(2);
                cout << "Asientos Ocupados: " << asientosOcupados << " de " << TOTAL_AIRCRAFT_CAPACITY << endl;
                cout << "Porcentaje de ocupación del avión: " << porcentaje << "%\n";
                break;
            }

            case 9:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción no válida. Intente nuevamente.\n";
        }
    } while (opcion != 9);

    return 0;
}

// --- FUNCIONES AUXILIARES ---

void inicializarSistema() {
    // Inicializa todos los asientos de las matrices a 0 (disponible)
    for (int i = 0; i < MAX_EXECUTIVE_ROWS; i++) {
        for (int j = 0; j < MAX_EXECUTIVE_COLS; j++) {
            executiveSeats[i][j] = 0;
        }
    }
    for (int i = 0; i < MAX_ECONOMY_ROWS; i++) {
        for (int j = 0; j < MAX_ECONOMY_COLS; j++) {
            economySeats[i][j] = 0;
        }
    }
    // Marca todas las entradas de reserva como inactivas al inicio
    for (int i = 0; i < TOTAL_AIRCRAFT_CAPACITY; i++) {
        todasLasReservas[i].activa = false;
    }
    numReservasActivas = 0;
    numPasajerosRegistrados = 0;
    cout << "Sistema de asientos y reservas inicializado.\n";
}

void mostrarMapaAsientos() {
    cout << "\n--- Mapa de Asientos (0 = Disponible, 1 = Ocupado) ---\n";

    // Mostrar Clase Ejecutiva
    cout << "\nClase Ejecutiva:\n";
    cout << "   "; // Espacio para encabezado de columna
    for (int j = 0; j < MAX_EXECUTIVE_COLS; j++) {
        cout << "C" << j << "  ";
    }
    cout << endl;
    for (int i = 0; i < MAX_EXECUTIVE_ROWS; i++) {
        cout << "F" << i << " ";
        for (int j = 0; j < MAX_EXECUTIVE_COLS; j++) {
            cout << executiveSeats[i][j] << "   ";
        }
        cout << endl;
    }

    // Mostrar Clase Económica
    cout << "\nClase Económica:\n";
    cout << "   "; // Espacio para encabezado de columna
    for (int j = 0; j < MAX_ECONOMY_COLS; j++) {
        cout << "C" << j << "  ";
    }
    cout << endl;
    for (int i = 0; i < MAX_ECONOMY_ROWS; i++) {
        cout << "F" << i << " ";
        for (int j = 0; j < MAX_ECONOMY_COLS; j++) {
            cout << economySeats[i][j] << "   ";
        }
        cout << endl;
    }
}