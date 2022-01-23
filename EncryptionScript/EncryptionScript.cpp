
#include <iostream>
#include <string>
#include <cctype>
using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::getline;

int main()
{
	string standard_characters{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890" };
	string encrypted_characters{ "zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA0987654321" };
	string user_input;
	string encrypted_message;
	string decrypted_message;

	cout << "Enter a string to be encrypted: ";
	getline(cin, user_input);
	cout << "\nEncrypting..." << endl;

	for (size_t i{ 0 }; i < user_input.length(); ++i) // could have used ranged for loop instead
	{
		size_t standard_char_index = standard_characters.find(user_input.at(i));
		if (standard_char_index != string::npos)
			encrypted_message += encrypted_characters.at(standard_char_index);
		else
			encrypted_message += user_input.at(i);
	}
	cout << encrypted_message << endl << endl;

	cout << "Decrypting..." << endl;

	for (size_t i{ 0 }; i < encrypted_message.length(); ++i)
	{
		size_t encrypted_char_index = encrypted_characters.find(encrypted_message.at(i));
		if (encrypted_char_index != string::npos)
			decrypted_message += standard_characters.at(encrypted_char_index);
		else
			decrypted_message += encrypted_message.at(i);
	}
	cout << decrypted_message << endl;




	return 0;
}

