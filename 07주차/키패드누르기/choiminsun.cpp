#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> findout(char goal) //��ǥ�� ���� vector(��, ��) ��ȯ
{
    char key[4][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}, {'*', '0', '#'} };

    vector<int> position;

    for (int i = 0; i < sizeof(key) / sizeof(key[0]); i++)
    {
        for (int j = 0; j < sizeof(key[i]) / sizeof(char); j++)
        {
            if (key[i][j] == goal)
            {
                position.push_back(i);
                position.push_back(j);
                return position;
            }
        }
    }
}

char select(char l, char r, int goal)
{
    vector<int> g = findout(goal + '0'); //��ǥ������ ��ǥ
    vector<int> left = findout(l);
    vector<int> right = findout(r);

    int L = abs(g[0] - left[0]) + abs(g[1] - left[1]);
    int R = abs(g[0] - right[0]) + abs(g[1] - right[1]);

    if (L < R)
    {
        return 'L';
    }
    else if (L > R)
    {
        return 'R';
    }
    else
    {
        return 'S';
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    char left = '*';
    char right = '#';

    for (int i = 0; i < numbers.size(); i++)
    {
        int n = numbers[i];
        if (n == 1 || n == 4 || n == 7) //���� Ű�е�
        {
            answer += 'L';
            left = n + '0';
        }
        else if (n == 3 || n == 6 || n == 9) //������ Ű�е�
        {
            answer += 'R';
            right = n + '0';
        }
        else //�߾� Ű�е�
        {
            char s = select(left, right, n);
            if (s == 'L') //L�� ������ 
            {
                answer += 'L';
                left = n + '0';
            }
            else if (s == 'R')//R�� ������
            {
                answer += 'R';
                right = n + '0';
            }
            else
            {
                if (hand.compare("left") == 0)
                {
                    answer += 'L';
                    left = n + '0';
                }
                else
                {
                    answer += 'R';
                    right = n + '0';
                }
            }
        }
    }

    return answer;
}

int main()
{
    vector<int> i = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };
    string s = solution(i, "right");

    cout << s << endl;
}