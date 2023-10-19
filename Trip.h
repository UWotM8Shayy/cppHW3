#ifndef TRIP_H
#define TRIP_H

#include "Date.h"
#include <string>

class Trip {
private:
    int tripNumber;
    std::string destination;
    Date date;

public:
    
    Trip();
    Trip(int tripNumber, const std::string& destination, const Date& date);

    
    int getTripNumber() const;
    std::string getDestination() const;
    Date getDate() const;

    
    void setTripNumber(int tripNumber);
    void setDestination(const std::string& destination);
    void setDate(const Date& date);

    
    void printTrip() const;

    
    Trip& operator=(const Trip& other);

    
    Trip(const Trip& other);

    
    ~Trip();
};

#endif 
