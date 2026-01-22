DIU Smart Campus Simulation (OpenGL)
A 2D Computer Graphics simulation of the Daffodil International University (DIU) campus, built using C++ and OpenGL (GLUT). This project demonstrates core graphics algorithms, geometric transformations, and interactive animation logic to create a "Smart City" environment.

🎥 Watch Demo Video

🚀 Key Features
Day/Night Cycle: Dynamic lighting changes based on a simulated time of day. Street lights automatically turn on at night.

Smart Traffic System:

Cars respect traffic lights (stop on Red, go on Green).

Collision avoidance logic (cars stop if too close to the car in front).

Interactive Physics:

Wind Simulation: Trees sway and balloons bob based on adjustable wind levels.

Gate Control: Interactive security gate that lifts and closes.

Campus Landmarks:

Academic Building (AB-04).

Solar Panels & Windmills (Renewable Energy).

Clock Tower.

Core Algorithms: Implementation of Midpoint Circle and Bresenham's Line algorithms.

🎮 Controls
Interact with the simulation using the keyboard:

Key	Action
D	Advance Time (Cycle through Day/Night)
W	Change Wind Level (0 to 3 intensity levels)
S	Toggle Windmill (Start/Stop spinning)
G	Toggle Gate (Open/Close security gate)
ESC	Exit the program

🛠️ Tech Stack & Algorithms
Language: C++

Library: OpenGL (GLUT/FreeGLUT)

Concepts Used:

Primitives: GL_POINTS, GL_LINES, GL_TRIANGLES, GL_QUADS, GL_POLYGON.

Transformations: glTranslatef (Movement), glRotatef (Animation), glScalef.

Custom Algorithms:

Midpoint Circle Algorithm (for celestial bodies/wheels).

Bresenham's Line Algorithm (for structural lines).

⚙️ How to Run
Prerequisites
You need a C++ compiler and OpenGL/GLUT libraries installed.

Compilation
On macOS (using Terminal):

Bash

g++ main.cpp -o main -framework OpenGL -framework GLUT -Wno-deprecated
./main
On Linux (Ubuntu/Debian):

Bash

# Install dependencies if not present
sudo apt-get install freeglut3-dev

# Compile and Run
g++ main.cpp -o main -lGL -lGLU -lglut
./main
On Windows (Code::Blocks / MinGW):

Ensure GLUT/FreeGLUT is linked in your linker settings (-lfreeglut -lopengl32 -lglu32).

Build and Run the project.

📂 Project Structure
main.cpp: Contains the source code, including the display() function, state updates, and drawing logic for cars, buildings, and environment.

👨‍💻 Author
Name: [Your Name]

University: Daffodil International University (DIU)

Department: Computer Science and Engineering
