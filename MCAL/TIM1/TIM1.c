#include "STD_Types.h"
#include "BIT_Math.h"

#include "TIM1.h"
#include "TIM1_cfg.h"
#include "TIM1_priv.h"


pf TIM1_CallBack_Ovf = stub;
pf TIM1_CallBack_Cmp_OCR1A = stub;
pf TIM1_CallBack_Cmp_OCR1B = stub;
pf TIM1_CallBack_Cmp_ICU = stub;

//uint8 u8modesArrGlob[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 15}; 

uint8 getMode(void);

void TIM1_vidInit(void)
{
  uint8 u16TCCR1A_pre = 0;
  uint8 u16TCCR1B_pre = 0;
  
  u8TCCR1A_pre = (uint8) (TIM1_CHA_COM_BITS << 6) | (TIM1_CHB_COM_BITS << 4) | (TIM1_MODE & 0b11);
  u8TCCR1B_pre = (uint8) (TIM1_NOISE_CANCEL << 7) |  (uint8) (TIM1_EDGE_SELECTION << 6) |  (uint8) TIM1_CLK_SEL | ((TIM1_MODE >> 2) << 3);
  
  TCCR1A  = u8TCCR1A_pre;
  TCCR1B  = u8TCCR1B_pre;
	
}

void TIM1_vidEnableOvfIreq(void)
{
	SET_BIT(TIMSK, 2);
}
void TIM1_vidDisableOvfIreq(void)
{
	CLEAR_BIT(TIMSK, 2);	
}

void TIM1_vidEnableCmpIreqOCR1A(void)
{
	SET_BIT(TIMSK, 4);
}

void TIM1_vidDisableCmpIreqOCRA1(void)
{
	CLEAR_BIT(TIMSK, 4);
}

void TIM1_vidEnableCmpIreqOCR1B(void)
{
	SET_BIT(TIMSK, 3)
}

void TIM1_vidDisableCmpIreqOCR1B(void)
{
	CLEAR_BIT(TIMSK, 3);
}

void TIM1_vidDisableCmpIreqOCRA1(void)
{
	CLEAR_BIT(TIMSK, 4);
}

void TIM1_vidSetCallbackOvf(pf pfCallBackCpy)
{
	TIM1_CallBack_Ovf = pfCallBackCpy;
}
void TIM1_vidSetCallbackCmpOCR1A(pf pfCallBackCpy)
{
	TIM1_CallBack_Cmp_OCR1A = pfCallBackCpy;
}

void TIM1_vidSetCallbackCmpOCR1B(pf pfCallBackCpy)
{
	TIM1_CallBack_Cmp_OCR1B= pfCallBackCpy;
}

void TIM1_vidSetCallbackICU(pf pfCallBackCpy)
{
	TIM1_CallBack_Cmp_ICU = pfCallBackCpy;
}

void TIM1_vidSetValueTcnt1(uint16 u16ValueCpy)
{
	TCNT1L = (uint8) u16ValueCpy;
	TCNT1H = (uint8) (u16ValueCpy >> 8);
}
void TIM1_vidSetValueOCR1A(uint16 uValueCpy)
{
	OCR1AL = (uint8) u16ValueCpy;
	OCRA1H = (uint8) (u16ValueCpy >> 8);
}

void TIM1_vidSetValueOCR1B(uint16 uValueCpy)
{
	OCR1BL = (uint8) u16ValueCpy;
	OCR1BH = (uint8) (u16ValueCpy >> 8);
}

uint16 TIM1_u8GetValueTcnt1(void)
{
	return (uint16) (TCNT1H << 8) | TCNT1L;
}


void TIM1_vidSetValueICU(uint16 u16ValueCpy)
{
	ICU1L = (uint8) u16ValueCpy;
	ICU1H = (uint8) (u16ValueCpy >> 8);
}

uint16 TIM1_u8GetValueICU(void)
{
	return (uint16) (ICU1H << 8) | ICU1L;
}

// Capture event (ICU ISR) interrupt vector
void __vector_6 (void) __attribute__((signal, used));
void __vector_6 (void)
{
	TIM1_CallBack_Cmp_ICU();
}

// Compare match (ISR) for OCR1A
void __vector_7 (void) __attribute__((signal, used));
void __vector_7 (void)
{
	TIM1_CallBack_Cmp_OCR1A();
}

// Compare match (ISR) for OCR1B 
void __vector_8 (void) __attribute__((signal, used));
void __vector_8 (void)
{
	TIM1_CallBack_Cmp_OCR1B();
}

// Overflow ISR
void __vector_9 (void) __attribute__((signal, used));
void __vector_9 (void)
{
	TIM1_CallBack_Ovf();
}

static void stub(void)
{
	
} 

uint8 getMode(void)
{
	return TIM1_MODE;
}