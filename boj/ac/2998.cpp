// AC
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a;
	cin >> a;

	string b;
	for (int i=0; a.size()%3 != 0 && i<3-a.size()%3; ++i)
		b.push_back('0');

	b += a;

	for (int i=0; i<b.size(); i+=3)
	{
		string c;
		c.push_back(b[i]); c.push_back(b[i+1]); c.push_back(b[i+2]);
		if (c == "000") putchar('0');
		if (c == "001") putchar('1');
		if (c == "010") putchar('2');
		if (c == "011") putchar('3');
		if (c == "100") putchar('4');
		if (c == "101") putchar('5');
		if (c == "110") putchar('6');
		if (c == "111") putchar('7');
	}
}