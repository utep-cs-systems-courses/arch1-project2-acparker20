#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "switch_state_machine.h"
char switch_state_changed;

int state = 0;

static char switch_update_interrupt_sense(){
  char p2val = P2IN;
  // update switch interrupt to detect changes from current button
  P2IES |= (p2val & SWITCHES); // if switch up, sense down
  P2IES &= (p2val |= ~SWITCHES); // if switch down, sense up
  return p2val;
}
void switch_init(){ // setup switch

  P2REN |= SWITCHES; // enables resistors for switches
  P2IE = SWITCHES; // enable interrupts from from switches 
  P2OUT |= SWITCHES; // pull-ups for switches
  P2DIR &= ~SWITCHES; // set switches' bits for input
  switch_update_interrupt_sense();
  switch_interrupt_handler(); //initially read switches
 
}
void switch_interrupt_handler(){
  switch_state_changed = 0;
  char p2val = switch_update_interrupt_sense();
  // when switch is up 
  if(p2val & SW1 ? 0 : 1){
    state = 01;
    switch_state_machine_assembly(state);
  }
  if(p2val & SW2 ? 0 : 1){
    state = 02;
    switch_state_machine_assembly(state);

  }
  if(p2val & SW3 ? 0 : 1){
    state = 03;
    switch_state_machine_assembly(state);
  }
  if(p2val & SW4 ? 0 : 1){
    state = 04;
    switch_state_machine_assembly(state);
  }
}
 
