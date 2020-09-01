// UAS-Coding-Challenge-2020.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>

void IntersectCheck(int X, int Y, int R, int A, int B, int C);


int main()
{
    //Finds values to check for  
    int line1x, line1y;
    int line2x, line2y;
    int circlex, circley, circler;
    int slope, A, B, C;
    int Result;
    std::cout << "This program will calculate if your line intersects along a circle.\n";
    std::cout << "Enter your first point x value, followed by y value\n";
    std::cin >> line1x;
    std::cin >> line1y;
    std::cout << "Enter your second point x value, followed by y value\n";
    std::cin >> line2x;
    std::cin >> line2y;
    std::cout << "Enter your circle main point x value, followed by y value\n";
    std::cin >> circlex;
    std::cin >> circley;
    std::cout << "Enter your circle radius\n";
    std::cin >> circler;

    //Find Standard form (where slope = -(A/B), -C=Ax+By)
    A = -(line2y - line1y);
    B = (line2x - line1x);
    C = -(A*(line1x)+B*(line1y));
    IntersectCheck(circlex, circley, circler, A, B, C);


    return 0;

}

void IntersectCheck(int X, int Y, int R, int A, int B, int C) {
    double Distance;
    //Use Shortest Distance from point to a line formula, using the centre of the circle (|A*x+B*Y+C|/sqrt(A^2+b^2))
    Distance = (abs(A * X + B * Y + C)) / (sqrt(A ^ 2 + B ^ 2));
    if (Distance > R) {
        std::cout << "No Intersection\n";
    }
    if (Distance == R) {
        std::cout << "One Intersection\n";
    }
    if (Distance < R) {
        std::cout << "Two Intersection\n";
    }

    return;
}
