/*******************************************************************************
  Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_sst26.c

  Summary:
    This file contains the source code for QSPI PLIB Demonstration

  Description:
    This file contains the source code for QSPI PLIB Demonstration.
    It implements the logic of Erasing, reading and writing to QSPI Flash memory

 *******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
//DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app_qspi.h"
#include "definitions.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
#define WRITE_VERIFY_ENABLED 1
#define MIN_DMA_BUFFER_LEN      (CACHE_LINE_SIZE)

volatile bool CACHE_ALIGN xfer_done;

sqi_dma_desc_t CACHE_ALIGN sqiCmdDesc[CMD_DESC_NUMBER];
sqi_dma_desc_t CACHE_ALIGN sqiBufDesc[BUFF_DESC_NUMBER];

uint8_t CACHE_ALIGN sqi_cmd_jedec[MIN_DMA_BUFFER_LEN];
uint8_t CACHE_ALIGN sqi_cmd_eqio[MIN_DMA_BUFFER_LEN];
uint8_t CACHE_ALIGN sqi_cmd_rsten[MIN_DMA_BUFFER_LEN];
uint8_t CACHE_ALIGN sqi_cmd_rst[MIN_DMA_BUFFER_LEN];
uint8_t CACHE_ALIGN sqi_cmd_wren[MIN_DMA_BUFFER_LEN];
uint8_t CACHE_ALIGN sqi_cmd_rdsr[MIN_DMA_BUFFER_LEN];
uint8_t CACHE_ALIGN sqi_cmd_ce[MIN_DMA_BUFFER_LEN];
uint8_t CACHE_ALIGN sqi_cmd_se[MIN_DMA_BUFFER_LEN];
uint8_t CACHE_ALIGN sqi_cmd_be[MIN_DMA_BUFFER_LEN];
uint8_t CACHE_ALIGN sqi_cmd_pp[MIN_DMA_BUFFER_LEN];
uint8_t CACHE_ALIGN sqi_cmd_hsr[MIN_DMA_BUFFER_LEN];
uint8_t CACHE_ALIGN sqi_cmd_ULBPR[MIN_DMA_BUFFER_LEN];
uint8_t CACHE_ALIGN sqi_cmd_dummy[MIN_DMA_BUFFER_LEN];


    
// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

static void APP_EventHandler(uintptr_t context)
{
    xfer_done = true;
}

void APP_WaitUntilTransferDone(void)
{
    while(!xfer_done);
}

/* This function resets the flash by sending down the reset enable command
 * followed by the reset command. */

void APP_ResetFlash(void)
{
    xfer_done = false;

    sqiCmdDesc[0].bd_ctrl       = ( SQI_BDCTRL_BD_BUFLEN(1) | SQI_BDCTRL_PKT_INT_EN_Msk |
                                    SQI_BDCTRL_LIFM_Msk | SQI_BDCTRL_LAST_BD_Msk |
                                    SQI_BDCTRL_SPI_DEV_SEL10(0x00) | SQI_BDCTRL_CS_ASSERT_Msk |
                                    SQI_BDCTRL_DESC_EN_Msk);

    sqiCmdDesc[0].bd_bufaddr    = (uint32_t *)&sqi_cmd_rsten;
    sqiCmdDesc[0].bd_stat       = 0;
    sqiCmdDesc[0].bd_nxtptr     = 0x00000000;

    DCACHE_CLEAN_BY_ADDR((uint32_t *)&sqiCmdDesc[0], sizeof(sqi_dma_desc_t));
    
    SQI1_DMATransfer((sqi_dma_desc_t *)&sqiCmdDesc[0]);

    while(xfer_done == false);

    xfer_done = false;

    sqiCmdDesc[1].bd_ctrl       = ( SQI_BDCTRL_BD_BUFLEN(1) | SQI_BDCTRL_PKT_INT_EN_Msk |
                                    SQI_BDCTRL_LIFM_Msk | SQI_BDCTRL_LAST_BD_Msk |
                                    SQI_BDCTRL_SPI_DEV_SEL10(0x00) | SQI_BDCTRL_CS_ASSERT_Msk |
                                    SQI_BDCTRL_DESC_EN_Msk);

    sqiCmdDesc[1].bd_bufaddr    = (uint32_t *)&sqi_cmd_rst;
    sqiCmdDesc[1].bd_stat       = 0;
    sqiCmdDesc[1].bd_nxtptr     = 0x00000000;

    DCACHE_CLEAN_BY_ADDR((uint32_t *)&sqiCmdDesc[1], sizeof(sqi_dma_desc_t));
    
    SQI1_DMATransfer((sqi_dma_desc_t *)&sqiCmdDesc[1]);

    while(xfer_done == false);

}

/* Enables the QUAD IO on the flash */
void APP_EnableQuadIO(void)
{
    xfer_done = false;

    sqiCmdDesc[0].bd_ctrl       = ( SQI_BDCTRL_BD_BUFLEN(1) | SQI_BDCTRL_PKT_INT_EN_Msk |
                                    SQI_BDCTRL_LIFM_Msk | SQI_BDCTRL_LAST_BD_Msk |
                                    SQI_BDCTRL_SPI_DEV_SEL10(0x00) | SQI_BDCTRL_CS_ASSERT_Msk |
                                    SQI_BDCTRL_DESC_EN_Msk);

    sqiCmdDesc[0].bd_bufaddr    = (uint32_t *)&sqi_cmd_eqio;
    sqiCmdDesc[0].bd_stat       = 0;
    sqiCmdDesc[0].bd_nxtptr     = 0x00000000;

    DCACHE_CLEAN_BY_ADDR((uint32_t *)&sqiCmdDesc[0], sizeof(sqi_dma_desc_t));
    
    SQI1_DMATransfer((sqi_dma_desc_t *)&sqiCmdDesc[0]);

    while(xfer_done == false);
}

/* Sends Write Enable command to flash */
void APP_WriteEnable(void)
{
    sqiCmdDesc[0].bd_ctrl       = ( SQI_BDCTRL_BD_BUFLEN(1) | SQI_BDCTRL_MODE(0x02) |
                                    SQI_BDCTRL_SPI_DEV_SEL10(0x00) | SQI_BDCTRL_CS_ASSERT_Msk |
                                    SQI_BDCTRL_DESC_EN_Msk);

    sqiCmdDesc[0].bd_bufaddr    = (uint32_t *)&sqi_cmd_wren;
    sqiCmdDesc[0].bd_stat       = 0;
    sqiCmdDesc[0].bd_nxtptr     = (sqi_dma_desc_t *)&sqiCmdDesc[1];
}

/* This function sends down command to perform a global unprotect of the flash. */
void APP_UnlockFlash(void)
{
    xfer_done = false;

    APP_WriteEnable();

    sqiCmdDesc[1].bd_ctrl       = ( SQI_BDCTRL_BD_BUFLEN(1) | SQI_BDCTRL_PKT_INT_EN_Msk |
                                    SQI_BDCTRL_LIFM_Msk | SQI_BDCTRL_LAST_BD_Msk |
                                    SQI_BDCTRL_MODE(0x02) | SQI_BDCTRL_SPI_DEV_SEL10(0x00) |
                                    SQI_BDCTRL_CS_ASSERT_Msk | SQI_BDCTRL_DESC_EN_Msk);

    sqiCmdDesc[1].bd_bufaddr    = (uint32_t *)&sqi_cmd_ULBPR;
    sqiCmdDesc[1].bd_stat       = 0;
    sqiCmdDesc[1].bd_nxtptr     = 0x00000000;

    DCACHE_CLEAN_BY_ADDR((uint32_t *)&sqiCmdDesc[0], (2*sizeof(sqi_dma_desc_t)));
    
    SQI1_DMATransfer((sqi_dma_desc_t *)&sqiCmdDesc[0]);

    while(xfer_done == false);
}

/* This function reads and stores the flash id. */
void APP_ReadJedecId(uint32_t *jedec_id)
{
    xfer_done = false;

    sqi_cmd_jedec[1] = DUMMY_BYTE;

    sqiCmdDesc[0].bd_ctrl       = ( SQI_BDCTRL_BD_BUFLEN(2) | SQI_BDCTRL_MODE(0x02) |
                                    SQI_BDCTRL_SPI_DEV_SEL10(0x00) | SQI_BDCTRL_DESC_EN_Msk);

    sqiCmdDesc[0].bd_bufaddr    = (uint32_t *)&sqi_cmd_jedec;
    sqiCmdDesc[0].bd_stat       = 0;
    sqiCmdDesc[0].bd_nxtptr     = (sqi_dma_desc_t *)&sqiBufDesc[0];

    sqiBufDesc[0].bd_ctrl       = ( SQI_BDCTRL_BD_BUFLEN(4) | SQI_BDCTRL_PKT_INT_EN_Msk |
                                    SQI_BDCTRL_LIFM_Msk | SQI_BDCTRL_LAST_BD_Msk |
                                    SQI_BDCTRL_MODE(0x02) | SQI_BDCTRL_DIR_Msk |
                                    SQI_BDCTRL_SPI_DEV_SEL10(0x00) | SQI_BDCTRL_CS_ASSERT_Msk |
                                    SQI_BDCTRL_DESC_EN_Msk);

    sqiBufDesc[0].bd_bufaddr    = (uint32_t *)jedec_id;
    sqiBufDesc[0].bd_stat       = 0;
    sqiBufDesc[0].bd_nxtptr     = 0x00000000;
    
    DCACHE_CLEAN_BY_ADDR((uint32_t *)sqi_cmd_jedec, sizeof(sqi_cmd_jedec));
    DCACHE_CLEAN_BY_ADDR((uint32_t *)&sqiCmdDesc[0], sizeof(sqi_dma_desc_t));
    DCACHE_CLEAN_BY_ADDR((uint32_t *)&sqiBufDesc[0], sizeof(sqi_dma_desc_t));

    // Initialize the root buffer descriptor
    SQI1_DMATransfer((sqi_dma_desc_t *)&sqiCmdDesc[0]);

    while(xfer_done == false);
}

/* Function to read the status register of the flash. */
void APP_ReadStatus( uint32_t *rx_data, uint32_t rx_data_length )
{
    xfer_done = false;

    sqi_cmd_rdsr[1] = DUMMY_BYTE;

    sqiCmdDesc[0].bd_ctrl       = ( SQI_BDCTRL_BD_BUFLEN(2) | SQI_BDCTRL_MODE(0x02) |
                                    SQI_BDCTRL_SPI_DEV_SEL10(0x00) | SQI_BDCTRL_DESC_EN_Msk);

    sqiCmdDesc[0].bd_bufaddr    = (uint32_t *)&sqi_cmd_rdsr;
    sqiCmdDesc[0].bd_stat       = 0;
    sqiCmdDesc[0].bd_nxtptr     = (sqi_dma_desc_t *)&sqiBufDesc[0];

    sqiBufDesc[0].bd_ctrl       = ( SQI_BDCTRL_BD_BUFLEN(rx_data_length) | SQI_BDCTRL_PKT_INT_EN_Msk |
                                    SQI_BDCTRL_LIFM_Msk | SQI_BDCTRL_LAST_BD_Msk |
                                    SQI_BDCTRL_MODE(0x02) | SQI_BDCTRL_DIR_Msk |
                                    SQI_BDCTRL_SPI_DEV_SEL10(0x00) | SQI_BDCTRL_CS_ASSERT_Msk |
                                    SQI_BDCTRL_DESC_EN_Msk);

    sqiBufDesc[0].bd_bufaddr    = (uint32_t *)rx_data;
    sqiBufDesc[0].bd_stat       = 0;
    sqiBufDesc[0].bd_nxtptr     = 0x00000000;
    
    DCACHE_CLEAN_BY_ADDR((uint32_t *)sqi_cmd_rdsr, sizeof(sqi_cmd_rdsr));
    DCACHE_CLEAN_BY_ADDR((uint32_t *)&sqiCmdDesc[0], sizeof(sqi_dma_desc_t));
    DCACHE_CLEAN_BY_ADDR((uint32_t *)&sqiBufDesc[0], sizeof(sqi_dma_desc_t));

    // Initialize the root buffer descriptor
    SQI1_DMATransfer((sqi_dma_desc_t *)&sqiCmdDesc[0]);

    while(xfer_done == false);
}


/* Reads n Bytes of data from the flash memory */
void APP_Read( uint32_t *rx_data, uint32_t rx_data_length, uint32_t address )
{
    uint32_t pendingBytes   = rx_data_length;
    uint8_t *readBuffer     = (uint8_t *)rx_data;
    uint32_t numBytes       = 0;
    uint32_t i              = 0;

    xfer_done = false;

    // Construct parameters to issue read command
    sqi_cmd_hsr[1] = (0xff & (address>>16));
    sqi_cmd_hsr[2] = (0xff & (address>>8));
    sqi_cmd_hsr[3] = (0xff & (address>>0));    
    sqi_cmd_hsr[4] = 0;

    sqiCmdDesc[0].bd_ctrl       = ( SQI_BDCTRL_BD_BUFLEN(5) | SQI_BDCTRL_MODE(0x02) |
                                    SQI_BDCTRL_SPI_DEV_SEL10(0x00) | SQI_BDCTRL_DESC_EN_Msk);

    sqiCmdDesc[0].bd_bufaddr    = (uint32_t *)&sqi_cmd_hsr;
    sqiCmdDesc[0].bd_stat       = 0;
    sqiCmdDesc[0].bd_nxtptr     = (sqi_dma_desc_t *)&sqiCmdDesc[1];  
    
    DCACHE_CLEAN_BY_ADDR((uint32_t *)&sqiCmdDesc[0], sizeof(sqiCmdDesc[0]));

    sqiCmdDesc[1].bd_ctrl       = ( SQI_BDCTRL_BD_BUFLEN(2) | SQI_BDCTRL_MODE(0x02) |
                                    SQI_BDCTRL_SPI_DEV_SEL10(0x00) | SQI_BDCTRL_DESC_EN_Msk);

    sqiCmdDesc[1].bd_bufaddr    = (uint32_t *)&sqi_cmd_dummy;
    sqiCmdDesc[1].bd_stat       = 0;
    sqiCmdDesc[1].bd_nxtptr     = (sqi_dma_desc_t *)&sqiBufDesc[0]; 
    
    DCACHE_CLEAN_BY_ADDR((uint32_t *)sqi_cmd_hsr, sizeof(sqi_cmd_hsr));
    DCACHE_CLEAN_BY_ADDR((uint32_t *)&sqiCmdDesc[0], 2 * sizeof(sqi_dma_desc_t));

    for (i = 0; (i < BUFF_DESC_NUMBER) && (pendingBytes > 0); i++)
    {
        if (pendingBytes > PAGE_SIZE)
        {
            numBytes = PAGE_SIZE;
        }
        else
        {
            numBytes = pendingBytes;
        }

        sqiBufDesc[i].bd_ctrl       = ( SQI_BDCTRL_BD_BUFLEN(numBytes) | SQI_BDCTRL_PKT_INT_EN_Msk |
                                        SQI_BDCTRL_MODE(0x02) | SQI_BDCTRL_DIR_Msk |
                                        SQI_BDCTRL_SPI_DEV_SEL10(0x00) | SQI_BDCTRL_DESC_EN_Msk);

        sqiBufDesc[i].bd_bufaddr    = (uint32_t *)readBuffer;
        sqiBufDesc[i].bd_stat       = 0;
        sqiBufDesc[i].bd_nxtptr     = (sqi_dma_desc_t *)&sqiBufDesc[i+1];

        pendingBytes    -= numBytes;
        readBuffer      += numBytes;
    }

    /* The last descriptor must indicate the end of the descriptor list */
    sqiBufDesc[i-1].bd_ctrl         |= (SQI_BDCTRL_LIFM_Msk | SQI_BDCTRL_LAST_BD_Msk |
                                        SQI_BDCTRL_CS_ASSERT_Msk);

    sqiBufDesc[i-1].bd_nxtptr       = 0x00000000;
    
    DCACHE_CLEAN_BY_ADDR((uint32_t *)&sqiBufDesc[0], (i * sizeof(sqi_dma_desc_t)));

    // Initialize the root buffer descriptor
    SQI1_DMATransfer((sqi_dma_desc_t *)&sqiCmdDesc[0]);
}

void APP_PageWrite( void *tx_data, uint32_t address )
{
    xfer_done = false;

    APP_WriteEnable();

    // Construct parameters to issue page program command
    sqi_cmd_pp[1] = (0xff & (address>>16));
    sqi_cmd_pp[2] = (0xff & (address>>8));
    sqi_cmd_pp[3] = (0xff & (address>>0));

    sqiCmdDesc[1].bd_ctrl       = ( SQI_BDCTRL_BD_BUFLEN(4) | SQI_BDCTRL_MODE(0x02) |
                                    SQI_BDCTRL_SPI_DEV_SEL10(0x00) | SQI_BDCTRL_DESC_EN_Msk);

    sqiCmdDesc[1].bd_bufaddr    = (uint32_t *)(&sqi_cmd_pp);
    sqiCmdDesc[1].bd_stat       = 0;
    sqiCmdDesc[1].bd_nxtptr     = (sqi_dma_desc_t *)(&sqiBufDesc[0]);

    sqiBufDesc[0].bd_ctrl       = ( SQI_BDCTRL_BD_BUFLEN(PAGE_SIZE) | SQI_BDCTRL_PKT_INT_EN_Msk |
                                    SQI_BDCTRL_LIFM_Msk | SQI_BDCTRL_LAST_BD_Msk |
                                    SQI_BDCTRL_MODE(0x02) | SQI_BDCTRL_STAT_CHECK_Msk |
                                    SQI_BDCTRL_SPI_DEV_SEL10(0x00) | SQI_BDCTRL_CS_ASSERT_Msk |
                                    SQI_BDCTRL_DESC_EN_Msk);

    sqiBufDesc[0].bd_bufaddr    = (uint32_t *)(tx_data);
    sqiBufDesc[0].bd_stat       = 0;
    sqiBufDesc[0].bd_nxtptr     = 0x00000000;
    
    DCACHE_CLEAN_BY_ADDR((uint32_t *)sqi_cmd_pp, sizeof(sqi_cmd_pp));
    DCACHE_CLEAN_BY_ADDR((uint32_t *)&sqiCmdDesc[0], (2 * sizeof(sqi_dma_desc_t)));
    DCACHE_CLEAN_BY_ADDR((uint32_t *)&sqiBufDesc[0], sizeof(sqi_dma_desc_t));

    // Initialize the root buffer descriptor
    SQI1_DMATransfer((sqi_dma_desc_t *)(&sqiCmdDesc[0]));
}


/* Sends Erase command to flash */
void APP_Erase(uint8_t *address, uint32_t length)
{
    xfer_done = false;

    APP_WriteEnable();

    sqiCmdDesc[1].bd_ctrl       = ( SQI_BDCTRL_BD_BUFLEN(length) | SQI_BDCTRL_PKT_INT_EN_Msk |
                                    SQI_BDCTRL_LIFM_Msk | SQI_BDCTRL_LAST_BD_Msk |
                                    SQI_BDCTRL_MODE(0x02) | SQI_BDCTRL_STAT_CHECK_Msk |
                                    SQI_BDCTRL_SPI_DEV_SEL10(0x00) | SQI_BDCTRL_CS_ASSERT_Msk |
                                    SQI_BDCTRL_DESC_EN_Msk);

    sqiCmdDesc[1].bd_bufaddr    = (uint32_t *)(address);
    sqiCmdDesc[1].bd_stat       = 0;
    sqiCmdDesc[1].bd_nxtptr     = 0x00000000;
    
    DCACHE_CLEAN_BY_ADDR((uint32_t *)&sqiCmdDesc[0], (2 * sizeof(sqi_dma_desc_t)));

    SQI1_DMATransfer((sqi_dma_desc_t *)(&sqiCmdDesc[0]));
}

void APP_SectorErase(uint32_t address)
{
    sqi_cmd_se[1] = (0xff & (address>>16));
    sqi_cmd_se[2] = (0xff & (address>>8));
    sqi_cmd_se[3] = (0xff & (address>>0));

    DCACHE_CLEAN_BY_ADDR((uint32_t *)sqi_cmd_se, sizeof(sqi_cmd_se));
    APP_Erase(&sqi_cmd_se[0], 4);
}

void APP_BulkErase( uint32_t address )
{
    sqi_cmd_be[1] = (0xff & (address>>16));
    sqi_cmd_be[2] = (0xff & (address>>8));
    sqi_cmd_be[3] = (0xff & (address>>0));

    DCACHE_CLEAN_BY_ADDR((uint32_t *)sqi_cmd_be, sizeof(sqi_cmd_be));
    APP_Erase(&sqi_cmd_be[0], 4);
}

void APP_ChipErase( void )
{
    APP_Erase(sqi_cmd_ce, 1);
}


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_QSPI_Initialize ( void )
{

   // SQI1_Initialize();
    
    sqi_cmd_jedec[0]    = SST26_CMD_QUAD_JEDEC_ID_READ;
    sqi_cmd_eqio[0]     = SST26_CMD_ENABLE_QUAD_IO;
    sqi_cmd_rsten[0]    = SST26_CMD_FLASH_RESET_ENABLE;
    sqi_cmd_rst[0]      = SST26_CMD_FLASH_RESET;
    sqi_cmd_wren[0]     = SST26_CMD_WRITE_ENABLE;
    sqi_cmd_rdsr[0]     = SST26_CMD_READ_STATUS_REG;
    sqi_cmd_ce[0]       = SST26_CMD_CHIP_ERASE;
    sqi_cmd_be[0]       = SST26_CMD_BULK_ERASE_64K;
    sqi_cmd_se[0]       = SST26_CMD_SECTOR_ERASE;
    sqi_cmd_pp[0]       = SST26_CMD_PAGE_PROGRAM;
    sqi_cmd_hsr[0]      = SST26_CMD_HIGH_SPEED_READ;
    sqi_cmd_ULBPR[0]    = SST26_CMD_UNPROTECT_GLOBAL;
    
    DCACHE_CLEAN_BY_ADDR((uint32_t *)sqi_cmd_jedec, sizeof(sqi_cmd_jedec));
    DCACHE_CLEAN_BY_ADDR((uint32_t *)sqi_cmd_eqio, sizeof(sqi_cmd_eqio));
    DCACHE_CLEAN_BY_ADDR((uint32_t *)sqi_cmd_rsten, sizeof(sqi_cmd_rsten));
    DCACHE_CLEAN_BY_ADDR((uint32_t *)sqi_cmd_rst, sizeof(sqi_cmd_rst));
    DCACHE_CLEAN_BY_ADDR((uint32_t *)sqi_cmd_wren, sizeof(sqi_cmd_wren));
    DCACHE_CLEAN_BY_ADDR((uint32_t *)sqi_cmd_rdsr, sizeof(sqi_cmd_rdsr));
    DCACHE_CLEAN_BY_ADDR((uint32_t *)sqi_cmd_ce, sizeof(sqi_cmd_ce));
    DCACHE_CLEAN_BY_ADDR((uint32_t *)sqi_cmd_be, sizeof(sqi_cmd_be));
    DCACHE_CLEAN_BY_ADDR((uint32_t *)sqi_cmd_se, sizeof(sqi_cmd_se));
    DCACHE_CLEAN_BY_ADDR((uint32_t *)sqi_cmd_pp, sizeof(sqi_cmd_pp));
    DCACHE_CLEAN_BY_ADDR((uint32_t *)sqi_cmd_hsr, sizeof(sqi_cmd_hsr));
    DCACHE_CLEAN_BY_ADDR((uint32_t *)sqi_cmd_ULBPR, sizeof(sqi_cmd_ULBPR));

    SQI1_RegisterCallback(APP_EventHandler, (uintptr_t)NULL);


}

/*******************************************************************************
 End of File
 */
