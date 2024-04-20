#minimalna wymagana wersja cmake
cmake_minimum_required(VERSION 3.26)
#nazwa projektu
project(lista_2)
#standard jezyka c++
set(CMAKE_CXX_STANDARD 17)
#określenie celu (plik wykonywalny) o nazwie lista_2 do którego utworzenia skompilowane zostaną pliki main.cpp i tokenize.cpp
add_executable(lista_2 main.cpp tokenize.cpp)
# umożliwia pobieranie i dołączanie zewnętrznych projektów lub bibliotek podczas procesu kompilacji.
Include(FetchContent)
#deklaruje pobranie Catch2 z GitHuba
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.4.0 # or a later release
)
#pobiera bibliotekę Catch2 i udostępnia ją w projekcie
FetchContent_MakeAvailable(Catch2)
# Linkowanie z biblioteką Catch2
target_link_libraries(lista_2 Catch2::Catch2WithMain)