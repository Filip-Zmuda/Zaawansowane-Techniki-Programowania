#include <iostream>
#include <vector>
#include <string>

template<typename T>
void show(const std::string& name, const std::vector<T>& vec) {
    std::cout << name << ": ";
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    std::cout << name << " size = " << vec.size() << std::endl;
    std::cout << name << " capacity = " << vec.capacity() << std::endl;
    std::cout << std::endl;
}

int main() {
    std::vector <int> vec1;
    std::vector <int> vec2(10);
    std::vector <int> vec3(10,5);
    std::vector <int> vec4{1,2,3,4};

    show("vec1",vec1);

    show("vec2",vec2);

    show("vec3",vec3);

    show("vec4",vec4);

    vec2.push_back(4);
    std::cout<<"dodano element na końcu wektora vec2 funkcją push_back"<<std::endl;
    show("vec2",vec2);

    vec3.reserve(40);
    std::cout << "Zarezerwowano 40 wartości dla wektora vec3" << std::endl;
    show("vec3",vec3);

    vec2.shrink_to_fit();
    std::cout << "Przycięto pojemność wektora vec2 do jego rozmiaru" << std::endl;
    show("vec2",vec2);

    bool isempty=vec3.empty();
    std::cout << "Zastosowano funkcję empty na wektorze vec3 (wartosc 0 oznacza pusty, wartosc 1 - niepusty)" << std::endl;
    std::cout << "vec3.empty() = " << isempty << std::endl;
    std::cout<<std::endl;

    vec4.clear();
    std::cout << "Zastosowano funkcję clear na wektorze vec4" << std::endl;
    show("vec4",vec4);

    vec4.resize(15);
    std::cout << "Zastosowano funkcję resize(15) na wektorze vec4" << std::endl;
    show("vec4",vec4);

    vec4.resize(5,5);
    std::cout << "Zastosowano funkcję resize(5,5) na wektorze vec4" << std::endl;
    show("vec4",vec4);

    vec4.resize(10,5);
    std::cout << "Zastosowano funkcję resize(10,5) na wektorze vec4" << std::endl;
    show("vec4",vec4);

    vec4.emplace_back(6);
    std::cout << "dodano element na końcu wektora vec4 funkcją emplace_back" << std::endl;
    show("vec4",vec4);

    vec4.pop_back();
    std::cout << "usunięto element z końca wektora vec4 funkcją pop_back" << std::endl;
    show("vec4",vec4);

    std::cout << "vec4 front = " << vec4.front() << std::endl;
    std::cout << "vec4 back = " << vec4.back() << std::endl;
    std::cout << std::endl;



    return 0;
}
