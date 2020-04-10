#include <Servo.h>
#include <Keypad.h>

/* SERVO PART */
const int MIN_ANGLE = 80;
const int MAX_ANGLE = 160;

const int NUM_SERVO = 7;
Servo servoList[5];

const int servoPins[NUM_SERVO] = {13, 12, 11, 10, 9, 8, 7};

const int SERVO_PATTERN_LEN = 15;
const int servoPattern[SERVO_PATTERN_LEN][NUM_SERVO] = {
    {1, 1, 1, 0, 1, 1, 1},
    {0, 0, 1, 0, 0, 1, 0},
    {1, 0, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 0, 1, 1},
    {0, 1, 1, 1, 0, 1, 0},
    {1, 1, 0, 1, 0, 1, 1},
    {1, 1, 0, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 1, 0},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 0, 1, 0, 1},
    {1, 1, 1, 0, 1, 1, 1}};

/* KEYPAD PART */
const byte ROWS = 4;
const byte COLS = 4;

const char keypadPattern[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

const byte rowPins[ROWS] = {5, 4, 3, 2};
const byte colPins[COLS] = {A0, A1, A2, A3};

Keypad keypad = Keypad(makeKeymap(keypadPattern), rowPins, colPins, ROWS, COLS);

void setup()
{
    for (int i = 0; i < NUM_SERVO; i++)
    {
        Servo servo;
        servo.attach(servoPins[i]);
        servoList[i] = servo;
    }

    Serial.begin(9600);
}

void loop()
{
    char currKey = keypad.getKey();
    if (currKey)
    {
        if (currKey == '#')
        {
            tick();
        }
        else
        {
            displayDigit(getServoIndex(currKey));
        }
    }
}

void tick()
{
    int counter = 0;
    char currKey = 0;
    while (!currKey)
    {
        counter++;
        displayDigit(counter % 10);
        delay(1000);

        currKey = keypad.getKey();
    }
}

int getServoIndex(char currKey)
{
    switch (currKey)
    {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    case '*':
        return 10;
    case 'A':
        return 11;
    case 'B':
        return 12;
    case 'C':
        return 13;
    case 'D':
        return 14;
    }
}

void displayDigit(int index)
{
    if (index < 0 || index > SERVO_PATTERN_LEN)
    {
        return;
    }

    for (int i = 0; i < NUM_SERVO; i++)
    {
        servoList[i].write(MAX_ANGLE - ((MAX_ANGLE - MIN_ANGLE) * servoPattern[index][i]));
    }
}
