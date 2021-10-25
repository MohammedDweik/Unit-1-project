#include <iostream>
#include <string>
#include <windows.h>
#include <cmath>
using namespace std;

//function to calculate total windows and doors
//used unsigned int to enter the 10-digit item number for challenge
int add(int x, int y)
{
    return x * 16 + y * 9;
}

//function to calculate total material cost
float materialcost(float l, float w, float h, float t)
{
    return ((l * h * 2) + (h * w * 2) + (l * w) - t) * 3;
}

//function to calculate total material post tax cost
float multiply(float pre)
{
    return (pre * 0.13) + pre;
}

//function to calculate final total hours
float totalhours(float a, float b, float c, float t)
{
    return ((a * c * 2) + (c * b * 2) + (a * b) - t) / (66);
}

//function to calculate total cost for hours work
float costhours(float d, float e, float f, float t)
{
    return (((d * f * 2) + (f * e * 2) + (d * e) - t) / (66) * 22.5 * 0.13) + ((d * f * 2) + (f * e * 2) + (d * e) - t) / (66) * (22.5);
}

//function to round to nearest half hour
float nearesthalf(float z)
{
    return z / 30;

}

int main()
{
    //variables
    string name;
    int window = 9, door = 16;
    float length = 12, width = 12, height = 12, total = 20;
    float pretax = 200, postcost = 300, finaltotalcost = 20;
    float minute = 20, halfhour = 20;

    //to calculate total windows and doors
    cout << "Enter Room Name:\n";
    cin >> name;
    system("cls");

    cout << "Enter amount of Doors:\n";
    cin >> window;
    system("cls");

    cout << "Enter Number of Windows:\n";
    cin >> door;
    system("cls");

    total = add(window, door);

    //to calculate total material cost
    cout << "Enter Room Length in Square Feet:\n";
    cin >> length;
    system("cls");

    cout << "Enter Room Width in Square Feet:\n";
    cin >> width;
    system("cls");

    cout << "Enter Room Height in Square Feet:\n";
    cin >> height;
    system("cls");

    pretax = materialcost(length, width, height, total) * 2;
    cout << "Your Pretax cost is:\n";
    cout << pretax << "$" << endl;

    //to calculate postax cost
    postcost = multiply(pretax);
    cout << "Your Postcost is:\n";
    cout << postcost << "$" << endl;
    
    //to calculate final total hours
    cout << "Total Hours are:\n";
    cout << totalhours(length, width, height, total) * 2 << endl;
    
    //challenge: function to round the nearest hour
    cout << "Nearest integer after round:" << round(totalhours(length, width, height, total) * 2) << endl;

    //challenge: round to the nearest half hour
    floor(totalhours(length, width, height, total) * 2);
    minute = ((totalhours(length, width, height, total) * 2) - floor(totalhours(length, width, height, total) * 2)) * (60);
    halfhour = nearesthalf(minute);
    round(halfhour) * 30;
    cout << "The nearest half hour after round:" << floor(totalhours(length, width, height, total) * 2) << "h" << round(halfhour) * 30 << "m" << endl;

    //to calculate total cost for hours work
    cout << "Total Hours cost is:\n";
    cout << costhours(length, width, height, total) * 2 << "$" << endl;

    //to calculate final total cost for everything
    cout << "Final total cost is:\n";
    finaltotalcost = postcost + costhours(length, width, height, total) * 2;
    cout << finaltotalcost << "$" << endl;

    //challenge: sales receipt
    cout << "********************************************" << endl;
    cout << "********  S A L E S  R E C E I P T  ********" << endl;
    cout << "********************************************" << endl;
    cout << "**      Total Material Cost( 2 coats)     **" << endl;
    cout << "**      pretaxcost=" << pretax << "$                  **" << endl;
    cout << "**      postcost=" << postcost << "$                 **" << endl;
    cout << "**                                        **" << endl;
    cout << "********************************************" << endl;
    cout << "**      total hours=" << totalhours(length, width, height, total) * 2 << "h              **" << endl;
    cout << "**      cost for hours=" << costhours(length, width, height, total) * 2 << "$           **" << endl;
    cout << "**                                        **" << endl;
    cout << "**      final total cost=" << finaltotalcost << "$         **" << endl;
    cout << "**                                        **" << endl;
    cout << "**                                        **" << endl;
    cout << "********************************************" << endl;

    //challenge: ASCII code to output text in colour
    system("Color F0");
}

