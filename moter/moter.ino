int BUTTON=19;
int LED=18;
int trigPin1 = 12;
int echoPin1 = 11;
int trigPin2 = 9;
int echoPin2 = 10;
int a=2;
int buttonStart=0;
void setup() {
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  pinMode(BUTTON,INPUT);
  pinMode(2,OUTPUT);//모터
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  
  pinMode(trigPin1, OUTPUT);  // 트리거 핀을 출력으로 설정
  pinMode(echoPin1, INPUT);  // 에코 핀을 입력으로 설정
  pinMode(trigPin2, OUTPUT);  // 트리거 핀을 출력으로 설정
  pinMode(echoPin2, INPUT);  // 에코 핀을 입력으로 설정
}

void loop() {
  onoff();
  
  
  
  digitalWrite(trigPin1, HIGH);
  delay(10);
  digitalWrite(trigPin1, LOW);
  float duration1 = pulseIn(echoPin1, HIGH);
  float distance1 = ((float) (340 * duration1) / 10000) / 2;

  Serial.print(distance1);
  Serial.print("cm");

  digitalWrite(trigPin2, HIGH);
  delay(10);
  digitalWrite(trigPin2, LOW);
  float duration2 = pulseIn(echoPin2, HIGH);
  float distance2 = ((float) (340 * duration2) / 10000) / 2;
  Serial.print(" ");
  Serial.print(distance2);
  Serial.println("cm");
  
  
  if(a==1){
    digitalWrite(3,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
  }else if (a!=1){
    digitalWrite(2,LOW);
    digitalWrite(5,LOW);
  }
}
void onoff(){
  buttonStart=digitalRead(BUTTON);
  Serial.print("button=");
  Serial.print(buttonStart);
  Serial.print(" a=");
  Serial.print(a);
  
  if(buttonStart == HIGH){
    a=(a%2)+1;
    delay(500);
  }
  if(a==1){
    digitalWrite(LED,HIGH);
  
  }
  else{
    digitalWrite(LED,LOW);
  }
  
}
