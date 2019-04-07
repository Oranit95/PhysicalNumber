#include <iostream>
#include "Unit.h"
using namespace std;
namespace ariel{


class PhysicalNumber{
 public:
ariel::Unit u;
double number;

 PhysicalNumber(double number, Unit u) ;
 PhysicalNumber operator+(const PhysicalNumber &a) const;
 PhysicalNumber operator+=(const PhysicalNumber &a) const;
 PhysicalNumber operator++() const;
 PhysicalNumber operator+() const;
 PhysicalNumber operator-(const PhysicalNumber &a) const;
 PhysicalNumber operator-() const;
 PhysicalNumber operator-=(const PhysicalNumber &a) const;
 PhysicalNumber operator--() const;
 bool operator<(const PhysicalNumber &a);
 bool operator>(const PhysicalNumber &a);
 bool operator<=(const PhysicalNumber &a);
 bool operator>=(const PhysicalNumber &a);
 bool operator!=(const PhysicalNumber &a);
 bool operator==(const PhysicalNumber &a);
 friend ostream& operator<< (ostream& os, const PhysicalNumber& p);
 friend istream& operator>> (istream& is, PhysicalNumber& p);



};
}

