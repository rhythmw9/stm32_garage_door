/* 
    Author: Rhythm Winicour-Freeman
    File: stm32_f411re_startup.c
    Description: Startup file for stm32f411re application
*/

#include <stdint.h>


/* external symbols defined in the linker script */
extern uint32_t _estack;
extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;
extern uint32_t _sidata;


/* Function prototypes */
void Reset_Handler(void);
int main(void);

/* 
    essential interrupt handler prototypes
        -this specific attribute allows the handlers to be overridden by explicitly named handlers with the same name elseware
*/
void NMI_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void MemManage_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
// need to add a prototype for each peripheral/module that uses interrupts


/* This array defines the MCUs interrupt vector table, placed in the .isr_vector_tbl section defined in the linker script */
uint32_t vector_tbl[] __attribute__ ((section(".isr_vector_tbl"))) =
{
    (uint32_t)&_estack,
    (uint32_t)&Reset_Handler,
    (uint32_t)&NMI_Handler,
    (uint32_t)&HardFault_Handler,
    (uint32_t)&MemManage_Handler
};


/* Universal fallback for any ISR that has not been implemented 
        -infinite while loop is better than an undefined state
*/
void Default_Handler(void)
{
    while(1)
    {
        // infinite loop
    }
}


/* This function prepares the system for execution before main */
void Reset_Handler(void)
{
    // initialize pointers for copying from flash to ram
    uint32_t* mem_src_ptr = (uint32_t*)&_sidata; // end addr of the .text section in flash (same as the start of the data section)
    uint32_t* mem_dst_ptr = (uint32_t*)&_sdata; // start addr of the .data section in flash

    // copy data section from flash to sram
    while(mem_dst_ptr < &_edata)
    {
        *mem_dst_ptr = *mem_src_ptr; 
	    ++mem_dst_ptr; 
	    ++mem_src_ptr; 
    }

    // initalize the pointer for .bss section zeroing
    mem_dst_ptr = (uint32_t*)&_sbss;

    // zero the .bss section
    while(mem_dst_ptr < &_ebss)
    {
        *mem_dst_ptr = 0;
	    ++mem_dst_ptr;
    }

    // enter main
    main();

    // deafult fallback
    Default_Handler();
}
