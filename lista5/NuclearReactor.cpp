//
// Created by c on 4/25/24.
//

#include "NuclearReactor.h"

bool NuclearReactor::foo() {
    shutdown();
    std::cout << "Brawo, nie wysadziłeś pół kraju" << std::endl;
    return true;
}
