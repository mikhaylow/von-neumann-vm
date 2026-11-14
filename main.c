#include <stdio.h>
#define CPU_STATE_SIZE 8
#define MEMORY_SIZE 256

int init_memory(int *memory);

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

    int status = init_memory(memory);
    if (status != 0)
    {
        return status;
    }

    int addr;

    addr = 0;

    cpu_state[0] = 4;         // адрес первой команды
    cpu_state[3] = memory[0]; // вектор прерываний

    while (cpu_state[4] == 0)
    {
        cpu_state[2] = memory[cpu_state[0]]; // текущая команда
        addr = memory[cpu_state[0] + 1];     // адрес операнда

        if (cpu_state[2] != 0 && (addr < 0 || addr >= MEMORY_SIZE))
        {
            cpu_state[5] = 1;            // код ошибки
            cpu_state[0] = cpu_state[3]; // переход на вектор прерываний
            printf("pc = %d, command = %d, ERROR: out of bounds\n", cpu_state[0], cpu_state[2]);
        }

        switch (cpu_state[2])
        {
        case 1:
            cpu_state[1] = memory[addr];
            printf("pc = %d, command = %d, operand = %d, acc = %d\n", cpu_state[0], cpu_state[2], memory[addr], cpu_state[1]);
            cpu_state[0] += 2;
            break;

        case 2:
            cpu_state[1] += memory[addr];
            printf("pc = %d, command = %d, operand = %d, acc = %d\n", cpu_state[0], cpu_state[2], memory[addr], cpu_state[1]);
            cpu_state[0] += 2;
            break;

        case 3:
            cpu_state[1] -= memory[addr];
            printf("pc = %d, command = %d, operand = %d, acc = %d\n", cpu_state[0], cpu_state[2], memory[addr], cpu_state[1]);
            cpu_state[0] += 2;
            break;

        case 0:
            cpu_state[4] = 1;
            printf("pc = %d, command = %d, operand = no, acc = %d. The program is completed\n", cpu_state[0], cpu_state[2], cpu_state[1]);
            break;

        default:
            cpu_state[4] = 1;
            printf("pc = %d, command = %d, operand = no, acc = %d. The program is completed\n", cpu_state[0], cpu_state[2], cpu_state[1]);
            break;
        }
    }

    return 0;
}

int init_memory(int *memory)
{
    FILE *f = fopen("program.txt", "r");
    if (f == NULL)
        return -1;

    size_t i = 0;
    while (i < MEMORY_SIZE && fscanf(f, "%d", &memory[i]) == 1)
        i++;

    fclose(f);

    return 0;
}