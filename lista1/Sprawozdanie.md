## Zaawansowane techniki programowania              - lista 1, Filip Żmuda 263631

**1.** Zaimplementowano kod w katalogach `prog1 (main.cpp)` i `prog2 (main2.cpp)` wypisujący na ekranie "Hello World!":
main.cpp:
```
    #include<iostream>
    #include"hello.h"
    int main(){
    hello_world();
    std::cout<<"Jestem programem pierwszym"<<std::endl;
    }
  ```  
 main2.cpp:
```
    #include<iostream>
    #include"hello.h"
    int main(){
    hello_world();
    std::cout<<"Jestem programem drugim"<<std::endl;
    }
```
Oba programy korzystają z biblioteki "hello" umieszczonej w katalogu `lib/hello`:
hello.cpp:

    #include <iostream>
    void hello_world(){
    std::cout<<"hello world!"<<std::endl;
    }
hello.h:
```
    void hello_world();
```

**2.** Aby zbudować kod, wykorzystano polecenia umieszczone w pliku `build.sh`, wykonującym je automatycznie po wpisaniu polecenia `./build.sh`
```
    #!/usr/bin/bash
    CXXFLAGS="-Ilib/hello"
    g++ ${CXXFLAGS} -c ./src/prog1/main.cpp -o ./build/main.o
    g++ ${CXXFLAGS} -c ./src/prog2/main2.cpp -o ./build/main2.o
    g++ ${CXXFLAGS} -c ./lib/hello/hello.cpp -o ./build/hello.o
    g++ ./build/main.o ./build/hello.o -o ./build/p1
    g++ ./build/main2.o ./build/hello.o -o ./build/p2
```
 W pierwszej linii wskazano środowisko w którym powinien zostać zbudowany kod, w tym wypadku jest to lokalizacja basha. 
 W drugiej linii zdefiniowano zmienną `CXXFLAGS`, która przechowuje opcje kompilatora, w tym przypadku flagę `-I`, wskazującą katalog, w którym należy szukać plików nagłówkowych zawartych w kodzie. 
 Następne trzy linie odpowiadają za kompilację plików `.cpp` do plików obiektowych i są zbudowane w ten sam sposób (na przykładzie trzeciej linii): 
 linia kompiluje plik `main.cpp` znajdujący się w katalogu `src/prog1`, używając kompilatora `g++`. Wcześniej zdefiniowane w `CXXFLAGS` flagi są dołączane do polecenia kompilacji. Opcja `-c` oznacza, że należy tylko skompilować plik do kodu obiektowego (bez łączenia), a opcja`-o` wraz ze ścieżką `./build/main.o` wskazuje, że plik wynikowy będzie umieszczony w katalogu build i będzie miał nazwę `main.o`. Ostatnie dwie linie łączą plik `hello.o` z plikami `main.o` i `main2.o` do plików wykonywalnych `p1` i `p2`.

**3.** Następnie stworzono plik `Makefile` pozwalający zbudować projekt po wpisaniu w terminalu polecenia `make`:
```
    CXXFLAGS=-Ilib/hello/
    
    all: P1 P2
    
    P1: build/main1.o lib/hello/hello.o
	    g++ $^ -o ./build/P1
	    
    P2: build/main2.o lib/hello/hello.o
	    g++ $^ -o ./build/P2
	    
    build/main1.o: src/prog1/main.cpp lib/hello/hello.h
	    g++ ${CXXFLAGS} -c $< -o ./build/main1.o
	    
    build/main2.o: src/prog2/main2.cpp lib/hello/hello.h
	    g++ ${CXXFLAGS} -c $< -o ./build/main2.o
	    
    lib/hello/hello.o: lib/hello/hello.cpp lib/hello/hello.h
	    g++ ${CXXFLAGS} -c $< -o $@
```
 Podobnie jak w pliku `build.sh` zmienna `CXXFLAGS`ustawiona jest na `-I` i wskazuje na lokalizację pliku nagłówkowego w `lib/hello`.
```
    all: P1 P2
```
To określenie celu domyślnego. Gdy nie podamy celu wywołując polecenie `make`, `Makefile` domyślnie wykona cele dla `P1` i `P2` (Chodzi o to, żeby nie budować i kompilować całego projektu, jeśli nie ma takiej potrzeby, dlatego domyślne cele w `Makefile` ustawiono dla plików wykonywalnych, a nie źródłowych).

Wszystkie późniejsze polecenia zapisane są w formie:
```
    Cel: zależności(wymagania)
	    polecenie
```
`Makefile` po wywołaniu polecenia `make` sprawdza, czy któraś z zależności nie była modyfikowana po ostatnim zbudowaniu celu i czy wszystkie zależności są dostępne. Jeśli nie są, lub były modyfikowane po ostatnim zbudowaniu celu, to `Makefile` wykona podane polecenie, aby zaktualizować cel.
```
    P1: build/main1.o lib/hello/hello.o
        g++ $^ -o ./build/P1
```
Ten zapis informuje, że celem jest plik wykonywalny `P1`. Jeśli zmianie ulegną pliki `main1.o`, lub `hello.o`,  to kompilator `g++` połączy wszystkie pliki wymienione po dwukropku (o czym informuje nas zapis `$^`) w plik wykonywalny o nazwie `P1` i umieści go w katalogu `build` (o czym informuje nas flaga `-o`). Analogiczny zapis występuje dla pliku `P2`.

Cele dla plików obiektowych  są zdefiniowane w taki sam sposób. Jednak są one kompilowane z plików `.cpp`, zatem należy napisać dla nich inne polecenia:
```
    build/main1.o: src/prog1/main.cpp lib/hello/hello.h
		g++ ${CXXFLAGS} -c $< -o ./build/main1.o
```
Zapis w drugiej linii oznacza, że należy za  pomocą kompilatora `g++` z flagą określoną w `CXXFLAGS`, oraz `-c` (tylko kompilacja) skompilować plik `main.cpp`. Mówi nam o tym zapis `$<`, który oznacza zawsze pierwszą z podanych zależności. Ma on zostać skompilowany do pliku obiektowego o nazwie `main1.o` i umieszczony w katalogu `build`, o czym informuje nas flaga `-o`. 

W ostatniej linii pliku Makefile występuje zapis `$@` oznaczający, że odnosimy się do aktualnie opisywanego celu. Zatem:
```
    lib/hello/hello.o: lib/hello/hello.cpp lib/hello/hello.h
	    g++ ${CXXFLAGS} -c $< -o $@
```
oznacza, że definiujemy cel dla pliku obiektowego `hello.o`. Jeśli zmianie ulegną pliki biblioteki `hello` (`hello.cpp`, lub `hello.h`), to nastąpi kompilacja pliku `hello.cpp` do pliku obiektowego o nazwie `hello.o` (czyli dokładnie tego, który został podany jako cel - zapis `$@`).

**4.** Jako ostatni utworzono plik `Cmakelists.txt`, czyli plik konfiguracji procesu budowy projektu przy użyciu narzędzia CMake:
```
	cmake_minimum_required(VERSION 3.27)
	project(lista1)
    
    set(CMAKE_CXX_STANDARD 11)
    
    include_directories(lib/hello)
    add_library(hello lib/hello/hello.cpp)
    
    add_executable(P1 /home/filip/ztp
    filip_zmuda/lista1/src/prog1)
    add_executable(P2 /home/filip/ztp
    filip_zmuda/lista1/src/prog2)
    
    target_link_libraries(P1 PRIVATE hello)
    target_link_libraries(P2 PRIVATE hello)
    
    find_package(Threads REQUIRED)
    target_compile_options(P1 PRIVATE -pthread)
    target_link_libraries(P1 PRIVATE Threads::Threads)
    
    include(FetchContent)
    FetchContent_Declare(
	    json
	    URL https://github.com/nlohmann/json/archive/v3.7.1.tar.gz
    )
    FetchContent_MakeAvailable(json)
    
    target_link_libraries(P2 PRIVATE nlohmann_json::nlohmann_json)
```
Na początku pliku określona jest minimalna wymagana wersja narzędzia CMake, nazwa projektu i standard języka C++, zgodnie z którym kompilowany będzie projekt. Następnie do ścieżki, w której kompilator będzie szukał plików nagłówkowych dodawany jest katalog `lib/hello`. 
Zgodnie z wymaganiami projektu, biblioteka hello jest budowana dyrektywą `add_library`. Następnie, zgodnie z wymaganiami, dyrektywy `add_executable`wskazują, że pliki wykonywalne o nazwach `P1` i `P2` będą zbudowane z plików znajdujących się w podanych ścieżkach (są to pliki `main.cpp` i `main2.cpp`). Ostatnim wymaganiem jest zlinkowanie biblioteki `hello` ze wspomnianymi programami, jest to wykonywane za pomocą dyrektywy `target_link_libraries`. Oznacza to, że funkcje zdefiniowane w bibliotece `hello` będą dostępne dla programów `P1` i `P2`.

**5.** Ponieważ w przyszłości w programie `prog1` będzie wymagane użycie wątków, do pliku konfiguracyjnego dodany został fragment odpowiedzialny za znalezienie pakietu `Threads` (Jest on ustawiony jak REQUIRED, zatem jest niezbędny do poprawnego zbudowania projektu, a jeśli nie zostanie znaleziony, proces konfiguracji zostanie przerwany z błędem), dodaniu opcji kompilatora informującej go, że plik wykonywalny `P1` będzie potrzebował obsługi wątków, oraz zlinkowanie z tym programem biblioteki Threads.

**6.** Program `prog2` będzie korzystać z niestandardowej biblioteki, zatem ostatnim elementem pliku konfiguracyjnego jest włączenie (`include`) modułu `FetchContent` pozwalającego na pobieranie potrzebnych zasobów w trakcie konfiguracji projektu. Następnie deklarowana jest nazwa i źródło biblioteki (`FetchContent_Declare`) i jest ona udostępniana dla dalszych operacji konfiguracyjnych (`FetchContent_MakeAvailable()`). W ostatnim kroku pobrana biblioteka jest linkowana dyrektywą `target_link_libraries` z plikiem wykonywalnym `P2`

