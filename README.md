# cub3D

A small raycasting engine written in **C**, inspired by the rendering technique used by early first-person games.

Developed as part of the 42 curriculum, the project turns a 2D map into a pseudo-3D first-person view using raycasting, texture sampling and player movement.

> This was a collaborative 42 project.

## Highlights

- DDA-style raycasting
- Textured walls
- Configurable floor and ceiling colors
- Player movement and rotation
- Collision checking
- `.cub` configuration parsing
- Map validation and closed-map detection
- XPM texture loading
- MiniLibX rendering on Linux
- Explicit resource cleanup and error handling

## Build

The current Makefile is configured for Linux and MiniLibX.

```bash
make
```

Run the program with a map:

```bash
./cub3D maps/<map>.cub
```

## Controls

| Key | Action |
| --- | --- |
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `←` / `→` | Rotate |
| `Esc` | Quit |

## How it works

For each vertical screen column, a ray is projected from the player's position through the camera plane. The engine determines where that ray intersects the map, calculates the wall distance and projected slice height, then samples the appropriate wall texture.

The parser also validates the map before rendering: texture paths, RGB values, player position, allowed characters and enclosure are checked before the game starts.

## What this project demonstrates

cub3D combines low-level graphics, vector/matrix-style reasoning, parsing, memory management and an event-driven game loop. It is one of the projects where mathematics stops being abstract and immediately becomes visible on screen.

---

Part of my developer portfolio: **[github.com/Overflow-ADW](https://github.com/Overflow-ADW)**  
Professional work: **[Avenue du Web](https://avenueduweb.be)**
