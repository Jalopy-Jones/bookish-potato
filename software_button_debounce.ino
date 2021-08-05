/******** Debouncing pushbuttons in software **********/

int switchPin = 8;
int ledPin = 11;
boolean lastButton = LOW;
boolean currentButton = LOW;
boolean ledLevel = 0;

void setup()
{
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

boolean debounce(boolean last)
{
  boolean current = digitalRead(switchPin);
  if(last != current)
  {
    delay(5);
    current = digitalRead(switchPin);
  }
  return current;
}

void loop ()
{
  currentButton = debounce(lastButton);
  if(lastButton == LOW && currentButton == HIGH)
  {
    ledLevel = ledLevel + 51;
  }
  lastButton = currentButton;
  if (ledLevel > 255) ledLevel = 0;
  analogWrite(ledPin, ledLevel);
}
