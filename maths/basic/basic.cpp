#include <bits/stdc++.h>
using namespace std;

// extras--------------

// x=round(x*100)/100; //gives double up to 2 decimal places;

// ap=a+0*d,a+1*d,a+2*d...................a+(n-1)*d //d is comman difference ,a is first term , n is last term
// sum= n/2(2a+(n-1)d) //sum of ap

// gp is ratio of 2 conisucative no.s is same throught the series
// ex 2,4,8,16,32............

// so ar^0,ar^1,ar^2,ar^3,ar^4...............a*(r^(n-1)) // a is first term r is ratio between 2 conisucative no.s
// sum= a(1-r^n)/1-r

// sum of sq 1^2 +2^2 +3^2=14 n(n+1)(2n+1)/6

// for no of trailing zeros count n/5+ n/5*2 + n/5*3.......up to 5*i <=n



void sieveprime(int n) {
    //using hashing
    int arr[] = new int[n + 1];

    arr[0] = arr[1] = 0;
    arr[2] = 1;

    /*making all odd no.s prime
    because all even nos eexpect 2 is not prime we know that so making all odd no. prime
    */
    for (int i = 3; i <= n; i += 2)
        arr[i] = 1;

    for (int i = 3; i <= n; i += 2) {
        for (int j = i * i; j <= n; j += i * 2)
            arr[j] = 0; //making the multipiles of odd no. as not prime

    }

    for (int i = 1; i <= 100; i++) {
        if (arr[i] != 0)
            cout<<i<<" ";

    }


}


void sqrootWithOutSqFunction(double n)//newton raphson method
{
    /*
    this method is called newton raphson method
    sqroot(n)=x,
    x^2=n,   f(x)=x^2-n, f'(x)= 2x,   x^2-n=0,
    X(n+1)=Xn - f(Xn)/f'(Xn) , X(n+1)= Xn - ((Xn)^2-n)/2Xn

    by sloving X(n+1)= 1/2*(  ((Xn)^2)+n)/Xn  ) , = 0.5*(Xn+ n/Xn )

    when X(n+1)==Xn , then Xn is the sqroot of n

    */

    double ans = n / 2, ans1 = 0;
    while (!(ans == ans1))
    {
        ans1 = ans;
        ans = 0.5 * (ans + n / ans);
    }
    cout << ans << endl;
}

int powerOfNo(int a, int b) //gives power in terms size of bit in b
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1 == 1)
        {
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }
    return ans;
}

int gcd(int a, int b) //eculids algo
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
} //gcd *lcm=a*b, so lcm=a*b/gcd

int count(int n)
{
    return floor(log10(n) + 1);
}

//creator: MarufHasan24
double factorial(int n){
    if(n==0){
        return 1;
    }
    return n*factorial(n-1);
}// factorial of any number using recursive function

int main()
{
    // cout << "hello" << endl;
    // cout << gcd(8, 32) << endl;
    // cout << count(6578) << endl;
    // cout << powerOfNo(3, 5) << endl;
    // sqrootWithOutSqFunction(6.2);
    // factorial(124)
    return 0;
}
