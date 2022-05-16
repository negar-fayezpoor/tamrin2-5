// This program has an error
#include <iostream>
#include <cstdlib>

using namespace std;

class Time {
    int min;
    int hour;
public:
    Time();
    Time(int m , int h);
    Time(int h);
    void set_time(int m , int h);
    int get_minute(){return min;}
    int get_hour(){return hour;}
    int compare (Time t2);
    string TimeofDay();

};

Time::Time(){
    hour = 0;
    min = 0;
}

Time::Time(int h , int m){
    hour = h;
    min = m;
}

Time::Time(int h){
    hour = h;
    min = 0;
}

void Time::set_time(int h, int m){
    if (h < 0 || h > 23 || m < 0 || m > 59)
        abort();
    hour = h;
    min = m;
}

int Time::compare(Time t2){
    if((hour == t2.hour) && (min == t2.min))
        return 0;
    else if ((hour > t2.hour) || ((hour == t2.hour) && (min > t2.min)))
        return 1;

    return -1;
}

string Time::TimeofDay(){
    string result = "";
    if (hour < 12)
        result = "Morning";
    else if (hour == 12)
        result = "Non";
    else if (hour > 12 && hour < 17)
        result = "Afternon";
    else if (hour >= 17 && hour < 20)
        result = "Evening";
    else
        result = "Night";
    return result;
}

int main()
{
   Time start (16 , 20);
   Time end (16 , 20);
   if (end.compare(start) == 1){
   cout << "You started on " << start.TimeofDay()
        << " (" << start.get_hour() << ":" << start.get_minute() << ")";
   cout << "\nand finished on " << end.TimeofDay()
        << " (" << end.get_hour() << ":" << end.get_minute() << ")";
   }
   else if (end.compare(start) == 0)
       cout << "You have not worked for us";
   else
       cout << "invalid";

   getchar();
    return 0;
}







