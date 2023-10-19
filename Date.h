#ifndef DATE_H
#define DATE_H

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date();
    Date(int day, int month, int year); 

   
    int getDay() const;
    int getMonth() const;
    int getYear() const;

   
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);

    
    void printDate() const;
};

#endif 
