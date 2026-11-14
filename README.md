# von-neumann-vm

A simulation of the von Neumann architecture written in C.

### Basic Commands:

---

'1' - Load accumulator from memory address\
'2' - Add memory value to accumulator\
'3' - Subtract memory value from accumulator\
'0' - Halt program

## How to Use:

**Example of `program.txt`**

```
0       - interrupt vector
10 5 3  - data
1 1     - opcode, address
2 2     - opcode, address
3 3     - opcode, address
0       - halt program
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
pc = 4, command = 1, operand = 10, acc = 10
pc = 6, command = 2, operand = 5, acc = 15
pc = 8, command = 3, operand = 3, acc = 12
pc = 10, command = 0, operand = no. The program is completed
```
