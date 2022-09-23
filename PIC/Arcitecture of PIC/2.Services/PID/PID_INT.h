/*************************************************/
/** Name :                                       */
/** Date :                                       */
/** Description : PID Interface                  */
/** Version     : 1.0 V                          */
/*************************************************/


#ifndef _PID_INT_H_
#define _PID_INT_H_

#define PID_AUTOMATIC          (1)
#define PID_MANUAL             (0)
#define PID_DIRECT             (0)
#define PID_REVERSE            (1)
#define PID_P_ON_M             (0)
#define PID_P_ON_E             (1)


/** Description :                                                 */
/* Initialize Timer 5                                             */
void PID_vidInit();


/** Description :                                                 */
/*  clamps the output to a specific range. 0-255 by default, but  */
/*   it's likely the user will want to change this depending on   */
/*   the application                                              */
void PID_vidSetOutputLimits(float Min, float Max);


/** Description :                                                 */
/*  sets PID to either Manual (0) or Auto (non-0)                 */
void PID_vidSetMode(int Mode);

/** Description :                                                 */
/* performs the PID calculation.  it should be                    */
/*   called every time loop() cycles. ON/OFF and                  */
/*   calculation frequency can be set using SetMode               */
/*   SetSampleTime respectively                                   */
int PID_vidCompute();

/******************************************************************/
/************( available but not commonly used functions )*********/
/******************************************************************/


/** Description :                                                 */
/* While most users will set the tunings once in the              */
/*   constructor, this function gives the user the option         */
/*   of changing tunings during runtime for Adaptive control      */
void PID_vidSetTunings(float Kp, float Ki, float Kd, int POn);


/** Description :                                                       */
/* Sets the Direction, or "Action" of the controller. DIRECT            */
/*   means the output will increase when error is positive. REVERSE     */
/*   means the opposite.  it's very unlikely that this will be needed   */
/*   once it is set in the constructor.                                 */
void PID_vidSetControllerDirection(int Direction);



/** Description :                                                       */
/* sets the frequency, in Milliseconds, with which                      */
/*   the PID calculation is performed.  default is 100                  */
void PID_vidSetSampleTime(int NewSampleTime);


/**********/
void PID(float* Input, float* Output, float* Setpoint,
        float Kp, float Ki, float Kd, int POn, int ControllerDirection);
long  map(long x, long in_min, long in_max, long out_min, long out_max);



#endif