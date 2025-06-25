/*
 * SEGMENT_program.c
 *
 *  Created on: Mar 22, 2025
 *      Author: Mostafa Mohamed
 */
#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "SEGMENT_interface.h"
#include "SEGMENT_config.h"
#include "GPIO_interface.h"
#include "STP_interface.h"
#include "SYSTICK_interface.h"

const u8_t SEGMENT_MAP[10] = {
    0b1111110, // 0
    0b0110000, // 1
    0b1101101, // 2
    0b1111001, // 3
    0b0110011, // 4
    0b1011011, // 5
    0b1011111, // 6
    0b1110000, // 7
    0b1111111, // 8
    0b1111011  // 9
};

static u8_t currentLetter = 0;
static u8_t currentNumber = 0;

void SEGMENT_Blink(u16_t Blink_Time)
{
	for(u8_t i=0; i<4; i++){
	    STP_Shift_Data(currentLetter, currentNumber);
	    STP_Send_Data();
	    delay_ms(Blink_Time/4);
	    STP_Shift_Data(SEGMENT_OFF, SEGMENT_OFF);
	    STP_Send_Data();
	    delay_ms(Blink_Time/4);
	}
}
void SEGMENT_display_Error_Code(u8_t Error_Number)
{
    currentLetter = SEGMENT_LETTER_E;
    currentNumber = SEGMENT_MAP[Error_Number];
    STP_Shift_Data(currentLetter, currentNumber);
    STP_Send_Data();
}
void SEGMENT_display_on_Startup()
{
    currentLetter = SEGMENT_LETTER_H;
    currentNumber = SEGMENT_LETTER_I;
    STP_Shift_Data(currentLetter, currentNumber);
    STP_Send_Data();
}

void SEGMENT_Turn_Off()
{
    STP_Shift_Data(SEGMENT_OFF, SEGMENT_OFF);
    STP_Send_Data();
}
