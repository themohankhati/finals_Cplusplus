#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;


class Date
 {
 private:
    int month,day,year;
    char names[12][10]; //[num_months][name_size]
 public:
    Date(int d,int m,int y) //Parameterized constructor.
    {

      if(d>=1 && d<=31 && (m==1||m==3||m==5||m==7||m==8||m==10||m==12))
        {
            day=d;
            month=m;
            year=y;
        }
       else if (m==2 && d>=1 && d<=29 && y%4==0) // for leap year
       {
           day=d;
           month=m;
           year=y;
       }
      else if (m==2 && d>=1 && d<=28 && y%4!=0)//for common year
        {
            day=d;
            month=m;
            year=y;
        }
      else if (d>=1 && d<=30 && (m==4||m==6||m==9||m==11))
        {
            day=d;
            month=m;
            year=y;
        }
      else{
            cout<<"invalid input."; //invalid input cannot be accepted.
        }

    }

//member function setNames will assign names of month to the names array.
    void setNames()
    {
        strcpy(names[0],"January");
        strcpy(names[1],"February");
        strcpy(names[2],"March");
        strcpy(names[3],"April");
        strcpy(names[4],"May");
        strcpy(names[5],"June");
        strcpy(names[6],"July");
        strcpy(names[7],"August");
        strcpy(names[8],"September");
        strcpy(names[9],"October");
        strcpy(names[10],"November");
        strcpy(names[11],"December");
    }

    //1st pattern
    int showSampleA()
    {
        cout<<day<<"/"<<month<<"/"<<year<<endl;}

    //2nd pattern
    int showSampleB()
    {
        cout<<names[month-1]<<" "<<day<< ","<<year<<endl;
    }

    //3rd pattern
    int showSampleC()
    {
        cout<<day<<" "<<names[month-1]<<" "<<year<<endl;
    }
    // to display prefix and postfix.
     int displayDate()
            {
                cout<<names[month-1]<<" "<<day<<","<<year<<endl;
            }

    //prefix increment operator
    Date operator++()
    {

        //the date should be dec 31.
        if(day==31 && month==12)
        {
            day=1;
            month=1;
            ++year;
        }

        else
        {
            if ((month==1||month==3||month==5||month==7||month==8||month==10) && (day==31))
            {
                day=1;
                ++month;
            }
            else if ((month==4||month==6||month==9||month==11) && (day==30))
            {
                day=1;
                ++month;
            }
            else if (month==2 && (year%400==0||year%100!=0) && year%4==0 && day==29)//leap year
            {
                day=1;
                ++month;
                }
            else if(month==2 && !((year%400==0||year%100!=0) && year%4==0) && day==28)//common year
             {
                 day=1;
                ++month;
            }
            else
            {
                ++day;
            }
        }


    }
    //postfix increment operator
    Date operator++(int)
    {
        //the date should be dec 31.
        if(day==31 && month==12)
        {
            day=1;
            month=1;
            year++;
        }

        else
        {
            if ((month==1||month==3||month==5||month==7||month==8||month==10) && (day==31))
            {
                day=1;
                month++;
            }
            else if ((month==4||month==6||month==9||month==11) && (day==30))
            {
                day=1;
                month++;
            }
            else if (month==2 && (year%400==0||year%100!=0) && year%4==0 && day==29)//leap year
            {
               day=1;
               month++;
            }

            else if (month==2 && !((year%400==0||year%100!=0) && year%4==0) && day==28)//common year
            {
               day=1;
               month++;
            }
            else
            {
                day++;
            }
        }}

        //prefix decrement operator
        Date operator--()
        {
            if (day==1 && month==1) //month should be January.
            {
                day=31;
                month=12;
                --year;
            }
            else if ((month==2||month==4||month==6||month==8||month==9||month==11) && (day==1))
            {
                day=31;
                --month;
            }
            else if ((month==5||month==7||month==10||month==12) && (day==1))
            {
                day=30;
                --month;
            }
            else if (month==3 && (year%400==0||year%100!=0) && year % 4==0 && day==1)//leap year
            {
                day=29;
                --month;

            }
            else if (month==3 && !((year%400==0||year%100!=0) && year%4==0) && day==1)//common year
            {
                day=28;
                --month;
            }
            else
            {
                --day;
            }
        }
          //postfix decrement operator.
        Date operator--(int)
        {
            if (day==1 && month==1) //month should be January.
            {
                day=31;
                month=12;
                year--;
            }
            else if((month==2||month==4||month==6||month==8||month==9||month==11) && (day==1))
            {
                day=31;
                month--;
            }
            else if ((month==5||month==7||month==10||month==12) && (day==1))
            {
                day=30;
                month--;
            }
            else if  (month==3 && (year%400==0||year%100!=0)&& year%4==0 && day==1)//for leap year
            {
                day=29;
                month--;

            }

            else if (month==3 && !((year%400==0||year%100!=0) && year%4==0) && day==1)//common year
            {
                 day=28;
                 month--;
            }

            else
            {
                day--;
            }
        }
    //overloading subtraction operator.
    int operator-(Date &date)
        {
            int day_diff=day-date.day;
            int month_diff=month-date.month;
            int year_diff=year-date.year;
            int total_diff=year_diff*365+month_diff*30+day_diff;
            return total_diff;}
 };

int main()
{
    Date m1(31,12,1900);
    Date m2(12,12,1901);
    m1.setNames();
    m2.setNames();
    cout<<"\n\n..Dates in different format..\n";
    //will show the date in 1st pattern.
    m1.showSampleA();
    //will show the date in 2nd pattern.
    m1.showSampleB();
    //will show the date in 3rd pattern.
    m1.showSampleC();


    ++m1;
    cout<<"\nDate after prefix increment = ";//prefix increment
    m1.displayDate();
    m1++;
    cout<<"\nDate after postfix increment = ";//postfix increment
    m1.displayDate();
    --m1;
    cout<<"\nDate after prefix decrement = ";//prefix decrement
    m1.displayDate();
    m1--;
    cout<<"\nDate after postfix decrement = ";//postfix decrement
    m1.displayDate();


    cout<<"\n\n...after subtraction..."<<endl;//will gives num of days betn two dates.
    cout<<m2-m1;





}
