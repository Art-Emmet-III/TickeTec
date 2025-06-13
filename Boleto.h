//
// Created by Emiliano Garcia on 10/06/25.
//

#ifndef BOLETO_H
#define BOLETO_H

#include <iostream>
#include <stdexcept>
using namespace std;

// Excepción para cantidad inválida
class CantidadInvalidaException : public exception {
private:
    string mensaje;
public:
    CantidadInvalidaException(const string& msg) : mensaje(msg) {}
    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};

class Boleto {
protected:
    double precio;
    int cantidad;
    double iva;
    double total;
    double subtotal;

public:
    Boleto();
    Boleto(double precio, int cantidad);
    virtual ~Boleto() {}

    // POLIMORFISMO (virtual)
    virtual void obtenerTotal();
    virtual void imprimeBoleto();

    // SOBRECARGA DE OPERADORES
    Boleto operator+(const Boleto& otro) const;    // Sumar boletos
    Boleto operator*(int multiplicador) const;     // Multiplicar cantidad
    bool operator>(const Boleto& otro) const;     // Comparar totales
    bool operator<(const Boleto& otro) const;
    friend ostream& operator<<(ostream& os, const Boleto& boleto);
    Boleto& operator+=(const Boleto& otro);

    // Getters
    double getPrecio() const { return precio; }
    int getCantidad() const { return cantidad; }
    double getTotal() const { return total; }
    double getSubtotal() const { return subtotal; }

    // Setters con validación
    void setPrecio(double precio);
    void setCantidad(int cantidad);
};

#endif //BOLETO_H
