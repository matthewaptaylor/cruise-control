# cruise-control

## Getting Started

### Prerequisites

If using VSCode, we recommend installing the [C/C++](vscode:extension/ms-vscode.cpptools) and [Kieler](vscode:extension/kieler.keith-vscode) extensions for syntax highlighting, code formatting, and code visualisation.

You need to compile the Esterel code to C code using the Esterel compiler. You can access this by opening Ubuntu via [FlexIT](http://flexit.auckland.ac.nz/), and making sure you have the preinstalled Esterel compiler in your PATH with the following command:

```bash
export PATH=$PATH:/opt/esterelv6_01/bin
```

*edit*:

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

To compile and run the XES simulator, use the following commands:

```bash
cd src
make cruiseControl.xes
./cruiseControl.xes
```
