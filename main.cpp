// Run: g++ main.cpp -o main -framework OpenGL -framework GLUT -Wno-deprecated && ./main
#define GL_SILENCE_DEPRECATION
#ifdef APPLE
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

// --- CONFIGURATION ---
const float PI = 3.1415926f;
int width = 1200;
int height = 700;

// --- STATE VARIABLES ---
float dayTime = 90.0f;       
int windLevel = 0;           
bool redLight = false;
int lightTimer = 0;
float animationTime = 0.0f;

// Control States
float gateLift = 80.0f;
bool isGateOpen = true;
bool spinWindmill = true; 
float windmillAngle = 0.0f;

// --- STRUCTS ---
struct Car { float x, speed, r, g, b, laneY; bool stopped; };
vector<Car> cars;

struct Cloud { float x, y, scale; };
vector<Cloud> clouds;

struct Tree { float x, y; int type; };
vector<Tree> trees;

struct Balloon { float x, y, r, g, b; };
vector<Balloon> balloons;

// --- 1. CORE ALGORITHMS ---

void drawCircleMidpoint(int xc, int yc, int r) {
    int x = 0, y = r;
    int d = 1 - r;
    glBegin(GL_POINTS);
    while (x <= y) {
        glVertex2i(xc + x, yc + y); glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc + y); glVertex2i(xc - x, yc - y);
        glVertex2i(xc + y, yc + x); glVertex2i(xc + y, yc - x);
        glVertex2i(xc - y, yc + x); glVertex2i(xc - y, yc - x);
        if (d < 0) d = d + 2 * x + 3;
        else { d = d + 2 * (x - y) + 5; y--; }
        x++;
    }
    glEnd();
}

void drawLineBresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;
    glBegin(GL_POINTS);
    while (true) {
        glVertex2i(x1, y1);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx) { err += dx; y1 += sy; }
    }
    glEnd();
}

// --- 2. HELPER FUNCTIONS ---

void setColor(float r, float g, float b, float a = 1.0f) {
    glColor4f(r, g, b, a);
}

void drawFilledCircle(float x, float y, float radius) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= 360; i += 10) {
        float theta = i * PI / 180.0f;
        glVertex2f(x + radius * cos(theta), y + radius * sin(theta));
    }
    glEnd();
}

void drawRect(float x, float y, float w, float h, float r, float g, float b) {
    setColor(r, g, b);
    glRectf(x, y, x + w, y + h);
}

void drawText(float x, float y, string text) {
    glRasterPos2f(x, y);
    for (char c : text) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
}

// --- 3. SCENE OBJECTS ---

void drawSolarPanel(float x, float y) {
    // Stand
    drawRect(x, y, 5, 40, 0.5f, 0.5f, 0.5f);
    // Panel (Tilted)
    glBegin(GL_QUADS);
    setColor(0.1f, 0.1f, 0.6f); // Dark Blue
    glVertex2f(x - 20, y + 60);
    glVertex2f(x + 25, y + 60);
    glVertex2f(x + 25, y + 40);
    glVertex2f(x - 20, y + 40);
    glEnd();
    // Grid lines
    glColor3f(0.8f, 0.8f, 0.9f);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(x, y+40); glVertex2f(x, y+60);
    glVertex2f(x-20, y+50); glVertex2f(x+25, y+50);
    glEnd();
}

void drawStreetLight(float x, float y) {
    // Pole (Shortened to 100)
    drawRect(x, y, 5, 100, 0.3f, 0.3f, 0.3f);
    // Arm
    drawRect(x, y+90, 25, 5, 0.3f, 0.3f, 0.3f);
    // Lamp Head
    drawRect(x+20, y+85, 10, 10, 0.2f, 0.2f, 0.2f);
    
    // Light
    bool isNight = sin(dayTime * PI / 180.0f) < 0;
    if (isNight) {
        // Glow
        glEnable(GL_BLEND);
        setColor(1.0f, 1.0f, 0.6f, 0.4f);
        glBegin(GL_TRIANGLES);
        glVertex2f(x+25, y+85);
        glVertex2f(x+5, y);
        glVertex2f(x+45, y);
        glEnd();
        glDisable(GL_BLEND);
        setColor(1.0f, 1.0f, 0.8f); // Bulb ON
    } else {
        setColor(0.4f, 0.4f, 0.4f); // Bulb OFF
    }
    drawFilledCircle(x+25, y+85, 5);
}