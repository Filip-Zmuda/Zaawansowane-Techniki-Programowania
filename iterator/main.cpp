#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

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

template<typename T>
void show_list(const std::string& name, const std::list<T>& lst) {
    std::cout << name << ": ";
    for (const auto& elem : lst) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

bool czy_parzysta(int value){
    return value%2==0;
}
int main() {
    std::vector<int> vec1 (10);
    //std::vector<int>::iterator it;

    for(int i=0; i<10; ++i){
        vec1[i]=i;
    }

    auto it=vec1.begin();

    show("vec1",vec1);
    std::cout << "vec1.begin() = " << *it << std::endl;
    std::cout << std::endl;

    for(auto iter=vec1.begin(); iter!=vec1.end(); ++iter){
        std::cout << *iter << " ";
    }
    std::cout << std::endl << std::endl;

    //przetestowac dla list,set,map

    std::list <int> lista = {10,9,8,7,6,5,4,3,2,1};

    show_list("lista",lista);

    for(auto iter=lista.begin(); iter!=lista.end(); ++iter){
        std::cout << *iter << " ";
    }
    std::cout<< std::endl << std::endl;



    std::vector<int> vec2 = {1,2,1,4,1,7,1,1};
    show("vec2",vec2);

    int cnt = std::count(vec2.begin(),vec2.end(),1);
    std::cout << "ilosc jedynek w vec2 = " << cnt <<std::endl << std::endl;

    int cnt_p=count_if(begin(vec2), end(vec2), czy_parzysta);
    std::cout << "ilosc liczb parzystych w vec2 = " << cnt_p << std::endl << std::endl;

}

