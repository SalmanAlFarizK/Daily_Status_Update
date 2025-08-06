/*****************************************************************************
 * Gobal Includes
 ****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/*****************************************************************************
 * Enum Declarations
 ****************************************************************************/
typedef enum _eChoiceType_
{
    eSetLsb = 1,
    eClearLsb,
    eToggleLsb,
    eSetMsb,
    eClearMsb,
    eToggleMsb,
    eSetSpecificBit,
    eClearSpecificBit,
    eToggleSpecificBit,
    eExit,
} eChoiceType;

/*****************************************************************************
 * Function Declarations
 ****************************************************************************/
void SetLsb(uint8_t ucVal);
void ClearLsb(uint8_t ucVal);
void ToggleLsb(uint8_t ucVal);
void SetMsb(uint8_t ucVal);
void ClearMsb(uint8_t ucVal);
void ToggleMsb(uint8_t ucVal);
void SetSpecificBit(uint8_t ucVal);
void ClearSpecificBit(uint8_t ucVal);
void ToggleSpecificBit(uint8_t ucVal);

/*****************************************************************************
 * Main Function
 ****************************************************************************/
int main()
{
    uint8_t ucVal = 0;
    int iChoice;
    printf("Enter the value: ");
    scanf("%d",&ucVal);
    printf("\n");
    do
    {
        printf("Enter a choice : \n");
        printf("1.Set LSB\n");
        printf("2.Clear LSB\n");
        printf("3.Toggle LSB\n");
        printf("4.Set MSB\n");
        printf("5.Clear MSB\n");
        printf("6.Toggle MSB\n");
        printf("7.Set Specific bit\n");
        printf("8.Clear Specific bit\n");
        printf("9.Toggle Specific bit\n");
        printf("10.Exit\n");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case eSetLsb:
                SetLsb(ucVal);
                break;

            case eClearLsb:
                ClearLsb(ucVal);
                break;

            case eToggleLsb:
                ToggleLsb(ucVal);
                break;

            case eSetMsb:
                SetMsb(ucVal);
                break;

            case eClearMsb:
                ClearMsb(ucVal);
                break;

            case eToggleMsb:
                ToggleMsb(ucVal);
                break;

            case eSetSpecificBit:
                SetSpecificBit(ucVal);
                break;

            case eClearSpecificBit:
                ClearSpecificBit(ucVal);
                break;

            case eToggleSpecificBit:
                ToggleSpecificBit(ucVal);
                break;
            
            case eExit:
                break;
            
            default:
                printf("Enter the valid option :) \n");
        }
    } while (iChoice != eExit);
    
    return 0;
}

/*****************************************************************************
 * Function Definitions
 ****************************************************************************/
void SetLsb(uint8_t ucVal)
{
    ucVal |= 0x01;
    printf("Value after setting LSB: %d\n", ucVal);
}

void ClearLsb(uint8_t ucVal)
{
    ucVal &= ~0x01;
    printf("Value after clearing LSB: %d\n", ucVal);
}

void ToggleLsb(uint8_t ucVal)
{
    ucVal ^= 0x01;
    printf("Value after toggling LSB: %d\n", ucVal);
}

void SetMsb(uint8_t ucVal)
{
    ucVal |= 0x80;
    printf("Value after setting MSB: %d\n", ucVal);
}

void ClearMsb(uint8_t ucVal)
{
    ucVal &= ~0x80;
    printf("Value after clearing MSB: %d\n", ucVal);
}

void ToggleMsb(uint8_t ucVal)
{
    ucVal ^= 0x80;
    printf("Value after toggling MSB: %d\n", ucVal);
}

void SetSpecificBit(uint8_t ucVal)
{
    uint8_t ucPos;
    printf("Enter the position of the bit to set (0-7): ");
    scanf("%d", &ucPos);
    if (ucPos < 8)
    {
        ucVal |= (1 << ucPos);
        printf("Value after setting bit %d: %d\n", ucPos, ucVal);
    }
    else
    {
        printf("Invalid position! Please enter a value between 0 and 7.\n");
    }
    
    return;
}

void ClearSpecificBit(uint8_t ucVal)
{
    uint8_t ucPos;
    printf("Enter the position of the bit to clear (0-7): ");
    scanf("%d", &ucPos);
    if (ucPos < 8)
    {
        ucVal &= ~(1 << ucPos);
        printf("Value after clearing bit %d: %d\n", ucPos, ucVal);
    }
    else
    {
        printf("Invalid position! Please enter a value between 0 and 7.\n");
    }
    return;
}  

void ToggleSpecificBit(uint8_t ucVal)
{
    uint8_t ucPos;
    printf("Enter the position of the bit to toggle (0-7): ");
    scanf("%d", &ucPos);
    if (ucPos < 8)
    {
        ucVal ^= (1 << ucPos);
        printf("Value after toggling bit %d: %d\n", ucPos, ucVal);
    }
    else
    {
        printf("Invalid position! Please enter a value between 0 and 7.\n");
    }
    return;
}