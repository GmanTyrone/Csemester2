#include <iostream>
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
    }
    Segment(Point c, Point d){
      	point1=c;
        point2=d;
    }
    float getLength(){
        return point1.getDistance(point2);
    };
};

class Shape
{
public:
  Segment seg[10];
  int edgeCount;
  Shape();
  Shape(Segment *S, int n) // to construct a shape with a serial of segment.
  {
      edgeCount=n;
      for (int i =0;i<n;i++)
        {
            seg[i] = Segment(S[i]);
        }
  }
  float getPerimeter() //return the perimeter of the shape
  {
      float perimeter=0;
      for(int i=0;i<edgeCount;++i){
        perimeter+=seg[i].getLength();
      }
      return perimeter;
  }
};

class Rectangle : public Shape
{
public:
    Rectangle();
    Rectangle(Segment *S, int n=4):Shape(S,n){
    }
    float getArea() //return the area of the rectangle
    {
        return(getPerimeter()-2*seg[0].getLength())*seg[0].getLength()/2;
    }
};

int main(void)
{
    return 0;
}
