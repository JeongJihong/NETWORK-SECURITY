#include <iostream>
#define BLOCK_SIZE 4

using namespace std;

void encryption(char*, int*, int, int);
void decryption(char*, int*, int, int);

int main()
{
	char str[100];
	int key[100] = { 0, }, str_len = 0, key_len = BLOCK_SIZE;
	int mode = 0;
	strncpy(str, "\0", 100);

	while (1) {
		cout << "select mode  1. encryption  2.decryption  3.quit" << endl;
		cin >> mode;
		getchar();

		switch (mode) {
		case 1:
			cout << "Enter the plain text: ";
			gets_s(str, sizeof(str));
			cout << "Enter the key: ";
			for (int i = 0; i < BLOCK_SIZE; ++i)
				cin >> key[i];

			str_len = strlen(str);

			encryption(str, key, str_len, key_len);
			break;

		case 2:
			cout << "Enter the cipher text: ";
			gets_s(str, sizeof(str));
			cout << "Enter the key: ";
			for (int i = 0; i < BLOCK_SIZE; ++i)
				cin >> key[i];

			str_len = strlen(str);

			decryption(str, key, str_len, key_len);
			break;

		default:
			exit(0);
			break;
		}
	}
	return 0;
}

void encryption(char* str, int* key, int str_len, int key_len)
{
	for (int i = 0; i < str_len; ++i) {
		int j = i % key_len;

		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] -= 'A';
			if (str[i] + key[j] < 0) {
				str[i] += 26;
			}
			str[i] += key[j] % 26;
			str[i] += 'A';
		}
		else if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] -= 'a';
			if (str[i] + key[j] < 0) {
				str[i] += 26;
			}
			str[i] += key[j] % 26;
			str[i] += 'a';
		}
		else;
	}
	cout << "ciphertext: " << str << endl;
}

void decryption(char* str, int* key, int str_len, int key_len)
{
	for (int i = 0; i < str_len; ++i) {
		int j = i % key_len;
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] -= 'A';
			while (str[i] + key[j] < 0) {
				str[i] += 26;
			}
			str[i] += key[j] % 26;
			str[i] += 'A';
		}
		else if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] -= 'a';
			while (str[i] - key[j] < 0) {
				str[i] += 26;
			}
			str[i] -= key[j] % 26;
			str[i] += 'a';
		}
		else;
	}
	cout << "plaintext: " << str << endl;
}
