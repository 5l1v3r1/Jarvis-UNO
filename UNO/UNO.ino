const int white_pilot_light_pin = 7; 
const int buzzer_pin = 6;
volatile int white_pilot_light_state = 0;
volatile int buzzer_state = 0;

const int shake_pin = 12;
const int blaze_pin = 11;
const int discover_people_pin =10;

void setup(){
  pinMode(white_pilot_light_pin, OUTPUT);
  pinMode(buzzer_pin, OUTPUT);
  pinMode(shake_pin, INPUT);
  pinMode(blaze_pin, INPUT);
  pinMode(discover_people_pin, INPUT);
  Serial.begin(9600);
}

void white_pilot_light_control(int state){
  //state =HIGH or LOW
  digitalWrite(white_pilot_light_pin,state);  
}
void buzzer_control(int state){
  //state =HIGH or LOW
  digitalWrite(buzzer_pin,state);  
}

void loop(){
  if (white_pilot_light_state==0){
    white_pilot_light_control(LOW);
  }
  if (buzzer_state==0){
    buzzer_control(LOW);
  }else{
    //buzzer_control(LOW);
  }
  white_pilot_light_state = 0;
  buzzer_state =0;
  
  shake_monitor();
  discover_people();
  delay(500); // 1000 = 1 second
}

void  warn(){
  white_pilot_light_control(HIGH);
  white_pilot_light_state = 1;
  buzzer_control(HIGH);
  buzzer_state = 1;
}


void shake_monitor(){
  if(digitalRead(shake_pin) == HIGH){
    Serial.println("shake-");
    warn();
  }
}

void blaze(){
  if(digitalRead(blaze_pin) == HIGH){
  }
}

void discover_people(){
  if(digitalRead(discover_people_pin) == HIGH){
    Serial.println("discover_people-");
    warn();
  }
}

