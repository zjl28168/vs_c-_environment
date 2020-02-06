// class_stone.hpp -- definition for the stone class
#ifndef CLASS_STONE_HPP
#define CLASS_STONE_HPP
class stonewt
{
private:
    enum { lbs_per_stn = 14 };      // pounds per stone
    int stone;
    double pds_left;
    double pounds;
public:
    stonewt( double lbs );
    stonewt( int stn, double lbs );
    stonwt();
    ~stonewt();
    void show_lbs() const;
    void show_stn() const;
    //conversion functons
    explicit operator int() const;    //explicit call this function
    explicit operator double() const;
};
#endif