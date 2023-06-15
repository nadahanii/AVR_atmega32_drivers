#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg,bitN)    ((reg) |= (1<<bitN))    // Sets a bit (bitN) in a register (reg)
#define CLR_BIT(reg,bitN)  ((reg) &= ~(1<<bitN))     // Clears a bit (bitN) in a register (reg)
#define TOG_BIT(reg,bitN) ((reg) ^= (1<<bitN))       // Toggles a bit (bitN) in a register (reg)
#define GET_BIT(reg,bitN)    (1 & ((reg)>>bitN))     // Returns value of bit (bitN) in a register (reg)

#define GET_REG(reg) (reg)
#define SET_REG(reg) ((reg)=0xFF)
#define CLR_REG(reg) ((reg)=0x00)
#define TOG_REG(reg) ((reg)^=0xFF)
#define ASSIGN_REG(reg,value) ((reg)=value)
#endif
