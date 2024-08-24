/*
 * my_first _project.c
 *
 * Created: 8/21/2023 9:04:00 PM
 * Author : PC
 */ 
#include <stdio.h>
#include "../ECUAL/LED/led.h"
#include "../ECUAL/BUTTON/button.h"
uint8_t buttonstate=0;
uint8_t flag=0;
uint8_t pressed=0;
	
uint8_t data=0;
appStart()
{
	BUTTON_read(PORT_C,1,&buttonstate);
			
	if (buttonstate==HIGH )
	{
		if (pressed==0)
		{
			if (flag>= 4)
			{
				data&=~(1<<(flag-4));
			}
			else
			{
				data|=(1<<flag);
			}
			uint8_t res = DIO_writePort(PORT_A,data);
			if (res == DIOERRORSTATE)
			{
				printf("DIOERRORSTATE");
			}
			flag++;
			if (flag>7)
			{
				flag=0;
			}
			pressed=1;
		}
	}
	else
	{
		pressed =0;
	}

}

int main(void)
{
	LED_init(PORT_A,0);
	LED_init(PORT_A,1);
	LED_init(PORT_A,2);
	LED_init(PORT_A,3);
	
	BUTTON_init(PORT_C,1);
    while (1) 
    {
		appStart();
	}
	
}