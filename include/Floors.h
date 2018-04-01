#ifndef FLOORS_H
#define FLOORS_H
#include <iostream>
#include <string>

using namespace std;

class Floors
{
    public:
        Floors();
        int getRefrigeratorBottles();
        void getAllRooms();
        void getAllRooms(int);
        void getPhoneNumber(string);
        void getOccupancy(int);
        void getVacancy(int);
        void getRoomInfo(int);
        bool validRoom(int);
        void getCostumerDetails(int);

    protected:

    private:
        int floorNumber;
        int roomNumber;
        int phoneNumber;
        int occupancy;
        int refrigeratorBottles;
        bool booked;
        int roomsOnFloor;
        int totalRooms;
};

#endif // FLOORS_H
