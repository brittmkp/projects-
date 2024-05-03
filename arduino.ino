#include <MotorDriver.h>

#define SERIAL_PORT_SPEED 115200

#define RC_CH1_INPUT 3 // receiver pin 3
#define RC_CH2_INPUT A5 // receiver pin A5

volatile uint16_t RC_VALUES[2];
volatile uint32_t RC_START[2];
volatile bool channel1Changed = false;
volatile bool channel2Changed = false;

MotorDriver m;

void setup() {
  Serial.begin(SERIAL_PORT_SPEED);
  pinMode(RC_CH1_INPUT, INPUT);
  pinMode(RC_CH2_INPUT, INPUT);

  attachInterrupt(digitalPinToInterrupt(RC_CH1_INPUT), READ_RC1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(RC_CH2_INPUT), READ_RC2, CHANGE);
}

void loop() {
  if (channel1Changed) {
    rc_read_values();
    process_channel_1_signal();
    channel1Changed = false;
  }

  if (channel2Changed) {
    rc_read_values();
    process_channel_2_signal();
    channel2Changed = false;
  }
}

void READ_RC1 (){
  Read_Input(0, RC_CH1_INPUT); 
}

void READ_RC2 (){
  Read_Input(1, RC_CH2_INPUT); 
}

void Read_Input(uint8_t channel, uint8_t input_pin) {
  if (digitalRead(input_pin) == HIGH){
    RC_START[channel] = micros();
  }
  else {
    uint16_t rc_compare = (uint16_t)(micros()- RC_START[channel]);
    RC_VALUES[channel] = rc_compare;

    if (channel == 0) {
      channel1Changed = true;
    } else if (channel == 1) {
      channel2Changed = true;
    }
  }
}

void rc_read_values(){
  noInterrupts();
  interrupts();
}

void process_channel_1_signal() {
  const uint16_t NEUTRAL_SIGNAL = 1484;
  const uint16_t MIN_SIGNAL = 1029;
  const uint16_t MAX_SIGNAL = 1939;

  int motorSpeed = map(RC_VALUES[0], MIN_SIGNAL, MAX_SIGNAL, 0, 255);

  if (RC_VALUES[0] > 1490) {
    m.motor(1, FORWARD, 255); 
    m.motor(4, FORWARD, 255); 
  } 
  else if (RC_VALUES[0] < 1480) {
    m.motor(1, BACKWARD, 255); 
    m.motor(4, BACKWARD, 255); 
  } 
  else {
    m.motor(1, RELEASE, 0); 
    m.motor(4, RELEASE, 0); 
  }
}

void process_channel_2_signal() {
  const uint16_t MIN_SIGNAL = 1029;
  const uint16_t MAX_SIGNAL = 1939;

  int motorSpeed = map(RC_VALUES[1], MIN_SIGNAL, MAX_SIGNAL, 0, 255);

  if (RC_VALUES[1] > 1480) {
    m.motor(3, FORWARD, 255); 
  } 
  else if (RC_VALUES[1] < 1470) {
    m.motor(3, BACKWARD, 255); 
  } 
  else {
    m.motor(3, RELEASE, 0); 
  }
}
