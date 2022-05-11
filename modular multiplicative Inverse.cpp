#include <bits/stdc++.h>
using namespace std;

// method : 1
//find modular inverse using extended Euclid algorithm
// Returns modulo inverse of a with respect
// to m using extended Euclid Algorithm
// Assumption: a and m are coprimes, i.e.,
// gcd(a, m) = 1
int modInverse(int a, int m)
{
	int m0 = m;
	int y = 0, x = 1;

	if (m == 1)
		return 0;

	while (a > 1) {
		// q is quotient
		int q = a / m;
		int t = m;

		// m is remainder now, process same as
		// Euclid's algo
		m = a % m, a = t;
		t = y;

		// Update y and x
		y = x - q * y;
		x = t;
	}

	// Make x positive
	if (x < 0)
		x += m0;

	return x;
}

// method : 2
/* if gcd(a, m)!=1 .......then O(m) time

int modInverse(int a, int m)
{
    for (int x = 1; x < m; x++)
        if (((a%m) * (x%m)) % m == 1)
            return x;
}

*/

// method : 3

/* if m is prime-------------------O(log m) time & O(log m) space

void modInverse(int a, int m)
{
    int g = gcd(a, m);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {
        // If a and m are relatively prime, then modulo
        // inverse is a^(m-2) mode m
        cout << "Modular multiplicative inverse is "
             << power(a, m - 2, m);
    }
}
 
// To compute x^y under modulo m
int power(int x, unsigned int y, unsigned int m)
{
    if (y == 0)
        return 1;
    int p = power(x, y / 2, m) % m;
    p = (p * p) % m;
 
    return (y % 2 == 0) ? p : (x * p) % m;
}
 
// Function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

*********************************or**********************************

int power(int a, int b)
{
	if(!b)
		return 1;
	int ans = power(a, b/2);
	ans = (ans*ans)%mod;
	if(b%2)
		ans = (ans*a)%mod;
	return ans;
}
int inv(int x){
    return power(x,mod-2);
}
*************************************************************************
*/
int main()
{
	int a = 3, m = 11;


	cout << "Modular multiplicative inverse is "<< modInverse(a, m);
	return 0;
}

