
//LED 1
#define LED_PI1			  PIOA
#define LED_PI1_ID		  ID_PIOA
#define LED_PI1_IDX		  0
#define LED_PI1_IDX_MASK  (1 << LED_PI1_IDX)   // Mascara para CONTROLARMOS o LED

//LED 2
#define LED_PI2			  PIOC
#define LED_PI2_ID		  ID_PIOC
#define LED_PI2_IDX		  30
#define LED_PI2_IDX_MASK  (1 << LED_PI2_IDX)   // Mascara para CONTROLARMOS o LED

//LED 3
#define LED_PI3			  PIOB
#define LED_PI3_ID		  ID_PIOB
#define LED_PI3_IDX		  2
#define LED_PI3_IDX_MASK  (1 << LED_PI3_IDX)   // Mascara para CONTROLARMOS o LED

// Configuracoes do BOTAO 1
#define BUT_PI1			  PIOD
#define BUT_PI1_ID        ID_PIOD
#define BUT_PI1_IDX	      28
#define BUT_PI1_IDX_MASK (1u << BUT_PI1_IDX)

// Botão 2
#define BUT_PI2			  PIOC
#define BUT_PI2_ID        ID_PIOC
#define BUT_PI2_IDX	      31
#define BUT_PI2_IDX_MASK (1u << BUT_PI2_IDX) // esse já está pronto.

// Botão 3
#define BUT_PI3			  PIOA
#define BUT_PI3_ID        ID_PIOA
#define BUT_PI3_IDX	      19
#define BUT_PI3_IDX_MASK (1u << BUT_PI3_IDX) // esse já está pronto.

void oled_init(void) {
	
	pmc_enable_periph_clk(LED_PI1_ID);
	//Inicializa LED1 como saída
	pio_set_output(LED_PI1, LED_PI1_IDX_MASK, 0, 0, 0);
	
	pmc_enable_periph_clk(LED_PI2_ID);
	//Inicializa LED2 como saída
	pio_set_output(LED_PI2, LED_PI2_IDX_MASK, 0, 0, 0);
	
	pmc_enable_periph_clk(LED_PI1_ID);
	//Inicializa LED1 como saída
	pio_set_output(LED_PI3, LED_PI3_IDX_MASK, 0, 0, 0);
	
	// Inicializa PIO do BOTAO 1
	pmc_enable_periph_clk(BUT_PI1_ID);
	// configura pino ligado ao botão como entrada com um pull-up.
	pio_set_input(BUT_PI1,BUT_PI1_IDX_MASK,PIO_DEFAULT);
	pio_pull_up(BUT_PI1,BUT_PI1_IDX_MASK,1);
	pio_set_debounce_filter(BUT_PI1, BUT_PI1_IDX_MASK, 60);
	
	// Inicializa PIO do BOTAO 2
	pmc_enable_periph_clk(BUT_PI2_ID);
	// configura pino ligado ao botão como entrada com um pull-up.
	pio_set_input(BUT_PI2,BUT_PI2_IDX_MASK,PIO_DEFAULT);
	pio_pull_up(BUT_PI2,BUT_PI2_IDX_MASK,1);
	pio_set_debounce_filter(BUT_PI2, BUT_PI2_IDX_MASK, 60);
	
	// Inicializa PIO do BOTAO 2
	pmc_enable_periph_clk(BUT_PI3_ID);
	// configura pino ligado ao botão como entrada com um pull-up.
	pio_set_input(BUT_PI3,BUT_PI3_IDX_MASK,PIO_DEFAULT);
	pio_pull_up(BUT_PI3,BUT_PI3_IDX_MASK,1);
	pio_set_debounce_filter(BUT_PI3, BUT_PI3_IDX_MASK, 60);
	
}