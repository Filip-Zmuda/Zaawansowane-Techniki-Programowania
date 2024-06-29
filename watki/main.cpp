#include <iostream>
#include <thread>
#include <unistd.h>
#include <chrono>
#include "Counter.h"
#include <mutex>
#include <future>

std::mutex mtx; // Mutex do synchronizacji

void print_thread_info(const std::string & msg) {
    std::cout << msg << std::endl;
    std::cout << "PID: " << getpid() << ", PPID: " << getppid() << ", Thread ID: " << std::this_thread::get_id() << std::endl;
}



// Zwykła funkcja
void regularFunction() {
    print_thread_info("Zwykła funkcja:");
    std::cout << "Zwykła funkcja: Wątek działa" << std::endl << std::endl;
}

// Funktor
class Functor {
public:
    void operator()() {
        print_thread_info("Functor:");
        std::cout << "Functor: Wątek działa" << std::endl << std::endl;
    }
};

void zadanie1() {
    // Zwykła funkcja
    std::thread thread1(regularFunction);
    thread1.join();

    // Funktor
    Functor functor;
    std::thread thread2(functor);
    thread2.join();

    // Funkcja anonimowa (lambda)
    std::thread thread3([] {
        print_thread_info("Lambda:");
        std::cout << "Lambda: Wątek działa" << std::endl << std::endl;
    });
    thread3.join();
}

// Zwykła funkcja z parametrem
void regularFunctionWithParam(int x) {
    print_thread_info("Zwykła funkcja z parametrem:");
    std::cout << "Zwykła funkcja: Wątek działa, parametr: " << x << std::endl << std::endl;
}

// Funktor z parametrem
class FunctorWithParam {
public:
    void operator()(int x) {
        print_thread_info("Functor z parametrem:");
        std::cout << "Functor: Wątek działa, parametr: " << x << std::endl << std::endl;
    }
};

void zadanie2() {
    int param = 10;

    // Zwykła funkcja z parametrem
    std::thread thread1(regularFunctionWithParam, param);
    thread1.join();

    // Funktor z parametrem
    FunctorWithParam functorWithParam;
    std::thread thread2(functorWithParam, param);
    thread2.join();

    // Funkcja anonimowa (lambda) z parametrem
    std::thread thread3([](int x) {
        print_thread_info("Lambda z parametrem:");
        std::cout << "Lambda: Wątek działa, parametr: " << x << std::endl << std::endl;
    }, param);
    thread3.join();
}

// Funkcje dla zadania 3
void threadFunction1() {
    for (int i = 0; i < 10; ++i) {
        print_thread_info("jestem wątkiem 1");
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void threadFunction2() {
    for (int i = 0; i < 10; ++i) {
        print_thread_info("jestem wątkiem 2");
        std::this_thread::sleep_for(std::chrono::milliseconds(700));
    }
}

void zadanie3() {
    std::thread thread1(threadFunction1);
    std::thread thread2(threadFunction2);

    thread1.join();
    thread2.join();
}

//funkcja do zadania 4A i 4B
void threadFunction3(Counter & counter) {
    for (int i = 0; i < 1000000; ++i) {
        counter.increase();
    }
}

// Funkcja do zadania 4C (zabezpieczona  mutexem)
void threadFunction4(Counter & counter) {
    for (int i = 0; i < 1000000; ++i) {
        std::scoped_lock lock(mtx); // Scoped lock dla mutexu
        counter.increase();
    }
}

void zadanie5() {
    // Funkcja, która zwraca wynik za pomocą obietnicy
    auto calculateValue = []() -> int {
        // Tworzymy obietnicę i przyszłość
        std::promise<int> prom;
        std::future<int> fut = prom.get_future();

        // Uruchamiamy zadanie asynchronicznie
        std::thread th([&prom]() {
            // Symulacja obliczeń, tutaj zakładamy, że trwa to pewien czas
            std::this_thread::sleep_for(std::chrono::seconds(2));

            // Obliczenie wyniku
            int result = 42;

            // Ustawienie wartości w obietnicy
            prom.set_value(result);
        });

        // Pobieramy wynik z przyszłości
        int result = fut.get();

        // Po zakończeniu wątku oczekujemy wyniku
        th.join();

        return result;
    };

    // Wywołanie funkcji calculateValue i otrzymanie wyniku
    int result = calculateValue();

    // Wyświetlamy wynik
    std::cout << "Otrzymany wynik: " << result << std::endl;
}

int main() {
    print_thread_info("main:");
    std::cout << std::endl;
    //zadanie1();
    //zadanie2();
    //zadanie3();

    // // zadanie 4A
    // Counter counter;
    // std::thread thread1(threadFunction3, std::ref(counter));
    // thread1.join();
    // std::cout << "Wartość licznika po zakończeniu wątku: " << counter.get_value() << std::endl;


    // //zadanie 4B
    // // Uruchamiamy dwa wątki, które zwiększają licznik
    // Counter counter;
    // std::thread thread1(threadFunction3, std::ref(counter));
    // std::thread thread2(threadFunction3, std::ref(counter));
    //
    // thread1.join();
    // thread2.join();
    //
    // std::cout << "Wartość licznika po zakończeniu wątków: " << counter.get_value() << std::endl;
    // //Wartość licznika po zakończeniu wątków (dla N=100000): 200000
    // //Wartość licznika po zakończeniu wątków (dla N=1000000): 1622445

    // //zadanie 4C
    // Counter counter;
    //
    // // Uruchamiamy dwa wątki, które zwiększają licznik, synchronizując dostęp do niego
    // std::thread thread1(threadFunction4, std::ref(counter));
    // std::thread thread2(threadFunction4, std::ref(counter));
    //
    // thread1.join();
    // thread2.join();
    //
    // std::cout << "Wartość licznika po zakończeniu wątków: " << counter.get_value() << std::endl;

    zadanie5();
    return 0;
}
