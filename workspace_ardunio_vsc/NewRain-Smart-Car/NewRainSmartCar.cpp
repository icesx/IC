#include <Arduino.h>
#include "AFMotor/AFMotor.h"
#include <servo/Servo.h>
#include "ultrasonic/Ultrasonic.h"
#include "stepcounter/stepcounter.h"
Ultrasonic uc(22, 23);
AF_DCMotor motor_r(MOTOR2_B);
AF_DCMotor motor_l(MOTOR1_A);
Servo myservo;
StepCounter stepcounter_l(INTERRUPT_NUM_0);
StepCounter stepcounter_r(INTERRUPT_NUM_1);
const int safeDistance = 20;
void servoReset()
{
	Serial.println("servoReset");
	myservo.write(90);
}
void forward()
{
	Serial.println("forward");
	motor_r.run(BACKWARD);
	motor_l.run(FORWARD);
	delay(10);
	servoReset();
}
void backward()
{
	Serial.println("backward");
	motor_r.run(FORWARD);
	motor_l.run(BACKWARD);
	delay(300);
	servoReset();
}
void turnLeft()
{
	Serial.println("turnLeft");
	motor_r.run(RELEASE);
	motor_l.run(BACKWARD);
	delay(300);
	servoReset();
}
void turnRight()
{
	Serial.println("turnRight");
	motor_r.run(FORWARD);
	motor_l.run(RELEASE);
	delay(200);
	servoReset();
}
void stop()
{
	Serial.println("stop");
	motor_r.run(RELEASE);
	motor_l.run(RELEASE);
}
void turn(int angle)
{
	Serial.print("to turn ");
	Serial.println(angle);
	if (angle > 90)
	{
		Serial.print("turn delay time is bigger than 90 ");
		turnLeft();
		stop();
	}
	else
	{
		Serial.print("turn delay time is smaller than 90 ");
		turnRight();
		stop();
	}
}
int turnPos = 90;
int distance = safeDistance;
void changeDirection()
{
	Serial.println("changeDirection");
	for (int pos = 0; pos <= 180; pos += 45)
	{
		myservo.write(pos);
		delay(300);
		int _distance = uc.distance();
		Serial.print("pos is ");
		Serial.print(pos);
		Serial.print(" distance is ");
		Serial.println(_distance);
		if (_distance < 10)
		{
			backward();
			break;
		}
		if (_distance > distance)
		{
			distance = _distance;
			turnPos = pos;
			Serial.print("turnPos is ");
			Serial.println(turnPos);
		}
	}
	if (turnPos != 90)
	{
		turn(turnPos);
	}
	else
	{
		backward();
	}
	turnPos = 90;
	distance = safeDistance;
}
void carRun()
{
	int distance = uc.distance();
	Serial.print("distance is ");
	Serial.print(distance);
	Serial.println("cm");
	if (distance > safeDistance)
	{
		forward();
	}
	else
	{
		stop();
		changeDirection();
	}
}
void testAnglePrtSencond()
{
	motor_r.run(FORWARD);
	delay(1000);
	motor_r.run(RELEASE);
}
void testTurnLeft()
{
	turnLeft();
}
void testTurnRight()
{
	turnRight();
}
void ir()
{
	attachInterrupt(2, changeDirection, LOW);
}
void setup()
{
	Serial.begin(115200);
	motor_r.setSpeed(180);
	motor_l.setSpeed(200);
	myservo.attach(9);
	servoReset();
}
void sameSpeed()
{
	int l = stepcounter_l.speed();
	int r = stepcounter_r.speed();
	Serial.print("left=");
	Serial.print(l);
	Serial.print("right=");
	Serial.print(r);
}
void loop()
{
	carRun();
	sameSpeed();
	delay(50);
	//	testTurnLeft();
}
