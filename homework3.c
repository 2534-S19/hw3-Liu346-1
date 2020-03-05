#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "homework3.h"
#include "myGPIO.h"
#include "myTimer.h"




int main(void)
{
    // Count variables to control the LEDs.
    unsigned int count0 = 0;
    unsigned int count1 = 0;

    // TODO: Declare the variables that main uses to interact with your state machine.
    int pressed;


        //LEDs
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


    //turn on LEDs


    // Stops the Watchdog timer.
    initBoard();
    // Initialize the GPIO.
    // YOU MUST WRITE THIS FUNCTION IN myGPIO.c
    initGPIO();
    // Initialize Timer0 to provide a one second count interval for updating LED2.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_0_BASE, TIMER0_PRESCALER, TIMER0_COUNT);
    // Initialize Timer1 to provide a one millisecond count interval for updating the button history.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_1_BASE, TIMER1_PRESCALER, TIMER1_COUNT);

    while(1)
    {
        // Update the color of LED2 using count0 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeLaunchpadLED2(count0);
        // Update the color of the Boosterpack LED using count1 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeBoosterpackLED(count1);

        // TODO: If Timer0 has expired, increment count0.
        // YOU MUST WRITE timer0expired IN myTimer.c

        if(timer0Expired())
        {
            count0++;
            TurnOn_Launchpad_LEDR();

        }

        // TODO: If Timer1 has expired, update the button history from the pushbutton value.
        // YOU MUST WRITE timer1expired IN myTimer.c

        if(timer1Expired() && ((P5IN & TOP_BUTTON) == 0) )
        {

            pressed = 1;

        }
        else
        {
            pressed = 0;
        }

        // TODO: Call the button state machine function to check for a completed, debounced button press.
        // YOU MUST WRITE THIS FUNCTION BELOW.

        if(fsmBoosterpackButtonS1(1))
        {
            count1++;
        }

        // TODO: If a completed, debounced button press has occurred, increment count1.



    }
}

void initBoard()
{
    WDT_A_hold(WDT_A_BASE);
}

// TODO: Map the value of a count variable to a color for LED2.
// Since count is an unsigned integer, you can mask the value in some way.
void changeLaunchpadLED2(unsigned int count)
{
    /*
    count = count & 0x07;
    switch(count)
    {
    case '0x00':
            P5OUT = P5OUT |  BLUE_LED;
    case '0x01':
    case '0x02':
    case '0x03':
    case '0x04':
    case '0x05':
    case '0x06':
    case '0x07':
    */
    //TurnOff_Launchpad_LEDR();

            /*
    if(count == 0x00)
    {
        //TurnOn_BOOST_LEDB();


    }
    */
    TurnOff_Launchpad_LEDR();
    TurnOff_Launchpad_LEDG();
    TurnOff_Launchpad_LEDB();
    //TurnOff_Launchpad_LEDR();

    count = count & 0x07;

        if(count == 0x01)
        {
            TurnOn_Launchpad_LEDR();

        }
        else if(count == 0x02)
        {
            TurnOn_Launchpad_LEDG();
        }
        else if(count == 0x03)
        {
            TurnOn_Launchpad_LEDG();
            TurnOn_Launchpad_LEDR();
        }
        else if(count == 0x04)
        {
            TurnOn_Launchpad_LEDG();
            TurnOn_Launchpad_LEDB();
        }
        else if(count == 0x05)
        {
            TurnOn_Launchpad_LEDR();
            TurnOn_Launchpad_LEDB();
        }
        else if(count == 0x06)
        {
            TurnOn_Launchpad_LEDB();
        }
        else if(count == 0x07)
        {
            TurnOn_Launchpad_LEDB();
            TurnOn_Launchpad_LEDG();
            TurnOn_Launchpad_LEDR();
        }
    }


// TODO: Maybe the value of a count variable to a color for the Boosterpack LED
// This is essentially a copy of the previous function, using a different LED
void changeBoosterpackLED(unsigned int count)
{
    TurnOff_BOOST_LEDR();
    TurnOff_BOOST_LEDB();
    TurnOff_BOOST_LEDG();
    //TurnOff_Launchpad_LEDR();
    //TurnOff_Launchpad_LEDR();
    count = count & 0x07;
    if(count == 0x01)
        {
            TurnOn_BOOST_LEDR();

        }
        else if(count == 0x02)
        {
            TurnOn_BOOST_LEDG();
        }
        else if(count == 0x03)
        {
            TurnOn_BOOST_LEDG();
            TurnOn_BOOST_LEDR();
        }
        else if(count == 0x04)
        {
            TurnOn_BOOST_LEDG();
            TurnOn_BOOST_LEDB();
        }
        else if(count == 0x05)
        {
            TurnOn_BOOST_LEDR();
            TurnOn_BOOST_LEDB();
        }
        else if(count == 0x06)
        {
            TurnOn_BOOST_LEDB();
        }
        else if(count == 0x07)
        {
            TurnOn_BOOST_LEDB();
            TurnOn_BOOST_LEDG();
            TurnOn_BOOST_LEDR();
        }
}

// TODO: Create a button state machine.
// The button state machine should return true or false to indicate a completed, debounced button press.
bool fsmBoosterpackButtonS1(unsigned int buttonhistory)
{
    bool pressed = false;


    return pressed;
}
