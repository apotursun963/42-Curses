
#include <ctime>
#include <iostream>
#include <iomanip>
#include "Account.hpp"


// static değişkenler
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// static fonksiyonlar
int Account::getNbAccounts()    { return _nbAccounts; }
int Account::getTotalAmount()   { return _totalAmount; }
int Account::getNbDeposits()    { return _totalNbDeposits; }
int Account::getNbWithdrawals() { return _totalNbWithdrawals; }

void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
        << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

// Constructor
Account::Account(int initial_deposit) {
    _accountIndex = _nbAccounts++;
    _totalAmount += initial_deposit;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

// Destructor
Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

// Nesneye özel func: Hesaba para yatırır, hem hesabın hem de toplamın bakiyesini ve işlem sayısını artırır, ekrana bilgi yazar.
void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits += 1;
    _totalNbDeposits += 1;
    std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

// Nesneye özel func: Hesaptan para çekmeye çalışır, yeterli para varsa çeker ve bilgileri günceller, yoksa "refused" yazar.
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

// Nesneye özel func: Hesabın mevcut bakiyesini döndürür.
int Account::checkAmount() const {
    return this->_amount;
}

// Nesneye özel func: Hesabın mevcut durumunu (bakiye, işlem sayıları) ekrana yazar.
void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << checkAmount()
              << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

// Her işlem çıktısının başına, şu anki tarihi ve saati [YYYYMMDD_HHMMSS] formatında ekrana yazdırır.
void Account::_displayTimestamp() {
    std::time_t t = std::time(0);       // Şu anki zamanı (saniye cinsinden) alır.
    std::tm *now = std::localtime(&t);  // Zamanı yerel zamana çevirir (yıl, ay, gün, saat, dakika, saniye olarak).
    std::cout << '['
              << std::setw(2) << std::setfill('0') << (now->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << (now->tm_mon + 1)
              << std::setw(2) << std::setfill('0') << now->tm_mday << '_'
              << std::setw(2) << std::setfill('0') << now->tm_hour
              << std::setw(2) << std::setfill('0') << now->tm_min
              << std::setw(2) << std::setfill('0') << now->tm_sec << "] ";
}














/*
Amaç: Bir banka hesabı (Account) sınıfı tasarlamak.
- Birden fazla banka hesabı oluşturabilmek,
- Her hesap için para yatırma, çekme işlemleri yapabilmek,
- Tüm hesaplar için toplam para, toplam işlem sayısı gibi istatistikleri tutmak,
- Her işlemde ve hesap açılış/kapanışında ekrana belirli formatta bilgi yazdırmak.

Hem static (tüm hesaplar için ortak) hem de nesneye özel (her hesap için ayrı) fonksiyonlar/değişkenler var.


- static fonksiyon: 
Static fonksiyon, sınıfa ait olup, nesneye (yani bir objeye) ait değildir.
Static fonksiyonlar, sadece static değişkenlere ve diğer static fonksiyonlara erişebilir.
Nesne oluşturulmadan da çağrılabilirler.

Static değişkenler: Tüm hesaplar için ortak olan, genel bilgileri (toplam hesap sayısı, toplam para, toplam işlem sayısı gibi) tutar.
Static fonksiyonlar: Bu ortak bilgileri almak veya ekrana yazdırmak için kullanılır.
Static olanlar, tüm nesneler için ortaktır ve sınıfın genel durumunu temsil eder. Static olmayanlar ise her nesneye (her hesaba) özeldir.


Constructor ve Destructor
---
Account(int initial_deposit): Yeni bir hesap açar, ilk parayı yatırır, ekrana "created" mesajı yazar.
~Account(): Hesap silindiğinde çağrılır, ekrana "closed" mesajı yazar.



static fonksiyonlar
---
Amaç: Tüm hesaplar için ortak olan bilgileri döndürür veya ekrana yazdırır.
getNbAccounts(): Toplam hesap sayısını döndürür.
getTotalAmount(): Tüm hesaplarda bulunan toplam parayı döndürür.
getNbDeposits(): Tüm hesaplarda yapılan toplam para yatırma işlemi sayısını döndürür.
getNbWithdrawals(): Tüm hesaplarda yapılan toplam para çekme işlemi sayısını döndürür.
displayAccountsInfos(): Yukarıdaki bilgileri ekrana yazdırır.

Nesneye Özel Fonksiyonlar (Her hesap için ayrı)
----
makeDeposit(int deposit): Hesaba para yatırır, hem hesabın hem de toplamın bakiyesini ve işlem sayısını artırır, ekrana bilgi yazar.
makeWithdrawal(int withdrawal): Hesaptan para çekmeye çalışır, yeterli para varsa çeker ve bilgileri günceller, yoksa "refused" yazar.
displayStatus() const: Hesabın mevcut durumunu (bakiye, işlem sayıları) ekrana yazar.
checkAmount() const: Hesabın mevcut bakiyesini döndürür.


Static Değişkenler (Tüm hesaplar için ortak olan verileri tutar.)
_nbAccounts: Toplam hesap sayısı.
_totalAmount: Tüm hesapların toplam parası.
_totalNbDeposits: Tüm hesaplarda yapılan toplam para yatırma işlemi sayısı.
_totalNbWithdrawals: Tüm hesaplarda yapılan toplam para çekme işlemi sayısı.

Nesneye Özel Değişkenler
_accountIndex: Hesabın sıra numarası.
_amount: Hesabın mevcut bakiyesi.
_nbDeposits: Bu hesapta yapılan toplam para yatırma işlemi sayısı.
_nbWithdrawals: Bu hesapta yapılan toplam para çekme işlemi sayısı.


C++’da değişken adının başında alt çizgi (_) kullanmak, 
genellikle özel (private) üye değişkenlerini belirtmek 
için tercih edilir.

Hesap oluşturulurken, işlem yapılırken ve yok edilirken belirli bir formatta çıktı üretmelisin (log dosyasındaki gibi).
Zaman damgalarını _displayTimestamp() fonksiyonu ile üretmelisin.

_displayTimestamp(): 
_displayTimestamp() fonksiyonu, ekrana işlem yapılan anın tarih ve saatini belirli bir formatta (örneğin [20250602_143210]) yazar.
Bu, log çıktılarında her işlemin ne zaman yapıldığını göstermek için kullanılır.


19920104_091532.log
---
Beklenen çıktı örneği (log dosyası).
Programın çıktısı bu dosyadaki gibi olmalı (zaman damgaları hariç).
*/
