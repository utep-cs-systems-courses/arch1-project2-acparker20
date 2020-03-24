#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h" // setPeriod
#include "led.h" //led control()
#include "switches.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){

  configureClocks(); // setup oscillator, CPU and clocks
  switch_init();
  led_init();

  or_sr(0x18); //CPU off, GIE on

}
