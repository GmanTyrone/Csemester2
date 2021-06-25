#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

void Boom();
int employees[2500][2500]={{0}};

int main(void)
{
    //Takes the number of employees
    int EmpNum,T, M=0,D=0;
    cin>>EmpNum;


    //Fills the friendship map
    for(int i=0;i<EmpNum;++i){
        int Nmployefriends;
        cin>>Nmployefriends;
        for(int j=0;i<Nmployefriends;++j){
            int x;
            cin>>x;
            employees[x][i]=1;
        }
    }

    //EmpNum constant thru this
    //checks the employee source
    vector <int>cola;
    vector <int>cola2;
    int Origen;
    cin>>Origen;
    cola.push_back



    return 0;
}
