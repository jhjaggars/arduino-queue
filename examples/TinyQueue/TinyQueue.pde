#include <TinyQueue.h>

TinyQueue queue(10);

void setup()
{
  Serial.begin(9600);
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  queue.enqueue(4);
  queue.enqueue(5);
  queue.enqueue(6);
  queue.enqueue(7);
  queue.enqueue(8);
  queue.enqueue(9);
  queue.enqueue(10);
  queue.enqueue(11);
  queue.enqueue(12);
  
  Serial.print("Size of tq: ");
  Serial.println(queue.size());
  
  byte x = queue.dequeue();
  
  Serial.print("Byte received: ");
  Serial.println(x, DEC);
  
  Serial.print("Size of tq: ");
  Serial.println(queue.size());
  
  int s = queue.size();
  
  for( int i = 0; i < s; i++ )
  {
    x = queue.dequeue();
    Serial.print(i);
    Serial.print("] ");
    Serial.print("Byte received: ");
    Serial.println(x, DEC);
  }
  
  Serial.print("Size of tq: ");
  Serial.println(queue.size());
  
  x = queue.dequeue();
  
  Serial.print("Byte received: ");
  Serial.println(x, DEC);
}

void loop()
{
}

