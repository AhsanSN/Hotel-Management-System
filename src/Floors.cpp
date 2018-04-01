#include "Floors.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include "Costumer.h"

using namespace std;

///global variables
extern int roomsFloor1[10][3];
extern int roomsFloor2[10][3];
extern int roomsFloor3[10][3];
extern string roomBookedForCostumersName[50];
extern int roomBookedForCostumersRoom[50];
extern int costumerNumber;

Floors::Floors()
{
}

void Floors::getRoomInfo(int roomNumber) //generates information whether room is occupied or not
{
    cout<<""<<endl;
    if (validRoom(roomNumber) == true) //check if the room number is valid
    {
        getOccupancy(roomNumber); //people who can live in this room
        getVacancy(roomNumber);
        //personLivingInRoom(roomNumber);
        //getPhoneNumber(roomNumber);
    }
    else //if room number is not valid prompts the user
    {
        cout<<"Room doesn't exist!"<<endl;
    }
}

void Floors::getCostumerDetails(int roomNumber_i) //extracts the details of the customers
{
    int locationOfRoominMainList;
    for (int i =0 ; i<costumerNumber ; i++)
    {
        if (roomBookedForCostumersRoom[i] == roomNumber_i)
        {
            locationOfRoominMainList= i;
            break;
        }
        roomBookedForCostumersName[locationOfRoominMainList];
    }
}

bool Floors::validRoom(int validRoom_i) //checks if the room number given is valid or not
{ //all the rooms in the hotel
    int Rooms[30] = {101,102,103,104,105,106,107,108,109,110,201,202,203,204,205,206,207,208,209,210,301,302,303,304,305,306,307,308,309,310}; //list of valid rooms
    for (int i = 0; i<30 ; i++)
    {
        if (Rooms[i] == validRoom_i) //check validity
        { //linear search
            return true;
        }
    }
    return false;
} // returns bool value

void Floors::getVacancy(int vacancy_i) //checks if the room is vacant or booked
{ // if room is empty the value will be 1
    if (vacancy_i / 100 == 1) //floor 1, rooms from 101 to 109
    {
        for (int i=0; i<10 ; i++)
        { //comparing the room given number
            if (roomsFloor1[i][0] == vacancy_i)
            {
                if (roomsFloor1[i][1] == 1) //checking vacancy
                { //if 1 that means room empty otherwise booked
                    cout<<"State: Vacant"<<endl;
                    break; //stops the loop if desired result is obtained
                }
                else
                {
                    cout<<"State: Booked"<<endl;
                    break; //stops the loop if desired result is obtained
                }
            }
        }
    }

    if (vacancy_i / 100 == 2) //floor 2, rooms from 200 to 209
    {
        for (int i=0; i<10 ; i++)
        { //comparing the room given number
            if (roomsFloor2[i][0] == vacancy_i)
            {
                if (roomsFloor2[i][1] == 1) //checking vacancy
                { //if 1 that means room empty otherwise booked
                    cout<<"State: Vacant"<<endl;
                    break; //stops the loop if desired result is obtained
                }
                else
                {
                    cout<<"State: Booked"<<endl;
                    break; //stops the loop if desired result is obtained
                }
            }
        }
    }

    if (vacancy_i / 100 == 3) //floor 3, rooms from 300 to 309
    {
        for (int i=0; i<10 ; i++)
        { //comparing the room given number
            if (roomsFloor3[i][0] == vacancy_i)
            {
                if (roomsFloor3[i][1] == 1) //checking vacancy
                { //if 1 that means room empty otherwise booked
                    cout<<"State: Vacant"<<endl;
                    break; //stops the loop if desired result is obtained
                }
                else
                {
                    cout<<"State: Booked"<<endl;
                    break; //stops the loop if desired result is obtained
                }
            }
        }
    }
}

int Floors::getRefrigeratorBottles() //returns the number of bottles in the refrigerator
{
    cout<<refrigeratorBottles<<endl;
    return (refrigeratorBottles); //returning the private variable refrigeratorBottles
}

void Floors::getAllRooms() //gives the number of vacant rooms in the hotel
{ // if room is empty the value will be 1
    int roomsEmpty = 0;
    for (int i = 0; i<10 ; i++) //checking rooms on floor 1
    { //if 1 that means room empty otherwise booked
        if (roomsFloor1[i][1] == 1) // if room is empty the value will be 1
        {
            roomsEmpty = roomsEmpty + 1; //counter
        }
    }
    for (int i = 0; i<10 ; i++) //checking rooms on floor 2
    { //if 1 that means room empty otherwise booked
        if (roomsFloor2[i][1] == 1)
        {
            roomsEmpty = roomsEmpty + 1; //counter
        }
    }
    for (int i = 0; i<10 ; i++) //checking rooms on floor 3
    { //if 1 that means room empty otherwise booked
        if (roomsFloor3[i][1] == 1)
        {
            roomsEmpty = roomsEmpty + 1; //counter
        }
    }
    cout<<"Total empty rooms in hotel: "<<roomsEmpty<<endl;
}

void Floors::getPhoneNumber(string room_input)
{ //generates phone number
    string room_inputString = room_input;
    cout<<"0"+room_inputString<<endl;
}

void Floors::getOccupancy(int roomNo_1)
{
    if (roomNo_1 / 100 == 1) //floor 1, rooms from 101 to 109
    {
        for (int i=0; i<10 ; i++)
        { //matches the room number
            if (roomsFloor1[i][0] == roomNo_1)
            { //cout the number of people in the room
                cout<<"Occupancy: "<<roomsFloor1[i][2]<<endl;
            }
        }
    }
    if (roomNo_1 / 100 == 2) //floor 2, rooms from 200 to 209
    {
        for (int i=0; i<10 ; i++)
        { //matches the room number
            if (roomsFloor2[i][0] == roomNo_1)
            { //cout the number of people in the room
                cout<<"Occupancy: "<<roomsFloor2[i][2]<<endl;
            }
        }
    }
    if (roomNo_1 / 100 == 3) //floor 3, rooms from 300 to 309
    { //matches the room number
        for (int i=0; i<10 ; i++)
        {
            if (roomsFloor3[i][0] == roomNo_1)
            { //cout the number of people in the room
                cout<<"Occupancy: "<<roomsFloor3[i][2]<<endl;
            }
        }
    }
}

void Floors::getAllRooms(int FloorNo) //similar to getAllRooms --> function overloading
{ //run when floor number is given
    if (FloorNo == 1)
    { //checks vacancy of rooms on floor 1
        int roomsEmpty = 0; //counter
        for (int i = 0; i<10 ; i++)
        {
            if (roomsFloor1[i][1] == 1)
            { //if 1 that means room empty otherwise booked
                roomsEmpty = roomsEmpty + 1; //counter
            }
        } //prints the total number of empty rooms on floor 1
        cout<<"Rooms empty on floor "<<FloorNo<<" : " << roomsEmpty<<endl;
    }
    if (FloorNo == 2)
    { //checks vacancy of rooms on floor 2
        int roomsEmpty = 0; //counter
        for (int i = 0; i<10 ; i++)
        {
            if (roomsFloor2[i][1] == 1)
            { //if 1 that means room empty otherwise booked
                roomsEmpty = roomsEmpty + 1; //counter
            }
        } //prints the total number of empty rooms on floor 2
        cout<<"Rooms empty on floor "<<FloorNo<<" : " << roomsEmpty<<endl;
    }
    if (FloorNo == 3)
    { //checks vacancy of rooms on floor 3
        int roomsEmpty = 0; //counter
        for (int i = 0; i<10 ; i++)
        {
            if (roomsFloor3[i][1] == 1)
            { //if 1 that means room empty otherwise booked
                roomsEmpty = roomsEmpty + 1; //counter
            }
        } //prints the total number of empty rooms on floor 3
        cout<<"Rooms empty on floor "<<FloorNo<<" : " << roomsEmpty<<endl;
    }
}
