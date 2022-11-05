#define F_CPU  8000000
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "KEYPAD_Interface.h"
#include "LCD_Interface.h"
#include <avr/io.h>
#include <avr/delay.h>
#define clear 0b00000001
void main (void)
{
	DIO_VidSetPinDirection(PORTB ,PIN0 , OUTPUT);
	DIO_VidSetPinDirection(PORTB ,PIN1 , OUTPUT);
	u8 LOC_u8PressedNumber;
	u8 LOC_u8Data[20];
	u16 LOC_u16FirstNumber=0;
	u16 LOC_u16SecondNumber=0;
	u32 LOC_u32Password [3] = {1,2,3};
	u32 LOC_u32try_Password [3];
	u32 LOC_u32newtry_Password [3];
	u8  LOC_u8Flag=0;
	u8 LOC_u8flagerror =0;
	u8 LOC_u8flagerror2 =0;

	KPD_VidInit();
	LCD_VidInit();
	
	while (1)
	{
		LCD_VidSendCommand(clear);
		_delay_ms(2);
		LCD_VidSetPosition(0,0);
		LCD_VidWriteString("Enter  PW press1");
		LCD_VidSetPosition(1,0);
		LCD_VidWriteString("Change PW press2");
		
		

				do {
					LOC_u8PressedNumber=KPD_u8GetPressedKey();
				}
				while(KPD_NO_PRESSED_KEY==LOC_u8PressedNumber);
				
				
				
/*******************************************************************/
				/*To chose Enter password */
				
				if (LOC_u8PressedNumber== 1)
				{
					LCD_VidSendCommand(clear);
					_delay_ms(2);
					LCD_VidWriteString("Enter PW: ");
					
					
						LOC_u8Flag=0;
						LOC_u8flagerror=0;
                for (u8 i=0; i<3; i++)
				{
		  
		 
		 
		 
						do {
							LOC_u32try_Password [i]=KPD_u8GetPressedKey();
						}
						while(KPD_NO_PRESSED_KEY==LOC_u32try_Password [i]);
						
					LCD_VidSendCommand(clear);
					_delay_ms(2);
					LCD_VidSetPosition(0,0);
					LCD_VidWriteString("Enter PW: ");
					for (u8 j=0; j<=i; j++)
					{
					LCD_VidSetPosition(1,j);
					LCD_VidWriteChar('*');	
					}
					
					if (LOC_u32try_Password [i] == LOC_u32Password [i] )
					{
						LOC_u8Flag++;
						
					}
						
				
		  LOC_u8flagerror++;
	       	} 
								
					
												
					
							
					
					if (LOC_u8Flag == 3)
					{
						_delay_ms(500);
						LCD_VidSendCommand(clear);
						_delay_ms(2);
						LCD_VidWriteString("Correct PW");
						DIO_VidSetPortValue(PORTB , HIGH);
						_delay_ms(3000);
						DIO_VidSetPortValue(PORTB , LOW);
						
					}
					else if (LOC_u8flagerror==3 && LOC_u8flagerror2!=3)
					{
						_delay_ms(500);
						LCD_VidSendCommand(clear);
						_delay_ms(2);
						LCD_VidWriteString("Try again");
						_delay_ms(3000);
						LOC_u8flagerror2 ++;
					}						
						
						else if (LOC_u8flagerror2==3)
						{
							LCD_VidSendCommand(clear);
							_delay_ms(2);
							LCD_VidWriteString("Error PW");
							_delay_ms(3000);
							LCD_VidSendCommand(clear);
							_delay_ms(2);
							LCD_VidWriteString("Wait...");
							_delay_ms(5000);
							LOC_u8flagerror2=0;
							
						}
				
				}
				
				
				
/*******************************************************************/
				/*To change password*/
				
				else if (LOC_u8PressedNumber== 2)
				{
					LCD_VidSendCommand(clear);
					_delay_ms(2);
					LCD_VidWriteString("Enter old PW:");
					LOC_u8Flag=0;
					LOC_u8flagerror=0;
					
					for (u8 i=0; i<3; i++)
					{
						
						
						
						do {
							LOC_u32try_Password [i]=KPD_u8GetPressedKey();
						}
						while(KPD_NO_PRESSED_KEY==LOC_u32try_Password [i]);
						
						LCD_VidSendCommand(clear);
						_delay_ms(2);
						LCD_VidSetPosition(0,0);
						LCD_VidWriteString("Enter old PW: ");
						for (u8 j=0; j<=i; j++)
						{
							LCD_VidSetPosition(1,j);
							LCD_VidWriteChar('*');
						}
						
						if (LOC_u32try_Password [i] == LOC_u32Password [i] )
						{
							LOC_u8Flag++;
							
						}
						
						
						LOC_u8flagerror++;
					}
					
					
					
					if (LOC_u8Flag == 3)
					{
						_delay_ms(500);
						LCD_VidSendCommand(clear);
						_delay_ms(2);
						LCD_VidWriteString("Enter new PW:");
						
						for (u8 i=0; i<3; i++)
						{
							
							
							
							
							do {
								LOC_u32newtry_Password [i]=KPD_u8GetPressedKey();
							}
							while(KPD_NO_PRESSED_KEY==LOC_u32newtry_Password [i]);
							
							LOC_u32Password [i] = LOC_u32newtry_Password [i];
							
							LCD_VidSetPosition(1,i);
							LCD_VidWriteNumber(LOC_u32Password [i]);
							
											
						}	
						
						_delay_ms(2000);											
					}
					else if (LOC_u8flagerror==3)
					{
						_delay_ms(500);
						LCD_VidSendCommand(clear);
						_delay_ms(2);
						LCD_VidWriteString("Error PW");
						_delay_ms(3000);
					}
					
				
					
	}
		
  }			
		
}
	

	
		


