#include "Case.h"

int Case::getValue() const {
    return value;
}

void Case::setValue(int newValue) {
    value = newValue;
}

bool Case::isEmpty() const {
    return (value == 0);
}
