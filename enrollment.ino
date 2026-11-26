// كود تسجيل البصمة
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
    Serial.println("✅ الحساس جاهز!");
  } else {
    Serial.println("❌ خطأ - تأكد من التوصيل");
    while(1);
  }

  Serial.println("اكتب رقم ID (1-127) لتسجيل البصمة:");
}

void loop() {
  while(!Serial.available());
  int id = Serial.parseInt();
  if(id < 1 || id > 127) {
    Serial.println("رقم غير صحيح، اكتب بين 1 و 127");
    return;
  }

  Serial.println("ضع إصبعك على الحساس...");
  while(finger.getImage() != FINGERPRINT_OK);
  if(finger.image2Tz(1) != FINGERPRINT_OK) { Serial.println("خطأ في التصوير"); return; }

  Serial.println("ارفع إصبعك وضعه مرة ثانية...");
  delay(2000);
  while(finger.getImage() != FINGERPRINT_NOFINGER);
  while(finger.getImage() != FINGERPRINT_OK);
  if(finger.image2Tz(2) != FINGERPRINT_OK) { Serial.println("خطأ في التصوير"); return; }

  if(finger.createModel() != FINGERPRINT_OK) { Serial.println("البصمتان لم تتطابقا، حاول مرة ثانية"); return; }
  if(finger.storeModel(id) != FINGERPRINT_OK) { Serial.println("خطأ في الحفظ"); return; }

  Serial.print("✅ تم حفظ البصمة - ID: ");
  Serial.println(id);
  Serial.println("اكتب رقم آخر لتسجيل بصمة جديدة:");
}
