#include <iostream>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signo)
{
    std::cout << "recieved signal number: " << signo << std::endl;
}

int main()
{
    if (signal(SIGINT, sig_handler) == SIG_ERR)
    {
        std::cerr << "Error by registering handler" << std::endl;
    }
    while (true){
        std::cout << "Process running\n";
        sleep(1);
    }
    return 0;
}