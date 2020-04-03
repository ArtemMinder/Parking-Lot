#include "handicappedspot.h"

HandicappedSpot::HandicappedSpot()
{

}
HandicappedSpot::HandicappedSpot(int const& newNumber)
{
    number = newNumber;
}

int HandicappedSpot::getNumer() const{
    return number;
}
