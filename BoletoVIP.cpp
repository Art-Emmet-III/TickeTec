//
// Created by Emiliano Garcia on 10/06/25.
//

#include "BoletoVIP.h"

BoletoVIP::BoletoVIP() : Boleto(), descuento(0.10) {}

BoletoVIP::BoletoVIP(double precio, int cantidad, double descuento)
    : Boleto(precio, cantidad), descuento(descuento) {
    obtenerTotal(); // Recalcular con descuento
}

void BoletoVIP::obtenerTotal() {
    subtotal = cantidad * precio;
    double subtotalConDescuento = subtotal * (1.0 - descuento);
    double ivaCalculado = subtotalConDescuento * (iva / 100.0);
    total = subtotalConDescuento + ivaCalculado;
}

void BoletoVIP::imprimeBoleto() {
    cout << "\n--- BOLETO VIP ---" << endl;
    cout << "Precio por boleto: $" << precio << endl;
    cout << "Cantidad: " << cantidad << endl;
    cout << "Subtotal: $" << subtotal << endl;
    cout << "Descuento VIP (" << (descuento * 100) << "%): -$"
         << (subtotal * descuento) << endl;
    cout << "Subtotal con descuento: $" << (subtotal * (1.0 - descuento)) << endl;
    cout << "IVA (" << iva << "%): $"
         << ((subtotal * (1.0 - descuento)) * iva / 100.0) << endl;
    cout << "Total: $" << total << endl;
}

BoletoVIP BoletoVIP::operator+(const BoletoVIP& otro) const {
    BoletoVIP resultado;
    resultado.precio = (precio + otro.precio) / 2;
    resultado.cantidad = cantidad + otro.cantidad;
    resultado.descuento = (descuento + otro.descuento) / 2; // Descuento promedio
    resultado.iva = iva;
    resultado.obtenerTotal();
    return resultado;
}