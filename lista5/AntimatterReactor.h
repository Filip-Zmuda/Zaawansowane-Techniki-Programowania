//
// Created by c on 4/25/24.
//
#include <iostream>
#ifndef LISTA5_ANTIMATTERREACTOR_H
#define LISTA5_ANTIMATTERREACTOR_H


template<typename T>
class AntimatterReactor: public T{
public:
    bool foo(){
        T::shutdown();
        std::cout << "Brawo, nie wysadziłeś połowy kraju" << std::endl;
        return true;
    }
};


#endif //LISTA5_ANTIMATTERREACTOR_H
