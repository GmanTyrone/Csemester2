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
        return;
    }
    Segment(Point c, Point d){
        point1=Point(c.getX(),c.getY());
        point2=Point(d.getX(),d.getY());
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
        float dem=(Ax-Bx)*(Cy-Dy)-(Ay-By)*(Cx-Dx);
        float t=((Ax-Cx)*(Cy-Dy)-(Ay-Cy)*(Cx-Dx))/dem;
        float u=((Bx-Ax)*(Ay-Cy)-(By-Ay)*(Ax-Cx))/dem;
        if((Ax==Cx&&Ay==Cy)||(Ax==Dx&&Ay==Dy)){
            return &point1;
        }
        else if((Bx==Cx&&By==Cy)||(Bx==Dx&&By==Dy)){
            return &point2;
        }
        else if((t>=0&&t<=1)&&(u>=0&&u<=1)){
            float Px=(Ax+t*(Bx-Ax));
            float Py=(Ay+t*(By-Ay));
            return new Point(Px,Py);
        }
        else return NULL;
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
    bool isCollision(const Rectangle Marco){
        bool flag=false;
        for(Segment x: this->seg){
            for(Segment y:Marco.seg){
                    if(x.getIntersect(y)!=nullptr)flag=true;
            }
        }
        return flag;
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
};

int main(void)
{
    return 0;
}
