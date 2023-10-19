#include "Trip.h"
#include <iostream>
#include <cctype>


Trip::Trip() : tripNumber(0), destination(""), date() {}

Trip::Trip(int tripNumber, const std::string& destination, const Date& date)
    : tripNumber(tripNumber), destination(destination), date(date) {}


int Trip::getTripNumber() const {
    return tripNumber;
}

std::string Trip::getDestination() const {
    return destination;
}

Date Trip::getDate() const {
    return date;
}


void Trip::setTripNumber(int tripNumber) {
    if (tripNumber > 0) {
        this->tripNumber = tripNumber;
    }
}

void Trip::setDestination(const std::string& destination) {
    bool isOnlyLetters = true;
    for (char ch : destination) {
        if (!isalpha(ch)) {
            isOnlyLetters = false;
            break;
        }
    }

    if (isOnlyLetters) {
        this->destination = destination;
    }
    else {
        std::cout << "Error: Destination can only contain letters." << std::endl;
    }
}

void Trip::setDate(const Date& date) {
    this->date = date;
}


void Trip::printTrip() const {
    std::cout << "Trip Number: " << tripNumber << std::endl;
    std::cout << "Destination: " << destination << std::endl;
    std::cout << "Date: ";
    date.printDate();
}


Trip& Trip::operator=(const Trip& other) {
    if (this != &other) {
        tripNumber = other.tripNumber;
        destination = other.destination;
        date = other.date;
    }
    return *this;
}


Trip::Trip(const Trip& other) : tripNumber(other.tripNumber), destination(other.destination), date(other.date) {}


Trip::~Trip() 
{
  
}
