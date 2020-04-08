// Algorithm.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
// ���η���������˷�

#include <iostream>
#include <string>
#include <malloc.h>
#include <algorithm>
#include <sstream>
using namespace std;

// ʹ��stringstream����int��string��ת��
int str2Int(string k)
{
	int back;
	stringstream instr(k);
	instr >> back;
	return back;
}
string int2Str(int intValue)
{
	string result;
	stringstream stream;
	stream << intValue;
	stream >> result;
	return result;
}

void removePreZero(string& str)
{
	// ȥ��ǰ��0,��Ҫ����ֻ��һ��0����ȫ����0�����

	if (str.length() == 1) return;

	int k = 0;
	for (int i = 0; i < str.length(); i++)
	{
		// string.at(i) ����string���±�Ϊi��Ԫ�ص�����
		if (str.at(i) == '0') k++;
		else break;
	}
	if (k == str.length()) str = "0";
	else str = str.substr(k);  //string.substr(k)����string��k����β���Ӵ�
}

/**
 * ������ӣ�������ǰ��0�����
 * @param x
 * @param y
 * @return
 */
string add(string x, string y)
{
	string result = "";

	// ȥ��ǰ��0
	removePreZero(x);
	removePreZero(y);

	// ��ת�ַ���������ӣ�reverse�������ڷ�ת�ַ������޷���ֵ��ͷ�ļ���<algorithm>
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());

	for (int i = 0, j = 0; j || i < max(y.length(), x.length()); i++)
	{
		int t = j;
		if (i < x.length())t += (x.at(i) - '0');
		if (i < y.length())t += (y.at(i) - '0');
		//c.s[c.len++] = t % 10;
		int q = t % 10;
		result.insert(0, int2Str(q));
		j = t / 10;
	}

	return result;
}

string subtract(string& x, string& y)
{
	string result = "";

	//ȥ��ǰ��0
	removePreZero(x);
	removePreZero(y);

	int len_x = x.length();
	int len_y = y.length();
	int len = len_x > len_y ? len_x : len_y;
	int* tempResult = (int*)malloc(sizeof(int) * len);
	string sign;

	if (len_x > len_y)  // x - yΪ����
	{
		sign = "+";
	}
	else if (len_x < len_y)  // x-yΪ����
	{
		sign = "-";
	}
	else  //������ͬ���жϸ�λ�Ĵ�С
	{
		int i;
		for (i = 0; i < len_x; i++)
		{
			if (x.at(i) == y.at(i))continue;
			else if (x.at(i) > y.at(i))
			{
				sign = "+";
				break;
			}
			else
			{
				sign = "-";
				break;
			}
		}
		if (i == len_x) // ˵��û��break��˵��x == y
		{
			return "0";
		}
	}

	//��ת�ַ����������
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());

	int q = 0;

	//��x����ֱ�������������y-x���������ռ��ϸ���
	for (int i = 0; i < len; i++)
	{
		int aint = i < len_x ? x.at(i) - '0' : 0;
		int bint = i < len_y ? y.at(i) - '0' : 0;
		if (sign.at(0) == '+')
		{
			tempResult[q++] = aint - bint;
		}
		else
		{
			tempResult[q++] = bint - aint;
		}
	}
	for (int i = 0; i < q; i++)
	{
		if (tempResult[i] < 0)
		{
			tempResult[i + 1] -= 1;
			tempResult[i] += 10;
		}
	}
	q--;
	while (tempResult[q] == 0)q--;
	for (int i = q; i >= 0; i--)
	{
		result += int2Str(tempResult[i]);
	}
	if (sign.at(0) == '-')return sign + result;
	return result;
}

/**
 * ���ǰ��0
 * @param str
 * @param zero_num
 */
void addPreZero(string& str, int zero_num)
{
	for (int i = 0; i < zero_num; i++)str.insert(0, "0");
}
string addLastZero(string str, int zero_num)
{
	string s = str;
	for (int i = 0; i < zero_num; i++)s += "0";
	return s;
}

/**
 * ����x��y�ĳ˻�, ���غ�ɽ���int�͵ĺ�string���͵�
 * @param x
 * @param y
 * @return
 */
string multiply(string& x, string& y)
{
	bool flag_x = false; //��
	bool flag_y = false;
	bool flag; // ���ս����������
	//�ȴ���������
	if (x.at(0) == '-')
	{//��
		flag_x = true;
		x = x.substr(1);
	}
	if (y.at(0) == '-')
	{
		flag_y = true;
		y = y.substr(1);
	}
	//������Ϊ������������Ϊ����������Ϊ��
	if ((flag_x && flag_y) || (!flag_x && !flag_y))
	{
		flag = false;
	}
	else
	{
		flag = true;//������Ϊ��
	}

	/**
	 * Ԥ������x��y�������ͬλ����������
	 * x��y�ĳ��ȱ�����2��ָ�������������ܵݹ���μ���
	 * ������Ҫ��x��y���ǰ��0�������ȴ���Ϊ���е���С�ĳ���
	 *
	 * �������x��y�ĳ��Ƚ�ͳһ
	 */

	int init_len = 4;

	if (x.length() > 2 || y.length() > 2)
	{ // ���ȴ���2ʱ����С����Ӧ��Ϊ4���ʳ�ʼֵΪ4

		if (x.length() >= y.length())
		{
			while (init_len < x.length())init_len *= 2; //�������������յĳ���
			//���ǰ��0
			if (x.length() != init_len)
			{
				addPreZero(x, init_len - x.length());
			}
			addPreZero(y, init_len - y.length());
		}
		else
		{
			while (init_len < y.length())init_len *= 2;
			//���ǰ��0
			addPreZero(x, init_len - x.length());
			if (y.length() != init_len)
			{
				addPreZero(y, init_len - y.length());
			}
		}
	}

	if (x.length() == 1)
	{
		addPreZero(x, 1);
	}
	if (y.length() == 1)
	{
		addPreZero(y, 1);
	}
	int n = x.length();
	string result;
	string a1, a0, b1, b0;
	if (n > 1)
	{
		a1 = x.substr(0, n / 2);
		a0 = x.substr(n / 2, n);
		b1 = y.substr(0, n / 2);
		b0 = y.substr(n / 2, n);
	}

	if (n == 2)
	{ //����Ϊ2ʱ�������ݹ�

		int x1 = str2Int(a1);
		int x2 = str2Int(a0);
		int y1 = str2Int(b1);
		int y2 = str2Int(b0);
		int z = (x1 * 10 + x2) * (y1 * 10 + y2);
		result = int2Str(z);
	}
	else
	{
		string c2 = multiply(a1, b1);
		string c0 = multiply(a0, b0);
		string temp_c1_1 = add(a0, a1);
		string temp_c1_2 = add(b1, b0);
		string temp_c1_3 = add(c2, c0);
		string temp_c1 = multiply(temp_c1_1, temp_c1_2);
		string c1 = subtract(temp_c1, temp_c1_3);
		string s1 = addLastZero(c1, n / 2);
		string s2 = addLastZero(c2, n);
		result = add(add(s1, s2), c0);
	}
	if (flag)
	{ //���Ϊ����
		result.insert(0, "-");
	}
	return result;
}

string multiply(string x, int y)
{
	string temp = int2Str(y);
	return multiply(x, temp);
}

string multiply(int x, string y)
{
	string temp = int2Str(x);
	return multiply(temp, y);
}

string multiply(int x, int y)
{
	string temp1 = int2Str(x);
	string temp2 = int2Str(y);
	return multiply(temp1, temp2);
}

int main()
{
	int a = -123123123;
	int b = -123343;
	string X = "123456";
	string Y = "654321";
	string result = multiply(X, Y);
	cout << result << endl;

	return 0;
}