//This program focuses on various constructors, static functions and variables

#include <iostream>
#include "Vector2D.h"

int main() 
{
	{
		Vector2D v1 = Vector2D::fromCarthesian(2., 3.);		// (x, y)
		const Vector2D v2 = Vector2D::fromPolar(4., 30.);	// (promień, kąt w stopniach)

		v1.print("v1: ");
		v2.print("v2: ");
		std::cout << "==== START: Number of Vector2Ds: " << Vector2D::count<<  std::endl;
		
		double prod = v1.dot(v2);
		std::cout << "Dot product = " << prod << std::endl;
		
		const Vector2D v3 = v1.add(v2); 
		v3.print("v3: ");
		std::cout << v3.dot(v1) << ", " << v3.dot(v2) << std::endl;

		Vector2D v4 = v2;
		v4.print("v4: ");
		std::cout << "==== MIDDLE: Number of Vector2Ds: " << Vector2D::count << std::endl;

		Vector2D v5 (std::move(v3.add(v1)));
		v5.print("v5: ");
		
	}
	std::cout << "==== END: Number of Vector2Ds: " << Vector2D::count << std::endl;
	
}
/* output
v1: (2, 3)
v2: (3.4641, 2)
==== START: Number of Vector2Ds: 2
Dot product = 12.9282
v3: (5.4641, 5)
25.9282, 28.9282
copying (3.4641, 2)
v4: (3.4641, 2)
==== MIDDLE: Number of Vector2Ds: 4
moving (7.4641, 8)
v5: (7.4641, 8)
==== END: Number of Vector2Ds: 0
*/