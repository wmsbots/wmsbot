#pragma config(Motor,  port1,           motor1,        tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           motor2,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           motor3,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           motor4,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           motor5,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           motor6,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           motor7,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           motor8,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           motor9,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          motor10,       tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
__        ____  __ ____     ____
\ \      / /  \/  / ___|   / ___|___  _ __ ___
 \ \ /\ / /| |\/| \___ \  | |   / _ \| '__/ _ \
  \ V  V / | |  | |___) | | |__| (_) | | |  __/
   \_/\_/  |_|  |_|____/   \____\___/|_|  \___|
*/

task main()	{


	while (true) {




		//////////////////////////////////////////////////////////
		//
		// DRIVE
		//


		// RIGHT SIDE

		motor[motor10] = vexRT[Ch3] * 1.27;


		// LEFT SIDE

		motor[motor1] = vexRT[Ch2] * 1.27;


		//////////////////////////////////////////////////////////
		//
		// COLLECTOR MECHANISM
		//

		// motors: collectleft, collectright
		//
		// Press 5U for foward. Release to stop
		// Press 5D for reverse. Release to stop
		// motors: collectleft & collectright

		// TODO: Validate that each motor is spinning in the correct direction
		//       If only one motor is needed, remove code for second motor

		if (vexRT[Btn5U] == 1) {
			motor[motor3] = 127;
		}
		else {
			motor[motor3] = 0;
		}

		if (vexRT[Btn5D] == 1) {
			motor[motor3] = -127;
		}
		else {
			motor[motor3] = 0;
		}


		//////////////////////////////////////////////////////////
		//
		// ELEVATOR
		//
		// Press 6U for foward. Release to stop
		// Press 6D for reverse. Release to stop
		// motors: elevateleft & elevateright


		if (vexRT[Btn6U] == 1) {
			motor[motor4] = 127;
		}
		else {
			motor[motor4] = 0;
		}

		if (vexRT[Btn6D] == 1) {
			motor[motor4] = -127;
		}
		else {
			motor[motor4] = 0;
		}


		//////////////////////////////////////////////////////////
		//
		// SHOOTER
		//
		// motors: shootleft, shootright

		// 7u to start
		// 7D to stop



		if (vexRT[Btn7U] == 1) {

			// Start the motors slowly

			// If Motor is not running, start it up

			motor[motor5] = 127;
			motor[motor6] = 127;

			/*
			if (getMotorVelocity(motor5) < 1) {
				int i;
				for (i=0; i<127; i=i+20) {
					motor[motor5] = i; //
					motor[motor6] = i; //

					// Max out Motor speed
					if (i > 100) {
						i = 127;
					}
				}
			}

			*/
		}

		if (vexRT[Btn7D] == 1) {

			// TODO: Do we need slowdown code?

			motor[motor5] = 0;
			motor[motor6] = 0;
		}


	} // END while (true)

} // END task main


/*

_|          _|                        _|
_|          _|    _|_|      _|_|_|  _|_|_|_|    _|_|    _|_|_|
_|    _|    _|  _|_|_|_|  _|_|        _|      _|    _|  _|    _|
  _|  _|  _|    _|            _|_|    _|      _|    _|  _|    _|
    _|  _|        _|_|_|  _|_|_|        _|_|    _|_|    _|    _|



_|      _|  _|        _|        _|  _|
_|_|  _|_|        _|_|_|    _|_|_|  _|    _|_|
_|  _|  _|  _|  _|    _|  _|    _|  _|  _|_|_|_|
_|      _|  _|  _|    _|  _|    _|  _|  _|
_|      _|  _|    _|_|_|    _|_|_|  _|    _|_|_|

There's No I in Team.

*/
