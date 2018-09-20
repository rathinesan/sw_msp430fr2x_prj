//#include <msp430.h> 

#include <drivers/MSP430FR2xx_4xx/driverlib.h>
/**
 * main.c
 */
int main(void)
{
    // Stop watchdog timer
    WDT_A_hold(WDT_A_BASE);

    // Set P1.0 to output direction
    GPIO_setAsOutputPin(
        GPIO_PORT_P1,
        GPIO_PIN0
        );
    
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P2,
                                          GPIO_PIN7);

    // Disable the GPIO power-on default high-impedance mode
    // to activate previously configured port settings
    PMM_unlockLPM5();

    while(1)
    {
        if(GPIO_getInputPinValue(GPIO_PORT_P2, GPIO_PIN7) == 0)
        {
            GPIO_setOutputHighOnPin(GPIO_PORT_P1,
                    GPIO_PIN0);
        }
        else
        {
        
            GPIO_setOutputLowOnPin(GPIO_PORT_P1,
                    GPIO_PIN0);
        }
    }
    
    return 0;
}
