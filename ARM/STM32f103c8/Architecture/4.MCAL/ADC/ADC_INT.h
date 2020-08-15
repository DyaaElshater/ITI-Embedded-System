/****************************************************************/
/**	Name		:	Dyaa Elshater								*/
/**	Date		:	6/1/2019									*/
/**	Description	:	ADC Interface file							*/
/** MCU			:	STM32F103C8									*/
/**	Version		:	2.0 V									`	*/
/****************************************************************/

#ifndef ADC_INT_H_
#define ADC_INT_H_



#define ADC_CONTINUES_MODE	1
#define ADC_SINGLE_MODE		0


#define ADC_SINGLE_CHANNEL	1
#define ADC_MULTI_CHANNEL	0

#define ADC_LEFT_ALIGN		1
#define ADC_RIGHT_ALIGN		0

typedef enum
{
ADC_CHANNEL0		,
ADC_CHANNEL1		,
ADC_CHANNEL2		,
ADC_CHANNEL3		,
ADC_CHANNEL4		,
ADC_CHANNEL5		,
ADC_CHANNEL6		,
ADC_CHANNEL7		,
ADC_CHANNEL8		,
ADC_CHANNEL9		,
ADC_CHANNEL10		,
ADC_CHANNEL11		,
ADC_CHANNEL12		,
ADC_CHANNEL13		,
ADC_CHANNEL14		,
ADC_CHANNEL15		,
ADC_CHANNEL16		,
ADC_CHANNEL17
}tdefAdcChannels;


typedef enum
{
	ALIGN_RIGHT,ALIGN_LEFT
}tdefADC_ALIGN;

typedef enum
{
	TIMER_1_TRGO_EVENT,
	TIMER_1_CC4_EVENT,
	ADC1_2_TIMER2_TRGO_EVENT__ADC3_TIMER4_CC3_EVENT,
	ADC1_2_TIMER2_CC1_EVENT__ADC3_TIMER8_CC2_EVENT,
	ADC1_2_TIMER3__ADC3_TIMER8_CC4_EVENT,
	ADC1_2_TIMER4__ADC3_TIMER5_TRGO_EVENT,
	ADC1_2_EXTI_line15__TIM8_CC4_EVENT___ADC3_TIMER5_CC4_EVENT,
	Injected_SoftWare
}tdefInjectedExtTrigger;

typedef enum
{
	ADC1_2_TIMER1__ADC3_TIMER3_CC1_EVENT,
	ADC1_2_TIMER1_CC2_EVENT__ADC3_TIMER2_CC3_EVENT,
	TIMER1_CC3_EVENT,
	ADC1_2_TIMER2_CC2_EVENT__ADC3_TIMER8_CC1_EVENT,
	ADC1_2_TIMER3__ADC3_TIMER8_TRGO_EVENT,
	ADC1_2_TIMER4_CC4_EVENT__ADC3_TIMER5_CC1_EVENT,
	ADC1_2_EXTI_line11__TIM8_CC4_EVENT___ADC3_TIMER5_CC3_EVENT,
	Regular_SoftWare
}tdefRegularExtTrigger;


typedef enum
{
	ADC_Disable,ADC_Enable
}tdefAdcEn;

void ADC1_vidINIT();
void ADC2_vidINIT();
void ADC3_vidINIT();

void ADC1_vidRegularChannel_Start();
void ADC2_vidRegularChannel_Start();
void ADC3_vidRegularChannel_Start();

void ADC1_vidInjectedChannel_Start();
void ADC2_vidInjectedChannel_Start();
void ADC3_vidInjectedChannel_Start();

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

		/**	Update **/
void ADC1_vidResetCalibration(void);
void ADC2_vidResetCalibration(void);
void ADC3_vidResetCalibration(void);

void ADC1_vidSetAlign(tdefADC_ALIGN enuAdcAlignCpy);
void ADC2_vidSetAlign(tdefADC_ALIGN enuAdcAlignCpy);
void ADC3_vidSetAlign(tdefADC_ALIGN enuAdcAlignCpy);

void ADC1_vidEnableInjectedExternalEvent(tdefAdcEn enuAdcEnCpy);
void ADC2_vidEnableInjectedExternalEvent(tdefAdcEn enuAdcEnCpy);
void ADC3_vidEnableInjectedExternalEvent(tdefAdcEn enuAdcEnCpy);

void ADC1_vidSetInjectedExtTriggeredEvent(tdefInjectedExtTrigger enuInjectedExtTriggerCpy);
void ADC2_vidSetInjectedExtTriggeredEvent(tdefInjectedExtTrigger enuInjectedExtTriggerCpy);
void ADC3_vidSetInjectedExtTriggeredEvent(tdefInjectedExtTrigger enuInjectedExtTriggerCpy);

void ADC1_vidEnableRegularExternalEvent(tdefAdcEn enuAdcEnCpy);
void ADC2_vidEnableRegularExternalEvent(tdefAdcEn enuAdcEnCpy);
void ADC3_vidEnableRegularExternalEvent(tdefAdcEn enuAdcEnCpy);

void ADC1_vidSetRegularExtTriggeredEvent(tdefRegularExtTrigger enuRegularExtTriggerCpy);
void ADC2_vidSetRegularExtTriggeredEvent(tdefRegularExtTrigger enuRegularExtTriggerCpy);
void ADC3_vidSetRegularExtTriggeredEvent(tdefRegularExtTrigger enuRegularExtTriggerCpy);

void ADC1_vidSetRegularSoftwareTrigger(void);
void ADC2_vidSetRegularSoftwareTrigger(void);
void ADC3_vidSetRegularSoftwareTrigger(void);

void ADC1_vidSetRegularSoftwareTrigger(void);
void ADC2_vidSetRegularSoftwareTrigger(void);
void ADC3_vidSetRegularSoftwareTrigger(void);

void ADC1_vidSetInjectedSoftwareTrigger(void);
void ADC2_vidSetInjectedSoftwareTrigger(void);
void ADC3_vidSetInjectedSoftwareTrigger(void);

void ADC1_vidSetTemperatureEnable(tdefAdcEn enuAdcEnCpy);
void ADC2_vidSetTemperatureEnable(tdefAdcEn enuAdcEnCpy);
void ADC3_vidSetTemperatureEnable(tdefAdcEn enuAdcEnCpy);

u16 ADC1_u16GetTemperatureValue(void);
u16 ADC2_u16GetTemperatureValue(void);
u16 ADC3_u16GetTemperatureValue(void);

void ADC1_vidDMA_Enable(void);
void ADC1_vidDMA_Disable(void);
void ADC2_vidDMA_Enable(void);
void ADC2_vidDMA_Disable(void);
void ADC3_vidDMA_Enable(void);
void ADC3_vidDMA_Disable(void);

void ADC1_vidSelectWatchDogChannels(tdefAdcChannels enuAdcChannelCpy);
void ADC2_vidSelectWatchDogChannels(tdefAdcChannels enuAdcChannelCpy);
void ADC3_vidSelectWatchDogChannels(tdefAdcChannels enuAdcChannelCpy);

void ADC1_vidWatchDogEnableScanMode(tdefAdcEn enuAdcEn);
void ADC2_vidWatchDogEnableScanMode(tdefAdcEn enuAdcEn);
void ADC3_vidWatchDogEnableScanMode(tdefAdcEn enuAdcEn);

void ADC1_vidEnableEndOfConvertionInterrupt(tdefAdcEn enuAdcEn);
void ADC2_vidEnableEndOfConvertionInterrupt(tdefAdcEn enuAdcEn);
void ADC3_vidEnableEndOfConvertionInterrupt(tdefAdcEn enuAdcEn);

void ADC1_vidEnableEndOfConvertionInjectedChannelsInterrupt(tdefAdcEn enuAdcEn);
void ADC2_vidEnableEndOfConvertionInjectedChannelsInterrupt(tdefAdcEn enuAdcEn);
void ADC3_vidEnableEndOfConvertionInjectedChannelsInterrupt(tdefAdcEn enuAdcEn);

void ADC1_vidEnableWatchDogInterrupt(tdefAdcEn enuAdcEn);
void ADC2_vidEnableWatchDogInterrupt(tdefAdcEn enuAdcEn);
void ADC3_vidEnableWatchDogInterrupt(tdefAdcEn enuAdcEn);

void ADC1_vidSetEndOfConvertionCallBackFunction(vidpfvid pfCallBackCpy);
void ADC2_vidSetEndOfConvertionCallBackFunction(vidpfvid pfCallBackCpy);
void ADC3_vidSetEndOfConvertionCallBackFunction(vidpfvid pfCallBackCpy);

void ADC1_vidSetWatchDogCallBackFunction(vidpfvid pfCallBackCpy);
void ADC2_vidSetWatchDogCallBackFunction(vidpfvid pfCallBackCpy);
void ADC3_vidSetWatchDogCallBackFunction(vidpfvid pfCallBackCpy);

void ADC1_vidSetEndOfConvertionInjectedChannelsCallBackFunction(vidpfvid pfCallBackCpy);
void ADC2_vidSetEndOfConvertionInjectedChannelsCallBackFunction(vidpfvid pfCallBackCpy);
void ADC3_vidSetEndOfConvertionInjectedChannelsCallBackFunction(vidpfvid pfCallBackCpy);

void ADC1_vidAutomaticInjectedGroupconversionEnable(tdefAdcEn enuAdcEnCpy);
void ADC2_vidAutomaticInjectedGroupconversionEnable(tdefAdcEn enuAdcEnCpy);
void ADC3_vidAutomaticInjectedGroupconversionEnable(tdefAdcEn enuAdcEnCpy);

void ADC1_vidDiscontinuousModeInjectedChannelEnable (tdefAdcEn enuAdcEnCpy);
void ADC2_vidDiscontinuousModeInjectedChannelEnable (tdefAdcEn enuAdcEnCpy);
void ADC3_vidDiscontinuousModeInjectedChannelEnable (tdefAdcEn enuAdcEnCpy);

typedef enum
{
	ADC_1_Channel ,
	ADC_2_Channels,
	ADC_3_Channels,
	ADC_4_Channels,
	ADC_5_Channels,
	ADC_6_Channels,
	ADC_7_Channels,
	ADC_8_Channels
}tdefAdcNODiscontinuousCh;

void ADC1_vidSetDiscontinuousChannelNumber(tdefAdcNODiscontinuousCh enuAdcNODiscontinuousCh);
void ADC2_vidSetDiscontinuousChannelNumber(tdefAdcNODiscontinuousCh enuAdcNODiscontinuousCh);
void ADC3_vidSetDiscontinuousChannelNumber(tdefAdcNODiscontinuousCh enuAdcNODiscontinuousCh);

typedef enum
{
	Independent_mode,
	Combined_regular_simultaneous__injected_simultaneous_mode,
	Combined_regular_simultaneous__alternate_trigger_mode,
	Combined_injected_simultaneous__fast_interleaved_mode,
	Combined_injected_simultaneous__slow_Interleaved_mode,
	Injected_simultaneous_mode_only,
	Regular_simultaneous_mode_only,
	Fast_interleaved_mode_only,
	 Slow_interleaved_mode_only,
	 Alternate_trigger_mode_only
}tdefAdcDualMode;
void ADC1_vidDualMode(tdefAdcDualMode enumAdcDualModeCpy);

void ADC1_vidWatchDogEnable(tdefAdcEn enuAdcEnCpy);
void ADC2_vidWatchDogEnable(tdefAdcEn enuAdcEnCpy);
void ADC3_vidWatchDogEnable(tdefAdcEn enuAdcEnCpy);

void ADC1_vidInjectedWatchDogEnable(tdefAdcEn enuAdcEnCpy);
void ADC2_vidInjectedWatchDogEnable(tdefAdcEn enuAdcEnCpy);
void ADC3_vidInjectedWatchDogEnable(tdefAdcEn enuAdcEnCpy);

void ADC1_vidSetRegularLength(u8 u8LengthCpy);
void ADC1_vidSetSQR1(tdefAdcChannels enuAdcChannelCpy);
void ADC1_vidSetSQR2(tdefAdcChannels enuAdcChannelCpy);
void ADC1_vidSetSQR3(tdefAdcChannels enuAdcChannelCpy);
void ADC1_vidSetSQR4(tdefAdcChannels enuAdcChannelCpy);
void ADC1_vidSetSQR5(tdefAdcChannels enuAdcChannelCpy);
void ADC1_vidSetSQR6(tdefAdcChannels enuAdcChannelCpy);
void ADC1_vidSetSQR7(tdefAdcChannels enuAdcChannelCpy);
void ADC1_vidSetSQR8(tdefAdcChannels enuAdcChannelCpy);
void ADC1_vidSetSQR9(tdefAdcChannels enuAdcChannelCpy);
void ADC1_vidSetSQR10(tdefAdcChannels enuAdcChannelCpy);
void ADC1_vidSetSQR11(tdefAdcChannels enuAdcChannelCpy);
void ADC1_vidSetSQR12(tdefAdcChannels enuAdcChannelCpy);
void ADC1_vidSetSQR13(tdefAdcChannels enuAdcChannelCpy);
void ADC1_vidSetSQR14(tdefAdcChannels enuAdcChannelCpy);
void ADC1_vidSetSQR15(tdefAdcChannels enuAdcChannelCpy);
void ADC1_vidSetSQR16(tdefAdcChannels enuAdcChannelCpy);
void ADC1_vidSetInjectedLength(u8 u8Length);
void ADC1_vidSetJSQR1(tdefAdcChannels enuAdcChannelCpy);
void ADC1_vidSetJSQR2(tdefAdcChannels enuAdcChannelCpy);
void ADC1_vidSetJSQR3(tdefAdcChannels enuAdcChannelCpy);
void ADC1_vidSetJSQR4(tdefAdcChannels enuAdcChannelCpy);

void ADC2_vidSetRegularLength(u8 u8LengthCpy);
void ADC2_vidSetSQR1(tdefAdcChannels enuAdcChannelCpy);
void ADC2_vidSetSQR2(tdefAdcChannels enuAdcChannelCpy);
void ADC2_vidSetSQR3(tdefAdcChannels enuAdcChannelCpy);
void ADC2_vidSetSQR4(tdefAdcChannels enuAdcChannelCpy);
void ADC2_vidSetSQR5(tdefAdcChannels enuAdcChannelCpy);
void ADC2_vidSetSQR6(tdefAdcChannels enuAdcChannelCpy);
void ADC2_vidSetSQR7(tdefAdcChannels enuAdcChannelCpy);
void ADC2_vidSetSQR8(tdefAdcChannels enuAdcChannelCpy);
void ADC2_vidSetSQR9(tdefAdcChannels enuAdcChannelCpy);
void ADC2_vidSetSQR10(tdefAdcChannels enuAdcChannelCpy);
void ADC2_vidSetSQR11(tdefAdcChannels enuAdcChannelCpy);
void ADC2_vidSetSQR12(tdefAdcChannels enuAdcChannelCpy);
void ADC2_vidSetSQR13(tdefAdcChannels enuAdcChannelCpy);
void ADC2_vidSetSQR14(tdefAdcChannels enuAdcChannelCpy);
void ADC2_vidSetSQR15(tdefAdcChannels enuAdcChannelCpy);
void ADC2_vidSetSQR16(tdefAdcChannels enuAdcChannelCpy);
void ADC2_vidSetInjectedLength(u8 u8Length);
void ADC2_vidSetJSQR1(tdefAdcChannels enuAdcChannelCpy);
void ADC2_vidSetJSQR2(tdefAdcChannels enuAdcChannelCpy);
void ADC2_vidSetJSQR3(tdefAdcChannels enuAdcChannelCpy);
void ADC2_vidSetJSQR4(tdefAdcChannels enuAdcChannelCpy);

void ADC3_vidSetRegularLength(u8 u8LengthCpy);
void ADC3_vidSetSQR1(tdefAdcChannels enuAdcChannelCpy);
void ADC3_vidSetSQR2(tdefAdcChannels enuAdcChannelCpy);
void ADC3_vidSetSQR3(tdefAdcChannels enuAdcChannelCpy);
void ADC3_vidSetSQR4(tdefAdcChannels enuAdcChannelCpy);
void ADC3_vidSetSQR5(tdefAdcChannels enuAdcChannelCpy);
void ADC3_vidSetSQR6(tdefAdcChannels enuAdcChannelCpy);
void ADC3_vidSetSQR7(tdefAdcChannels enuAdcChannelCpy);
void ADC3_vidSetSQR8(tdefAdcChannels enuAdcChannelCpy);
void ADC3_vidSetSQR9(tdefAdcChannels enuAdcChannelCpy);
void ADC3_vidSetSQR10(tdefAdcChannels enuAdcChannelCpy);
void ADC3_vidSetSQR11(tdefAdcChannels enuAdcChannelCpy);
void ADC3_vidSetSQR12(tdefAdcChannels enuAdcChannelCpy);
void ADC3_vidSetSQR13(tdefAdcChannels enuAdcChannelCpy);
void ADC3_vidSetSQR14(tdefAdcChannels enuAdcChannelCpy);
void ADC3_vidSetSQR15(tdefAdcChannels enuAdcChannelCpy);
void ADC3_vidSetSQR16(tdefAdcChannels enuAdcChannelCpy);
void ADC3_vidSetInjectedLength(u8 u8Length);
void ADC3_vidSetJSQR1(tdefAdcChannels enuAdcChannelCpy);
void ADC3_vidSetJSQR2(tdefAdcChannels enuAdcChannelCpy);
void ADC3_vidSetJSQR3(tdefAdcChannels enuAdcChannelCpy);
void ADC3_vidSetJSQR4(tdefAdcChannels enuAdcChannelCpy);

u8 ADC1_u8CheckAnalogWatchDogFlag();
u8 ADC2_u8CheckAnalogWatchDogFlag();
u8 ADC3_u8CheckAnalogWatchDogFlag();

u8 ADC1_u8CheckRegularEndOfConversionFlag();
u8 ADC2_u8CheckRegularEndOfConversionFlag();
u8 ADC3_u8CheckRegularEndOfConversionFlag();

u8 ADC1_u8CheckInjectedEndOfConversion();
u8 ADC2_u8CheckInjectedEndOfConversion();
u8 ADC3_u8CheckInjectedEndOfConversion();

u8 ADC1_u8CheckRegularStartFlag();
u8 ADC2_u8CheckRegularStartFlag();
u8 ADC3_u8CheckRegularStartFlag();

u8 ADC1_u8CheckInjectedStartFlag();
u8 ADC2_u8CheckInjectedStartFlag();
u8 ADC3_u8CheckInjectedStartFlag();

#endif /* ADC_INT_H_ */
