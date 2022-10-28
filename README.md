# Ultimate Hacking Keyboard firmware wit per key lightning functionality.

This repository is a fork of the  of the [Ultimate Hacking Keyboard firmware](https://github.com/UltimateHackingKeyboard/firmware).

Main purpose of this fork is to add ability to configure per key color. 

To acheve this new cacro commands were added:

    COMMAND = set backlight.strategy { functional | constantRgb | perKey}

//1 - use colors from functional coloring if no color for key was specified

    COMMAND = set backlight.perKey.default_coloring BOOLEAN

//first number is index in array of 256 elements
// next 3 numbers are rgb color

    COMMAND = set backlight.perKey.color <number 0-255 (NUMBER)> <number 0-255 (NUMBER)> <number 0-255 (NUMBER)> <number 0-255 (NUMBER)>

//layer index
//slot index
//key index
//index color array that was set with backlight.perKey.color

    COMMAND = set backlight.perKey.change <number 0-255 (NUMBER)> <number 0-255 (NUMBER)> <number 0-255 (NUMBER)> <number 0-255 (NUMBER)>

Example :

    set backlight.strategy perKey
    set backlight.perKey.default_coloring 1
    set backlight.perKey.color 1 255 255 255 // key module
    //key module
    set backlight.perKey.change 0 2 0 1 //key module 0
    set backlight.perKey.change 0 2 1 1 //key module 1
    set backlight.perKey.change 0 2 2 1 //key module 2
