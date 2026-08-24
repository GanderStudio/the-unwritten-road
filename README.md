# The Unwritten Road

The Unwritten Road is a 2D top-down action roguelike built with C++ and SDL3.

This repository is a full rebuild of my original working demo. The original version worked, but the code became difficult to update and improve. With this rebuild, I want to keep the game and its ideas while using a proper INPUT → UPDATE → RENDER loop, avoiding spaghetti code, and actually understanding what I am writing along the way.

## Current status

Early development. The SDL3 window, renderer, and basic game loop are working. The project now uses a `Game` class that keeps setup, input, update, render, and shutdown separate instead of leaving everything inside `main.cpp`.
