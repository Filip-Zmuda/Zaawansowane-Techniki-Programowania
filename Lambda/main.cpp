#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <numeric>

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

class enemy {
public:
    std::vector<int> position;
    int size;
    int HP;

    enemy() : position(0,0), size(5), HP(100) {}
};

int main() {
    std::vector <int> vec1 = {5,4,3,2,1};
    std::vector <int> vec2 = {10,9,8,7,6};
    std::sort(vec1.begin(), vec1.end());
    show("vec1",vec1);


    //podnoszenie wszystkich elementów wektora do kwadratu
    std::transform(vec1.begin(), vec1.end(), vec1.begin(), [] (int v){return v*v;});
    show("vec1",vec1);

    //dodawanie elementów dwóch wektorów
    std::transform(vec1.begin(), vec1.end(), vec2.begin(), vec2.begin(), [](int a, int b) { return a + b; });
    show("vec2", vec2);


//    std::vector <int> vec3(5);
//    srand(time(NULL));
//    std::generate(vec3.begin(),vec3.end(),rand());
//    show("vec3", vec3);

    std::vector<int> vec3(5); // Resize vec3 to have 5 elements
    srand((time(NULL)));
    std::generate(vec3.begin(), vec3.end(), rand);
    show("vec3", vec3);

    std::vector <int> vec4;
    std::copy(vec3.begin(),vec3.end(),std::back_inserter(vec4));
    show("vec4", vec4);

    std::copy(vec4.begin(), vec4.end(), std::ostream_iterator<int>(std::cout," "));
    std::cout<<std::endl<<std::endl;

    std::vector <int> vec5 = {1,2,3};

    int s = std::accumulate(vec5.begin(), vec5.end(), 0);
    std::cout << s <<std::endl;

    double p = std::accumulate(vec5.begin(),vec5.end(),2,[](int a, int b){std::cout<<a<<" "<< b<<std::endl; return a*b;});
    std::cout<<p<<std::endl;



    return 0;
}
