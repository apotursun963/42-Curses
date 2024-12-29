#!/bin/bash

ARCH=$(uname -srvmo)
PCPU=$(grep 'physical id' /proc/cpuinfo | uniq | wc -l)
VCPU=$(grep processor /proc/cpuinfo | uniq | wc -l)
RAM_TOTAL=$(free -h | grep Mem | awk '{print $2}')
RAM_USED=$(free -h | grep Mem | awk '{print $3}')
RAM_PERC=$(free -k | grep Mem | awk '{printf("%.2f%%"), $3 / $2 * 100}')
DISK_TOTAL=$(df -h --total | grep total | awk '{print $2}')
DISK_USED=$(df -h --total | grep total | awk '{print $3}')
DISK_PERC=$(df -k --total | grep total | awk '{print $5}')
CPU_USAGE=$(top -bn1 | grep '^%Cpu' | xargs | awk '{printf("%.1f%%"), $2 + $4}')
LAST_BOOT=$(who -b | awk '{print($3 " " $4)}')
LVM=$(if [ $(lsblk | grep lvm | wc -l) -eq 0 ]; then echo no; else echo yes; fi)
TCP=$(grep TCP /proc/net/sockstat | awk '{print $3}')
NUM_USERS=$(who | wc -l)
IP_ADDRS=$(hostname -i)
MAC_ADDRS=$(ip link show | grep link/ether | awk '{print $2}')
SUDO_LOG=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

wall "
          	---------------------------------------------------------------
          	 Architecture       : $ARCH					
          	 Physical CPUs      : $PCPU					
          	 Virtual CPUs       : $VCPU					
          	 Memory Usage       : $RAM_USED/$RAM_TOTAL ($RAM_PERC)	
          	 Disk Usage         : $DISK_USED/$DISK_TOTAL ($DISK_PERC)	
          	 CPU Usage          : $CPU_USAGE				
          	 Last Boot          : $LAST_BOOT				
          	 LVM use            : $LVM					
          	 TCP Connections    : $TCP ESTABLISHED	
          	 Number Of Users    : $NUM_USERS
          	 Network            : $IP_ADDRS ($MAC_ADDRS)		
          	 Sudo Command Logs  : $SUDO_LOG commands used		
          	---------------------------------------------------------------
"


# --------------------------------------------------COMMANDS--------------------------------------------------------------
"
1-uname: Sistem Hakkında Bilgiler Verir. (Çekirdek Sürümü, Versiyonu | İşletim Sisteminin Adı...)
2-free: Ram Özelliklerini Görüntüler. (Toplam RAM Miktarı | Kullanılan RAM Miktarı...)
3-top: Bu Komut Sistemin Anlık Performansını Görüntülemek İçin Kullanılan Bir Sistem Yönetim Aracıdır. 
CPU kullanımı, Bellek Kullanımı, Disk I/O, Ağ Aktivitesi Gibi Sistem Kaynaklarının Durumunu İzlemek İçin Oldukça Faydalıdır.
4-df: Sistemdeki Disk Alanı Kullanımını Görüntüler. (Diskteki Tüm Dosya Sistemlerinin Toplam, Kullanılan, Ve Kullanılabilir Alan Bilgilerini Sunar.)
5-lsblk: Sistemde Bağlı Tüm Blok Cihazlarını (Diskler, Partitionlar, Sanal Diskler vb.) Listelemek İçin Kullanılır. 
Bu Komut, Bilgisayarın Disk Düzenini ve Yapılarını Görselleştirir, Cihazların Adlarını, Boyutlarını, Dosya Sistemi Türlerini, 
Mount Noktalarını ve Diğer İlgili Bilgileri Detaylı Bir Şekilde Görüntüler. 
6-wall: Bu komut, sistemdeki tüm aktif kullanıcıların ekranlarına mesaj göndermek için kullanılır. 
"
