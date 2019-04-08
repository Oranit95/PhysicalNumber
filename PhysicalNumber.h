#include <iostream>
#include "Unit.h"
using namespace std;
namespace ariel{


class PhysicalNumber{
 private:
 ariel::Unit u;
 double number;
 
 public:
 PhysicalNumber(double number, Unit u) ;
 PhysicalNumber operator+(const PhysicalNumber &a) const;
 PhysicalNumber operator+=(const PhysicalNumber &a) const;
 PhysicalNumber operator++() const;
 PhysicalNumber operator++(int a) const;
 PhysicalNumber operator+() const;
 PhysicalNumber operator-(const PhysicalNumber &a) const;
 PhysicalNumber operator-() const;
 PhysicalNumber operator-=(const PhysicalNumber &a) const;
 PhysicalNumber operator--() const;
 PhysicalNumber operator--(int a) const;
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
