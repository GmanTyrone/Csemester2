#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Point
{
    private: float x, y;
    public:
        Point(){
            x=0;
            y=0;
        }
        Point(float a, float b){
            x=a;
            y=b;
        }
        void printPoint(){
            cout<<"("<<x<<", "<<y<<")";
        }
        float getX(){
            return x;
        }
        float getY(){
            return y;
        }
        void setX(float equis){
            x=equis;
        }
        void setY(float ye){
            y=ye;
        }
        float getDistance(Point punto2){
        return sqrt((getX()-punto2.getX())*(getX()-punto2.getX())+(getY()-punto2.getY())*(getY()-punto2.getY()));
        }
};





int main(void)
{
    return 0;
}
