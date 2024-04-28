#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate modular exponentiation (a^b mod m)
long long power(long long a, long long b, long long m)
{
    if (b == 0)
        return 1;
    long long temp = power(a, b / 2, m);
    long long result = (temp * temp) % m;
    if (b % 2 == 1)
        result = (result * a) % m;
    return result;
}

int main()
{
    // Given parameters
    long long p = 59;
    long long q = 29;
    long long h = 11; // g
    long long H_M = 26;
    long long k = 10;
    long long x = 7; // Bob's private key

    // Calculate g = h^((p-1)/q) mod p
    long long g = power(h, (p - 1) / q, p);

    // Calculate y = h^x mod p
    long long y = power(h, x, p);

    // Calculate r = (g^k mod p) mod q
    long long r = power(g, k, p) % q;

    // Calculate s = (k^(-1) * (H(M) + x*r)) mod q
    long long inverse_k = 0;
    for (long long i = 1; i < q; i++)
    {
        if ((k * i) % q == 1)
        {
            inverse_k = i;
            break;
        }
    }

    if (inverse_k == 0)
    {
        cout << "Inverse of k doesn't exist." << endl;
        return 0;
    }

    long long s = (inverse_k * (H_M + x * r)) % q;

    // Display the signature (r, s)
    cout << "Signature (r, s): (" << r << ", " << s << ")" << endl;

    return 0;
}
