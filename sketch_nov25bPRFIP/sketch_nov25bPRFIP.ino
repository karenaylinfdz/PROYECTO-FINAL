int val = 0;
void setup()
{ 
  Serial.begin(9600);
  pinMode(2,INPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
}
void loop()
{
    // ------------------------------------
    // 1) LECTURA DE COMANDOS DESDE VISUAL
    // ------------------------------------
    if (Serial.available() > 0)
    {
        String cmd = Serial.readStringUntil('\n');
        cmd.trim();

        if (cmd == "AON")  digitalWrite(5, HIGH);
        if (cmd == "AOFF") digitalWrite(5, LOW);

        if (cmd == "BON")  digitalWrite(6, HIGH);
        if (cmd == "BOFF") digitalWrite(6, LOW);

        if (cmd == "CON")  digitalWrite(7, HIGH);
        if (cmd == "COFF") digitalWrite(7, LOW);
    }

 // 2) LECTURA SENSOR Y SECUENCIA AUT.

val = digitalRead(2);

    if (val == 0)
    {
        ejecutarSecuencia();
    }
}
void ejecutarSecuencia()
{   
    digitalWrite(8,HIGH);
    Serial.println(1);
    delay(500);
    digitalWrite(9,HIGH);
    Serial.println(2);
    delay(500);
    digitalWrite(10,HIGH);
    Serial.println(3);
    delay(500);
    digitalWrite(3,HIGH);
    Serial.println(4);
    delay(500);
    digitalWrite(4,HIGH);
    Serial.println(5);
    delay(500);
  
    digitalWrite(8,LOW);
    Serial.println(-1);
    delay(500);
    digitalWrite(9,LOW);
    Serial.println(-2);
    delay(500);
    digitalWrite(10,LOW);
    Serial.println(-3);
    delay(500);
    digitalWrite(3,LOW);
    Serial.println(-4);
    delay(500);
    digitalWrite(4,LOW);
    Serial.println(-5);
    delay(500);
  
 
}

