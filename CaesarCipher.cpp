#include <iostream>
#include <string>

using namespace std;

void encryption();
void decryption();

int main()
{
	int mode;

	while (1) {
		cout << "select mode  1. encryption  2.decryption  3.quit" << endl;
		cin >> mode;

		switch (mode) {
		case 1:
			encryption();
			break;
		case 2:
			decryption();
			break;
		default:
			exit(0);
			break;
		}
	}
	return 0;
}

void encryption()
{
	char str[100];
	int key, str_len;

	cout << "Enter the text: ";
	cin >> str;
	cout << "Enter the key: ";
	cin >> key;
	str_len = strlen(str);

	for (int i = 0; i < str_len; ++i) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] - 'A';
			if (str[i] + key < 0)
				str[i] = str[i] + 26;
			str[i] = (str[i] + key) % 26;
			str[i] = str[i] + 'A';
		}
		else if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = str[i] - 'a';
			if (str[i] + key < 0)
				str[i] = str[i] + 26;
			str[i] = (str[i] + key) % 26;
			str[i] = str[i] + 'a';
		}
	}
	cout << "cipher text: " << str << endl;
}

void decryption()
{
	char str[100];
	int key, str_len;

	cout << "Enter the text: ";
	cin >> str;
	cout << "Enter the key: ";
	cin >> key;
	str_len = strlen(str);

	for (int i = 0; i < str_len; ++i) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] - 'A';
			if (str[i] + key < 0)
				str[i] = str[i] + 26;
			str[i] = (str[i] - key) % 26;
			str[i] = str[i] + 'A';
		}
		else if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = str[i] - 'a';
			if (str[i] + key < 0)
				str[i] = str[i] + 26;
			str[i] = (str[i] - key) % 26;
			str[i] = str[i] + 'a';
		}
	}
	cout << "plain text: " << str << endl;
}