#pragma config(Sensor, dgtl1,  opsedrive,      sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  ultrasonicright, sensorSONAR_inch)
#pragma config(Motor,  port1,           forklift,      tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           dfr,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           dfl,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           mpincerl,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           mthrowerl,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           mthrowerr,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           mpincerr,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           drr,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           drl,           tmotorVex393_MC29, openLoop, reversed)
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
  SensorValue[opsedrive]=0;

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
	motor[dfl]=120;
	motor[dfr]=120;
	motor[drl]=120;
	motor[drr]=120;
}
task driveStop()
{
	motor[dfl]=0;
	motor[dfr]=0;
	motor[drl]=0;
	motor[drr]=0;
}
task autonomous()
{
  // ..........................................................................
	startTask(driveForward);
	waitUntil(SensorValue[opsedrive] >= 1080);
	startTask(driveStop);
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
task forkliftCheckUp()
{
	if(vexRT[Btn7U]==1)                                           // Add
	{                                                             // Limit Switch
		motor[forklift]=120; //Raises forklift while 7U is pressed
	}
	else if(vexRT[Btn7U]==0 && vexRT[Btn7D]==0)
	{
		motor[forklift]=0; //Stop forklift
	}

}

task forkliftCheckDown()
{
		if(vexRT[Btn7D]==1)
	{
		motor[forklift]=-120; //Lowers forklift while 6D is pressed
	}
	else if(vexRT[Btn7D]==0 && vexRT[Btn7U]==0)
	{
		motor[forklift]=0; //Stops forklift
	}
}

task mpincerCheckIn()
{
	if(vexRT[Btn6U]==1)
	{
		motor[mpincerl]=120; //Lowers forklift while 6D is pressed
		motor[mpincerr]=120;
	}
	else if(vexRT[Btn6D]==0 && vexRT[Btn6U]==0)
	{
		motor[mpincerr]=0; //Stop thrower
		motor[mpincerl]=0;
	}
}

task mpincerCheckOut()
{
	if(vexRT[Btn6D]==1)
	{
		motor[mpincerl]=-120; //Extrudes pincer while 6D is pressed
		motor[mpincerr]=-120;
	}
	else if(vexRT[Btn6D]==0 && vexRT[Btn6U]==0)
	{
		motor[mpincerl]=0; //Stops pincer
		motor[mpincerr]=0;
	}
}

task mthrowerCheckUp()
{
	if(vexRT[Btn5U]==1)
	{
		motor[mthrowerl]=120; //Raises thrower whBtn7U is pressed
		motor[mthrowerr]=120;
	}
	else if(vexRT[Btn5U]==0 && vexRT[Btn5D]==0)
	{
		motor[mthrowerl]=0; //Stop thrower
		motor[mthrowerr]=0;
	}
}

task mthrowerCheckDown()
{
	if(vexRT[Btn5D]==1)
	{
		motor[mthrowerl]=0;
		motor[mthrowerr]=0;
	}
	else if(vexRT[Btn5D]==0 && vexRT[Btn5U]==0)
	{
		motor[mthrowerl]=0;
		motor[mthrowerr]=0;
	}
}


task usercontrol()
{
  // User control code here, inside the loop

  while (true)
  {
			//Right side of the robot is controlled by the right joystick, Y-axis
	    motor[dfr] = vexRT[Ch2];
	    motor[drr]  = vexRT[Ch2];
	    //Left side of the robot is controlled by the left joystick, Y-axis
	    motor[dfl] = vexRT[Ch3];
	    motor[drl]  = vexRT[Ch3];

			startTask(forkliftCheckUp);

			startTask(forkliftCheckDown);

			startTask(mpincerCheckIn);

			startTask(mpincerCheckOut);

			startTask(mthrowerCheckUp);

			startTask(mthrowerCheckDown);

    // ........................................................................


  }
}


/*
flip motors port 1 & 5
claw left port 3 & 4
claw right port 9 & 10
pinion rack port 2
2 motor drive
*/
