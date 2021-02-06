## ETS2-and-ATS-can-dashboard
Using a can-bus dashboard on the ETS2 and ATS game

## How to install:
copy the **dash_plugin.dll** and **dash_plugin.txt** to your ATS/ETS2 plugin folder, ...\bin\win_x86\plugins or ...\bin\win_x64\plugins.
Edite the **dash_plugin.txt** to change the COM port of the arduino on your PC.
install the MPC2515 library and upload the code to the arduino. 

# Arduino pinout:
| Arduino | MCP2515 |
| GND | GND |
| 5V  | 5V  |
| D2  | INT |
| D10 | CS  |
| D11 | SI  |
| D12 | SO  |
| D13 | SCK |
(https://github.com/autowp/arduino-mcp2515/blob/master/examples/wiring.png)


## next steps:
need some adjust on the fuel and odometer,

## Credits:
 i edit this guy code https://www.youtube.com/watch?v=D1OmAtDfw7A to use the psa Can-bus protocol, and the [ludgwig-v](https://github.com/ludwig-v/) mcp2515 library 
