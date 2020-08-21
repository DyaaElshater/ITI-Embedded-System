/********************************************************************/
/** Name 		: Dyaa Elshater										*/
/** Date		: 6/7/2020											*/
/** Description	: DMA private file									*/
/** MCU			: STM32F103C8										*/
/** Version 	: 3.0V												*/
/********************************************************************/



#ifndef DMA_PRIV_H_
#define DMA_PRIV_H_

typedef struct
{
	u32 ISR		;
	u32 IFCR	;
	u32 CCR1	;
	u32 CNDTR1	;
	u32 CPAR1	;
	u32 CMAR1	;
	u32 Reserved1	;
	u32 CCR2	;
	u32 CNDTR2	;
	u32 CPAR2	;
	u32 CMAR2	;
	u32 Reserved2	;
	u32 CCR3	;
	u32 CNDTR3	;
	u32 CPAR3	;
	u32 CMAR3	;
	u32 Reserved	;
	u32 CCR4	;
	u32 CNDTR4	;
	u32 CPAR4	;
	u32 CMAR4	;
	u32 Reserved4	;
	u32 CCR5	;
	u32 CNDTR5	;
	u32 CPAR5	;
	u32 CMAR5	;
	u32 Reserved5	;
	u32 CCR6	;
	u32 CNDTR6	;
	u32 CPAR6	;
	u32 CMAR6	;
	u32 Reserved6	;
	u32 CCR7	;
	u32 CNDTR7	;
	u32 CPAR7	;
	u32 CMAR7	;
	u32 Reserved7	;
}DMA_Register;

#define DMA1		((volatile DMA_Register*)(0x40020000))
#define DMA2		((volatile DMA_Register*)(0x40020400))

		/*ISR*/
#define	TEIF7	27
#define	HTIF7 	26
#define	TCIF7 	25
#define	GIF7 	24
#define	TEIF6 	23
#define	HTIF6 	22
#define	TCIF6 	21
#define	GIF6 	20
#define	TEIF5 	19
#define	HTIF5 	18
#define	TCIF5 	17
#define	GIF5 	16
#define	TEIF4 	15
#define	HTIF4 	14
#define	TCIF4 	13
#define	GIF4 	12
#define	TEIF3 	11
#define	HTIF3 	10
#define	TCIF3 	9
#define	GIF3 	8
#define	TEIF2 	7
#define	HTIF2 	6
#define	TCIF2 	5
#define	GIF2 	4
#define	TEIF1 	3
#define	HTIF1 	2
#define	TCIF1 	1
#define	GIF1	0

		/*IFCR*/
#define	CTEIF7	27
#define	CHTIF7 	26
#define	CTCIF7 	25
#define	CGIF7 	24
#define	CTEIF6 	23
#define	CHTIF6 	22
#define	CTCIF6 	21
#define	CGIF6 	20
#define	CTEIF5 	19
#define	CHTIF5 	18
#define	CTCIF5 	17
#define	CGIF5 	16
#define	CTEIF4 	15
#define	CHTIF4 	14
#define	CTCIF4 	13
#define	CGIF4 	12
#define	CTEIF3 	11
#define	CHTIF3 	10
#define	CTCIF3 	9
#define	CGIF3 	8
#define	CTEIF2 	7
#define	CHTIF2 	6
#define	CTCIF2 	5
#define	CGIF2 	4
#define	CTEIF1 	3
#define	CHTIF1 	2
#define	CTCIF1 	1
#define	CGIF1	0

	/*CCRx*/
#define	CTEIF7 	27
#define	CHTIF7 	26
#define	CTCIF7 	25
#define	CGIF7 	24
#define	CTEIF6 	23
#define	CHTIF6 	22
#define	CTCIF6 	21
#define	CGIF6 	20
#define	CTEIF5 	19
#define	CHTIF5 	18
#define	CTCIF5 	17
#define	CGIF5 	16
#define	CTEIF4 	15
#define	CHTIF4 	14
#define	CTCIF4 	13
#define	CGIF4 	12
#define	CTEIF3 	11
#define	CHTIF3 	10
#define	CTCIF3 	9
#define	CGIF3 	8
#define	CTEIF2 	7
#define	CHTIF2 	6
#define	CTCIF2 	5
#define	CGIF2 	4
#define	CTEIF1 	3
#define	CHTIF1 	2
#define	CTCIF1 	1
#define	CGIF1	0

	/*CCRx*/
#define	MEM2MEM	14
#define	PL		12
#define	MSIZE	10
#define	PSIZE	8
#define	MINC	7
#define	PINC	6
#define	CIRC	5
#define	DIR		4
#define	TEIE	3
#define	HTIE	2
#define	TCIE	1
#define	EN		0

#define DMA1_MAX_CHANNELS	7
#define DMA2_MAX_CHANNELS	5

void __DMA_Temp(void){}

static vidpfvid DMA1_TCI[DMA1_MAX_CHANNELS];
static vidpfvid DMA2_TCI[DMA2_MAX_CHANNELS];

static vidpfvid DMA1_HTI[DMA1_MAX_CHANNELS];
static vidpfvid DMA2_HTI[DMA2_MAX_CHANNELS];

static vidpfvid DMA1_TEI[DMA1_MAX_CHANNELS];
static vidpfvid DMA2_TEI[DMA2_MAX_CHANNELS];

#define DMA_MASK_GIF_BIT		1
#define DMA_MASK_TCIF_BIT		2
#define DMA_MASK_HTIF_BIT		4
#define DMA_MASK_TEIF_BIT		8


#endif /* DMA_PRIV_H_ */
