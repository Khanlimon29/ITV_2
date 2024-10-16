template <typename T>
class IArrayOperations {
public:
    virtual void printArray(const T* array, int size) = 0;
    virtual T findMax(const T* array, int size) = 0;
    virtual void mergeSort(T* array, int left, int right) = 0;
};

template <typename T>
class ISwapper {
public:
    virtual void swap(T& a, T& b) = 0;
};