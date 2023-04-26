#ifndef __INTERRUPT_TABLE
#define __INTERRUPT_TABLE

/* Contents of Interrupt Table (Non-Secure) */
void Non_Secure_Watchdog_Reset_Request_NS(void);
void Non_Secure_Watchdog_Interrupt_NS(void);
void S32K_Timer_Interrupt_NS(void);
void Timer0_Interrupt_NS(void);
void Timer1_Interrupt_NS(void);
void Dual_Timer_Interrupt_NS(void);
void Message_Handling_Unit0_CPU0_Interrupt_NS(void);
void Message_Handling_Unit1_CPU0_Interrupt_NS(void);
void Reserved_Interrupt_NS(void);

/* Contents of Interrupt Table (Secure) */

#endif  // interrupt_table.h