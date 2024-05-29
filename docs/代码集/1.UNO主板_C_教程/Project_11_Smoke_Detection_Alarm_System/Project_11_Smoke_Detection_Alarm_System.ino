//**********************************************************************************
/*  
 * 名称   : Smoke_Detection_Alarm_System
 * 功能   : 烟雾或可燃性气体控制LED和蜂鸣器
 * 作者   : http://www.keyes-robot.com/ 
*/
int item = 0;

void setup() {
  Serial.begin(9600); //设置串口波特率为9600
  pinMode(3, INPUT);  //模拟气体(MQ-2)传感器连接D3上，并设置为输入模式
  pinMode(4, OUTPUT); //将有源蜂鸣器连接到D4上，并设置为输出模式
  pinMode(5, OUTPUT);  //将LED连接到D5上，并设置为输出模式
}

void loop() {
  item = digitalRead(3); //读取模拟气体(MQ-2)传感器输出的数字信号
  Serial.println(item);  //串口打印模拟气体(MQ-2)传感器输出的数字信号
  if (item == 0) {  //检测到烟雾或可燃性气体
    digitalWrite(4, HIGH); //打开蜂鸣器
    digitalWrite(5, HIGH);  //打开LED
    delay(500);  //延迟 500ms
    digitalWrite(4, LOW);  //关闭蜂鸣器
    digitalWrite(5, LOW);  //关闭LED
    delay(500);  //延迟 500ms
  } else {  //未检测到烟雾或可燃性气体
    digitalWrite(4, LOW); //关闭蜂鸣器
    digitalWrite(5, LOW);  //关闭LED
  }
}
//**********************************************************************************