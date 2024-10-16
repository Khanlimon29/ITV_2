#pragma once
#include <iostream>
//#include <algorithm> делает бррр
#include "ITemplates.h"

template <typename T>
class ArrayOperations : public IArrayOperations<T> {
public:
    void printArray(const T* array, int size) override;
    T findMax(const T* array, int size) override;
    void mergeSort(T* array, int left, int right) override;
private:
    void merge(T* array, int left, int mid, int right);
};

template <typename T>
class Swapper : public ISwapper<T> {
public:
    void swap(T& a, T& b) override;
};



template<typename T>
void ArrayOperations<T>::printArray(const T* array, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

template<typename T>
T ArrayOperations<T>::findMax(const T* array, int size) {
    T max = array[0];
    for (int i = 1; i < size; ++i) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max; // return *std::max_element(array, array + size); делает бррр 
}

template<typename T>
void ArrayOperations<T>::mergeSort(T* array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(array, left, mid); // сортировка левой 
        mergeSort(array, mid + 1, right); // и правой части

        merge(array, left, mid, right); // слияние
    }
}

template<typename T>
void ArrayOperations<T>::merge(T* array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    T* leftArray = new T[n1];
    T* rightArray = new T[n2];

    for (int i = 0; i < n1; ++i) {
        leftArray[i] = array[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        rightArray[j] = array[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        }
        else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < n2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

template<typename T>
void Swapper<T>::swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}