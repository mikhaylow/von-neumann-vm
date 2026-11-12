# von-neumann-vm
A simulation of the von Neumann architecture written in C.

### Basic Commands:
---
'1' - increment the accumulator value by 1\
'2' - decrement the accumulator value by 1\
'3' - add the value from a memory cell (the next cell) to the accumulator

## How to Use:

**Example of `program.txt`**
```
0 10 1 1 3 1 2 0
```

**Compiling**
```
$ make
```

**Running**
```
$ ./main
```

**Expected output**
```
pc = 2, command = 1, operand = no, acc = 1
pc = 3, command = 1, operand = no, acc = 2
pc = 4, command = 3, operand = 1, acc = 12
pc = 6, command = 2, operand = no, acc = 11
pc = 7, command = 0, operand = no, acc = 11. The program is completed.
```