# TickeTec 🎟️

Proyecto en C++ para la venta de boletos en línea. Este sistema permite registrar clientes y generar distintos tipos de boletos, incluyendo boletos VIP, utilizando conceptos de Programación Orientada a Objetos.

---

## 🚀 Características principales

- Uso de **herencia** y **polimorfismo** mediante clases como `Persona` y `Cliente`.
- Manejo de **sobrecarga de operadores** para comparar y combinar clientes.
- Distinción entre **boletos normales y VIP** con clases especializadas (`Boleto`, `BoletoVIP`).
- Construcción del proyecto con **CMake** y desarrollado en **CLion**.

---

## 🧩 Estructura del código

├── Boleto.h / Boleto.cpp       -> Clase base para boletos
├── BoletoVIP.h / BoletoVIP.cpp -> Herencia de Boleto con características extra
├── Persona.h / Persona.cpp     -> Clase base para personas
├── Cliente.h / Cliente.cpp     -> Herencia de Persona, incluye email y operadores
├── main.cpp                    -> Menú y lógica principal
├── CMakeLists.txt              -> Archivo de configuración para compilar el proyecto
└── .gitignore                  -> Evita subir archivos temporales o del IDE

