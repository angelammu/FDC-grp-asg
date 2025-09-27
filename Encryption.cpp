#include<iostream>
#include<string>
using namespace std;

int main()
{
	while(true){
	
    int choice;
    cout << "-------------------------------------------" << endl;
    cout << "|             WELCOME TO WATSUP           |" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "|          [1] - Encrypt Messages         |" << endl;
    cout << "|          [2] - Decrypt Messages         |" << endl;
    cout << "|          [3] - Exit App                 |" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "\nChoice: " ;
    cin >> choice;
    cin.ignore();
	
	    if (choice == 1) {
	        string message;
	        cout << "\nMessage can only be alphabetical" << endl;
	        cout << "Enter message: ";
	        getline(cin, message);
	
	        int key;
	        cout << "Enter key (0-25): "; //based on the alphabet so total is 26
	        cin >> key;
	        cin.ignore();
	
	        string encrpytedtxt = message;
	
	        for (int i = 0; i < message.size(); i++) {
	        
	            if (message[i] == 32) { //32 is the ASCII of space so we ignore
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
	
	        cout << "Encrypted text: "<< encrpytedtxt << endl << endl;
	    } else if (choice == 2) {
	
	        string encryptedmsg;
	        cout << "\nMessage can only be alphabetical" << endl;
	        cout << "Enter message: ";
	        getline(cin, encryptedmsg);
	
	        int decryptedkey;
	        cout << "Enter key (0-25): ";
	        cin >> decryptedkey;
	        cin.ignore();
	
	        string decryptedtxt = encryptedmsg;
	
	        for (int i = 0; i < encryptedmsg.size(); i++) {
	        
	            if (encryptedmsg[i] == 32) {
	                continue; 
	            } else {
	
	                if ((encryptedmsg[i] - decryptedkey) < 97 && (encryptedmsg[i] - decryptedkey) > 90){
	                    int temp = (encryptedmsg[i] - decryptedkey) + 26;
	                    decryptedtxt[i] = temp;
	                } else if ((encryptedmsg[i] - decryptedkey) < 65) {
	                    int temp = (encryptedmsg[i] - decryptedkey) + 26;
	                    decryptedtxt[i] = temp;
	                } else {
	                    decryptedtxt[i] = encryptedmsg[i] - decryptedkey;
	                }
	            }
	        }
	
	        cout << "Decrypted text: "<< decryptedtxt << endl << endl;
	
	    } else {
	        cout << "Invalid option";
	        break;
	    }
	}

    return 0;
}
