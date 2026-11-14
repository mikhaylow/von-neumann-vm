# von-neumann-vm

A simulation of the von Neumann architecture written in C.

### Basic Commands:

---

'1' - Load accumulator from memory address\
'2' - Add memory value to accumulator\
'3' - Subtract memory value from accumulator\
'4' - Jump to memory address\
'0' - Halt program

## How to Use:

**Example of `program.txt`**

```
20
1 2 3 4 5
0 5 1
1 6
1 7
2 8
3 9
4 19
0
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
pc = 9, command = 1 (LOAD), operand: 6, acc = 0
pc = 11, command = 1 (LOAD), operand: 7, acc = 5
pc = 13, command = 2 (ADD), operand = 8, acc = 6
pc = 15, command = 3 (SUB), operand = 9, acc = 5
pc = 17, command = 4 (JUMP), operand = 19
pc = 19, command = 0 (HALT), operand = no. The program is completed
```
