#include <iostream>
#define BLOCK_SIZE 6

using namespace std;

int main()
{
	char p_text[100] = { 0, };
	static char c_text[100] = { 0, };
	int select = 0, key[BLOCK_SIZE] = { 3, 5, 1, 6, 4, 2 }, key_size = BLOCK_SIZE,
		block_num = 0, str_size = 0;

	while (1) {
		cout << "1.Encryption  2.Decryption  ";
		cin >> select;
		if (select == 1) {
			cout << "Enter the plain text: ";
			cin >> p_text;

			str_size = strlen(p_text);
			if (str_size % BLOCK_SIZE != 0) {
				block_num = strlen(p_text) / BLOCK_SIZE + 1;
				for (int i = strlen(p_text); i < block_num * BLOCK_SIZE; ++i)
					p_text[i] = 'x';
			}

			for (int i = 0; i < block_num; ++i) {
				for (int j = 0; j < BLOCK_SIZE; ++j)
					c_text[i * BLOCK_SIZE + j] = p_text[(key[j] - 1) + i * BLOCK_SIZE];
			}
			cout << c_text << endl;
		}
		else if (select == 2) {
			for (int i = 0; i < block_num; ++i) {
				for (int j = 0; j < BLOCK_SIZE; ++j)
					 p_text[(key[j] - 1) + i * BLOCK_SIZE] = c_text[i * BLOCK_SIZE + j];
			}
			cout << p_text << endl;
		}
		else {
			exit(0);
		}
	}
	return 0;
}