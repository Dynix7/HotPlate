#include "helper.hpp"


double toSec(unsigned long millis) {
    return (double) millis * 1e-3;
}

double getTime() {
    return toSec(millis());
}