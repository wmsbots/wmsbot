#pragma config(Motor,  port1,           dr,            tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           st1,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           st2,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           intake,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          dl,            tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
__        ___ _     _  ____              _
\ \      / (_) | __| |/ ___|__ _ _ __ __| |
 \ \ /\ / /| | |/ _` | |   / _` | '__/ _` |
  \ V  V / | | | (_| | |__| (_| | | | (_| |
   \_/\_/  |_|_|\__,_|\____\__,_|_|  \__,_|


dr = port 1
dl -= port 2

Weston Middle School
*/

task main()	{

	while (true) {

		int shooterSpeed = 127;

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
			motor[dl]  = 0;                // Stop the left motor (cancel noise)
		}

		if(abs(vexRT[Ch2]) > threshold)         // If the right joystick is greater than or less than the threshold:
		{
			motor[dr] = (vexRT[Ch2]);
		}
		else                                    // If the right joystick is within the threshold:
		{
			motor[dr] = 0;                // Stop the right motor (cancel noise)
		}

		// SHOOTERS

		if (vexRT[Btn6U] == 1) {
		motor[st1] = shooterSpeed;
		motor[st2] = shooterSpeed;
		} else {
		motor[st1] = 0;
		motor[st2] = 0;
		}





		// Hold 5U to drive elevator

		if (vexRT[Btn5U] == 1) {
			motor[intake] = 127;
			} else {

			// If 5U isn't pressed
			// check for 5D which is
			// reverse. If neither, turn off.

			if (vexRT[Btn5D] == 1) {
				motor[intake] = -127;
				} else {
				motor[intake] = 0;
			}
		}
	}
}
