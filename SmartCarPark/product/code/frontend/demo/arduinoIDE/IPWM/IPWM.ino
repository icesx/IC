int potpin = 5; //定义模拟接口0
int ledpin = 11; //定义数字接口11（PWM 输出）
int val = 0; // 暂存来自传感器的变量数值
void setup()
{
  pinMode(ledpin, OUTPUT); //定义数字接口11 为输出
  Serial.begin(9600);//设置波特率为9600
  //注意：模拟接口自动设置为输入
}
void loop()
{
  val = analogRead(potpin); // 读取传感器的模拟值并赋值给val
  int v=map(val,0,1023,0,500);//把0-1023区间的数映射到0-500的数，其实可以理解成比例关系,500 is max voltage is 
  Serial.println((float)v/100.00);//显示val 变量
  analogWrite(ledpin, val / 4); // 打开LED 并设置亮度（PWM 输__________出最大值255）
  delay(10);//延时0.01 秒
}
