/********************************************************/
/** Description : private file for TIM1                 */
/** Author      : Marwan Tamer                 	    */
/** Date        : 24 May 2024                           */
/** Version     : 1.0V                                  */
/********************************************************/

#ifndef TIM1_PRIV_H
#define TIM1_PRIV_H

// Timer 1 TCCR
#define TCCR1A    *((volatile uint8 *) 0x4F)
#define TCCR1B    *((volatile uint8 *) 0x4E)

// Timer 1 TCNT Register
#define TCNT1H    *((volatile uint8 *) 0x4D)
#define TCNT1L    *((volatile uint8 *) 0x4C)

// Timer 1 ICU
#define ICU1H	  *((volatile uint8 *) 0x47)
#define ICU1L	  *((volatile uint8 *) 0x46)

// Output Capture Register A
#define OCR1AH    *((volatile uint8 *) 0x4B)
#define OCR1AL    *((volatile uint8 *) 0x4A)

// Output Capture Register B
#define OCR1BH    *((volatile uint8 *) 0x49)
#define OCR1BL    *((volatile uint8 *) 0x48)

// TIMSK, and TIFR 
#define TIMSK     *((volatile uint8 *) 0x59)
#define TIFR      *((volatile uint8 *) 0x58)


// Modes
#define TIM1_NORMAL             	   0
#define TIM1_PHASE_CORR_8BIT    	   1
#define TIM1_PHASE_CORR_9BIT    	   2
#define TIM1_PHASE_CORR_10BIT   	   3
#define TIM1_CTC_OCR1A          	   4
#define TIM1_FAST_PWM_8BIT      	   5
#define TIM1_FAST_PWM_9BIT      	   6
#define TIM1_FAST_PWM_10BIT     	   7
#define TIM1_PHASE_FREQ_CORR_ICU       8    //Phase correct freq 8 , 9. phase corr 10,11
#define TIM1_PHASE_FREQ_CORR_OCR1      9
#define TIM1_PHASE_CORR_ICU      	   10
#define TIM1_PHASE_CORR_OCR1A      	   11
#define TIM1_CTC_ICU     			   12
#define TIM1_FAST_PWM_ICU     		   14
#define TIM1_FAST_PWM_OCR1A     	   15

// Prescaler
#define TIM1_OFF                0
#define TIM1_PRESC_1            1
#define TIM1_PRESC_8            2
#define TIM1_PRESC_64           3
#define TIM1_PRESC_256          4
#define TIM1_PRESC_1024         5
#define TIM1_EXT_FALLING        6
#define TIM1_EXT_RISING         7

// Edge detection for ICU
#define TIM1_ICU_FALLING_EDGE		0
#define TIM1_ICU_RISING_EDGE		1

// Noise Cancelation 
#define TIM1_NOISE_CANCEL_OFF		0
#define TIM1_NOISE_CANCEL_ON		1

// Number for checking any error
#define VOID_CHECK_NUM  10

// Concatenation macro like function
#define CONC_(a,b) CONC_H_(a,b)
#deinfe CONC_H_(a,b) a##b 

// Guard the mode
#ifndef  TIM1_MODE
#define  TIM1_MODE TIM1_NORMAL

#else

	#define x CONC_(VOID_CHECK_NUM,TIM1_MODE)

	#if x == 10
	
		#undef TIM1_MODE
		#define TIM1_MODE TIM1_NORMAL
	
	#elif TIM1_MODE < TIM1_NORMAL  || TIM1_MODE > TIM1_FAST_PWM_OCR1A || TIM1_MODE == 13
		
		//#error "Out of range"; // For handling the error by writing a message to the user 
		
		#undef TIM1_MODE
		#define TIM1_MODE TIM1_NORMAL
		
	#endif

#endif

// Guard the clock selection
#ifndef TIM1_CLK_SEL
#define TIM1_CLK_SEL TIM1_PRESC_8

#else

	#define x CONC_(VOID_CHECK_NUM, TIM1_CLK_SEL)
	
	#if x == 10
	
		#undef TIM1_CLK_SEL
		#define TIM1_CLK_SEL TIM1_PRESC_8
		
	#elif TIM1_CLK_SEL < TIM1_OFF  || TIM1_CLK_SEL > TIM1_EXT_RISING 
		
		//#error "Out of range"; // For handling the error by writing a message to the user 
		
		#undef  TIM1_CLK_SEL
		#define TIM1_CLK_SEL TIM1_PRESC_8
	
	#endif
	

#endif

// Guard Channel A COM bits
#ifndef TIM1_CHA_COM_BITS
#define TIM1_CHA_COM_BITS TIM1_COM_BITS_DESC

#else

	#define x CONC_(VOID_CHECK_NUM, TIM1_CHA_COM_BITS)
	
	#if x == 10
	
		#undef  TIM1_CHA_COM_BITS
		#define TIM1_CHA_COM_BITS TIM1_COM_BITS_DESC
		
	#elif TIM1_CHA_COM_BITS < TIM1_COM_BITS_DESC  || TIM1_CHA_COM_BITS > TIM1_COM_BITS_SET 
		
		//#error "Out of range"; // For handling the error by writing a message to the user 
		
		#undef  TIM1_CHA_COM_BITS
		#define TIM1_CHA_COM_BITS TIM1_COM_BITS_DESC	
	
	#endif
	

#endif

// Guard Channel B COM bits
#ifndef TIM1_CHB_COM_BITS
#define TIM1_CHB_COM_BITS TIM1_COM_BITS_DESC

#else

	#define x CONC_(VOID_CHECK_NUM, TIM1_CHB_COM_BITS)
	
	#if x == 10
	
		#undef  TIM1_CHB_COM_BITS
		#define TIM1_CHB_COM_BITS TIM1_COM_BITS_DESC
		
	#elif TIM1_CHB_COM_BITS < TIM1_COM_BITS_DESC  || TIM1_CHB_COM_BITS > TIM1_COM_BITS_SET 
		
		//#error "Out of range"; // For handling the error by writing a message to the user 
		
		#undef  TIM1_CHB_COM_BITS
		#define TIM1_CHB_COM_BITS TIM1_COM_BITS_DESC
	
	#endif
	

#endif

// Guard edge selection
#ifndef TIM1_EDGE_SELECTION
#define TIM1_EDGE_SELECTION TIM1_ICU_RISING_EDGE 

#else

	#define x CONC_(VOID_CHECK_NUM, TIM1_EDGE_SELECTION)
	
	#if x == 10
	
		#undef  TIM1_EDGE_SELECTION
		#define TIM1_EDGE_SELECTION TIM1_ICU_RISING_EDGE
	
	#elif TIM1_EDGE_SELECTION < TIM1_ICU_FALLING_EDGE  || TIM1_EDGE_SELECTION > TIM1_ICU_RISING_EDGE 
		
		//#error "Out of range"; // For handling the error by writing a message to the user 
		
		#undef  TIM1_EDGE_SELECTION
		#define TIM1_EDGE_SELECTION TIM1_ICU_RISING_EDGE
	
	#endif
	

#endif

// Guard noise cancelation state
#ifndef TIM1_NOISE_CANCEL
#define TIM1_NOISE_CANCEL TIM1_NOISE_CANCEL_ON

#else

	#define x CONC_(VOID_CHECK_NUM, TIM1_NOISE_CANCEL)
	
	#if x == 10
	
		#undef  TIM1_NOISE_CANCEL
		#define TIM1_NOISE_CANCEL TIM1_NOISE_CANCEL_ON
		
	#elif TIM1_NOISE_CANCEL < TIM1_NOISE_CANCEL_OFF  || TIM1_NOISE_CANCEL > TIM1_NOISE_CANCEL_ON 
		
		//#error "Out of range"; // For handling the error by writing a message to the user 
		
		#undef  TIM1_NOISE_CANCEL
		#define TIM1_NOISE_CANCEL TIM1_NOISE_CANCEL_ON
	
	#endif
	

#endif


#if TIM1_MODE == TIM1_NORMAL || TIM1_MODE == TIM1_CTC_ICU || TIM1_MODE == TIM1_CTC_OCR1A

	#define TIM1_COM_BITS_DESC    0 // Disconnected
	#define TIM1_COM_BITS_TOGGLE  1 // Toggle on compare match
	#define TIM1_COM_BITS_CLEAR   2 // Clear on compare match (Set output to low level)
	#define TIM1_COM_BITS_SET     3 // Set on compare match (Set output to high level)
	
#elif TIM1_MODE == TIM1_PHASE_CORR_10BIT || TIM1_MODE == TIM1_PHASE_CORR_9BIT || TIM1_MODE == TIM1_PHASE_CORR_8BIT || TIM1_MODE == TIM1_PHASE_FREQ_CORR_ICU || TIM1_MODE == TIM1_PHASE_FREQ_CORR_OCR1 || TIM1_MODE == TIM1_PHASE_CORR_OCR1A || TIM1_MODE == TIM1_PHASE_CORR_ICU
	
	#define TIM1_COM_BITS_DESC    0 // Disconnected
	#define TIM1_COM_BITS_TOGGLE  1 // Toggle on compare match
	#define TIM1_COM_BITS_CLEAR   2 // Set on compare match when downcounting (Set output to low level)
	#define TIM1_COM_BITS_SET     3 // Clear on compare match when downcounting (Set output to high level)
	
#elif TIM1_MODE == TIM1_FAST_PWM_8BIT || TIM1_MODE == TIM1_FAST_PWM_9BIT || TIM1_MODE == TIM1_FAST_PWM_10BIT || TIM1_MODE == TIM1_FAST_PWM_OCR1A || TIM1_MODE == TIM1_FAST_PWM_ICU	
	
	#define TIM1_COM_BITS_DESC    0 // Disconnected
	#define TIM1_COM_BITS_TOGGLE  1 // Toggle on compare match
	#define TIM1_COM_BITS_CLEAR   2 // Clear on compare match means non-inverting mode (Set output to low level)
	#define TIM1_COM_BITS_SET     3 // Set on compare match means inverting mode (Set output to high level)

#endif	

static void stub(void);


#endif 