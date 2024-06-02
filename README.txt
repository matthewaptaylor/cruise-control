# cruise-control

## Getting Started

### Prerequisites

If using VSCode, we recommend installing the [C/C++](vscode:extension/ms-vscode.cpptools) and [Kieler](vscode:extension/kieler.keith-vscode) extensions for syntax highlighting, code formatting, and code visualisation.

### Installing with FlexIT

You need to compile the Esterel code to C code using the Esterel compiler. You can access this by opening Ubuntu via [FlexIT](http://flexit.auckland.ac.nz/), and making sure you have the preinstalled Esterel compiler in your PATH with the following command:

```bash
export PATH=$PATH:/opt/esterelv6_01/bin
```

Note that if you try to compile from the VM's mounted virtual disk from your host machine (e.g. `tsclient`), you may encounter issues with the Esterel compiler. Instead, copy the files to the VM's local disk and compile from there.

### Installing without FlexIT

_edit_:

```bash
# PREREQUISTIES:
esterel -version
xes -version
xeve -version

# If they are not found, but installed you may need to symbo-link to /usr/bin
# example:
sudo ln -s /path_to/esterel_distro/bin/xeve /usr/local/bin/xeve
# confirm link:
ls -l /usr/local/bin/xeve
```

```bash
# change line 31 of Makefile --
export ESTEREL= /path_to/esterel_distro

# if errors are thrown, you may need the following libraries:
sudo apt update
# gcc-multilib
sudo apt install gcc-multilib
# 32-bit lib
sudo apt install libc6-dev-i386
# 32-bit x11 devlopment lib
sudo apt install libx11-dev:i386
```

## Use the XES Simulator

To compile the program and run the XES simulator, use the following commands:

```bash
cd src
make cruiseControl.xes
./cruiseControl.xes
```

## Using

The program consists of a top-level module, `CruiseControl`, which instantiates the following modules:

- `StateMachine`: the state machine that controls the cruise control system and switches between the `OFF`, `ON`, `STDBY`, and `DISABLE` states.
- `CarDrivingControl`: the module that controls whe throttle output based on the current state of the system, and either the driver's acceleration or the cruise control's target speed.
- `CruiseSpeedManagement`: the module that manages the cruise control's target speed and allows changes to the target speed based on the driver's input.

### Inputs

| Name       | Type    | Description                                        |
| ---------- | ------- | -------------------------------------------------- |
| On         | boolean | Turn the cruise control system on                  |
| Off        | boolean | Turn the cruise control system off                 |
| Resume     | boolean | Resume the cruise control system from STDBY        |
| Set        | boolean | Set the cruise control system to the current speed |
| QuickDecel | boolean | Quickly decelerate the vehicle by a fixed amount   |
| QuickAccel | boolean | Quickly accelerate the vehicle by a fixed amount   |
| Accel      | float   | The driver's acceleration pedal input              |
| Brake      | float   | The driver's brake pedal input                     |
| Speed      | float   | The current speed of the vehicle                   |

### Outputs

| Name        | Type    | Description                                    |
| ----------- | ------- | ---------------------------------------------- |
| CruiseSpeed | float   | The target speed of the cruise control system  |
| ThrottleCmd | float   | The throttle command to be sent to the vehicle |
| CruiseState | integer | The current state of the cruise control system |
