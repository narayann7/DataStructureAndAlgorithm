// for understanding basic of recursion

#include <iostream>
#include <cstring>  
using namespace std;

void noOfPossibleStrings(string str1, string str2, int index)
{
if(index==str1.length())
{
cout<<str2<<" ";
return;
}
    noOfPossibleStrings(str1, str2, index+1);
   
    noOfPossibleStrings(str1, str2+str1[index], index+1);
}
int reverseString(string ch ,int s, int e) // reverse a string using recursion
{
    if (s == e || s > e)
        return 1;
    if (ch.at(s) != ch.at(e))
        return 0;
    return (ch, s + 1, e - 1);
}
int Fibonacci(int n) //
{
    if (n == 0 || n == 1)
        return 0;
    if (n == 2)
        return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}
int sumOfEachDigit(int n)
{
    if (n < 10)
        return n;
    return sumOfEachDigit(n / 10) + n % 10;
}
void towerOfHanoi(int n, char A, 
                    char B, char C)  
{  
    if (n == 0)  
    {  
       
        return;  
    }  
    towerOfHanoi(n - 1, A, C, B);  
    cout << "Move disk " << n << " from rod " << A << 
                                " to rod " << B << endl;  
    towerOfHanoi(n - 1, C, B, A);  
}  


int main() {
    string str;int n;
    
    

    while(true)
    {
    cout<<"\n1 for pallindrome\n";
    cout<<"2 for fibonacci\n";
    cout<<"3 for sum of each digit\n";
    cout<<"4 for no. of possible strings\n";
    cout<<"5 for tower of hanoi\n";
    cout<<"enter the choice\n";
    int ch;
    cin>>ch;

    switch (ch)
    {
    case 1:

        cout<<"enter a String\n";

        cin>>str;

        if (reverseString(str, 0, str.length() - 1))
cout<<"given string is pallindrome\n";
        else
cout<<"given string is not pallindrome\n";

        break;
    case 2:
cout<<"enter a nth term for Fibonacci Sequence\n" ;
       cin>>n;
        int i;
        cout<<"Fibonacci Sequence is -> ";
        for (i = 1; i <= n; i++)
        {
 
           cout<<Fibonacci(i)<<" ";
        }
        break;

    case 3:
        cout<<"enter a number\n";
        cin>>n;
        cout<<"the sum of each digit = \n"<< sumOfEachDigit(n);
        break;
    case 4:
        cout<<"enter a String\n";

        cin>> str;
            noOfPossibleStrings(str," ",0);
            break;
            case 5:
            cout<<"enter a number\n";
        cin>>n;
        towerOfHanoi(n,'A','B','C');
break;


    default:
        break;
    }

    }
    return 0;
}