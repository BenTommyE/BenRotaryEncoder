/* Rotary encoder with attachInterrupt

Counts pulses from an incremental encoder. Taking also into account the 
direction and counts down when the rotor rotates in the other direction.
 
created 2014
by Ben-Tommy Eriksen
 
*/

volatile unsigned int counter = 0;

void setup() {
  Serial.begin (9600);
  attachInterrupt(0, ai0, RISING);
  attachInterrupt(1, ai1, RISING);
}

void loop() {
  Serial.println (counter);
}

void ai0()
{
  if(digitalRead(3)==LOW) {
    counter++;
  }else{
    counter--;
  }
}

void ai1()
{
  if(digitalRead(2)==LOW) {
    counter--;
  }else{
    counter++;
  }
}
