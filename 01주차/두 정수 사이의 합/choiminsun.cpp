//2023.05.10
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int a, int b) {
    long long answer = 0;

    //1. a�� b���� Ŭ ���
    if (a > b)
    {
        for (int i = b; i <= a; i++)
        {
            answer += i;
        }
    }
    //2. a�� b���� �۰ų� ���� ���
    else
    {
        for (int i = a; i <= b; i++)
        {
            answer += i;
        }
    }

    return answer;
}