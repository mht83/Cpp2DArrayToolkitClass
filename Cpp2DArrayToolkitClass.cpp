//////////////////////////////////////////////written by mht83/////////////////////////////////////////
#include "Cpp2DArrayToolkitClass.h"

#include <vector>  
#include <cstddef> 

template<typename T>
class MatrixContainer {
public:
    
    MatrixContainer(size_t rows, size_t cols) {
        rowsCount = rows;
        colsCount = cols;
        arr = std::vector<T>(rows * cols);
    }

    void fill(T value) {
        for (size_t i=0; i < rowsCount * colsCount; ++i) {
            arr[i] = value;
        }
    }

    T& at(size_t row, size_t col) {
        return arr[row * colsCount + col];
    }

    T& data(T value) {
        for (int i = 0; i < rowsCount * colsCount; ++i) {
            if(arr[i]==value){
                return arr[i];
            }
        }
    }

    void capacity() {
        std::cout << "[" << rowCount() << "]" << "[" << colCount() << "]";
    }

    void swap(T a, T b) {
        T temp = data(a); 
        data(a) = data(b);
        data(b) = temp;
    }

    size_t rowCount() const {
        return rowsCount;
    }

    size_t colCount() const {
        return colsCount;
    }

    void display() const {
        auto it = arr.cbegin();
        for (size_t i = 0; i < rowsCount; ++i) {
            for (size_t j = 0; j < colsCount; ++j) {
                std::cout << *it << ' ';
                ++it;
            }
            std::cout << '\n';
        }
    }

private:
    size_t rowsCount;
    size_t colsCount;
    std::vector<T> arr;
};

int main() {
    MatrixContainer<int> matrix(3, 4);
    matrix.fill(1);

    matrix.at(1, 1) = 2;
    matrix.at(1, 2) = 3;

    std::cout << "Filling the matrix with initial values...\n";
    matrix.display();

    matrix.data(2) = 5;

    std::cout << "\nUpdating the value at position (1, 1) to 5...\n";
    matrix.display();

    matrix.swap(3, 5);
    std::cout << "\nSwapping values 3 and 5 in the matrix...\n";
    matrix.display();

    std::cout << "\nSize of matrix is :";
    matrix.capacity();
    std::cout << '\n';
}