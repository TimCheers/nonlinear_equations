#include <iostream>
#include <math.h>
#include <time.h>

//e^x-e^(-x)-2=0
//0.8814

using namespace std;

double e = exp(1.0);

double f(double x)
{
	double f;
	f = pow(e, x) - pow(e, -x) - 2;
	return f;	
}

double pf(double x)
{
	double pf;
	pf = pow(e, x) + pow(e, -x);
	return pf;
}

double fun1()
{
	double x, a = 0, b = 1, x0, f_a, f_b, f_x0;
	f_a = f(a);
	f_b = f(b);
	int k = 0;
	while (b - a > 0.00001)
	{
		x0 = (a + b) / 2;
		f_x0 = f(x0);
		if (f_a * f_x0 < 0)
		{
			b = x0;
			f_b = f_x0;
		}
		else
		{
			a = x0;
			f_a = f_x0;
		}
		x = (a + b) / 2;
		k++;
	}
	return x;
}

double fun2() 
{
	srand(time(NULL));
	double x, x0, x1;
	x0 = rand() / float(RAND_MAX);
	x = 1;
	x1 = x0;
	while (abs(x - x1) >= 0.00001)
	{
		x = x0 - (f(x0) / pf(x0));
		x1 = x0;
		x0 = x;
	}
	return x;
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	double x, x0, x1;
	x0 =rand() / float(RAND_MAX);
	x = 1;
	x1 = x0;
	int k=0;
	while (abs(x - x1) >= 0.00001)
	{
		x1 = x0;
		x = abs(f(x1));
		x = x1;
		x0 = x;
		k++;
	}
	cout << x<<endl<<k<<endl;
}


