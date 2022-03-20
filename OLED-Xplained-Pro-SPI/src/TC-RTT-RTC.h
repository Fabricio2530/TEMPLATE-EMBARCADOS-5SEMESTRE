
#include "TC-RTT-RTC.c"

static void RTT_init(float freqPrescale, uint32_t IrqNPulses, uint32_t rttIRQSource);

void RTT_Handler(void);

void TC_init(Tc * TC, int ID_TC, int TC_CHANNEL, int freq);

void RTC_init(Rtc *rtc, uint32_t id_rtc, calendar t, uint32_t irq_type);

void RTC_Handler(void);

