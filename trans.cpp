#include <graphics.h>
#include <iostream>
#include <cmath>

using namespace std;

// Point structure to hold coordinates
struct Point
{
    float x, y;

    // Overloading + operator for translation
    Point operator+(const Point &other)
    {
        return {x + other.x, y + other.y};
    }

    // Overloading * operator for scaling
    Point operator*(float scale)
    {
        return {x * scale, y * scale};
    }

    // Function to rotate point around the origin
    Point rotate(float angle)
    {
        float rad = angle * (3.14 / 180); // Convert degrees to radians
        return {
            x * cos(rad) - y * sin(rad),
            x * sin(rad) + y * cos(rad)};
    }
};

// Function to draw a triangle using three points
void drawTriangle(Point p1, Point p2, Point p3, int color)
{
    setcolor(color); // Set the color for drawing
    line(p1.x, p1.y, p2.x, p2.y);
    line(p2.x, p2.y, p3.x, p3.y);
    line(p3.x, p3.y, p1.x, p1.y);
}

// Function to clear and redraw the shapes
void drawShapes(Point original[], Point transformed[])
{
    cleardevice(); // Clear the graphics window
    // Draw original shape in white
    drawTriangle(original[0], original[1], original[2], WHITE);

    // Draw the transformed shape based on the  transformations
    drawTriangle(transformed[0], transformed[1], transformed[2], YELLOW);
}

int main()
{
    // Initialize graphics
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Original triangle points
    Point original[3] = {{200, 100}, {300, 100}, {250, 50}};
    Point transformed[3]; // Array to hold transformed points

    // Draw original triangle
    drawShapes(original, transformed);
    delay(2000); // Delay for 2 seconds

    while (true)
    {
        // Menu for transformations
        cout << "Choose a transformation:\n";
        cout << "1. Translate\n";
        cout << "2. Scale\n";
        cout << "3. Rotate\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";

        int choice;
        cin >> choice;

        if (choice == 4)
        {
            break; // Exit the loop
        }

        if (choice == 1)
        {
            // Translation
            Point translation;
            cout << "Enter translation vector (dx, dy): ";
            cin >> translation.x >> translation.y;

            transformed[0] = original[0] + translation;
            transformed[1] = original[1] + translation;
            transformed[2] = original[2] + translation;

            drawShapes(original, transformed);
            delay(2000); // Delay for 2 seconds
        }
        else if (choice == 2)
        {
            // Scaling
            float scale;
            cout << "Enter scale factor: ";
            cin >> scale;

            // Calculate the centroid
            float centerX = (original[0].x + original[1].x + original[2].x) / 3;
            float centerY = (original[0].y + original[1].y + original[2].y) / 3;

            // Scale the points around the centroid
            transformed[0].x = centerX + (original[0].x - centerX) * scale;
            transformed[0].y = centerY + (original[0].y - centerY) * scale;

            transformed[1].x = centerX + (original[1].x - centerX) * scale;
            transformed[1].y = centerY + (original[1].y - centerY) * scale;

            transformed[2].x = centerX + (original[2].x - centerX) * scale;
            transformed[2].y = centerY + (original[2].y - centerY) * scale;

            drawShapes(original, transformed);
            delay(2000); // Delay for 2 seconds
        }
        else if (choice == 3)
        {
            // Rotation
            float angle;
            cout << "Enter rotation angle: ";
            cin >> angle;

            transformed[0] = original[0].rotate(angle);
            transformed[1] = original[1].rotate(angle);
            transformed[2] = original[2].rotate(angle);

            drawShapes(original, transformed);
            delay(2000); // Delay for 2 seconds
        }
        else
        {
            cout << "Invalid choice, please try again.\n";
        }
    }

    // Close the graphics window
    closegraph();
    return 0;
}
