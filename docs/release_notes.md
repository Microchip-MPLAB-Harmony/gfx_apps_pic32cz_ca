---
title: Release notes
nav_order: 99
---

![MPLAB® Harmony Graphics Suite](./images/mhgs.png) Microchip MPLAB® Harmony 3 Graphics Application Examples for PIC32CZ CA Family
# Microchip MPLAB® Harmony 3 Release Notes

## MPLAB® Harmony 3 Graphics Application Examples for PIC32CZ CA Family v3.0.0

### Development kit and demo application support

Following table provides number of peripheral library examples available for different development kits.

| Development Kits  | MPLABx applications |
|:-----------------|:-------------------:|
| PIC32CZ CA Curiosity     | 4 |
|

## Release v3.0.0

### New Features

New features added in this release are as follows:

- Added Legato Quickstart using LCC with maXTouch on WQVGA Display
- Added Legato Adventure using LCC with maXTouch on WQVGA Display
- Added Legato External Resources using LCC with maXTouch on WQVGA Display
- Added Blank Quickstart using LCC with maXTouch on WQVGA Display

### Known Issues

The current known issues are as follows:

- Reading the RLE image from the SQI on Legato External Resources is very slow.  The problem is still under investigation.

### Development Tools

- [MPLAB® X IDE v6.20](https://www.microchip.com/mplab/mplab-x-ide)
- [MPLAB® XC32 C/C++ Compiler v4.35](https://www.microchip.com/mplab/compilers)
- MPLAB® X IDE plug-ins:
    - [MPLAB® Code Configurator (MCC) Plugin v5.5.0](https://github.com/Microchip-MPLAB-Harmony/mplabx-plugin)
    - MPLAB® Code Configurator (MCC) Core v5.7.0

### Dependent Components

* [GFX v3.12.0](https://github.com/Microchip-MPLAB-Harmony/gfx/releases/tag/v3.14.0)
* [CORE v3.13.2](https://github.com/Microchip-MPLAB-Harmony/usb/releases/tag/v3.13.2)
* [USB v3.11.0](https://github.com/Microchip-MPLAB-Harmony/usb/releases/tag/v3.11.0)
* [CSP v3.18.2](https://github.com/Microchip-MPLAB-Harmony/csp/releases/tag/v3.18.2)
* [DEV_PACKS v3.18.1](https://github.com/Microchip-MPLAB-Harmony/dev_packs/releases/tag/v3.18.1)
* [BSP v3.18.0](https://github.com/Microchip-MPLAB-Harmony/bsp/releases/tag/v3.18.0)
