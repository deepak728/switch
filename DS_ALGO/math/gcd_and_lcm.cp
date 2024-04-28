#include <bits/stdc++.h>
using namespace std;

int gcd (int a, int b) {
    if (b == 0) // will handle all the edge cases
        return a;
    else
        return gcd (b, a % b);
}

int lcm(int a,int b){
    //using property a*b=gcd(a,b)*lcm(a,b);
    return a/gcd(a,b)*b;  // to avoid overflow.
}
int main() {
   
    cout << abs(gcd(12,16))<<endl;
    cout<< abs(lcm(-12,16));
}