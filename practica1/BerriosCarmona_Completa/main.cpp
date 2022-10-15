#include <iostream>
#include "funtionality.hpp"

int main()
{
    int opt;
    while (opt != 4) {
        std::cout << "Elija una de las siguientes opciones" << std::endl;
        std::cout << "1) QuickSort" << std::endl;
        std::cout << "2) Determinante iterativo" << std::endl;
        std::cout << "3) Determinante recursivo" << std::endl;
        std::cout << "4) Salir" << std::endl;

        std::cin >> opt;

        switch (opt) {
            case 1:
                ordenacionQuickSort();
                break;
            case 2:
                determinanteIterativo();
                break;
            case 3:
                determinanteRecursivo();
                break;
            default:
                break;
        }
    }
    return 0;
}
