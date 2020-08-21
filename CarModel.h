#ifndef CARMODEL_H
#define CARMODEL_H

#include <string>

struct CarModel{
    int place = {};
    std::string license = {};
    std::string type = {};
    std::string startTime = {};
    std::string parkingTime = {};
    long long amount = {};
};

#endif // CARMODEL_H
