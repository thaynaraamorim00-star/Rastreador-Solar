# include <Servo.h> //Inclui biblioteca pra controlar o servo motor

Servo motorSolar;

//Pinos
const int ldrEsq = A0; //Sensor esquerdo
const int ldrDir = A1; //sensor direito
const int pinoServo = 9;

//Variáveis
int valEsq = 0;
int valDir = 0;
int posicao = 90; //Começa no meio
int tolerancia = 10; //Margem pra não ficar tremendo

void setup() {
motorSolar.attach(pinoServo); //Liga o servo no pino 9
motorSolar.write(posicao); // Move pra posição inicial
Serial.begin(9600);
}

void loop() {
    //Lê os sensores de luz
    valEsq = analogRead(ldrEsq);
    valDir = analogRead(ldrDir);

    //Ver valores no Monitor Serial
    Serial.print("Esq: "); Serial.print(valEsq);
    Serial.print("Dir: "); Serial.print(valDir);

    //Lógica de comparação
    if(abs(valEsq - valDir)>tolerancia) {
        //Se a esquerda tem mais luz que a direita, move pra esquerda
        if(valEsq > valDir) {
            posicao = posicao + 1;
        }
        else{
            //Se direita tem mais luz, move pra direita
            posicao = posicao - 1;
        }
    }
    //Motor só vai de 0 a 180 graus
    if(posicao > 180) { posicao = 180; }
    if(posicao < 0) { posicao = 0; }

    motorSolar.write(posicao);

    delay(15);
}