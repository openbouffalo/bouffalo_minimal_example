  .section .text
  .global start
start:
  la sp, __stack_end
  jal main