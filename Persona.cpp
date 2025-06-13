//
// Created by Emiliano Garcia on 10/06/25.
//

#include "Persona.h"

Persona::Persona() : nombre(""), edad(0), ciudad("") {}

Persona::Persona(string nombre, int edad, string ciudad) {
    this->nombre = nombre;
    setEdad(edad);
    this->ciudad = ciudad;
}

Persona::~Persona() {}

void Persona::imprimePersona() {
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Ciudad: " << ciudad << endl;
}

void Persona::setEdad(int edad) {
    if (edad <= 17) {
        throw EdadInvalidaException("Debes de tener +18 años.");
    }
    this->edad = edad;
}

// SOBRECARGA DE OPERADORES para Persona
bool Persona::operator==(const Persona& otra) const {
    return (nombre == otra.nombre && edad == otra.edad && ciudad == otra.ciudad);
}

bool Persona::operator!=(const Persona& otra) const {
    return !(*this == otra);
}

ostream& operator<<(ostream& os, const Persona& persona) {
    os << "Persona[" << persona.nombre << ", " << persona.edad
       << " años, " << persona.ciudad << "]";
    return os;
}

Persona& Persona::operator=(const Persona& otra) {
    if (this != &otra) {
        nombre = otra.nombre;
        edad = otra.edad;
        ciudad = otra.ciudad;
    }
    return *this;
}