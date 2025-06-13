//
// Created by Emiliano Garcia on 10/06/25.
//

#ifndef BOLETOVIP_H
#define BOLETOVIP_H

#include "Boleto.h"

class BoletoVIP : public Boleto {
private:
    double descuento;

public:
    BoletoVIP();
    BoletoVIP(double precio, int cantidad, double descuento = 0.10);

    // HERENCIA con Override de métodos virtuales
    void obtenerTotal() override;
    void imprimeBoleto() override;

    // SOBRECARGA DE OPERADORES  para VIP
    BoletoVIP operator+(const BoletoVIP& otro) const;

    double getDescuento() const { return descuento; }
    void setDescuento(double desc) { descuento = desc; }
};

#endif //BOLETOVIP_H
