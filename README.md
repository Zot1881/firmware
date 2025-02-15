# Ultimate Hacking Keyboard firmware wit per key lightning functionality.

This repository is a fork of the  of the [Ultimate Hacking Keyboard firmware](https://github.com/UltimateHackingKeyboard/firmware).

Main purpose of this fork is to add ability to configure per key color. 

To acheve this new macro commands were added:

Enable new coloring scheme via perKey option in backlight.strategy command

    COMMAND = set backlight.strategy { functional | constantRgb | perKey}

Use default coloring from functional coloring if no color for key was specified.

    COMMAND = set backlight.perKey.default_coloring BOOLEAN [0 or 1]

Set color to color map

first number is index in array of 256 elements, next 3 numbers are rgb color

    COMMAND = set backlight.perKey.color <number 0-255 (NUMBER)> <number 0-255 (NUMBER)> <number 0-255 (NUMBER)> <number 0-255 (NUMBER)>

Specify key color that was added to color map.

![uhkv2_scheme_small](https://user-images.githubusercontent.com/14919498/198552064-bc501fbd-5378-4a77-9007-0690c6033d59.JPEG)

layer index

slot index

key index

index color array that was set with backlight.perKey.color

    COMMAND = set backlight.perKey.change <number 0-255 (NUMBER)> <number 0-255 (NUMBER)> <number 0-255 (NUMBER)> <number 0-255 (NUMBER)>

Example :

    set backlight.strategy perKey
    set backlight.perKey.default_coloring 1
    set backlight.perKey.color 1 255 255 255 // key module
    //key module
    set backlight.perKey.change 0 2 0 1 //key module 0
    set backlight.perKey.change 0 2 1 1 //key module 1
    set backlight.perKey.change 0 2 2 1 //key module 2


# Prepare development environment on Ubuntu:

    apt install curl git
    apt install binutils-arm-none-eabi gcc-arm-none-eabi libnewlib-arm-none-eabi make

    curl https://raw.githubusercontent.com/creationix/nvm/master/install.sh | bash 
    source ~/.bashrc 
    nvm install 16.15.0

    git clone --recursive https://github.com/Zot1881/firmware.git

in firmware/lib/agent/

    npm install 
    npm run build

in firmware/scripts

    npm install
    ./generate-versions-h.js
    ./make-release.js
