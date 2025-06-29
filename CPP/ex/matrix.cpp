

#include "matrix.hpp"

// Yapıcılar ve Yıkıcılar
Matrix::Matrix() 
    : _rows(0), _cols(0), _data(nullptr) {

}

Matrix::Matrix(size_t rows, size_t cols)
    : _rows(rows), _cols(cols), _data(new int[rows * cols]) {       // new int[rows * cols]() -> 0'lıyor
}

Matrix::Matrix(const Matrix& other) 
    : _rows(other._rows), _cols(other._cols), _data(new int[other._rows * other._cols])
{
  for (size_t i = 0; i < _rows * _cols; ++i)
    _data[i] = other._data[i];
}

Matrix::~Matrix() {
    delete[] _data;
}


// Atama Operatörleri
Matrix& Matrix::operator=(const Matrix& other) {

    if (this == &other)     // Self-assignment kontrolü
        return *this;
    
    delete[] _data;         // Eski belleği sil

    // Boyutları kopyala
    _rows = other._rows;
    _cols = other._cols;

    // Yeni bellek ayır ve verileri kopyala
    _data = new int [_rows * _cols];
    for (int i=0; i < _rows * _cols; ++i)
        _data[i] = other._data[i];

    return *this;   // Zincirli atamaya izin ver
}



// Eleman Erişimi Fonksiyonları
int &Matrix::operator()(size_t i, size_t j) {   // Değerler Değiştirilebilir
    if (i >= _rows || j >= _cols)
        std::cout << "out of index\n";
    return _data[i * _cols + j];
}

/*
- Fonksiyonunun sonundaki const:
fonksiyon sınıfın hiçbir üye değişkenini değiştirmez
- Parametrelerin başındaki const:
yalnızca parametreyi değiştirmemize izin vermez.
*/
int Matrix::operator()(size_t i, size_t j) const {  // Değerler Değiştirilemez çünkü "const"
    if (i >= _rows || j >= _cols)
        std::cout << "out of index\n";
    return _data[i * _cols + j];
}



// Aritmetik Operatör Overload’ları
Matrix Matrix::operator+(const Matrix& other) const {
    if (_rows != other._rows || _cols != other._cols)
        std::cout << "invalid size\n";
    
    // Sonuç matrisi oluştur
    Matrix result(_rows, _cols);

    // Hücre hücre toplama
    for (size_t i = 0; i < _rows; ++i) {
        for (size_t j = 0; j < _cols; ++j) {
            result(i, j) = (*this)(i, j) + other(i, j);
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (_cols != other._rows)
        std::cout << "invalid size\n";
    
    // 2. Sonuç matrisi: _rows × rhs._cols boyutunda
    Matrix result(_rows, other._cols);

    result.fill(0);  // çarpmada toplama yapacağımız için sıfırla başlatmak mantıklı

    for (size_t i = 0; i < _rows; ++i) {
        for (size_t j = 0; j < other._cols; ++j) {
            int sum = 0;
            for (size_t k = 0; k < _cols; ++k) {
                sum += (*this)(i, k) * other(k, j);
            }
            result(i, j) = sum;
        }
    }
    return result;
}




// Yardımcı fonksiyonlar
size_t Matrix::rows() const {
    return _rows;
}

size_t Matrix::cols() const {
    return _cols;
}

void Matrix::fill(int value) {
    for (int i=0; i < _rows * _cols; i++)
        _data[i] = value;
}
