---
title: Release notes
nav_order: 99
---

![MPLAB® Harmony Graphics Suite](./docs/images/mhgs.png) Microchip MPLAB® Harmony 3 Graphics Application Examples for PIC32CZ CA Family
# Microchip MPLAB® Harmony 3 Release Notes

## MPLAB® Harmony 3 Graphics Application Examples for PIC32CZ CA Family v3.0.0-E1

### Development kit and demo application support

Following table provides number of peripheral library examples available for different development kits.

| Development Kits  | MPLABx applications |
|:-----------------|:-------------------:|
| PIC32CZ CA Curiosity     | 5 |
|

## Release v3.0.0-E1

### New Features

New features added in this release are as follows:

- Added Legato Quickstart using LCC with maXTouch on WQVGA Display
- Added Legato Adventure using LCC with maXTouch on WQVGA Display
- Added Legato Benchmark using LCC with maXTouch on WQVGA Display
- Added Legato External Resources using LCC with maXTouch on WQVGA Display
- Added Blank Quickstart using LCC with maXTouch on WQVGA Display

### Known Issues

The current known issues are as follows:

- Reading the RLE image from the SQI on Legato External Resources is very slow.  The problem is still under investigation.

### Development Tools

- [MPLAB® X IDE v6.05 or later](https://www.microchip.com/mplab/mplab-x-ide)
- [MPLAB® XC32 C/C++ Compiler v4.20 or later](https://www.microchip.com/mplab/compilers)
- MPLAB® X IDE plug-ins:
    - [MPLAB® Code Configurator (MCC) v5.2.2 or above](https://github.com/Microchip-MPLAB-Harmony/mplabx-plugin)
    - MPLAB® Code Configurator (MCC) Core v5.4.14 or above

### Dependent Components

* [GFX v3.12.0](https://github.com/Microchip-MPLAB-Harmony/gfx/releases/tag/v3.12.0)
* [USB v3.11.0-E1](https://github.com/Microchip-MPLAB-Harmony/usb/releases/tag/v3.11.0-E1)
* [CSP v3.15.0-E1](https://github.com/Microchip-MPLAB-Harmony/csp/releases/tag/v3.15.0-E1)
* [DEV_PACKS v3.15.0-E1](https://github.com/Microchip-MPLAB-Harmony/dev_packs/releases/tag/v3.15.0-E1)
* [BSP v3.15.0-E1](https://github.com/Microchip-MPLAB-Harmony/bsp/releases/tag/v3.15.0-E1)
