#define PIN_speakerPin 8

int flame_sensor_D = 12; // D indicate Digital , A indicate Analog
int mq4_sensor_D = 11;
int mq4_sensor_A = A5;

void setup() {
  Serial.begin(9600);
  pinMode(flame_sensor_D, INPUT);
  pinMode(mq4_sensor_D, INPUT);
  pinMode(mq4_sensor_A, INPUT);
  pinMode(PIN_speakerPin, OUTPUT);
}

void loop() {
  /* is_fire=1 when feel the flame ,else is_fire=0 */
  int is_flame = digitalRead(flame_sensor_D);
  /* mq4_D digital output by mq4 sensor, mq4_A analog output by mq4 sensor*/
  int mq4_value_D = digitalRead(mq4_sensor_D);
  int mq4_value_A = analogRead(mq4_sensor_A); //

  String str="Isframe="+String(is_flame)+",mq4_value_D="+String(mq4_value_D)+",mq4_value_A="+String(mq4_value_A);
  Serial.println(str); // send message to esp8266(nodemcu)(wifi moudle)

  if(is_flame==0 or mq4_value_D==0 or mq4_value_A>700){
    tone(PIN_speakerPin,30); 
    // tone(pin,frequency,duration)   pin:接口  frequency:频率 duration:持续时间
    delay(10);
//    noTone(PIN_speakerPin);
  }else{
    noTone(PIN_speakerPin);
  }
  delay(3000);
}
