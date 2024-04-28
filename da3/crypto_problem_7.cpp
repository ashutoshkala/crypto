#include <iostream>
#include <cmath>
// elgamma digital siganture
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
    long long q = 73;
    long long alpha = 11;
    long long private_key = 47; // Secret key
    long long public_key = 39;  // Corresponding public key
    long long k = 23;           // Randomly chosen k
    long long m = 25;           // Message to sign

    // Calculate r = α^k mod q
    long long r = power(alpha, k, q);

    // Calculate s = (m - private_key * r) * k^(-1) mod (q-1)
    long long inverse_k = 0;
    for (long long i = 1; i < q; i++)
    {
        if ((k * i) % (q - 1) == 1)
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

    long long s = ((m - private_key * r) * inverse_k) % (q - 1);

    // Display the signature (r, s)
    cout << "Signature (r, s): (" << r << ", " << s << ")" << endl;

    return 0;
}
