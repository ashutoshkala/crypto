#include <iostream>

using namespace std;

// Function to compute the discrete logarithm
int discreteLog(int base, int result, int prime)
{
    int power = 1;
    for (int i = 1; i <= prime - 1; ++i)
    {
        power = (power * base) % prime;
        if (power == result)
            return i;
    }
    return -1; // Discrete logarithm not found
}

int main()
{
    cout << endl;
    // (a) log10(22) for the prime p = 47
    int resultA = discreteLog(10, 22, 47);
    cout << "Discrete logarithm of 22 base 10 (mod 47): " << resultA << endl;
    cout << endl;

    // (b) log627(608) for the prime p = 941
    int resultB = discreteLog(627, 608, 941);
    cout << "Discrete logarithm of 608 base 627 (mod 941): " << resultB << endl;
    cout << endl;

    return 0;
}
