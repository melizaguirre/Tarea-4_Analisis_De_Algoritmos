#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono> 

std::vector<int> generarArreglo(int cantidad) {
    std::vector<int> arreglo(cantidad);
    for (int i = 0; i < cantidad; i++) {
        arreglo[i] = i + 1;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(arreglo.begin(), arreglo.end(), gen);

    return arreglo;
}

void imprimirArreglo(const std::vector<int>& arreglo) {
    for (int num : arreglo) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void selectionSort(std::vector<int>& arreglo) {
    int n = arreglo.size();
    for (int i = 0; i < n - 1; i++) {
        int minimo = i;
        for (int j = i + 1; j < n; j++) {
            if (arreglo[j] < arreglo[minimo]) {
                minimo = j;
            }
        }
        std::swap(arreglo[i], arreglo[minimo]);
    }
}

int main() {
    int cantidad = 150000;
    std::vector<int> arreglo = generarArreglo(cantidad);

    std::cout << "Arreglo original:" << std::endl;
    imprimirArreglo(arreglo);

    auto inicio = std::chrono::high_resolution_clock::now();

    selectionSort(arreglo);

    auto fin = std::chrono::high_resolution_clock::now();
    auto duracion = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio);

    std::cout << "\nArreglo ordenado:" << std::endl;
    imprimirArreglo(arreglo);

    std::cout << "\nTiempo de ejecución: " << duracion.count() << " ms" << std::endl;

    return 0;
}
