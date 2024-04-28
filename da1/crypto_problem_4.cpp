#include <iostream>
#include <string>

using namespace std;

// Function to perform repeating-key XOR encryption
string repeatingKeyXOR(const string &plaintext, const string &key)
{
    string ciphertext;
    size_t keyLength = key.length();
    for (size_t i = 0; i < plaintext.length(); ++i)
    {
        char c = plaintext[i] ^ key[i % keyLength]; // XOR each character with corresponding key byte
        ciphertext.push_back(c);
    }
    return ciphertext;
}

int main()
{
    // Opening stanza of the English work
    string plaintext = "Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal";

    // Key
    string key = "ICE";

    // Encrypt the plaintext using repeating-key XOR
    string ciphertext = repeatingKeyXOR(plaintext, key);
    cout << endl;
    cout << "Output :";
    // Print the ciphertext
    for (size_t i = 0; i < ciphertext.length(); ++i)
    {
        // Print each character in hexadecimal format
        cout << hex << static_cast<int>(static_cast<unsigned char>(ciphertext[i]));
    }
    cout << endl;
    cout << endl;

    return 0;
}
