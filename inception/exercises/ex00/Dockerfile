# containterin temelini ubuntu yapıyorum (container içindeki işletim sistemi ubuntudur)
FROM ubuntu:latest      

# kendi bilgisayarındaki main.c dosyasını container içindeki çalışma dizinine koyuyorum.
ADD main.c .

# Container içinde terminal komutu çalıştırıyorsun.
RUN apt-get update && apt-get install -y gcc

# GCC kullanarak C kodunu derliyorsun.
RUN gcc main.c -o program

# Container çalışınca otomatik olarak ./program çalışacak
CMD ["./program"]
