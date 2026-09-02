# 
#    Author: Rhythm Winicour-Freeman
#    File: Makefile
#    Description: Project compile, link, and run rules (outdated)
#
CC = arm-none-eabi-gcc
CFLAGS = -c -g -mcpu=cortex-m4 -mthumb -std=gnu11
LDFLAGS = -T -nostdlib linker/stm32_f411re_ls.ld -Wl,-Map=project.map

.PHONY : final clean flash run

final : project.elf

systick.o : src/systick.c
	$(CC) $(CFLAGS) $^ -o $@

gpio.o : src/gpio.c
	$(CC) $(CFLAGS) $^ -o $@

main.o : src/main.c
	$(CC) $(CFLAGS) $^ -o $@

stm32_f411re_startup.o : startup/stm32_f411re_startup.c
	$(CC) $(CFLAGS) $^ -o $@

project.elf : main.o stm32_f411re_startup.o gpio.o systick.o
	$(CC) $(LDFLAGS) $^ -o $@

project.bin : project.elf
	arm-none-eabi-objcopy -O binary project.elf project.bin

flash :
	openocd -f board/st_nucleo_f4.cfg

run :
	openocd -f board/st_nucleo_f4.cfg -c "program project.elf verify reset exit"

clean :
	rm -rf *.o *.elf *.map *.bin
