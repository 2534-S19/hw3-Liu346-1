/*
 * GPIO.c
 *
 *  Created on:
 *      Author:
 */

// For the code you place here, you may use your code that uses register references.
// However, I encourage you to start using the Driver Library as soon as possible.

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myGPIO.h"

// TODO: Create a function to initialize the GPIO.

// Even though this assignment does not use all of the pushbuttons, you should write one function that does a complete GPIO init.
void initGPIO()
{
//leds
    P1DIR |= LEFT_LED;
    P2DIR |= RED_LED;
    P2DIR |= GREEN_LED;
    P5DIR |= BLUE_LED;
    P2DIR |= LAUNCH_RED_LED;
    P2DIR |= LAUNCH_GREEN_LED;
    P2DIR |= LAUNCH_BLUE_LED;

    //Buttons
    P5DIR &= ~TOP_BUTTON;
    P3DIR &= ~BOTTOM_BUTTON;
    P1DIR &= ~LEFT_BUTTON;
    P1DIR &= ~RIGHT_BUTTON;

    P5REN |= TOP_BUTTON;
    P3REN |= BOTTOM_BUTTON;
    P1REN |= LEFT_BUTTON;
    P1REN |= RIGHT_BUTTON;

    P5OUT |= TOP_BUTTON;
    P3OUT |= BOTTOM_BUTTON;
    P1OUT |= LEFT_BUTTON;
    P1OUT |= RIGHT_BUTTON;




    // Turn off all LEDs at the start.


}

// TODO: Create a function to return the status of Launchpad Pushbutton S1
unsigned char checkStatus_LaunchpadS1()
{
    return ((P1IN & LEFT_BUTTON) == PRESSED);
}

// TODO: Create a function to return the status of Launchpad Pushbutton S2
unsigned char checkStatus_LaunchpadS2()
{
    return ((P1IN & RIGHT_BUTTON) == PRESSED);
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S1
unsigned char checkStatus_BoosterpackS1()
{
    return ((P5IN & TOP_BUTTON) == PRESSED);
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S2
unsigned char checkStatus_BoosterpackS2()
{
    return ((P3IN & BOTTOM_BUTTON) == PRESSED);
}

// TODO: Create a function to turn on Launchpad LED1.
void turnOn_LaunchpadLED1()
{
    P1OUT = P1OUT |  LEFT_LED;
}

// TODO: Create a function to turn off Launchpad LED1.
void TurnOff_Launchpad_LED1()
{
    P1OUT = P1OUT & ~LEFT_LED;
}

// TODO: Create a function to turn on the Red Launchpad LED2.
void turnOn_LaunchpadLED2Red()
{
    P2OUT = P2OUT & ~LAUNCH_RED_LED;
}

// TODO: Create a function to turn off the Red Launchpad LED2.
void TurnOff_BOOST_LEDR()
{
    P2OUT = P2OUT & ~RED_LED;
}

// TODO: Create a function to turn on the Green Launchpad LED2.
void TurnOn_Launchpad_LEDG()
{
    P2OUT = P2OUT |  LAUNCH_GREEN_LED;
}

// TODO: Create a function to turn off the Green Launchpad LED2.
void TurnOff_Launchpad_LEDG()
{
    P2OUT = P2OUT & ~LAUNCH_GREEN_LED;
}

// TODO: Create a function to turn on the Blue Launchpad LED2.
void TurnOn_Launchpad_LEDB()
{
    P2OUT = P2OUT |  LAUNCH_BLUE_LED;
}

// TODO: Create a function to turn off the Blue Launchpad LED2.
void TurnOff_Launchpad_LEDB()
{
    P2OUT = P2OUT & ~LAUNCH_BLUE_LED;
}

// TODO: Create a function to turn on the Red Boosterpack LED2.
void TurnOn_BOOST_LEDR()
{
    P2OUT = P2OUT |  RED_LED;
}

// TODO: Create a function to turn off the Red Boosterpack LED2.
void TurnOff_BOOST_LEDRR()
{
    P2OUT = P2OUT & ~RED_LED;
}

// TODO: Create a function to turn on the Green Boosterpack LED2.
void TurnOn_BOOST_LEDG()
{
    P2OUT = P2OUT |  GREEN_LED;
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void TurnOff_BOOST_LEDG()
{
    P2OUT = P2OUT & ~GREEN_LED;
}

// TODO: Create a function to turn on the Blue Boosterpack LED2.
void TurnOn_BOOST_LEDB()
{
    P5OUT = P5OUT |  BLUE_LED;
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void TurnOff_BOOST_LEDB()
{
    P5OUT = P5OUT & ~BLUE_LED;
}







