OUTPUT_ARCH(riscv)
OUTPUT_FORMAT(elf32-littleriscv)

ENTRY(start)

MEMORY {
  ITCM (rx):  ORIGIN = 0x22010000, LENGTH = 16K
  DTCM (rw):  ORIGIN = 0x42014000, LENGTH = 48K
  WRAM (rw):  ORIGIN = 0x42020000, LENGTH = 64K
  XIP  (rx):  ORIGIN = 0x23000000, LENGTH = 16M
} 

SECTIONS {
  .text ORIGIN(0x23000000) : AT(0x23002000) {
    KEEP(*(.text.start))
    *(SORT_BY_ALIGNMENT(SORT_BY_NAME(.text*)))
    *(SORT_BY_ALIGNMENT(SORT_BY_NAME(.rodata*)))
    *(SORT_BY_ALIGNMENT(SORT_BY_NAME(.srodata*))) 
  }

  /*.rodata 0x23001000 : AT(0x23003000) {
    *(SORT_BY_ALIGNMENT(SORT_BY_NAME(.rodata*)))
    *(SORT_BY_ALIGNMENT(SORT_BY_NAME(.srodata*))) 
  } > XIP*/

  .data : ALIGN(16) {
    __data_flash = LOADADDR(.data);
    __data_start = .;
    *(SORT_BY_ALIGNMENT(SORT_BY_NAME(.data*)))
    *(SORT_BY_ALIGNMENT(SORT_BY_NAME(.sdata*)))
    __data_end = .;
  } > WRAM

  .bss : ALIGN(16) {
    __bss_start = .;
    *(SORT_BY_ALIGNMENT(SORT_BY_NAME(.sbss*)))
    *(SORT_BY_ALIGNMENT(SORT_BY_NAME(.bss*)))
    __bss_end = .;
  } > WRAM

  .stack : ALIGN(16) {
    __stack_start = .;
    . += 0x1000;
    __stack_end = .;
  } > DTCM

}