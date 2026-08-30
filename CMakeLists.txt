cmake_minimum_required(VERSION 4.0.0)

project(project LANGUAGES C)

add_executable(project src/main.c 
               startup/stm32_f411re_startup.c 
               src/gpio.c 
               src/systick.c
               src/uart.c)

set_target_properties(project PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

target_compile_options(project PRIVATE -mcpu=cortex-m4 -mthumb -std=gnu11 -g)

target_link_options(project PRIVATE -nostdlib -T ${CMAKE_SOURCE_DIR}/linker/stm32_f411re_ls.ld -Wl,-Map=project.map)

target_link_libraries(project PRIVATE gcc)

