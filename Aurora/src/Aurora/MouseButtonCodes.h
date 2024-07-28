#pragma once

// These keycodes follow the GLFW keycodes.
// Taken from the GLFW3.h header file.
// https://www.glfw.org/docs/latest/group__buttons.html

#define AURORA_MOUSE_BUTTON_UNKNOWN   -1  // Unknown mouse button

#define AURORA_MOUSE_BUTTON_1         0   // Mouse button 1 (typically left button)
#define AURORA_MOUSE_BUTTON_2         1   // Mouse button 2 (typically right button)
#define AURORA_MOUSE_BUTTON_3         2   // Mouse button 3 (typically middle button)
#define AURORA_MOUSE_BUTTON_4         3   // Mouse button 4 (usually the first extra button)
#define AURORA_MOUSE_BUTTON_5         4   // Mouse button 5 (usually the second extra button)
#define AURORA_MOUSE_BUTTON_6         5   // Additional mouse button 6
#define AURORA_MOUSE_BUTTON_7         6   // Additional mouse button 7
#define AURORA_MOUSE_BUTTON_8         7   // Additional mouse button 8

#define AURORA_MOUSE_BUTTON_LAST      AURORA_MOUSE_BUTTON_8
#define AURORA_MOUSE_BUTTON_LEFT      AURORA_MOUSE_BUTTON_1 // Left mouse button
#define AURORA_MOUSE_BUTTON_RIGHT     AURORA_MOUSE_BUTTON_2 // Right mouse button
#define AURORA_MOUSE_BUTTON_MIDDLE    AURORA_MOUSE_BUTTON_3 // Middle mouse button (wheel button)
