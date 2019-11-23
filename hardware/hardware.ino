#include <LSM6DS0Sensor.h>

#if defined(ARDUINO_SAM_DUE)
#define DEV_I2C Wire1   //Define which I2C bus is used. Wire1 for the Arduino Due
#define SerialPort Serial
#else
#define DEV_I2C Wire    //Or Wire
#define SerialPort Serial
#endif

// Components.
LSM6DS0Sensor *AccGyr;

void setup() {
  // Led.
  pinMode(13, OUTPUT);

  // Initialize serial for output.
  SerialPort.begin(9600);
  
  // Initialize I2C bus.
  DEV_I2C.begin();

  // Initlialize components.
  AccGyr = new LSM6DS0Sensor(&DEV_I2C);
  AccGyr->Enable_X();
  AccGyr->Enable_G();
}

void loop() {
  // Led blinking.
  digitalWrite(13, HIGH);
  delay(250);
  digitalWrite(13, LOW);
  delay(250);

  // Read accelerometer and gyroscope.
  int32_t accelerometer[3];
  int32_t gyroscope[3];
  AccGyr->Get_X_Axes(accelerometer);
  AccGyr->Get_G_Axes(gyroscope);

  // Output data.
  SerialPort.println(sqrt(pow(accelerometer[0],2)+pow(accelerometer[1],2)+pow(accelerometer[2],2)));
  SerialPort.println(sqrt(pow(gyroscope[0],2)+pow(gyroscope[1],2)+pow(gyroscope[2],2)));
}
