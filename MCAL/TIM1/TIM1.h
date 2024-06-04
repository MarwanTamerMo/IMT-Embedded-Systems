/********************************************************/
/** Description : Interface file for TIM1               */
/** Author      : Marwan Tamer                	    */
/** Date        : 24 May 2024                            */
/** Version     : 1.0V                                  */
/********************************************************/

#ifndef TIM1_H
#define TIM1_H

void TIM1_vidInit(void);

void TIM1_vidEnableOvfIreq(void);
void TIM1_vidDisableOvfIreq(void);

// OCR1A OCR1B CMP Interrupts
void TIM1_vidEnableCmpIreqOCR1A(void);
void TIM1_vidEnableCmpIreqOCR1B(void);

void TIM1_vidDisableCmpIreqOCR1A(void);
void TIM1_vidDisableCmpIreqOCR1B(void);

// ICU Interrupt
void TIM1_vidEnableIreqICU(void);
void TIM1_vidDisableIreqICU(void);

// OCR1A OCR1B SetCallBacks
void TIM1_vidSetCallbackCmpOCR1A(pf pfCallBackCpy);
void TIM1_vidSetCallbackCmpOCR1B(pf pfCallBackCpy);

// OVF SetCallBack
void TIM1_vidSetCallbackOvf(pf pfCallBackCpy);

// ICU
void TIM1_vidSetCallbackICU(pf pfCallBackCpy);

// TCNT1 Setters and Getters
void TIM1_vidSetValueTcnt1(uint16 u16ValueCpy);
uint8 TIM1_u8GetValueTcnt1(void);

// ICU Setters and Getters
void TIM1_vidSetValueICU(uint16 u16ValueCpy);
uint8 TIM1_u8GetValueICU(void);

// OCR1A Setter
void TIM1_vidSetValueOCR1A(uint16 u16ValueCpy);

// OCR1B Setter
void TIM1_vidSetValueOCR1B(uint16 u16ValueCpy);

// Change ICU Edge Sense
void TIM1_vidChangeICUSense(uint8 u8StateCpy);

 // 100, on : 20, off: 80
 // 50,  on: 25,  off: 25
 // 20,  on: 16,  off: 4
 // 
 // 3097 , 64


#endif