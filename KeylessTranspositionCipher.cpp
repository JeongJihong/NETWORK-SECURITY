#include <iostream>

using namespace std;

void encryption(char*, char(*tmp)[100], int, int);
void decryption(char*, char(*tmp)[100], int, int);

int main()
{
	char c_text[100] = { 0, }, d_text[100]{ 0, };
	static char tmp[2][100] = { 0, };
	int len = 0, key = 2;
	int mode = 0;

	while (1) {
		cout << "select mode  1. encryption  2.decryption  3.quit" << endl;
		cin >> mode;
		getchar();

		switch (mode) {
		case 1:
			cout << "Enter the plain text: ";
			gets_s(c_text, sizeof(c_text));

			len = strlen(c_text);

			encryption(c_text, tmp, len, key);
			break;

		case 2:
			cout << "Enter the cipher text: ";
			gets_s(d_text, sizeof(d_text));

			len = strlen(d_text);
		
			decryption(d_text, tmp, len, key);
			break;

		default:
			exit(0);
			break;
		}
	}
	return 0;
}

void encryption(char* c_text, char (*tmp)[100], int len, int key)
{
	for (int i = 0; i < len; ++i) {
		if (c_text[i] >= 'a' && c_text[i] <= 'z' || c_text[i] >= 'A' && c_text[i] <= 'Z') {
			if (i % 2 == 0)
				tmp[0][i / 2] = c_text[i];
			else
				tmp[1][i / 2] = c_text[i];
		}
	}
	if (len % 2 == 0) {
		for (int i = 0; i < (len / 2); ++i) {
			c_text[i] = tmp[0][i];
			c_text[i + (len / 2)] = tmp[1][i];
		}
	}
	else {
		int i = 0;
		for (i = 0; i < (len / 2); ++i) {
			c_text[i] = tmp[0][i];
			c_text[i + (len / 2) + 1] = tmp[1][i];
		}
		c_text[len / 2] = tmp[0][i];
	}
	cout << "ciphertext: " << c_text << endl;
}

void decryption(char* d_text, char(*tmp)[100], int len, int key)
{
	for (int i = 0; i < len; ++i) {
		if (i % 2 == 0)
			d_text[i] = tmp[0][i / 2];
		else
			d_text[i] = tmp[1][i / 2];
	}
	cout << "plaintext: " << d_text << endl;
	return;
}