/*
  Copyright 2019 Google LLC

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

#include <Keyboard.h>


// On a Leonardo, [0,1,2,3,7] can be used for interrupts.

int ledPin = 13,
    audioPin = 2,
    videoPin = 3;

// state must be volatile
volatile byte ledState = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  // make pin an input and turn on the
  // pullup resistor so it goes high unless
  // connected to ground:
  pinMode(audioPin, INPUT_PULLUP);
  pinMode(videoPin, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(audioPin), toggleAudio, FALLING);
  attachInterrupt(digitalPinToInterrupt(videoPin), toggleVideo, FALLING);
  Keyboard.begin();  // current a no-op
}

void toggleAudio() {
  sendShifted('d');
}
void toggleVideo() {
  sendShifted('e');
}


volatile int lastTime = 0;
bool checkLast() {
  unsigned long now = millis();
  if (now - lastTime < 200) {
    return false;
  }
  lastTime = now;
  return true;

}

void sendShifted(char c) {
  if (!checkLast()) {
    return;
  }
  ledState = HIGH;
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(c);
  delay(200); // must be less than OS repeat interval but longer than debounce
  ledState = LOW;
  Keyboard.releaseAll();
}

void loop() {
  digitalWrite(ledPin, ledState);
}
