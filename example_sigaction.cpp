#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>

void handler(int num)
{
    size_t len;
    char buf[128];
    snprintf(buf, 128, "signal: %d \n", num);
    len = strlen(buf);
    write(STDOUT_FILENO, buf, len);
}

int main()
{
    unsigned int i;
    struct sigaction sa;
    sa.sa_handler = handler;
    sigaction(SIGINT, &sa, NULL);
    while (1)
    {
        sleep(1);
        printf("sigaction process %d running %d\n", getpid(), i++);
    }
    return 0;
}