#include <asf.h>

#include "PIO_OLED.h"
#include "PIO_FUNCTIONS.h"
#include "TC-RTT-RTC.h"

#include "gfx_mono_ug_2832hsweg04.h"
#include "gfx_mono_text.h"
#include "sysfont.h"


//Variaveis globais


void init(void) {
	//Initialize the board clock
	sysclk_init();
	oled_init();
	gfx_mono_ssd1306_init();
	
	// Desativa WatchDog Timer
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	
	
}

int main (void)
{
	board_init();
	sysclk_init();
	init();
	delay_init();

	gfx_mono_draw_string("Aguardando", 0,16, &sysfont);
  /* Insert application code here, after the board has been initialized. */
	while(1) {
			
			if (flag_but1) {
					
				pin_toggle(LED_PI1, LED_PI1_IDX_MASK);
				delay_ms(300);
				pin_toggle(LED_PI1, LED_PI1_IDX_MASK);
				gfx_mono_draw_string("Botao 1   ", 0,16, &sysfont);
				flag_but1 = 0;
			}
				
			if (flag_but2) {
				
				pin_toggle(LED_PI2, LED_PI2_IDX_MASK);
				delay_ms(300);
				pin_toggle(LED_PI2, LED_PI2_IDX_MASK);
				gfx_mono_draw_string("Botao 2   ", 0,16, &sysfont);
				flag_but2 = 0;
			}
			
			if (flag_but3) {
				
				pin_toggle(LED_PI3, LED_PI3_IDX_MASK);
				delay_ms(300);
				pin_toggle(LED_PI3, LED_PI3_IDX_MASK);
				
				gfx_mono_draw_string("Botao 3    ", 0,16, &sysfont);
				flag_but3 = 0;
			}
			
			
	}
}
