#include "Costumer.h"
#include "Floors.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctype.h>
#include <cstdlib>
#include <windows.h>
#include <unistd.h>
#include <time.h>

using namespace std;

extern int roomsFloor1[10][3];
extern int roomsFloor2[10][3];
extern int roomsFloor3[10][3];
extern int costumerNumber;
extern string roomBookedForCostumersName[50];
extern int roomBookedForCostumersRoom[50];
extern int roomBookedForCostumersBottle[50];
extern int roomBookedForCostumersBottlesDrank[50];
extern int roomBookedForCostumersBookingTime[50];
extern int roomBookedForCostumersBill[50];

time_t rawtime;
struct tm * timeinfo;

Costumer::Costumer()
{
}

Costumer::Costumer(int noOfPeople)
{
    //
    string cnic_i;
    string dob_i;
    string nameAddition;
    int drinkFanta =3;
    int drinkSprite = 3;
    int drinkPepsi = 4;
    names[noOfPeople];
    cnic[noOfPeople];
    dob[noOfPeople];
    for (int i = 0; i<noOfPeople ; i++)
    { //generates the name of guests at random
        char name_i[9]= {'G','u','e','s','t',' ','0'+rand()%10,'0'+rand()%10,'\0'};
        names[i] = name_i;
    //generates the cnics of guests at random
        char cnic_i[16] = {'0'+rand()%10,'0'+rand()%10,'0'+rand()%10,'0'+rand()%10,'0'+rand()%10, '-', '0'+rand()%10,'0'+rand()%10,'0'+rand()%10,'0'+rand()%10,'0'+rand()%10, '0'+rand()%10,'0'+rand()%10,'-', '0'+rand()%10,'\0'};
        cnic[i] = cnic_i;
    //generates the date of birth of guests at random
        char dob_i[9] = {'0'+rand()%3,'0'+rand()%10,'-','0','0'+rand()%10+1,'-','0'+rand()%10,'0'+rand()%10,'\0'};
        dob[i] = dob_i;
    }

    //adding it in a text file
    //system("cls");
    roomGiven = giveRoom(noOfPeople);
    string editLine; // takes each line
    ofstream editFile;
    char filename[30] = "Datafile.txt";
    editFile.open(filename,std::ios_base::app);
    if ((roomGiven<=309) && (roomGiven>=100))
    { //entering data from file
        editFile << "-----"<<endl;
        editFile << "Costumer: "<<names[0]<<endl;
        editFile << ""<<endl;
        editFile << "Head name: "<<names[0]<<endl;
        editFile << "Room: "<<roomGiven<<endl;
        time ( &rawtime );
        timeinfo = localtime (&rawtime );
        editFile<<"Booking time: ";
        editFile<<(" Booking : %s", asctime (timeinfo) )<<endl;
        editFile << "Number of people: "<<noOfPeople<<endl;

    }
//entering data into the file
    if ((roomGiven<=309) && (roomGiven>=100))
    {
        for (int i = 0; i<noOfPeople; i++)
        {
            editFile << "Name: "<<names[i]<<"   CNIC: "<<cnic[i]<<"   Date of birth: "<<dob[i]<<"\n"; //of guest
        }
    }
    editFile.close(); //closes the file
    cout<<"DETAILS ENTERED: "<<endl;
    cout<<"_________________"<<endl;
    if ((roomGiven<=309) && (roomGiven>=100)) //prints the data in file
    {
        for (int i = 0; i<(noOfPeople) ; i++)
        {
            cout<<"Name: "<<names[i]<<"   CNIC: "<<cnic[i]<<"   Date of birth: "<<dob[i]<<endl;
        }
    }
    else //if no room is available
    {
        cout<<"No details entered, as no room is available"<<endl;
    }


    if ((roomGiven<=309) && (roomGiven>=100))
    {
        roomBookedForCostumersName[costumerNumber] = names[0];
        roomBookedForCostumersRoom[costumerNumber] = roomGiven;
        roomBookedForCostumersBottle[costumerNumber] = 10;
        costumerNumber = costumerNumber + 1;

    }

    cout<<""<<endl;
}

void Costumer::personLivingInRoom(int room_input)
{ //prints the number of people living in the room
    for (int i = 0 ; i<costumerNumber ; i++)
    {
        if (roomBookedForCostumersRoom[i] == room_input)
        {
            cout<<"Person living in room: "<<roomBookedForCostumersName[i]<<endl;
            break;
        }
    }
}

void Costumer::namesOfPeopleInHotel()
{ //cout the the customer name and booked room number
    for (int i=0; i<costumerNumber; i++)
    {
        cout<<"Customer: "<<roomBookedForCostumersName[i]<<"    Room: "<<roomBookedForCostumersRoom[i]<<endl;
    }
}

int Costumer::giveRoom(int noOfPeople)
{
    bool permission = false;
    for (int i = 0; i<10 ; i++)
    {
        if ((roomsFloor1[i][2] == noOfPeople) && (roomsFloor1[i][1] == 1 ))
        { //checks if a room can accommodate people arrived on any of the rooms on floor 1
            cout<<""<<endl;
            cout<<"Room "<<roomsFloor1[i][0]<<" given to "<<names[0]<<endl;
            roomsFloor1[i][1] = false;
            roomGiven_location = i;
            roomGiven = roomsFloor1[i][0]; //room no. of the given room
            floorGiven = 1; //floor of the room given
            permission = false;
            return roomsFloor1[i][0];
        }
        if (i == 9)
        {
            permission = true;
        }
    }
    if  (permission == true)
    {
        for (int i = 0; i<10 ; i++)
        {
            if ((roomsFloor2[i][2] == noOfPeople) && (roomsFloor2[i][1] == 1 ))
            { //checks if a room can accommodate people arrived on any of the rooms on floor 2
                cout<<""<<endl;
                cout<<"Room "<<roomsFloor2[i][0]<<" given to "<<names[0]<<endl;
                roomsFloor2[i][1] = false;
                roomGiven = roomsFloor2[i][0];
                roomGiven_location = i;
                permission = false;
                floorGiven = 2;
                return roomsFloor2[i][0];
            }
            if (i == 9)
            {
                permission = true;
            }
        }
    }
    if  (permission == true)
    {
        for (int i = 0; i<10 ; i++)
        {
            if ((roomsFloor3[i][2] == noOfPeople) && (roomsFloor3[i][1] == 1 ))
            { //checks if a room can accommodate people arrived on any of the rooms on floor 3
                cout<<""<<endl;
                cout<<"Room "<<roomsFloor3[i][0]<<" given to "<<names[0]<<endl;
                roomsFloor3[i][1] = false;
                roomGiven = roomsFloor3[i][0];
                roomGiven_location = i;
                permission = false;
                floorGiven = 3;
                return roomsFloor2[i][0];
            }
            if (i == 9)
            {
                permission = true;
            }
        }
    }
    if (permission == true)
    {
        cout<<""<<endl;
        cout<<"No room available!"<<endl;
        return 0;
    }
    refrigeratorBottles = 5;
}

void Costumer::checkOut(string nameInput, int roomGiven)
{
    int index;
    bool valid= false;
    for (int i=0; i<costumerNumber; i++) //checks validity of input data
    {
        if ((roomBookedForCostumersName[i]==nameInput && roomBookedForCostumersRoom[i]== roomGiven))
        {
            valid= true;
            break; //breaks the loop
        }
    }
    if (valid == true)
    {
        if (roomGiven/100 == 1)
        {
            for (int i = 0; i<costumerNumber; i++)
            {
                if (roomBookedForCostumersRoom[i] == roomGiven)
                {
                    index = i;
                    break;
                }
            }
            for (int i = 0; i<10 ; i++)
            {
                if (roomsFloor1[i][0] == roomGiven)
                {
                    roomsFloor1[i][1] = true;
                    //checkOutTime = getTimeOfCheckOut();
                    cout<<""<<endl;
                    cout<<nameInput<<" checked out from the room "<<endl;
                    costumerNumber = costumerNumber - 1;

                }
            }
        }
        if (roomGiven/100 == 2)
        {
            for (int i = 0; i<costumerNumber; i++)
            {
                if (roomBookedForCostumersRoom[i] == roomGiven)
                {
                    index = i;
                    break;
                }
            }
            for (int i = 0; i<10 ; i++)
            {
                if (roomsFloor2[i][0] == roomGiven)
                {
                    roomsFloor2[i][1] = true;
                    //checkOutTime = getTimeOfCheckOut();
                    cout<<nameInput<<" checked out from the room "<<endl;
                    costumerNumber = costumerNumber - 1;

                }
            }
        }
        if (roomGiven/100 == 3)
        {
            for (int i = 0; i<costumerNumber; i++)
            {
                if (roomBookedForCostumersRoom[i] == roomGiven)
                {
                    index = i;
                    break;
                }
            }
            for (int i = 0; i<10 ; i++)
            {
                if (roomsFloor3[i][0] == roomGiven)
                {
                    roomsFloor3[i][1] = true;
                    //checkOutTime = getTimeOfCheckOut();
                    cout<<""<<endl;
                    cout<<nameInput<<" checked out from the room "<<endl;
                    costumerNumber = costumerNumber - 1;
                }
            }
        }
        /// Removing enteries from the shared main arrays
        removeNameFromList(nameInput, roomGiven);
        removeRoomFromList(roomGiven);
        //removeBottlesFromList(roomGiven);
        //removeBottlesDrankFromList(roomGiven);
        //removeBookingTimeFromList(roomGiven);
    }
}

void Costumer::getRoom()
{
    cout<<roomGiven<<endl; //prints the attribute
}

void Costumer::peopleInRoom(int roomNumber)
{
    //get name
    string name;
    for (int i=0; i<costumerNumber; i++)
    { //getting the room entered
        if (roomBookedForCostumersRoom[i]==roomNumber)
        {
            name= roomBookedForCostumersName[i];
        }
    }
    //
    string erase_all; //erases the exiting data in file
    char filename[50]="DataFile.txt"; // takes the file name
    ifstream readfile; //reads file
    string eachline = ""; // stores each line of the file
    readfile.open(filename); //open the file with that name
    while(getline(readfile,eachline)) //runs the loop number of times the lines in the file
    {
        if (eachline== ("Head name: "+ name)) //name of guest
        {
            while ((getline(readfile,eachline))&&(eachline!="-----")) //read all contents of file
            {
                cout<<eachline<<endl; //prints each line
            }
        }
    }
    readfile.close(); //closes file
    cout<<""<<endl;
}

void Costumer:: getNoOfBottlesAvailable(int roomNumber)
{
    int bottlePosition;
    if  (costumerNumber>0)
    {
        for(int i=0 ; i<costumerNumber; i++)
        { //finding the room entered by the user
            if (roomBookedForCostumersRoom[i]==roomNumber)
            {
                bottlePosition = i;
                break;
            }
        } //prints the number of bottles currently in the refrigerator
        cout<<"Number of bottles in refrigerator: "<<roomBookedForCostumersBottle[bottlePosition]<<endl;;
        if (refrigeratorBottles < 5)
        { //if bottles less than 5 than refill the refrigerator
            refillRefrigerator(roomNumber);
        }
        else
        {
            cout<<"This room is vacant! "<<endl; ///
        }
    }

}

void Costumer::takeABottle(int roomNumber)
{
    int bottlePosition = 0;
    for(int i=0 ; i<costumerNumber; i++)
    { //checking validity of room
        if (roomBookedForCostumersRoom[i]==roomNumber)
        {
            bottlePosition = i;
            break;
        }
    }
    int bottleInput;
    bottleInput = rand() % 3 + 1; //generating a random number
    if (roomBookedForCostumersBottle[bottlePosition] > 0)
    {
        addBottlestoFile(bottlePosition, bottleInput); //input in file
        roomBookedForCostumersBottle[bottlePosition] = roomBookedForCostumersBottle[bottlePosition] - 1;
        roomBookedForCostumersBottlesDrank[bottlePosition] = roomBookedForCostumersBottlesDrank[bottlePosition] + 1;
        roomBookedForCostumersBill[bottlePosition] = roomBookedForCostumersBill[bottlePosition] + 90;

        if (roomBookedForCostumersBottle[bottlePosition]<3)
        {
            refillRefrigerator(roomNumber);
        }
    }
}

void Costumer::getBottlesDrank(int roomNumber)
{
    if (costumerNumber>0)
    {
        for(int i=0 ; i<costumerNumber; i++)
        {
            if (roomBookedForCostumersRoom[i]==roomNumber)
            {
                bottlePosition = i;
                break;
            }
        }
        cout<<roomBookedForCostumersName[bottlePosition]<<" drank: "<<roomBookedForCostumersBottlesDrank[bottlePosition]<<" bottles"<<endl;
    }
    //return 0;
}

void Costumer::getBottlesFromFile()
{
    string name;
    string erase_all;
    char filename[50]="Bottlefile.txt"; // takes the file name
    ifstream readfile; //reads file
    string eachline = ""; // stores each line of the file
    readfile.open(filename); //open the file with that name
    for (int i = 0; i<costumerNumber ; i++)
    {
        name =roomBookedForCostumersName[i];
        cout<<"Bottles drank by: "<<name<<endl;
        while(getline(readfile,eachline)) //runs the loop number of times the lines in the file
        {
            if (eachline== (name+" :"))
            { //prints all the bottles consumed by each guest
                getline(readfile,eachline);
                cout<<eachline<<endl;
            }
        }
        cout<<"----------"<<endl;
        readfile.clear(); //clears the file
        readfile.seekg(0, readfile.beg);
    }
    readfile.close(); //closes file
}

int Costumer::refillRefrigerator(int roomNumber)
{
    int bottlePosition;
    int bottlesAdded;
    for(int i=0 ; i<costumerNumber; i++)
    {
        if (roomBookedForCostumersRoom[i]==roomNumber)
        {
            bottlePosition = i;
            break;
        }
    }
    if (roomBookedForCostumersBottle[bottlePosition]  < 5)
    {
        int drinkFanta =3;
        int drinkSprite = 3;
        int drinkPepsi = 4;
        bottlesAdded = 5- roomBookedForCostumersBottle[bottlePosition];
        roomBookedForCostumersBottle[bottlePosition] = roomBookedForCostumersBottle[bottlePosition] + (bottlesAdded);
    }
    return 0;
}

void Costumer::removeNameFromList(string name, int room)
{
    string arrayNameTemporary[50];
    int i,j;
    int lengthofArray= costumerNumber;
    for(i=0,j=0; i<lengthofArray; ++i)
    {
        if(roomBookedForCostumersName[i] != name)
        {
            arrayNameTemporary[j++]=roomBookedForCostumersName[i];
        }
    }
    for(i=0; i<j; i++)
    {
        roomBookedForCostumersName[i]=arrayNameTemporary[i];
    }
}

void Costumer::removeRoomFromList(int room)
{
    int arrayNameTemporary[50];
    int i,j;
    int lengthofArray= costumerNumber;
    for(i=0,j=0; i<lengthofArray; ++i)
    {
        if(roomBookedForCostumersRoom[i] != room)
        {
            arrayNameTemporary[j++]=roomBookedForCostumersRoom[i];
        }
    }
    for(i=0; i<j; i++)
    {
        roomBookedForCostumersRoom[i]=arrayNameTemporary[i];
    }
}

void Costumer::addBottlestoFile(int bottlePosition, int bottle)
{ //stores the number of bottles consumed by the guests
    string editLine; // takes each line
    ofstream editFile; //stores data in a .txt file
    char filename[30] = "Bottlefile.txt"; //stores data in a .txt file
    editFile.open(filename,std::ios_base::app);
    editFile << roomBookedForCostumersName[bottlePosition]<<" :"<<endl;
    if (bottle == 1)
    { //cout the bottles consumed
        cout<<roomBookedForCostumersName[bottlePosition]<< " took a Pepsi - 200ml "<<endl;
        editFile <<" Pepsi - 200ml"<<endl;
    }
    if (bottle == 2)
    { //cout the bottles consumed
        cout<<roomBookedForCostumersName[bottlePosition]<< " took a Fanta - 220ml "<<endl;
        editFile <<" Fanta - 250ml"<<endl;
    }
    if (bottle == 3)
    { //cout the bottles consumed
        cout<<roomBookedForCostumersName[bottlePosition]<< " took a Sprite - 300ml "<<endl;
        editFile <<" Sprite - 300ml"<<endl;
    }
    editFile << "---"<<endl;
    editFile.close(); //closes the file
}

