/*
 * NKP_ONE Example Project
 * โปรเจกต์ตัวอย่างสำหรับทดสอบบอร์ด NKP_ONE
 * 
 * สิ่งที่โปรแกรมนี้ทำ:
 * 1. แสดงข้อความบน OLED
 * 2. ให้มอเตอร์หมุนไปข้างหน้าและหยุด
 * 3. ควบคุม Servo
 * 4. ส่งเสียง Beep
 * 5. อ่านค่าจาก Analog
 * 
 * วิธีใช้งาน:
 * - กดปุ่ม SW1 เพื่อเริ่มโปรแกรม
 * - ดูผลลัพธ์บนจอ OLED
 */

#include <NKP_ONE.h>

void setup() {
  // เริ่มต้น Serial สำหรับ Debug
  Serial.begin(115200);
  
  // เริ่มต้นบอร์ด NKP_ONE
  NKP_ONE();
  
  // แสดงข้อความต้อนรับ
  set_oled_clear();
  set_oled(0, 0, "NKP ONE");
  set_oled(0, 10, "Example");
  set_oled(0, 20, "Press SW1");
  
  // รอกดปุ่ม SW1
  IO15();
  
  // ส่งเสียง Beep เมื่อพร้อม
  beep();
  
  Serial.println("NKP_ONE Ready!");
}

void loop() {
  // ===== ส่วนที่ 1: แสดงข้อความบน OLED =====
  set_oled_clear();
  set_oled(0, 0, "Test 1/4");
  set_oled(0, 10, "OLED OK!");
  delay(2000);
  
  // ===== ส่วนที่ 2: ทดสอบมอเตอร์ =====
  set_oled_clear();
  set_oled(0, 0, "Test 2/4");
  set_oled(0, 10, "Motor Test");
  
  // เดินหน้า 2 วินาที
  set_oled(0, 20, "Forward...");
  motor(1, 70);
  motor(2, 70);
  delay(2000);
  
  // หยุด
  set_oled(0, 20, "Stop");
  motor(1, 0);
  motor(2, 0);
  delay(1000);
  
  // ===== ส่วนที่ 3: ทดสอบ Servo =====
  set_oled_clear();
  set_oled(0, 0, "Test 3/4");
  set_oled(0, 10, "Servo Test");
  
  // หมุนไป 0 องศา
  set_oled(0, 20, "0 degree");
  servo(1, 0);
  delay(1000);
  
  // หมุนไป 90 องศา
  set_oled(0, 20, "90 degree");
  servo(1, 90);
  delay(1000);
  
  // หมุนไป 180 องศา
  set_oled(0, 20, "180 degree");
  servo(1, 180);
  delay(1000);
  
  // กลับมา 90 องศา
  servo(1, 90);
  
  // ===== ส่วนที่ 4: อ่านค่า Analog =====
  set_oled_clear();
  set_oled(0, 0, "Test 4/4");
  set_oled(0, 10, "Analog Read");
  
  for (int i = 0; i < 10; i++) {
    int value = analog(A0);
    
    set_oled_clear();
    set_oled(0, 0, "Test 4/4");
    set_oled(0, 10, "A0 Value:");
    set_oled(0, 20, value);
    
    Serial.print("A0: ");
    Serial.println(value);
    
    delay(500);
  }
  
  // ===== เสร็จสิ้นการทดสอบ =====
  set_oled_clear();
  set_oled(0, 0, "All Tests");
  set_oled(0, 10, "Complete!");
  set_oled(0, 20, "Press SW1");
  
  beep();
  
  // รอกดปุ่ม SW1 เพื่อเริ่มใหม่
  IO15();
}

/*
 * ===== ตัวอย่างฟังก์ชันเพิ่มเติม =====
 * ลบ comment ออกเพื่อใช้งาน
 */

// ฟังก์ชันให้รถหลีกเลี่ยงสิ่งกีดขวาง
/*
void avoidObstacle() {
  int distance = analog(A0);
  
  if (distance < 500) {
    // เจอสิ่งกีดขวาง
    motor(1, 0);
    motor(2, 0);
    delay(500);
    
    // เลี้ยวซ้าย
    motor(1, -50);
    motor(2, 50);
    delay(1000);
  } else {
    // เดินหน้าปกติ
    motor(1, 70);
    motor(2, 70);
  }
}
*/

// ฟังก์ชันควบคุม Servo ด้วยปุ่มหมุน
/*
void controlServoWithKnob() {
  int knobValue = Knob();
  int angle = knobValue / 22.75;  // แปลงเป็น 0-180 องศา
  
  servo(1, angle);
  
  set_oled_clear();
  set_oled(0, 0, "Servo:");
  set_oled(0, 10, angle);
}
*/

// ฟังก์ชันตรวจสอบปุ่ม SW1
/*
void checkButton() {
  if (sw1() == 0) {
    set_oled_clear();
    set_oled(0, 0, "Button");
    set_oled(0, 10, "Pressed!");
    beep();
    delay(500);
  }
}
*/
