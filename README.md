# Mission-Possible-55 Final Code
The code for mission possible group 55. 
Chief programmers: Simon Chervenak, Matthew Shu
Temperature Calibration: Ambrose Yang
Autonomous Route Design: Jacob Palosky
Presentation: Leo He

## Programmer Schedule
Note: the full documentation can be found [here](http://help.robotc.net/WebHelpVEX/index.htm).

1) Drive code. We need to write this first so we can make sure the robot works.
2) Figure out method of transmission
3) Decide method of movement
 - Autonomous
 - Pre-programmed
 - Live Control (do we have controllers?)

## Roadmap
1) Decide which things we should measure/do
   - plant flag
   - measure wind speed (OHML 4+)
   - temperature (4+)
   - salinity (2+)
   - photocell for (4+):
     - position of sun
     - time
     - position of rover
     - other
   - optional
     - albedo
     - seismic activity
     - color mapping of terrain
     - search for magnetism/iron
     - __ph of water or soil__ (seems easier)
     - ultrasonic
     - collect gravel
     - drill for "hydrocarbons"
     - __color recognition__
     - __arduino (raspberry pi)__
     - self-navigation
     - design your own...


## Contributing

All changes should be done in a pull request and approved. (Make a new branch, commit to it, pull request.)

Issues should be denoted as
1) Steps to reproduce.
2) Expected behavior.
3) Pseudocode or general idea to fix.

It will be a good idea to download [GitHub Desktop](https://desktop.github.com). This will facilitate your commiting process.

Milestones for programming should be made **__before__** any commits are made. Make sure to label pull requests/issues as their milestones. Milestone's titles should be descriptive and the description should be short.


## Helpful UART Connection Links

http://cdn.robotc.net/pdfs/cortex/support/VEX_Cortex_UART_Info.pdf
https://evolvedawesome.github.io/VEXSerial/
http://www.savagehomeautomation.com/projects/raspberry-pi-rs232-serial-interface-options-revisit.html
