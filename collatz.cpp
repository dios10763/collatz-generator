#include <iostream>
#include <limits>
#include <string>
#include <unistd.h>
int main (int argc, char *argv[]) {
  unsigned long long numero;
  unsigned long long cantidad = 1;
  const unsigned long long maximo = std::numeric_limits<unsigned long long>::max() ;
  if (argc > 1) {
    try {
      numero = std::stoull(argv[1]);
    }
    catch (const std::invalid_argument&) {
      std::cerr << "Argumento invalido";
      return 1;
    }
    catch (const std::out_of_range&) {
      std::cerr << "Número fuera de rango";
      return 1;
    };
  } else {
      if (isatty(STDIN_FILENO)) {
       std::cout << "Ingresa un numero entero: ";
      }
      while(!(std::cin >> numero)) {
        if (std::cin.eof()) {
          std::cerr << "No se recibio un numero valido\n";
                return 1;
        }
        std::cerr << "Error, ese no es un numero valido, prueba con otro número: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
     }
  
    }
   if (numero < 1) {
    return 0;
  }
  while (true) {
    std::cout << cantidad << ".- " << numero << "\n";
    if (numero == 1) break;
    cantidad++;
    if (numero % 2 == 0) {
      numero /= 2;
    }
    else {
      if (numero > maximo / 3) {
        std::cerr << "Overflow detectado mientras se realizaba la operación de multiplicación\n";
        return 1;
      }

      unsigned long long temp = numero * 3;

      if (temp > maximo -1) {
        std::cerr << "Overflow detectado mientras se realizaba la operación de suma\n";
        return 1;
      }
      numero = temp + 1;
    }
  }
  std::cout << "La cantidad de numeros fue: " << cantidad << "\n";
  return 0;
}
