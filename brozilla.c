#pragma config(Motor,	 port1,						motor1,				 tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,	 port2,						motor2,				 tmotorVex393_MC29, openLoop)
#pragma config(Motor,	 port3,						motor3,				 tmotorVex393_MC29, openLoop)
#pragma config(Motor,	 port4,						motor4,				 tmotorVex393_MC29, openLoop)
#pragma config(Motor,	 port5,						motor5,				 tmotorVex393_MC29, openLoop)
#pragma config(Motor,	 port6,						motor6,				 tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,	 port7,						motor7,				 tmotorVex393_MC29, openLoop)
#pragma config(Motor,	 port8,						motor8,				 tmotorVex393_MC29, openLoop)
#pragma config(Motor,	 port9,						motor9,				 tmotorVex393_MC29, openLoop)
#pragma config(Motor,	 port10,					motor10,			 tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard							 !!*//

/*
____					 ______ _ _
| __ ) _ __ ___|__	(_) | | __ _
|	 _ \| '__/ _ \ / /| | | |/ _` |
| |_) | | | (_) / /_| | | | (_| |
|____/|_|	 \___/____|_|_|_|\__,_|

*/

task main()	{

	/*
	int intakeButtonToggleState = 0;
	int intakeButtonPressed = 0;
	*/

	int shooterButtonToggleState = 0;
	int shooterButtonPressed = 0;

	int shootMotorSpeed = 100;

	while (true) {

		/*
		Motor 1 = right side drive
		Motor 2 = elevator. toggle and reverse
		Motor 6 = intake. toggle and reverse

		Motor 3 and 4 : shooter right side
		Motor 8 and 9 : shooter left side

		Motor 10 = left side drive
		*/


		//////////////////////////////////////////////////////////
		//
		// DRIVE
		//


		// RIGHT SIDE



		motor[motor10] = vexRT[Ch2] * 1.27;


		// LEFT SIDE

		motor[motor1] = vexRT[Ch3] * 1.27;




		//////////////////////////////////////////////////////////
		//
		// INTAKE MECHANISM
		//



		if (vexRT[Btn5U] == 1) {
			motor[motor2] = 127;
			motor[motor6] = 127;
		}  else {
			motor[motor2] = 0;
			motor[motor6] = 0;
	}




		// Reverse Intake Motors
		while (vexRT [Btn5D] == 1) {
			motor[motor2] = -64;
			motor[motor6] = -64;
		}

		// Stop Intake Motors
		while(vexRT[Btn5]==0)
		{
			motor[motor2]=0;
			motor[motor6]=0;
		}
*/

	}





	//////////////////////////////////////////////////////////
	//
	// SHOOTER MECHANISM

	if( vexRT[ Btn8U ] == 1 )
	{
		if( ! shooterButtonPressed )
		{
			// change the toggle state
			shooterButtonToggleState = 1 - shooterButtonToggleState;

			// Note the button is pressed
			shooterButtonPressed = 1;
		}
	}
	else
	{
		// the button is not pressed
		shooterButtonPressed = 0;
	}


	// Now do something with our toggle flag
	if( shooterButtonToggleState )
	{
		motor[motor3] = 100;
		motor[motor4] = 100;
		motor[motor8] = 100;
		motor[motor9] = 100;
	}
	else
	{
		motor[motor3] = 0;
		motor[motor4] = 0;
		motor[motor8] = 0;
		motor[motor9] = 0;
	} // END while (true)

} // END task main


/*

_|					_|												_|
_|					_|		_|_|			_|_|_|	_|_|_|_|		_|_|		_|_|_|
_|		_|		_|	_|_|_|_|	_|_|				_|			_|		_|	_|		_|
_|	_|	_|		_|						_|_|		_|			_|		_|	_|		_|
_|	_|				_|_|_|	_|_|_|				_|_|		_|_|		_|		_|



_|			_|	_|				_|				_|	_|
_|_|	_|_|				_|_|_|		_|_|_|	_|		_|_|
_|	_|	_|	_|	_|		_|	_|		_|	_|	_|_|_|_|
_|			_|	_|	_|		_|	_|		_|	_|	_|
_|			_|	_|		_|_|_|		_|_|_|	_|		_|_|_|

There's No I in Team.

*/
