#Makefile config.
COMMON_OBJECTS =
CPU		= msp430g2553
CFLAGS		= -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)

CC		= msp430-elf-gcc
AS		= msp430-elf-as

all: buzzer.elf

buzzer.elf: ${COMMON_OBJECTS} main.o switch_state_machine_assembly.o p1_interrupt_handler.o switches.o switch_state_machine.o led.o buzzer.o ../project/lib/libTimer.a
	${CC} $(CFLAGS) $(LDFLAGS) -o $@ $^

load: buzzer.elf
	msp430loader.sh buzzer.elf

clean:
	rm -f *.o *.elf

main.c: buzzer.h led.h switches.h
switches.c: switches.h switch_state_machine.h
led.c: led.h
buzzer.c: buzzer.h
p1_interrupt_handler.c: switches.h
wdInterruptHandler.c: buzzer.h led.h
switch_state_machine.c: led.h switches.h buzzer.h
switch_state_machine_assembly.s: led.h switches.h buzzer.h
