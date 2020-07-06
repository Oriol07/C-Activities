#include "Order.h"
#include "Utils.h"
#include <string>
#include <chrono>

const int MAX{ 20000 };

int main() {

	srand(static_cast<unsigned>(time(nullptr)));

#pragma region GENERAR DATOS
	//Array random de 100 elementos
	int *r100c0 = Utils::generate(100, MAX);
	int *r100c1 = Utils::copy(r100c0, 100);
	int *r100c2 = Utils::copy(r100c0, 100);

	//Array random de 1000 elementos
	int *r1000c0 = Utils::generate(1000, MAX);
	int *r1000c1 = Utils::copy(r1000c0, 1000);
	int *r1000c2 = Utils::copy(r1000c0, 1000);

	//Array random de 10000 elementos
	int *r10000c0 = Utils::generate(10000, MAX);
	int *r10000c1 = Utils::copy(r10000c0, 10000);
	int *r10000c2 = Utils::copy(r10000c0, 10000);

	//Array random de 100000 elementos
	int *r100000c0 = Utils::generate(100000, MAX);
	int *r100000c1 = Utils::copy(r100000c0, 100000);
	int *r100000c2 = Utils::copy(r100000c0, 100000);

	//Array ordenado de menor a mayor, el mismo que se generó desordenado
	int *vO100c0 = Utils::copy(r100c0, 100);
	Order::insertionSort(vO100c0, 100);

	int *vO1000c0 = Utils::copy(r1000c0, 1000);
	Order::insertionSort(vO1000c0, 1000);

	int *vO10000c0 = Utils::copy(r10000c0, 10000);
	Order::insertionSort(vO10000c0, 10000);

	int *vO100000c0 = Utils::copy(r100000c0, 100000);
	Order::insertionSort(vO100000c0, 100000);

	//Array ordenado de mayor a menor(el anterior reordenando)
	int *vD100c0 = Utils::reverse(vO100c0, 100);
	int *vD100c1 = Utils::copy(vD100c0, 100);
	int *vD100c2 = Utils::copy(vD100c0, 100);

	int *vD1000c0 = Utils::reverse(vO1000c0, 1000);
	int *vD1000c1 = Utils::copy(vD1000c0, 1000);
	int *vD1000c2 = Utils::copy(vD1000c0, 1000);

	int *vD10000c0 = Utils::reverse(vO10000c0, 10000);
	int *vD10000c1 = Utils::copy(vD10000c0, 10000);
	int *vD10000c2 = Utils::copy(vD10000c0, 10000);

	int *vD100000c0 = Utils::reverse(vO100000c0, 100000);
	int *vD100000c1 = Utils::copy(vD100000c0, 100000);
	int *vD100000c2 = Utils::copy(vD100000c0, 100000);
#pragma endregion

#pragma region MIDIENDO EN MICROSEGUNDOS
	std::chrono::steady_clock::time_point start;

	long long bMBubbleSort[4][3];
	long long bMSelectionSort[4][3];
	long long bMInsertionSort[4][3];

	//Benchmark, condición: Desordenado

	start = std::chrono::high_resolution_clock::now();
	Order::bubbleSort(r100c0, 100);
	bMBubbleSort[0][0] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	start = std::chrono::high_resolution_clock::now();
	Order::bubbleSort(r1000c0, 1000);
	bMBubbleSort[1][0] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	start = std::chrono::high_resolution_clock::now();
	Order::bubbleSort(r10000c0, 10000);
	bMBubbleSort[2][0] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	start = std::chrono::high_resolution_clock::now();
	Order::bubbleSort(r100000c0, 100000);
	bMBubbleSort[3][0] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	start = std::chrono::high_resolution_clock::now();
	Order::selectionSort(r100c1, 100);
	bMSelectionSort[0][0] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	start = std::chrono::high_resolution_clock::now();
	Order::selectionSort(r1000c1, 1000);
	bMSelectionSort[1][0] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	start = std::chrono::high_resolution_clock::now();
	Order::selectionSort(r10000c1, 10000);
	bMSelectionSort[2][0] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	start = std::chrono::high_resolution_clock::now();
	Order::selectionSort(r100000c1, 100000);
	bMSelectionSort[3][0] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	start = std::chrono::high_resolution_clock::now();
	Order::insertionSort(r100c2, 100);
	bMInsertionSort[0][0] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	start = std::chrono::high_resolution_clock::now();
	Order::insertionSort(r1000c2, 1000);
	bMInsertionSort[1][0] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	start = std::chrono::high_resolution_clock::now();
	Order::insertionSort(r10000c2, 10000);
	bMInsertionSort[2][0] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	start = std::chrono::high_resolution_clock::now();
	Order::insertionSort(r100000c2, 100000);
	bMInsertionSort[3][0] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	//Benchmark, condición: Ordenado (el mismo utilizado en el caso anterior pero ordenado)

	start = std::chrono::high_resolution_clock::now();
	Order::bubbleSort(vO100c0, 100);
	bMBubbleSort[0][1] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	start = std::chrono::high_resolution_clock::now();
	Order::bubbleSort(vO1000c0, 1000);
	bMBubbleSort[1][1] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	start = std::chrono::high_resolution_clock::now();
	Order::bubbleSort(vO10000c0, 10000);
	bMBubbleSort[2][1] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	start = std::chrono::high_resolution_clock::now();
	Order::bubbleSort(vO100000c0, 100000);
	bMBubbleSort[3][1] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	start = std::chrono::high_resolution_clock::now();
	Order::selectionSort(vO100c0, 100);
	bMSelectionSort[0][1] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	start = std::chrono::high_resolution_clock::now();
	Order::selectionSort(vO1000c0, 1000);
	bMSelectionSort[1][1] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	start = std::chrono::high_resolution_clock::now();
	Order::selectionSort(vO10000c0, 10000);
	bMSelectionSort[2][1] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	start = std::chrono::high_resolution_clock::now();
	Order::selectionSort(vO100000c0, 100000);
	bMSelectionSort[3][1] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	start = std::chrono::high_resolution_clock::now();
	Order::insertionSort(vO100c0, 100);
	bMInsertionSort[0][1] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	start = std::chrono::high_resolution_clock::now();
	Order::insertionSort(vO1000c0, 1000);
	bMInsertionSort[1][1] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	start = std::chrono::high_resolution_clock::now();
	Order::insertionSort(vO10000c0, 10000);
	bMInsertionSort[2][1] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	start = std::chrono::high_resolution_clock::now();
	Order::insertionSort(vO100000c0, 100000);
	bMInsertionSort[3][1] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	//Benchmark, condición: Ordenado al reves (haciendo reverso del ordenado anterior)

	start = std::chrono::high_resolution_clock::now();
	Order::bubbleSort(vD100c0, 100);
	bMBubbleSort[0][2] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	start = std::chrono::high_resolution_clock::now();
	Order::bubbleSort(vD1000c0, 1000);
	bMBubbleSort[1][2] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	start = std::chrono::high_resolution_clock::now();
	Order::bubbleSort(vD10000c0, 10000);
	bMBubbleSort[2][2] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	start = std::chrono::high_resolution_clock::now();
	Order::bubbleSort(vD100000c0, 100000);
	bMBubbleSort[3][2] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	start = std::chrono::high_resolution_clock::now();
	Order::selectionSort(vD100c1, 100);
	bMSelectionSort[0][2] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	start = std::chrono::high_resolution_clock::now();
	Order::selectionSort(vD1000c1, 1000);
	bMSelectionSort[1][2] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	start = std::chrono::high_resolution_clock::now();
	Order::selectionSort(vD10000c1, 10000);
	bMSelectionSort[2][2] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	start = std::chrono::high_resolution_clock::now();
	Order::selectionSort(vD100000c1, 100000);
	bMSelectionSort[3][2] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	start = std::chrono::high_resolution_clock::now();
	Order::insertionSort(vD100c2, 100);
	bMInsertionSort[0][2] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	start = std::chrono::high_resolution_clock::now();
	Order::insertionSort(vD1000c2, 1000);
	bMInsertionSort[1][2] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	start = std::chrono::high_resolution_clock::now();
	Order::insertionSort(vD10000c2, 10000);
	bMInsertionSort[2][2] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

	start = std::chrono::high_resolution_clock::now();
	Order::insertionSort(vD100000c2, 100000);
	bMInsertionSort[3][2] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();
#pragma endregion

#pragma region MOSTRAR RESULTADOS

	std::cout << "Bubble Sort\n";
	std::cout << "   100:" << bMBubbleSort[0][0] << "--" << bMBubbleSort[0][1] << "--" << bMBubbleSort[0][2] << std::endl;
	std::cout << "  1000:" << bMBubbleSort[1][0] << "--" << bMBubbleSort[1][1] << "--" << bMBubbleSort[1][2] << std::endl;
	std::cout << " 10000:" << bMBubbleSort[2][0] << "--" << bMBubbleSort[2][1] << "--" << bMBubbleSort[2][2] << std::endl;
	std::cout << "100000:" << bMBubbleSort[3][0] << "--" << bMBubbleSort[3][1] << "--" << bMBubbleSort[3][2] << std::endl;
	std::cout << "Selection Sort\n";
	std::cout << "   100:" << bMSelectionSort[0][0] << "--" << bMSelectionSort[0][1] << "--" << bMSelectionSort[0][2] << std::endl;
	std::cout << "  1000:" << bMSelectionSort[1][0] << "--" << bMSelectionSort[1][1] << "--" << bMSelectionSort[1][2] << std::endl;
	std::cout << " 10000:" << bMSelectionSort[2][0] << "--" << bMSelectionSort[2][1] << "--" << bMSelectionSort[2][2] << std::endl;
	std::cout << "100000:" << bMSelectionSort[3][0] << "--" << bMSelectionSort[3][1] << "--" << bMSelectionSort[3][2] << std::endl;
	std::cout << "Insertion Sort\n";
	std::cout << "   100:" << bMInsertionSort[0][0] << "--" << bMInsertionSort[0][1] << "--" << bMInsertionSort[0][2] << std::endl;
	std::cout << "  1000:" << bMInsertionSort[1][0] << "--" << bMInsertionSort[1][1] << "--" << bMInsertionSort[1][2] << std::endl;
	std::cout << " 10000:" << bMInsertionSort[2][0] << "--" << bMInsertionSort[2][1] << "--" << bMInsertionSort[2][2] << std::endl;
	std::cout << "100000:" << bMInsertionSort[3][0] << "--" << bMInsertionSort[3][1] << "--" << bMInsertionSort[3][2] << std::endl;

	system("pause");

#pragma endregion


	return 0;
}