

void pin_toggle(Pio *pio, uint32_t mask) {
	if(pio_get_output_data_status(pio, mask))
	pio_clear(pio, mask);
	else
	pio_set(pio,mask);
}

void pisca_led (int n, int t, Pio *pio, uint32_t mask) {
	for (int i=0;i<n;i++){
		pio_clear(pio, mask);
		delay_ms(t);
		pio_set(pio, mask);
		delay_ms(t);
	}
}

void cria_pino_entrada(Pio *pio, uint32_t ul_id, uint32_t mask){
	pmc_enable_periph_clk(ul_id);
	pio_configure(pio, PIO_INPUT, mask, PIO_DEFAULT);
}

void cria_pino_saida(Pio *pio, uint32_t ul_id, uint32_t mask){
	pmc_enable_periph_clk(ul_id);
	pio_configure(pio, PIO_OUTPUT_0, mask, PIO_DEFAULT);
}