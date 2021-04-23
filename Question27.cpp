#include <iostream>
#include <string>

using namespace std;

int main()
{
    int cases;
    cin>>cases;
    for(int z=0;z<cases;++z){
        //Settings
        char bitmap[32][32];
        for(int i=0;i<32;++i){
            for(int j=0;j<32;++j)
                bitmap[i][j]='.';
        }
        int x,y;
        string instructions;
        cin>>x>>y;
        cin>>instructions;

        //Mapping
        for(int i=0; i<instructions.length()-1; ++i){
            switch(instructions[i]){
                case 'E':
                    bitmap[x][y-1] = 'X';
                    x++;
                    break;
                case 'N':
                    bitmap[x][y] = 'X';
                    y++;
                    break;
                case 'W':
                    bitmap[x-1][y] = 'X';
                    x--;
                    break;
                case 'S':
                    bitmap[x-1][y-1] = 'X';
                    y--;
            }
        }


        //Printing
        cout<<"Bitmap #"<<z+1<<endl;
        for(int i=0;i<32;++i){
            for(int j=0;j<32;++j){
                cout<<bitmap[j][31-i];
                if(j==31)cout<<endl;
            }
            if(i==31)cout<<endl;
        }
    }
    return 0;
}
