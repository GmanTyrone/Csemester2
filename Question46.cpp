#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int main() {
    //n is x and m is y, for size of grid
    int n, m;

    //Initial positions of the robot
    int xo, yo;

    //Orientation of the robot
    char D[2];

    //instrucciones is instructions
    string instrucciones;
    char pre[100][100] = {};

    //scans the size of the grid
    cin>>n>>m;

    //scans the initial position and orientation of the robots. While there are to scan
    while(scanf("%d %d %s", &xo, &yo, D) == 3) {

        //scans the instructions string
        cin>>instrucciones;

        int direccion = D[0];
        bool flag = false;
        for(int i = 0; instrucciones[i]; i++) {
            //Advances
            if(instrucciones[i] == 'F') {
                switch(direccion) {
                    case 'N':yo++;break;
                    case 'E':xo++;break;
                    case 'W':xo--;break;
                    case 'S':yo--;break;
                }

            //Turns Right
            } else if(instrucciones[i] == 'R') {
                switch(direccion) {
                    case 'N':direccion = 'E';break;
                    case 'E':direccion = 'S';break;
                    case 'W':direccion = 'N';break;
                    case 'S':direccion = 'W';break;
                }

            //Turns Left
            } else {
                switch(direccion) {
                    case 'N':direccion = 'W';break;
                    case 'E':direccion = 'N';break;
                    case 'W':direccion = 'S';break;
                    case 'S':direccion = 'E';break;
                }
            }

            //Checks if it goes out of boundaries
            if(xo < 0 || yo < 0 || xo > n || yo > m) {
                switch(direccion) {
                    case 'N':yo--;break;
                    case 'E':xo--;break;
                    case 'W':xo++;break;
                    case 'S':yo++;break;
                }
                if(pre[xo][yo] == 1)
                    continue;
                flag = 1;
                pre[xo][yo] = 1;
                break;
            }
        }
        cout<<xo<<" "<<yo<<" "<<(char)direccion;
        if(flag)cout<<" LOST";
        /*if(!flag)
            printf("%d %d %c\n", xo, yo, direccion);
        else {
            printf("%d %d %c LOST\n", xo, yo, direccion);
        }*/
        cout<<endl;
    }
    return 0;
}
