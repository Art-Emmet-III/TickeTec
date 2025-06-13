#include <iostream>
#include "Boleto.h"
#include "BoletoVIP.h"
#include "Cliente.h"
using namespace std;

// Arrays con precios y disponibilidad
double precioArr1[4] = {5700.00, 6000.00, 6250.00, 6500.00};
double precioArr2[4] = {2500.00, 2750.00, 3000.00, 3250.00};
double precioArr3[4] = {8000.00, 8250.00, 8500.00, 9000.00};
double precioArr4[4] = {750.00, 800.00, 850.00, 900.00};

int dispArr1[4] = {3579, 2753, 563, 286};
int dispArr2[4] = {794, 641, 27, 18};
int dispArr3[4] = {2791, 3149, 783, 220};
int dispArr4[4] = {569, 629, 115, 190};

void mostrarDemostracionConceptos() {
    cout << "\n*** Ejemplos Predefinidos ***" << endl;

    try {
        // 1. HERENCIA
        cout << "\n1. HERENCIA:" << endl;
        Cliente cliente1("Juan", 25, "CDMX", "juan@email.com");
        cout << "Cliente creado usando herencia de Persona" << endl;

        // 2. POLIMORFISMO
        cout << "\n2. POLIMORFISMO:" << endl;
        Boleto* boleto1 = new Boleto(1000, 2);
        Boleto* boletoVIP1 = new BoletoVIP(1000, 2, 0.15);

        cout << "Boleto normal:" << endl;
        boleto1->imprimeBoleto();
        cout << "\nBoleto VIP (comportamiento diferente):" << endl;
        boletoVIP1->imprimeBoleto();

        // 3. SOBRECARGA DE OPERADORES
        cout << "\n3. SOBRECARGA DE OPERADORES:" << endl;
        Boleto boleto2(500, 1);
        Boleto boleto3 = *boleto1 + boleto2; // Operador +
        cout << "Boleto1 + Boleto2 = " << boleto3 << endl;

        Boleto boleto4 = boleto2 * 3; // Operador *
        cout << "Boleto2 * 3 = " << boleto4 << endl;

        bool esMayor = *boleto1 > boleto2; // Operador >
        cout << "¿Boleto1 > Boleto2? " << (esMayor ? "Sí" : "No") << endl;

        // 4. MANEJO DE EXCEPCIONES
        cout << "\n4. MANEJO DE EXCEPCIONES:" << endl;

        // Excepción por cantidad inválida
        try {
            Boleto boletoInvalido(100, -5);
        } catch (const CantidadInvalidaException& e) {
            cout << "Excepción capturada: " << e.what() << endl;
        }

        // Excepción por edad inválida
        try {
            Cliente clienteInvalido("Pedro", 15, "GDL", "pedro@email.com");
        } catch (const EdadInvalidaException& e) {
            cout << "Excepción capturada: " << e.what() << endl;
        }

        // Excepción por edad inválida
        try {
            Cliente clienteEdadAlta("María", 150, "GDL", "maria@email.com");
        } catch (const EdadInvalidaException& e) {
            cout << "Excepción capturada: " << e.what() << endl;
        }

        delete boleto1;
        delete boletoVIP1;

    } catch (const exception& e) {
        cout << "Error general: " << e.what() << endl;
    }
}

void comprarBoletosConExcepciones(double precios[], int disponibilidad[]) {
    try {
        string zona;
        int cantidad;
        char esVIP;

        cout << "\n--------" << endl;
        cout << "PRECIOS" << endl;
        cout << "--------" << endl;
        cout << "a) Cabecera norte: $" << precios[0] << endl;
        cout << "b) Cabecera sur: $" << precios[1] << endl;
        cout << "c) Platea B: $" << precios[2] << endl;
        cout << "d) Platea A: $" << precios[3] << endl;

        cout << "\nZona: ";
        cin >> zona;
        cout << "Cantidad de boletos (máximo 4): ";
        cin >> cantidad;

        // Validar disponibilidad
        int indice = -1;
        if (zona == "a") indice = 0;
        else if (zona == "b") indice = 1;
        else if (zona == "c") indice = 2;
        else if (zona == "d") indice = 3;
        else throw invalid_argument("Zona inválida");

        if (disponibilidad[indice] < cantidad) {
            throw runtime_error("No hay suficientes boletos disponibles");
        }

        double precio = precios[indice];
        disponibilidad[indice] -= cantidad;

        cout << "¿Es boleto VIP? (s/n): ";
        cin >> esVIP;

        // Crear boleto usando polimorfismo
        // Solo si se ingresa 's' se considerara VIP, de otra forma normal
        Boleto* boleto;
        if (esVIP == 's') {
            boleto = new BoletoVIP(precio, cantidad);
        } else {
            boleto = new Boleto(precio, cantidad);
        }

        // Crear cliente
        Cliente cliente;
        cliente.ingresarDatos();

        // Mostrar información
        cliente.imprimePersona();
        boleto->imprimeBoleto();

        delete boleto;

    } catch (const CantidadInvalidaException& e) {
        cout << "Error en cantidad: " << e.what() << endl;
    } catch (const EdadInvalidaException& e) {
        cout << "Error en edad: " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "Error de ejecución: " << e.what() << endl;
    } catch (const exception& e) {
        cout << "Error general: " << e.what() << endl;
    }
}

int main() {
    int opcion;

    do {
        cout << "\n-----------------------------------------------------" << endl;
        cout << "Bienvenido al sistema de compras en línea de TICKETEC" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "1. Ver eventos" << endl;
        cout << "2. Comprar boletos" << endl;
        cout << "3. Disponibilidad" << endl;
        cout << "4. Demostración de conceptos OOP" << endl;
        cout << "5. Salir" << endl;
        cout << "\nIngrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                // Mostrar eventos
                cout << "\n--- EVENTOS DISPONIBLES ---" << endl;
                cout << "1. Portugal vs España - 8 Jun 2025" << endl;
                cout << "2. Cruz Azul vs América - 15 Dic 2025" << endl;
                cout << "3. Pittsburgh Steelers vs Baltimore Ravens - 7 Ene 2026" << endl;
                cout << "4. Boca Juniors vs River Plate - 7 Ene 2026" << endl;
                break;

            case 2: {
                int evento;
                cout << "\n-----------------------------------------------------" << endl;
                cout << "1. Portugal vs España - 8 Jun 2025" << endl;
                cout << "2. Cruz Azul vs América - 15 Dic 2025" << endl;
                cout << "3. Pittsburgh Steelers vs Baltimore Ravens - 7 Ene 2026" << endl;
                cout << "4. Boca Juniors vs River Plate - 7 Ene 2026" << endl;
                cout << "-----------------------------------------------------" << endl;
                cout << "Seleccione evento (1-4): ";
                cin >> evento;

                switch (evento) {
                    case 1: comprarBoletosConExcepciones(precioArr1, dispArr1); break;
                    case 2: comprarBoletosConExcepciones(precioArr2, dispArr2); break;
                    case 3: comprarBoletosConExcepciones(precioArr3, dispArr3); break;
                    case 4: comprarBoletosConExcepciones(precioArr4, dispArr4); break;
                    default: cout << "Evento inválido" << endl;
                }
                break;
            }

            case 3:
                // Mostrar disponibilidad
                cout << "\n--- DISPONIBILIDAD ---" << endl;
            cout << "Cabecera norte -> CN, Cabecera sur -> CS, Platea B -> PB, Platea A -> PA" << endl;
            cout << "-------------------------------------------------------------------------" << endl;
                cout << "POR vs ESP: CN - " << dispArr1[0] << ", CS - " << dispArr1[1]
                     << ", PB - " << dispArr1[2] << ", PA - " << dispArr1[3] << endl;
            cout << "CAZ vs AME: CN - " << dispArr2[0] << ", CS - " << dispArr2[1]
                     << ", PB - " << dispArr2[2] << ", PA - " << dispArr2[3] << endl;
            cout << "PIT vs BAL: CN - " << dispArr3[0] << ", CS - " << dispArr3[1]
            << ", PB - " << dispArr3[2] << ", PA - " << dispArr3[3] << endl;
            cout << "BOC vs RIV: CN - " << dispArr4[0] << ", CS - " << dispArr4[1]
            << ", PB - " << dispArr4[2] << ", PA - " << dispArr4[3] << endl;
                break;

            case 4:
                mostrarDemostracionConceptos();
                break;

            case 5:
                cout << "¡Gracias por usar TICKETEC!" << endl;
                break;

            default:
                cout << "Opción inválida" << endl;
        }

    } while (opcion != 5);

    return 0;
}