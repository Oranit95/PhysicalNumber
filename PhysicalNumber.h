#include <iostream>
#include "Unit.h"
using namespace std;
namespace ariel{


class PhysicalNumber{
 private:
 ariel::Unit u;
 double value;
 
 public:
 PhysicalNumber(double number, Unit u) ;
 PhysicalNumber operator+(const PhysicalNumber &a) const ;
 PhysicalNumber operator+=(const PhysicalNumber &a) ;
 PhysicalNumber operator++() ;
 PhysicalNumber operator++(int a) ;
 PhysicalNumber operator+() const;
 PhysicalNumber operator-(const PhysicalNumber &a) const;
 PhysicalNumber operator-() ;
 PhysicalNumber operator-=(const PhysicalNumber &a) ;
 PhysicalNumber operator--() ;
 PhysicalNumber operator--(int a) ;
 bool operator<(const PhysicalNumber &a);
 bool operator>(const PhysicalNumber &a);
 bool operator<=(const PhysicalNumber &a);
 bool operator>=(const PhysicalNumber &a);
 bool operator!=(const PhysicalNumber &a);
 bool operator==(const PhysicalNumber &a);
 friend ostream& operator<< (ostream& os, const PhysicalNumber& p);
 friend istream& operator>> (istream& is, PhysicalNumber& p);
 double change(const PhysicalNumber &a, const PhysicalNumber &b) const;
 PhysicalNumber(const PhysicalNumber &a);




};
}

