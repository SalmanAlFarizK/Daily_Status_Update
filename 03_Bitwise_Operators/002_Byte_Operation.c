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
    eSetBitsInLsByte = 1,
    eSetBitsInMsByte,
    eSetBitsInLsNibble,
    eSetBitsInMsNibble,
    eSetNBits,
    eClearNBits,
    eToggleNBits,
    eExit,
} eChoiceType;

/*****************************************************************************
 * Function Declarations
 ****************************************************************************/
void SetBitsInLsByte(void);
void SetBitsInMsByte(void);
void SetBitsInLsNibble(void);
void SetBitsInMsNibble(void);
void SetNBits(void);
void ClearNBits(void);
void ToggleNBits(void);


/*****************************************************************************
 * Main Function
 ****************************************************************************/
int main()
{
    int iChoice;
    do
    {
        printf("Enter the choice: \n");
        printf("1. Set bits in LS byte \n");
        printf("2. Set bits in MS byte \n");
        printf("3. Set bits in LS nibble \n");
        printf("4. Set bits in MS nibble \n");
        printf("5. Set N bits \n");
        printf("6. Clear N bits \n");
        printf("7. Toggle N bits \n");
        printf("8. Exit \n");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case eSetBitsInLsByte:
                SetBitsInLsByte();
                break;

            case eSetBitsInMsByte:
                SetBitsInMsByte();
                break;

            case eSetBitsInLsNibble:
                SetBitsInLsNibble();
                break;

            case eSetBitsInMsNibble:
                SetBitsInMsNibble();
                break;

            case eSetNBits:
                SetNBits();
                break;

            case eClearNBits:
                ClearNBits();
                break;

            case eToggleNBits:
                ToggleNBits();
                break;

            case eExit:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while(iChoice != eExit);
    return 0;
}

/*****************************************************************************
 * Function Definitions
 ****************************************************************************/
void SetBitsInLsByte(void)
{
    uint16_t uhVal;
    printf("Enter a 16-bit value: ");
    scanf("%d", &uhVal);
    uhVal |= 0x00FF;
    printf("Value after setting bits in LS byte: %d\n", uhVal);

    return;
}

void SetBitsInMsByte(void)
{
    uint16_t uhVal;
    printf("Enter a 16-bit value: ");
    scanf("%d", &uhVal);
    uhVal |= 0xFF00;
    printf("Value after setting bits in MS byte: %d\n", uhVal);

    return;
}

void SetBitsInLsNibble(void)
{
    uint8_t ucVal;
    printf("Enter an 8-bit value: ");
    scanf("%d", &ucVal);
    ucVal |= 0x0F;
    printf("Value after setting bits in LS nibble: %d\n", ucVal);

    return;
}

void SetBitsInMsNibble(void)
{
    uint8_t ucVal;
    printf("Enter an 8-bit value: ");
    scanf("%d", &ucVal);
    ucVal |= 0xF0;
    printf("Value after setting bits in MS nibble: %d\n", ucVal);

    return;
}

void SetNBits(void)
{
    uint8_t ucVal;
    uint8_t ucN;
    printf("Enter an 8-bit value: ");
    scanf("%d", &ucVal);
    printf("Enter the number of bits to set (0-8): ");
    scanf("%d", &ucN);
    if (ucN <= 8)
    {
        ucVal |= ((1 << ucN) - 1);
        printf("Value after setting %d bits: %d\n", ucN, ucVal);
    }
    else
    {
        printf("Invalid number of bits! Please enter a value between 0 and 8.\n");
    }
    return;
}

void ClearNBits(void)
{
    uint8_t ucVal;
    uint8_t ucN;
    printf("Enter an 8-bit value: ");
    scanf("%d", &ucVal);
    printf("Enter the number of bits to clear (0-8): ");
    scanf("%d", &ucN);
    if (ucN <= 8)
    {
        ucVal &= ~((1 << ucN) - 1);
        printf("Value after clearing %d bits: %d\n", ucN, ucVal);
    }
    else
    {
        printf("Invalid number of bits! Please enter a value between 0 and 8.\n");
    }
    return;
}

void ToggleNBits(void)
{
    uint8_t ucVal;
    uint8_t ucN;
    printf("Enter an 8-bit value: ");
    scanf("%d", &ucVal);
    printf("Enter the number of bits to toggle (0-8): ");
    scanf("%d", &ucN);
    if (ucN <= 8)
    {
        ucVal ^= ((1 << ucN) - 1);
        printf("Value after toggling %d bits: %d\n", ucN, ucVal);
    }
    else
    {
        printf("Invalid number of bits! Please enter a value between 0 and 8.\n");
    }
    return;
}