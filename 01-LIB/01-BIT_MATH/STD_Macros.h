/*
 * STD_Macros.h
 *
 * Created: 1/16/2022 1:35:59 AM
 * Author: Mohamed Elhafy
 *
 * standard macros for future use 
 * 
 * Macro like a function 
 * 
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_

// architecture Dependant Macro
#define F_CPU 8000000UL   // Make the clock of the micro is 8 MHZ
#define REGISTER_SIZE 8  //Set register size for future use or edit 


//sitting or clear or toggle or read a specific  bit 
#define SET_BIT(reg,bit) reg|=(1<<bit)               // for sitting bit make OR"|" with one shifted lift by the pin number  
#define CLR_BIT(reg,bit) reg&=(~(1<<bit))           // for clearing bit make AND"&" with the complement of one shifted lift by the pin number 
#define TOG_BIT(reg,bit) reg^=(1<<bit)             // for toggling bit make XOR"^" with the one shifted lift by the pin number
#define READ_BIT(reg,bit) ((reg&(1<<bit))>>bit)   // for reading bit make AND"&" with the one shifted lift by the pin number and then shift the output with the pin number

//asking is the bit if is set or not 
#define IS_BIT_SET(reg,bit) (reg&(1<<bit))>>bit     // for return one is the bit is one make AND"&" with the one shifted lift by the pin number and then shift the output with the pin number
#define IS_BIT_CLEAR(reg,bit) !((reg&(1<<bit))>>bit) // for return one if the bit is zero make AND"&" with the one shifted lift by the pin number and then shift the output with the pin number and then not the output

// Rotating the numbers bits
#define ROR(reg,num) reg=(reg<<(REGISTER_SIZE-num))|(reg>>(num))  // rotate right the bits of the number  
#define ROL(reg,num) reg=(reg>>(REGISTER_SIZE-num))|(reg<<(num)) // rotate lift the bits of the number


#define DUMMY_DATA 0xff


// My typeDefs

typedef unsigned char uint_8;             // New name for unsigned char as uint_8    
typedef signed char sint_8;               // New name for signed char as sint_8    

typedef unsigned short uint_16;            // New name for unsigned short as uint_16               
typedef signed short sint_16;              // New name for signed short as sint_16      

typedef unsigned long uint_32;             // New name for unsigned long as uint_32      
typedef signed long sint_32;               // New name for signed long as sint_32

typedef unsigned long long uint_64;        // New name for unsigned long long as uint_64   
typedef signed long long sint_64;          // New name for signed long long as sint_64   

typedef float float_32;          // New name for float as float_32  
typedef double float_64;         // New name for double as float_64  
typedef long double float_96;    // New name for long double as float_96 
 

#endif /* STD_MACROS_H_ */