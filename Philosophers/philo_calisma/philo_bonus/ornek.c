

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>



// Process örneği

int main(int argc, char const *argv[])
{
    pid_t   child_pid = fork();

    if (child_pid < 0)
        return (-1);
    else if (child_pid == 0)
    {
        printf("Child process started (PID: %d)\n", getpid());
        sleep(3);
        printf("Child process exiting...\n");
        kill(getpid(), SIGKILL);
    }
    else
    {
        // Ebeveyn süreci çocuk süreci beklesin
        waitpid(child_pid, NULL, 0);    // waitpid kullanmazsan ne olurmuş anla (windows + ş = emoji)
        printf("Child process cleaned up.\n");
    }
    return 0;
}










// Semaphore örneği
