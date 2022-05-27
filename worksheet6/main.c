/*
	Copyright 2012, Michael Scott

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/
/*changed USART3 to USART2 for Rev B boards - craig 18/2/14 */
#include "com_port.h"
#include"string.h"
#include "stdlib.h"
#include "math.h"

#include <stm32f10x.h>
#include <stm32f10x_rcc.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_usart.h>

int __io_putchar(int c) {

	/* Wait until ready to send */
	while (USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET)
	{
	}

	USART_SendData(USART2, (u16) c);

	return c;
}

int __io_inbyte(void) {

	int c;

	/* Wait until ready to receive */
	while (USART_GetFlagStatus(USART2, USART_FLAG_RXNE) == RESET)
	{
	}

	c = (int) USART_ReceiveData(USART2);

	return c;
}


void COMPortInit ( void ) {

	USART_InitTypeDef USART_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;

	/* Enable GPIO clock */
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOD | RCC_APB2Periph_AFIO, ENABLE ); 

	/* Enable USART2 clock */
	RCC_APB1PeriphClockCmd( RCC_APB1Periph_USART2, ENABLE );

	/* Remap USART, as USART2 uses alternate pins */
	GPIO_PinRemapConfig( GPIO_Remap_USART2,ENABLE );

	/* Configure USART2 Tx pin */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;   /*changed from 8 to 5 for USART craig 2*/
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init( GPIOD, &GPIO_InitStructure );

	/* Configure USART2 Rx pin */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6; /* changed from 9 to 6 for USART 2 craig */
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init( GPIOD, &GPIO_InitStructure );

	/* Configure USART 8N1 */
	USART_InitStructure.USART_BaudRate = mainCOM_PORT_BAUD_RATE;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_Init( USART2, &USART_InitStructure );

	/* Enable USART */
	USART_Cmd( USART2, ENABLE );
}

int main(void)

{
  int i,c;

	COMPortInit();

	__io_putchar('h');
	__io_putchar('e');
	__io_putchar('l');
	__io_putchar('l');
	__io_putchar('o');
	__io_putchar('\n');

	uint8_t new_q = 1;
	uint8_t merker;
	char* p_merker;
	int merker_stelle = 0;
	uint8_t stelle1 = 0;
	uint8_t stelle2 = 0;

	uint8_t answer = 0;
	uint8_t RandNum1;
	uint8_t RandNum2;

	while(1)
	{
		if(new_q == 1)
		{

		RandNum1 = rand()%10;
		RandNum2 = rand()%10;

		__io_putchar(RandNum1 + '0');
		__io_putchar('+');
		__io_putchar(RandNum2 + '0');
		__io_putchar('=');

		new_q = 0;
		}

		merker = __io_inbyte();
		p_merker = &merker;

		if(merker != 13 && merker_stelle <=2) 
		{	

			if(merker_stelle == 0)
			{
				stelle1 = merker - '0';
				merker_stelle++;
			}
			else if(merker_stelle == 1)
			{
				stelle2 = merker - '0';
				merker_stelle++;
			}
			__io_putchar(merker);
			
		}
		else
		{
			new_q = 1;
			__io_putchar('\n');

			if(merker_stelle == 1)
			{
				answer = stelle1;
			}
			else if(merker_stelle ==2)
			{
				answer = stelle1 * 10 + stelle2;
			}

			if(answer == (RandNum2 + RandNum1))
			{
				__io_putchar('R');
				__io_putchar('i');
				__io_putchar('g');
				__io_putchar('h');
				__io_putchar('t');
			}
			else
			{
				__io_putchar('W');
				__io_putchar('r');
				__io_putchar('o');
				__io_putchar('n');
				__io_putchar('g');
			}
			__io_putchar('\n');
			answer = 0;
			merker_stelle = 0;
			//memset(answer, 0, 10);

		}
	}
	
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}

#endif

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
