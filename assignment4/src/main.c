/**
 * @file main.c
 * @brief Main entry point to the C1M2 Assessment
 *
 * This file contains the main code for the C1M2 assesment. Students
 * are not to change any of the code, they are instead supposed to compile
 * these files with their makefile.
 *
 * @author Arina Sofiyeva
 * @date March 15 2024
 *
 */
#include "../include/common/platform.h"
#include "../include/common/memory.h"
#include "course1.c"

int main() {}
    #ifdef COURSE1
        printf("The function course1 is being called.\n");
        course1();
    #endif
}
