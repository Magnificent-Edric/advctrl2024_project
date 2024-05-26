// void setup() {
//    pinMode(13, OUTPUT); // объявляем пин 13 как выход
// }

// void loop() {
//    digitalWrite(13, HIGH); // включаем мотор

//    delay(1000); // ждем 1 секунду

//    digitalWrite(13, LOW); // выключаем мотор

//    delay(1000); // ждем 1 секунду
// }

/*
  Потенциометры на A0 и A1. Вывод в порт.
  Открой Инструменты/Плоттер для просмотра графика
*/
float arr[51] = {12.710276,  11.972771, 11.896508, 11.821296, 11.747112, 11.673938, 11.601749, 11.53053, 11.460258, 11.390914, 11.322482, 11.254945, 11.188282, 11.122479, 11.057518, 10.993383, 10.93006, 10.867533, 10.805784, 10.744803, 10.684574, 10.625082, 10.566315, 10.508259, 10.450901, 10.39423, 10.338234, 10.282899, 10.228212, 10.174167, 10.1207485, 10.067946, 10.015752, 9.964149, 9.913137, 9.8626995, 9.812825, 9.76351, 9.714742, 9.666512, 9.618811, 9.5716305};
// const int AIA = A1;
// const int AIB = A2;
const int AIA = 7;
const int AIB = 8;
byte speed = 255;

void setup() {
  // открываем порт для связи
  Serial.begin(9600);
  pinMode(AIA, OUTPUT);
  pinMode(AIB, OUTPUT);
  // Serial.print(arr);

  // udSerial = new Serial(this, Serial.list()[0], 9600);
  // output = createWriter ("dust_concentration.txt");

}

void backward(float n)
{
 analogWrite(AIA, 0);
 analogWrite(AIB, n);
}
void forward(float n)
{
 digitalWrite(AIA, n);
 digitalWrite(AIB, 0);
}

void loop() {
  // выводим оба значения 
  // через запятую в одну строку
  float fromPot=0.0;
  float v = 0.0;
  fromPot = analogRead(A0)/ 3.75;
  // Serial.print(analogRead(A0));
  Serial.println(fromPot);
  Serial.print('\n');
  // Serial.println(analogRead(A1));
  delay(10);
  // analogWrite(AIA, 0);
  if (fromPot >= 50 && fromPot <= 204){
    if (fromPot < 100 && fromPot >= 50){
      v = int(arr[204 - int(fromPot)] / 4);
      // digitalWrite(AIA, HIGH);
      analogWrite(AIA, v);
      analogWrite(AIB, 0);
    }
    else if (fromPot <= 140 && fromPot >= 100){
      v = int(arr[204 - int(fromPot)] / 4);
      // digitalWrite(AIA, HIGH);
      analogWrite(AIA, v);
      analogWrite(AIB, 0);
    }
    else if (fromPot > 140 &&  fromPot<= 204){
      v = int(arr[204 - int(fromPot)] / 4);
      // digitalWrite(AIA, HIGH);
      analogWrite(AIA, v);
      analogWrite(AIB, 0);
    }
    // else{
    //   v = arr[204 - int(fromPot)] / 4;
    // }
    // Serial.println(v);
    // Serial.println("\n");
    
  // delay(5);
    delay(10);
  //   backward(fromPot);
  }
  else{
    // digitalWrite(AIA, 0);
    // digitalWrite(AIB, 0);
    analogWrite(AIA, 0);
    analogWrite(AIB, 0);
  }
  // analogWrite(AIA, -0);
}
