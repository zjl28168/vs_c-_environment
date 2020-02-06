// class_stone.cpp -- stone class methods
#include <iostream>
#include "class_stone.hpp"
using std::cout;

stonewt::stonewt( double lbs )
{
    stone = int(lbs) / lbs_per_stn;
    pds_left = int(lbs) % lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

stonewt::stonewt( int stn, double lbs )
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * lbs_per_stn + lbs;
}

stonewt::stonwt()
{
    stone = pds_left = pounds = 0;
}

stonewt::~stonewt()
{
}

void stonewt::show_lbs() const
{
    cout << pounds << " pounds.\n";
}

void stonewt::show_stn() const
{
    cout << stone << " stone " << pds_left << " pounds.\n";
}
//conversion functons
stonewt::operator int() const
{
    return int( pounds + 0.5 );
}
stonewt::operator double() const
{
    return pounds;
}
