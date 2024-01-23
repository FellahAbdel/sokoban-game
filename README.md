# Sokoban Game

This project revolves around one of the oldest and most renowned games globally. We have implemented its simplest version using the C programming language.

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)

## Features

We have developed two versions of the game: a console version and a graphic version utilizing the SDL graphic library. This means that players can engage with the game either through the terminal or in a pop-up window. The key elements in the game include:

- `@`: Player
- `$`: Box
- `.`: Goals
- `#`: Walls

## Installation

To enjoy the game, follow the steps below. It's important to install the SDL library beforehand.

```bash
$ git clone https://github.com/FellahAbdel/sokoban-game.git
$ cd sokoban-game
$ git switch parti2sdl
```

## Usage

Using the game is straightforward; simply execute the following bash commands.

```bash
$ make              # Compile the program
$ make console      # Launch the game in console mode
$ make sdl          # Launch the game in SDL (graphic) mode
```

In console mode, the game appears as follows:

Use the following keys to navigate:

- `j`: Down
- `k`: Up
- `l`: Right
- `j`: Left

Live demo :
[console live demo](./console-demo.webm)

In SDL mode, use the arrow keys for movement.

[sdl live demo](./sdl-demo.webm)
