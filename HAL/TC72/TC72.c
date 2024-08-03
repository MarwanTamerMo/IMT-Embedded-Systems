/*****************************************************/
/*Description  : TC72 Driver Implementation file     */
/*Author       : Marwan Tamer                        */
/*version 	   : 1.0V   on  1 Aug 2024               */
/*****************************************************/

#include "STD_Types.h"
#include "Bitmath.h"
#include "SPI.h"
#include "TC72_cnfg.h"
#include "TC72_priv.h"
#include "DIO.h" // Include DIO driver header

void TC72_vidInit()
{
    // Initialize SPI communication
    SPI_vidInit();
    
    // Initialize the CE pin as output
    DIO_vidInit();
    DIO_enuWritePin(CE_PIN, 1); // Set CE_PIN to high initially
    
    // Set the TC72 to continuous temperature conversion mode
    TC72_vidSelectMode(AUTO_CONVERSION_MODE); // Continuous conversion mode
}

void TC72_vidSelectMode(uint8 u8ModeCpy)
{
    // Assert the chip enable (CE) pin low to select the TC72
    CE_PIN_LOW();

    // Write the control register address with the write flag
    SPI_u8TransmitDataSync(CONTROL_REG_WRITE);

    // Write the mode to the control register
    SPI_u8TransmitDataSync(u8ModeCpy);

    // Deassert the chip enable (CE) pin high to deselect the TC72
    CE_PIN_HIGH();
}

uint8 TC72_u8ReadData()
{
    uint8 u8TempData;

    // Assert the chip enable (CE) pin low to select the TC72
    CE_PIN_LOW();

    // Select the MSB temperature register for reading
    SPI_u8TransmitDataSync(MSB_TEMP_REG);
    
    // Read MSB temperature register
    u8TempData = SPI_u8ReceiveDataSync();

    // Deassert the chip enable (CE) pin high to deselect the TC72
    CE_PIN_HIGH();

    return u8TempData;
}

void TC72_vidWriteData(uint8 u8DataCpy)
{
    // This function can be used for future write operations to the TC72
    CE_PIN_LOW();
    SPI_u8TransmitDataSync(CONTROL_REG_WRITE);
    SPI_u8TransmitDataSync(u8DataCpy);
    CE_PIN_HIGH();
}

// CE_PIN control functions
void CE_PIN_HIGH()
{
    DIO_enuWritePin(CE_PIN, 1); // Set CE_PIN to high
}

void CE_PIN_LOW()
{
    DIO_enuWritePin(CE_PIN, 0); // Set CE_PIN to low
}
