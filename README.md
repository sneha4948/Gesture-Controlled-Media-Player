# Introduction
Gesture control can be defined as the ability to recognize and interpret movements of the human body in order to interact with and control a computer system without direct physical contact. The term “natural user interface” is becoming more commonly used to describe these interface systems, reflecting the general lack of any intermediate devices between the user and the system.

The concept behind the project is pretty simple. Two Ultrasonic (US) sensors were placed on top of our monitor and read the distance and it’s change between the monitor and our hand, recorded through Arduino. Based on this value of distance, certain actions were
performed through Python code. The PyAutoGUI library of Python was utilized to perform this task. It let our Python scripts control the mouse and keyboard to automate interactions with other applications. 

Documentation: https://pyautogui.readthedocs.io/en/latest/

# Working principle:
The commands from Arduino are sent to the computer through serial port (USB). This data is then read by python which is running on the computer and based on the read data certain key actions are performed - 
1. Play/Pause
2. Forward/Rewind 
3. Volume Up/Down
