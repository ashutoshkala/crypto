#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to convert hexadecimal string to binary string
string hexToBinary(const string &hex)
{
    string binary;
    for (size_t i = 0; i < hex.length(); ++i)
    {
        char c = hex[i];
        int value;
        if (c >= '0' && c <= '9')
            value = c - '0';
        else if (c >= 'a' && c <= 'f')
            value = 10 + c - 'a';
        else if (c >= 'A' && c <= 'F')
            value = 10 + c - 'A';
        else
            throw invalid_argument("Invalid hexadecimal character");

        for (int j = 3; j >= 0; --j)
        {
            binary.push_back(((value >> j) & 1) ? '1' : '0');
        }
    }
    return binary;
}

// Function to convert binary string to base64 string
string binaryToBase64(const string &binary)
{
    const string base64Chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    string base64;
    for (size_t i = 0; i < binary.length(); i += 6)
    {
        int index = 0;
        for (size_t j = 0; j < 6; ++j)
        {
            index <<= 1;
            if (i + j < binary.length() && binary[i + j] == '1')
                index |= 1;
        }
        base64.push_back(base64Chars[index]);
    }
    while (base64.length() % 4 != 0)
    {
        base64.push_back('=');
    }
    return base64;
}

int main()
{
    // Input hexadecimal string to be converted to base64
    string hexString = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7"
                       "573206d757368726f6f6d";

    // Convert hexadecimal string to binary
    string binaryString = hexToBinary(hexString);

    // Convert binary string to base64
    string base64String = binaryToBase64(binaryString);
    cout << endl;
    // Print the base64 string
    cout << "Output :" << base64String << endl;
    cout << endl;

    return 0;
}
