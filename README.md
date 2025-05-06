# OpenGlu-Arm-Example
A simple robotic arm example using OpenGL and GLU, developed as a project for the Computer Graphics course at Universidade Federal do Vale do São Francisco (UNIVASF). Created by João Victor de Oliveira and Gabriela Mota Lages Gomes.  This project demonstrates basic 3D transformations and hierarchical modeling using C++ and OpenGL.
# OpenGL Robotic Arm (OpenGL + GLU)

This project features a simple articulated robotic arm developed using OpenGL and GLU. It was created as part of the **Computer Graphics** course at the **Universidade Federal do Vale do São Francisco (UNIVASF)**.

## 🎯 Objective

To demonstrate core 3D graphics concepts such as hierarchical modeling and geometric transformations (rotation, translation), using a robotic arm structure composed of connected segments.

## 👥 Authors

- João Victor de Oliveira  
- Gabriela Mota Lages Gomes

## 🛠 Technologies

- C++
- OpenGL
- GLU (OpenGL Utility Library)
- FreeGLUT (for window management and input)
- JavaScript

## 🚀 How to Compile and Run

### ✅ Requirements

- A C++ compiler (e.g., `g++`)
- OpenGL and FreeGLUT libraries
- Properly set up `include` and `lib` directories (as provided or configured)

### 💻 Compilation Command (Windows – MinGW or similar)

Assuming you have an `include/` folder with headers and `lib/x64/` folder with `.lib` files:

```bash
g++ -o main.exe main.cpp -I"./include" -L"./lib/x64" -lfreeglut -lopengl32 -lglu32
