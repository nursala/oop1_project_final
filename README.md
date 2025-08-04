# 💣 Bomberman Game - Final OOP1 Project

🎮 A C++ arcade-style game inspired by Bomberman, developed as a final project for the Object-Oriented Programming course. The game uses the SFML library for graphics and applies core OOP principles like polymorphism, inheritance, RTTI, and Singleton.


## 🧩 Gameplay Overview
Players must escape levels by finding hidden doors under rocks while avoiding or eliminating enemies using bombs. Collectible gifts give time, lives, or advantages, some of which are hidden under destructible blocks.

## 🧠 Programming Concepts Used
- **Object-Oriented Programming** (classes, inheritance, polymorphism)
- **RTTI** (Run-Time Type Identification)
- **Singleton pattern** (for resource managers)
- **Smart Pointers**: `std::unique_ptr`
- **Vectors**, arrays, maps for data structures

## 📦 Key Components

### Main Modules
- `main.cpp`: Launches the game and initializes the `Controller`
- `Controller.cpp`: Core game logic and screen manager
- `Window.cpp`: Manages rendering window
- `StatusBar.cpp`: Displays game status (score, time, lives)
- `Button.cpp`: UI buttons

### Screens (`screensSrc/`)
- `HomeScreen`, `GameScreen`, `Pause`, `WinScreen`, `LossScreen`, `Help`
- `Screen.cpp`: Base class for all screens

### Game Board & Logic
- `Board.cpp`: Manages objects and level updates
- `PlayList.txt`: Stage configuration

### Game Objects
- `StaticObject.cpp`: Base for walls, rocks, doors, gifts
- `UpdatingObject.cpp`: Base for moving/updating entities (robots, guards, bombs)
- `Bomb.cpp`, `Splash.cpp`, `Robot.cpp`, `Guard.cpp`, etc.

### Resource Management (`ResourceManager/`)
- `TextureManager.cpp`, `SoundManager.cpp`: Singleton classes
- `LevelManager.cpp`: Loads stage data

## 🔊 Game Elements
Symbols used in levels:
- `#`: Wall (unbreakable)
- `@`: Rock (breakable)
- `D`: Door (can be hidden)
- `/`: Robot
- `!`: Guard
- `B`: Bonus time
- `A`: Extra life
- `F`: Freeze guards
- `R`: Remove one guard

## 🎮 Known Features
- Guards move using a mix of AI (IQ-based) and randomness
- Limited bomb placement (3 at a time)
- Rewards for defeating enemies or completing levels
- Smart screen resizing and object scaling

## 🐞 Known Bugs
- Some effects (e.g., death animations) reset objects
- Gifts/doors may appear under destructible tiles randomly

## 🧪 Build & Run Instructions

1. Install [SFML](https://www.sfml-dev.org/)
2. Clone the repo:
   ```bash
   git clone https://github.com/nursala/oop1_project_final.git
   cd oop1_project_final
