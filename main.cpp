// UAS-Coding-Challenge-2020.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>

void IntersectCheck(double X, double Y, double R, double A, double B, double C);


int main()
{
    //Finds values to check for  
    int line1x, line1y;
    int line2x, line2y;
    double circlex, circley, circler;
    double slope, A, B, C, D, theta,xint1,xint2,yint1,yint2;

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

    //Find point slope form
    slope = static_cast<double>(line2y - line1y) / static_cast<double>(line2x - line1x);
    D = line1y - (slope * line1x);

    //Find Standard form (where slope = -(A/B), -C=Ax+By)
    A = -(line2y - line1y);
    B = (line2x - line1x);
    C = -(A*(line1x)+B*(line1y));
    

    IntersectCheck(circlex, circley, circler, A, B, C);

    //Find Intercepts if Distance > R
    //If theta > 0, two intersect, if = 0, tangent, if < 0, no intersect
    //Basically reverse engineering the substitution method to find exact point location using circle and line formula.
  
    theta = (pow(circler, 2)) * (1 + pow(slope, 2)) - pow((circley - slope * circlex - D), 2);
    if( theta > 0) {
        xint1 = (circlex + circley * slope - D * slope + sqrt(theta)) / (1 + pow(slope, 2));
        xint2 = (circlex + circley * slope - D * slope - sqrt(theta)) / (1 + pow(slope, 2));
        yint1 = (D + circlex*slope +circley*pow(slope,2) +slope*sqrt(theta))/ (1 + pow(slope, 2));
        yint2 = (D + circlex * slope + circley * pow(slope, 2) - slope * sqrt(theta)) / (1 + pow(slope, 2));
        std::cout << xint1 << "," << yint1 << "\n";
        std::cout << xint2 << "," << yint2 << "\n";
    }
    
    return 0;

}

void IntersectCheck(double X, double Y, double R, double A, double B, double C) {
    double Distance;
    //Use Shortest Distance from point to a line formula, using the centre of the circle (|A*x+B*Y+C|/sqrt(A^2+b^2))
    Distance = (abs(A * X + B * Y + C)) / sqrt(pow(A,2)+pow(B,2));
    if (Distance > R) {
        std::cout << "\n\nNo Intersection\n";
    }
    if (Distance == R) {
        std::cout << "\n\nOne Intersection\n";
    }
    if (Distance < R) {
        std::cout << "\n\nTwo Intersection\n";
        std::cout << "Points at:\n";
    }
    return;
}
