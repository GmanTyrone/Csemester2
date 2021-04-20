class bar3d
{
  public: float width, height, depth;
  bar3d(){
    width=0;
    height=0;
    depth=0;
  }
  bar3d(float a, float b, float c){
    if(a>0&&a<1000&&b>0&&b<1000&&c>0&&c<1000){
      width=a;
      height=b;
      depth=c;
    }
    else{
      width=0;
      height=0;
      depth=0;
    }
  }
  float getVolume(){
  return width*height*depth;
  }
  void scale(float x){
  width*=x;
  height*=x;
  depth*=x;
  }
  float addVolume (bar3d x){
  return x.getVolume()+getVolume();
  }
};

int main(void)
{
    return 0;
}
