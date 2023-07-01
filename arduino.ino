const int trigger1 = 2; // Trigger pin of 1st Sensor
const int echo1 = 3;    // Echo pin of 1st Sensor
const int trigger2 = 4; // Trigger pin of 2nd Sensor
const int echo2 = 5;    // Echo pin of 2nd Sensor
void setup()
{
    Serial.begin(9600);
    pinMode(trigger1, OUTPUT);
    pinMode(echo1, INPUT);
    pinMode(trigger2, OUTPUT);
    pinMode(echo2, INPUT);
}

void calculate_distance(int trigger, int echo)
{
    digitalWrite(trigger, LOW);

    8

        delayMicroseconds(2);
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);

    time_taken = pulseIn(echo, HIGH);
    dist = time_taken * 0.034 / 2;
    if (dist > 50)
        dist = 50;
}

calculate_distance(trigger1, echo1);
distL = dist; // get distance of left sensor
calculate_distance(trigger2, echo2);
distR = dist; // get distance of right sensor

if ((distL > 40 && distR > 40) && (distL < 50 && distR < 50))
{
    Serial.println("Play/Pause");
    delay(500);
}
if ((distL > 40 && distL < 50) && (distR == 50))
{
    Serial.println("Rewind");
    delay(500);
}

if ((distR > 40 && distR < 50) && (distL == 50))
{
    Serial.println("Forward");
    delay(500);
}

// Lock Left - Control Mode
if (distL >= 13 && distL <= 17)

    9

    {
        delay(100); // Hand Hold Time
        calculate_distance(trigger1, echo1);
        distL = dist;
        if (distL >= 13 && distL <= 17)
        {
            Serial.println("Left Locked");
            while (distL <= 40)
            {
                calculate_distance(trigger1, echo1);
                distL = dist;
                if (distL < 10) // Hand pushed in
                {
                    Serial.println("Vup");
                    delay(300);
                }
                if (distL > 20) // Hand pulled out
                {
                    Serial.println("Vdown");
                    delay(300);
                }
            }
        }
    }