#include <iostream>
#include <string>

using namespace std;

// ==========================
// Encryption Function
// ==========================
string encrypt(string text, int shift)
{
    string encryptedText = "";

    for(char ch : text)
    {
        // Uppercase letters
        if(isupper(ch))
        {
            encryptedText += char((ch - 'A' + shift) % 26 + 'A');
        }

        // Lowercase letters
        else if(islower(ch))
        {
            encryptedText += char((ch - 'a' + shift) % 26 + 'a');
        }

        // Other characters
        else
        {
            encryptedText += ch;
        }
    }

    return encryptedText;
}

// ==========================
// Decryption Function
// ==========================
string decrypt(string text, int shift)
{
    string decryptedText = "";

    for(char ch : text)
    {
        // Uppercase letters
        if(isupper(ch))
        {
            decryptedText += char((ch - 'A' - shift + 26) % 26 + 'A');
        }

        // Lowercase letters
        else if(islower(ch))
        {
            decryptedText += char((ch - 'a' - shift + 26) % 26 + 'a');
        }

        // Other characters
        else
        {
            decryptedText += ch;
        }
    }

    return decryptedText;
}

// ==========================
// Main Function
// ==========================
int main()
{
    string text;
    int shift;

    cout << "=====================================\n";
    cout << "   BASIC ENCRYPTION & DECRYPTION\n";
    cout << "=====================================\n\n";

    cout << "Enter Text: ";
    getline(cin, text);

    cout << "Enter Shift Value: ";
    cin >> shift;

    // Encrypt
    string encrypted = encrypt(text, shift);

    // Decrypt
    string decrypted = decrypt(encrypted, shift);

    // Output
    cout << "\n=====================================\n";

    cout << "Original Text : " << text << endl;
    cout << "Encrypted Text: " << encrypted << endl;
    cout << "Decrypted Text: " << decrypted << endl;

    cout << "=====================================\n";

    return 0;
}