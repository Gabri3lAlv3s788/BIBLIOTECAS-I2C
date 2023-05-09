//=============================================================================================================================================
// ---------- Biblioteca ----------
#include <Wire.h>


//--- Endereços HEX de registro do giroscópio
#define Gyro_gX0 0x28
#define Gyro_gX1 0x29
#define Gyro_gY0 0x2A
#define Gyro_gY1 0x2B
#define Gyro_gZ0 0x2C
#define Gyro_gZ1 0x2D

int Gyro = 0x69; //Endereço HEX do giroscópio

// ---------- Variáveis auxiliares ----------
int gX0, gX1, gX_out;
int gY0, gY1, gY_out;
int gZ0, gZ1, gZ_out;
float Xg, Yg, Zg;
float angleX, angleY, angleZ, angleXc, angleYc, angleZc;

unsigned long start, finished, elapsed;
float dt = 0.015;



//=============================================================================================================================================
// ---------- VOID SETUP ----------
void setup()
{
  //Inicia a biblioteca e determina a velocidade do monitor serial
  Wire.begin();
  Serial.begin(9600);
  delay(100);

  //Conexão inicial com o giroscópio - variável Gyro declarada com seu endereço HEX
  Wire.beginTransmission(Gyro);
  Wire.write(0x20); // CTRL_REG1 - Ligou!!
  Wire.write(15);   // Modo normal: 15d - 00001111 bit
  Wire.endTransmission();

  Wire.beginTransmission(Gyro);
  Wire.write(0x23); // CTRL_REG4 - Sensibilidade, seleção de escala
  Wire.write(48);   // 2000dps: 48d - 00110000 bit
  Wire.endTransmission();
}
// ---------- Fim do setup ----------
