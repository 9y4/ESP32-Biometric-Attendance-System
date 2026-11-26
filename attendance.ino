// كود نظام التحضير بالبصمة
// التوصيل: أحمر=3.3V | أصفر=GPIO16 | أبيض=GPIO17 | أسود=GND
#include <Adafruit_Fingerprint.h>

HardwareSerial fpSerial(2);
Adafruit_Fingerprint finger(&fpSerial);

void setup() {
  Serial.begin(115200);
  fpSerial.begin(57600, SERIAL_8N1, 16, 17);
  finger.begin(57600);
  delay(200);

  if (finger.verifyPassword()) {
    Serial.println("✅ نظام التحضير جاهز");
    Serial.println("ضع إصبعك لتسجيل الحضور...");
  } else {
    Serial.println("❌ خطأ - تأكد من التوصيل");
    while(1);
  }
}

void loop() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK) return;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK) return;

  p = finger.fingerSearch();
  if (p == FINGERPRINT_OK) {
    Serial.print("✅ تم التحضير - الطالب ID: ");
    Serial.println(finger.fingerID);
    delay(2000);
  } else {
    Serial.println("❌ بصمة غير معروفة");
    delay(1000);
  }
}
