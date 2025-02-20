



#include <sys/time.h>
#include <stdio.h>


long long get_current_time(void) {
    struct timeval time;
    gettimeofday(&time, NULL);
    return ((long long)time.tv_sec * 1000) + (time.tv_usec / 1000);  
}

int main() {
    printf("Şu anki zaman (ms): %lld\n", get_current_time());
    return 0;
}

