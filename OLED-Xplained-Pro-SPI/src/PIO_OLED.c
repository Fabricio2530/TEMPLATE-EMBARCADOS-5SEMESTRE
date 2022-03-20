
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

//variaveis globais
volatile char flag_but1 = 0;
volatile char flag_but2 = 0;
volatile char flag_but3 = 0;

void but1_callback(void){
	flag_but1 = 1;	
}

void but2_callback(void){
	flag_but2 = 1;
}

void but3_callback(void) {
	flag_but3 = 1;
}

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
	
	pio_handler_set(BUT_PI1,
	BUT_PI1_ID,
	BUT_PI1_IDX_MASK,
	PIO_IT_EDGE,
	but1_callback);
	
	pio_handler_set(BUT_PI2,
	BUT_PI2_ID,
	BUT_PI2_IDX_MASK,
	PIO_IT_RISE_EDGE,
	but2_callback);
	
	pio_handler_set(BUT_PI3,
	BUT_PI3_ID,
	BUT_PI3_IDX_MASK,
	PIO_IT_RISE_EDGE,
	but3_callback);
	
	// Ativa interrupção e limpa primeira IRQ gerada na ativacao
	pio_enable_interrupt(BUT_PI1, BUT_PI1_IDX_MASK);
	pio_get_interrupt_status(BUT_PI1);
	
	pio_enable_interrupt(BUT_PI2, BUT_PI2_IDX_MASK);
	pio_get_interrupt_status(BUT_PI2);
	
	pio_enable_interrupt(BUT_PI3, BUT_PI3_IDX_MASK);
	pio_get_interrupt_status(BUT_PI3);
	
	// Configura NVIC para receber interrupcoes do PIO do botao
	// com prioridade 4 (quanto mais próximo de 0 maior)
	NVIC_EnableIRQ(BUT_PI1_ID);
	NVIC_SetPriority(BUT_PI1_ID, 4); // Prioridade 4
	
	NVIC_EnableIRQ(BUT_PI2_ID);
	NVIC_SetPriority(BUT_PI2_ID, 4); // Prioridade 4
	
	NVIC_EnableIRQ(BUT_PI3_ID);
	NVIC_SetPriority(BUT_PI3_ID, 4); // Prioridade 4
	
}