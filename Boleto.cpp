//
// Created by Emiliano Garcia on 10/06/25.
//

#include "Boleto.h"

Boleto::Boleto() : precio(0.0), cantidad(0), iva(16.0), total(0.0), subtotal(0.0) {}

Boleto::Boleto(double precio, int cantidad) : iva(16.0), total(0.0), subtotal(0.0) {
    setPrecio(precio);
    setCantidad(cantidad);
    obtenerTotal();
}

void Boleto::setPrecio(double precio) {
    if (precio < 0) {
        throw invalid_argument("El precio no puede ser negativo");
    }
    this->precio = precio;
}

void Boleto::setCantidad(int cantidad) {
    if (cantidad < 0 || cantidad > 4) {
        throw CantidadInvalidaException("La compra máxima de boletos es 4.");
    }
    this->cantidad = cantidad;
}

void Boleto::obtenerTotal() {
    subtotal = cantidad * precio;
    double ivaCalculado = subtotal * (iva / 100.0);
    total = subtotal + ivaCalculado;
}

void Boleto::imprimeBoleto() {
    cout << "\n--- INFORMACIÓN DEL BOLETO ---" << endl;
    cout << "Precio por boleto: $" << precio << endl;
    cout << "Cantidad: " << cantidad << endl;
    cout << "Subtotal: $" << subtotal << endl;
    cout << "IVA (" << iva << "%): $" << (subtotal * iva / 100.0) << endl;
    cout << "Total: $" << total << endl;
}

// SOBRECARGA DE OPERADORES para Boleto
Boleto Boleto::operator+(const Boleto& otro) const {
    Boleto resultado;
    resultado.precio = (precio + otro.precio) / 2; // Precio promedio
    resultado.cantidad = cantidad + otro.cantidad;
    resultado.iva = iva; // Mantener el mismo IVA
    resultado.obtenerTotal();
    return resultado;
}

Boleto Boleto::operator*(int multiplicador) const {
    if (multiplicador < 0) {
        throw invalid_argument("El multiplicador no puede ser negativo");
    }
    Boleto resultado = *this;
    resultado.cantidad *= multiplicador;
    resultado.obtenerTotal();
    return resultado;
}

bool Boleto::operator>(const Boleto& otro) const {
    return total > otro.total;
}

bool Boleto::operator<(const Boleto& otro) const {
    return total < otro.total;
}

ostream& operator<<(ostream& os, const Boleto& boleto) {
    os << "Boleto[Precio: $" << boleto.precio << ", Cantidad: " << boleto.cantidad
       << ", Total: $" << boleto.total << "]";
    return os;
}

Boleto& Boleto::operator+=(const Boleto& otro) {
    cantidad += otro.cantidad;
    obtenerTotal();
    return *this;
}