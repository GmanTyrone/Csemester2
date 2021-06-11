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
      return(partemonth+", "+parteday+", "+parteyear);
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
        if(isLeapYear(*this))maxdays=29;
        else maxdays=28;
      }
      if(day>maxdays){
        setDay(day-maxdays);
        addMonths(1);
        addDays(0);
      }
  }
protected:
  int year, month, day;
};


class TimeSpan
{
public:
  TimeSpan();
  TimeSpan(int d, int hh, int mm, int ss)
  {
      day=d;
      hour=hh;
      minute=mm;
      second=ss;
  };
  int toTotalDays()
  {
      return 0;
  };
  int toTotalHours();
  int toTotalMinutes();
  int toTotalSeconds();
  string toString();
private:
  int day=0, hour=0, minute=0, second=0;
};




class DateTime : public Date
{
public:
  virtual string toString() // "mm/dd/yyyy HH:MM:SS"
  {
      string partemonth=to_string(month);
      while(partemonth.length()<2)partemonth.insert(0,"0");
      string parteday=to_string(day);
      while(parteday.length()<2)parteday.insert(0,"0");
      string parteyear=to_string(year);
      while(parteyear.length()<4)parteyear.insert(0,"0");
      string partehour=to_string(hour);
      while(partehour.length()<2)partehour.insert(0,"0");
      string partemin=to_string(minute);
      while(partemin.length()<2)partemin.insert(0,"0");
      string parteseg=to_string(second);
      while(parteseg.length()<2)parteseg.insert(0,"0");
      return(partemonth+"/"+parteday+"/"+parteyear+" "+partehour+":"+partemin+":"+parteseg);
  }
  DateTime() : Date()
  {
    hour = 0;
    minute = 0;
    second = 0;
  }
  DateTime(int y, int m, int d, int hh=0, int mm=0, int ss=0) : Date(y, m, d)
  {
    hour = hh;
    minute = mm;
    second = ss;
  }
  void setHour(int h){hour=h;};
  void setMinute(int m){minute=m;};
  void setSecond(int s){second=s;};
  int getHour() const{return hour;};
  int getMinute() const{return minute;};
  int getSecond() const{return second;};
  void addHours(int h) // adds the specified number of hours to this instance
  {
      int protohours=hour+h;
      setHour(protohours%24);
      addDays(protohours/24);
  }
  void addMinutes(int m) // adds the specified number of minutes to this instance
  {
      int prominutes=minute+m;
      setMinute(prominutes%60);
      addHours(prominutes/60);
  }
  void addSeconds(int s) // adds the specified number of seconds to this instance
  {
      int protosec=second+s;
      setSecond(protosec%60);
      addMinutes(protosec/60);
  }
  TimeSpan operator-(const DateTime &dt) const // return a TimeSpan object represents a time interval
  {
      TimeSpan();
  }
  int toDays()
  {
      int total=day;
      int maxdays;
      int totalmonths=month;
      while(totalmonths>0){
            --totalmonths;
            switch(totalmonths)
            {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                maxdays=31;
                break;
            case 4: case 6: case 9: case 11:
                maxdays=30;
                break;
            case 2:
                if(isLeapYear(*this))maxdays=29;
                else maxdays=28;
                break;
            default:
                maxdays=0;
                break;
            }
      total+=maxdays;
      }
      total+=(365*(year-1));
      return total;
  }
private:
  int hour, minute, second;
};

int main() {
  int y, m, d, hh, mm, ss;
  cin>>y>>m>>d>>hh>>mm>>ss;
  DateTime d1(y, m, d, hh, mm, ss);
  cin>>y>>m>>d>>hh>>mm>>ss;
  DateTime d2(y, m, d, hh, mm, ss);
  cout<<(d1 - d2).toTotalSeconds();
  return 0;
}
