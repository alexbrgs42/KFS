#include "../../INCL/tty.h"

void handle_keyboard()
{
	char c = 0;
	do
	{
		if(inb(0x60) != c) // PORT FROM WHICH WE READ
		{
			c = inb(0x60);
			if (c > 0)
			{
				printk(0, "e"); // print on screen
			}
			if (c == (char)16) // test for q
				printk(0, "Q");
		}
	}
	while (c != 1); // 1 = ESCAPE
}
