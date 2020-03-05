/*
 * homework3.h
 *
 *  Created on:
 *      Author:
 */



#ifndef HOMEWORK3_H_
#define HOMEWORK3_H_

// This function initializes the board by turning off the Watchdog Timer.
void initBoard();
// This function indexes a count value to an LED color on Launchpad LED2.
void changeLaunchpadLED2(unsigned int count);
// This function indexes a count value to an LED color on the Boosterpack LED.
void changeBoosterpackLED(unsigned int count);
// This function serves as a debounce state machine for Boosterpack button S1
bool fsmBoosterpackButtonS1(unsigned int buttonhistory);


// TODO: Define any constants that are local to homework.c using #define

#define LEFT_BUTTON BIT1
#define RIGHT_BUTTON BIT4
#define TOP_BUTTON BIT1
#define BOTTOM_BUTTON BIT5
#define LEFT_LED BIT0
#define BLUE_LED BIT6
#define GREEN_LED BIT4
#define RED_LED BIT6
#define LAUNCH_RED_LED BIT0
#define LAUNCH_BLUE_LED BIT2
#define LAUNCH_GREEN_LED BIT1
#define PRESSED 0

#endif /* HOMEWORK3_H_ */
