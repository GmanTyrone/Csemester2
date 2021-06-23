#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int mapa[7][3]={{8,8,8},
                {8,8,8},
                {8,8,8},
                {8,8,9},
                {8,9,10},
                {8,10,10},
                {8,9,9}};
string days[7]={"SUN","MON","TUE","WED","THU","FRI","SAT"};

int main(void)
{
    int n,x=0,y=0;
    cin>>n;
    while(n>0){
        string month, day;
        x=0;
        cin>>month>>day;
        if(month=="FEB")y=0;
        else if(month=="APR"||month=="JUN"||month=="SEP"||month=="NOV")y=1;
        else y=2;
        for(int i=0;i<7;++i)x=i+1;
    };
    return 0;
}
