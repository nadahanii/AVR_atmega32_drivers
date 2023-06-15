/*
 * LED_Animations.h
 *
 *  Created on: Feb 17, 2023
 *      Author: dell
 */

#ifndef LED_ANIMATIONS_H_
#define LED_ANIMATIONS_H_

void Flash_Every_500_ms(u8 Reading_PORTID,u8 Reading_PINID,u8 Output_PORTID,u8 Output_PINID , u8* VALUE);

void Shift_Left_Every_250_ms(u8 Reading_PORTID,u8 Reading_PINID,u8 Output_PORTID , u8* VALUE);

void Shift_Right_Every_250_ms(u8 Reading_PORTID,u8 Reading_PINID,u8 Output_PORTID , u8* VALUE);

void Two_LEDs_Converge_Every_300_ms(u8 Reading_PORTID,u8 Reading_PINID,u8 Output_PORTID , u8* VALUE);

void Two_LEDs_Diverge_Every_300_ms(u8 Reading_PORTID,u8 Reading_PINID,u8 Output_PORTID , u8* VALUE);

void Ping_Pong_Every_250_ms(u8 Reading_PORTID,u8 Reading_PINID,u8 Output_PORTID , u8* VALUE);

void Snake_Effect_Every_300_ms(u8 Reading_PORTID,u8 Reading_PINID,u8 Output_PORTID , u8* VALUE);

void LEDs_Converge_Or_Diverge_Every_300_ms(u8 Reading_PORTID,u8 Reading_PINID,u8 Output_PORTID , u8* VALUE);




#endif /* APP_LED_ANIMATIONS_LED_ANIMATIONS_H_ */
