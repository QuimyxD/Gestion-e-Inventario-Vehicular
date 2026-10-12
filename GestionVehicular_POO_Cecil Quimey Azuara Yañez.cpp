#include <iostream>
#include <cstring>

using namespace std;

// Clase base "Vehiculo"
class Vehiculo{
private:
    char* marca;
    int year;
    double precio;

public:
    // Constructor por defecto
    Vehiculo() : year(0), precio(0.0){
        marca = new char[1]{'\0'}; // Memoria dinamica para "marca"
    }

    // Constructor parametrizado
    Vehiculo(const char* m, int y, double p) : year(y), precio(p > 0 ? p : 0.0){
        marca = new char[strlen(m) + 1]; // Memoria dinamica para "marca"
        strcpy(marca, m);
    }

    // Constructor de copia profunda (Deep Copy)
    Vehiculo(const Vehiculo& v) : year(v.year), precio(v.precio) {
        marca = new char[strlen(v.marca) + 1];
        strcpy(marca, v.marca);
        cout << "Copia hecha y memoria dinamica para \"marca\".\n" << endl;
    }

    // Operador de asignacion
    Vehiculo& operator=(const Vehiculo& v) {
        if (this != &v){
            delete[] marca;
            marca = new char[strlen(v.marca) + 1];
            strcpy(marca, v.marca);
            year = v.year;
            precio = v.precio;
        }
        return *this;
    }

    // Destructor
    virtual ~Vehiculo(){ 
        delete[] marca;
    }

    // Setters
    void setMarca(const char* m){
        delete[] marca;
        marca = new char[strlen(m) + 1];
        strcpy(marca, m);
    }

    void setYear(int y){ 
        year = y; 
    }

    void setPrecio(double p){ 
        precio = (p > 0) ? p : precio; 
    }

    // Getters
    const char* getMarca() const{ 
        return marca; 
    }

    int getYear() const{ 
        return year; 
    }

    double getPrecio() const{ 
        return precio; 
    }

    // Sobrecarga de aplicarDescuento
    void aplicarDescuento(double porcentaje){ 
        precio -= (precio * (porcentaje / 100.0)); 
    }

    void aplicarDescuento(double monto, bool Fijo){
        if (Fijo && precio >= monto) precio -= monto;
    }

    // Calculo polimorfico base
    virtual double calcularPrecioFinal() const{ 
        return precio; 
    }

    // Sobrecarga de operadores
    double operator+(const Vehiculo& v) const{ 
        return precio + v.precio; 
    }

    bool operator==(const Vehiculo& v) const{ 
        return (year == v.year && precio == v.precio); 
    }

    friend ostream& operator<<(ostream& os, const Vehiculo& v){
        return os << "Marca: " << v.marca << "\nYear: " << v.year << "\nPrecio Base: $" << v.precio;
    }
};

// Clase derivada "Automovil"
class Automovil : public Vehiculo{
private:
    int puertas;

public:
    Automovil() : Vehiculo(), puertas(4){}

    Automovil(const char* m, int y, double p, int numPuertas) 
        : Vehiculo(m, y, p), puertas(numPuertas){}

    void setNumPuertas(int p){ 
        puertas = p; 
    }

    int getNumPuertas() const{ 
        return puertas; 
    }

    // 10%
    double calcularPrecioFinal() const{ 
        return getPrecio() * 1.10; 
    }

};

// Clase derivada "Motocicleta"
class Motocicleta : public Vehiculo{
private:
    int cilindrada;

public:
    Motocicleta() : Vehiculo(), cilindrada(125){}

    Motocicleta(const char* m, int y, double p, int cc) 
        : Vehiculo(m, y, p), cilindrada(cc){}

    void setCilindrada(int cc){ 
        cilindrada = cc; 
    }

    int getCilindrada() const{ 
        return cilindrada; 
    }

    // Recargo del 15% si la cilindrada >= 500 cc
    double calcularPrecioFinal() const{
        return (cilindrada >= 500) ? getPrecio() * 1.15 : getPrecio();
    }
};

// main
int main() {
    cout << "ESCENARIO 1\n" << endl;
    Automovil auto1("Ferrari", 2026, 6500000.00, 4);
    cout << auto1 << endl;

    Automovil auto2 = auto1; // Llama al constructor de copia
    cout << "\nauto2 (copia):\n" << auto2 << endl << endl;

    cout << "ESCENARIO 2\n" << endl;
    Motocicleta moto1("BMW", 2026, 750000.00, 725);

    Vehiculo* inventario[] = { &auto1, &moto1 };

    for (int i = 0; i < 2; i++) {
        cout << *inventario[i] 
             << "\nPrecio Final: $" << inventario[i]->calcularPrecioFinal() << "\n" << endl;
    }

    cout << "ESCENARIO 3\n" << endl;
    cout << "Precio inicial auto1: $" << auto1.getPrecio() << endl;
    
    auto1.aplicarDescuento(10.0); // Descuento 10%
    cout << "Precio con el 10% de descuento: $" << auto1.getPrecio() << endl;

    auto1.aplicarDescuento(5000.0, true); // Descuento fijo $5000
    cout << "Precio con $5000 de descuento fijo: $" << auto1.getPrecio() << endl << endl;

    cout << "ESCENARIO 4\n" << endl;
    cout << "Suma de precios base (auto1 + moto1): $" << (auto1 + moto1) << endl;

    if (auto1 == auto2) {
        cout << "auto1 y auto2 tienen el mismo year y precio." << endl;
    } else {
        cout << "auto1 y auto2 NO tienen el mismo year y precio." << endl;
    }

    return 0;
}