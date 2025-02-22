/*  21/Febrero/2025  PIXELBITS Studios General Software   9:51 P.M.

codigo creado en vivo para TWITCH de PIXELBITS Studios , en el cual
se da movimiento a diodo laser mediante el uso de servomotores  SG90
y un joystick sencillo de interfaz , se agrega funcion de aleatoriedad al pulsar un bnoton y 
funciones separadas de movimientos para X,Y , asi como indicadores lumionicos
con leds del valor de lectura en la resistencia del joystick y funcion de
encender diodo laser con boton del joystick .

MATERIALES :
diodo laser , 2 servomotores SG90 
4 resistencias 10k , LED RGB , led ambar
jouystick sencillo , Arduino NANO .


*/
#include <Servo.h>

Servo servoX;
Servo servoY;

int servopinX = 9;
int servopinY = 7;

int joysw = 3;//pin
int joyx = 0;//pin
int joyy = 1;//pin
int joyvalxx;
int joyvalyy;
int joyvalx;
int joyvaly;
int joyswestado = 1;
int joySwread;

int laser = 13;//pin
int laserestado = 0;
int btnRandom = 8 ;//pin
int btnRandomEstado = 1 ;
int btnRandomLectura;
int randomEstado = 0 ;

int azul = 4 ;//pin
int verde = 5 ;//pin
//int rojo = 13 ;//pin
int ledindicador =  6;//pin

void joylectura() {
  int joySwread = digitalRead(joysw);
  int joyreadx = analogRead(joyx);
  int joyready = analogRead(joyy);

  Serial.print("\t X : ");
  Serial.print(joyreadx);
  Serial.print("\t Y : ");
  Serial.print(joyready);
  Serial.print("\t SW : ");
  Serial.println(joySwread);
}

void joyswfunction(){
  int joySwread = digitalRead(joysw);
    delay(100);
    if(joySwread == 1 && joyswestado == 0){
      if(laserestado == 0){
        digitalWrite(laser , 1);
        laserestado = 1 ;
      }
      else{
        digitalWrite(laser, 0);
        laserestado = 0 ;
      }
    }
  joyswestado = joySwread;
}


void joyXmove(){
  joyvalxx = analogRead(joyx);
  joyvalx = map(joyvalxx,0, 1023,0,180);
  servoX.write(joyvalx);
  delay(20);

  if(joyvalxx >= 400 && joyvalxx <= 500){
    digitalWrite(ledindicador, 1);
    delay(10);
  }else{
    digitalWrite(ledindicador, 0);

  }
  

  if(joyvalxx <= 100){
    digitalWrite(azul, 1);
    delay(10);
  }else{
    digitalWrite(azul, 0);
    delay(10);
  }

  if(joyvalxx >= 800){
    digitalWrite(verde, 1);
    delay(10);
  }else{
    digitalWrite(verde, 0);
    delay(10);
  }

}

void joyYmove(){
  joyvalyy = analogRead(joyy);
  joyvaly = map(joyvalyy,0, 1023,0,180);
  servoY.write(joyvaly);
  delay(20);

  if(joyvalyy >= 400 && joyvalyy <= 500){
    digitalWrite(ledindicador, 1);
    delay(10);
  }else{
    digitalWrite(ledindicador, 0);

  }

  if(joyvalyy <= 100){
    digitalWrite(azul, 1);
    delay(10);
  }else{
    digitalWrite(azul, 0);
    delay(10);
  }

  if(joyvalyy >= 800){
    digitalWrite(verde, 1);
    delay(10);
  }else{
    digitalWrite(verde, 0);
    delay(10);
  }

}

void MovimientoRandom(){
   int anguloRandom = random(0, 180);

    int btnRandomLectura = digitalRead(btnRandom);
    delay(100);
    if(btnRandomLectura == 1 && btnRandomEstado == 0){
        servoX.write(anguloRandom);
        servoY.write(anguloRandom);
        delay(2000);
        randomEstado = 1 ;
      }
    btnRandomEstado = btnRandomLectura;
}

void parpadeoverde(){
  //for(int i = 0; i < 5 ; i++){
    digitalWrite(verde, 1);
    delay(100);
    digitalWrite(verde, 0);
    delay(500);
  //}
}

void setup() {
  Serial.begin(9600);
  servoX.attach(servopinX);  // attaches the servo on pin 9 to the Servo object
  servoY.attach(servopinY);
  pinMode(joysw, INPUT_PULLUP);
  pinMode(laser, OUTPUT);

  //pinMode(rojo , OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);

}

void loop() {
joylectura();
joyswfunction();
MovimientoRandom();
joyXmove();
joyYmove();
}
