#include <iostream>
#include <unistd.h>
#include "sys/wait.h"

void zadanie1()
{
    pid_t pid = fork();
    if (pid == 0)
    {
        std::cout << "Jestem dzieckiem, mój PID to: " << getpid() << ", PID mojego rodzica to: " << getppid() << std::endl;
    } else
    {
        std::cout << "Jestem procesem głownym, mój PID to: " << getpid() << ", PID mojego rodzica to: " << getppid() << std::endl;
    }
}

void zadanie2()
{
    pid_t pid;

    std::cout << "Jestem procesem głownym, mój PID to: " << getpid() << ", PID mojego rodzica to: " << getppid() << std::endl;

    for (int i = 0; i < 5; ++i) {
        pid = fork();

        if(pid == -1){
            perror("fork: ");
            exit(1);
        }

        if (pid == 0) { //child
            std::cout << "Jestem dzieckiem, mój PID to: " << getpid() << ", PID mojego rodzica to: " << getppid() << std::endl;
            exit(1);
        }
    }
    for (int i = 0; i < 5; ++i) { wait(NULL);}

    std::cout << "Jestem procesem głownym, mój PID to: " << getpid() << ", PID mojego rodzica to: " << getppid() << std::endl;
}

void zadanie3a(){
    std::cout << "Jestem procesem głownym, mój PID to: " << getpid() << ", PID mojego rodzica to: " << getppid() << std::endl;
        pid_t pid = fork();

        if (pid == -1) {
            std::cerr << "Błąd podczas tworzenia procesu potomnego." << std::endl;
            exit(1);
        }
        if (pid == 0) {
            std::cout << "Proces potomny (PID: " << getpid() << ") działa w pętli nieskończonej." << std::endl;
            while (true) {
            }
        }
        else {
            std::cout << "Proces główny (PID: " << getpid() << ") kończy działanie." << std::endl;
        }
}

void zadanie3b(){
    std::cout << "Jestem procesem głownym, mój PID to: " << getpid() << ", PID mojego rodzica to: " << getppid() << std::endl;
    pid_t pid = fork();

    if (pid == -1) {
        std::cerr << "Błąd podczas tworzenia procesu potomnego." << std::endl;
        exit(1);
    }
    if (pid == 0) {
        std::cout << "Proces potomny (PID: " << getpid() << ") kończy działanie" << std::endl;
    }
    else {
        std::cout << "Proces główny (PID: " << getpid() << ") działa w pętli nieskończonej." << std::endl;
        while (true) {
        }
    }
}

void zadanie4() {
    pid_t pid = fork();

    if (pid == -1) {
        std::cerr << "Błąd podczas tworzenia procesu potomnego." << std::endl;
        exit(1);
    }

    if (pid == 0) {
        std::cout << "Jestem dzieckiem, mój PID to: " << getpid() << ", PID mojego rodzica to: " << getppid() << std::endl;
        // Proces potomny kończy działanie z kodem wyjścia 42
        exit(42);
    } else {
        // Proces główny czeka na zakończenie procesu potomnego
        int status;
        pid_t child_pid = wait(&status);

        if (child_pid == -1) {
            std::cerr << "Błąd podczas oczekiwania na zakończenie procesu potomnego." << std::endl;
            exit(1);
        }

        if (WIFEXITED(status)) {
            int exit_status = WEXITSTATUS(status);
            std::cout << "Proces główny: proces potomny (PID: " << child_pid << ") zakończył się z kodem wyjścia: " << exit_status << std::endl;
        } else {
            std::cerr << "Proces główny: proces potomny (PID: " << child_pid << ") zakończył się w sposób nienormalny." << std::endl;
        }
    }
}

int main() {

    //zadanie1();
    //zadanie2();
    //zadanie3a();
    //zadanie3b();
    zadanie4();
    return 0;
}
