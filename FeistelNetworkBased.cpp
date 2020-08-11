#include <iostream>
#include <bitset>
#define BLOCK_SIZE 6
#define ROUND_NUM 2

using namespace std;

char F1(char input);
char F2(char input);
char Feistel_Enc(char p);
char Feistel_Dec(char c);

int main()
{
	char p = 0x2B, c = 0, d = 0;
	cout << "평문: " << bitset<8>(p) << endl;

	c = Feistel_Enc(p);
	cout << "암호문: " << bitset<8>(c) << endl;

	d = Feistel_Dec(c);
	cout << "복호문: " << bitset<8>(d) << endl;

	return 0;
}

char F1(char input)
{
	if (input == 0x00)
		return 0x05;
	else if (input == 0x01)
		return 0x02;
	else if (input == 0x02)
		return 0x03;
	else if (input == 0x03)
		return 0x06;
	else if (input == 0x04)
		return 0x04;
	else if (input == 0x05)
		return 0x01;
	else if (input == 0x06)
		return 0x07;
	else if (input == 0x07)
		return 0x00;
	else
		return 0x00;
}

char F2(char input)
{
	if (input == 0x00)
		return 0x04;
	else if (input == 0x01)
		return 0x00;
	else if (input == 0x02)
		return 0x03;
	else if (input == 0x03)
		return 0x07;
	else if (input == 0x04)
		return 0x06;
	else if (input == 0x05)
		return 0x05;
	else if (input == 0x06)
		return 0x01;
	else if (input == 0x07)
		return 0x02;
	else
		return 0x00;
}

char Feistel_Enc(char p)
{
	char l = 0, r = 0, _r = 0, c_bit = 0;
	l = (p >> 3) & 0x07;
	r = p & 0x07;
	_r = r;

	for (int i = 0; i < ROUND_NUM; ++i) {
		if (i == 0) {
			r = l ^ F1(_r);
			l = _r;
		}
		else if(i == ROUND_NUM - 1)
			l = l ^ F2(r);
	}
	c_bit = (l << 3) | r;
	return c_bit;
}

char Feistel_Dec(char c)
{
	char l = 0, r = 0, _r = 0, d_bit = 0;
	l = (c >> 3) & 0x07;
	r = c & 0x07;
	_r = r;

	for (int i = 0; i < ROUND_NUM; ++i) {
		if (i == 0) {
			r = l ^ F2(_r);
			l = _r;
		}
		else if (i == ROUND_NUM - 1)
			l = l ^ F1(r);
	}
	d_bit = (l << 3) | r;
	return d_bit;
}