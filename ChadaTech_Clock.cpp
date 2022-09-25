/*
Author: Kyle Reddoch
Date: 9/13/2022
*/

#include "Header.h"  //Imports header file

void displayTime(Clock12 userClock12, Clock24 userClock24) {  //Function to display side by side clock
    cout << "*************************\t\t" << "*************************" << endl;  //Border for left and right clock
    cout << "*\t12-Hour Clock\t*\t\t";  //12-hour clock title
    cout << "*\t24-Hour Clock\t*" << endl;  //24 hour clock title
    cout << "*\t" << setw(2) << setfill('0') << userClock12.hours << ":" << setw(2) << setfill('0') << userClock12.minutes;  //12-hour clock display
    cout << ":" << setw(2) << setfill('0') << userClock12.seconds << " " << userClock12.meridian << "\t*\t\t";  //Continuation of previous line
    cout << "*\t" << setw(2) << setfill('0') << userClock24.hours << ":" << setw(2) << setfill('0') << userClock24.minutes;  //24-hour clock display
    cout << ":" << setw(2) << setfill('0') << userClock24.seconds << "\t*" << endl;  //Continuation of previous line
    cout << "*************************" << "\t\t*************************" << endl;  //Border for left and right clock
}

void displayMenu() {  //Function to display menu
    cout << "\n*************************" << endl;  //Top border
    cout << "* 1 - Add One Hour\t*" << endl;  //User option to add one hour to clocks
    cout << "* 2 - Add One Minute\t*" << endl;  //User option to add one minute to clocks
    cout << "* 3 - Add One Second\t*" << endl;  //User option to add one second to clocks
    cout << "* 4 - Exit Program\t*" << endl;  //User option to exit program
    cout << "*************************" << endl;  //Bottom border
}

int main() {
    Clock12 clock12;  //Creates 12-hour clock object
    Clock24 clock24;  //Creates 24-hour clock object

    int userSelection = 0;  //Takes user input for menu

    while (userSelection != 4) {  //Loop continues until user chooses 4th option
        displayTime(clock12, clock24);  //Displays clocks
        displayMenu();  //Displays menu
        cin >> userSelection;  //Takes user input
        switch (userSelection) {  //Switch statement taking the users input
        case 1:  //User selects add one hour
            clock12.addHour(1);  //Adds one hour to 12-hour clock
            clock24.addHour(1);  //Adds one hour to 24-hour clock
            system("CLS");  //Clears screen
            break;  //Breaks loop
        case 2:  //User selects add one minute
            clock12.addMinute(1);  //Adds one minute to 12-hour clock
            clock24.addMinute(1);  //Adds one minute to 24-hour clock
            system("CLS");  //Clears screen
            break;  //Breaks loop
        case 3:  //User selects add one second
            clock12.addSeconds(1);  //Adds one second to 12-hour clock
            clock24.addSeconds(1);  //Adds one second to 24-hour clock
            system("CLS");  //Clears screen
            break;  //Breaks loop
        case 4:  //User selects to exit program
            cout << "Exiting Program" << endl;  //Outputs exit message
            break;  //Breaks loop
        default:  //Default in case user enters invalid option
            system("CLS");  //Clears screen
            cout << "Invalid selection. Please make a selection from the menu" << endl;  //Outputs error message
        }
    }
}