#ifndef COSTUMER_H
#define COSTUMER_H
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctype.h>
#include <cstdlib>
#include <windows.h>
#include <unistd.h>

using namespace std;

class Costumer
{
    public:
        Costumer();
        Costumer(int);
        string getName();
        int getNoOfPeople();
        int getTimeOfBooking();
        void checkOut(string, int);
        int getTimeOfCheckOut();
        void getDurationOfStay(int);
        int giveRoom(int);
        void getRoom();
        void takeABottle(int);
        int getFloorGiven();
        void getNoOfBottlesAvailable(int);
        void getBottlesDrank(int);
        int refillRefrigerator(int);
        int totalBill();
        void getCostumerDetailsFromFile();
        void namesOfPeopleInHotel();
        void removeNameFromList(string,int);
        void removeRoomFromList(int);
        void peopleInRoom(int);
        int removeBottlesFromList(int);
        int removeBottlesDrankFromList(int);
        int removeBookingTimeFromList(int);
        void personLivingInRoom(int);
        void addBottlestoFile(int ,int );
        void getBottlesFromFile();

    protected:

    private:
        string names[1000];
        string dob[1000];
        string cnic[1000];
        int drinkPepsi;
        int drinkFanta;
        int drinkSprite;
        int noOfPeople;
        int roomGiven;
        int floorGiven;
        long int durationOfStay;
        int roomGiven_location;
        int refrigeratorBottles;
        int bottlesDrank;
        int bill_bottles;
        long int checkOutTime;
        int bookingTime;
        int bottlePosition;
};


#endif // COSTUMER_H
