#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class Date
{
public:
  Date()
  {
    year = 1;
    month = 1;
    day = 1;
  }
  Date(int y, int m, int d)
  {
    year = y;
    month = m;
    day = d;
  }
  virtual string toString() // "mm, dd, yyyy"
  {
      string partemonth=to_string(month);
      while(partemonth.length()<2)partemonth.insert(0,"0");
      string parteday=to_string(day);
      while(parteday.length()<2)parteday.insert(0,"0");
      string parteyear=to_string(year);
      while(parteyear.length()<4)parteyear.insert(0,"0");
      return(partemonth+",  "+parteday+",  "+parteyear);
  }
  void setDay(int d){day=d;};
  void setMonth(int m){month=m;};
  void setYear(int y){year=y;};
  int getDay() const {return day;};
  int getMonth() const{return month;};
  int getYear() const{return year;};
  static bool isLeapYear(const Date &d)
  {
    if((d.year%4==0&&d.year%100!=0)||d.year%400==0)return true;
    return false;
  };
  void addYears(int y) // adds the specified number of years to this instance
  {
      year+=y;
      addMonths(0);
  };
  void addMonths(int m) // adds the specified number of months to this instance
  {
      setMonth(month+m);
      if(month>12){
        setMonth(month-12);
        addYears(1);
        addMonths(0);
      }
      addDays(0);
  };
  void addDays(int d)// adds the specified number of days to this instance
  {
      int maxdays=30;
      setDay(day+d);
      switch(month)
      {
      case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        maxdays=31;
        break;
      case 4: case 6: case 9: case 11:
        maxdays=30;
        break;
      case 2:
        if(Bisiesto())maxdays=29;
        else maxdays=28;
      }
      if(day>maxdays){
        setDay(day-maxdays);
        addMonths(1);
        addDays(0);
      }
  }
private:
  int year, month, day;
  bool Bisiesto()
  {
    if((year%4==0&&year%100!=0)||year%400==0)return true;
    return false;
  };
};

int main() {
  int n;
  Date d(2020, 2, 1);
  cout<<d.toString()<<endl;
  cin>>n;
  d.addDays(n);
  cout<<d.toString()<<endl;
  cin>>n;
  d.addMonths(n);
  cout<<d.toString()<<endl;
  cin>>n;
  d.addYears(n);
  cout<<d.toString()<<endl;
  return 0;
}
