#include <iostream>
#include "CoolingSystem.h"
#include "CoolingSystemMock.h"
#include "NuclearReactor.h"
#include "FusionReactor.h"
#include "AntimatterReactor.h"


int main() {

    CoolingSystem systemchlodzacy;
    CoolingSystemMock testowysystemchlodzacy;

    AntimatterReactor<CoolingSystem> ar1; // prawdziwy reaktor
    AntimatterReactor<CoolingSystemMock> ar2; // reaktor testujący, który zamiast CoolingSystem użyje CoolingSystemMock
    //FusionReactor fr1(systemchlodzacy);
    FusionReactor fr2(testowysystemchlodzacy);
    NuclearReactor nr1;

    //ar1.foo();
    //ar2.foo();
    //fr1.foo();
    fr2.foo();
    //nr1.foo();
    return 0;
}
