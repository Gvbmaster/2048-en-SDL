#include "Grid.h"
#include "Case.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

Case::Case() : value(0) {
}

int Case::getValue() const {
    return value;
}

void Case::setValue(int newValue) {
    value = newValue;
}

bool Case::isEmpty() const {
    return (value == 0);
}
