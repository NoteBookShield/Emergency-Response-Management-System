#include <stdio.h>
int main()
{
    int n, t, count;
    char s[101];
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        count = 0;
        scanf("%d", &n);
        scanf("%s", s);
        if (s[0] == 'B')
        {
            count++;
        }

        for (int j = 1; j < n; j++)
        {
            if (s[j] == s[j - 1])
            {
                count++;
            }
        }
        printf("%d\n", count);
    }
}