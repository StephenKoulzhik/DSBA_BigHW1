#ifndef GAMESTRUCTURE_H
#define GAMESTRUCTURE_H
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <QtDebug>
using namespace std;

struct Game
{
    string title;
    int rank, ratingsCounter, milestone, perfectRatings;
    double rating, price;
};

vector<Game> fillVec()
{
    vector<Game> res;
    fstream in("android-games.csv");
    string s;

    getline(in, s);
    while(getline(in, s, '\n'))
    {

        Game anotherOne;
        stringstream ss(s);
        int counter = 0;
        string temp;
        vector<string> arr;

        while (getline(ss, temp, '|'))
        {
            if (counter <= 4 || counter == 7 || counter == 9)
                arr.push_back(temp);
            counter++;
        }

        anotherOne.rank = stoi(arr[0]);
        anotherOne.title = arr[1];
        anotherOne.ratingsCounter = stoi(arr[2]);
        if (arr[3].find('M') != string::npos)
        {
            string chislo = arr[3].substr(0, arr[3].find(' '));
            anotherOne.milestone = stod(chislo) * 1000000;
        }
        else if (arr[3].find('k') != string::npos)
        {
            string chislo = arr[3].substr(0, arr[3].find(' '));
            anotherOne.milestone = stod(chislo) * 1000;
        }
        else
            anotherOne.milestone = stoi(arr[3]);

        anotherOne.rating = stod(arr[4]);
        anotherOne.price = stod(arr[5]);
        anotherOne.perfectRatings = stoi(arr[6]);

        res.push_back(anotherOne);
    }

    qDebug() << QString::fromStdString(s);
    qDebug() << QString::fromStdString(res[0].title);
    return res;
}
#endif // GAMESTRUCTURE_H
