#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size(); //�� �Ҿ�������� ���� �� �Ա�

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    int l = 0; //lost�� �ε���
    int r = 0; //reserve�� �ε���

    for (; l < lost.size(); l++)
    {
        for (; r < reserve.size(); r++)
        {
            if (reserve[r] < lost[l] - 1) //1. ������ ������ �ƹ��� �� �Ծ�
                continue;
            else if ((reserve[r] >= (lost[l] - 1)) && (reserve[r] <= (lost[l] + 1))) //2. ���� �� �ִ� ü������ �ֱ��ѵ�
            {
                //1. ������ ���� ������ -> ���� ����� �� �� �ƴ���.
                if (reserve[r] == lost[l] - 1)
                {
                    if (r + 1 < reserve.size() && reserve[r + 1] == lost[l])
                        continue;
                }
                //2. ���� ���� -> �� �Ծ�
                //3. ������ ū ������ -> �� ���� ģ�� ������� �ƴ���.
                if (reserve[r] == lost[l] + 1)
                {
                    if (l + 1 < lost.size() && lost[l + 1] == reserve[r])
                        break;
                }
                if ((l + 1 < lost.size()) && (reserve[r] == lost[l + 1]))
                {
                    break;
                }
                answer++;
                r++;
            }
            break;
        }
    }
    return answer;
}