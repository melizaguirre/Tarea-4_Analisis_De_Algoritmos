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

void heapify(std::vector<int>& arreglo, int n, int i) {
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 

    if (l < n && arreglo[l] > arreglo[largest])
        largest = l;

    if (r < n && arreglo[r] > arreglo[largest])
        largest = r;

    if (largest != i) {
        std::swap(arreglo[i], arreglo[largest]);
        heapify(arreglo, n, largest);
    }
}

void heapSort(std::vector<int>& arreglo) {
    int n = arreglo.size();

    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arreglo, n, i);

    for (int i = n - 1; i > 0; --i) {
        std::swap(arreglo[0], arreglo[i]);
        heapify(arreglo, i, 0);
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
    heapSort(arreglo);
    auto fin = std::chrono::high_resolution_clock::now();

    double tiempoMs = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio).count();

    std::cout << "\nArreglo ordenado:" << std::endl;
    imprimirArreglo(arreglo);

    std::cout << "\nTiempo de ejecución de Heap Sort: " << tiempoMs << " ms" << std::endl;

    return 0;
}
