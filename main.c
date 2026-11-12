#include <stdio.h>
#define CPU_STATE_SIZE 8
#define MEMORY_SIZE 256

int main(void)
{
    /*
     * cpu_state[0] - счетчик команд (pc)
     * cpu_state[1] - аккумулятор (acc), хранит текущий результат
     * cpu_state[2] - регистр команд (ir), хранит текущий опкод
     * cpu_state[3] - вектор прерываний (адрес обработчика ошибок)
     * cpu_state[4] - флаг остановки (0 = работает, 1 = остановлен)
     * cpu_state[5] - код последней ошибки (0 = нет ошибки)
     * cpu_state[6] - резерв для будущих расширений
     * cpu_state[7] - резерв для будущих расширений
     */
    int cpu_state[CPU_STATE_SIZE] = {0};

    int memory[MEMORY_SIZE] = {0};

    FILE *f = fopen("program.txt", "r");
    if (f == NULL)
        return -1;

    size_t i = 0;
    while (i < MEMORY_SIZE && fscanf(f, "%d", &memory[i]) == 1)
        i++;

    fclose(f);

    cpu_state[0] = 2;

    int addr = 0;

    while (cpu_state[4] == 0)
    {
        cpu_state[2] = memory[cpu_state[0]];

        switch (cpu_state[2])
        {
        case 1:
            cpu_state[1] += 1;
            printf("pc = %d, command = %d, operand = no, acc = %d\n", cpu_state[0], cpu_state[2], cpu_state[1]);
            // pc++
            cpu_state[0] += 1;
            break;

        case 2:
            cpu_state[1] -= 1;
            printf("pc = %d, command = %d, operand = no, acc = %d\n", cpu_state[0], cpu_state[2], cpu_state[1]);
            // pc++
            cpu_state[0] += 1;
            break;

        case 3:
            addr = memory[cpu_state[0] + 1];
            cpu_state[1] += memory[addr];
            printf("pc = %d, command = %d, operand = %d, acc = %d\n", cpu_state[0], cpu_state[2], addr, cpu_state[1]);
            // pc += 2
            cpu_state[0] += 2;
            break;

        case 0:
            cpu_state[4] = 1;
            printf("pc = %d, command = %d, operand = no, acc = %d. The program is completed.\n", cpu_state[0], cpu_state[2], cpu_state[1]);
            break;

        default:
            cpu_state[4] = 1;
            break;
        }
    }

    return 0;
}