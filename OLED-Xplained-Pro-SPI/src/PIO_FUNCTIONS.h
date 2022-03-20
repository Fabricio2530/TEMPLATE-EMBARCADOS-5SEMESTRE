
#include "PIO_FUNCTIONS.c"

void pin_toggle(Pio *pio, uint32_t mask);
void pisca_led (int n, int t, Pio *pio, uint32_t mask) ;
void cria_pino_entrada(Pio *pio, uint32_t ul_id, uint32_t mask);
void cria_pino_saida(Pio *pio, uint32_t ul_id, uint32_t mask);