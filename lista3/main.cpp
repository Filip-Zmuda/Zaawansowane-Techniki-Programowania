#include <iostream>
#include <string>

class Osoba {
public:
    std::string imie;
    Osoba(const std::string& imie) : imie(imie) {}

    void niewirtualnaInfo() {
        std::cout << imie << std::endl;
    }

    virtual void wirtualnaInfo() {
        std::cout << imie << std::endl;
    }
};

void wywolajNiewirtualna(Osoba *p) {
    p->niewirtualnaInfo();
}

void wywolajWirtualna(Osoba *p) {
    p->wirtualnaInfo();
}

int main() {
    Osoba o("Jan");
    wywolajNiewirtualna(&o);
    wywolajWirtualna(&o);
    return 0;
}
