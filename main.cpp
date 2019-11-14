#include <iostream>
#include "sorting.h"

using namespace std;

struct file {
    string name;
    string address;
    string city;
    string st;
    char zip[6];
    int age;
};

int main() {
    int loc;
    char tgt[60];
    char more;
    sorting x;
    //********************************************** THESE ARE FAKE ADDRESSES ******************************************
    struct file data[] = {
            {"John J Doe", "202 Harvey Rd", "College Station", "TX", "77450", 29},
            {"Tama Martin", "202 College Main", "Houston", "TX", "72002", 10},
            {"Dick Simmons", "Box 1010", "El Paso", "TX", "72081", 55},
            {"Udo Pooch", "1004 Windwood", "Houston", "AR", "02400", 80},
            {"Aarron Stein", "1000 Spicewood", "New York", "NY", "23932", 90},
            {"Steve Jobs", "2082 RainTree", "College Station", "TX", "30020", 45},
            {"Robert Ricks", "8378 University DR.", "Bryan", "TX", "72001", 25},
            {"Richard Ticks", "2498 C. Main", "Los Angeles", "CA", "20020", 18},
            {"Tim Safferd", "3303 George Bush Dr.", "Bryan", "TX", "20200", 12},
            {"Rickard Thamos", "7438 RoseMerry", "Salt Lake", "UT", "83298", 73},
            {"Mary Hart", " 3998 Hallow St", "Anthem", "CA", "00329", 30},
            {"Todd Hoffer", "2939 Univ. Blvd", "Huntsville", "AL", "23890", 63},
            {"Shannon Shoumaker", "2300 Decon", "Dallas", "TX", "73999", 24},
            {"Mike Meeks", "Box 2839", "Paris", "TX", "72990", 43},
            {"Mickey Monique", "Box 3899", "Kansas City", "MO", "38982", 65},
            {"Joe Motana", "10000 Hardwood", "San Franciso", "CA", "83999", 33},
            {"Tom Landry", "48923 Software", "Seattle", "WN", "43223", 13},
            {"Larry Bird", "3298 Hilow Ln", "Kauffman", "AK", "84920", 39},
            {"Denis Cohen", "Box 2399", "Las Cruis", "NM", "73289", 28},
            {"Fy Maybree", "399 Harvey Rd", "Wisconsin", "MO", "48299", 32},
    };

    cout << "\n\nOriginal data: \t\t\t\tName\t\t\t\t    Zip\t\tAge";
    x.printThem(data);
    cout << "\nHit ENTER key to continue . . .";
    cin.get();

    //Sort all of them, on AGE key, in the increasing order!
    cout << "\n\n\nSort by zip in increasing:\tName\t\t\t\t    Zip\t\tAge";
    x.bubbleSort(data);
    x.printThem(data);
    cout << "\nHit ENTER key to continue . . . ";
    cin.get();

    //Sort all of them, on AGE key, in the decreasing order!
    cout << "\n\nSort by zip in decreasing:\tName\t\t\t\t    Zip\t\tAge";
    x.shellSort(data);
    x.printThem(data);
    cout << "\nHit ENTER key to continue . . . ";

    do { //Do something with key age
        cout << "\n\nPlease input an zip to search : ";
        cin  >> tgt;
        loc = x.findIt(data, tgt);
        if (loc > -1)
        {
            cout << "\n\n\t\tI am lucky, data at position " << loc + 1;
            cout << "\n\t" << data[loc].name << "  " << data[loc].address << " "
                 << data[loc].city << " " << data[loc].st << " " << data[loc].zip
                 << " " << data[loc].age;
        }
        else {
            cout << "\n\t\tNo record with zip " << tgt;
        }
        cout << "\n\n\t\tDo more (Y/N) ? ";
        cin  >> more;
    } while (more == 'y' || more == 'Y');

    return 0;
}