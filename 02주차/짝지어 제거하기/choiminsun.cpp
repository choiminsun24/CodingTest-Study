#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    if (s.size() % 2 == 1)
        return 0;
    bool check = false;
    do {
        check = false;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1]) //��ġ�ϴ� �� �߰��ϸ� ����� �ٽ� ����.
            {
                s.erase(--i, 2);
                if (s.size() == 0) //����� size0�� �Ǹ� 1 return
                    return 1;
                check = true; //���� �� �����ϱ� �� �� �ٽ� �غ���~
            }
        }
    } while (check); //�� �� ���Ҵµ� ���� �� ����.

    return 0; //�� ������ ��. �ȵ�.
}