#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
using namespace std;

class Point
{
public:
    int x, y;
};

class Poly
{
private:
    Point p[4]; // Four points for a square

public:
    void intiz()
    {
        // Define fixed points for a square
        p[0] = {200, 200}; // Top-left
        p[1] = {400, 200}; // Top-right
        p[2] = {400, 400}; // Bottom-right
        p[3] = {200, 400}; // Bottom-left
    }

    void fill()
    {
        int ymin = p[0].y, ymax = p[0].y;

        // Find the bounding box
        for (int i = 0; i < 4; i++)
        {
            if (p[i].y < ymin)
                ymin = p[i].y;
            if (p[i].y > ymax)
                ymax = p[i].y;
        }

        // Scan fill
        for (int s = ymin; s <= ymax; s++)
        {
            int inter[2], c = 0; // Store intersections
            for (int i = 0; i < 4; i++)
            {
                int x1 = p[i].x, y1 = p[i].y;
                int x2 = p[(i + 1) % 4].x, y2 = p[(i + 1) % 4].y;

                // Ensure y1 <= y2
                if (y1 > y2)
                    swap(x1, x2), swap(y1, y2);

                // Check for intersection with the scan line
                if (s >= y1 && s <= y2)
                {
                    if (y2 != y1)
                    {                                                       // Avoid division by zero
                        inter[c++] = (x2 - x1) * (s - y1) / (y2 - y1) + x1; // Calculate intersection
                        // inter[c++] = (dx) * (s - y1) / (dy) + x1;
                    }
                }
            }

            // Draw filled line if we have a valid pair of intersections
            if (c % 2 == 0)
            { // Ensure we have an even number of intersections
                for (int i = 0; i < c; i += 2)
                {
                    line(inter[i], s, inter[i + 1], s); // Fill between intersections
                }
                delay(50);
            }
        }
    }
};

int main()
{
    initwindow(500, 600);
    Poly sq;
    sq.intiz();
    setcolor(YELLOW);
    sq.fill();    // Fill the polygon
    delay(5000);  // Wait for 5 seconds
    closegraph(); // Close graphics window
    getch();      // Wait for a key press
    return 0;     // Exit program
}