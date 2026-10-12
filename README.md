# Sistema de Gestión e Inventario Vehicular — "Guanajuato Motors"

Este repositorio contiene la implementación en **C++** de un sistema de gestión de inventario vehicular diseñado para la empresa automotriz **Guanajuato Motors**. El objetivo principal del proyecto es solucionar problemas de estabilidad de software mediante el uso avanzado de la **Programación Orientada a Objetos (POO)** y una correcta administración de memoria dinámica en el Heap.

---

## Características Principales y Pilares de POO

El sistema modela una jerarquía de clases para gestionar vehículos, aplicando rigurosamente los siguientes conceptos:

1. **Gestión Dinámica de Memoria y Copia Profunda (*Deep Copy*):**
   * Manejo dinámico del nombre de la `marca` mediante la asignación en el Heap (`new char[]`).
   * Aplicación de la **Regla de los Tres**: Constructor parametrizado, Constructor de Copia Profunda y Operador de Asignación (`operator=`) para evitar punteros colgantes (*dangling pointers*) y fugas de memoria (*memory leaks*).

2. **Encapsulamiento:**
   * Atributos protegidos bajo el modificador `private` (`marca`, `year`, `precio`).
   * Acceso y modificación mediante *Getters* y *Setters* con validación de datos (p. ej. precios no negativos).

3. **Sobrecarga (Métodos y Operadores):**
   * **Métodos:** Sobrecarga de `aplicarDescuento()` para manejar tanto porcentajes como montos fijos en dinero.
   * **Operadores:**
     * `operator+`: Suma escalar de precios base entre vehículos.
     * `operator==`: Comparación de año y precio base entre objetos.
     * `operator<<`: Impresión formateada de datos mediante función `friend`.

4. **Herencia y Polimorfismo:**
   * Clase base `Vehiculo` de la que heredan `Automovil` y `Motocicleta`.
   * Redefinición del método virtual `calcularPrecioFinal()`:
     * **Automovil:** Aplica un 10% de impuesto sobre el precio base.
     * **Motocicleta:** Aplica un 15% de recargo solo si la cilindrada es $\ge 500\text{ cc}$.
     * Manejo polimórfico a través de un arreglo de punteros `Vehiculo*`.

---

## Estructura del Código

```text
├── GestionVehicular_POO_Cecil Quimey Azuara Yañez.cpp   # Código fuente principal en C++
└── README.md                                   # Documentación del proyecto
```

---

## Compilación y Ejecución

Para compilar y ejecutar el proyecto utilizando un compilador estándar como `g++`:

1. **Abrir una terminal en el directorio del archivo.**
2. **Compilar el archivo C++:**
   ```bash
   g++ -std=c++11 "TAREA05_POO_Cecil Quimey Azuara Yañez.cpp" -o InventarioVehicular
   ```
3. **Ejecutar el programa:**
   * En Linux/macOS:
     ```bash
     ./InventarioVehicular
     ```
   * En Windows:
     ```cmd
     InventarioVehicular.exe
     ```

---

## Escenarios de Prueba Demostrados

El método `main()` ejecuta 4 escenarios para verificar el correcto funcionamiento del sistema:

* **Escenario 1:** Construcción de un objeto `Automovil` ("Ferrari") y verificación de la copia profunda mediante `auto2 = auto1`.
* **Escenario 2:** Recorrido polimórfico de un inventario (`Vehiculo*[]`) calculando automáticamente impuestos/recargos de `Automovil` y `Motocicleta`.
* **Escenario 3:** Aplicación de descuento del 10% seguido de un descuento fijo de $5,000 sobre el objeto.
* **Escenario 4:** Prueba de sobrecarga de operadores (`+` para sumar precios base y `==` para evaluar igualdad de estado tras las modificaciones).

---

## Autor y Créditos

**Cecil Quimey Azuara Yáñez**

- **Carrera:** Licenciatura en Ingeniería de Datos e Inteligencia Artificial (LIDIA).
- **Institución:** Universidad de Guanajuato – División de Ingenierías (Campus Irapuato - Salamanca).
- **Asignatura:** Fundamentos del Análisis de Datos.
