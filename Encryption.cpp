#include<iostream>
#include<string>
using namespace std;

int main()
{
    int choice;
    cout << "1. Encryption" << endl << "2. Decrpytion" << endl << "Enter choice [1,2]: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        string message;
        cout << "Message can only be alphabetical" << endl;
        cout << "Enter message: ";
        getline(cin, message);

        int key;
        cout << "Enter key (0-25): ";
        cin >> key;
        cin.ignore();

        string encrpytedtxt = message;

        for (int i = 0; i < message.size(); i++) {
        
            if (message[i] == 32) {
                continue; 
            } else {

                if ((message[i] + key) > 122) {
                    int temp = (message[i] + key) - 122;
                    encrpytedtxt[i] = 96 + temp;
                } else if (message[i] + key > 90 && message[i] <= 96){
                    int temp =(message[i] + key) - 90;
                    encrpytedtxt[i] = 64 + temp;
                } else {
                    encrpytedtxt[i] += key;
                }
            }
        }

        cout << "Encrypted text: "<< encrpytedtxt;
    } else if (choice == 2) {

        string encryptedtxt;
        cout << "Message can only be alphabetical" << endl;
        cout << "Enter message: ";
        getline(cin, encryptedtxt);

        int decryptedkey;
        cout << "Enter key (0-25): ";
        cin >> decryptedkey;
        cin.ignore();

        string decryptedtxt = encryptedtxt;

        for (int i = 0; i < encryptedtxt.size(); i++) {
        
            if (encryptedtxt[i] == 32) {
                continue; 
            } else {

                if ((encryptedtxt[i] - decryptedkey) < 97 && (encryptedtxt[i] >= 65 && encryptedtxt[i]) <= 90) {
                    int temp = (encryptedtxt[i] - decryptedkey) + 26;
                    decryptedtxt[i] = temp;
                } else if ((encryptedtxt[i] - decryptedkey) < 65) {
                    int temp = 97 - (encryptedtxt[i] - decryptedkey) + 26;
                    decryptedtxt[i] = temp;
                } else {
                    decryptedtxt[i] = encryptedtxt[i] - decryptedkey;
                }
            }
        }

        cout << "Decrypted text: "<< decryptedtxt;

    } else {
        cout << "Invalid option";
    }
}
