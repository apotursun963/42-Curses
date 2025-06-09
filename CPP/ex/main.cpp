

#include "matrix.hpp"
#include <iomanip>      // setw için

void printMatrix(const Matrix& m) {
    for (size_t i = 0; i < m.rows(); ++i) {
        for (size_t j = 0; j < m.cols(); ++j) {
            std::cout << " " << m(i,j);
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

int main()
{
    Matrix matrix1(3, 3);
    matrix1.fill(7);
    printMatrix(matrix1);

    Matrix matrix2(matrix1);
    matrix2.fill(10);
    printMatrix(matrix2);

    Matrix C = matrix1 + matrix2;
    printMatrix(C);

    return 0;
}
