// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"


int		main( void ) {

	typedef std::vector<Account::t>							  accounts_t;	// accounts_t: Account nesnelerinden oluşan bir vektör
	typedef std::vector<int>								  ints_t;		// ints_t: int tipinden sayılardan oluşan vektör.
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;	// acc_int_t: Bir Account vektörünün iteratorü ile bir int vektörünün iteratoründen oluşan çift (ikili). Bu, aynı anda iki vektörde ilerlemek için kolaylık sağlar.

	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };	// Her hesap için ilk yatırılacak paralar
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );	// amounts dizisinin uzunluğu alınıyıor
	accounts_t				accounts( amounts, amounts + amounts_size );		// accounts: Yukarıdaki miktarlara sahip sekiz tane Account "nesnesi" oluşturuluyor. (Dizinin başından sonuna kadar olan değerlerle.)
	accounts_t::iterator	acc_begin	= accounts.begin();		// accounts vektörünün ilk elemanını gösteren bir iterator (bir çeşit işaretçi/kursor).
	accounts_t::iterator	acc_end		= accounts.end();

	// Para Yatırma
	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	size_t const		d_size( sizeof(d) / sizeof(int) );
	ints_t				deposits( d, d + d_size );	// Her hesaba yatırılacak para miktarları
	ints_t::iterator	dep_begin	= deposits.begin();		
	ints_t::iterator	dep_end		= deposits.end();

	// Para Çekme
	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) );
	ints_t				withdrawals( w, w + w_size );	// Her hesaptan çekilecek para miktarları.
	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();

	// Tüm hesapların ve sistemin genel durumunu ekrana yazdırır.
	// Her hesap için displayStatus() fonksiyonu çağrılır.
	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	/*
	Toplu Para Yatırma
	acc_begin ve dep_begin'den başlayarak, her bir hesaba sırasıyla para yatırılır.
	Aynı anda iki vektörde (hesaplar ve yatırılacak miktarlar) ilerlemek için acc_int_t (iterator çifti) kullanılır.
	Her iterasyonda, bir hesaba bir para yatırılır.
	*/
	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) );
	}
	
	// Tüm işlemlerden sonra tekrar sistem ve tüm hesaplar ekrana yazdırılır.
	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	// Toplu Para Çekme
	// Tıpkı yatırma işlemi gibi, bu sefer her hesaptan sırasıyla para çekilir.
	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	// Tüm işlemlerden sonra tekrar sistem ve tüm hesaplar ekrana yazdırılır.
	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;
}

/*
Bu main fonksiyonu, birkaç tane Account (Hesap) nesnesi oluşturuyor, her birine başlangıç para yatırıyor, 
sonra topluca para yatırma ve çekme işlemleri yapıyor. Her aşamadan sonra hesapların ve genel 
sistemin durumunu ekrana yazdırıyor.


Vektör (std::vector) nedir?
C++'ta vektör (vector), dinamik olarak boyutlandırılabilen, sıralı bir dizi (array) gibidir.
İçine eleman ekleyip çıkarabilirsiniz; boyutu otomatik olarak değişir.
Standart Kütüphane'de (STL) bulunur: #include <vector>
Kullanımı diziye benzer ama daha esnektir.

Iterator nedir?
Iterator, vektör (veya başka bir STL konteyneri) üzerinde dolaşmayı sağlayan bir "işaretçi"dir.
Dizi indeksleri gibi kullanılır, ama STL yapıları için özel olarak tasarlanmıştır.
Bir vektörün başından sonuna kadar elemanları sırasıyla gezmek için kullanılır.
*/

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
