#pragma config(Sensor, dgtl1,  rightSonar,     sensorSONAR_mm)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  pincerEncoder,  sensorRotation)
#pragma config(Motor,  port2,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           dr,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           mpincerl,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           forklift1,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           forklift2,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           mpincerr,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           dl,            tmotorVex269_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
task driveForward()
{
	motor[dl]=120;	
	motor[dr]=120;
}

task driveStop()
{
	motor[dl]=-120;	
	motor[dr]=-120;
}

task autonomous()
{
  // ..........................................................................
	int distance = 1080;
	int	sValue = 0;
	
	while(sValue < 720) // While the right encoder is less than distance:
  {
   sValue = SensorValue[rightEncoder] ;
	 motor[mpincerl]=120;
	 motor[mpincerr]=120;
  }
	motor[mpincerl]=0;
	motor[mpincerr]=0;
	
	
  sValue = 0;
  while(sValue < distance) // While the right encoder is less than distance:
  {
  	sValue = SensorValue[rightEncoder] ;
		startTask(driveForward);
  }
  
	startTask(driveStop);
	if(SensorValue[rightSonar] > 12)
	{
		while(sValue < 1440) // While the right encoder is less than distance:
	  {
	   sValue = SensorValue[rightEncoder] ;
		 motor[dl]=120;
		 motor[dr]=-120;
	  }
	}
	else if(SensorValue[rightSonar] <= 12)
	{
		while(sValue < 1440) // While the right encoder is less than distance:
	  {
	   sValue = SensorValue[rightEncoder] ;
		 motor[dl]=-120;
		 motor[dr]=120;
		}
	}
	motor[mpincerl]=0;
	motor[mpincerr]=0;

		
	while(sValue < 480) // While the right encoder is less than distance:
  {
  	sValue = SensorValue[rightEncoder] ;
	
  }
	
	// ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
int speed = 120;

int toggleswitch = 0;

task toggleToggleSwitch()
{
	if(vexRT[Btn8D]==1)
	{
		if(toggleswitch==0)
		{
			toggleswitch = 1;	
		}
		else if(toggleswitch==1)
		{
			toggleswitch = 0;
		}
	}
}

task forklift1CheckUp()
{
	if(toggleswitch == 0)
	{
		if(vexRT[Btn5U]==1)
		{
			motor[forklift1]=speed; //Raises forklift while 6U is pressed
		}
		else if(vexRT[Btn5U]==0 && vexRT[Btn5D]==0)
		{
			motor[forklift1]=0; //Stop thrower
		}
	}
}

task forklift1CheckDown()
{
	if(toggleswitch==0)
	{
		if(vexRT[Btn5D]==1)
		{
			motor[forklift1]=-speed; //Lowers forklift while 6D is pressed
		}
		else if(vexRT[Btn5D]==0 && vexRT[Btn5U]==0)
		{
			motor[forklift1]=0; //Stop thrower
		}
	}
}

task forklift2CheckUp()
{
	if(toggleswitch == 1)
	{
		if(vexRT[Btn5U]==1)
		{
			motor[forklift2]=speed; //Raises forklift while 6U is pressed
		}
		else if(vexRT[Btn5U]==0 && vexRT[Btn5D]==0)
		{
			motor[forklift2]=0; //Stop thrower
		}
	}
}

task forklift2CheckDown()
{
	if(toggleswitch==1)
	{
		if(vexRT[Btn5D]==1)
		{
			motor[forklift2]=-speed; //Lowers forklift while 6D is pressed
		}
		else if(vexRT[Btn5D]==0 && vexRT[Btn5U]==0)
		{
			motor[forklift2]=0; //Stop thrower
		}
	}
}

task mpincerIn()
{
	if(vexRT[Btn6U]==1)
	{
		motor[mpincerl]=speed; //Lowers forklift while 6D is pressed
		motor[mpincerr]=speed;
	}
	else if(vexRT[Btn6D]==0 && vexRT[Btn6U]==0)
	{
		motor[mpincerl]=0; //Stop thrower
		motor[mpincerr]=0;
	}
}

task mpincerOut()
{
	if(vexRT[Btn6D]==1)
	{
		motor[mpincerl]=-speed; //Lowers forklift while 6D is pressed
		motor[mpincerr]=-speed;
	}
	else if(vexRT[Btn6D]==0 && vexRT[Btn6U]==0)
	{
		motor[mpincerl]=0; //Stop thrower
		motor[mpincerr]=0;
	}
}
task usercontrol()
{
  // User control code here, inside the loop

  while (true)
  {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
				// Used to filter out joystick abberations
				int threshold = 10;
				//////////////////////////////////////////////////////////
				//
				// DRIVE
				//
				// This code has filtering in place
				// Because the joystick returns a value that is not always
				// exactly zero.
				//
				// Because of this, the Cortex makes a whining sound
				// because the drive motors are being triggered
				// with values less than 10
				//
				// By testing if the joystick is within the threshold
				// We can turn off the motors and stop the noise
				// and power drain

				if(abs(vexRT[Ch3]) > threshold)         // If the left joystick is greater than or less than the threshold:
				{
					motor[dl]  = (vexRT[Ch3] );
				}
				else                                    // If the left joystick is within the threshold:
				{
					motor[dl]  = (0);
				}
				if(abs(vexRT[Ch2]) > threshold)         // If the right joystick is greater than or less than the threshold:
				{
					motor[dr] = (vexRT[Ch2]);
				}
				else                                    // If the right joystick is within the threshold:
				{
					motor[dr] = 0;                				// Stop the right motor (cancel noise)
				}

			startTask(toggleToggleSwitch);
			
			startTask(forklift1CheckUp);

			startTask(forklift1CheckDown);
			
			startTask(forklift2CheckUp);
			
			startTask(forklift2CheckDown);
			
			startTask(mpincerIn);
			
			startTask(mpincerOut);

			//...................................................


  }
}

