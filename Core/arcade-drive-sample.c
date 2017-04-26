#define DEADBAND(n, t)    ((abs(n) > (t))? (n): 0)
#define BOUND(n, lo, hi)   (((n) < (lo))? lo: ((n) > (hi))? (hi): (n))

while(true)                            // Infinite loop:
{
    getJoystickSettings(joystick);

    int drivePower = DEADBAND(joystick.joy1_y1, deadZone)*100/128;
    int turnPower = DEADBAND(joystick.joy1_x1, deadZone)*100/128;

    motor[driveL] = BOUND(drivePower + turnPower, -100, 100);
    motor[driveR] = BOUND(drivePower - turnPower, -100, 100);

    wait1Msec(100);
}
