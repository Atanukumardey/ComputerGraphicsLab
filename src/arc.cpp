#include <bits/stdc++.h>
#include <graphics.h>
#include <conio.h>
#include <thread>
using namespace std;

typedef void (*DrawFunction)();

void initialization(DrawFunction drawFunc) {

    int x = getmaxx() / 2 - 110;
    int y = 10;
    int y2 = 30;

    for (int i = 0; i < 100; i++) {
        // Clear the screen
        cleardevice();

        // Draw a line
        line(0, 50, getmaxx(), 50);

        // Change text color
        // setcolor(i % 15 + 1);

        // Display "ABC"
        outtextxy(x, y, (char*) "ABC");
        outtextxy(x, y2, (char*) "Other Staff");

        // Call the provided drawing function
        drawFunc();

        // Delay to create animation effect
        delay(100);

        // Move the text
        x += 10;

        // Reset the position when it reaches the right edge
        if (x >= getmaxx())
            x = getmaxx() / 2 - 110;
    }
}


void drawArc(){     
    int x = getmaxx()/2, 
        y = getmaxy()/2, 
        r = 100, start = 20, 
        end = 170;

    arc(x, y, start, end, r);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*) "C:\\TC\\BGI");

    // Create threads for initialization and drawing
    // std::thread initThread(initialization, drawArc);

    // Wait for the initialization thread to finish
    // initThread.join();
    initialization(drawArc);

    // Close the graphics window
    getch();
    closegraph();

    return 0;
}
