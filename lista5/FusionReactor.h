//
// Created by c on 4/25/24.
//
#include "CoolingSystem.h"
#include "CoolingSystemMock.h"
#include <iostream>
#ifndef LISTA5_FUSIONREACTOR_H
#define LISTA5_FUSIONREACTOR_H


class FusionReactor{
    CoolingSystemMock & cooling;
public:
    //FusionReactor(CoolingSystem& coolingSystem) : cooling(coolingSystem) {}
    FusionReactor(CoolingSystemMock& coolingSystemMock) : cooling(coolingSystemMock) {}
    bool foo();
};


#endif //LISTA5_FUSIONREACTOR_H
