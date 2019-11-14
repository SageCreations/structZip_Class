//
// Created by Edward Cruz on 11/13/2019.
//

#include "sorting.h"
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

struct file {
    string name;
    string address;
    string city;
    string st;
    char zip[6];
    int age;
};

void sorting::printThem(struct file x[])
{
    for (int i = 0; i < 20; i++)
    {
        cout << "\n\t\t\t\t\t\t\t" << setw(20) << left << x[i].name << "   "
             << x[i].zip << "\t " << x[i].age;
    }
}

void sorting::bubbleSort(struct file a[])
{
    struct file temp;
    for (int i = 0; i < 20 - 1; i++) {
        for (int j = 0; j < 20 - i - 1; j++) {
            if (strcmp(a[j].zip, a[j+1].zip) > 0) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void sorting::shellSort(struct file data[])
{
    int jump = 20;
    bool swapped = true;
    struct file temp;
    for (jump = jump/2; jump > 0; swapped = true, jump = jump/2) {
        while (swapped)
        {
            swapped = false;
            for (int i = 0; i < 20 - jump; i++)
            {
                if (strcmp(data[i].zip, data[i+jump].zip) < 0)
                {
                    temp = data[i];
                    data[i] = data[i+jump];
                    data[i+jump] = temp;
                    swapped = true;
                }
            }
        }
    }
}

int sorting::findIt(struct file x[], char temp[])
{
    int first = 0, last = 19, mid;
    string zip;
    while (first <= last)
    {
        mid = (first + last) / 2;
        zip = x[mid].zip;
        if (strcmp(x[mid].zip, temp) == 0)
            return mid;
        else
        if (strcmp(x[mid].zip, temp) < 0)
            last = mid - 1;
        else first = mid + 1;
    }
    return -1;
}

