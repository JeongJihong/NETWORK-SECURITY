#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

void encryption();
void decryption();
int modinverse(int);

int main()
{
	int mode;
	
	while (1) {
		cout << "select mode  1. encryption  2.decryption  3.quit" << endl;
		cin >> mode;
		getchar();

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
	char str[100] = { 0, };
	int key1 = 0, key2 = 0, str_len = 0;

	cout << "Enter the text: ";
	gets_s(str, sizeof(str));
	cout << "Enter the key1, key2: ";
	cin >> key1 >> key2;
	str_len = strlen(str);

	for (int i = 0; i < str_len; ++i) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] - 'A';
			if (key1 * str[i] + key2 < 0)
				str[i] = str[i] + 26;
			str[i] = (key1 * str[i] + key2) % 26;
			str[i] = str[i] + 'A';
		}
		else if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = str[i] - 'a';
			if (key1 * str[i] + key2 < 0)
				str[i] = str[i] + 26;
			str[i] = (key1 * str[i] + key2) % 26;
			str[i] = str[i] + 'a';
		}
		else;
	}
	cout << "ciphertext: " << str << endl;
}

void decryption()
{
	char str[100] = { 0, };
	int key1 = 0, key2 = 0, str_len = 0, key1_inverse;

	cout << "Enter the text: ";
	gets_s(str, sizeof(str));
	cout << "Enter the key1, key2: ";
	cin >> key1 >> key2;
	str_len = strlen(str);
	key1_inverse = modinverse(key1);

	for (int i = 0; i < str_len; ++i) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] - 'A';
			if (((str[i] - key2) * key1_inverse) < 0)
				str[i] = str[i] + 26;
			str[i] = ((str[i] - key2) * key1_inverse) % 26;
			str[i] = str[i] + 'A';
		}
		else if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = str[i] - 'a';
			if (((str[i] - key2) * key1_inverse) < 0)
				str[i] = str[i] + 26;
			str[i] = ((str[i] - key2) * key1_inverse) % 26;
			str[i] = str[i] + 'a';
		}
		else;
	}
	cout << "plaintext: " << str << endl;
}

int modinverse(int a)
{
	a = a % 26;
	for (int x = 1; x < 26; ++x) {
		if ((a * x) % 26 == 1)
			return x;
	}
}