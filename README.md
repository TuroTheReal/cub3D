# CUB3D

## Table of Contents
- [About](#about)
- [Installation](#installation)
- [Usage](#usage)
- [Key Concepts Learned](#key-concepts-learned)
- [Skills Developed](#skills-developed)
- [Project Overview](#project-overview)
- [Map Configuration](#map-configuration)
- [Controls](#controls)
- [42 School Standards](#42-school-standards)


## About

This repository contains my implementation of the **cub3D** project at 42 School.
Cub3D is a graphical project that introduces the fundamental concepts of **ray-casting** to create a dynamic 3D view inside a maze.
Inspired by the legendary **Wolfenstein 3D**, the first true FPS in videogame history, this project demonstrates how to create a pseudo-3D perspective from a 2D map using mathematical algorithms and the MinilibX graphics library.

The project explores the world of computer graphics, teaching how early game engines created immersive 3D experiences with limited computational resources through clever mathematical tricks and optimizations.


## Installation

### Prerequisites
- **MinilibX library** (included in the project)
- **GCC compiler** with support for C99
- **Make** utility
- **X11 development libraries** (Linux) or **AppKit framework** (macOS)

### Compilation
```bash
# Clone the repository
git clone https://github.com/TuroTheReal/cub3D.git
cd cub3D

# Compile the project
make

# Clean object files
make clean

# Clean everything
make fclean

# Recompile
make re
```

## Usage

```bash
# Run the program with a map file
./cub3D maps/map.cub
```


## Key Concepts Learned

### Advanced C Programming
- **Memory Management**: Dynamic allocation for textures and game state
- **Modular Architecture**: Clean separation between parsing, rendering, and game logic
- **Error Handling**: Robust validation and graceful error recovery
- **File I/O**: Reading and parsing map configuration files
-
### Ray-Casting Algorithm
- **Mathematical Foundations**: Understanding trigonometry, vectors, and coordinate systems
- **DDA Algorithm**: Digital Differential Analyzer for efficient line traversal
- **Wall Detection**: Calculating intersections between rays and map boundaries
- **Distance Calculations**: Implementing Euclidean distance with fisheye effect correction

### Graphics Programming
- **MinilibX Mastery**: Pixel manipulation, window management, and event handling
- **Rendering Pipeline**: From ray calculation to pixel drawing
- **Texture Mapping**: Applying wall textures based on ray intersections
- **Performance Optimization**: Efficient algorithms for real-time rendering

### Game Development Fundamentals
- **Player Movement**: Implementing smooth character controls and collision detection
- **Camera Systems**: Understanding field of view and projection matrices
- **Map Parsing**: Reading and validating configuration files
- **Event Management**: Handling keyboard input and window events


## Skills Developed

- **Computer Graphics**: Fundamental understanding of 3D rendering techniques
- **Mathematical Programming**: Practical application of trigonometry and linear algebra
- **Real-time Systems**: Creating smooth, interactive experiences with consistent frame rates
- **Game Engine Architecture**: Building modular, maintainable game systems
- **Graphics Library Usage**: Mastering low-level graphics APIs and pixel manipulation
- **Algorithm Optimization**: Implementing efficient ray-casting for real-time performance
- **Project Architecture**: Designing clean, scalable code for complex graphical applications


## Project Overview

The cub3D project recreates the core mechanics of early 3D games through ray-casting. The program reads a map file containing:

- **Map Layout**: 2D grid representing walls, empty spaces, and player starting position
- **Texture Paths**: References to wall texture files for different surfaces
- **Colors**: Floor and ceiling color specifications
- **Player Configuration**: Starting position and orientation

### Core Components

**Ray-Casting Engine**: The heart of the project, casting rays from the player's position to determine wall distances and heights for each screen column.

**Texture System**: Loading and mapping textures to create realistic wall appearances based on ray intersection points.

**Player Controller**: Smooth movement with collision detection, rotation, and strafing capabilities.

**Map Parser**: Comprehensive validation and loading of map configuration files with error handling.

**Rendering System**: Efficient pixel-by-pixel drawing to create the final 3D perspective view.

## Map Configuration

Map files (`.cub`) must follow this structure:

```
NO ./textures/north_wall.xpm
SO ./textures/south_wall.xpm
WE ./textures/west_wall.xpm
EA ./textures/east_wall.xpm

F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

Where:
- `1` = Wall
- `0` = Empty space
- `N/S/E/W` = Player starting position and orientation
- `NO/SO/WE/EA` = Texture paths for each wall direction
- `F` = Floor color (RGB)
- `C` = Ceiling color (RGB)


## Controls

- **W/A/S/D**: Move forward/left/backward/right
- **Left/Right Arrows**: Rotate camera view
- **ESC**: Exit the program
- **Red Cross**: Close window


## 42 School Standards

### Norm Requirements
- ✅ Maximum 25 lines per function
- ✅ Maximum 5 functions per file
- ✅ Proper indentation and formatting
- ✅ No forbidden functions usage
- ✅ Compilation without warnings (-Wall -Wextra -Werror)

### Project Standards
- ✅ Smooth window management (minimize, resize, close)
- ✅ Comprehensive map validation and error handling
- ✅ Efficient ray-casting implementation
- ✅ Proper texture loading and memory management
- ✅ No memory leaks (validated with valgrind)
- ✅ Clean project structure with appropriate Makefile

### Bonus Features (Optional)
- ✅ Wall collision detection
- ✅ Minimap display
- ✅ Doors that can open/close
- ✅ Animated sprites
- ✅ Mouse look rotation


## 📝 Related Articles

Blog posts documenting the learning process and context behind this project:

- 📝 [42 Piscine and Common Core: What I Learned](https://arthur-portfolio.com/en/blog/42-piscine-and-core-curriculum) — Reflections on 42 School's selection process and 2-year curriculum


---
## Contact

- **GitHub**: [@TuroTheReal](https://github.com/TuroTheReal)
- **Email**: arthurbernard.dev@gmail.com
- **LinkedIn**: [Arthur Bernard](https://www.linkedin.com/in/arthurbernard92/)

---

<p align="center">
  <img src="https://img.shields.io/badge/Made%20with-C-blue.svg"/>
  <img src="https://img.shields.io/badge/Graphics-MinilibX-green.svg"/>
  <img src="https://img.shields.io/badge/Technique-Ray--Casting-red.svg"/>
</p>
