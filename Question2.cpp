#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int x;
    cin>>x;
    for(int i=0;i<4;++i){
        cout<<x%10;
        x/=10;
    }
    return 0;
}
