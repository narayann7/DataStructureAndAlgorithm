#include <stdio.h>
#include <string.h>

// Q) Set of all strings over ∑={0,1} having only even no of 0‟s.

// this is the starting state of DFA
int dfa = 0;

// finite machine state q0
void q0(char c)
{
    if (c == '0')
        dfa = 1;
    else if (c == '1')
        dfa = 0;
    else
        dfa = -1;
}

// finite machine state q1
void q1(char c)
{
    if (c == '0')
        dfa = 0;
    else if (c == '1')
        dfa = 1;
    else
        dfa = -1;
}

// function to check the given string
int isAccepted(char str[])
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (dfa == 0)
            q0(str[i]);
        else if (dfa == 1)
            q1(str[i]);
        else
            return 0;
    }
    if (dfa == 0)
        return 1;
    else
        return 0;
}

int main()
{
    char str[50];
    printf("Enter String: ");
    scanf("%s", str);

    if (isAccepted(str))
        printf("%s is ACCEPTED\n", str);
    else
        printf("%s is REJECTED\n", str);

    return 0;
}