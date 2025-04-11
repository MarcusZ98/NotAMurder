# Not A Murder
A Rail-Shooter Game Made in Unreal Engine 5

## Overview
Not A Murder is a student project created over the summer of 2024 by a small team of three: two programmers and one game designer. The game was developed using Unreal Engine 5 with C++, with the primary goal of learning, experimenting, and improving our skills in game development and Unreal Engine systems.

In Not A Murder, you play as a crow flying through carefully designed levels on a predefined path — engaging enemies, avoiding obstacles, and scoring points along the way.

This project was not only a fun creative exercise but also an opportunity to explore more advanced Unreal systems such as spline-based movement, modular enemy behavior, custom UI frameworks, and save/load systems.

## Features
### Rail-Shooter Gameplay
- Play as a crow locked to a spline-based path through the level.

- Move within a constrained space while the camera smoothly follows the player.

### Spline-Based Systems
- Fully modular spline system used for both player movement and enemy paths.

- Enemy groups dynamically generated and customizable directly in the editor.

### Modular Enemy & Weapon Systems
- Inheritance-based enemy system for easy creation of new enemy types.

- Weapons and projectiles built for flexibility and reuse between player and enemies.

### Score & Stats Tracking
- Game State handles all runtime statistics and scoring.

- Save System retains best scores and ranks for each level.

### Custom UI Framework
- Custom-built widgets with controller support and animated buttons.

- Menus built to be modular and reusable across different screens.

## Team  

| Role        | Name               | Focus Area                          |
|-------------|-------------------|-------------------------------------|
| Programmer  | Marcus Zibung         | Spline Systems, UI, Game Framework  |
| Programmer  | Fabio Pereria  | Player Controls & Movement, Enemy Interaction  |
| Game Designer | Spilios Kehagias   | Level Design, Game Design       |

## Tech Stack
- Unreal Engine 5

- C++

- Blueprint Scripting (for visual logic & editor tooling)

## Development Focus
This project was designed as a learning experience. While we aimed to make a fun and playable prototype, the real goal was to:

- Experiment with Unreal Engine systems we've never used before.

- Develop reusable tools and modular systems.

- Collaborate in a small cross-disciplinary team.

- Build an understanding of good programming structure and game architecture in UE5.

## Running The Project
1. Clone the repository.

2. Open the .uproject file in Unreal Engine 5.

3. Build the project from source (C++).

4. Play the game in-editor.

## Acknowledgements
Special thanks to our teachers, classmates, and the Unreal Engine documentation for helping us out along the way.
