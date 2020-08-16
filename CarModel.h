#ifndef CARMODEL_H
#define CARMODEL_H

#include <string>
#include <vector>

struct CarModel{
    std::vector<int> place = {};
    std::vector<std::string> license = {};
    std::vector<std::string> type = {};
    std::vector<std::string> startTime = {};
    std::vector<std::string> parkingTime = {};
    std::vector<long long> amount = {};
};

#endif // CARMODEL_H
