#include <iostream>
#include <sstream>
#include <stdexcept>
#include "PhysicalNumber.h"
#include "Unit.h"
using namespace std;
 namespace ariel{

ariel::Unit u;
double number;

 PhysicalNumber::PhysicalNumber(double number, Unit u){
	this->u=u;
	this->number=number;
 }

 PhysicalNumber PhysicalNumber::operator+ (const PhysicalNumber &a) const {return *this;}
 PhysicalNumber PhysicalNumber::operator+= (const PhysicalNumber &a) const{return *this;}
 PhysicalNumber PhysicalNumber::operator++ () const{return *this;}
 PhysicalNumber PhysicalNumber::operator+ () const{return *this;}
 PhysicalNumber PhysicalNumber::operator- (const PhysicalNumber &a) const{return *this;}
 PhysicalNumber PhysicalNumber::operator-= (const PhysicalNumber &a) const{return *this;}
 PhysicalNumber PhysicalNumber::operator-- () const{return *this;}
 PhysicalNumber PhysicalNumber::operator- () const{return *this;}
 bool PhysicalNumber::operator<(const PhysicalNumber &a){return true;}
 bool PhysicalNumber::operator>(const PhysicalNumber &a){return true;}
 bool PhysicalNumber::operator<=(const PhysicalNumber &a){return true;}
 bool PhysicalNumber::operator>=(const PhysicalNumber &a){return true;}
 bool PhysicalNumber::operator!=(const PhysicalNumber &a){return true;}
 bool PhysicalNumber::operator==(const PhysicalNumber &a){return true;}
   ostream& operator<<(ostream& os, const PhysicalNumber& p){
	cout<<p.number;
	return os;
  }
   istream& operator>>(istream& is, PhysicalNumber& p){
	cin>>p.number;
	return is;
  }
};



