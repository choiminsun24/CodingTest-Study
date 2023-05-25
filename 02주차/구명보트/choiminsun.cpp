#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end(), greater<>());

    for (int i = 0; people[i] == limit; i++)
    {
        answer++;
    }

    for (int i = answer; i < people.size(); i++)
    {
        int limitNew = limit - people[i];
        //for (int j = i + 1; j < people.size(); j++)
        for (int j = people.size() - 1; j > i; j--)
        {
            if (people[j] > limitNew)
                break;
            else if (people[j] == limitNew || (people[j] < limitNew && (j - 1 <= i || people[j - 1] > limitNew))) //���ų� ���� ģ���� ����ġ ������ �� �����
            {
                people.erase(people.begin() + j); //���� ���
                break;
            }
        }
        answer++;
    }

    return answer;
}