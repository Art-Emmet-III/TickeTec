//
// Created by Emiliano Garcia on 10/06/25.
//

#include "Cliente.h"
#include <regex>

Cliente::Cliente() : Persona(), email("") {}

Cliente::Cliente(string nombre, int edad, string ciudad, string email)
    : Persona() {
    this->nombre = nombre;
    setEdad(edad);    // Esto puede lanzar EdadInvalidaException
    this->ciudad = ciudad;
}

Cliente::~Cliente() {}

void Cliente::imprimePersona() {
    cout << "\n----------" << endl;
    cout << "CLIENTE" << endl;
    cout << "----------" << endl;
    Persona::imprimePersona();
    cout << "Email: " << email << endl;
}

void Cliente::ingresarDatos() {
    cout << "\n------------------" << endl;
    cout << "Datos del Cliente" << endl;
    cout << "------------------" << endl;
    cout << "Nombre: ";
    cin >> nombre;

    cout << "Edad (+18): ";
    verificarEdad();

    cout << "Ciudad: ";
    cin >> ciudad;

    cout << "Email: ";
    cin >> email;
}



void Cliente::verificarEdad() {
    int edadTemp;
    bool edadValida = false;
    while (!edadValida) {
        try {
            cin >> edadTemp;
            if (edadTemp < 18) {
                throw EdadInvalidaException("Debe ser mayor de 18 años");
            }
            setEdad(edadTemp);
            edadValida = true;
        } catch (const EdadInvalidaException& e) {
            cout << "Error: " << e.what() << ". Reingrese: ";
        }
    }
}

// SOBRECARGA DE OPERADORES para Cliente
Cliente Cliente::operator+(const Cliente& otro) const {
    // Combinar información de dos clientes
    string nombreCombinado = nombre + " & " + otro.nombre;
    int edadPromedio = (edad + otro.edad) / 2;
    string ciudadCombinada = ciudad == otro.ciudad ? ciudad : ciudad + "/" + otro.ciudad;
    string emailCombinado = email + ";" + otro.email;

    return Cliente(nombreCombinado, edadPromedio, ciudadCombinada, emailCombinado);
}

bool Cliente::operator<(const Cliente& otro) const {
    return edad < otro.edad;
}