
#include <cstdlib>
#include <iostream>


class Matrix {
public:
  // 1. Yapıcılar
  Matrix();                              // “Boş” bir matris oluşturur., _rows = 0, _cols = 0 olarak ayarlanır.
  Matrix(size_t rows, size_t cols);      // boyutlandırılmış
  Matrix(const Matrix& other);           // kopyalama yapıcı
  ~Matrix();                             // yıkıcı

  // 2. Atama operatörü
  Matrix& operator=(const Matrix& other);

  // 3. Eleman erişimi
  int& operator()(size_t i, size_t j);             // lvalue
  int  operator()(size_t i, size_t j) const;       // rvalue

  // 4. Aritmetik operatörler
  Matrix operator+(const Matrix& other) const;       // matris toplama
  Matrix operator*(const Matrix& other) const;       // matris çarpma

  // 5. Yardımcılar
  size_t rows() const;   // Matrisin satır sayısını geri döndürmek.
  size_t cols() const;   // Matrisin sütun sayısını geri döndürmek.
  void   fill(int value);                          // tüm elemanlara sabit değer ata

private:
  size_t _rows;
  size_t _cols;
  int*   _data;    // satır-sütun boyutunda tek boyutlu dizi
};
