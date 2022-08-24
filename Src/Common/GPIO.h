/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPIO.h
 *       Module:  GPIO
 *
 *  Description:  GPIO pins driver
 *
 *********************************************************************************************************************/
#ifndef GPIO_H
#define GPIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define NUMBER_OF_MODIFIED_CHANNELS     10

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
    GPIO_Channel_A0,
    GPIO_Channel_A1,
    GPIO_Channel_A2,
    GPIO_Channel_A3,
    GPIO_Channel_A4,
    GPIO_Channel_A5,
    GPIO_Channel_A6,
    GPIO_Channel_A7,

    GPIO_Channel_B0,
    GPIO_Channel_B1,
    GPIO_Channel_B2,
    GPIO_Channel_B3,
    GPIO_Channel_B4,
    GPIO_Channel_B5,
    GPIO_Channel_B6,
    GPIO_Channel_B7,

    GPIO_Channel_C0,
    GPIO_Channel_C1,
    GPIO_Channel_C2,
    GPIO_Channel_C3,
    GPIO_Channel_C4,
    GPIO_Channel_C5,
    GPIO_Channel_C6,
    GPIO_Channel_C7,

    GPIO_Channel_D0,
    GPIO_Channel_D1,
    GPIO_Channel_D2,
    GPIO_Channel_D3,
    GPIO_Channel_D4,
    GPIO_Channel_D5,
    GPIO_Channel_D6,
    GPIO_Channel_D7,

    GPIO_Channel_E0,
    GPIO_Channel_E1,
    GPIO_Channel_E2,
    GPIO_Channel_E3,
    GPIO_Channel_E4,
    GPIO_Channel_E5,
    GPIO_Channel_E6,

    GPIO_Channel_F0 = 40,
    GPIO_Channel_F1,
    GPIO_Channel_F2,
    GPIO_Channel_F3,
    GPIO_Channel_F4,
    GPIO_Channel_F5,
} GPIO_PinType;

typedef enum
{
    Input,
    Output,
} GPIO_PinDirectionType;

typedef enum
{
    DIO,
} GPIO_PinModeType;

typedef enum
{
    Pull_Up,
    Pull_Down,
    Open_Drain,
} GPIO_PinInternalAttachType;

typedef enum
{
    Low_Current,    /* 2 mA Output Current */
    Mid_Current,    /* 4 mA Output Current */
    High_Current,   /* 8 mA Output Current */
} GPIO_PinOutputCurrentType;

typedef struct
{
    GPIO_PinType PT;
    GPIO_PinDirectionType PD;
    GPIO_PinModeType PM;
    GPIO_PinInternalAttachType PIA;
    GPIO_PinOutputCurrentType POC;
} GPIO_ConfigType;

typedef enum
{
    DIO_Low,
    DIO_High,
} DIO_LevelType;

/* PortLevelType is the whole 8 bits of the Port */
typedef uint8 DIO_PortLevelType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Port_Init(const GPIO_ConfigType *configPtr);

DIO_LevelType DIO_ReadChannel(GPIO_PinType ChannelID);
void DIO_WriteChannel(GPIO_PinType ChannelID, DIO_LevelType Level);
DIO_PortLevelType DIO_ReadPort(GPIO_PinType ChannelID);
void DIO_WritePort(GPIO_PinType ChannelID, DIO_PortLevelType Level);
void DIO_FlipChannel(GPIO_PinType ChannelID);

#endif  /* GPIO_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
