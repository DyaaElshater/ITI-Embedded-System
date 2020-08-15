/****************************************************************/
/**	Name		:	Dyaa Elshater								*/
/**	Date		:	6/1/2019									*/
/**	Description	:	ADC Private file							*/
/** MCU			:	STM32F103C8									*/
/**	Version		:	2.0 V									`	*/
/****************************************************************/

#ifndef ADC_PRIV_H_
#define ADC_PRIV_H_

typedef struct
{
	u32 SR;
	u32 CR1;
	u32 CR2;
	u32 SMPR1;
	u32 SMPR2;
	u32 JOFR1;
	u32 JOFR2;
	u32 JOFR3;
	u32 JOFR4;
	u32 HTR;
	u32 LTR;
	u32 SQR1;
	u32 SQR2;
	u32 SQR3;
	u32 JSQR;
	u32 JDR1;
	u32 JDR2;
	u32 JDR3;
	u32 JDR4;
	u32 DR;
}ADC_REG;

/*
#define ADC1	((volatile ADC_REG*)(0x40012400))
#define ADC2	((volatile ADC_REG*)(0x40012800))
#define ADC3	((volatile ADC_REG*)(0x40013C00))
*/


static volatile ADC_REG*const ADC1 = (volatile ADC_REG*)(0x40012400);
static volatile ADC_REG*const ADC2 = (volatile ADC_REG*)(0x40012800);
static volatile ADC_REG*const ADC3 = (volatile ADC_REG*)(0x40013C00);



/*
#define ADC1 (volatile ADC_REG*)(0x40012400)
#define ADC2 (volatile ADC_REG*)(0x40012800)
#define ADC3 (volatile ADC_REG*)(0x40013C00)
*/


		/*SR*/
#define STRT	4
#define JSTRT	3
#define JEOC	2
#define EOC		1
#define AWD		0
		/*CR1*/
#define AWDEN	23
#define JAWDEN	22
#define DUALMOD	16
#define DISCNUM	13
#define JDISCEN	12
#define DISCEN	11
#define JAUTO	10
#define AWDSGL	9
#define SCAN	8
#define JEOCIE	7
#define AWDIE	6
#define EOCIE	5
#define AWDCH	0
		/*CR2*/
#define TSVREFE	23
#define SWSTART	22
#define JSWSTART 21
#define EXTTRIG	20
#define EXTSEL	17
#define JEXTTRIG 15
#define JEXTSEL	12
#define ALIGN	11
#define DMA		8
#define RSTCAL	3
#define CAL		2
#define CONT	1
#define ADON	0
		/*SQR1*/
#define	L		20
#define	SQ16	15
#define	SQ15	10
#define	SQ14	5
#define	SQ13	0
		/*SQR2*/
#define	SQ12	25
#define	SQ11	20
#define	SQ10	15
#define	SQ9		10
#define	SQ8		5
#define	SQ7		0
		/*SQR3*/
#define	SQ6		25
#define	SQ5		20
#define	SQ4		15
#define	SQ3		10
#define	SQ2		5
#define	SQ1		0
		/*JSQR*/
#define	JL		20
#define	JSQ4	15
#define	JSQ3	10
#define	JSQ2	5
#define	JSQ1	0
		/*DR*/
#define	ADC2DATA	16

void ADC_TEM(void){}
vidpfvid ADC_EOC[3] ={ADC_TEM,ADC_TEM,ADC_TEM},
		 ADC_WD[3]  ={ADC_TEM,ADC_TEM,ADC_TEM} ,
		 ADC_JEOC[3]={ADC_TEM,ADC_TEM,ADC_TEM};

#define ADC_CHECK_AWD_BIT	1
#define ADC_CHECK_EOC_BIT	2
#define ADC_CHECK_JEOC_BIT	4
#define ADC_CHECK_JSTRT_BIT	8
#define ADC_CHECK_STRT_BIR	16


#endif /* ADC_PRIV_H_ */
