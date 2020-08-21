/********************************************************************/
/** Name 		: Dyaa Elshater										*/
/** Date		: 6/7/2020											*/
/** Description	: DMA interface file								*/
/** MCU			: STM32F103C8										*/
/** Version 	: 3.0V												*/
/********************************************************************/

#ifndef DMA_INT_H_
#define DMA_INT_H_


typedef enum
{
	DMA_LowPriority,
	DMA_MediumPriority,
	DMA_HighPriority,
	DMA_VeryHighPriority
}tdefDmapriority;

typedef enum
{
	DMA_ReadFromPeripheral,
	DMA_ReadFromMemory
}tdefDmaDirection;

typedef enum
{
	DMA_DISABLE,
	DMA_ENABLE
}tdefDmaEn;

typedef enum
{
	DMA_8_bits,
	DMA_16_bits,
	DMA_32_bits
}tdefDMADataSize;

typedef struct
{
	u32 DMA_CCR		;
	u32 DMA_CNDTR	;
	u32 DMA_CPAR	;
	u32 DMA_CMAR	;
}tdefChannelRegisters;

typedef struct
{
	tdefChannelRegisters *CHannelRegisters ;
	u32					PeripheralAdress	;
	u32					MemoryAdress	;
	u16 				NumberOfDataTransfer;
	tdefDmapriority 	priority:2;
	tdefDmaDirection 	Direction:1	;
	tdefDmaEn			CircularMode :1 ;
	tdefDmaEn			PeripheralIncrement :1 ;
	tdefDmaEn			MemoryIncrement : 1	;
	tdefDMADataSize		MemorySize : 2 ;
	tdefDMADataSize		PeripheralSize : 2 ;
	tdefDmaEn			MwmoryToMemory :1 ;
	tdefDmaEn			TransferCompleteInterruptEnable :1 ;
	tdefDmaEn			HalfTransferInterruptEnable :1 ;
	tdefDmaEn			TransferErrorInterruptEnable :1 ;
	tdefDmaEn			ChannelEnable :1 	;
}tdefDmaChannel;


#define DMA1_BASE_ADDRESS	(0x40020000)
#define DMA2_BASE_ADDRESS	(0x40020400)

#define DMA_CH1_CCR_OFFSET	(0x008)
#define DMA_CH2_CCR_OFFSET	(0x01C)
#define DMA_CH3_CCR_OFFSET	(0x030)
#define DMA_CH4_CCR_OFFSET	(0x044)
#define DMA_CH5_CCR_OFFSET	(0x058)
#define DMA_CH6_CCR_OFFSET	(0x06C)
#define DMA_CH7_CCR_OFFSET	(0x080)


void DMA1_vidInit();
void DMA2_vidInit();

typedef enum
{
	DMA_Channel_1,
	DMA_Channel_2,
	DMA_Channel_3,
	DMA_Channel_4,
	DMA_Channel_5,
	DMA_Channel_6,
	DMA_Channel_7
}tdefDMAChannels;

/** enuDmaChannelCpy -> DMA_Channel_x , x should be from 1 to 7*/
void DMA1_vidEnable_Channel(tdefDMAChannels enuDmaChannelCpy,tdefDmaEn enuDmaEnCpy);

/** enuDmaChannelCpy -> DMA_Channel_x , x should be from 1 to 5*/
void DMA2_vidEnable_Channel(tdefDMAChannels enuDmaChannelCpy,tdefDmaEn enuDmaEnCpy);

u8 DMA1_u8CheckGlobalInterrutFlag(tdefDMAChannels enuDmaChannel);
u8 DMA1_u8CheckTransferCompleteFlag(tdefDMAChannels enuDmaChannel);
u8 DMA1_u8CheckHalfTransferFlag(tdefDMAChannels enuDmaChannel);
u8 DMA1_u8CheckTransferErrorFlag(tdefDMAChannels enuDmaChannel);

u8 DMA2_u8CheckGlobalInterrutFlag(tdefDMAChannels enuDmaChannel);
u8 DMA2_u8CheckTransferCompleteFlag(tdefDMAChannels enuDmaChannel);
u8 DMA2_u8CheckHalfTransferFlag(tdefDMAChannels enuDmaChannel);
u8 DMA2_u8CheckTransferErrorFlag(tdefDMAChannels enuDmaChannel);

void DMA1_vidClearGlobalInterrutFlag(tdefDMAChannels enuDmaChannel);
void DMA1_vidClearTransferCompleteFlag(tdefDMAChannels enuDmaChannel);
void DMA1_vidClearHalfTransferFlag(tdefDMAChannels enuDmaChannel);
void DMA1_vidCheckTransferErrorFlag(tdefDMAChannels enuDmaChannel);

void DMA2_vidClearGlobalInterrutFlag(tdefDMAChannels enuDmaChannel);
void DMA2_vidClearTransferCompleteFlag(tdefDMAChannels enuDmaChannel);
void DMA2_vidClearHalfTransferFlag(tdefDMAChannels enuDmaChannel);
void DMA2_vidClearTransferErrorFlag(tdefDMAChannels enuDmaChannel);

void DMA1_vidEnableMemoryToMemoryMode(tdefDMAChannels enuDmaChannelCpy,tdefDmaEn enuDmaEnCpy);
void DMA2_vidEnableMemoryToMemoryMode(tdefDMAChannels enuDmaChannelCpy,tdefDmaEn enuDmaEnCpy);

void DMA1_vidSetChannelpriority(tdefDMAChannels enuDmaChannelCpy , tdefDmapriority enuDmapriority);
void DMA2_vidSetChannelpriority(tdefDMAChannels enuDmaChannelCpy, tdefDmapriority enuDmapriority);

void DMA1_vidSetMemorySize(tdefDMAChannels enuDmaChannelCpy,tdefDMADataSize enuMSizeCpy);
void DMA1_vidSetPeripheralSize(tdefDMAChannels enuDmaChannelCpy,tdefDMADataSize enuPSizeCpy);

void DMA2_vidSetMemorySize(tdefDMAChannels enuDmaChannelCpy,tdefDMADataSize enuMSizeCpy);
void DMA2_vidSetPeripheralSize(tdefDMAChannels enuDmaChannelCpy,tdefDMADataSize enuPSizeCpy);

void DMA1_vidSetMemoryIncrementMode(tdefDMAChannels enuDmaChannelCpy,tdefDmaEn enuDmaEnCpy);
void DMA1_vidSetPeripheralIncrementMode(tdefDMAChannels enuDmaChannelCpy,tdefDmaEn enuDmaEnCpy);
void DMA1_vidSetMemoryIncrementMode(tdefDMAChannels enuDmaChannelCpy,tdefDmaEn enuDmaEnCpy);
void DMA1_vidSetPeripheralIncrementMode(tdefDMAChannels enuDmaChannelCpy,tdefDmaEn enuDmaEnCpy);

void DMA1_vidSetCircularMode(tdefDMAChannels enuDmaChannelCpy,tdefDmaEn enuDmaEnCpy);
void DMA2_vidSetCircularMode(tdefDMAChannels enuDmaChannelCpy,tdefDmaEn enuDmaEnCpy);

void DMA1_vidSetDataTransferDirection(tdefDMAChannels enuDmaChannelCpy,tdefDmaDirection enuDIRCpy);
void DMA2_vidSetDataTransferDirection(tdefDMAChannels enuDmaChannelCpy,tdefDmaDirection enuDIRCpy);

void DMA1_vidEnableTransferErrorInterrupt(tdefDMAChannels enuDmaChannelCpy,tdefDmaEn enuDmaEnCpy);
void DMA2_vidEnableTransferErrorInterrupt(tdefDMAChannels enuDmaChannelCpy,tdefDmaEn enuDmaEnCpy);

void DMA1_vidEnableHallfTransferInterrupt(tdefDMAChannels enuDmaChannelCpy,tdefDmaEn enuDmaEnCpy);
void DMA2_vidEnableHallfTransferInterrupt(tdefDMAChannels enuDmaChannelCpy,tdefDmaEn enuDmaEnCpy);

void DMA1_vidEnableTransferCompleteInterrupt(tdefDMAChannels enuDmaChannelCpy,tdefDmaEn enuDmaEnCpy);
void DMA2_vidEnableTransferCompleteInterrupt(tdefDMAChannels enuDmaChannelCpy,tdefDmaEn enuDmaEnCpy);

void DMA1_vidSetCallBackFunction_TransferError(tdefDMAChannels enuDmaChannelCpy,vidpfvid pfCallBackCpy);
void DMA2_vidSetCallBackFunction_TransferError(tdefDMAChannels enuDmaChannelCpy,vidpfvid pfCallBackCpy);

void DMA1_vidSetCallBackFunction_HalfTransfer(tdefDMAChannels enuDmaChannelCpy,vidpfvid pfCallBackCpy);
void DMA2_vidSetCallBackFunction_HalfTransfer(tdefDMAChannels enuDmaChannelCpy,vidpfvid pfCallBackCpy);

void DMA1_vidSetCallBackFunction_CompleteTransfer(tdefDMAChannels enuDmaChannelCpy,vidpfvid pfCallBackCpy);
void DMA2_vidSetCallBackFunction_CompleteTransfer(tdefDMAChannels enuDmaChannelCpy,vidpfvid pfCallBackCpy);

void DMA1_vidSetNumberOfDataTransfer(tdefDMAChannels enuDmaChannelCpy,u16 u16DataCpy);
void DMA2_vidSetNumberOfDataTransfer(tdefDMAChannels enuDmaChannelCpy,u16 u16DataCpy);

void DMA1_vidSetPeripheralAddress(tdefDMAChannels enuDmaChannelCpy,u32 u32AddressCpy);
void DMA2_vidSetPeripheralAddress(tdefDMAChannels enuDmaChannelCpy,u32 u32AddressCpy);

void DMA1_vidSetMemoryAddress(tdefDMAChannels enuDmaChannelCpy,u32 u32AddressCpy);
void DMA2_vidSetMemoryAddress(tdefDMAChannels enuDmaChannelCpy,u32 u32AddressCpy);


#endif /* DMA_INT_H_ */
