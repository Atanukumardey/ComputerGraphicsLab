#include <graphics.h>
#include <conio.h>
#include <thread>

// Define a function pointer type for the drawing function
typedef void (*DrawFunction)();

void drawRectangle() {
    int l = getmaxx() / 2 - 100,
        t = getmaxy() / 2 - 100,
        r = getmaxx() / 2 + 100,
        b = getmaxy() / 2 + 50;

    bar(l, t, r, b);
}


void initialization(DrawFunction drawFunc) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*) "C:\\TC\\BGI");

    // Set text color
    setcolor(YELLOW);

    // Display animated text
    int x = getmaxx() / 2 - 110;
    int y = 10;

    for (int i = 0; i < 100; i++) {
        // Clear the screen
        cleardevice();

        // Draw a line
        line(0, 30, getmaxx(), 30);

        // Change text color
        setcolor(i % 15 + 1);

        // Display "ABC"
        outtextxy(x, y, (char*) "ABC");

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

    getch();
    closegraph();
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*) "C:\\TC\\BGI");

    // Set text color
    setcolor(YELLOW);

    // Create threads for initialization and drawing
    std::thread initThread(initialization, drawRectangle);

    // Wait for the initialization thread to finish
    initThread.join();

    // Close the graphics window
    closegraph();

    return 0;
}
