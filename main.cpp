#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctype.h>
#include <cstdlib>
#include <windows.h>
#include <unistd.h>
#include <time.h>
#include "Costumer.h"
#include "Floors.h"


using namespace std;

/*
Prototypes
*/
void TimeDelay();
void deleteDataInFile();
void deleteBottlesInFile();
void takeCommand();
void homeMenu();

///global variables and arrays_start
int costumerNumber = 0;
//General structure of an array = {room number , Empty == true , number of people}
//Rooms of the 3 floors of the hotel
int roomsFloor1[10][3] = {{101, false,2}, {102, true,1}, {103, true,4}, {104, true,2}, {105, true,3}, {106, true,5}, {107, true,4}, {108, true,1}, {109, true,4}, {110, true,4}};
int roomsFloor2[10][3] = {{201, false,3}, {202, false,2}, {203, true,2}, {204, true,4}, {205, true,1}, {206, true,4}, {207, true,3}, {208, true,4}, {209, true,5}, {210, true,3}};
int roomsFloor3[10][3] = {{301, false,4}, {302, false,5}, {303, false,4}, {304, true,5}, {305, true,2}, {306, true,3}, {307, true,1}, {308, true,2}, {309, true,3}, {310, true,2}};
//arrays
string roomBookedForCostumersName[50];
int roomBookedForCostumersRoom[50];
int roomBookedForCostumersBottle[50];
int roomBookedForCostumersBottlesDrank[50];
int roomBookedForCostumersBill[50];

///global variables and arrays_end


int main()
{

    deleteDataInFile(); //deletes the previous data in file
    deleteBottlesInFile();

    homeMenu(); //program starts
    return 0;
}

void takeCommand()
{
    int roomNumber;
    system("cls");
    Costumer c1;
    Floors f1;
    int command_1; //output screen
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"              Welcome to Pearl Continental               "<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<""<<endl; //asks the user what kind of details he/she requires
    cout<<"     Type '1' to get details of a room"<<endl;
    cout<<"     Type '2' to get number of vacant rooms on a floor"<<endl;
    cout<<"     Type '3' to get total number of vacant rooms"<<endl;
    cout<<"     Type '4' to get bottles in the refrigerator of a customer"<<endl;
    cout<<"     Type '5' to get number of bottles guest drank"<<endl;
    cout<<"     Type '6' to get names of people living in hotel"<<endl;
    cout<<"     Type '7' to get all bottles used by guests"<<endl;
    cout<<"     Type '8' to navigate to homepage"<<endl;
    cout<<""<<endl;
    cout<<"     Enter command: ";
    cin>>command_1;
//gives the details according to what the user wants
    if (command_1 == 1) //details of a room
    {
        int roomNumber;
        cout<<"Enter room number: ";
        cin>>roomNumber;
        f1.getRoomInfo(roomNumber);
        c1.peopleInRoom(roomNumber);
        system("pause"); // says ,"Press any key to continue"
        system("cls");
        takeCommand();

    }
    else if (command_1 == 2) //number of vacant rooms on a floor
    {
        int room_i;
        cout<<"         Enter room number: ";
        cin>>room_i;
        f1.getAllRooms(room_i);
        system("pause"); // says ,"Press any key to continue"
        system("cls");
        takeCommand();

    }
    else if (command_1 == 3) //total number of vacant rooms
    {
        f1.getAllRooms();
        system("pause"); // says ,"Press any key to continue"
        system("cls");
        takeCommand();

    }
    else if (command_1 == 4) //bottles in the refrigerator of a customer
    {
        int roomNo_1;
        cout<<"Enter your room number: ";
        cin>>roomNo_1;
        c1.getNoOfBottlesAvailable(roomNo_1);
        system("pause"); // says ,"Press any key to continue"
        system("cls");
        takeCommand();

    }
    else if (command_1 == 5) //number of bottles guest drank
    {
        int roomNumber;
        cout<<"Enter room number:";
        cin>>roomNumber;
        c1.getBottlesDrank(roomNumber);
        system("pause"); // says ,"Press any key to continue"
        system("cls");
        takeCommand();

    }
    else if (command_1 == 6) //names of people living in hotel
    {
        cout<<""<<endl;
        cout<<"People living in hotel: "<<costumerNumber<<endl;
        cout<<""<<endl;
        cout<<"-------------"<<endl;
        cout<<""<<endl;
        if (costumerNumber==0) //hotel is empty
        {
            cout<<"No one is living in the hotel "<<endl;
        }
        else
        {
            cout<<"-----------------------------------------------------------------------"<<endl;
            for (int i = 0; i<costumerNumber; i++)
            {
                cout<<"-------------------------------"<<endl;
                cout<<"Name:  "<<roomBookedForCostumersName[i]<<"   Room number:  "<<roomBookedForCostumersRoom[i]<<endl;
                cout<<""<<endl;
                roomNumber = roomBookedForCostumersRoom[i];
                f1.getRoomInfo(roomNumber);
                c1.peopleInRoom(roomNumber);
            }
        }
        system("pause"); // says ,"Press any key to continue"
        system("cls");
        takeCommand();
    }
    else if  (command_1 ==7) //all bottles used by guests
    {
        c1.getBottlesFromFile();
        system("pause"); // says ,"Press any key to continue"
        system("cls");
        takeCommand();
    }
    else if (command_1 == 8) //navigates back to homepage
    {
        system("cls");
        homeMenu(); //again asks the user what to do

    }
    else
    {
        cout<<"Please enter a valid command."<<endl; //if the entered command is not valid
        Sleep(633);
        system("pause"); // says ,"Press any key to continue"
        system("cls");
        takeCommand();
    }
}

void homeMenu()
{
    srand (time(NULL));
    Costumer c1; //object customer
    Floors f1; //object room/floor
    int days;
    int totalEarned = 0;
    int peopleEnteringHotel;
    int noOfPeople = 0;
    int takeBottleFromRoom = 0;
    int takeBottleTimes = 0;
    int takeAmountOfBottles = 0;
    int numberOfCheckouts = 0;
    int personToCheckout = 0;
    string command;
//main menu
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"              Welcome to Pearl Continental               "<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<""<<endl;
    cout<<"Type 'sim' for simulation"<<endl;
    cout<<"Type 'det' for details"<<endl;
    cout<<"Type 'exit' to close program"<<endl;
    cout<<""<<endl;
    cout<<"What do you want to do? ";
    cin>>command;

    if (command == "exit")
    {
        exit(EXIT_SUCCESS); //closes the program
    }
    if (command == "det") //if the user want details then goes to takeCommand function
    {
        takeCommand();
    }
    if (command == "sim") //simulation
    {
        ///day 1 simulation
        cout<<"Number of days you want to simulate: "; //asks user for number of days
        cin>>days;                                     // generates at random
        for (int i = 0 ; i< days ; i++)
        {
            cout<<"____________________________________________________________________________________________________________"<<endl;
            cout<<""<<endl;
            cout<<"--------------------------------------"<<endl;
            cout<<"        Guests in hotel - DAY "<<i+1<<"    "<<endl;
            c1.namesOfPeopleInHotel();
            cout<<"--------------------------------------"<<endl;
            peopleEnteringHotel = rand() % 5 + 1;
            for (int i = 0 ; i< peopleEnteringHotel ; i++)
            {
                noOfPeople = rand() % 5 + 1;
                Costumer c1(noOfPeople);
            }


            takeAmountOfBottles =  rand() % 5 + 1;
            takeBottleTimes = rand() % 5+2;
            for (int i = 0 ; i<takeBottleTimes ; i++)
            {
                takeBottleFromRoom = rand() % costumerNumber;
                for (int j = 0 ; j<takeAmountOfBottles ; j++)
                {
                    c1.takeABottle(roomBookedForCostumersRoom[takeBottleFromRoom]);
                    totalEarned = totalEarned + 90;
                }
            }

            cout<<"--------------------------------------"<<endl;
            cout<<"             BOTTLES DRANK            "<<endl;
            cout<<""<<endl;
            for (int i = 0; i<costumerNumber ; i++)
            {
                c1.getBottlesDrank(roomBookedForCostumersRoom[i]);
            }
            //bills
            cout<<"--------------------------------------"<<endl;
        }
        //bills
        for (int i = 0; i<costumerNumber ; i++)
        {
            roomBookedForCostumersBill[i] = roomBookedForCostumersBill[i] + 5000;
            totalEarned = totalEarned + 5000;
        }
        //random checkouts
        numberOfCheckouts = rand() % (costumerNumber/2)+1;
        for (int i = 0; i<numberOfCheckouts ; i++)
        {
            //person to checkout
            personToCheckout = rand() % costumerNumber;

            //person to checkout
            c1.checkOut(roomBookedForCostumersName[personToCheckout],roomBookedForCostumersRoom[personToCheckout]);
        }
        cout<<"Hotel earned: Rs "<<totalEarned<<endl;
        system("pause"); // says ,"Press any key to continue"
        system("cls");
        homeMenu();
    }
    else
    {
        cout<<"Give a valid command "<<endl; //if the program does not recognize the command given
        Sleep(300);
        system("cls");
        homeMenu();
    }
}

void TimeDelay() // gives a 3 second pause
{
    cout<<""<<endl;
    cout<<"1";
    Sleep(333); //time in milliseconds
    cout<<".";
    Sleep(333); //time in milliseconds
    cout<<".";
    Sleep(331); //time in milliseconds

    cout<<"2";
    Sleep(333); //time in milliseconds
    cout<<".";
    Sleep(333); //time in milliseconds
    cout<<".";
    Sleep(331); //time in milliseconds

    cout<<"3";
    Sleep(333); //time in milliseconds
    cout<<".";
    Sleep(333); //time in milliseconds
    cout<<".";
    Sleep(331); //time in milliseconds
}

void deleteDataInFile()
{
    string editLine; // takes each line
    ofstream editFile;
    char filename[30] = "Datafile.txt";
    editFile.open(filename);
    editFile<<""<<endl; //deletes entire data in file
    editFile.close();
}

void deleteBottlesInFile()
{
    string editLine; // takes each line
    ofstream editFile;
    char filename[30] = "Bottlefile.txt";
    editFile.open(filename); //deletes all the data stored in file
    editFile<<""<<endl;
    editFile.close();
}

