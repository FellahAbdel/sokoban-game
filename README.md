# Sokoban

This project is about one of the oldest famous games in the world. We coded its simplest version by using C programming language.

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)

## Features

We implemented two versions of the game which are the console and the graphic version with the of help the SDL graphic library. That is to say, we could play it via the terminal or in a pop window. You should know the following details :

- `@` : Player
- `$` : Box
- `.` : Goals
- `#` : Walls

## Installation

To experience the game you should follow the steps below, you should install the SDL library before.

```bash
$ git clone https://github.com/FellahAbdel/sokoban-game.git
$ cd
$ git switch parti2sdl
```

## Usage

It's so simple, use the following bash command.

```bash
$ make              # To compile the program
$ make console      # To lunch the game in console mode
$ make sdl          # To lunch the game in sdl (graphic) mode
```

Here is what the game looks like in console mode :

Use the keys below to make moves :

- `j`: Bottom
- `k`: Up
- `l`: Right
- `j`: Left

In the sdl mode, use the left, right, up, and down keys.
