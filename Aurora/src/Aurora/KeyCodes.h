#pragma once

// These keycodes follow the GLFW keycodes.
// Taken from the GLFW3.h header file.
// https://www.glfw.org/docs/latest/group__keys.html

#define AURORA_KEY_UNKNOWN            -1 // Unknown key

#define AURORA_KEY_SPACE              32  // Spacebar
#define AURORA_KEY_APOSTROPHE         39  // Apostrophe (')
#define AURORA_KEY_COMMA              44  // Comma (,)
#define AURORA_KEY_MINUS              45  // Minus (-)
#define AURORA_KEY_PERIOD             46  // Period (.)
#define AURORA_KEY_SLASH              47  // Slash (/)
#define AURORA_KEY_0                  48  // 0
#define AURORA_KEY_1                  49  // 1
#define AURORA_KEY_2                  50  // 2
#define AURORA_KEY_3                  51  // 3
#define AURORA_KEY_4                  52  // 4
#define AURORA_KEY_5                  53  // 5
#define AURORA_KEY_6                  54  // 6
#define AURORA_KEY_7                  55  // 7
#define AURORA_KEY_8                  56  // 8
#define AURORA_KEY_9                  57  // 9
#define AURORA_KEY_SEMICOLON          59  // Semicolon (;)
#define AURORA_KEY_EQUAL              61  // Equal (=)
#define AURORA_KEY_A                  65  // A
#define AURORA_KEY_B                  66  // B
#define AURORA_KEY_C                  67  // C
#define AURORA_KEY_D                  68  // D
#define AURORA_KEY_E                  69  // E
#define AURORA_KEY_F                  70  // F
#define AURORA_KEY_G                  71  // G
#define AURORA_KEY_H                  72  // H
#define AURORA_KEY_I                  73  // I
#define AURORA_KEY_J                  74  // J
#define AURORA_KEY_K                  75  // K
#define AURORA_KEY_L                  76  // L
#define AURORA_KEY_M                  77  // M
#define AURORA_KEY_N                  78  // N
#define AURORA_KEY_O                  79  // O
#define AURORA_KEY_P                  80  // P
#define AURORA_KEY_Q                  81  // Q
#define AURORA_KEY_R                  82  // R
#define AURORA_KEY_S                  83  // S
#define AURORA_KEY_T                  84  // T
#define AURORA_KEY_U                  85  // U
#define AURORA_KEY_V                  86  // V
#define AURORA_KEY_W                  87  // W
#define AURORA_KEY_X                  88  // X
#define AURORA_KEY_Y                  89  // Y
#define AURORA_KEY_Z                  90  // Z
#define AURORA_KEY_LEFT_BRACKET       91  // Left Bracket ([)
#define AURORA_KEY_BACKSLASH          92  // Backslash (\)
#define AURORA_KEY_RIGHT_BRACKET      93  // Right Bracket (])
#define AURORA_KEY_GRAVE_ACCENT       96  // Grave Accent (`)
#define AURORA_KEY_WORLD_1            161 // Non-US #1
#define AURORA_KEY_WORLD_2            162 // Non-US #2

/* Function keys */
#define AURORA_KEY_ESCAPE             256 // Escape
#define AURORA_KEY_ENTER              257 // Enter
#define AURORA_KEY_TAB                258 // Tab
#define AURORA_KEY_BACKSPACE          259 // Backspace
#define AURORA_KEY_INSERT             260 // Insert
#define AURORA_KEY_DELETE             261 // Delete
#define AURORA_KEY_RIGHT              262 // Right Arrow
#define AURORA_KEY_LEFT               263 // Left Arrow
#define AURORA_KEY_DOWN               264 // Down Arrow
#define AURORA_KEY_UP                 265 // Up Arrow
#define AURORA_KEY_PAGE_UP            266 // Page Up
#define AURORA_KEY_PAGE_DOWN          267 // Page Down
#define AURORA_KEY_HOME               268 // Home
#define AURORA_KEY_END                269 // End
#define AURORA_KEY_CAPS_LOCK          280 // Caps Lock
#define AURORA_KEY_SCROLL_LOCK        281 // Scroll Lock
#define AURORA_KEY_NUM_LOCK           282 // Num Lock
#define AURORA_KEY_PRINT_SCREEN       283 // Print Screen
#define AURORA_KEY_PAUSE              284 // Pause
#define AURORA_KEY_F1                 290 // F1
#define AURORA_KEY_F2                 291 // F2
#define AURORA_KEY_F3                 292 // F3
#define AURORA_KEY_F4                 293 // F4
#define AURORA_KEY_F5                 294 // F5
#define AURORA_KEY_F6                 295 // F6
#define AURORA_KEY_F7                 296 // F7
#define AURORA_KEY_F8                 297 // F8
#define AURORA_KEY_F9                 298 // F9
#define AURORA_KEY_F10                299 // F10
#define AURORA_KEY_F11                300 // F11
#define AURORA_KEY_F12                301 // F12
#define AURORA_KEY_F13                302 // F13
#define AURORA_KEY_F14                303 // F14
#define AURORA_KEY_F15                304 // F15
#define AURORA_KEY_F16                305 // F16
#define AURORA_KEY_F17                306 // F17
#define AURORA_KEY_F18                307 // F18
#define AURORA_KEY_F19                308 // F19
#define AURORA_KEY_F20                309 // F20
#define AURORA_KEY_F21                310 // F21
#define AURORA_KEY_F22                311 // F22
#define AURORA_KEY_F23                312 // F23
#define AURORA_KEY_F24                313 // F24
#define AURORA_KEY_F25                314 // F25

/* Keypad */
#define AURORA_KEY_KP_0               320 // Keypad 0
#define AURORA_KEY_KP_1               321 // Keypad 1
#define AURORA_KEY_KP_2               322 // Keypad 2
#define AURORA_KEY_KP_3               323 // Keypad 3
#define AURORA_KEY_KP_4               324 // Keypad 4
#define AURORA_KEY_KP_5               325 // Keypad 5
#define AURORA_KEY_KP_6               326 // Keypad 6
#define AURORA_KEY_KP_7               327 // Keypad 7
#define AURORA_KEY_KP_8               328 // Keypad 8
#define AURORA_KEY_KP_9               329 // Keypad 9
#define AURORA_KEY_KP_DECIMAL         330 // Keypad Decimal
#define AURORA_KEY_KP_DIVIDE          331 // Keypad Divide
#define AURORA_KEY_KP_MULTIPLY        332 // Keypad Multiply
#define AURORA_KEY_KP_SUBTRACT        333 // Keypad Subtract
#define AURORA_KEY_KP_ADD             334 // Keypad Add
#define AURORA_KEY_KP_ENTER           335 // Keypad Enter
#define AURORA_KEY_KP_EQUAL           336 // Keypad Equal

#define AURORA_KEY_LEFT_SHIFT         340 // Left Shift
#define AURORA_KEY_LEFT_CONTROL       341 // Left Control
#define AURORA_KEY_LEFT_ALT           342 // Left Alt
#define AURORA_KEY_LEFT_SUPER         343 // Left Super (Windows/Command key)
#define AURORA_KEY_RIGHT_SHIFT        344 // Right Shift
#define AURORA_KEY_RIGHT_CONTROL      345 // Right Control
#define AURORA_KEY_RIGHT_ALT          346 // Right Alt
#define AURORA_KEY_RIGHT_SUPER        347 // Right Super (Windows/Command key)
#define AURORA_KEY_MENU               348 // Menu
