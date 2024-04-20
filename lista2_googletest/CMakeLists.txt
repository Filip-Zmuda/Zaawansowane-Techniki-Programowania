#minimalna wersja cmake
cmake_minimum_required(VERSION 3.26)
#nazwa projektu
project(lista2_googletest)
#standard języka c++
set(CMAKE_CXX_STANDARD 17)
#określenie celu (plik wykonywalny) o nazwie lista2_googletest do którego utworzenia skompilowane zostaną pliki main.cpp i tokenize.cpp
add_executable(lista2_googletest main.cpp tokenize.cpp)
# umożliwia pobieranie i dołączanie zewnętrznych projektów lub bibliotek podczas procesu kompilacji.
include(FetchContent)
#deklaruje pobranie GoogleTest z GitHuba
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
#Ustawia flagę zapobiegającą konfliktom z bibliotekami współdzielonymi
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#pobiera bibliotekę GoogleTest i udostępnia ją w projekcie
FetchContent_MakeAvailable(googletest)
#Dodaje do ścieżki include katalog z plikami nagłówkowymi GoogleTest
include_directories(${googletest_SOURCE_DIR}/googletest/include)
#Linkuje cel lista2_googletest z biblioteką gtest_main
target_link_libraries(lista2_googletest gtest_main)