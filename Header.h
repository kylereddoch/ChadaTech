/*
Author: Kyle Reddoch
Date: 9/13/2022
*/

#define _CRT_SECURE_NO_WARNINGS  //Had to use this or VS wouldn't let me compile

#include<iostream>  //Lets me take user input
#include<ctime>  //Lets me use real local time
#include<iomanip>  //Lets me use setw and setfill on strings

using namespace std;  //Namespace for output

class Clock {  //Declares base clock class
public:  //Declares public variables
    int hours;  //Declares hour variable
    int minutes;  //Declares minute variable
    int seconds;  //Declares seconds variable
};

class Clock12 : public Clock {  //Declares 12-hour clock class that inherits from Clock class
public:  //Declares public variables
    string meridian;  //Declares string to hold meridian

    Clock12() {  //Default constructor for 12-hour clock
        time_t now = time(0);  //Creates object for using local time, still a little unsure what this and next line actally does
        tm* ltm = localtime(&now);  //I believes this creates a pointer to another object but still unsure, just followed ctime docs
        hours = ltm->tm_hour;  //Stores time object hours into hours variable
        minutes = ltm->tm_min;  //Stores time object minutes into minutes variable
        seconds = ltm->tm_sec;  //Stores time object seconds into seconds variable

        if (hours >= 12) {  //Sets meridian depending on value of hour variable
            meridian = "P M";
            hours -= 12;
        }
        else
            meridian = "A M";

    }

    void addHour(int h) { //Function to add hour to 12-hour clock taking int argument
        hours += h;  //Adds argument value to hour variable
        if (hours > 12) {  //Resets hours variable once clock reaches midnight
            hours -= 12;
        }
        else if (hours >= 12) {  //Swaps meridian depending on value of hours variable and value of meridian variable
            if (meridian == "A M") {
                meridian = "P M";
            }
            else if (meridian == "P M") {
                meridian = "A M";
            }
        }
    }

    void addMinute(int m) {  //Function to add minute to 12-hour clock taking int argument
        minutes += m;  //Adds argument value to minutes variable
        if (minutes >= 60) {  //Adds one hour if minutes value reaches 60
            int h = minutes / 60;
            minutes -= 60 * h;
            addHour(h);
        }
    }

    void addSeconds(int sec) {  //Function to add second to 12-hour clock taking int argument
        seconds += sec;  //Adds argument value to seconds variable
        if (seconds >= 60) {  //Adds one minute if seconds value reaches 60
            int m = seconds / 60;
            seconds -= 60 * m;
            addMinute(m);
        }
    }
};

class Clock24 :public Clock {  //Declares 24-hour clock class that inherits from base Clock class
public:  //Declares public variables
    Clock24() {  //Default constructor for 24-hour clock
        time_t now = time(0);  //Creates object for using local time, still a little unsure what this and next line actally does
        tm* ltm = localtime(&now);  //I believes this creates a pointer to another object but still unsure, just followed ctime docs
        hours = ltm->tm_hour;  //Stores time object hours into hours variable
        minutes = ltm->tm_min;  //Stores time object minutes into minutes variable
        seconds = ltm->tm_sec;  //Stores time object seconds into seconds variable
    }

    void addHour(int h) {  //Function to add hour to 24-hour clock taking int argument
        hours += h;  //Adds argument value to hour variable
        if (hours >= 24) {  //Resets hours variable once clock reaches midnight
            hours -= 24;
        }
    }

    void addMinute(int m) {  //Function to add minute to 24-hour clock taking int argument
        minutes += m;  //Adds argument value to minutes variable
        if (minutes >= 60) {  //Adds one hour if minutes value reaches 60
            int h = minutes / 60;
            minutes -= 60 * h;
            addHour(h);
        }
    }

    void addSeconds(int sec) {  //Function to add second to 24-hour clock taking int argument
        seconds += sec;  //Adds argument value to minutes variable
        if (seconds >= 60) {  //Adds one minute if seconds value reaches 60
            int m = seconds / 60;
            seconds -= 60 * m;
            addMinute(m);
        }
    }
};