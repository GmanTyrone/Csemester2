#include<stdlib.h>
#include<math.h>
#include<stdexcept>
#include<iostream>
using namespace std;
class Point
{
    public:
        float x;
        float y;
        Point (){
            x=0;
            y=0;
        }
        Point (float a,float b){
            setX(a);
            setY(b);
        }
        void printPoint(){
            cout<<"("<<x<<", "<<y<<")";
        }
        float getX(){
            return x;
        }
        void setX(float c){
            x=c;
        }
        float getY(){
            return y;
        }
        void setY(float d){
            y=d;
        }
        float getDistance(Point e){
            float deltaX, deltaY, distance;
            deltaX=x-e.getX();
            deltaX*=deltaX;
            deltaY=y-e.getY();
            deltaY*=deltaY;
            distance=sqrt(deltaX+deltaY);
            return distance;
        }
};
class Segment
{
public:
        Point point1;
        Point point2;
        Segment(){
            point1.setX(0);
            point1.setY(0);
            point2.setX(0);
            point2.setY(0);
        }
        Segment(Point p1,Point p2){
            point1.setX(p1.getX());
            point1.setY(p1.getY());
            point2.setX(p2.getX());
            point2.setY(p2.getY());
        }
        float getLength(){
            return point1.getDistance(point2);
        }
};
class Shape
{
    public:
        Segment seg[10];
        int edgeCount;
        Shape(){
            for(int i=0;i<10;i++){
                seg[i].point1.setX(0);
                seg[i].point1.setY(0);
                seg[i].point2.setX(0);
                seg[i].point2.setY(0);
            }
            edgeCount=0;
        }
        Shape(Segment *segment1, int cnt){
            edgeCount=cnt;
            for(int i=0;i<cnt;i++){
                seg[i]=segment1[i];
            }
            for(int j=0;j<cnt-1;j++){
                if(seg[j].point2.getX()!=seg[j+1].point1.getX()&&seg[j].point2.getY()!=seg[j+1].point1.getY()&&seg[cnt-1].point2.getX()!=seg[0].point1.getX()&&seg[cnt-1].point2.getY()!=seg[0].point1.getY())
                    throw invalid_argument("");
            }
        }
        virtual float getArea() = 0;
        float getPerimeter(){
            float perimeter=0;
            for(int i=0;i<edgeCount;i++){
                perimeter+=seg[i].getLength();
            }
            return perimeter;
        }
        Segment getSeg(int index) const
        {
            return seg[index];
        }
};
class Square : public Shape
{
public:
    Square(Segment *seg) : Shape(seg, 4){
    }
    float getArea()
    {
        return seg[0].getLength() * seg[0].getLength();
    }
};
class Rectangle : public Shape
{
public:
    Rectangle(Segment *seg):Shape(seg, 4){
    }
    float getArea(){
    float area=1;
    for(int i=0;i<4;i++){
            area*=seg[i].getLength();
    }
    area=sqrt(area);
        return area;
    }
    bool isCollision(const Rectangle &rectangle){
        float maxX=getSeg(0).point1.getX();
        float minX=getSeg(0).point1.getY();
        float maxY=getSeg(0).point1.getX();
        float minY=getSeg(0).point1.getY();
        for(int i=0;i<4;i++){
            if(getSeg(i).point1.getX()>maxX){
                maxX=getSeg(i).point1.getX();
            }
            if(getSeg(i).point1.getY()>maxY){
                maxX=getSeg(i).point1.getY();
            }
            if(getSeg(i).point1.getX()<minX){
                minX=getSeg(i).point1.getX();
            }
            if(getSeg(i).point1.getY()>minY){
                minY=getSeg(i).point1.getY();
            }
        }
        float RmaxX=rectangle.getSeg(0).point1.getX();
        float RminX=rectangle.getSeg(0).point1.getY();
        float RmaxY=rectangle.getSeg(0).point1.getX();
        float RminY=rectangle.getSeg(0).point1.getY();
        for(int i=0;i<4;i++){
            if(rectangle.getSeg(i).point1.getX()>RmaxX){
                RmaxX=rectangle.getSeg(i).point1.getX();
            }
            if(rectangle.getSeg(i).point1.getY()>RmaxY){
                RmaxX=rectangle.getSeg(i).point1.getY();
            }
            if(rectangle.getSeg(i).point1.getX()<RminX){
                RminX=rectangle.getSeg(i).point1.getX();
            }
            if(rectangle.getSeg(i).point1.getY()>minY){
                RminY=rectangle.getSeg(i).point1.getY();
            }
        }
        if(minX==maxX||maxY==RminY||RminX==RmaxX||RmaxY==RminY){
            return false;
        }
        if(minX>=RmaxX||RminX>=maxX){
            return false;
        }
        if(minY>=RmaxY||RminY>=maxY){
            return false;
        }
        return true;

    }
};
