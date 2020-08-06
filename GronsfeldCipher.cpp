#include <iostream>

using namespace std;

void encryption(char*, char*, int, int);
void decryption(char*, char*, int, int);

int main()
{
	char str[100] = { 0, }, key[100] = { 0, };
	int str_len = 0, key_len = 0;
	int mode = 0;

	while (1) {
		cout << "select mode  1. encryption  2.decryption  3.quit" << endl;
		cin >> mode;
		getchar();

		switch (mode) {
		case 1:
			cout << "Enter the plain text: ";
			gets_s(str, sizeof(str));
			cout << "Enter the key: ";
			gets_s(key, sizeof(key));

			str_len = strlen(str);
			key_len = strlen(key);

			encryption(str, key, str_len, key_len);
			break;

		case 2:
			cout << "Enter the cipher text: ";
			gets_s(str, sizeof(str));
			cout << "Enter the key: ";
			gets_s(key, sizeof(key));

			str_len = strlen(str);
			key_len = strlen(key);

			decryption(str, key, str_len, key_len);
			break;

		default:
			exit(0);
			break;
		}
	}
	return 0;
}

void encryption(char* str, char* key, int str_len, int key_len)
{
	for (int i = 0; i < str_len; ++i) {
		int j = i % key_len;
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] -= 'A';
			key[j] -= '0';
			while (str[i] + key[j] < 0) {
				str[i] += 26;
			}
			str[i] += key[j] % 26;
			str[i] += 'A';
		}
		else if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] -= 'a';
			key[j] -= '0';
			while (str[i] + key[j] < 0) {
				str[i] += 26;
			}
			str[i] += key[j] % 26;
			str[i] += 'a';
		}
		else;
	}
	cout << "ciphertext: " << str << endl;
}

void decryption(char* str, char* key, int str_len, int key_len)
{
	for (int i = 0; i < str_len; ++i) {
		int j = i % key_len;
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] -= 'A';
			key[j] -= '0';
			while (str[i] + key[j] < 0) {
				str[i] += 26;
			}
			str[i] += key[j] % 26;
			str[i] += 'A';
		}
		else if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] -= 'a';
			key[j] -= '0';
			while (str[i] + key[j] < 0) {
				str[i] += 26;
			}
			str[i] += key[j] % 26;
			str[i] += 'a';
		}
		else;
	}
	cout << "plaintext: " << str << endl;
}
