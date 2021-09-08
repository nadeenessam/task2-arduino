#define LDR_1 A0
#define LDR_2 A1
const int LDR_Min=150;
const int buzzer = 9;

bool LDR1=LOW;
bool LDR2=LOW;

int PeopleNumber=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(analogRead(LDR_1)<LDR_Min && analogRead(LDR_2)>LDR_Min && LDR1==LOW && LDR2==LOW)
    LDR1=HIGH;
  if(analogRead(LDR_1)>LDR_Min && analogRead(LDR_2)<LDR_Min && LDR1==HIGH && LDR2==LOW)
   {
      while(analogRead(LDR_2)<LDR_Min)
      { } 
       PeopleNumber++;
       if(PeopleNumber>5){
        tone(buzzer, 1000); 
  delay(100000);           
  exit(0);     
       }
       Serial.println("People in room: " + (String)PeopleNumber);
       LDR1=LOW;
       LDR2=LOW;
   }
   
  
  if(analogRead(LDR_1)>LDR_Min && analogRead(LDR_2)<LDR_Min && LDR1==LOW && LDR2==LOW)
    LDR2=HIGH;

  if(analogRead(LDR_1)<LDR_Min && analogRead(LDR_2)>LDR_Min && LDR1==LOW && LDR2==HIGH)
   {
      while(analogRead(LDR_1)<LDR_Min)
      { }
      PeopleNumber=PeopleNumber>0?PeopleNumber-1:0;
      Serial.println("People in room: " + (String)PeopleNumber);
      LDR2=LOW;
      LDR1=LOW;
   }
}
