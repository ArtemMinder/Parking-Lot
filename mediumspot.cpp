#include "mediumspot.h"

MediumSpot::MediumSpot()
{

}

MediumSpot::MediumSpot(int const& newNumber)
{
    number = newNumber;
}

int MediumSpot::getNumer() const{
    return number;
}
