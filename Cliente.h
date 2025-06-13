//
// Created by Emiliano Garcia on 10/06/25.
//

#ifndef CLIENTE_H
#define CLIENTE_H

#include "Persona.h"



class Cliente : public Persona {
private:
    string email;
public:
    Cliente();
    Cliente(string nombre, int edad, string ciudad, string email);
    ~Cliente();

    // HERENCIA con Override de métodos virtuales
    void imprimePersona() override;
    void ingresarDatos() override;

    // SOBRECARGA DE OPERADORES específicos para Cliente
    Cliente operator+(const Cliente& otro) const; // Combinar clientes
    bool operator<(const Cliente& otro) const;    // Comparar por edad

    // Getters y Setters
    string getEmail() const { return email; }
    void setEmail(const string& email);

private:
    void verificarEdad();
};

#endif //CLIENTE_H
