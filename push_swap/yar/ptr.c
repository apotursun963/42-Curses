# include <stdio.h>
# include <stdlib.h>

/*Önemli

-Tek ve Çift Pointer Farkı:
Tek Pointer: Stack'in ilk elemanını işaret eder ve yalnızca işaret ettiği veriyi değiştirebilir. 
Pointer'ın kendisi değiştirilemez.
Tek Pointer Kullanımı: Veriye erişim sağlanacak ve pointer'ın kendisi değiştirilmeyecekse uygundur.

-Çift Pointer: Stack'in ilk elemanını işaret eden pointer'ın adresini taşır. 
Bu sayede, fonksiyon içinde pointer'ın kendisi değiştirilebilir.
Tek ve Çift Pointer Kullanım Durumları:
Çift Pointer Kullanımı: Pointer'ın kendisinin değiştirilmesi gerekiyorsa 
(örneğin, bir bağlı listenin başını değiştirmek için) gereklidir.
*/

void change_pointer(int **ptr)
{
    int x = 10;
    *ptr = &x;      // ptr'in işaret ettiği pointer'ı x'in adresine yönlendiriyoruz.
}

int main(int argc, char *argv[])
{
    int sayi = 7;
    int *ptr = &sayi;

    printf("pointer'in işaret ettği adres: %p\n", ptr);     // yani 
    printf("sayi degiskenin adresi: %p\n", &sayi);                  // 
    printf("ptr degiskenin adresi: %p\n", &ptr);

    printf("%d\n", *ptr);
    change_pointer(&ptr);       // fonksiyona pointer'ın kendisinin adresini gönderiyouz.
    printf("%d\n", *ptr);
}



typedef struct s_stack
{
    int                data;
    struct s_stack     *next;
}   t_stack;


/*
Bu versiyonda, fonksiyonun parametresi bir çift pointer (pointer to pointer) olduğu için, 
top işaretçisinin değeri fonksiyon içinde güncellenir ve bu değişiklik "main" fonksiyonuna yansır. 
Yani, top'un adresine geçildiği için, işaretçinin kendisi de güncellenmiş olur.
*/
void    push(t_stack** top, int value)
{
    t_stack *new_elemn = (t_stack*)malloc(sizeof(t_stack));
    
    new_elemn->data = value;
    new_elemn->next = *top;         // Yeni düğümün next'i eski baş düğümü gösterir.
    *top = new_elemn;               // Yeni düğüm stack'in yeni başı olur
    printf("Eleman eklendi: %d\n", new_elemn->data);
}

int main()
{
    t_stack*    stack = NULL;

    // Stack push fonksiyonuna stack'ın adresi gönderiliyor ve orjinal stack üzerinde değişiklikler oluyor.
    push(&stack, 10);       
    printf("%d\n", *stack);
}

/*
Bu versiyonun çalışması için top işaretçisinin değeri fonksiyon içinde değişir. 
Ancak top işaretçisinin kendisi, fonksiyon bitince geri gönderilmez. 
Yani fonksiyon sadece kendi yerel kopyasını değiştirir ve main fonksiyonundaki stack değeri değişmez.
*/
void    push(t_stack *top, int value)
{
    t_stack* new = (t_stack*)malloc(sizeof(t_stack));

    new->data = value;
    new->next = top;
    top = new;           // top pointer'ı değişir, ancak bu değişiklik main fonksiyonunu etkilemez.
    printf("Eleman eklendi: %d\n", new->data);
}

int main()
{
    t_stack*    stack = NULL;

    // Stack push fonksiyonuna kopyalanarak iletiliyor. 
    // ve push fonksiyonunda kopya üzerinde işlemler oluyor ve 
    // bu işlemler main'de orjinal stack'ı etkilemiyor
    push(stack, 10);
    printf("%d\n", *stack);
}


/*
-Tek işaretçi kullanımı: 
Eğer fonksiyonda yalnızca veriye erişim sağlanacak ve dışarıya bir değişiklik yansıtılmayacaksa, 
tek işaretçi kullanılabilir. Bu, genellikle daha basit durumlarda tercih edilir.
-Çift işaretçi kullanımı: 
Eğer fonksiyon, işaretçinin kendisini değiştirmeyi amaçlıyorsa 
(örneğin, bir bağlı listenin başını değiştirmek gibi), çift işaretçi kullanımı gereklidir.
*/

/*
Çift Pointer: Daha dinamik durumlarda (örneğin, bağlı liste yapılarında) kullanılır 
ve fonksiyon içinde orijinal pointer'ın güncellenmesini sağlar.
Tek Pointer: Daha basit durumlarda yeterlidir ve yalnızca veri üzerinde işlemler yapar.
*/

/*
malloc ile tahsis edilen bellek: 
Bellek tahsis edildikten sonra, işaretçi bu belleği tutar. 
Eğer işaretçiyi NULL yaparsanız, bu bellek alanını kaybedersiniz ve serbest bırakmak mümkün olmaz.
NULL yapmak: 
İşaretçiyi NULL yapmak, önceki belleği kaybetmek anlamına gelir ve bu 
belleği serbest bırakma şansınızı ortadan kaldırır.
free ile serbest bırakma: Bellek serbest bırakılmadan önce işaretçi, 
tahsis edilen bellek alanını işaret ediyor olmalıdır. 
Eğer işaretçi NULL yapılmışsa, serbest bırakma işlemi yapılamaz.

eğer malloc ile ayırdığın bir alana değer vermezsen varsayılan olarak 0 olur linked list'te
*/



void    increase(int *number)
{
    *number = 10;
}

#include <stdio.h>
int main(int argc, char const *argv[])
{
    int num = 5;
    increase(&num);
    printf("%d\n", num);
    return 0;
}
    