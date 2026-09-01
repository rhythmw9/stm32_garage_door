/* 
    Author: Rhythm Winicour-Freeman
    File: stm32_f411re_ls.ld
	Description: Linker script for stm32f411re application
*/


/* Entry point */
ENTRY(Reset_Handler)


/* Memory configuration */
MEMORY
{
	FLASH(rx):ORIGIN =0x08000000,LENGTH =512K
	SRAM(rwx):ORIGIN =0x20000000,LENGTH =128K
}

/* end of stack global symbol to be used in the startup file */
_estack = ORIGIN(SRAM)+LENGTH(SRAM);
 


__max_heap_size = 0x200;
__max_stack_size = 0x400;

/* Memory sections */
SECTIONS
{
     /* first section of output file */
	.text :
	{
	  . = ALIGN(4);
	  *(.isr_vector_tbl)  /* merge all .isr_vector_tbl sections of input files */
	  *(.text)             /* merge all .text sections of input files */
	  *(.rodata)           /* merge all .rodata sections of input files */
	  . = ALIGN(4);
	 _etext = .;          /* Create a global symbol to hold end of text section */
	}>FLASH
	    

    /* second section of output file */
	.data :
	{
	 . = ALIGN(4);
	_sdata = .;   /* Create a global symbol to hold start of data section */
	  *(.data)
	 . = ALIGN(4);
	_edata = .;   /* Create a global symbol to hold end of data section */
	} > SRAM AT> FLASH  /* >(vma) AT> (lma) */

	_sidata = LOADADDR(.data);  /* Get the .data sections flash address */	
	
	/* third section of output file */
	.bss :
	{
	 . = ALIGN(4);
	_sbss = .;  /* Create a global symbol to hold start of bss section */
	*(.bss)  /*merge all .bss sections of input files*/
	 . = ALIGN(4);
	_ebss = .;  /* Create a global symbol to hold end of bss section */
	}> SRAM
}
