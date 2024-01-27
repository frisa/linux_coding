#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handler(int num)
{
    char buf[128];
    size_t len;
    snprintf(buf, 128, "Signal number %d\n", num);
    len = strlen(buf);
    // asynchronous save
    write(STDOUT_FILENO, buf, len);
}

int main()
{
    unsigned int cnt=0;
    signal(SIGINT, handler);
    signal(SIGTERM, handler);
    signal(SIGKILL, handler);
    while (true){
        std::cout << cnt++ << ": process running (pid: " << getpid() << ")"<< std::endl;
        sleep(1);
    }
    return 0;
}