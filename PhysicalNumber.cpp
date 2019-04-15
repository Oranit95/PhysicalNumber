#include <iostream>
#include <sstream>
#include <stdexcept>
#include "PhysicalNumber.h"
#include "Unit.h"
using namespace std;
 namespace ariel{

// the vairables of the class
ariel::Unit u;
double value;

// constructor
 PhysicalNumber::PhysicalNumber(double value, Unit u){
	this->u=u;
	this->value=value;
 }

//copy constructor
 PhysicalNumber::PhysicalNumber(const PhysicalNumber &a) {
	this->value=a.value;
	this->u=a.u;
 }

//addition of two numbers
 PhysicalNumber PhysicalNumber::operator+ (const PhysicalNumber &a) const {
	double sum = change(*this, a)+value;
	return PhysicalNumber(sum,u);
 }

//addition and assigning
 PhysicalNumber& PhysicalNumber::operator+= (const PhysicalNumber &a)  {
	this->value = change(*this, a) + value;;
	return *this;
 }

//prefix ++
 PhysicalNumber& PhysicalNumber::operator++ () {
	++value;
	return *this;
 }

//postfix ++
 PhysicalNumber PhysicalNumber::operator++(int) {
	PhysicalNumber pN(*this);
        value++;
	return pN;
 }

//return the physical number with no change : unary +
 PhysicalNumber PhysicalNumber::operator+ () const{
        return *this;
 }

//subtraction of two numbers
 PhysicalNumber PhysicalNumber::operator- (const PhysicalNumber &a) const{
	double diff = value-change(*this, a);
	return PhysicalNumber(diff,u);
 }

//subtraction and assigning
 PhysicalNumber& PhysicalNumber::operator-= (const PhysicalNumber &a) {
	this->value = value - change(*this, a);
	return *this;
  }

//prefix --
 PhysicalNumber& PhysicalNumber::operator-- () {
       value--;
	return *this;
 }

//postfix --
 PhysicalNumber PhysicalNumber::operator--(int) {
       PhysicalNumber pN(this->value,this->u);
        value--;
	return pN;
 }

//return the physical number * -1 : unary -
 PhysicalNumber PhysicalNumber::operator- (){
        return  PhysicalNumber(value*-1,u);
 }

//check if the our physical number is smaller then other physical number
 bool PhysicalNumber::operator<(const PhysicalNumber &a){
        double num = change(*this, a);
        if (value < num) return true;
        return false;      
 }

//check if the our physical number is bigger then other physical number
 bool PhysicalNumber::operator>(const PhysicalNumber &a){
        double num = change(*this, a);
        if (value > num) return true;
        return false; 
 }

//check if the our physical number is smaller or equal other physical number
 bool PhysicalNumber::operator<=(const PhysicalNumber &a){
        double num = change(*this, a);
        if (value <= num) return true;
        return false;      
 }

//check if the our physical number is bigger or equal other physical number
 bool PhysicalNumber::operator>=(const PhysicalNumber &a){
        double num = change(*this, a);
        if (value >= num) return true;
        return false;      
 }

//check if the our physical number is not equal to other physical number
 bool PhysicalNumber::operator!=(const PhysicalNumber &a){
        double num = change(*this, a);
        if (value == num) return false;
        return true;      
 }

//check if the our physical number is equal to other physical number
 bool PhysicalNumber::operator==(const PhysicalNumber &a){
        double num = change(*this, a);
        if (value == num) return true;
        return false;      
 }

//this function get a physical number and return it as ostream 
   ostream& operator<<(ostream& os, const PhysicalNumber& p){

	if(p.u == Unit::G) os<<p.value<<"[g]";
	else  if(p.u == Unit::KG) os<<p.value<<"[kg]";
        else  if(p.u == Unit::TON) os<<p.value<<"[ton]";
        else  if(p.u == Unit::CM) os<<p.value<<"[cm]";
        else  if(p.u == Unit::M) os<<p.value<<"[m]";
        else  if(p.u == Unit::KM) os<<p.value<<"[km]";
        else  if(p.u == Unit::SEC) os<<p.value<<"[sec]";
        else  if(p.u == Unit::MIN) os<<p.value<<"[min]";
        else  if(p.u == Unit::HOUR) os<<p.value<<"[hour]";
	return os;
  }

//this function get a istream and assigns the input to a physical number
  istream& operator>>(istream& is, PhysicalNumber& p){
    string s;
    is>>s;
    bool error = false;
    int unitStart = s.find("[");
    int unitEnd= s.find("]");
    if(unitStart<=0||unitEnd<0||unitEnd!=s.length()-1) error = true;
    double newValue;
    if (error) auto errorState = is.rdstate();
    else {
          try {
             newValue = stod(s.substr(0,unitStart));
	  }
	  catch (exception &e) { 
		  auto errorState = is.rdstate();
		  return is;
	  }
          string newUnit=s.substr(unitStart+1,unitEnd-unitStart-1);	
          if(newUnit.compare("cm")== 0 || newUnit.compare("CM")== 0) {
		  p.u = Unit::CM;
		  p.value=newValue;  
	  }
          else if (newUnit.compare("m")== 0 || newUnit.compare("M")== 0) {
		  p.u = Unit::M;
		  p.value=newValue;  
	  }
          else if (newUnit.compare("km")== 0 || newUnit.compare("KM")== 0) {
		  p.u = Unit::KM;
		  p.value=newValue;  
	  }
          else if (newUnit.compare("sec")== 0 || newUnit.compare("SEC")== 0) {
		  p.u = Unit::SEC;
		  p.value=newValue;
	  }
          else if (newUnit.compare("min")== 0 || newUnit.compare("MIN")== 0) {
		  p.u = Unit::MIN;
		  p.value=newValue;
	  }
          else if (newUnit.compare("hour")== 0 || newUnit.compare("HOUR")== 0) {
		  p.u = Unit::HOUR;
		  p.value=newValue;
	  }
          else if (newUnit.compare("g")== 0 || newUnit.compare("G")== 0) {
		  p.u = Unit::G;
		  p.value=newValue;
	  }
          else if (newUnit.compare("kg")== 0 || newUnit.compare("KG")== 0) {
		  p.u = Unit::KG;
		  p.value=newValue;
	  }
          else if (newUnit.compare("ton")== 0 || newUnit.compare("TON")== 0) {
		  p.u = Unit::TON;
		  p.value=newValue;
	  }
          else  auto errorState = is.rdstate();
    }  
    return is;
  }

// this function convert types of units
double PhysicalNumber::change(const PhysicalNumber &a,const PhysicalNumber &b) const
{
	switch (a.u)
        {	
	  case Unit::CM://first number is CM
	    switch(b.u)
            {
		case Unit::CM:
		 return b.value;
		case Unit::M:
		 return b.value*100;
		case Unit::KM:
		 return b.value*100000;
		default:
		  throw std::invalid_argument( "Incompatible Dimensions!" );
	    }
	 case Unit::M://first number is M
	    switch(b.u)
            {
		case Unit::CM:
		 return b.value/100;
		case Unit::M:
		 return b.value;
		case Unit::KM:
		 return b.value*1000;
		default:
		  throw std::invalid_argument( "Incompatible Dimensions!" );
	    }
	 case Unit::KM://first number is KM
	    switch(b.u)
            {
		case Unit::CM:
		 return b.value/100000;
		case Unit::M:
		 return b.value/1000;
		case Unit::KM:
		 return b.value;
		default:
		  throw std::invalid_argument( "Incompatible Dimensions!" );
	    }

	  case Unit::SEC://first number is SEC
	    switch(b.u)
            {
		case Unit::SEC:
		 return b.value;
		case Unit::MIN:
		 return b.value*60;
		case Unit::HOUR:
		 return b.value*3600;
		default:
		  throw std::invalid_argument( "Incompatible Dimensions!" );
	    }
	 case Unit::MIN://first number is MIN
	    switch(b.u)
            {
		case Unit::SEC:
		 return b.value/60;
		case Unit::MIN:
		 return b.value;
		case Unit::HOUR:
		 return b.value*60;
		default:
		  throw std::invalid_argument( "Incompatible Dimensions!" );
	    }
	 case Unit::HOUR://first number is HOUR
	    switch(b.u)
            {
		case Unit::SEC:
		 return b.value/3600;
		case Unit::MIN:
		 return b.value/60;
		case Unit::HOUR:
		 return b.value;
		default:
		  throw std::invalid_argument( "Incompatible Dimensions!" );
	    }
  	case Unit::G://first number is G
	    switch(b.u)
            {
		case Unit::G:
		 return b.value;
		case Unit::KG:
		 return b.value*1000;
		case Unit::TON:
		 return b.value*1000000;
		default:
		  throw std::invalid_argument( "Incompatible Dimensions!" );
	    }
	 case Unit::KG://first number is KG
	    switch(b.u)
            {
		case Unit::G:
		 return b.value/1000;
		case Unit::KG:
		 return b.value;
		case Unit::TON:
		 return b.value*1000;
		default:
		  throw std::invalid_argument( "Incompatible Dimensions!" );
	    }
	 case Unit::TON://first number is TON
	    switch(b.u)
            {
		case Unit::G:
		 return b.value/1000000;
		case Unit::KG:
		 return b.value/1000;
		case Unit::TON:
		 return b.value;
		default:
		  throw std::invalid_argument( "Incompatible Dimensions!" );
	    }

	}
}


};
