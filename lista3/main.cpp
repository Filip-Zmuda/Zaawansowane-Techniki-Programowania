#include <iostream>
#include <string>

class Osoba{
public:
    std::string imie;
	Osoba(const std::string& imie) : imie(imie) {}

	virtual void info(){
		std::cout << imie << std::endl;
	}
};

//class Student : public Osoba{
//    int indeks;
//public:
//	Student(const std::string& imie, int indeks) : Osoba(imie), indeks(indeks) {}
//
//	int indeks;
//	void info override(){
//		std::cout << imie << std::endl;
//		std::cout << indeks << std::endl;
//	}
//};

void foo (Osoba *p){
p->info();
}

int main(){
//srand(time(NULL));
Osoba o ("Jan");
//Student s ("Adam",12345);

//o.info();

//Osoba *op;
//Student *sp;

//if(rand()%2)
//	op = &o;
//else
//	op = &s;
//
foo(&o);
}