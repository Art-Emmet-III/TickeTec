//
// Created by Emiliano Garcia on 10/06/25.
//

#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// Excepción personalizada para edad inválida
class EdadInvalidaException : public exception {
private:
    string mensaje;
public:
    EdadInvalidaException(const string& msg) : mensaje(msg) {}
    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};

class Persona {
protected:
    string nombre;
    int edad;
    string ciudad;
public:
    Persona();
    Persona(string nombre, int edad, string ciudad);
    virtual ~Persona();

    // POLIMORFISMO - Métodos virtuales
    virtual void imprimePersona();
    virtual void ingresarDatos() = 0; // Método virtual puro

    // SOBRECARGA DE OPERADORES
    bool operator==(const Persona& otra) const;
    bool operator!=(const Persona& otra) const;
    friend ostream& operator<<(ostream& os, const Persona& persona);
    Persona& operator=(const Persona& otra);

    // Getters
    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
    string getCiudad() const { return ciudad; }

    void setEdad(int edad);
};

#endif //PERSONA_H
