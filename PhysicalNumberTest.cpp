/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);

    PhysicalNumber e1(5, Unit::CM);
    PhysicalNumber f1(7, Unit::M);
    PhysicalNumber g1(3, Unit::KM);
    PhysicalNumber e2(-5, Unit::CM);
    PhysicalNumber f2(-7, Unit::M);
    PhysicalNumber g2(3.2, Unit::KM);

    PhysicalNumber h(60, Unit::SEC);
    PhysicalNumber i(32, Unit::MIN);
    PhysicalNumber j(12, Unit::HOUR);
   
    PhysicalNumber k(50, Unit::G);
    PhysicalNumber l(100, Unit::KG);
    PhysicalNumber m(2, Unit::TON);


    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")

    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)

    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

    // YOUR TESTS - INSERT AS MANY AS YOU WANT

    .setname("Lengt Test")
    
    .CHECK_OUTPUT(e1, "5[cm]")
    .CHECK_OUTPUT(f1, "7[m]")
    .CHECK_OUTPUT(g1, "3[km]")
    .CHECK_OUTPUT(e2, "-5[cm]")
    .CHECK_OUTPUT(f2, "-7[m]")
    .CHECK_OUTPUT(g2, "3.2[km]")
    .CHECK_OUTPUT(e1+f1, "705[cm]")
    .CHECK_OUTPUT((f1+=e1), "7.05[m]")
    .CHECK_OUTPUT(f1, "7.05[m]")
    .CHECK_OUTPUT(f1+f1, "14.1[m]")
    .CHECK_OUTPUT(e1-e1, "0[cm]")
    .CHECK_OK(g1++)
    .CHECK_OUTPUT(g1, "4[km]")
    .CHECK_OK(g1--)
    .CHECK_OUTPUT(g1, "3[km]")
    .CHECK_OUTPUT((g1-=g2), "-0.2[km]")
    .CHECK_OUTPUT(-g1, "0.2[km]")
    .CHECK_OUTPUT((g2+=f1), "3.20705[km]")
    .CHECK_OUTPUT(+e2, "-5[cm]")
    .CHECK_OK(e2++)
    .CHECK_OUTPUT(e2, "-4[cm]")
    .CHECK_OK(f2--)
    .CHECK_OUTPUT(f2, "-8[m]")
    .CHECK_EQUAL(e2<e1, true)
    .CHECK_EQUAL(f2>f1, false)
    .CHECK_EQUAL(f1>=e2, true)
    .CHECK_EQUAL(g2<=g1, false)
    .CHECK_EQUAL(e2!=f1, true)
    .CHECK_EQUAL(e2!=e2, false)
    .CHECK_EQUAL(g1==g1, true)
    .CHECK_EQUAL(e1==e2,false)
    .CHECK_EQUAL(f1!=g1, true)
    .CHECK_EQUAL(e2!=g1, true)
    .CHECK_OUTPUT(++e1,"6[cm]")
    .CHECK_OUTPUT(++f2, "-7[m]")
    .CHECK_OUTPUT(++g1, "0.8[km]")
    .CHECK_OUTPUT(--e1,"5[cm]")
    .CHECK_OUTPUT(--f2, "-8[m]")
    .CHECK_OUTPUT(--g2, "2.20705[km]")

    .CHECK_OK(istringstream("3[ton]") >> f1)
    .CHECK_OUTPUT((f1 += PhysicalNumber(1000, Unit::KG)), "4[ton]")
    .CHECK_OK(istringstream("1[kg]") >> e2)
    .CHECK_OUTPUT((e2 += PhysicalNumber(1000, Unit::G)), "2[kg]")
    
   

    .setname("Time Test")
    .CHECK_OUTPUT(h, "60[sec]")
    .CHECK_OUTPUT(i, "32[min]")
    .CHECK_OUTPUT(j, "12[hour]")
    .CHECK_OUTPUT(h+i, "1980[sec]")
    .CHECK_OUTPUT((i+=h), "33[min]")
    .CHECK_OUTPUT(i+j, "753[min]")
    .CHECK_OUTPUT((h+=i), "2040[sec]")
    .CHECK_OUTPUT(h, "2040[sec]")
    .CHECK_OUTPUT(h+h, "4080[sec]")
    .CHECK_OUTPUT(j-j, "0[hour]")
    .CHECK_OK(j++)
    .CHECK_OUTPUT(j, "13[hour]")
    .CHECK_OK(j--)
    .CHECK_OUTPUT(j, "12[hour]")
    .CHECK_OUTPUT((j-=i), "11.45[hour]")
    .CHECK_OUTPUT(-i, "-33[min]")
    .CHECK_OUTPUT((i+=j), "720[min]")
    .CHECK_OUTPUT(+j, "11.45[hour]")
    .CHECK_OK(i++)
    .CHECK_OUTPUT(i, "721[min]")
    .CHECK_OK(i--)
    .CHECK_OUTPUT(i, "720[min]")
    .CHECK_EQUAL(i<j, false)
    .CHECK_EQUAL(i>j, true)
    .CHECK_EQUAL(h<=i, true)
    .CHECK_EQUAL(h<=j, true)
    .CHECK_EQUAL(i!=j, true)
    .CHECK_EQUAL(h!=j, true)
    .CHECK_EQUAL(i==i, true)
    .CHECK_EQUAL(i==j,false)
    .CHECK_OUTPUT(++h,"2041[sec]")
    .CHECK_OUTPUT(++i, "721[min]")
    .CHECK_OUTPUT(++j, "12.45[hour]")
    .CHECK_OUTPUT(--h,"2040[sec]")
    .CHECK_OUTPUT(--i, "720[min]")
    .CHECK_OUTPUT(--j, "11.45[hour]")

    .CHECK_OK(istringstream("55[cm]") >> i)
    .CHECK_OUTPUT((i += PhysicalNumber(10, Unit::M)), "1055[cm]")
    .CHECK_OK(istringstream("40[m]") >> j)
    .CHECK_OUTPUT((j += PhysicalNumber(850, Unit::CM)), "48.5[m]")


    .setname("Weight Test")
    .CHECK_OUTPUT(k, "50[g]")
    .CHECK_OUTPUT(l, "100[kg]")
    .CHECK_OUTPUT(m, "2[ton]")
    .CHECK_OUTPUT(k+l, "100050[g]")
    .CHECK_OUTPUT((l+=k), "100.05[kg]")
    .CHECK_OUTPUT(k+k, "100[g]")
    .CHECK_OUTPUT((m+=l), "2.10005[ton]")
    .CHECK_OUTPUT(m, "2.10005[ton]")
    .CHECK_OUTPUT(m+m, "4.2001[ton]")
    .CHECK_OUTPUT(k-k, "0[g]")
    .CHECK_OK(k++)
    .CHECK_OUTPUT(k, "51[g]")
    .CHECK_OK(k--)
    .CHECK_OUTPUT(k, "50[g]")
    .CHECK_OUTPUT((k-=l), "-100000[g]")
    .CHECK_OUTPUT(-k, "100000[g]")
    .CHECK_OUTPUT((m+=k), "2.00005[ton]")
    .CHECK_OUTPUT(+m, "2.00005[ton]")
    .CHECK_OK(m++)
    .CHECK_OUTPUT(m, "3.00005[ton]")
    .CHECK_OK(m--)
    .CHECK_OUTPUT(m, "2.00005[ton]")
    .CHECK_EQUAL(k<l, true)
    .CHECK_EQUAL(k>l, false)
    .CHECK_EQUAL(m>=l, true)
    .CHECK_EQUAL(k<=m, true)
    .CHECK_EQUAL(k!=m, true)
    .CHECK_EQUAL(l!=k, true)
    .CHECK_EQUAL(k==k, true)
    .CHECK_EQUAL(m==l,false)
    .CHECK_OUTPUT(++m,"3.00005[ton]")
    .CHECK_OUTPUT(++k, "-99999[g]")
    .CHECK_OUTPUT(++l, "101.05[kg]")
    .CHECK_OUTPUT(--m,"2.00005[ton]")
    .CHECK_OUTPUT(--k, "-100000[g]")
    .CHECK_OUTPUT(--l, "100.05[kg]")
    
    .CHECK_OK(istringstream("120[sec]") >> k)
    .CHECK_OUTPUT((k += PhysicalNumber(320, Unit::MIN)), "19320[sec]")
    .CHECK_OK(istringstream("1[hour]") >> m)
    .CHECK_OUTPUT((m += PhysicalNumber(90, Unit::MIN)), "2.5[hour]")


    .CHECK_THROWS(e1+h)
    .CHECK_THROWS(f1+i)
    .CHECK_THROWS(g2+m)  
    .CHECK_THROWS(g1+k)
    .CHECK_THROWS(e1+l)
    .CHECK_THROWS(m+i)
    .CHECK_THROWS(j+m)  
    .CHECK_THROWS(k+f2)
    .CHECK_THROWS(h-l)
    .CHECK_THROWS(f1-m)
    .CHECK_THROWS(e2-j)  
    .CHECK_THROWS(m-j)
    .CHECK_THROWS(k-i)
    .CHECK_THROWS(h-g1)
    .CHECK_THROWS(e1+=m)
    .CHECK_THROWS(f2+=k)
    .CHECK_THROWS(g2+=l)
    .CHECK_THROWS(i+=k)
    .CHECK_THROWS(h+=f2)
    .CHECK_THROWS(i+=m)
    .CHECK_THROWS(j+=e2)
    .CHECK_THROWS(m-=i)
    .CHECK_THROWS(m-=g1)
    .CHECK_THROWS(f2-=l)
    .CHECK_THROWS(h-=i)
    .CHECK_THROWS(e1-=k)
    .CHECK_THROWS(j-=h)
    .CHECK_THROWS(k-=g2)
    .CHECK_THROWS(k-=i)
    .CHECK_THROWS(e1<m)
    .CHECK_THROWS(h<l)
    .CHECK_THROWS(j<k)
    .CHECK_THROWS(e2>k)
    .CHECK_THROWS(g1>m)
    .CHECK_THROWS(g2>l)
    .CHECK_THROWS(f1<=i)
    .CHECK_THROWS(f1<=j)
    .CHECK_THROWS(e2<=h)
    .CHECK_THROWS(m>=j)
    .CHECK_THROWS(m>=i)
    .CHECK_THROWS(h>=f2)
    .CHECK_THROWS(e1==h)
    .CHECK_THROWS(i==l)
    .CHECK_THROWS(h==g1)
    .CHECK_THROWS(e1!=m)
    .CHECK_THROWS(e2!=k)
    .CHECK_THROWS(i!=l)


      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}
