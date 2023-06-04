#include <iostream>

void* operator new[](size_t size){
    void* p = malloc(size*sizeof(size_t));
    if (p == NULL)
        throw std::exception();
    return p;
}

void operator delete[](void* p){
    free(p);
}

void input(int** arr, int const size){
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            arr[i][j] = rand() % 100;        
}

void print(int** arr, int const size){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            std::cout << arr[i][j] << "\t";
        std::cout << std::endl;
    }
}

int main(){
    int size;
    std::cout << "Size = ";
    std::cin >> size;
    int** matrix = new int*[size];
    for (int i = 0; i < size; i++)
        matrix[i] = new int[size];
    input(matrix,size);
    print(matrix,size);
    for (int i = 0; i < size; i++)
    {
        delete[] matrix[i];
        matrix[i] = nullptr;
    }
    delete[] matrix;
    matrix = nullptr;
    return 0;
}