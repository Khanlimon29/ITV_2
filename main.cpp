#include "Templates.h"
#include <iostream>

template <typename T>
void demonstrateArray(T arr[], int size, const std::string typeName) {
    ArrayOperations<T> arrayOps;
    std::cout << "\n<" << typeName << ">\noriginal array: ";
    arrayOps.printArray(arr, size);
    arrayOps.mergeSort(arr, 0, size - 1);
    std::cout << "sorted array: ";
    arrayOps.printArray(arr, size);
    std::cout << "max element: " << arrayOps.findMax(arr, size) << "\n";
}

template <typename T>
void demonstrateSwap(T& a, T& b, const std::string typeName) {
    Swapper<T> swapper;
    std::cout << "\n<" << typeName << ">\noriginal values: " << a << " " << b << "\n";
    swapper.swap(a, b);
    std::cout << "swapped values:  " << a << " " << b << "\n";
}

int main() {
    std::cout << "/Array operations demo/";

    int arrInt[] = {12, 11, 13, 5, 6, 7};
    int sizeInt = sizeof(arrInt) / sizeof(arrInt[0]);
    demonstrateArray(arrInt, sizeInt, "int");

    float arrFloat[] = {1.3, 151.6, 18.4, 5.6, 0.1, 7.1};
    int sizeFloat = sizeof(arrFloat) / sizeof(arrFloat[0]);
    demonstrateArray(arrFloat, sizeFloat, "float");

    char arrChar[] = {'7', '2', '5', 'c', 'a', 'n', 'q'};
    int sizeChar = sizeof(arrChar) / sizeof(arrChar[0]);
    demonstrateArray(arrChar, sizeChar, "char");

    std::cout << "\n\n/Swapper demo/";

    int aInt = 10, bInt = 20;
    demonstrateSwap(aInt, bInt, "int");

    float aFloat = 10.6, bFloat = 20.1;
    demonstrateSwap(aFloat, bFloat, "float");

    char aChar = 'h', bChar = 'c';
    demonstrateSwap(aChar, bChar, "char");

    return 0;
}
