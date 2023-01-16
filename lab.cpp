// C++ program for implementation of Bisection Method for
// solving equations
#include<bits/stdc++.h>
using namespace std;
#define EPSILON 0.01

// An example function whose solution is determined using
// Bisection Method. The function is x^3 - x^2 + 2
double func(double x)
{
	return x*x*x - x*x + 2;
}

// Prints root of func(x) with error of EPSILON
void bisection(double a, double b)
{
	if (func(a) * func(b) >= 0)
	{
		cout << "You have not assumed right a and b\n";
		return;
	}

	double c = a;
	while ((b-a) >= EPSILON)
	{
		// Find middle point
		c = (a+b)/2;

		// Check if middle point is root
		if (func(c) == 0.0)
			break;

		// Decide the side to repeat the steps
		else if (func(c)*func(a) < 0)
			b = c;
		else
			a = c;
	}
	cout << "The value of root is : " << c;
}

// Driver program to test above function
int main()
{
	// Initial values assumed
	double a =-200, b = 300;
	bisection(a, b);
	return 0;
}
// C++ program for implementation of Newton Raphson Method for
// solving equations
#include<bits/stdc++.h>
#define EPSILON 0.001
using namespace std;

// An example function whose solution is determined using
// Bisection Method. The function is x^3 - x^2 + 2
double func(double x)
{
	return x*x*x - x*x + 2;
}

// Derivative of the above function which is 3*x^x - 2*x
double derivFunc(double x)
{
	return 3*x*x - 2*x;
}

// Function to find the root
void newtonRaphson(double x)
{
	double h = func(x) / derivFunc(x);
	while (abs(h) >= EPSILON)
	{
		h = func(x)/derivFunc(x);

		// x(i+1) = x(i) - f(x) / f'(x)
		x = x - h;
	}

	cout << "The value of the root is : " << x;
}

// Driver program to test above
int main()
{
	double x0 = -20; // Initial values assumed
	newtonRaphson(x0);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
// function takes value of x and returns f(x)
float f(float x)
{
    // we are taking equation as x^3+x-1
    float f = pow(x, 3) + x - 1;
    return f;
}
 
void secant(float x1, float x2, float E)
{
    float n = 0, xm, x0, c;
    if (f(x1) * f(x2) < 0) {
        do {
            // calculate the intermediate value
            x0 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
 
            // check if x0 is root of equation or not
            c = f(x1) * f(x0);
 
            // update the value of interval
            x1 = x2;
            x2 = x0;
 
            // update number of iteration
            n++;
 
            // if x0 is the root of equation then break the loop
            if (c == 0)
                break;
            xm = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
        } while (fabs(xm - x0) >= E); // repeat the loop
                                // until the convergence
 
        cout << "Root of the given equation=" << x0 << endl;
        cout << "No. of iterations = " << n << endl;
    } else
        cout << "Can not find a root in the given interval";
}
 
// Driver code
int main()
{
    // initializing the values
    float x1 = 0, x2 = 1, E = 0.0001;
    secant(x1, x2, E);
    return 0;
}
