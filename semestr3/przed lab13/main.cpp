#include "Fraction.h"
#include "FractionArray.h"
#include <iostream>
int main ()
{
  Fraction f1(6,8);
  const Fraction f2(1,2);

  std::cout << f1 << std::endl; 
  std::cout << f2 << std::endl; 
  
  double val = f2;
  std::cout << "Decimal fraction f1: " << val << std::endl;

  f1.simplify(); 
  std::cout << "After simplifying:" << std::endl;
  std::cout << f1 << std::endl; 
  
  std::cout << "Simple math:" << std::endl;
  Fraction f3 = f1*f2;
  std::cout << "Product: " << f3 << std::endl;
  std::cout << "Sum: " << f1+f2 << std::endl;
  std::cout << "Sum: " << f2+f1 << std::endl;
  std::cout << "Product again: " << 3*f2 << std::endl;

  f1 = f2; 		 // OK
  //f1+f2 = f3; // program doesn't compile when this line is uncommented

  FractionArray tab(2);
  tab[0] = f1; //OK
  tab[1] = f3; //OK
  f1 = tab[0]; //OK

  std::cout << tab << std::endl;

  const FractionArray tab_const(2);
  f1 = tab_const[1]; // OK
  //tab_const[0] = f1; // program doesn't compile when this line is uncommented
  // because we don't want to modify const objects
  

}
/* Output:
6/8
1/2
Decimal fraction f1: 0.5
After shortening:
3/4
Simple math:
Product: 3/8
Sum: 10/8
Sum: 10/8
Product again: 3/2
[ 1/2 3/8 ]
*/