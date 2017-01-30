#include "CurieIMU.h"

void setup() {
  // Инициализируем COM-порт и IMU
  Serial.begin(115200);
  CurieIMU.begin();
  // Диапазон +/- 4g и +/- 125 градусов/с
  CurieIMU.setAccelerometerRange(4);
  CurieIMU.setGyroRange(125);
}

void loop() {
  float fAccelX, fAccelY, fAccelZ;
  float fOmegaX, fOmegaY, fOmegaZ;
  char sStr[128];
  // Читаем
  CurieIMU.readAccelerometerScaled(fAccelX, fAccelY, fAccelZ);
  CurieIMU.readGyroScaled(fOmegaX, fOmegaY, fOmegaZ);
  // Отправляем
  sprintf(\
    sStr, \
    "Acceleration (g) X: %4.1f Y: %4.1f Z: %4.1f | Omega (deg/s) X: %6.1f Y: %6.1f Z: %6.1f ", \
    fAccelX, fAccelY, fAccelZ, fOmegaX, fOmegaY, fOmegaZ\
    );
  Serial.println(sStr);
  delay(500);
}

