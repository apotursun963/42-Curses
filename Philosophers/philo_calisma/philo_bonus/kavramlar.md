
## semaphore
Semaphore (semafor), çoklu iş parçacığı (multithreading) veya çoklu işlem (multiprocessing) programlamasında senkronizasyon ve erişim kontrolü için kullanılan bir mekanizmadır. Özellikle kritik bölge (critical section) adı verilen, aynı anda yalnızca belirli sayıda iş parçacığının erişmesini istediğimiz kod bloklarını yönetmek için kullanılır.

Semaphore, bir sayaç (counter) mekanizmasıdır ve belirli sayıda iş parçacığına (veya işlemlere) erişim izni verir. İzin verilen maksimum iş parçacığı sayısı semaforun başlangıç değeri ile belirlenir. Eğer bir iş parçacığı (thread) veya işlem (process) semaforu almak (wait) isterse, semafor değeri 0 olana kadar beklemek zorunda kalır.