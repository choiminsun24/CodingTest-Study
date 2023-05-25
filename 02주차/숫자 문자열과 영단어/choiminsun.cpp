#include <string>
#include <iostream>

using namespace std;

class TransToNum
{
private:
	bool itsNum; //�ֱ� word�� ���ڸ� true
	int num; //�ֱ� word�� ���� ��
	int index; //������� üũ�� �κ�
	string word; //�����̵��� �ܾ�
	bool checkNum(string word); //�ش� ������ �������� Ȯ��
	bool checkArabia(char word); //�ش� ���ڰ� �ƶ��� �������� Ȯ��

public:
	string str; //���� ����.
	int result; //��ȯ�� ���ڿ�(���ڷ� ����)
	TransToNum(string str); //������
	int transform(); //��ȯ(�̰� ���� ���ο� �;��ϴµ� ��¼�� ��¼��)
};

TransToNum::TransToNum(string str) //���� �ʱ�ȭ ���ְ�
{
	itsNum = false;
	result = 0;
	word = "";
	index = 0;

	this->str = str;
}

bool TransToNum::checkNum(string word) //if������ �Ķ������ ���ܾ �������� Ȯ��. �ش� ���δ� ��� ������ ����. 
{
	if (word == "zero")
	{
		itsNum = true;
		num = 0;
	}
	else if (word == "one")
	{
		itsNum = true;
		num = 1;
	}
	else if (word == "two")
	{
		itsNum = true;
		num = 2;
	}
	else if (word == "three")
	{
		itsNum = true;
		num = 3;
	}
	else if (word == "four")
	{
		itsNum = true;
		num = 4;
	}
	else if (word == "five")
	{
		itsNum = true;
		num = 5;
	}
	else if (word == "six")
	{
		itsNum = true;
		num = 6;
	}
	else if (word == "seven")
	{
		itsNum = true;
		num = 7;
	}
	else if (word == "eight")
	{
		itsNum = true;
		num = 8;
	}
	else if (word == "nine")
	{
		itsNum = true;
		num = 9;
	}
	else
	{
		itsNum = false;
	}

	return itsNum;
}

bool TransToNum::checkArabia(char word) //�ƶ��� �������� Ȯ��.
{
	int c = (int)(word - '0');
	if (c == 0 || c == 1 || c == 2 || c == 3 || c == 4 || c == 5 || c == 6 || c == 7 || c == 8 || c == 9)
	{
		this->num = c;
		return true;
	}
	else
	{
		return false;
	}
}

int TransToNum::transform()
{
	for (int i = 0; index < str.size(); index = i) //����� �ܾ�� �߰� �� �ε��� ������Ʈ�� ���� ����
	{
		if (checkArabia(str[index]) == true) //�ƶ��� �����̸� �ٷ� �߰�
			;
		else //�ƶ��� ���ڰ� �ƴ� ��� �׻� ���� ����.
			do {
				i++;
				word = str.substr(index, i - index + 1);
				checkNum(word);
			} while (itsNum == false); //���ڶ� ��ġ�� ������

			result = result * 10 + num; //����� ���� �߰�.
			//reset
			word = "";
			itsNum = false;
			i++;
	}

	return this->result; //���ڸ� ��ȯ.
}

int solution(string s) { //���� ���⿡ transform�� ��¼�� ��¼��
	int answer = 0;

	TransToNum t = TransToNum(s);

	answer = t.transform();

	return answer;
}

/*
int main(void)
{
	string test = "one";
	char c = test[0];

	cout << solution("one4seveneight");
}
*/