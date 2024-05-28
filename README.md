# cruise-control

## Getting Started

### Prerequisites

If using VSCode, we recommend installing the [C/C++](vscode:extension/ms-vscode.cpptools) and [Kieler](vscode:extension/kieler.keith-vscode) extensions for syntax highlighting, code formatting, and code visualisation.

You need to compile the Esterel code to C code using the Esterel compiler. You can access this by opening Ubuntu via [FlexIT](http://flexit.auckland.ac.nz/), and making sure you have the preinstalled Esterel compiler in your PATH with the following command:

```bash
export PATH=$PATH:/opt/esterelv6_01/bin
```

## Use the XES Simulator

To compile and run the XES simulator, use the following commands:

```bash
make src/cruiseControl.xes
./src/cruiseControl.xes
```
