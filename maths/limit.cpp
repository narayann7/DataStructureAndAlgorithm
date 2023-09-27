#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <math.h>
// if you don't know what is the useses of limit in math, can visit here https://en.wikipedia.org/wiki/Limit_(mathematics)
//Creator: MarufHasan24
using namespace std;
double limit(int tt, double (*fc)(float))
{
  int n;
    double a = pow(10,-7);
    double lim = (fc(tt - a) + fc(tt + a)) / 2;
    return lim;
}
/* double func(float x){
        return ((x*x)-1)/(x-1);
    } */
// Pass a function like `func` which return a double type value and can recive float type value.
int main(){
  //cout << limit(1, func) << endl;
    return 0;
}
