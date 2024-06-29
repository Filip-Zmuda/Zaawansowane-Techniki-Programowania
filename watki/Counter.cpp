//
// Created by filip on 6/29/24.
//
#include "Counter.h"

Counter::Counter() : value(0) {}

int Counter::get_value() const {
    return value;
}

void Counter::increase() {
    ++value;
}

