#include <iostream>

class DataSource{
public:
    virtual void getData()=0;
};

class HUSB{
public:
    int getone(){
        return 1;
    }
    void readData(){
        std::cout << "readData" << std::endl;
    }
};


class Dziedziczenie1 : public HUSB, public DataSource{
public:
    virtual void getData() override {
        std::cout<<"nadpisana przez klasę Dziedziczenie1"<<std::endl;
    }
};

class Dziedziczenie2 : public HUSB, public DataSource{
public:
    virtual void getData() override {
        std::cout<<"nadpisana przez klasę Dziedziczenie2"<<std::endl;
    }
};

class Korzystanie : public DataSource{
public:
    virtual void getData() override{
        std::cout<<"nadpisana przez klasę Korzystanie"<<std::endl;
    }
};

void foo(DataSource &ds){
    ds.getData();
}

void bar(HUSB &h){
    h.readData();
}


int main() {

    Dziedziczenie1 obiekt;
    obiekt.getData();           //obiekt klasy dziedziczacej po interfejsie DataSource, korzysta z nadpisanej funkcji getData()

    Dziedziczenie2 obiekt2;
    obiekt2.getData();

    HUSB obiekt3;
    Korzystanie obiekt4;
    
    int wynik = obiekt.getone();
    std::cout << "wynik1 = " << wynik << std::endl;
    int wynik2 = obiekt2.getone();
    std::cout << "wynik2 = " << wynik2 << std::endl;
    int wynik3 = obiekt3.getone();
    std::cout << "wynik3 = " << wynik3 << std::endl;

    foo(obiekt);
    foo(obiekt2);
    obiekt3.readData();
    obiekt.readData();      //obiekt klasy dziedziczacej po interfejsie DataSource i klasie HUSB, korzysta z funkcji readData() zawartej w klasie HUSB
    bar(obiekt);        //obiekt klasy dziedziczacej po interfejsie DataSource i klasie HUSB, korzysta z funkcji readData() zawartej w klasie HUSB
    //bar(obiekt4);         //blad, konflikt typow
    //foo(obiekt3);         //blad, konflikt typow


    return 0;
}
