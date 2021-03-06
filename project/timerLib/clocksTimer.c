#include <msp430.h>
#include "libTimer.h"

void configureClocks(){
  WDTCTL = WDTPW + WDTHOLD;
  BCSCTL1 = CALBC1_16MHZ;
  DCOCTL = CALDCO_16MHZ;

  BCSCTL2 &= ~(SELS);  //SMCLK source = DCO
  BCSCTL2 |= DIVS_3; // SMCLK = DCO / 8
}
void enableWDTIterrupts(){
  WDTCTL = WDTPW | //pswrd required otherwise reset
  WDTTMSEL | //watchdog interval mode 
  WDTCNTCL | // clear watchdog count
  1; // divide SMCLK by 8192
 IE1 |= WDTIE; //  Enable watchdog
}
void timerAUpmode(){
  TA0CCR0 = 0;
  TA0CCR1 = 0;
  TA0CCTL1 = OUTMOD_3;
  // timer A control:
  // Timer clock source 2: system clock(SMCLK)
  // Mode control 1: contimuously 0(CCR0)
  TACTL = TASSEL_2 + MC_1; 

}
