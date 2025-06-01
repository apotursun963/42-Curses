
#include <ctime>
#include <iostream>
#include <iomanip>
#include "Account.hpp"


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts()    { return _nbAccounts; }
int Account::getTotalAmount()   { return _totalAmount; }
int Account::getNbDeposits()    { return _totalNbDeposits; }
int Account::getNbWithdrawals() { return _totalNbWithdrawals; }

void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
        << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit) {
    _accountIndex = _nbAccounts++;
    _totalAmount += initial_deposit;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits += 1;
    _totalNbDeposits += 1;
    std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
    if ((_amount - withdrawal) < 0)
        return (std::cout << "refused\n", false);
    std::cout << withdrawal;
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals += 1;
    _totalNbWithdrawals += 1;
    std::cout << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return (true);
}

void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount
              << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp() {
    std::time_t t = std::time(0);   // get time now
    std::tm *now = std::localtime(&t);
    std::cout << '['
              << std::setw(2) << std::setfill('0') << (now->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << (now->tm_mon + 1)
              << std::setw(2) << std::setfill('0') << now->tm_mday << '_'
              << std::setw(2) << std::setfill('0') << now->tm_hour
              << std::setw(2) << std::setfill('0') << now->tm_min
              << std::setw(2) << std::setfill('0') << now->tm_sec << "] ";
}














/*
bir banka hesabı (Account) sınıfı tasarlamak ve uygulamak.

Sana verilen Account.hpp başlık dosyasındaki fonksiyonların ve değişkenlerin gövdesini (Account.cpp içinde) yazacaksın.
Sınıf, banka hesabı açma, para yatırma, para çekme gibi işlemleri ve bazı istatistikleri (toplam hesap sayısı, toplam para, toplam işlem sayısı vs.) tutacak.

Sınıfta hem statik (tüm hesaplar için ortak) hem de her nesneye ait (her hesap için ayrı) değişkenler var.
Statik fonksiyonlar ve değişkenlerle, tüm hesapların toplam bilgilerini tutacaksın.

Sana verilen tests.cpp dosyası, yazdığın sınıfı test ediyor.
Kodunu derleyip çalıştırınca, testlerin hepsini geçmeli ve çıktı, verilen log dosyasındakiyle aynı olmalı (zaman damgaları hariç).

Hesap oluşturulurken, işlem yapılırken ve yok edilirken belirli bir formatta çıktı üretmelisin (log dosyasındaki gibi).
Zaman damgalarını _displayTimestamp() fonksiyonu ile üretmelisin.
*/


/*

- static fonksiyon: 
Static fonksiyon, sınıfa ait olup, nesneye (yani bir objeye) ait değildir.
Static fonksiyonlar, sadece static değişkenlere ve diğer static fonksiyonlara erişebilir.
Nesne oluşturulmadan da çağrılabilirler.

- static değişken:
Static değişken, bir sınıfta tanımlandığında, o sınıftan oluşturulan tüm nesneler için ortak olur.
Yani, static değişkenin tek bir kopyası vardır ve tüm nesneler bu ortak değeri paylaşır.

Static değişkenler: Tüm hesaplar için ortak olan, genel bilgileri (toplam hesap sayısı, toplam para, toplam işlem sayısı gibi) tutar.
Static fonksiyonlar: Bu ortak bilgileri almak veya ekrana yazdırmak için kullanılır.
Static olanlar, tüm nesneler için ortaktır ve sınıfın genel durumunu temsil eder. Static olmayanlar ise her nesneye (her hesaba) özeldir.


Amaç: Tüm hesaplar için ortak olan bilgileri döndürür veya ekrana yazdırır.
getNbAccounts(): Toplam hesap sayısını döndürür.
getTotalAmount(): Tüm hesaplarda bulunan toplam parayı döndürür.
getNbDeposits(): Tüm hesaplarda yapılan toplam para yatırma işlemi sayısını döndürür.
getNbWithdrawals(): Tüm hesaplarda yapılan toplam para çekme işlemi sayısını döndürür.
displayAccountsInfos(): Yukarıdaki bilgileri ekrana yazdırır.

Amaç: Tüm hesaplar için ortak olan verileri tutar.
_nbAccounts: Toplam hesap sayısı.
_totalAmount: Tüm hesapların toplam bakiyesi.
_totalNbDeposits: Tüm hesaplarda yapılan toplam para yatırma işlemi sayısı.
_totalNbWithdrawals: Tüm hesaplarda yapılan toplam para çekme işlemi sayısı.


C++’da değişken adının başında alt çizgi (_) kullanmak, 
genellikle özel (private) üye değişkenlerini belirtmek 
için tercih edilir.
*/