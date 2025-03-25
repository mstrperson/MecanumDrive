# Mecanum Drive Train
## MotorDirection (enum)
Determines whether positive input values translate into Clockwise or Anticlockwise rotation of the Motor.
### Values
- FORWARD
- REVERSED
  
## DCMotor (class)
Encapsulates Arduino Servo library to wrap PWM commands to send to a standard Motor Controller.
### Constructor
`DCMotor(unsigned int pin)`
- param pin: PWM enabled Digital Pin on the Arduino.
### Public Interface
- `void setSpeed(double speed)` takes double between -1 and 1 and sends the appropriate PWM signal to the Motor Controller.
- `void stop()` shortcut for `setSpeed(0)`
- `void setOrientation(MotorDirection direction)` sets the state flag that affects translation of speed input to PWM to reverse the motor direction.
- `void setPWMPulseRange(int min, int max)` takes PWM duty-cycle values in microseconds that correspond to *full-reverse* and *full-forward* used in the translation of percentage values for setting the motors speed.

## MecanumDrive (class)
Does all the math for translating 3 axis joystick input into DCMotor commands for a standard MecanumDrive Robot.
### Constructor
`MecanumDrive(unsigned int lfPin, unsigned int rfPin, unsigned int rbPin, unsigned int lbPin)`
- constructs four DCMotors on each of the PWM Enabled Digital Pins.
### Public Interface
- `void drive(double x, double y, double t)` Three Axis Joystick Input to drive the robot.
- `void setPWMPulseRange(int min, int max)` Passes down the PWM range to each DCMotor instance -- assumes all Motor Controllers are the same.
- `void setMotorOrientations(...)` Sets each of the 4 motor directions to account for left/right or front/back symetry.
