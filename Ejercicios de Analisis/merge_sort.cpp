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

void merge(std::vector<int>& arreglo, int izquierda, int medio, int derecha) {
    int n1 = medio - izquierda + 1;
    int n2 = derecha - medio;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arreglo[izquierda + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arreglo[medio + 1 + j];

    int i = 0, j = 0;
    int k = izquierda;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arreglo[k] = L[i];
            i++;
        } else {
            arreglo[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arreglo[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arreglo[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arreglo, int izquierda, int derecha) {
    if (izquierda < derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        mergeSort(arreglo, izquierda, medio);
        mergeSort(arreglo, medio + 1, derecha);
        merge(arreglo, izquierda, medio, derecha);
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
    mergeSort(arreglo, 0, arreglo.size() - 1);
    auto fin = std::chrono::high_resolution_clock::now();

    double tiempoMs = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio).count();

    std::cout << "\nArreglo ordenado:" << std::endl;
    imprimirArreglo(arreglo);

    std::cout << "\nTiempo de ejecución de Merge Sort: " << tiempoMs << " ms" << std::endl;

    return 0;
}
