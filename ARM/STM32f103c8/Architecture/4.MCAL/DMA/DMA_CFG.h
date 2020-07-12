/********************************************************************/
/** Name 		: Dyaa Elshater										*/
/** Date		: 6/7/2020											*/
/** Description	: DMA configuration file							*/
/** MCU			: STM32F103C8										*/
/** Version 	: 1.0V												*/
/********************************************************************/

#ifndef DMA_CFG_H_
#define DMA_CFG_H_

/** configure the DMA Channels										*/

/*
 * {
 *  Assign the peripheral address	,
 * 	Assign the Memory address		,
 * 	Configure the number of data transfer	,
 *	Configure the priority of the Channel
 *										-	DMA_LowPriority
 *										-	DMA_MediumPriority
 *										-	DMA_HighPriority
 *										-	DMA_VeryHighPriority	,
 *	Configure the Channel direction
 *										-	DMA_ReadFromPeripheral
 *										-	DMA_ReadFromMemory * 	,
 *	Configure the Circlar Mode
 *										-	DMA_DISABLE
 *										-	DMA_ENABLE			,
 *	Configure Peripheral increment mode
 *										-	DMA_DISABLE
 *										-	DMA_ENABLE			,
 *	Configure Memory increment mode
 *										-	DMA_DISABLE
 *										-	DMA_ENABLE			,
 *	Configure the memory transfer size
 *											DMA_8_bits
 *											DMA_16_bits
 *											DMA_32_bits
 *											DMA_8_bits			,
 *	Configure the Peripheral transfer size
 *											DMA_8_bits
 *											DMA_16_bits
 *											DMA_32_bits
 *											DMA_8_bits			,
 *	Configure Memory to Memory
 *										-	DMA_DISABLE
 *										-	DMA_ENABLE			,
 *	Configure Interrupt enable
 *										-	DMA_DISABLE
 *										-	DMA_ENABLE			,
 ****************** Interrupt in Complete transfer		,
 ****************** Interrupt in Half transfer			,
 ****************** Interrupt when error in transfer	,
 *	Configure the Channel enable
 *										-	DMA_DISABLE
 *										-	DMA_ENABLE
 *
 */


tdefDmaChannel DMA1_Channels[7]=
{
	/*************** DMA 1 Channel 1 **********************/
	{
				( tdefChannelRegisters*)DMA1_BASE_ADDRESS+DMA_CH1_CCR_OFFSET	,
				0,					/** Assign the peripheral address 	*/
				0,					/** Assign the Memory address 		*/
				0,					/** Configure the number of data transfer */
				DMA_LowPriority	,	/** Configure the priority of the Channel */ /** DMA_LowPriority , DMA_MediumPriority , DMA_HighPriority , DMA_VeryHighPriority  **/
				DMA_ReadFromPeripheral	,  /** Configure the Channel direction	*/ /** DMA_ReadFromPeripheral ,  DMA_ReadFromMemory **/
				DMA_DISABLE,		/** Configure the Circlar Mode */ /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE,		/** Configure Peripheral increment mode	*/ /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE,		/** Configure Memory increment mode	*/ /** DMA_DISABLE , DMA_ENABLE **/
				DMA_8_bits,			/** Configure the memory transfer size */ /** DMA_8_bits , DMA_16_bits , DMA_32_bits **/
				DMA_8_bits,			/** Configure the Peripheral transfer size */ /** DMA_8_bits , DMA_16_bits , DMA_32_bits **/
				DMA_DISABLE,		/**	Configure Memory to Memory	*/	/** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE ,		/** Interrupt in Complete transfer */  /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE ,		/** Interrupt in Complete transfer */  /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE ,		/** Interrupt when error in transfer */  /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE			/** Configure the Channel enable */ /** DMA_DISABLE , DMA_ENABLE **/
	}	,
	/*************** DMA 1 Channel 2 **********************/
	{
				( tdefChannelRegisters*)DMA1_BASE_ADDRESS+DMA_CH2_CCR_OFFSET	,
				0,					/** Assign the peripheral address 	*/
				0,					/** Assign the Memory address 		*/
				0,					/** Configure the number of data transfer */
				DMA_LowPriority	,	/** Configure the priority of the Channel */ /** DMA_LowPriority , DMA_MediumPriority , DMA_HighPriority , DMA_VeryHighPriority  **/
				DMA_ReadFromPeripheral	,  /** Configure the Channel direction	*/ /** DMA_ReadFromPeripheral ,  DMA_ReadFromMemory **/
				DMA_DISABLE,		/** Configure the Circlar Mode */ /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE,		/** Configure Peripheral increment mode	*/ /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE,		/** Configure Memory increment mode	*/ /** DMA_DISABLE , DMA_ENABLE **/
				DMA_8_bits,			/** Configure the memory transfer size */ /** DMA_8_bits , DMA_16_bits , DMA_32_bits **/
				DMA_8_bits,			/** Configure the Peripheral transfer size */ /** DMA_8_bits , DMA_16_bits , DMA_32_bits **/
				DMA_DISABLE,		/**	Configure Memory to Memory	*/	/** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE ,		/** Interrupt in Complete transfer */  /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE ,		/** Interrupt in Complete transfer */  /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE ,		/** Interrupt when error in transfer */  /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE			/** Configure the Channel enable */ /** DMA_DISABLE , DMA_ENABLE **/
	}	,
	/*************** DMA 1 Channel 3 **********************/
	{
				( tdefChannelRegisters*)DMA1_BASE_ADDRESS+DMA_CH3_CCR_OFFSET	,
				0,					/** Assign the peripheral address 	*/
				0,					/** Assign the Memory address 		*/
				0,					/** Configure the number of data transfer */
				DMA_LowPriority	,	/** Configure the priority of the Channel */ /** DMA_LowPriority , DMA_MediumPriority , DMA_HighPriority , DMA_VeryHighPriority  **/
				DMA_ReadFromPeripheral	,  /** Configure the Channel direction	*/ /** DMA_ReadFromPeripheral ,  DMA_ReadFromMemory **/
				DMA_DISABLE,		/** Configure the Circlar Mode */ /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE,		/** Configure Peripheral increment mode	*/ /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE,		/** Configure Memory increment mode	*/ /** DMA_DISABLE , DMA_ENABLE **/
				DMA_8_bits,			/** Configure the memory transfer size */ /** DMA_8_bits , DMA_16_bits , DMA_32_bits **/
				DMA_8_bits,			/** Configure the Peripheral transfer size */ /** DMA_8_bits , DMA_16_bits , DMA_32_bits **/
				DMA_DISABLE,		/**	Configure Memory to Memory	*/	/** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE ,		/** Interrupt in Complete transfer */  /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE ,		/** Interrupt in Complete transfer */  /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE ,		/** Interrupt when error in transfer */  /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE			/** Configure the Channel enable */ /** DMA_DISABLE , DMA_ENABLE **/
	}	,
	/*************** DMA 1 Channel 4 **********************/
	{
				( tdefChannelRegisters*)DMA1_BASE_ADDRESS+DMA_CH4_CCR_OFFSET	,
				0,					/** Assign the peripheral address 	*/
				0,					/** Assign the Memory address 		*/
				0,					/** Configure the number of data transfer */
				DMA_LowPriority	,	/** Configure the priority of the Channel */ /** DMA_LowPriority , DMA_MediumPriority , DMA_HighPriority , DMA_VeryHighPriority  **/
				DMA_ReadFromPeripheral	,  /** Configure the Channel direction	*/ /** DMA_ReadFromPeripheral ,  DMA_ReadFromMemory **/
				DMA_DISABLE,		/** Configure the Circlar Mode */ /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE,		/** Configure Peripheral increment mode	*/ /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE,		/** Configure Memory increment mode	*/ /** DMA_DISABLE , DMA_ENABLE **/
				DMA_8_bits,			/** Configure the memory transfer size */ /** DMA_8_bits , DMA_16_bits , DMA_32_bits **/
				DMA_8_bits,			/** Configure the Peripheral transfer size */ /** DMA_8_bits , DMA_16_bits , DMA_32_bits **/
				DMA_DISABLE,		/**	Configure Memory to Memory	*/	/** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE ,		/** Interrupt in Complete transfer */  /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE ,		/** Interrupt in Complete transfer */  /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE ,		/** Interrupt when error in transfer */  /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE			/** Configure the Channel enable */ /** DMA_DISABLE , DMA_ENABLE **/
	}	,
	/*************** DMA 1 Channel 5 **********************/
	{
				( tdefChannelRegisters*)DMA1_BASE_ADDRESS+DMA_CH5_CCR_OFFSET	,
				0,					/** Assign the peripheral address 	*/
				0,					/** Assign the Memory address 		*/
				0,					/** Configure the number of data transfer */
				DMA_LowPriority	,	/** Configure the priority of the Channel */ /** DMA_LowPriority , DMA_MediumPriority , DMA_HighPriority , DMA_VeryHighPriority  **/
				DMA_ReadFromPeripheral	,  /** Configure the Channel direction	*/ /** DMA_ReadFromPeripheral ,  DMA_ReadFromMemory **/
				DMA_DISABLE,		/** Configure the Circlar Mode */ /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE,		/** Configure Peripheral increment mode	*/ /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE,		/** Configure Memory increment mode	*/ /** DMA_DISABLE , DMA_ENABLE **/
				DMA_8_bits,			/** Configure the memory transfer size */ /** DMA_8_bits , DMA_16_bits , DMA_32_bits **/
				DMA_8_bits,			/** Configure the Peripheral transfer size */ /** DMA_8_bits , DMA_16_bits , DMA_32_bits **/
				DMA_DISABLE,		/**	Configure Memory to Memory	*/	/** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE ,		/** Interrupt in Complete transfer */  /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE ,		/** Interrupt in Complete transfer */  /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE ,		/** Interrupt when error in transfer */  /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE			/** Configure the Channel enable */ /** DMA_DISABLE , DMA_ENABLE **/
	}	,
	/*************** DMA 1 Channel 6 **********************/
	{
				( tdefChannelRegisters*)DMA1_BASE_ADDRESS+DMA_CH6_CCR_OFFSET	,
				0,					/** Assign the peripheral address 	*/
				0,					/** Assign the Memory address 		*/
				0,					/** Configure the number of data transfer */
				DMA_LowPriority	,	/** Configure the priority of the Channel */ /** DMA_LowPriority , DMA_MediumPriority , DMA_HighPriority , DMA_VeryHighPriority  **/
				DMA_ReadFromPeripheral	,  /** Configure the Channel direction	*/ /** DMA_ReadFromPeripheral ,  DMA_ReadFromMemory **/
				DMA_DISABLE,		/** Configure the Circlar Mode */ /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE,		/** Configure Peripheral increment mode	*/ /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE,		/** Configure Memory increment mode	*/ /** DMA_DISABLE , DMA_ENABLE **/
				DMA_8_bits,			/** Configure the memory transfer size */ /** DMA_8_bits , DMA_16_bits , DMA_32_bits **/
				DMA_8_bits,			/** Configure the Peripheral transfer size */ /** DMA_8_bits , DMA_16_bits , DMA_32_bits **/
				DMA_DISABLE,		/**	Configure Memory to Memory	*/	/** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE ,		/** Interrupt in Complete transfer */  /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE ,		/** Interrupt in Complete transfer */  /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE ,		/** Interrupt when error in transfer */  /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE			/** Configure the Channel enable */ /** DMA_DISABLE , DMA_ENABLE **/
	}	,
	/*************** DMA 1 Channel 7 **********************/
	{
				( tdefChannelRegisters*)DMA1_BASE_ADDRESS+DMA_CH7_CCR_OFFSET	,
				0,					/** Assign the peripheral address 	*/
				0,					/** Assign the Memory address 		*/
				0,					/** Configure the number of data transfer */
				DMA_LowPriority	,	/** Configure the priority of the Channel */ /** DMA_LowPriority , DMA_MediumPriority , DMA_HighPriority , DMA_VeryHighPriority  **/
				DMA_ReadFromPeripheral	,  /** Configure the Channel direction	*/ /** DMA_ReadFromPeripheral ,  DMA_ReadFromMemory **/
				DMA_DISABLE,		/** Configure the Circlar Mode */ /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE,		/** Configure Peripheral increment mode	*/ /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE,		/** Configure Memory increment mode	*/ /** DMA_DISABLE , DMA_ENABLE **/
				DMA_8_bits,			/** Configure the memory transfer size */ /** DMA_8_bits , DMA_16_bits , DMA_32_bits **/
				DMA_8_bits,			/** Configure the Peripheral transfer size */ /** DMA_8_bits , DMA_16_bits , DMA_32_bits **/
				DMA_DISABLE,		/**	Configure Memory to Memory	*/	/** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE ,		/** Interrupt in Complete transfer */  /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE ,		/** Interrupt in Complete transfer */  /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE ,		/** Interrupt when error in transfer */  /** DMA_DISABLE , DMA_ENABLE **/
				DMA_DISABLE			/** Configure the Channel enable */ /** DMA_DISABLE , DMA_ENABLE **/
	}

};

/** Configure DMA2													*/
tdefDmaChannel DMA2_Channels[5]=
{
		/*************** DMA 2 Channel 1 **********************/
		{
					( tdefChannelRegisters*)DMA2_BASE_ADDRESS+DMA_CH1_CCR_OFFSET	,
					0,					/** Assign the peripheral address 	*/
					0,					/** Assign the Memory address 		*/
					0,					/** Configure the number of data transfer */
					DMA_LowPriority	,	/** Configure the priority of the Channel */ /** DMA_LowPriority , DMA_MediumPriority , DMA_HighPriority , DMA_VeryHighPriority  **/
					DMA_ReadFromPeripheral	,  /** Configure the Channel direction	*/ /** DMA_ReadFromPeripheral ,  DMA_ReadFromMemory **/
					DMA_DISABLE,		/** Configure the Circlar Mode */ /** DMA_DISABLE , DMA_ENABLE **/
					DMA_DISABLE,		/** Configure Peripheral increment mode	*/ /** DMA_DISABLE , DMA_ENABLE **/
					DMA_DISABLE,		/** Configure Memory increment mode	*/ /** DMA_DISABLE , DMA_ENABLE **/
					DMA_8_bits,			/** Configure the memory transfer size */ /** DMA_8_bits , DMA_16_bits , DMA_32_bits **/
					DMA_8_bits,			/** Configure the Peripheral transfer size */ /** DMA_8_bits , DMA_16_bits , DMA_32_bits **/
					DMA_DISABLE,		/**	Configure Memory to Memory	*/	/** DMA_DISABLE , DMA_ENABLE **/
					DMA_DISABLE ,		/** Interrupt in Complete transfer */  /** DMA_DISABLE , DMA_ENABLE **/
					DMA_DISABLE ,		/** Interrupt in Complete transfer */  /** DMA_DISABLE , DMA_ENABLE **/
					DMA_DISABLE ,		/** Interrupt when error in transfer */  /** DMA_DISABLE , DMA_ENABLE **/
					DMA_DISABLE			/** Configure the Channel enable */ /** DMA_DISABLE , DMA_ENABLE **/
		}	,
		/*************** DMA 2 Channel 2 **********************/
		{
					( tdefChannelRegisters*)DMA2_BASE_ADDRESS+DMA_CH2_CCR_OFFSET	,
					0,					/** Assign the peripheral address 	*/
					0,					/** Assign the Memory address 		*/
					0,					/** Configure the number of data transfer */
					DMA_LowPriority	,	/** Configure the priority of the Channel */ /** DMA_LowPriority , DMA_MediumPriority , DMA_HighPriority , DMA_VeryHighPriority  **/
					DMA_ReadFromPeripheral	,  /** Configure the Channel direction	*/ /** DMA_ReadFromPeripheral ,  DMA_ReadFromMemory **/
					DMA_DISABLE,		/** Configure the Circlar Mode */ /** DMA_DISABLE , DMA_ENABLE **/
					DMA_DISABLE,		/** Configure Peripheral increment mode	*/ /** DMA_DISABLE , DMA_ENABLE **/
					DMA_DISABLE,		/** Configure Memory increment mode	*/ /** DMA_DISABLE , DMA_ENABLE **/
					DMA_8_bits,			/** Configure the memory transfer size */ /** DMA_8_bits , DMA_16_bits , DMA_32_bits **/
					DMA_8_bits,			/** Configure the Peripheral transfer size */ /** DMA_8_bits , DMA_16_bits , DMA_32_bits **/
					DMA_DISABLE,		/**	Configure Memory to Memory	*/	/** DMA_DISABLE , DMA_ENABLE **/
					DMA_DISABLE ,		/** Interrupt in Complete transfer */  /** DMA_DISABLE , DMA_ENABLE **/
					DMA_DISABLE ,		/** Interrupt in Complete transfer */  /** DMA_DISABLE , DMA_ENABLE **/
					DMA_DISABLE ,		/** Interrupt when error in transfer */  /** DMA_DISABLE , DMA_ENABLE **/
					DMA_DISABLE			/** Configure the Channel enable */ /** DMA_DISABLE , DMA_ENABLE **/
		}	,
		/*************** DMA 2 Channel 3 **********************/
		{
					( tdefChannelRegisters*)DMA2_BASE_ADDRESS+DMA_CH3_CCR_OFFSET	,
					0,					/** Assign the peripheral address 	*/
					0,					/** Assign the Memory address 		*/
					0,					/** Configure the number of data transfer */
					DMA_LowPriority	,	/** Configure the priority of the Channel */ /** DMA_LowPriority , DMA_MediumPriority , DMA_HighPriority , DMA_VeryHighPriority  **/
					DMA_ReadFromPeripheral	,  /** Configure the Channel direction	*/ /** DMA_ReadFromPeripheral ,  DMA_ReadFromMemory **/
					DMA_DISABLE,		/** Configure the Circlar Mode */ /** DMA_DISABLE , DMA_ENABLE **/
					DMA_DISABLE,		/** Configure Peripheral increment mode	*/ /** DMA_DISABLE , DMA_ENABLE **/
					DMA_DISABLE,		/** Configure Memory increment mode	*/ /** DMA_DISABLE , DMA_ENABLE **/
					DMA_8_bits,			/** Configure the memory transfer size */ /** DMA_8_bits , DMA_16_bits , DMA_32_bits **/
					DMA_8_bits,			/** Configure the Peripheral transfer size */ /** DMA_8_bits , DMA_16_bits , DMA_32_bits **/
					DMA_DISABLE,		/**	Configure Memory to Memory	*/	/** DMA_DISABLE , DMA_ENABLE **/
					DMA_DISABLE ,		/** Interrupt in Complete transfer */  /** DMA_DISABLE , DMA_ENABLE **/
					DMA_DISABLE ,		/** Interrupt in Complete transfer */  /** DMA_DISABLE , DMA_ENABLE **/
					DMA_DISABLE ,		/** Interrupt when error in transfer */  /** DMA_DISABLE , DMA_ENABLE **/
					DMA_DISABLE			/** Configure the Channel enable */ /** DMA_DISABLE , DMA_ENABLE **/
		}	,
		/*************** DMA 2 Channel 4 **********************/
		{
					( tdefChannelRegisters*)DMA2_BASE_ADDRESS+DMA_CH4_CCR_OFFSET	,
					0,					/** Assign the peripheral address 	*/
					0,					/** Assign the Memory address 		*/
					0,					/** Configure the number of data transfer */
					DMA_LowPriority	,	/** Configure the priority of the Channel */ /** DMA_LowPriority , DMA_MediumPriority , DMA_HighPriority , DMA_VeryHighPriority  **/
					DMA_ReadFromPeripheral	,  /** Configure the Channel direction	*/ /** DMA_ReadFromPeripheral ,  DMA_ReadFromMemory **/
					DMA_DISABLE,		/** Configure the Circlar Mode */ /** DMA_DISABLE , DMA_ENABLE **/
					DMA_DISABLE,		/** Configure Peripheral increment mode	*/ /** DMA_DISABLE , DMA_ENABLE **/
					DMA_DISABLE,		/** Configure Memory increment mode	*/ /** DMA_DISABLE , DMA_ENABLE **/
					DMA_8_bits,			/** Configure the memory transfer size */ /** DMA_8_bits , DMA_16_bits , DMA_32_bits **/
					DMA_8_bits,			/** Configure the Peripheral transfer size */ /** DMA_8_bits , DMA_16_bits , DMA_32_bits **/
					DMA_DISABLE,		/**	Configure Memory to Memory	*/	/** DMA_DISABLE , DMA_ENABLE **/
					DMA_DISABLE ,		/** Interrupt in Complete transfer */  /** DMA_DISABLE , DMA_ENABLE **/
					DMA_DISABLE ,		/** Interrupt in Complete transfer */  /** DMA_DISABLE , DMA_ENABLE **/
					DMA_DISABLE ,		/** Interrupt when error in transfer */  /** DMA_DISABLE , DMA_ENABLE **/
					DMA_DISABLE			/** Configure the Channel enable */ /** DMA_DISABLE , DMA_ENABLE **/
		}	,
		/*************** DMA 2 Channel 5 **********************/
		{
					( tdefChannelRegisters*)DMA2_BASE_ADDRESS+DMA_CH5_CCR_OFFSET	,
					0,					/** Assign the peripheral address 	*/
					0,					/** Assign the Memory address 		*/
					0,					/** Configure the number of data transfer */
					DMA_LowPriority	,	/** Configure the priority of the Channel */ /** DMA_LowPriority , DMA_MediumPriority , DMA_HighPriority , DMA_VeryHighPriority  **/
					DMA_ReadFromPeripheral	,  /** Configure the Channel direction	*/ /** DMA_ReadFromPeripheral ,  DMA_ReadFromMemory **/
					DMA_DISABLE,		/** Configure the Circlar Mode */ /** DMA_DISABLE , DMA_ENABLE **/
					DMA_DISABLE,		/** Configure Peripheral increment mode	*/ /** DMA_DISABLE , DMA_ENABLE **/
					DMA_DISABLE,		/** Configure Memory increment mode	*/ /** DMA_DISABLE , DMA_ENABLE **/
					DMA_8_bits,			/** Configure the memory transfer size */ /** DMA_8_bits , DMA_16_bits , DMA_32_bits **/
					DMA_8_bits,			/** Configure the Peripheral transfer size */ /** DMA_8_bits , DMA_16_bits , DMA_32_bits **/
					DMA_DISABLE,		/**	Configure Memory to Memory	*/	/** DMA_DISABLE , DMA_ENABLE **/
					DMA_DISABLE ,		/** Interrupt in Complete transfer */  /** DMA_DISABLE , DMA_ENABLE **/
					DMA_DISABLE ,		/** Interrupt in Complete transfer */  /** DMA_DISABLE , DMA_ENABLE **/
					DMA_DISABLE ,		/** Interrupt when error in transfer */  /** DMA_DISABLE , DMA_ENABLE **/
					DMA_DISABLE			/** Configure the Channel enable */ /** DMA_DISABLE , DMA_ENABLE **/
		}

};



#endif /* DMA_CFG_H_ */
