#include<iostream>
#include<math.h>
using namespace std;

int getLength(long long value) 
{
	int counter = 0;
	while (value != 0) 
	{
		counter++;
		value /= 10;
	}
	return counter;
}
long long power(int x)
{
	int s=1;
	while(x--)
	{
		s=s*10;
	}
	return s;
}
long long multiply(long long x, long long y) 
{
	int xLength = getLength(x);
	int yLength = getLength(y);
	int n = (int)(fmax(xLength, yLength));
	if (n < 3)
		return x * y;
	int N = (n/2) + (n%2);

	long long multiplier = power(N);

	long long a = x/multiplier;
	long long b = x - (a * multiplier);
	long long c = y / multiplier;
	long long d = y - (c * multiplier);

	long long z0 = multiply(a,c);
	long long z1 = multiply(a + b, c + d);
	long long z2 = multiply(b, d);

    return z2 + ((z1 - z0 - z2) * multiplier) + (z0 * (long long)(power(2*N)));

}
int main() 
{
	long long x = 56789;
	long long y = 12345;
	cout<<multiply(x,y)<<endl;
	return 0;
}