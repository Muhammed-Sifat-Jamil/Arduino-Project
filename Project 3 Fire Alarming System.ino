int gas_sensor=A0,flame_sensor=7,buzzer=5;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  pinMode(flame_sensor,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(!digitalRead(flame_densor)){
  Serial.print("Fire Detected");
  digitalWrite(buzzer,HIGH);
}
else{
  Serial.print("No Fire Detected")
  digitalWrite(buzzer,LOW);
  }
   if(analogRead(A0)>230){
    Serial.print(" Smoke Detected");
    digitalWrite(buzzer,HIGH);

   }
   else{
    Serial.print (" Smoke not Detected");
    digitalWrite(buzzer,LOW);
   }
   Serial.println("");

}
