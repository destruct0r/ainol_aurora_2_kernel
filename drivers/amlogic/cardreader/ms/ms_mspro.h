#ifndef _H_MS_MSPRO
#define _H_MS_MSPRO

#include <linux/slab.h>
#include <linux/types.h>
    
#include <linux/cardreader/card_block.h>
#include <linux/cardreader/cardreader.h>
#include <linux/cardreader/sdio_hw.h>
#include <mach/card_io.h>

#include "ms_protocol.h"
    
#pragma pack(1)

	
	unsigned Reserved1:1;	//D1
	unsigned Reserved2:1;	//D2
	unsigned Reserved3:1;	//D3
	unsigned Reserved4:1;	//D4
	unsigned BREQ:1;	//D5: Buffer Request
	unsigned ERR:1;		//D6: Error
	unsigned CED:1;		//D7: Command End
} MS_MSPRO_INT_Register_t;

	
		
		
			
			
		
		
			
			
			
			
		
	
	
		
			
			
		
		
			
			
		
	
	


	
	
	
	


#pragma pack()
typedef enum _MS_MSPRO_Card_Type 
{ 
	CARD_NONE_TYPE = 0, 
	CARD_TYPE_MS, 
	CARD_TYPE_MSPRO 
} MS_MSPRO_Card_Type_t;

typedef enum _MS_MSPRO_Interface_Mode 
{ 
	INTERFACE_SERIAL = 1, 
	INTERFACE_PARALLEL = 4 
} MS_MSPRO_Interface_Mode_t;

typedef enum _MS_MSPRO_Error_Status 
{ 
    	MS_MSPRO_NO_ERROR =0, 
    	MS_MSPRO_ERROR_TPC_FORMAT, 
    	MS_MSPRO_ERROR_RDY_TIMEOUT, 
    	MS_MSPRO_ERROR_INT_TIMEOUT,
    	MS_MSPRO_ERROR_DATA_CRC, 
    	MS_MSPRO_ERROR_MEDIA_TYPE,
	MS_MSPRO_ERROR_CMDNK, 
	MS_MSPRO_ERROR_CED,
	MS_MSPRO_ERROR_FLASH_READ, 
	MS_MSPRO_ERROR_FLASH_WRITE,
	MS_MSPRO_ERROR_FLASH_ERASE,
	MS_MSPRO_ERROR_PARAMETER, 
	MS_MSPRO_ERROR_WRITE_PROTECTED,
	MS_MSPRO_ERROR_READ_ONLY,
	MS_ERROR_BOOT_SEARCH, 
	MS_ERROR_MEMORY_STICK_TYPE,
	MS_ERROR_FORMAT_TYPE, 
	MS_ERROR_BLOCK_NUMBER_SIZE,
	MS_ERROR_DISABLED_BLOCK, 
	MS_ERROR_NO_FREE_BLOCK,
	MS_ERROR_LOGICAL_PHYSICAL_TABLE, 
	MS_ERROR_BOOT_IDI,
	MSPRO_ERROR_MEDIA_BREAKDOWN, 
	MSPRO_ERROR_STARTUP_TIMEOUT,
	MSPRO_ERROR_WRITE_DISABLED, 
	MS_MSPRO_ERROR_TIMEOUT, 
	MS_MSPRO_ERROR_UNSUPPORTED, 
	MS_MSPRO_ERROR_NO_MEMORY, 
	MS_MSPRO_ERROR_NO_READ 
} MS_MSPRO_Error_Status_t;

typedef enum _MS_MSPRO_Media_Type 
{ 
	MEMORY_STICK_ERROR, 
	MEMORY_STICK, 
	MEMORY_STICK_WITH_SP,

	MEMORY_STICK_R, 
	MEMORY_STICK_ROM_WITH_SP,


	MEMORY_STICK_PRO_ROM, 
	MEMORY_STICK_PRO_R,


} MS_MSPRO_Media_Type_t;

typedef enum _Endian_Type 
{ 
	ENDIAN_TYPE_WORD = 2, 
	ENDIAN_TYPE_DWORD = 4, 
	ENDIAN_TYPE_QWORD = 8 
} Endian_Type_t;

typedef union _MS_MSPRO_Card_Buffer 
	
		
		
		
		
		
		
		
		
		
		
		    //MS_Boot_IDI_t boot_idi;
		unsigned short logical_physical_table[MS_MAX_SEGMENT_NUMBERS *
						      MS_BLOCKS_PER_SEGMENT];
		
						 MS_MAX_FREE_BLOCKS_PER_SEGMENT];
	
	
		
		
		
		
		    device_information_entry
		    [MSRPO_MAX_DEVICE_INFORMATION_ENTRY];
		
		
	



	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	SDIO_Pad_Type_t  io_pad_type;	/* hw io pin pad */
	
	unsigned char *dma_buf;
	unsigned char *dma_phy_buf;

	unsigned char *ms_mspro_buf;
	unsigned char *ms_mspro_phy_buf;

	unsigned char* data_buf;
	unsigned char* data_phy_buf;
	


//Transfer Protocol Command (TPC)
#define TPC_MS_READ_PAGE_DATA               0x2D
#define TPC_MS_MSPRO_READ_REG               0x4B
#define TPC_MS_MSPRO_GET_INT                0x78
#define TPC_MS_WRITE_PAGE_DATA              0xD2
#define TPC_MS_MSPRO_WRITE_REG              0xB4
#define TPC_MS_MSPRO_SET_RW_REG_ADRS        0x87
#define TPC_MS_MSPRO_SET_CMD                0xE1
#define TPC_MSPRO_READ_LONG_DATA            0x2D
#define TPC_MSPRO_READ_SHORT_DATA           0x3C
#define TPC_MSPRO_WRITE_LONG_DATA           0xD2
#define TPC_MSPRO_WRITE_SHORT_DATA          0xC3
#define TPC_MSPRO_EX_SET_CMD                0x96
    
#define MS_MSPRO_RDY_TIMEOUT                (50*TIMER_1MS)	//10ms, sleep mode
#define MS_MSPRO_INT_TIMEOUT                (1500*TIMER_1MS)	//1500ms, sleep mode
    
#define MS_MSPRO_INIT_RETRY					3
    
#define MS_MSPRO_TRANSFER_SLOWER_CLK				12	//M HZ
#define MS_MSPRO_TRANSFER_CLK						18	//M HZ
#define MS_MSPRO_TRANSFER_HIGHSPEED_CLK				25	//M HZ
    
#define MS_WRITE_ESPECIAL_CAPACITY_BLOCKS				130000

#endif				//_H_MS_MSPRO