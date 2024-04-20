#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cassert>
#include <catch2/catch_session.hpp>
#include <catch2/catch_test_macros.hpp>
#include "tokenize.h"


TEST_CASE( "Działanie Tokenizera", "[tokenizer]" ) {                    //nazwa testu, [tagi]

    REQUIRE(tokenize("Ala ma kota").size()==3);         //bazowe testy, sprawdzające, czy biblioteka
    REQUIRE(tokenize("Robert Downey Jr.").size()==3);   //działa poprawnie w najprostszym przypadku

    SECTION( "wielokrotne spacje  między słowami" ) {                   //sekcja zawierająca podobne do siebie wywołania
        REQUIRE(tokenize("Ala  ma kota").size()==3);    //funkcji o nietypowych parametrach
        REQUIRE(tokenize("Ala ma    kota").size()==3);
    }
    SECTION( "spacje na końcu" ) {
        REQUIRE(tokenize("Ala ma kota    ").size()==3);
        REQUIRE(tokenize("Ala    ").size()==1);
    }
    SECTION( "spacje na początku" ) {

        REQUIRE(tokenize("   Ala ma kota").size()==3);
    }
    SECTION( "wielokrotne spacje w różnych miejscach" ) {
        REQUIRE(tokenize("Robert Downey    Jr.   ").size()==3);
        REQUIRE(tokenize("    Ala   ma kota     ").size()==3);
        REQUIRE(tokenize("    To jest  test   biblioteki    catch2   ").size()==5);
    }
}



int main() {
    // assert(tokenize("Ala ").size()==1);
    // assert(tokenize("Ala ma kota").size()==3);
    // assert(tokenize("Robert Downey Jr.").size()==3);
    // assert(tokenize("Ala  ma kota").size()==3);
    // assert(tokenize("Ala ma    kota").size()==3);
    // assert(tokenize("Ala    ").size()==1);
    // assert(tokenize("Ala ma kota    ").size()==3);
    // assert(tokenize("Robert Downey    Jr.   ").size()==3);
    // assert(tokenize("   Ala ma kota").size()==3);
    // assert(tokenize("    Ala   ma kota     ").size()==3);

    Catch::Session().run();
}
