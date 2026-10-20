#include "../inc/motor.h"
#include "../inc/gpio.h"
#include "../inc/systick.h"

/* Constants */
#define STEPS_PER_REV 4096

/* Helper Function Prototypes*/
void SetRPM(int rpm);
void halfStepOneStep(int step);
void halfStepAngle(int angle, int dir, int rpm);

void motorDriverBoardInit(void)
{
    // set all 4 pins for INx signals to output mode
    GPIOA_MODER |= MODER_PIN8_OUTPUT;
    GPIOA_MODER |= MODER_PIN10_OUTPUT;
    GPIOA_MODER |= MODER_PIN9_OUTPUT;
    GPIOA_MODER |= MODER_PIN3_OUTPUT;
}

void motorRotate(int angle, int rpm, int* currentAngle)
{
    int changeAngle = 0;
    changeAngle = angle - *currentAngle;
    if(changeAngle > 0) // clockwise
    {
        halfStepAngle(changeAngle, 0, rpm);
        *currentAngle = angle;
    } else if(changeAngle < 0) // counter clockwise
    {
        changeAngle = -(changeAngle);
        halfStepAngle(changeAngle, 1, rpm);
        *currentAngle = angle;
    }
}




void SetRPM(int rpm)
{
    systickDelay_ms(60000000/STEPS_PER_REV/rpm);
}

void halfStepOneStep(int step)
{
    switch(step)
    {
        case 0:
            GPIOA_ODR |= ODR_PIN8; // set
            GPIOA_ODR &= ~(ODR_PIN10); // reset
            GPIOA_ODR &= ~(ODR_PIN9); // reset
            GPIOA_ODR &= ~(ODR_PIN3); // reset
            break;
        case 1:
            GPIOA_ODR |= ODR_PIN8; // set
            GPIOA_ODR |= ODR_PIN10; // set
            GPIOA_ODR &= ~(ODR_PIN9); // reset
            GPIOA_ODR &= ~(ODR_PIN3); // reset
            break;
        case 2:
            GPIOA_ODR &= ~(ODR_PIN8); // reset
            GPIOA_ODR |= ODR_PIN10; // set
            GPIOA_ODR &= ~(ODR_PIN9); // reset
            GPIOA_ODR &= ~(ODR_PIN3); // reset
            break;
        case 3:
            GPIOA_ODR &= ~(ODR_PIN8); // reset
            GPIOA_ODR |= ODR_PIN10; // set
            GPIOA_ODR |= ODR_PIN9; // set
            GPIOA_ODR &= ~(ODR_PIN3); // reset
            break;
        case 4:
            GPIOA_ODR &= ~(ODR_PIN8); // reset
            GPIOA_ODR &= ~(ODR_PIN10); // reset
            GPIOA_ODR |= ODR_PIN9; // set
            GPIOA_ODR &= ~(ODR_PIN3); // reset
            break;
        case 5:
            GPIOA_ODR &= ~(ODR_PIN8); // reset
            GPIOA_ODR &= ~(ODR_PIN10); // reset
            GPIOA_ODR |= ODR_PIN9; // set
            GPIOA_ODR |= ODR_PIN3; // set
            break;
        case 6:
            GPIOA_ODR &= ~(ODR_PIN8); // reset
            GPIOA_ODR &= ~(ODR_PIN10); // reset
            GPIOA_ODR &= ~(ODR_PIN9); // reset
            GPIOA_ODR |= ODR_PIN3; // set
            break;
        case 7:
            GPIOA_ODR |= ODR_PIN8; // set
            GPIOA_ODR &= ~(ODR_PIN10); // reset
            GPIOA_ODR &= ~(ODR_PIN9); // reset
            GPIOA_ODR |= ODR_PIN3; // set
            break;
    }
}

void halfStepAngle(int angle, int dir, int rpm)
{
    int numSequences = (angle * 512) / 360; 

    for(int seq = 0; seq < numSequences; ++seq)
    {
        if(dir == 0) // clockwise
        {
            for(int step = 7; step >= 0; --step)
            {
                halfStepOneStep(step);
                //SetRPM(rpm);
                systickDelay_ms(100);
            }
        } else if(dir == 1) // counter clockwise
        {
            for(int step = 0; step <= 7; ++step)
            {
                halfStepOneStep(step);
                //SetRPM(rpm);
                systickDelay_ms(100);
            }
        } 
    }
}