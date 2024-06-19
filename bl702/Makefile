CROSS_COMPILE	= riscv64-elf-
CC				= $(CROSS_COMPILE)gcc
OBJCOPY			= $(CROSS_COMPILE)objcopy

CFLAGS	= -ffreestanding \
		  -ffunction-sections \
		  -fno-builtin \
		  -fno-common \
		  -fno-pie \
		  -mabi=ilp32 \
		  -march=rv32i \
		  -O2 \
		  -std=gnu11 \
		  -Wall \
		  -Wextra \
		  -Wno-unused
LDFLAGS	= -no-pie \
		  -nostdlib \
		  -static \
		  -Wl,-O1 \
		  -Wl,--gc-sections \
		  -Wl,--no-dynamic-linker \
		  -Wl,--no-undefined

app.bin: app.elf
	$(OBJCOPY) -O binary $< $@

app.elf: linker.ld app.c startup.S
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ -T $^

app_flash.bin: app_flash.elf
	$(OBJCOPY) -O binary $< $@

app_flash.elf: linker_flash.ld app.c startup.S
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ -T $^