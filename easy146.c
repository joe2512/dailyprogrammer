// [Easy] Polygon Perimeter
// 
// A Polygon is a geometric two-dimensional figure that has n-sides (line segments) that 
// closes to form a loop. Polygons can be in many different shapes and have many different 
// neat properties, though this challenge is about Regular Polygons. Our goal is to 
// compute the permitter of an n-sided polygon that has equal-length sides given the 
// circumradius. This is the distance between the center of the Polygon to any of its 
// vertices; not to be confused with the apothem!
// 
// Input Description
// 
// Input will consist of one line on standard console input. This line will contain first 
// an integer N, then a floating-point number R. They will be space-delimited. The integer 
// N is for the number of sides of the Polygon, which is between 3 to 100, inclusive. R 
// will be the circumradius, which ranges from 0.01 to 100.0, inclusive.
// 
// Output Description
// 
// Print the permitter of the given N-sided polygon that has a circumradius of R. Print 
// up to three digits precision.

#include <stdio.h>

int main() {
	char a[2], b[6];
	
	printf("Enter the number of sides of the regular polygon: ");
	fgets(a, sizeof(a), stdin);
	printf("Enter the circumradius: ");
	fgets(b, sizeof(b), stdin);
	printf("one %s and then two %s", a, b);

}