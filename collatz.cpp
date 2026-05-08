#include <iostream>
#include <cmath>
int main (int argc, char *argv[]) {
  unsigned long long numero;
  unsigned long long cantidad = 1;
  std::cout << "Ingresa un numero entero: ";
  std::cin >> numero;
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
      numero = numero * 3 + 1;
    }
  }
  std::cout << "La cantidad de numeros fue: " << cantidad << "\n";
  return 0;
}
