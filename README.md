# Hotel Management System

## About

A Hotel Management System simulation that simulates a multi-day business in a hotel. See <code>Description</code> for more details.

## Installation

Simply run SyedAhsanAhmed02908.cbp to run open project. If you don't have to means to open the project, use exe file to run the project executable.

## Screenshots

<table>
  <tbody>
    <tr>
      <!-- Video 1 -->
      <td align="center">
          <img width="390" alt="FamiChat" src="/screenshots/Screenshot%20(697).png">
          <br>
      </td>
      <!-- Video 2 -->
      <td align="center">
          <img width="390" alt="FamiChat" src="/screenshots/Screenshot%20(705).png">
          <br>
      </td>
    </tr>    <tr>
      <!-- Video 1 -->
      <td align="center">
          <img width="390" alt="FamiChat" src="/screenshots/Screenshot%20(706).png">
          <br>
      </td>
      <!-- Video 2 -->
      <td align="center">
          <img width="390" alt="FamiChat" src="/screenshots/Screenshot%20(711).png">
          <br>
      </td>
    </tr>    <tr>
      <!-- Video 1 -->
      <td align="center">
          <img width="390" alt="FamiChat" src="/screenshots/Screenshot%20(708).png">
          <br>
      </td>
      <!-- Video 2 -->
      <td align="center">
          <img width="390" alt="FamiChat" src="/screenshots/Screenshot%20(709).png">
          <br>
      </td>
    </tr>    <tr>
      <!-- Video 1 -->
      <td align="center">
          <img width="390" alt="FamiChat" src="/screenshots/Screenshot%20(710).png">
          <br>
      </td>
      <!-- Video 2 -->
      <td align="center">
          <img width="390" alt="FamiChat" src="/screenshots/Screenshot%20(711).png">
          <br>
      </td>
    </tr>
  </tbody>
</table>

## Description
Pearl Continental Hotel Rawalpindi requires a hotel management system to support its administration.
The major features of a hotel are:

 there are three floors numbered 1,2 and 3 each of which has ten rooms

 each room has a room number, e.g. 201 for room 1 on floor 2

 each room has a phone number which is actually created by adding a zero before the room
number. So 0201 belongs to room 201.

 each room has a different occupancy which can range from 2 to 5

 each room has a refrigerator which can hold a total of 10 cold drinks, which can be Pepsi, Fanta
and Sprite and their capacity is 200, 250 and 300 ml.

 guests drink these drinks at random. Whenever the count falls below 3, the staff replenishes the
supply by adding random drinks.

A room can be booked to one or more persons with each person having a Name, CNIC and Date of Birth.
Information of all persons needs to be added. The booking mechanism has the following key features
that need to be implemented:

 adds persons to the room according to its occupancy and marks room as booked

 add date and time of booking and its charges (Day/Month/Year and Hour/Minute/Second)

 upon check out it removes all persons from the room and marks it as not booked

Staff should be able to obtain details of each room in a variety of ways. The user must be able to request
information for the following reports:

 all the rooms on all floors

 all the rooms on a particular floor

 display the booking details of a particular room which includes the people staying in the room,

the cold drinks available and the cold drinks used

Finally, your code should simulate actual behavior. Which means people coming and leaving for a week.
This means that you are going to run 7 iterations. Every day a random number of people are going to ask
for a room and they will be assigned appropriate rooms. You can make a file that contains the details of
all the guests which frequent the Hotel. At the end of simulation, you will generate a file containing all
the details of all the guests who left the hotel showing when they left and at what time and also how
long they stayed based on the date and time of booking and the date and time they checked out.
You as programmers are required to design an efficient C++ application that creates classes presented in
the scenario. Extensive use of arrays and pointers is expected during development.
