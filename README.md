# von-neumann-vm

A simulation of the von Neumann architecture written in C.

### Basic Commands:

---

'1' - Load accumulator from memory address\
'2' - Add memory value to accumulator\
'3' - Subtract memory value from accumulator\
'4' - Jump to memory address\
'5' - Conditional jump\
'0' - Halt program

## How to Use:

**Example of `program.txt`**

```
16
3 1 0
1 1
3 2
5 14
4 6
0
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
pc = 4, command = 1 (LOAD), operand: 1, acc = 3
pc = 6, command = 3 (SUB), operand = 2, acc = 2
pc = 8, command = 5 (JUMP IF ZERO), operand = 14, acc = 2
pc = 10, command = 4 (JUMP), operand = 6
pc = 6, command = 3 (SUB), operand = 2, acc = 1
pc = 8, command = 5 (JUMP IF ZERO), operand = 14, acc = 1
pc = 10, command = 4 (JUMP), operand = 6
pc = 6, command = 3 (SUB), operand = 2, acc = 0
pc = 8, command = 5 (JUMP IF ZERO), operand = 14, acc = 0
pc = 14, command = 0 (HALT), operand = no. The program is completed
```
