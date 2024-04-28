#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Function to perform XOR operation on a string with a single character
string singleByteXOR(const string &input, char key)
{
    string result;
    for (size_t i = 0; i < input.size(); ++i)
    {
        result.push_back(input[i] ^ key); // XOR each character with the key
    }
    return result;
}

// Function to score a piece of English plaintext based on character frequency
int scorePlaintext(const string &plaintext)
{
    // Define expected frequency of characters in English language
    const vector<double> expectedFrequency = {8.167, 1.492, 2.782, 4.253, 12.702, 2.228, 2.015,
                                              6.094, 6.966, 0.153, 0.772, 4.025, 2.406, 6.749,
                                              7.507, 1.929, 0.095, 5.987, 6.327, 9.056, 2.758,
                                              0.978, 2.360, 0.150, 1.974, 0.074};

    int score = 0;
    for (size_t i = 0; i < plaintext.size(); ++i)
    {
        char c = plaintext[i];
        if (isalpha(c))
        {
            char lowercase = tolower(c);
            score += expectedFrequency[lowercase - 'a'];
        }
    }
    return score;
}

int main()
{
    // Open the file containing the 60-character strings
    ifstream file("60_character_strings.txt");
    if (!file.is_open())
    {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    // Read each line from the file
    string line;
    string bestPlaintext;
    int maxScore = 0;
    char bestKey;
    while (getline(file, line))
    {
        // Convert hex-encoded string to binary
        string binaryInput;
        for (size_t i = 0; i < line.size(); i += 2)
        {
            int byte = stoi(line.substr(i, 2), nullptr, 16);
            binaryInput.push_back(static_cast<char>(byte));
        }

        // Try all possible keys and decrypt the message
        for (int key = 0; key < 256; ++key)
        {
            string decrypted = singleByteXOR(binaryInput, key);
            int score = scorePlaintext(decrypted);
            if (score > maxScore)
            {
                maxScore = score;
                bestPlaintext = decrypted;
                bestKey = key;
            }
        }
    }

    // Print the decrypted message and the key
    cout << "Decrypted message: " << bestPlaintext << endl;
    cout << "Key: " << hex << setw(2) << setfill('0') << static_cast<int>(bestKey) << endl;

    return 0;
}
