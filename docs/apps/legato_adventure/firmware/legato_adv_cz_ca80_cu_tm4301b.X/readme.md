
![](../../../../images/mhgs.png) legato\_adventure\_cz\_ca80\_cu\_tm4301b.X

Defining the Architecture
-------------------------

![](../../../../images/blank_qs_cz_ca80_cu_tm4301b_arch.png)

The architecture for this configuraiton is the PIC32CZ_CA Curiosity Ultra + High-Performance 4.3" WQVGA Display Module with maXTouch® Technology.

User touch input on the display panel is received thru the PCAP capacitive touch controller, which sends a notification to the Touch Input Driver. The Touch Input Driver reads the touch information over I2C and sends the touch event to the Graphics Library thru the Input System Service.

### Demonstration Features 

* Legato Graphics Library
* Input system service and touch driver
* Time system service, timer-counter peripheral library and driver
* 16-bit RGB565 color depth support (65535 unique colors)
* EBI peripheral library and driver
* I2C peripheral library and driver
* JPEG image stored in internal flash

Creating the Project Graph
--------------------------

![](../../../../images/pic32cz_ca80_cu_adv_tm4301b_pg.png)

The Project Graph diagram shows the Harmony components that are included in this application. Lines between components are drawn to satisfy components that depend on a capability that another component provides.

Adding the **PIC32CZ_CA Curiosity Ultra BSP** and **Legato Graphics w/ PDA TM4301B Display** Graphics Template component into the project graph will automatically add the components needed for a graphics project and resolve their dependencies. It will also configure the pins needed to drive the external peripherals like the display and the touch controller.

Building the Application
------------------------

The parent directory for this application is apps/legato_adventure. To build this application, use MPLAB X IDE open the apps/legato_adventure/firmware/legato_adv_cz_ca80_cu_tm4301b.X project file.

The following table lists configuration properties:  

| Project Name  | BSP Used |Graphics Template Used | Description |
|---------------| ---------|---------------| ---------|
| legato_adv_cz_ca80_cu_tm4301b.X |PIC32CZ_CA Curiosity Ultra| Legato Graphics w/ PDA TM4301B Display | Legato GFX on PIC32CZ_CA Curiosity Ultra board with PDA TM4301B 480x272 (WQVGA) Display  |

> \*\*\_NOTE:\_\*\* This application may contain custom code that is marked by the comments // START OF CUSTOM CODE ... and // END OF CUSTOM CODE. When using the MPLAB Harmony Configurator to regenerate the application code, use the "ALL" merging strategy and do not remove or replace the custom code.

Configuring the Hardware
------------------------

The final setup should be: 

![](../../../../images/PIC32CZ_CA_cfg.png)

Configuring the 4.3-inch WQVGA Display requires disconnecting the ribbon cable that connects the display to the interposer board.

![](../../../../images/e70_xu_tm4301b_conf2.png)

First, release the ribbon cable from the interposer board. Next, release the black clamp on the J2 connector and turn the display over. Finally, insert the ribbon cable into J2 and close the clamp.

![](../../../../images/e70_xu_tm4301b_conf3.png)

The board and display are powered by an external power supply connected to J100.

The board can be debug via the on-board EDBG via the **Debug USB** port J200, or by using the ICE4 Debugger and the ICE4 Cortex-M Trace Adapter Board, which are connected as shown above.

Running the Demonstration
-------------------------

The application first boots to an animated Splash Screen. Once the Splash Screen animation completes, the application boots to a Main Screen.

When at rest, the demo will cycle through idle sprite animations. Various areas of the screen are touch interactive

![](../../../../images/legato_adv_wqvga_run1.png)

If initiated to run, the lamb sprite will run to the end of the screen, and play out a sequence of smacking into a wall, hurt and dizzy animations.

![](../../../../images/legato_adv_wqvga_run2.png)

Tap Jump and the lamb will play out a jump animation.

![](../../../../images/legato_adv_wqvga_run3.png)

Info Screen describes the features supported by this demo

![](../../../../images/legato_adv_wqvga_run4.png)

* * * * *
