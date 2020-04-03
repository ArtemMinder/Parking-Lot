#include "largespot.h"

LargeSpot::LargeSpot()
{

}

LargeSpot::LargeSpot(int const& newNumber)
{
    number = newNumber;
}

int LargeSpot::getNumer() const{
    return number;
}
