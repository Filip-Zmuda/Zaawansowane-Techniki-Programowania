# Lista 2 ZTP Filip Żmuda 263631

# Catch2
Framework Catch2 zaimportowano do projektu w pliku CMakeLists.txt:
```
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
```

Utworzono bibliotekę "tokenize" zawierającą funkcję tokenizera i jej plik nagłówkowy dołączono do projektu. Testy podzielono na sekcje i napisano jak poniżej:
```
TEST_CASE( "Działanie Tokenizera", "[tokenizer]" ) {  //nazwa testu, [tagi]  
  
 REQUIRE(tokenize("Ala ma kota").size()==3);         //bazowe testy, sprawdzające, czy biblioteka   
 REQUIRE(tokenize("Robert Downey Jr.").size()==3);   //działa poprawnie w najprostszym przypadku  
  
  SECTION( "wielokrotne spacje  między słowami" ) {                   //sekcja zawierająca podobne do siebie wywołania  
	  REQUIRE(tokenize("Ala  ma kota").size()==3);    //funkcji o nietypowych parametrach  
	  REQUIRE(tokenize("Ala ma    kota").size()==3);  
    }  
  SECTION( "spacje na końcu" ) {  
	...
    }  
...
}

int main() {
  Catch::Session().run();  
}
```

Testy napisano zaczynając od sprawdzenia obsługi najprostszych przypadków i w miarę testowania zwiększano poziom skomplikowania parametru wywołania funkcji. W ten sposób dodając każdy kolejny test i wywołując wszystkie napisane uprzednio, mamy pewność, że program wciąż obsługuje prostsze przypadki, sprawdzane wcześniej.

# GoogleTest
Framework GoogleTest również zaimportowano przy użyciu pliku CMakeLists.txt:
```
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
```
Następnie napisano testy jednostkowe jak poniżej:
```
TEST(TokenizeTest, HandlesSpacesAfter) {    //grupa, nazwa testu  
  EXPECT_EQ(tokenize("Ala ma kota").size() , 3);  //test jednostkowy  
  EXPECT_EQ(tokenize("Ala    ").size(), 1);  
}  
  
TEST(TokenizeTest, HandlesSpacesInBetween) {  
    EXPECT_EQ(tokenize("Ala  ma kota").size() , 3);  
    EXPECT_EQ(tokenize("Robert Downey    Jr.   ").size() , 3);  
}

int main(int argc, char **argv) {  
    testing::InitGoogleTest(&argc, argv);  
    return RUN_ALL_TESTS();  
}
```
Umieszczanie testów w grupach pozwala utrzymać dobrą organizację kodu przy testowaniu wielu funkcji dużych projektów.

