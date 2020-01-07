import RPi.GPIO as GPIO
import time

led_pin = 17            
GPIO.setmode(GPIO.BCM)  
GPIO.setup(led_pin, GPIO.OUT)   
pwm = GPIO.PWM(led_pin, 100)    
pwm.start(0)  

try:
    while 1:                    
        for x in range(100):    
            pwm.ChangeDutyCycle(x) 
            sleep(0.01)    
            
        for x in range(100,0,-1): 
            pwm.ChangeDutyCycle(x)
            sleep(0.01)

except KeyboardInterrupt:
    pass      
     
pwm.stop()      
GPIO.cleanup()  