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
        else return nullptr;
    }
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

class Square : public Shape
{
public:
  Square(Segment *seg) : Shape(seg, 4)
  {
  }
  float getArea()
  {
    return seg[0].getLength() * seg[0].getLength();
  }
};

class Rectangle : public Shape
{
public:
    Rectangle();
    Rectangle(Segment *S):Shape(S,4){
    }
    float getArea() //return the area of the rectangle
    {
        return((getPerimeter()-2*seg[0].getLength())*seg[0].getLength()/2);
    }
    bool isCollision(const Rectangle Marco){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                    if(seg[i].getIntersect(Marco.seg[j]))return true;
            }
        }
        return false;
    }
};

int main() {
  Point p1(0, 0), p2(10, 0), p3(10, 0), p4(10, 10), p5(10, 10), p6(0, 10), p7(0, 10), p8(0, 0);
  Point p9(5, 5), p10(15, 5), p11(15, 5), p12(15, 15), p13(15, 15), p14(5, 15), p15(5, 15), p16(5, 5);
  Segment s[4] = {Segment(p1, p2), Segment(p3, p4), Segment(p5, p6), Segment(p7, p8)};
  Segment s2[4] = {Segment(p9, p10), Segment(p11, p12), Segment(p13, p14), Segment(p15, p16)};
  Point p17(0, 0), p18(10, 0), p19(10, 0), p20(10, 10), p21(10, 10), p22(0, 10), p23(0, 10), p24(0, 0);
  Point p25(15, 15), p26(15, 20), p27(15, 20), p28(20, 20), p29(20, 20), p30(20, 15), p31(20, 15), p32(15, 15);
  Segment s3[4] = {Segment(p17, p18), Segment(p19, p20), Segment(p21, p22), Segment(p23, p24)};
  Segment s4[4] = {Segment(p25, p26), Segment(p27, p28), Segment(p29, p30), Segment(p31, p32)};
  Rectangle r1(s), r2(s2), r3(s3), r4(s4);
  cout<<r1.isCollision(Rectangle(s2))<<std::endl;
  cout<<r3.isCollision(Rectangle(s4))<<std::endl;
  return 0;
}
