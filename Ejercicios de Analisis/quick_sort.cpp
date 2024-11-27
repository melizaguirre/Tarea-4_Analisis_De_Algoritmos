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

int particion(std::vector<int>& arreglo, int izquierda, int derecha) {
    int pivote = arreglo[derecha];
    int i = izquierda - 1;

    for (int j = izquierda; j < derecha; j++) {
        if (arreglo[j] < pivote) {
            i++;
            std::swap(arreglo[i], arreglo[j]);
        }
    }

    std::swap(arreglo[i + 1], arreglo[derecha]);
    return i + 1;
}

void quickSort(std::vector<int>& arreglo, int izquierda, int derecha) {
    if (izquierda < derecha) {
        int indiceParticion = particion(arreglo, izquierda, derecha);
        quickSort(arreglo, izquierda, indiceParticion - 1);
        quickSort(arreglo, indiceParticion + 1, derecha);
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
    quickSort(arreglo, 0, arreglo.size() - 1);
    auto fin = std::chrono::high_resolution_clock::now();

    double tiempoMs = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio).count();

    std::cout << "\nArreglo ordenado:" << std::endl;
    imprimirArreglo(arreglo);

    std::cout << "\nTiempo de ejecución de Quick Sort: " << tiempoMs << " ms" << std::endl;

    return 0;
}
