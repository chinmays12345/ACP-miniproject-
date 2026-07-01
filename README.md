# 2D Graphics Editor in C

## Overview

This project is a simple 2D Graphics Editor developed in C using a 2D character array.

The editor allows the user to draw different shapes using '*' characters on the console screen.

Empty spaces are represented using '_' characters.

---

## Features

- Draw Rectangle
- Draw Line (Bresenham Algorithm)
- Draw Triangle
- Draw Circle (Midpoint Circle Algorithm)
- Delete Objects
- Modify Objects
- Clear Canvas
- Display Picture
- Menu Driven Interface

---

## Technologies Used

- C Programming Language
- GCC Compiler
- Console Based Graphics

---

## Data Structure Used

A 2D character array is used to represent the drawing canvas.

```c
char canvas[30][60];
```

---

## Algorithms Used

### Rectangle
Nested loops are used to fill the rectangular region.

### Line
Bresenham's Line Drawing Algorithm.

### Circle
Midpoint Circle Algorithm.

### Triangle
Constructed using three lines.

---

## How to Compile

```bash
gcc graphics_editor.c -o graphics_editor -lm
```

Run

```bash
./graphics_editor
```

Windows

```bash
graphics_editor.exe
```

---

## Author

Name: CHINMAY.S

Course: B.Tech CSE

Subject: ACP Mini Project
