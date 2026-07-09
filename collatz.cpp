#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <unistd.h>
bool tomar_argumento(int argc, char **argv, unsigned long long *ptr_numero) {
  if (argc > 1) {
    try {
      *ptr_numero = std::stoull(argv[1]);
      return true;
    } catch (const std::invalid_argument &) {
      std::cerr << "Argumento invalido\n";
      return false;
    } catch (const std::out_of_range &) {
      std::cerr << "Numero fuera de rango";
      return false;
    }
  }
  return false;
}
bool tomar_input(unsigned long long *ptr_numero) {
  if (isatty(STDIN_FILENO)) {
    std::cout << "Ingresa un numero entero: ";
  }
  while (!(std::cin >> *ptr_numero)) {
    if (std::cin.eof()) {
      std::cerr << "No se recibio un numero valido\n";
      return false;
    }
    std::cerr << "Overflow detectado mientras se realizaba la operación de "
                 "multiplicación\n";
    std::cin.clear();
    std::cin.ignore();
  }
  return true;
}
bool modificar_numero(unsigned long long *ptr_numero,
                      unsigned long long *ptr_cantidad) {
  const unsigned long long maximo =
      std::numeric_limits<unsigned long long>::max();
  while (true) {
    std::cout << *ptr_cantidad << ".- " << *ptr_numero << "\n";
    if (*ptr_numero == 1) {
      return true;
    }
    (*ptr_cantidad)++;
    if (*ptr_numero % 2 == 0) {
      *ptr_numero /= 2;
    } else {
      if (*ptr_numero > maximo / 3) {
        std::cerr << "Overflow detectado mientras se realizaba la operación de "
                     "multiplicación\n";
        return false;
      }
      unsigned long long temp = *ptr_numero * 3;
      if (temp > maximo - 1) {
        std::cerr << "Overflow detectado mientras se realizaba la operación de "
                     "suma\n";
        return false;
      }
      *ptr_numero = temp + 1;
    }
  }
  return true;
}
int main(int argc, char *argv[]) {
  unsigned long long numero{}, cantidad{1};
  unsigned long long *ptr_numero = &numero;
  unsigned long long *ptr_cantidad = &cantidad;
  if (tomar_argumento(argc, argv, ptr_numero)) {
    modificar_numero(ptr_numero, ptr_cantidad);
  } else if (tomar_input(ptr_numero)) {
    modificar_numero(ptr_numero, ptr_cantidad);
  } else {
    return 1;
  }
  std::cout << "La cantidad de numeros fue: " << cantidad << "\n";
  return 0;
}
