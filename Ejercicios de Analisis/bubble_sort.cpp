#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono> 

std::vector<int> generarArreglo(int cantidad) {
    std::vector<int> arreglo(cantidad);
    for (int i = 0; i < cantidad; ++i) {
        arreglo[i] = i + 1;
    }
    for (int i = 0; i < cantidad; ++i) {
        int indiceAleatorio = rand() % cantidad;
        std::swap(arreglo[i], arreglo[indiceAleatorio]);
    }
    return arreglo;
}

void bubbleSort(std::vector<int>& arreglo) {
    int n = arreglo.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arreglo[j] > arreglo[j + 1]) {
                std::swap(arreglo[j], arreglo[j + 1]);
            }
        }
    }
}

void imprimirArreglo(const std::vector<int>& arreglo) {
    for (int num : arreglo) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    int cantidad = 150000; 
    std::vector<int> arreglo = generarArreglo(cantidad);

    std::cout << "Arreglo original: " << std::endl;
    for (int i = 0; i < 150000 && i < arreglo.size(); ++i) { 
        std::cout << arreglo[i] << " ";
    }
    std::cout << std::endl;

    auto inicio = std::chrono::high_resolution_clock::now();
    bubbleSort(arreglo); 
    auto fin = std::chrono::high_resolution_clock::now();

    double tiempoMs = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio).count();

    std::cout << "\nArreglo ordenado: " << std::endl;
    for (int i = 0; i < 150000 && i < arreglo.size(); ++i) { 
        std::cout << arreglo[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "\nTiempo de ejecución de Bubble Sort: " << tiempoMs << " ms" << std::endl;

    return 0;
}
