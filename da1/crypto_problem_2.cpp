#include <iostream>
#include <string>
#include <cstdio> // Include for snprintf

using namespace std;

// Function to perform fixed XOR operation on two equal-length buffers
string fixedXOR(const string &buffer1, const string &buffer2)
{
    if (buffer1.length() != buffer2.length())
    {
        throw invalid_argument("Buffers must be of equal length");
    }

    string result;
    for (size_t i = 0; i < buffer1.length(); ++i)
    {
        // Perform XOR operation on corresponding characters and append the result
        result.push_back(buffer1[i] ^ buffer2[i]);
    }
    return result;
}

int main()
{
    // Input strings in hexadecimal format
    string input1 = "1c0111001f010100061a024b53535009181c";
    string input2 = "686974207468652062756c6c277320657965";

    // Convert hexadecimal strings to binary strings
    string binaryInput1;
    string binaryInput2;
    for (size_t i = 0; i < input1.length(); i += 2)
    {
        int byte1 = stoi(input1.substr(i, 2), nullptr, 16);
        int byte2 = stoi(input2.substr(i, 2), nullptr, 16);
        binaryInput1.push_back(static_cast<char>(byte1));
        binaryInput2.push_back(static_cast<char>(byte2));
    }

    // Perform fixed XOR operation
    string xorResult = fixedXOR(binaryInput1, binaryInput2);

    // Convert result back to hexadecimal format
    string hexResult;
    for (size_t i = 0; i < xorResult.length(); ++i)
    {
        char hex[3];
        snprintf(hex, sizeof(hex), "%02x", static_cast<unsigned char>(xorResult[i]));
        hexResult += hex;
    }

    // Print the XOR result
    cout << endl;
    cout << "Output : " << hexResult << endl;
    cout << endl;

    return 0;
}
