# 🏫 DIU Smart Campus Simulation (OpenGL)

A 2D Computer Graphics simulation of the **Daffodil International University (DIU)** campus, built using **C++** and **OpenGL (GLUT)**. This project demonstrates core graphics algorithms, geometric transformations, and interactive animation logic to create a "Smart City" environment.

## 🚀 Key Features

### 1. 🌤️ Dynamic Environment
* **Day/Night Cycle:** Realistic lighting changes based on simulated time.
* **Smart Lighting:** Street lights automatically turn on when the sun goes down.

### 2. 🚦 Smart Traffic System
* **Traffic Control:** Cars automatically stop at **Red Lights** and move on **Green Lights**.
* **Collision Avoidance:** Intelligent braking logic prevents cars from crashing into each other.

### 3. 🌬️ Interactive Physics
* **Wind Simulation:** Adjustable wind speed affects:
    * Trees (swaying animation).
    * Balloons (bobbing intensity).
    * Clouds (movement speed).
* **Security Gate:** Interactive entry gate that can be raised or lowered.

### 4. ⚡ Renewable Energy & Landmarks
* **Windmills:** Rotating windmills that can be toggled on/off.
* **Solar Panels:** Models of green energy infrastructure.
* **Architecture:** Custom drawing of AB-04, Clock Tower, and Trees.

---

## 🎮 Controls

Use your keyboard to interact with the simulation:

| Key | Action | Details |
| :--- | :--- | :--- |
| **`D`** | **Day/Night** | Advance time manually to see lighting changes. |
| **`W`** | **Wind Control** | Increase wind intensity (Levels: 0, 1, 2, 3). |
| **`S`** | **Windmill** | Start or Stop the windmill rotation. |
| **`G`** | **Gate** | Open or Close the main security gate. |
| **`ESC`** | **Exit** | Close the program. |

---

## 🛠️ Tech Stack & Algorithms

* **Language:** C++
* **Library:** OpenGL (GLUT/FreeGLUT)
* **Core Concepts:**
    * **Midpoint Circle Algorithm:** Used for drawing circular objects (Sun, Wheels, Balloons).
    * **Bresenham's Line Algorithm:** Used for structural lines and rays.
    * **2D Transformations:** Translation, Rotation, and Scaling for animations.

---

## ⚙️ How to Run

### Prerequisites
* C++ Compiler (GCC/MinGW)
* OpenGL & GLUT Libraries

### Compilation Commands

**On Windows (Code::Blocks / MinGW):**
Ensure `freeglut` is linked in your project settings.
```bash
-lfreeglut -lopengl32 -lglu32
