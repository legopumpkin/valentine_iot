#include <Servo.h>

/*
 * Valeria's Valentine's Day Box
 * =============================
 * Northshore Christian Academy
 * 4th Grade
 * February 14th, 2017
 */

Servo myServo;

int const toggleSwitch = 2;
int const greenLight = 12;
int const redLight = 13;
int const openAngle = 0;
int const closedAngle = 95;
int onOff;

void setup() {
    myServo.attach(9);
    pinMode(toggleSwitch, INPUT);
    pinMode(greenLight, OUTPUT);
    pinMode(redLight, OUTPUT);
}

void loop() {
    onOff = digitalRead(toggleSwitch);
    if (onOff == LOW) {
        // The Box should close.
        myServo.write(closedAngle);
        // Make light Red.
        digitalWrite(redLight, HIGH);
        digitalWrite(greenLight, LOW);
    } else if (onOff == HIGH) {
        // The Box should open.
        myServo.write(openAngle);
        // Make light Green.
        digitalWrite(greenLight, HIGH);
        digitalWrite(redLight, LOW);
    }
    // Wait 100ms before checking again.
    delay(100);
}
