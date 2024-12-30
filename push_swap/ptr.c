# include <stdio.h>
# include <stdlib.h>

/*Önemli

Tek pointer, stack'in ilk elemanını işaret eder.
    - Yani, stack'in başındaki düğümün adresini taşır.
    - Ancak, tek pointer kullanıldığında bu pointer'ın kendisini değiştirmek mümkün değildir.

Çift pointer, stack'in ilk elemanını işaret eden pointer'ı işaret eder.
    - Yani, stack'in başını (top'u) gösteren bir pointer'ın adresini taşır.
    - Bu sayede, fonksiyon içinde stack'in başını (pointer'ı) doğrudan değiştirebiliriz.

Çift pointer kullanmak zorunda olduğumuz durumlar genellikle şunlardır:
    Bir Pointer'ın Adresini Değiştirmek:
        Eğer bir fonksiyon içinde pointer'ın kendisini değiştirmek istiyorsak, çift pointer kullanmalıyız. 
        Tek pointer ile bir fonksiyonda sadece o pointer'ın içeriğine (yani işaret ettiği değere) erişebilirsiniz
        fakat pointer'ın kendisini değiştiremezsiniz.
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
    t_stack* new_elemn = (t_stack*)malloc(sizeof(t_stack));
    
    new_elemn->data = value;
    new_elemn->next = *top;         // Yeni düğümün next'i eski baş düğümü gösterir.
    *top = new_elemn;               // Yeni düğüm stack'in yeni başı olur
    printf("Eleman eklendi: %d\n", value);
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
void    push(t_stack* top, int value)
{
    t_stack* new = (t_stack*)malloc(sizeof(t_stack));

    new->data = value;
    new->next = top;
    top = new;           // top pointer'ı değişir, ancak bu değişiklik main fonksiyonunu etkilemez.
    printf("Eleman eklendi: %d\n", value);
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
Tek işaretçi kullanımı: 
Eğer fonksiyonda yalnızca veriye erişim sağlanacak ve dışarıya bir değişiklik yansıtılmayacaksa, 
tek işaretçi kullanılabilir. Bu, genellikle daha basit durumlarda tercih edilir.
Çift işaretçi kullanımı: 
Eğer fonksiyon, işaretçinin kendisini değiştirmeyi amaçlıyorsa 
(örneğin, bir bağlı listenin başını değiştirmek gibi), çift işaretçi kullanımı gereklidir.
*/



