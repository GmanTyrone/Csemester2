#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

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

class Segment
{
private:
    Point point1,point2;
public:
    Segment(){
        point1.setX(0);
      	point1.setY(0);
        point2.setX(0);
        point2.setY(0);
    }
    Segment(Point c, Point d){
        point1.setX(c.getX());
      	point1.setY(c.getY());
        point2.setX(d.getX());
        point2.setY(d.getY());
    }
    float getLength(){
        return point1.getDistance(point2);
    };
    Point *getIntersect(Segment s){
        float Ax=point1.getX();
        float Ay=point1.getY();
        float Bx=point2.getX();
        float By=point2.getY();
        float Cx=s.point1.getX();
        float Cy=s.point1.getY();
        float Dx=s.point2.getX();
        float Dy=s.point2.getY();
        float t=((Ax-Cx)*(Cy-Dy)-(Ay-Cy)*(Cx-Dx))/((Ax-Bx)*(Cy-Dy)-(Ay-By)*(Cx-Dx));
        float u=((Bx-Ax)*(Ay-Cy)-(By-Ay)*(Ax-Cx))/((Ax-Bx)*(Cy-Dy)-(Ay-By)*(Cx-Dx));
        if((Ax==Cx&&Ay==Cy)||(Ax==Dx&&Ay==Dy)){
            Point *w = new Point;
            w->setX(Ax);
            w->setY(Ay);
            return w;
        }
        else if((Bx==Cx&&By==Cy)||(Bx==Dx&&By==Dy)){
            Point *w = new Point;
            w->setX(Bx);
            w->setY(By);
            return w;
        }
        else if((t>=0&&t<=1)&&(u>=0&&u<=1)){
            Point *w = new Point;
            float Px=(Ax+t*(Bx-Ax));
            float Py=(Ay+t*(By-Ay));
            w->setX(Px);
            w->setY(Py);
            return w;
        }
        else return nullptr;
    }
};
