#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#include "control_reg.h"
// Defining constant flags [CAN BE ALTERED]
#define FLAG_POWER (1 << 0) // Bit 0 -> 0000 0001
#define FLAG_READY (1 << 1) // Bit 1 -> 0000 0010
#define FLAG_ERROR (1 << 2) // Bit 2 -> 0000 0100
#define FLAG_OVERHEAT (1 << 3) // Bit 3 -> 0000 1000
#define FLAG_BLINK (1 << 4) // Bit 4 -> 0001 0000 

// Register = |0000 0000| 
// bit 0 tells if power is on(1) off(0)
// bit 1 tells if device is ready to receive(1) not (0)
// bit 2 tells if device is in error mode(1) in error mode no errors = (0)
// bit 3 tells if the device is overheating (1) if not (0)
// bit 4  tells the device to blink all the LEDs on (1) blinking (0) not blinking
int main(void) 
{
    uint8_t reg = 15; // Register
    uint8_t *preg = &reg;
    // Test prints
    printf("register before set: %02x\n", reg);
    bool res = set_flag(preg, FLAG_BLINK);
    printf("register before clearing: %02x\n", reg);
    bool check = check_flag(*preg, FLAG_BLINK);
    printf("register on: %d\n", check);
    bool clear = clear_flag(preg, FLAG_BLINK);
    printf("register after clearing: %02x\n", reg);
    check = check_flag(*preg, FLAG_BLINK);
    printf("register on: %d\n", check);
    return 0;
}


// Takes a pointer to unsigned integer register with 8 bits
// Uses the flag to set on the mode to the 8 bit reg
// Returns true if set the flag succesfully
// Returns false if *reg == NULL
bool set_flag(uint8_t *reg, uint8_t flag) 
{
    if (reg == NULL) 
    {
        return false;
    }
    else 
    {
    *reg |= flag;
    return true;      
    }

}

// clears a flag from the register by using pointer to reg
// returns false if *reg == NULL
// Else true
bool clear_flag(uint8_t *reg, uint8_t flag) 
{
    if (reg == NULL) 
    {
        return false;
    }
    else 
    {
        *reg &= ~flag;
        return true;
    }
} 

// Checks if a flag is on/off
// Returns true if flag is on
// Else false
bool check_flag(uint8_t reg, uint8_t flag) 
{
    if ((reg & flag) != 0) 
    {
        return true;
    }
    else 
    {
        return false;
    }
}