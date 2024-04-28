#include <iostream>
#include <cmath>
// DSA
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
    long long P = 7879;
    long long Q = 101;
    long long g = 170;
    long long x = 25; // Private Key
    long long k = 20;
    long long H_m = 42; // Hash of the message

    // Calculate public key y = g^x mod P
    long long y = power(g, x, P);

    // Calculate r = (g^k mod P) mod Q
    long long r = power(g, k, P) % Q;

    // Calculate s = (k^(-1) * (H(m) + x*r)) mod Q
    long long inverse_k = 0;
    for (long long i = 1; i < Q; i++)
    {
        if ((k * i) % Q == 1)
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

    long long s = (inverse_k * (H_m + x * r)) % Q;

    // Display the signature (r, s)
    cout << "Signature (r, s): (" << r << ", " << s << ")" << endl;

    return 0;
}
