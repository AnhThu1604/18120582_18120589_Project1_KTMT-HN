
#include <iostream>
#include <string>
#include <math.h>
#define MAX 128
using namespace std;


//AND, OR, XOR, NOT
/*
QInt QInt::operator&(const QInt& str)
{
	QInt ans;
	for (int i = 0; i < 4; ++i)
	{
		ans.data[i] = data[i] & str.data[i];
	}
	return ans;
}
QInt QInt::operator|(const QInt& str)
{
	QInt ans;
	for (int i = 0; i < 4; ++i)
	{
		ans.data[i] = data[i] | str.data[i];
	}
	return ans;
}
QInt QInt::operator^(const QInt& str)
{
	QInt ans;
	for (int i = 0; i < 4; ++i)
	{
		ans.data[i] = data[i] ^ str.data[i];
	}
	return ans;
}
QInt& QInt::operator~()
{
	QInt ans;
	for (int i = 0; i < 4; ++i)
		ans.data[i] = ~data[i];
	return ans;
}

*/


string Bu2(string bin)
{
	for (unsigned int i = 0; i < bin.length(); ++i)
		bin[i] = (bin[i] == '1') ? '0' : '1';
	return addBin(bin, "1");
}

string addBin(string a, string b)
{
	string kq;
	int size;
	//Chuan hoa do dai chuoi (a.length() = b.length())
	//gan mac dinh a la chuoi co do dai dai hon
	if (a.length() < b.length())
		a.swap(b);
	int len = a.length();
	size = len - b.length();
	for (int i = 0; i < size; ++i)
		b.insert(0, 1, '0');
	//Duyet va cong
	int remember = 0;

	//chuyen ki tu ve so (char: 0->9)
	//vd: ki tu 0 co ma la 48 chuyen ve int thi se tru cho 48
	//Nguoc lai cho truong hop chuyen int ve char
	int A, B, ans;
	char s;
	for (int i = len - 1; i >= 0; --i)
	{
		A = a[i] - 48;
		B = b[i] - 48;
		ans = A + B + remember;
		remember = ans / 2;
		s = ans % 2 + 48;
		kq = s + kq;
	}
	if (remember > 0)
	{
		s = remember + 48;
		kq = s + kq;
	}
	return kq;
}

string subBin(string a, string b)
{
	int size;
	//Chuan hoa do dai chuoi (a.length() = b.length())
	//gan mac dinh a la chuoi co do dai dai hon
	if (a.length() < b.length())
		a.swap(b);
	int len = a.length();
	size = len - b.length();
	for (int i = 0; i < size; ++i)
		b.insert(0, 1, '0');
	string ans;
	b = Bu2(b);
	ans = addBin(a, b);
	return ans;
}

string ROL(string bin)
{

	bin = bin + bin[0];
	bin.erase(0, 1);
	return bin;
}

string ROR(string bin)
{
	int len = bin.length();
	bin = bin[len - 1] + bin;
	bin.erase(len, len + 1);
	return bin;
}

//Dich trai
string SHL(string bin, int x)
{
	bin.erase(0, x);
	for (int i = 0; i < x; ++i)
		bin += '0';
	return bin;
}

//Dich phai so hoc
string SAR(string bin, int x)
{
	if (bin[0] == '0')
	{
		bin.erase(bin.length() - x, bin.length());
		for (int i = 0; i < x; ++i)
			bin = '0' + bin;
	}
	else
	{
		bin.erase(bin.length() - x, bin.length());
		for (int i = 0; i < x; ++i)
			bin = '1' + bin;
	}
	return bin;
}

string multBin(string M, string Q)
{

	//Gan mac dinh a co do dai lon hon
	if (M.length() < Q.length())
		M.swap(Q);
	int lenM = M.length();
	int lenQ = Q.length();
	//Tao mang CA voi n+1 bit 0
	//Chuoi A co do dai bang chuoi dai nhat(M)
	string A = "";

	for (int i = 0; i < lenM; ++i)
		A.insert(0, 1, '0');
	string Q1;
	Q1.insert(0, 1, '0');
	int k = lenM;
	string AQQ1;
	int lenAQQ1 = lenM + lenQ + 1;
	string Q0Q1;
	AQQ1 = A + Q + Q1;
	while (k > 0)
	{

		Q0Q1 = Q[Q.length() - 1] + Q1;
		if (Q0Q1 == "10")
		{
			A = subBin(A, M);
			if (A.length() > lenM)
				A.erase(0, 1);
		}
		else
		{
			if (Q0Q1 == "01")
			{
				A = addBin(A, M);
				if (A.length() > lenM)
					A = A.erase(0, 1);
			}
		}
		AQQ1 = A + Q + Q1;
		AQQ1 = SAR(AQQ1, 1);
		A = AQQ1.substr(0, lenM);
		Q = AQQ1.substr(lenM, lenQ);

		Q1 = AQQ1.substr(lenM + lenQ, 1);
		--k;
	}

	string kq = AQQ1.erase(lenAQQ1 - 1, 1);
	return kq;
}

void main()
{
	string a, b;
	cout << "Nhap a: ";
	cin >> a;

	cout << "Nhap b: ";
	cin >> b;

	string kq1 = addBin(a, b);
	cout << "\nKet qua cong: " << kq1;

	string kq2 = subBin(a,b);
	cout << "\nKet qua tru: " << kq2;

	string kq3 = multBin(a, b);
	cout << "\nKet qua: " << kq3;

}


