/* 
    Author: Rhythm Winicour-Freeman
    File: motor.h
    Description: 
*/
#ifndef MOTOR_H
#define MOTOR_H

/* Function Prototypes */
void motorDriverBoardInit(void);
void motorRotate(int angle, int rpm, int* currentAngle);

/* Bit Fields */
// #define MOTOR_IN1_ON (1U << 8)
// #define MOTOR_IN2_ON (1U << 10)
// #define MOTOR_IN3_ON (1U << 2)
// #define MOTOR_IN4_ON (1U << 3)

#endif /* MOTOR_H */