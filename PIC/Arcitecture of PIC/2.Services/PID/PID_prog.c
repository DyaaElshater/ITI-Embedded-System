/*************************************************/
/** Name :                                       */
/** Date :                                       */
/** Description : PID Implementation             */
/*************************************************/

/**********************************************************************************************
 * Arduino PID Library - Version 1.2.1
 * by Brett Beauregard <br3ttb@gmail.com> brettbeauregard.com
 *
 * This Library is licensed under the MIT License
 **********************************************************************************************/

#include "Bit_Math.h"
#include "Std_types.h"

#include "DIO_INT.h"

#include "PID_INT.h"
#include "PID_CFG.h"
#include "PID_PRIV.h"


    f32 dispKp;                                // * we'll hold on to the tuning parameters in user-entered
    f32 dispKi;                                //   format for display purposes
    f32 dispKd;                                //

    f32 kp;                  // * (P)roportional Tuning Parameter
    f32 ki;                  // * (I)ntegral Tuning Parameter
    f32 kd;                  // * (D)erivative Tuning Parameter

    f32 *myInput;              // * Pointers to the Input, Output, and Setpoint variables
    f32 *myOutput;             //   This creates a hard link between the variables and the
    f32 *mySetpoint;           //   PID, freeing the user from having to constantly tell us
                              //   what these values are.  with pointers we'll just know.

    f32 outMin, outMax;
    f32 outputSum, lastInput;

    unsigned long lastTime;
    unsigned long SampleTime  = 100;

    int controllerDirection;
    int pOn;
    short inAuto=1;
    short pOnE;


 extern count;

 unsigned long millis(){
    return count;
 }
/* InitTimer2()****************************************************************
 *        intialize timmer 5 to simulate millis() of arduino
 ******************************************************************************/





/* Initialize()****************************************************************
 *        does all the things that need to happen to ensure a bumpless transfer
 *  from manual to automatic mode.
 ******************************************************************************/
void PID_vidInit(){

   outputSum = *myOutput;
   lastInput = *myInput;
   if(outputSum > outMax) outputSum = outMax;
   else if(outputSum < outMin) outputSum = outMin;
}
/* Compute() **********************************************************************
 *     This, as they say, is where the magic happens.  this function should be called
 *   every time "void loop()" executes.  the function will decide for itself whether a new
 *   pid Output needs to be computed.  returns true when the output is computed,
 *   false when nothing has been done.
 **********************************************************************************/
int PID_vidCompute(){

   unsigned long now =millis();
   unsigned long timeChange = (now - lastTime);
   //if(!inAuto) return 0;

   if(timeChange>=SampleTime){
      /*Compute all the working error variables*/
      float input = *myInput;
      float error = *mySetpoint - input;
      float dInput = (input - lastInput);
      float output;
      outputSum+= (ki * error);

      /*Add Proportional on Measurement, if P_ON_M is specified*/
      if(!pOnE) outputSum-= kp * dInput;

      if(outputSum > outMax) outputSum= outMax;
      else if(outputSum < outMin) outputSum= outMin;

      /*Add Proportional on Error, if P_ON_E is specified*/

      if(pOnE) output = kp * error;
      else output = 0;

      /*Compute Rest of PID Output*/
      output += outputSum - kd * dInput;

            if(output > outMax) output = outMax;
      else if(output < outMin) output = outMin;

            *myOutput = output;

      /*Remember some variables for next time*/
      lastInput = input;
      lastTime = now;
            return 1;
   }
   else return 0;
}

/* SetTunings(...)*************************************************************
 * This function allows the controller's dynamic performance to be adjusted.
 * it's called automatically from the constructor, but tunings can also
 * be adjusted on the fly during normal operation
 ******************************************************************************/
void PID_vidSetTunings(float Kpl, float Kil, float Kdl, int POn)
{
   float SampleTimeInSec = ((float)SampleTime)/1000;
   if (Kpl<0 || Kil<0 || Kdl<0) return;

   pOn = POn;
   pOnE = (POn == PID_PON);

   dispKp = Kp; dispKi = Ki; dispKd = Kd;


   kp = Kpl;
   ki = Kil * SampleTimeInSec;
   kd = Kdl / SampleTimeInSec;

  if(controllerDirection ==PID_CONTROLLER_DIRECTION)
   {
      kp = (0 - kp);
      ki = (0 - ki);
      kd = (0 - kd);
   }
}



/* SetSampleTime(...) *********************************************************
 * sets the period, in Milliseconds, at which the calculation is performed
 ******************************************************************************/
void PID_vidSetSampleTime(int NewSampleTime)
{
   if (NewSampleTime > 0)
   {
      float ratio  = (float)NewSampleTime
                      / (float)SampleTime;
      ki *= ratio;
      kd /= ratio;
      SampleTime = (unsigned long)NewSampleTime;
   }
}

/* SetOutputLimits(...)****************************************************
 *     This function will be used far more often than SetInputLimits.  while
 *  the input to the controller will generally be in the 0-1023 range (which is
 *  the default already,)  the output will be a little different.  maybe they'll
 *  be doing a time window and will need 0-8000 or something.  or maybe they'll
 *  want to clamp it from 0-125.  who knows.  at any rate, that can all be done
 *  here.
 **************************************************************************/
void PID_vidSetOutputLimits(float Min, float Max)
{
   if(Min >= Max) return;
   outMin = Min;
   outMax = Max;

   if(inAuto)
   {
           if(*myOutput > outMax) *myOutput = outMax;
           else if(*myOutput < outMin) *myOutput = outMin;

           if(outputSum > outMax) outputSum= outMax;
           else if(outputSum < outMin) outputSum= outMin;
   }
}

/* SetMode(...)****************************************************************
 * Allows the controller Mode to be set to manual (0) or Automatic (non-zero)
 * when the transition from manual to auto occurs, the controller is
 * automatically initialized
 ******************************************************************************/
void PID_vidSetMode(int Mode)
{
    short newAuto = (Mode == PID_MODE);
    if(newAuto && !inAuto)
    {  /*we just went from manual to auto*/
        PID_vidInit();
    }
    inAuto =millis()- newAuto;
}


/**********/
void PID(float* Input, float* Output, float* Setpoint,
        float Kp, float Ki, float Kd, int POn, int ControllerDirection)
{
    myOutput = Output;
    myInput = Input;
    mySetpoint = Setpoint;
    inAuto = 1;

    PID_vidSetOutputLimits(0, 255);                                //default output limit corresponds to
                                                                                                //the arduino pwm limits

    SampleTime = 100;                                                        //default Controller Sample Time is 0.1 seconds

    PID_vidSetControllerDirection(ControllerDirection);
    PID_vidSetTunings(Kp, Ki, Kd, POn);

    lastTime = millis()-SampleTime;
}

/* SetControllerDirection(...)*************************************************
 * The PID will either be connected to a DIRECT acting process (+Output leads
 * to +Input) or a REVERSE acting process(+Output leads to -Input.)  we need to
 * know which one, because otherwise we may increase the output when we should
 * be decreasing.  This is called from the constructor.
 ******************************************************************************/
void PID_vidSetControllerDirection(int Direction)
{
   if(inAuto && Direction !=controllerDirection)
   {
      kp = (0 - kp);
      ki = (0 - ki);
      kd = (0 - kd);
   }
   controllerDirection = Direction;
}
///////******************************************************
long map(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
////////////////////////////////////////////////////////////////////////////