#include <iostream>
#include <limits>
int main (int argc, char *argv[]) {
  unsigned long long numero;
  unsigned long long cantidad = 1;
  const unsigned long long maximo = std::numeric_limits<unsigned long long>::max() ;
  std::cout << "Ingresa un numero entero: ";
  while(!(std::cin >> numero)) {
    std::cout << "Error, ese no es un numero valido, prueba con otro número: ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  if (numero < 1) {
    return 0;
  }
  while (true) {
    std::cout << cantidad << ".- " << numero << "\n";
    if (numero == 1) break;
    cantidad = cantidad + 1;
    if (numero % 2 == 0) {
      numero = numero / 2;
    }
    else {
      if (numero > maximo / 3) {
        std::cout << "Overflow detectado mientras se realizaba la operación de multiplicación\n";
        return 1;
      }

      unsigned long long temp = numero * 3;

      if (temp > maximo -1) {
        std::cout << "Overflow detectado mientras se realizaba la operación de suma\n";
        return 1;
      }
      numero = temp + 1;
    }
  }
  std::cout << "La cantidad de numeros fue: " << cantidad << "\n";
  return 0;
}
