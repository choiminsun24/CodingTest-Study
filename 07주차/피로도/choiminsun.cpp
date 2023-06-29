#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<bool> visit;

int count(vector<bool> v)
{
    int c = 0;

    for (bool b : v)
    {
        if (b == true)
            c++;
    }

    return c;
}

int search(int k, vector<vector<int>> dungeons)
{
    int answer = 0;

    for (int i = 0; i < dungeons.size(); i++)
    {
        if (visit[i] == false && k >= dungeons[i][0]) //�湮 ����
        {
            visit[i] = true;
            answer = max(answer, search(k - dungeons[i][1], dungeons)); //���� �湮�� �̹� �湮 ��
            visit[i] = false; //���� ��츦 ���� �湮 ���
        }

        if (answer == dungeons.size())
            return answer;
    }

    return max(answer, count(visit)); //�̹� ������ ���� ū �湮 ��
}

int solution(int k, vector<vector<int>> dungeons)
{
    visit.resize(dungeons.size(), false);

    return search(k, dungeons);
}