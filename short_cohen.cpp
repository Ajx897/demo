#include <graphics.h>
#include <iostream>

using namespace std;

#define INSIDE 0 // 0000
#define LEFT 1   // 0001
#define RIGHT 2  // 0010
#define BOTTOM 4 // 0100
#define TOP 8    // 1000

// Compute region code
int computeCode(float x, float y, float xMin, float yMin, float xMax, float yMax)
{
    int code = INSIDE;
    if (x < xMin)
        code |= LEFT;
    else if (x > xMax)
        code |= RIGHT;
    if (y < yMin)
        code |= BOTTOM;
    else if (y > yMax)
        code |= TOP;
    return code;
}

// Cohen-Sutherland line clipping algorithm
void cohenSutherland(float &x1, float &y1, float &x2, float &y2, float xMin, float yMin, float xMax, float yMax)
{
    int code1 = computeCode(x1, y1, xMin, yMin, xMax, yMax);
    int code2 = computeCode(x2, y2, xMin, yMin, xMax, yMax);

    while (true)
    {
        if (!(code1 | code2)) // Both points inside
            break;
        if (code1 & code2) // Both points outside
            return;

        int codeOut = code1 ? code1 : code2; // Out code
        float x, y;
        float m = (y2 - y1) / (x2 - x1);

        // Find intersection point
        if (codeOut & TOP)
        {
            x = x1 + (yMax - y1) / m; // For top
            y = yMax;
        }
        else if (codeOut & BOTTOM)
        {
            x = x1 + (yMin - y1) / m; // For bottom
            y = yMin;
        }
        else if (codeOut & RIGHT)
        {
            y = y1 + m * (xMax - x1); // For right
            x = xMax;
        }
        else if (codeOut & LEFT)
        {
            y = y1 + m * (xMin - x1); // For left
            x = xMin;
        }

        if (codeOut == code1)
        {
            x1 = x;
            y1 = y;
            code1 = computeCode(x1, y1, xMin, yMin, xMax, yMax);
        }
        else
        {
            x2 = x;
            y2 = y;
            code2 = computeCode(x2, y2, xMin, yMin, xMax, yMax);
        }
    }

    // Draw the clipped line
    setcolor(YELLOW);     // Set color to yellow
    line(x1, y1, x2, y2); // Draw the line
}

int main()
{
    initwindow(800, 600);

    float xMin = 200, yMin = 200, xMax = 600, yMax = 400;
    rectangle(xMin, yMin, xMax, yMax); // Clipping window

    // Original line to be clipped
    float x1 = 100, y1 = 300, x2 = 300, y2 = 300;

    // Draw the original line in white
    setcolor(WHITE);
    line(x1, y1, x2, y2); // Draw the original line

    delay(5000); // Wait for 5 seconds to see the original line
   
    // Delete the original line in white
    setcolor(BLACK);
    line(x1, y1, x2, y2);
    // Perform clipping
    cohenSutherland(x1, y1, x2, y2, xMin, yMin, xMax, yMax); // Clip the line

    delay(5000);  // Wait for 5 seconds to see the clipped line
    closegraph(); // Close graphics window
    return 0;
}
