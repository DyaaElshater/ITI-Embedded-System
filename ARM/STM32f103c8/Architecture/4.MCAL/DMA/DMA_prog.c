/********************************************************************/
/** Name 		: Dyaa Elshater										*/
/** Date		: 6/7/2020											*/
/** Description : DMA implementation								*/
/** MCU			: STM32F103C8										*/
/** Version 	: 3.0V												*/
/********************************************************************/

#include "Std_types.h"
#include "Bit_Math.h"
#include "DELAY.h"

#include "DMA_INT.h"
#include "DMA_CFG.h"
#include "DMA_PRIV.h"

void DMA1_vidInit()
{
	u8 loc_u8Iteration;
	for(loc_u8Iteration=0;loc_u8Iteration<DMA1_MAX_CHANNELS;loc_u8Iteration++)
	{
	/*	1. Set the peripheral register address in the DMA_CPARx register. The data will be moved from/ to this address to/ from the memory after the peripheral event.*/
		DMA1_Channels[loc_u8Iteration].CHannelRegisters->DMA_CPAR = DMA1_Channels[loc_u8Iteration].PeripheralAdress;

	/*	2. Set the memory address in the DMA_CMARx register. The data will be written to or read from this memory after the peripheral event. */
		DMA1_Channels[loc_u8Iteration].CHannelRegisters->DMA_CMAR = DMA1_Channels[loc_u8Iteration].MemoryAdress;

	/*	3. Configure the total number of data to be transferred in the DMA_CNDTRx register. After each peripheral event, this value will be decremented.*/
		DMA1_Channels[loc_u8Iteration].CHannelRegisters->DMA_CNDTR = DMA1_Channels[loc_u8Iteration].NumberOfDataTransfer;

	/*	4. Configure the channel priority using the PL[1:0] bits in the DMA_CCRx register*/
		DMA1_Channels[loc_u8Iteration].CHannelRegisters->DMA_CCR = DMA1_Channels[loc_u8Iteration].priority<<PL;

	/*	5. Configure data transfer direction, circular mode, peripheral & memory incremented mode, peripheral & memory data size, and interrupt after half and/or full transfer in the DMA_CCRx register */
		DMA1_Channels[loc_u8Iteration].CHannelRegisters->DMA_CCR |= (DMA1_Channels[loc_u8Iteration].MemoryIncrement<<MINC) | (DMA1_Channels[loc_u8Iteration].MemorySize<<MSIZE) | (DMA1_Channels[loc_u8Iteration].PeripheralIncrement<<PINC)
															     |  (DMA1_Channels[loc_u8Iteration].PeripheralSize<<PSIZE) | (DMA1_Channels[loc_u8Iteration].Direction<<DIR) | (DMA1_Channels[loc_u8Iteration].CircularMode<<CIRC) |(DMA1_Channels[loc_u8Iteration].MwmoryToMemory<<MEM2MEM)
																 |  (DMA1_Channels[loc_u8Iteration].TransferCompleteInterruptEnable<<TCIE) | (DMA1_Channels[loc_u8Iteration].HalfTransferInterruptEnable<<HTIE) | (DMA1_Channels[loc_u8Iteration].TransferErrorInterruptEnable<<TEIE);

	/*	6. Activate the channel by setting the ENABLE bit in the DMA_CCRx register. */
		DMA1_Channels[loc_u8Iteration].CHannelRegisters->DMA_CCR |= DMA1_Channels[loc_u8Iteration].ChannelEnable <<EN ;

	/*Initializing the Callback pointers*/
		DMA1_TCI[loc_u8Iteration]=__DMA_Temp;
		DMA1_HTI[loc_u8Iteration]=__DMA_Temp;
		DMA1_TEI[loc_u8Iteration]=__DMA_Temp;
	}

}

void DMA2_vidInit()
{
	u8 loc_u8Iteration;
	for(loc_u8Iteration=0;loc_u8Iteration<DMA2_MAX_CHANNELS;loc_u8Iteration++)
	{
	/*	1. Set the peripheral register address in the DMA_CPARx register. The data will be moved from/ to this address to/ from the memory after the peripheral event.*/
		DMA2_Channels[loc_u8Iteration].CHannelRegisters->DMA_CPAR = DMA2_Channels[loc_u8Iteration].PeripheralAdress;

	/*	2. Set the memory address in the DMA_CMARx register. The data will be written to or read from this memory after the peripheral event. */
		DMA2_Channels[loc_u8Iteration].CHannelRegisters->DMA_CMAR = DMA2_Channels[loc_u8Iteration].MemoryAdress;

	/*	3. Configure the total number of data to be transferred in the DMA_CNDTRx register. After each peripheral event, this value will be decremented.*/
		DMA2_Channels[loc_u8Iteration].CHannelRegisters->DMA_CNDTR = DMA2_Channels[loc_u8Iteration].NumberOfDataTransfer;

	/*	4. Configure the channel priority using the PL[1:0] bits in the DMA_CCRx register*/
		DMA2_Channels[loc_u8Iteration].CHannelRegisters->DMA_CCR = DMA2_Channels[loc_u8Iteration].priority<<PL;

	/*	5. Configure data transfer direction, circular mode, peripheral & memory incremented mode, peripheral & memory data size, and interrupt after half and/or full transfer in the DMA_CCRx register */
		DMA2_Channels[loc_u8Iteration].CHannelRegisters->DMA_CCR |= (DMA2_Channels[loc_u8Iteration].MemoryIncrement<<MINC) | (DMA2_Channels[loc_u8Iteration].MemorySize<<MSIZE) | (DMA2_Channels[loc_u8Iteration].PeripheralIncrement<<PINC)
															     |  (DMA2_Channels[loc_u8Iteration].PeripheralSize<<PSIZE) | (DMA2_Channels[loc_u8Iteration].Direction<<DIR) | (DMA2_Channels[loc_u8Iteration].CircularMode<<CIRC) |(DMA2_Channels[loc_u8Iteration].MwmoryToMemory<<MEM2MEM)
																 |  (DMA2_Channels[loc_u8Iteration].TransferCompleteInterruptEnable<<TCIE) | (DMA2_Channels[loc_u8Iteration].HalfTransferInterruptEnable<<HTIE) | (DMA2_Channels[loc_u8Iteration].TransferErrorInterruptEnable<<TEIE);

	/*	6. Activate the channel by setting the ENABLE bit in the DMA_CCRx register. */
		DMA2_Channels[loc_u8Iteration].CHannelRegisters->DMA_CCR |= DMA2_Channels[loc_u8Iteration].ChannelEnable <<EN ;

	/*Initializing the Callback pointers*/
		DMA2_TCI[loc_u8Iteration]=__DMA_Temp;
		DMA2_HTI[loc_u8Iteration]=__DMA_Temp;
		DMA2_TEI[loc_u8Iteration]=__DMA_Temp;

	}

}

/** enuDmaChannelCpy -> DMA_Channel_x , x should be from 1 to 7*/
void DMA1_vidEnable_Channel(tdefDMAChannels enuDmaChannelCpy,tdefDmaEn enuDmaEnCpy)
{
	CLEAR_BIT(DMA1_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR,EN);
	DMA1_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR |= enuDmaEnCpy <<EN ;
}

/** enuDmaChannelCpy -> DMA_Channel_x , x should be from 1 to 5*/
void DMA2_vidEnable_Channel(tdefDMAChannels enuDmaChannelCpy,tdefDmaEn enuDmaEnCpy)
{
	CLEAR_BIT(DMA2_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR,EN);
	DMA2_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR |= enuDmaEnCpy <<EN ;
}


u8 DMA1_u8CheckGlobalInterrutFlag(tdefDMAChannels enuDmaChannel)
{
	return GET_BIT(DMA1->ISR,(GIF1+(4*enuDmaChannel)));
}
u8 DMA1_u8CheckTransferCompleteFlag(tdefDMAChannels enuDmaChannel)
{
	return GET_BIT(DMA1->ISR,(TCIF1+(4*enuDmaChannel)));
}
u8 DMA1_u8CheckHalfTransferFlag(tdefDMAChannels enuDmaChannel)
{
	return GET_BIT(DMA1->ISR,(HTIF1+(4*enuDmaChannel)));
}
u8 DMA1_u8CheckTransferErrorFlag(tdefDMAChannels enuDmaChannel)
{
	return GET_BIT(DMA1->ISR,(TEIF1+(4*enuDmaChannel)));
}

u8 DMA2_u8CheckGlobalInterrutFlag(tdefDMAChannels enuDmaChannel)
{
	return GET_BIT(DMA2->ISR,(GIF1+(4*enuDmaChannel)));
}
u8 DMA2_u8CheckTransferCompleteFlag(tdefDMAChannels enuDmaChannel)
{
	return GET_BIT(DMA2->ISR,(TCIF1+(4*enuDmaChannel)));
}
u8 DMA2_u8CheckHalfTransferFlag(tdefDMAChannels enuDmaChannel)
{
	return GET_BIT(DMA2->ISR,(HTIF1+(4*enuDmaChannel)));
}
u8 DMA2_u8CheckTransferErrorFlag(tdefDMAChannels enuDmaChannel)
{
	return GET_BIT(DMA2->ISR,(TEIF1+(4*enuDmaChannel)));
}

void DMA1_vidClearGlobalInterrutFlag(tdefDMAChannels enuDmaChannel)
{
	SET_BIT(DMA1->ISR,(GIF1+(4*enuDmaChannel)));
}
void DMA1_vidClearTransferCompleteFlag(tdefDMAChannels enuDmaChannel)
{
	SET_BIT(DMA1->ISR,(TCIF1+(4*enuDmaChannel)));
}
void DMA1_vidClearHalfTransferFlag(tdefDMAChannels enuDmaChannel)
{
	SET_BIT(DMA1->ISR,(HTIF1+(4*enuDmaChannel)));
}
void DMA1_vidCheckTransferErrorFlag(tdefDMAChannels enuDmaChannel)
{
	SET_BIT(DMA1->ISR,(TEIF1+(4*enuDmaChannel)));
}

void DMA2_vidClearGlobalInterrutFlag(tdefDMAChannels enuDmaChannel)
{
	SET_BIT(DMA2->ISR,(GIF1+(4*enuDmaChannel)));
}
void DMA2_vidClearTransferCompleteFlag(tdefDMAChannels enuDmaChannel)
{
	SET_BIT(DMA2->ISR,(TCIF1+(4*enuDmaChannel)));
}
void DMA2_vidClearHalfTransferFlag(tdefDMAChannels enuDmaChannel)
{
	SET_BIT(DMA2->ISR,(HTIF1+(4*enuDmaChannel)));
}
void DMA2_vidClearTransferErrorFlag(tdefDMAChannels enuDmaChannel)
{
	SET_BIT(DMA2->ISR,(TEIF1+(4*enuDmaChannel)));
}

void DMA1_vidEnableMemoryToMemoryMode(tdefDMAChannels enuDmaChannelCpy,tdefDmaEn enuDmaEnCpy)
{
	CLEAR_BIT(DMA1_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR,MEM2MEM);
	DMA1_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR |= enuDmaEnCpy<<MEM2MEM ;
}
void DMA2_vidEnableMemoryToMemoryMode(tdefDMAChannels enuDmaChannelCpy,tdefDmaEn enuDmaEnCpy)
{
	CLEAR_BIT(DMA2_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR,MEM2MEM);
	DMA2_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR |= enuDmaEnCpy<<MEM2MEM ;
}

void DMA1_vidSetChannelpriority(tdefDMAChannels enuDmaChannelCpy, tdefDmapriority enuDmapriority)
{
	CLEAR_BIT(DMA1_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR,PL);
	DMA1_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR |= enuDmapriority<<PL ;
}
void DMA2_vidSetChannelpriority(tdefDMAChannels enuDmaChannelCpy, tdefDmapriority enuDmapriority)
{
	CLEAR_BIT(DMA2_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR,PL);
	DMA2_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR |= enuDmapriority<<PL ;
}

void DMA1_vidSetMemorySize(tdefDMAChannels enuDmaChannelCpy,tdefDMADataSize enuMSizeCpy)
{
	CLEAR_BIT(DMA1_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR,MSIZE);
	DMA1_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR |= enuMSizeCpy<<MSIZE ;
}
void DMA1_vidSetPeripheralSize(tdefDMAChannels enuDmaChannelCpy,tdefDMADataSize enuPSizeCpy)
{
	CLEAR_BIT(DMA2_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR,PSIZE);
	DMA2_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR |= enuPSizeCpy<<PSIZE ;
}

void DMA2_vidSetMemorySize(tdefDMAChannels enuDmaChannelCpy,tdefDMADataSize enuMSizeCpy)
{
	CLEAR_BIT(DMA2_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR,PSIZE);
	DMA2_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR |= enuMSizeCpy<<PSIZE ;
}
void DMA2_vidSetPeripheralSize(tdefDMAChannels enuDmaChannelCpy,tdefDMADataSize enuPSizeCpy)
{
	CLEAR_BIT(DMA2_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR,PSIZE);
	DMA2_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR |= enuPSizeCpy<<PSIZE ;
}

void DMA1_vidSetMemoryIncrementMode(tdefDMAChannels enuDmaChannelCpy,tdefDmaEn enuDmaEnCpy)
{
	CLEAR_BIT(DMA1_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR,MINC);
	DMA1_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR |= enuDmaEnCpy<<MINC ;
}
void DMA1_vidSetPeripheralIncrementMode(tdefDMAChannels enuDmaChannelCpy,tdefDmaEn enuDmaEnCpy)
{
	CLEAR_BIT(DMA1_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR,PINC);
	DMA1_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR |= enuDmaEnCpy<<PINC ;
}
void DMA2_vidSetMemoryIncrementMode(tdefDMAChannels enuDmaChannelCpy,tdefDmaEn enuDmaEnCpy)
{
	CLEAR_BIT(DMA2_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR,MINC);
	DMA2_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR |= enuDmaEnCpy<<MINC ;
}
void DMA2_vidSetPeripheralIncrementMode(tdefDMAChannels enuDmaChannelCpy,tdefDmaEn enuDmaEnCpy)
{
	CLEAR_BIT(DMA2_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR,PINC);
	DMA2_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR |= enuDmaEnCpy<<PINC ;
}

void DMA1_vidSetCircularMode(tdefDMAChannels enuDmaChannelCpy,tdefDmaEn enuDmaEnCpy)
{
	CLEAR_BIT(DMA1_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR,CIRC);
	DMA1_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR |= enuDmaEnCpy<<CIRC ;
}
void DMA2_vidSetCircularMode(tdefDMAChannels enuDmaChannelCpy,tdefDmaEn enuDmaEnCpy)
{
	CLEAR_BIT(DMA2_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR,CIRC);
	DMA2_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR |= enuDmaEnCpy<<CIRC ;
}

void DMA1_vidSetDataTransferDirection(tdefDMAChannels enuDmaChannelCpy,tdefDmaDirection enuDIRCpy)
{
	CLEAR_BIT(DMA1_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR,DIR);
	DMA1_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR |= enuDIRCpy<<DIR ;
}
void DMA2_vidSetDataTransferDirection(tdefDMAChannels enuDmaChannelCpy,tdefDmaDirection enuDIRCpy)
{
	CLEAR_BIT(DMA2_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR,DIR);
	DMA2_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR |= enuDIRCpy<<DIR ;
}

void DMA1_vidEnableTransferErrorInterrupt(tdefDMAChannels enuDmaChannelCpy,tdefDmaEn enuDmaEnCpy)
{
	CLEAR_BIT(DMA1_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR,TEIE);
	DMA1_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR |= enuDmaEnCpy<<TEIE ;
}
void DMA2_vidEnableTransferErrorInterrupt(tdefDMAChannels enuDmaChannelCpy,tdefDmaEn enuDmaEnCpy)
{
	CLEAR_BIT(DMA2_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR,TEIE);
	DMA2_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR |= enuDmaEnCpy<<TEIE ;
}

void DMA1_vidEnableHallfTransferInterrupt(tdefDMAChannels enuDmaChannelCpy,tdefDmaEn enuDmaEnCpy)
{
	CLEAR_BIT(DMA1_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR,HTIE);
	DMA1_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR |= enuDmaEnCpy<<HTIE ;
}
void DMA2_vidEnableHallfTransferInterrupt(tdefDMAChannels enuDmaChannelCpy,tdefDmaEn enuDmaEnCpy)
{
	CLEAR_BIT(DMA2_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR,HTIE);
	DMA2_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR |= enuDmaEnCpy<<HTIE ;
}

void DMA1_vidEnableTransferCompleteInterrupt(tdefDMAChannels enuDmaChannelCpy,tdefDmaEn enuDmaEnCpy)
{
	CLEAR_BIT(DMA1_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR,TCIE);
	DMA1_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR |= enuDmaEnCpy<<TCIE ;
}
void DMA2_vidEnableTransferCompleteInterrupt(tdefDMAChannels enuDmaChannelCpy,tdefDmaEn enuDmaEnCpy)
{
	CLEAR_BIT(DMA2_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR,TCIE);
	DMA2_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CCR |= enuDmaEnCpy<<TCIE ;
}


void DMA1_vidSetCallBackFunction_TransferError(tdefDMAChannels enuDmaChannelCpy,vidpfvid pfCallBackCpy)
{
	DMA1_TEI[enuDmaChannelCpy]=pfCallBackCpy;
}
void DMA2_vidSetCallBackFunction_TransferError(tdefDMAChannels enuDmaChannelCpy,vidpfvid pfCallBackCpy)
{
	DMA2_TEI[enuDmaChannelCpy]=pfCallBackCpy;
}

void DMA1_vidSetCallBackFunction_HalfTransfer(tdefDMAChannels enuDmaChannelCpy,vidpfvid pfCallBackCpy)
{
	DMA1_HTI[enuDmaChannelCpy]=pfCallBackCpy;
}
void DMA2_vidSetCallBackFunction_HalfTransfer(tdefDMAChannels enuDmaChannelCpy,vidpfvid pfCallBackCpy)
{
	DMA2_HTI[enuDmaChannelCpy]=pfCallBackCpy;
}

void DMA1_vidSetCallBackFunction_CompleteTransfer(tdefDMAChannels enuDmaChannelCpy,vidpfvid pfCallBackCpy)
{
	DMA1_TCI[enuDmaChannelCpy]=pfCallBackCpy;
}
void DMA2_vidSetCallBackFunction_CompleteTransfer(tdefDMAChannels enuDmaChannelCpy,vidpfvid pfCallBackCpy)
{
	DMA2_TCI[enuDmaChannelCpy]=pfCallBackCpy;
}

void DMA1_vidSetNumberOfDataTransfer(tdefDMAChannels enuDmaChannelCpy,u16 u16DataCpy)
{
	DMA1_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CNDTR = u16DataCpy;
}
void DMA2_vidSetNumberOfDataTransfer(tdefDMAChannels enuDmaChannelCpy,u16 u16DataCpy)
{
	DMA2_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CNDTR = u16DataCpy ;
}


void DMA1_vidSetPeripheralAddress(tdefDMAChannels enuDmaChannelCpy,u32 u32AddressCpy)
{
	DMA1_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CPAR= u32AddressCpy ;
}
void DMA2_vidSetPeripheralAddress(tdefDMAChannels enuDmaChannelCpy,u32 u32AddressCpy)
{
	DMA2_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CPAR= u32AddressCpy ;
}

void DMA1_vidSetMemoryAddress(tdefDMAChannels enuDmaChannelCpy,u32 u32AddressCpy)
{
	DMA1_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CMAR= u32AddressCpy ;
}
void DMA2_vidSetMemoryAddress(tdefDMAChannels enuDmaChannelCpy,u32 u32AddressCpy)
{
	DMA2_Channels[enuDmaChannelCpy].CHannelRegisters->DMA_CMAR= u32AddressCpy ;
}

/*	Interrupt ISR	*/

void DMA1_Channel1_IRQHandler(void)
{
	if(DMA1->ISR & (DMA_MASK_TCIF_BIT<<GIF1))
	{
		/*Clearing the status bit*/
		SET_BIT(DMA1->IFCR,CTCIF1);
		DMA1_TCI[0]();
	}
	else if(DMA1->ISR & (DMA_MASK_HTIF_BIT<<GIF1))
	{
		/*Clearing the status bit*/
		SET_BIT(DMA1->IFCR,CHTIF1);
		DMA1_HTI[0]();
	}
	else
	{
		/*Clearing the status bit*/
		SET_BIT(DMA1->IFCR,CTEIF1);
		DMA1_TEI[0]();
	}
}
void DMA1_Channel2_IRQHandler(void)
{
	if(DMA1->ISR & (DMA_MASK_TCIF_BIT<<GIF2))
	{
		/*Clearing the status bit*/
		SET_BIT(DMA1->IFCR,CTCIF2);
		DMA1_TCI[1]();
	}
	else if(DMA1->ISR & (DMA_MASK_HTIF_BIT<<GIF2))
	{
		/*Clearing the status bit*/
		SET_BIT(DMA1->IFCR,CHTIF2);
		DMA1_HTI[1]();
	}
	else
	{
		/*Clearing the status bit*/
		SET_BIT(DMA1->IFCR,CTEIF2);
		DMA1_TEI[1]();
	}
}
void DMA1_Channel3_IRQHandler(void)
{
	if(DMA1->ISR & (DMA_MASK_TCIF_BIT<<GIF3))
	{
		/*Clearing the status bit*/
		SET_BIT(DMA1->IFCR,CTCIF3);
		DMA1_TCI[2]();
	}
	else if(DMA1->ISR & (DMA_MASK_HTIF_BIT<<GIF3))
	{
		/*Clearing the status bit*/
		SET_BIT(DMA1->IFCR,CHTIF3);
		DMA1_HTI[2]();
	}
	else
	{
		/*Clearing the status bit*/
		SET_BIT(DMA1->IFCR,CTEIF3);
		DMA1_TEI[2]();
	}
}
void DMA1_Channel4_IRQHandler(void)
{
	if(DMA1->ISR & (DMA_MASK_TCIF_BIT<<GIF4))
	{
		/*Clearing the status bit*/
		SET_BIT(DMA1->IFCR,CTCIF4);
		DMA1_TCI[3]();
	}
	else if(DMA1->ISR & (DMA_MASK_HTIF_BIT<<GIF4))
	{
		/*Clearing the status bit*/
		SET_BIT(DMA1->IFCR,CHTIF4);
		DMA1_HTI[3]();
	}
	else
	{
		/*Clearing the status bit*/
		SET_BIT(DMA1->IFCR,CTEIF4);
		DMA1_TEI[3]();
	}
}
void DMA1_Channel5_IRQHandler(void)
{
	if(DMA1->ISR & (DMA_MASK_TCIF_BIT<<GIF5))
	{
		/*Clearing the status bit*/
		SET_BIT(DMA1->IFCR,CTCIF5);
		DMA1_TCI[4]();
	}
	else if(DMA1->ISR & (DMA_MASK_HTIF_BIT<<GIF5))
	{
		/*Clearing the status bit*/
		SET_BIT(DMA1->IFCR,CHTIF5);
		DMA1_HTI[4]();
	}
	else
	{
		/*Clearing the status bit*/
		SET_BIT(DMA1->IFCR,CTEIF5);
		DMA1_TEI[4]();
	}
}
void DMA1_Channel6_IRQHandler(void)
{
	if(DMA1->ISR & (DMA_MASK_TCIF_BIT<<GIF6))
	{
		/*Clearing the status bit*/
		SET_BIT(DMA1->IFCR,CTCIF6);
		DMA1_TCI[5]();
	}
	else if(DMA1->ISR & (DMA_MASK_HTIF_BIT<<GIF6))
	{
		/*Clearing the status bit*/
		SET_BIT(DMA1->IFCR,CHTIF6);
		DMA1_HTI[5]();
	}
	else
	{
		/*Clearing the status bit*/
		SET_BIT(DMA1->IFCR,CTEIF6);
		DMA1_TEI[5]();
	}
}
void DMA1_Channel7_IRQHandler(void)
{
	if(DMA1->ISR & (DMA_MASK_TCIF_BIT<<GIF7))
	{
		/*Clearing the status bit*/
		SET_BIT(DMA1->IFCR,CTCIF7);
		DMA1_TCI[6]();
	}
	else if(DMA1->ISR & (DMA_MASK_HTIF_BIT<<GIF7))
	{
		/*Clearing the status bit*/
		SET_BIT(DMA1->IFCR,CHTIF7);
		DMA1_HTI[6]();
	}
	else
	{
		/*Clearing the status bit*/
		SET_BIT(DMA1->IFCR,CTEIF7);
		DMA1_TEI[6]();
	}
}
void DMA2_Channel1_IRQHandler(void)
{
	if(DMA2->ISR & (DMA_MASK_TCIF_BIT<<GIF1))
	{
		/*Clearing the status bit*/
		SET_BIT(DMA2->IFCR,CTCIF1);
		DMA2_TCI[0]();
	}
	else if(DMA2->ISR & (DMA_MASK_HTIF_BIT<<GIF1))
	{
		/*Clearing the status bit*/
		SET_BIT(DMA2->IFCR,CHTIF1);
		DMA2_HTI[0]();
	}
	else
	{
		/*Clearing the status bit*/
		SET_BIT(DMA2->IFCR,CTEIF1);
		DMA2_TEI[0]();
	}
}
void DMA2_Channel2_IRQHandler(void)
{
	if(DMA2->ISR & (DMA_MASK_TCIF_BIT<<GIF2))
	{
		/*Clearing the status bit*/
		SET_BIT(DMA2->IFCR,CTCIF2);
		DMA2_TCI[1]();
	}
	else if(DMA2->ISR & (DMA_MASK_HTIF_BIT<<GIF2))
	{
		/*Clearing the status bit*/
		SET_BIT(DMA2->IFCR,CHTIF2);
		DMA2_HTI[1]();
	}
	else
	{
		/*Clearing the status bit*/
		SET_BIT(DMA2->IFCR,CTEIF2);
		DMA2_TEI[1]();
	}
}
void DMA2_Channel3_IRQHandler(void)
{
	if(DMA2->ISR & (DMA_MASK_TCIF_BIT<<GIF3))
	{
		/*Clearing the status bit*/
		SET_BIT(DMA2->IFCR,CTCIF3);
		DMA2_TCI[2]();
	}
	else if(DMA2->ISR & (DMA_MASK_HTIF_BIT<<GIF3))
	{
		/*Clearing the status bit*/
		SET_BIT(DMA2->IFCR,CHTIF3);
		DMA2_HTI[2]();
	}
	else
	{
		/*Clearing the status bit*/
		SET_BIT(DMA2->IFCR,CTEIF3);
		DMA2_TEI[2]();
	}
}
void DMA2_Channel4_5_IRQHandler(void)
{
	if (DMA2->ISR & (DMA_MASK_GIF_BIT<<GIF4))
	{
			/*DMA2_Channel 4*/
		if(DMA2->ISR & (DMA_MASK_TCIF_BIT<<GIF4))
		{
			/*Clearing the status bit*/
			SET_BIT(DMA2->IFCR,CTCIF4);
			DMA2_TCI[3]();
		}
		else if(DMA2->ISR & (DMA_MASK_HTIF_BIT<<GIF4))
		{
			/*Clearing the status bit*/
			SET_BIT(DMA2->IFCR,CHTIF4);
			DMA2_HTI[3]();
		}
		else
		{
			/*Clearing the status bit*/
			SET_BIT(DMA2->IFCR,CTEIF4);
			DMA2_TEI[3]();
		}
	}
	else
	{
			/*DMA2_Channel 5*/
		if(DMA2->ISR & (DMA_MASK_TCIF_BIT<<GIF5))
		{
			/*Clearing the status bit*/
			SET_BIT(DMA2->IFCR,CTCIF5);
			DMA2_TCI[4]();
		}
		else if(DMA2->ISR & (DMA_MASK_HTIF_BIT<<GIF5))
		{
			/*Clearing the status bit*/
			SET_BIT(DMA2->IFCR,CHTIF5);
			DMA2_HTI[4]();
		}
		else
		{
			/*Clearing the status bit*/
			SET_BIT(DMA2->IFCR,CTEIF5);
			DMA2_TEI[4]();
		}
	}
}
