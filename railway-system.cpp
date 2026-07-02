#include <iostream>
#include <string.h>

using namespace std;

class train
{
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];

public:
    static int trainCount;

    train()
    {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");
    }

    train(int tno, char tname[], char src[], char dest[], char time[])
    {
        trainNumber = tno;
        strcpy(trainName, tname);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);
        trainCount++;
    }
    ~train()
    {
    }

    void setTrainNumber(int tno)
    {
        trainNumber = tno;
    }

    void setTrainName(char tname[])
    {
        strcpy(trainName, tname);
    }

    void setSource(char src[])
    {
        strcpy(source, src);
    }

    void setDestination(char dest[])
    {
        strcpy(destination, dest);
    }

    void setTrainTime(char time[])
    {
        strcpy(trainTime, time);
    }

    void inputTrainDetails()
    {
        cout << "Enter Train Number: ";
        cin >> trainNumber;
        cin.ignore();

        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);

        cout << "Enter Source: ";
        cin.getline(source, 50);

        cout << "Enter Destination: ";
        cin.getline(destination, 50);

        cout << "Enter Train Time: ";
        cin.getline(trainTime, 10);

        trainCount++;
    }

    void displayTrainDetails()
    {
        cout << "Train Number: " << trainNumber << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Train Time: " << trainTime << endl;
    }

    int getTrainNumber()
    {
        return trainNumber;
    }

    static int getTrainCount()
    {
        return trainCount;
    }
};

int train::trainCount = 0;

class railwaySystem
{
private:
    train trains[100];
    int totalTrains;

public:
    railwaySystem()
    {
        totalTrains = 0;
    }

    void addTrain()
    {
        if (totalTrains < 100)
        {
            trains[totalTrains].inputTrainDetails();
            totalTrains++;
        }
        else
        {
            cout << "Train record limit is full!" << endl;
        }
    }

    void displayAllTrains()

    {
        if (totalTrains == 0)
        {
            cout << "No train records available!" << endl;
        }
        else
        {
            for (int i = 0; i < totalTrains; i++)
            {
                cout << "\nTrain " << i + 1 << " details:" << endl;
                trains[i].displayTrainDetails();
            }
        }
    }

    void SearchTrainByNumber(int number)
    {
        int found = 0;

        for (int i = 0; i < totalTrains; i++)
        {
            if (trains[i].getTrainNumber() == number)
            {
                cout << "\nTrain Found!" << endl;
                trains[i].displayTrainDetails();
                found = 1;
                break;
            }
        }

        if (found == 0)
        {
            cout << "Train not found!" << endl;
        }
    }
};

int main()
{
    railwaySystem r;
    int choice, number;

    do
    {
        cout << "\n--- Railway Reservation System Menu ---" << endl;
        cout << "1. Add New Train Record" << endl;
        cout << "2. Display All Train Records" << endl;
        cout << "3. Search Train by Number" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            r.addTrain();
            break;

        case 2:
            r.displayAllTrains();
            break;

        case 3:
            cout << "Enter Train Number to search: ";
            cin >> number;
            r.SearchTrainByNumber(number);
            break;

        case 4:
            cout << "Exiting the Railway Reservation System... Good Bye!" << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
