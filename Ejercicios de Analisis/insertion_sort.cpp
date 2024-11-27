#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

std::vector<int> generarArreglo(int cantidad) {
    std::vector<int> arreglo(cantidad);

    for (int i = 0; i < cantidad; i++) {
        arreglo[i] = i + 1;
    }

    for (int i = 0; i < cantidad; i++) {
        int indiceAleatorio = rand() % cantidad;
        int temp = arreglo[i];
        arreglo[i] = arreglo[indiceAleatorio];
        arreglo[indiceAleatorio] = temp;
    }

    return arreglo;
}

void insertionSort(std::vector<int>& arreglo) {
    for (size_t i = 1; i < arreglo.size(); i++) {
        int clave = arreglo[i];
        int j = i - 1;
        while (j >= 0 && arreglo[j] > clave) {
            arreglo[j + 1] = arreglo[j];
            j = j - 1;
        }
        arreglo[j + 1] = clave;
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

    std::cout << "Arreglo original:" << std::endl;
    imprimirArreglo(arreglo);

    auto inicio = std::chrono::high_resolution_clock::now();
    insertionSort(arreglo);
    auto fin = std::chrono::high_resolution_clock::now();

    double tiempoMs = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio).count();

    std::cout << "\nArreglo ordenado:" << std::endl;
    imprimirArreglo(arreglo);

    std::cout << "\nTiempo de ejecución de Insertion Sort: " << tiempoMs << " ms" << std::endl;

    return 0;
}
