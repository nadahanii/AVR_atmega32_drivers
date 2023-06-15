/*
 * LED_Animations.c
 *
 *  Created on: Feb 17, 2023
 *      Author: dell
 */

#include <avr/delay.h>
#include "../../STD_LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../HAL/LED/LED.h"

void Flash_Every_500_ms(u8 Reading_PORTID,u8 Reading_PINID,u8 Output_PORTID,u8 Output_PINID , u8* VALUE){
	DIO_ReadPin(Reading_PORTID,Reading_PINID,VALUE);

		if(*VALUE==HIGH){
			LED_ON(Output_PORTID,Output_PINID);
			_delay_ms(500);
			LED_OFF(Output_PORTID,Output_PINID);
			_delay_ms(500);
		}
		else{
			DIO_SetPortValue(Output_PORTID,LOW_PORT);
		}
}

void Shift_Left_Every_250_ms(u8 Reading_PORTID,u8 Reading_PINID,u8 Output_PORTID, u8* VALUE){
	DIO_ReadPin(Reading_PORTID,Reading_PINID,VALUE);
		if(*VALUE==HIGH){

			for(int i=0;i<8;i++){
				switch(i){
				case 0 :
						LED_ON(Output_PORTID,PIN0);
						_delay_ms(250);
						LED_OFF(Output_PORTID,PIN0);
						break;
				case 1:
						LED_ON(Output_PORTID,PIN1);
						_delay_ms(250);
						LED_OFF(Output_PORTID,PIN1);
						break;
				case 2 :
						LED_ON(Output_PORTID,PIN2);
						_delay_ms(250);
						LED_OFF(Output_PORTID,PIN2);
						break;
				case 3:
						LED_ON(Output_PORTID,PIN3);
						_delay_ms(250);
						LED_OFF(Output_PORTID,PIN3);
						break;
				case 4:
						LED_ON(Output_PORTID,PIN4);
						_delay_ms(250);
						LED_OFF(Output_PORTID,PIN4);
						break;
				case 5:
						LED_ON(Output_PORTID,PIN5);
						_delay_ms(250);
						LED_OFF(Output_PORTID,PIN5);
						break;
				case 6:
						LED_ON(Output_PORTID,PIN6);
						_delay_ms(250);
						LED_OFF(Output_PORTID,PIN6);
						break;

				case 7:
						LED_ON(Output_PORTID,PIN7);
						_delay_ms(250);
						LED_OFF(Output_PORTID,PIN7);
						break;
				}
				_delay_ms(250);
			}

		}
		else{
			DIO_SetPortValue(Output_PORTID,LOW_PORT);
		}
}

void Shift_Right_Every_250_ms(u8 Reading_PORTID,u8 Reading_PINID,u8 Output_PORTID , u8* VALUE){
	DIO_ReadPin(Reading_PORTID,Reading_PINID,VALUE);
			if(*VALUE==HIGH){

				for(int i=7;i>=0;i--){
					switch(i){
					case 0 :
							LED_ON(Output_PORTID,PIN0);
							_delay_ms(250);
							LED_OFF(Output_PORTID,PIN0);
							break;
					case 1:
							LED_ON(Output_PORTID,PIN1);
							_delay_ms(250);
							LED_OFF(Output_PORTID,PIN1);
							break;
					case 2 :
							LED_ON(Output_PORTID,PIN2);
							_delay_ms(250);
							LED_OFF(Output_PORTID,PIN2);
							break;
					case 3:
							LED_ON(Output_PORTID,PIN3);
							_delay_ms(250);
							LED_OFF(Output_PORTID,PIN3);
							break;
					case 4:
							LED_ON(Output_PORTID,PIN4);
							_delay_ms(250);
							LED_OFF(Output_PORTID,PIN4);
							break;
					case 5:
							LED_ON(Output_PORTID,PIN5);
							_delay_ms(250);
							LED_OFF(Output_PORTID,PIN5);
							break;
					case 6:
							LED_ON(Output_PORTID,PIN6);
							_delay_ms(250);
							LED_OFF(Output_PORTID,PIN6);
							break;

					case 7:
							LED_ON(Output_PORTID,PIN7);
							_delay_ms(250);
							LED_OFF(Output_PORTID,PIN7);
							break;
					}
					_delay_ms(250);
				}

			}
			else{
				DIO_SetPortValue(Output_PORTID,LOW_PORT);
			}
}

void Two_LEDs_Converge_Every_300_ms(u8 Reading_PORTID,u8 Reading_PINID,u8 Output_PORTID , u8* VALUE){
	DIO_ReadPin(Reading_PORTID,Reading_PINID,VALUE);

	if(*VALUE==HIGH){
		for(int i=0;i<4;i++){
			switch(i){
			case 0 :
				LED_ON(Output_PORTID,PIN7);
				LED_ON(Output_PORTID,PIN0);
				_delay_ms(250);
				LED_OFF(Output_PORTID,PIN7);
				LED_OFF(Output_PORTID,PIN0);
				break;

			case 1 :
				LED_ON(Output_PORTID,PIN6);
				LED_ON(Output_PORTID,PIN1);
				_delay_ms(250);
				LED_OFF(Output_PORTID,PIN6);
				LED_OFF(Output_PORTID,PIN1);
				break;

			case 2:
				LED_ON(Output_PORTID,PIN5);
				LED_ON(Output_PORTID,PIN2);
				_delay_ms(250);
				LED_OFF(Output_PORTID,PIN5);
				LED_OFF(Output_PORTID,PIN2);
				break;

			case 3:
				LED_ON(Output_PORTID,PIN4);
				LED_ON(Output_PORTID,PIN3);
				_delay_ms(250);
				LED_OFF(Output_PORTID,PIN4);
				LED_OFF(Output_PORTID,PIN3);
				break;
			}
		}
	}
	else{
		DIO_SetPortValue(Output_PORTID,LOW_PORT);
	}
}

void Two_LEDs_Diverge_Every_300_ms(u8 Reading_PORTID,u8 Reading_PINID,u8 Output_PORTID , u8* VALUE){
	DIO_ReadPin(Reading_PORTID,Reading_PINID,VALUE);

		if(*VALUE==HIGH){
			for(int i=0;i<4;i++){
				switch(i){
				case 0 :
					LED_ON(Output_PORTID,PIN4);
					LED_ON(Output_PORTID,PIN3);
					_delay_ms(250);
					LED_OFF(Output_PORTID,PIN4);
					LED_OFF(Output_PORTID,PIN3);
					break;

				case 1 :
					LED_ON(Output_PORTID,PIN5);
					LED_ON(Output_PORTID,PIN2);
					_delay_ms(250);
					LED_OFF(Output_PORTID,PIN5);
					LED_OFF(Output_PORTID,PIN2);
					break;

				case 2:
					LED_ON(Output_PORTID,PIN6);
					LED_ON(Output_PORTID,PIN1);
					_delay_ms(250);
					LED_OFF(Output_PORTID,PIN6);
					LED_OFF(Output_PORTID,PIN1);
					break;

				case 3:
					LED_ON(Output_PORTID,PIN7);
					LED_ON(Output_PORTID,PIN0);
					_delay_ms(250);
					LED_OFF(Output_PORTID,PIN7);
					LED_OFF(Output_PORTID,PIN0);
					break;
				}
			}
		}
		else{
			DIO_SetPortValue(Output_PORTID,LOW_PORT);
		}
}

void Ping_Pong_Every_250_ms(u8 Reading_PORTID,u8 Reading_PINID,u8 Output_PORTID , u8* VALUE){
	DIO_ReadPin(Reading_PORTID,Reading_PINID,VALUE);

	if(*VALUE==HIGH){
		for(int i=0;i<8;i++){
			switch(i){
			case 0 :
					LED_ON(Output_PORTID,PIN0);
					_delay_ms(250);
					LED_OFF(Output_PORTID,PIN0);
					break;
			case 1:
					LED_ON(Output_PORTID,PIN7);
					_delay_ms(250);
					LED_OFF(Output_PORTID,PIN7);
					break;
			case 2 :
					LED_ON(Output_PORTID,PIN1);
					_delay_ms(250);
					LED_OFF(Output_PORTID,PIN1);
					break;
			case 3:
					LED_ON(Output_PORTID,PIN6);
					_delay_ms(250);
					LED_OFF(Output_PORTID,PIN6);
					break;
			case 4:
					LED_ON(Output_PORTID,PIN2);
					_delay_ms(250);
					LED_OFF(Output_PORTID,PIN2);
					break;
			case 5:
					LED_ON(Output_PORTID,PIN5);
					_delay_ms(250);
					LED_OFF(Output_PORTID,PIN5);
					break;
			case 6:
					LED_ON(Output_PORTID,PIN3);
					_delay_ms(250);
					LED_OFF(Output_PORTID,PIN3);
					break;

			case 7:
					LED_ON(Output_PORTID,PIN4);
					_delay_ms(250);
					LED_OFF(Output_PORTID,PIN4);
					break;
			}
			_delay_ms(250);
		}
	}
	else{
		DIO_SetPortValue(Output_PORTID,LOW_PORT);
	}
}

void Snake_Effect_Every_300_ms(u8 Reading_PORTID,u8 Reading_PINID,u8 Output_PORTID , u8* VALUE){
	DIO_ReadPin(Reading_PORTID,Reading_PINID,VALUE);

	if(*VALUE==HIGH){
		for(int i=0;i<8;i++){
			switch(i){
			case 0 :
				LED_ON(Output_PORTID,PIN0);
				_delay_ms(300);

				break;
			case 1:
				LED_ON(Output_PORTID,PIN1);
				_delay_ms(300);

				break;
			case 2 :
				LED_ON(Output_PORTID,PIN2);
				_delay_ms(300);

				break;
			case 3:
				LED_ON(Output_PORTID,PIN3);
				_delay_ms(300);

				break;
			case 4:
				LED_ON(Output_PORTID,PIN4);
				_delay_ms(300);

				break;
			case 5:
				LED_ON(Output_PORTID,PIN5);
				_delay_ms(300);

				break;
			case 6:
				LED_ON(Output_PORTID,PIN6);
				_delay_ms(300);

				break;

			case 7:
				LED_ON(Output_PORTID,PIN7);
				_delay_ms(300);

				break;
			}
			_delay_ms(300);
		}

		DIO_SetPortValue(Output_PORTID,LOW_PORT);
		/*LED_OFF(Output_PORTID,PIN0);
		LED_OFF(Output_PORTID,PIN1);
		LED_OFF(Output_PORTID,PIN2);
		LED_OFF(Output_PORTID,PIN3);
		LED_OFF(Output_PORTID,PIN4);
		LED_OFF(Output_PORTID,PIN5);
		LED_OFF(Output_PORTID,PIN6);
		LED_OFF(Output_PORTID,PIN7);*/
	}
	else{
		DIO_SetPortValue(Output_PORTID,LOW_PORT);
	}
}

void LEDs_Converge_Or_Diverge_Every_300_ms(u8 Reading_PORTID,u8 Reading_PINID,u8 Output_PORTID , u8* VALUE){
	DIO_ReadPin(Reading_PORTID,Reading_PINID,VALUE);

	if(*VALUE==HIGH){
		for(int i=0;i<4;i++){
			switch(i){
				case 0 :
					LED_ON(Output_PORTID,PIN4);
					LED_ON(Output_PORTID,PIN3);
					_delay_ms(250);
					LED_OFF(Output_PORTID,PIN4);
					LED_OFF(Output_PORTID,PIN3);
					break;

				case 1 :
					LED_ON(Output_PORTID,PIN5);
					LED_ON(Output_PORTID,PIN2);
					_delay_ms(250);
					LED_OFF(Output_PORTID,PIN5);
					LED_OFF(Output_PORTID,PIN2);
					break;

				case 2:
					LED_ON(Output_PORTID,PIN6);
					LED_ON(Output_PORTID,PIN1);
					_delay_ms(250);
					LED_OFF(Output_PORTID,PIN6);
					LED_OFF(Output_PORTID,PIN1);
					break;

				case 3:
					LED_ON(Output_PORTID,PIN7);
					LED_ON(Output_PORTID,PIN0);
					_delay_ms(250);
					LED_OFF(Output_PORTID,PIN7);
					LED_OFF(Output_PORTID,PIN0);
					break;
			}
		}

		DIO_SetPortValue(Output_PORTID,LOW_PORT);
		for(int i=0;i<4;i++){
			switch(i){
				case 0 :
					LED_ON(Output_PORTID,PIN7);
					LED_ON(Output_PORTID,PIN0);
					_delay_ms(250);
					LED_OFF(Output_PORTID,PIN7);
					LED_OFF(Output_PORTID,PIN0);
					break;

				case 1 :
					LED_ON(Output_PORTID,PIN6);
					LED_ON(Output_PORTID,PIN1);
					_delay_ms(250);
					LED_OFF(Output_PORTID,PIN6);
					LED_OFF(Output_PORTID,PIN1);
					break;

				case 2:
					LED_ON(Output_PORTID,PIN5);
					LED_ON(Output_PORTID,PIN2);
					_delay_ms(250);
					LED_OFF(Output_PORTID,PIN5);
					LED_OFF(Output_PORTID,PIN2);
					break;

				case 3:
					LED_ON(Output_PORTID,PIN4);
					LED_ON(Output_PORTID,PIN3);
					_delay_ms(250);
					LED_OFF(Output_PORTID,PIN4);
					LED_OFF(Output_PORTID,PIN3);
					break;
			}
		}
		DIO_SetPortValue(Output_PORTID,LOW_PORT);
	}
	else{
		DIO_SetPortValue(Output_PORTID,LOW_PORT);
	}
}
