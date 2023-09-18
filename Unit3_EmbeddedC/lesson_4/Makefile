# Prepared by Loay Tamer 

CC 	   = arm-none-eabi-
CFLAGS =  -gdwarf-2 -g -mcpu=cortex-m4 -mthumb
INCS   = -I .
LIBS   = 
SRC    = $(wildcard *.c)
OBJ    = $(SRC:.c=.o)

PROJECT_NAME = toggle_led_tivaC
all: $(PROJECT_NAME).bin
	@echo "===== Build is done ====="

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

$(PROJECT_NAME).elf: $(OBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ)  -o $@ -Map=Map_file.map
	cp $@ $(PROJECT_NAME).axf

$(PROJECT_NAME).bin: $(PROJECT_NAME).elf
	$(CC)objcopy.exe  $< -O binary $@

clear_all:
	rm *.o *.bin *.elf

clear:
	rm *.bin *.elf

