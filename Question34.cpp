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
        bool operator ==(Point point2){
            if(getX()==point2.getX()&&getY()==point2.getY())return true;
            return false;
        }
};

class Segment
{
public:
    Point point1,point2;
//public:
    Segment(){
    }
    Segment(Point c, Point d){
      	point1=c;
        point2=d;
    }
    float getLength(){
        return point1.getDistance(point2);
    };
    bool touch(Segment barra2){
        if(point1==barra2.point1||point1==barra2.point2||point2==barra2.point1||point2==barra2.point2)return true;
        return false;
    }
};

class Shape
{
public:
  Segment seg[10];
  int edgeCount;
  Shape();
  Shape(Segment *S, int n) // to construct a shape with a serial of segment.
  {
      if(closeshape(S,n)){
        edgeCount=n;
        for (int i =0;i<n;i++)seg[i] = Segment(S[i]);
      }
      else throw invalid_argument("");
  }
  bool closeshape(Segment *S,int n)
  {
      for (int i =0;i<n;i++)
      {
          for(int j =0;j<n;j++){
            if(j!=i){
                if(S[i].touch(S[j]))return true;
            }
          }
      }
      return false;
  }
  virtual float getArea() = 0;
  Segment &getSeg(int index)
  {
  	return seg[index];
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

/*class Rectangle : public Shape
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

class Triangle : public Shape
{
public:
    Triangle();
    Triangle(Segment *S, int n=4):Shape(S,n){
    }
    float getArea() //return the area of the rectangle
    {
        float s=getPerimeter()/2;
        return sqrt(s*(s-seg[0].getLength())*(s-seg[1].getLength())*(s-seg[2].getLength()));
    }
};*/

int main(void)
{
    return 0;
}
