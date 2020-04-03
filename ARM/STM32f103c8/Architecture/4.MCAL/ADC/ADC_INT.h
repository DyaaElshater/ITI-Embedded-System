/****************************************************************/
/**	Name		:	Dyaa Elshater								*/
/**	Date		:	6/1/2019									*/
/**	Description	:	ADC Interface file							*/
/** MCU			:	STM32F103C8									*/
/**	Version		:	1.0 V									`	*/
/****************************************************************/

#ifndef ADC_INT_H_
#define ADC_INT_H_



#define ADC_CONTINUES_MODE	1
#define ADC_SINGLE_MODE		0


#define ADC_SINGLE_CHANNEL	1
#define ADC_MULTI_CHANNEL	0

#define ADC_ENABLE_CAL		1
#define ADC_DISABLE_CAL		0

#define ADC_LEFT_ALIGN		1
#define ADC_RIGHT_ALIGN		0

#define ADC_CHANNEL0		0
#define ADC_CHANNEL1		1
#define ADC_CHANNEL2		2
#define ADC_CHANNEL3		3
#define ADC_CHANNEL4		4
#define ADC_CHANNEL5		5
#define ADC_CHANNEL6		6
#define ADC_CHANNEL7		7
#define ADC_CHANNEL8		8
#define ADC_CHANNEL9		9
#define ADC_CHANNEL10		10
#define ADC_CHANNEL11		11
#define ADC_CHANNEL12		12
#define ADC_CHANNEL13		13
#define ADC_CHANNEL14		14
#define ADC_CHANNEL15		15
#define ADC_CHANNEL16		16


void ADC1_vidINIT();
void ADC2_vidINIT();
void ADC3_vidINIT();

void ADC1_vidRegularChannel_Start();
void ADC1_vidRegularChannel_Stop();
void ADC2_vidRegularChannel_Start();
void ADC2_vidRegularChannel_Stop();
void ADC3_vidRegularChannel_Start();
void ADC3_vidRegularChannel_Stop();

void ADC1_vidInjectedChannel_Start();
void ADC1_vidInjectedChannel_Stop();
void ADC2_vidInjectedChannel_Start();
void ADC2_vidInjectedChannel_Stop();
void ADC3_vidInjectedChannel_Start();
void ADC3_vidInjectedChannel_Stop();

u32 ADC1_u32RegularRead();
u32 ADC1_u32InjectedRead_JDR1();
u32 ADC1_u32InjectedRead_JDR2();
u32 ADC1_u32InjectedRead_JDR3();
u32 ADC1_u32InjectedRead_JDR4();
u32 ADC2_u32RegularRead();
u32 ADC2_u32InjectedRead_JDR1();
u32 ADC2_u32InjectedRead_JDR2();
u32 ADC2_u32InjectedRead_JDR3();
u32 ADC2_u32InjectedRead_JDR4();
u32 ADC3_u32RegularRead();
u32 ADC3_u32InjectedRead_JDR1();
u32 ADC3_u32InjectedRead_JDR2();
u32 ADC3_u32InjectedRead_JDR3();
u32 ADC3_u32InjectedRead_JDR4();

#endif /* ADC_INT_H_ */
