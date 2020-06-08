# Home_automation_using_GSM_Technology
I made this for semester project in university as electrical and computer engineering student from industrial control engineering stream.
The aim of this project is to control home appliances like fan, light, door and windows wirelessly using GSM Module without having to make physical contact. Compared to the old system the system has a great significance, if one can control every appliance of its home wirelessly using a text message from his mobile, it saves time, energy, and also the risk of different electrical dangers like electric shock since there is no physical contact. Cost saving of different switching materials that are being used in the old system is also saved and we avoid the risk of durability of the materials. 

The following are commands used to control the appliances through SMS.

R.NO.|Command.||       Function of the command.	         ||   Result of the command.
1)	 | ‘1’    ||          Used to turn on the fan.	     ||     Fan turned on!
2)	 | ‘2’    ||        	Used to turn off the fan.	     ||     Fan turned off!
3)	 | ‘3’    ||        	Used to turn on the light.     ||     Light turned on!
4)	 | ‘4’    ||        	Used to turn off the light.    ||     Light turned off!
5)	 | ‘5’    ||        	Used to unlock the door.	     ||     Door unlocked!
6)	 | ‘6’    ||        	Used to lock the door.	       ||     Door locked!
7)	 | ‘7’    ||        	Used to unlock the window.     ||    	Window unlocked!
8)	 | ‘8’    ||        	Used to lock  the window.	     ||     Window locked!
9)	 | ‘9’    ||        	Used to check device status.   ||    	“Replies according the status”.
10)	 | ‘0’    ||        	Used to show the help manual.  ||     “Shows possible commands with their function”.
11)	 | ‘a’    ||        	Used to turn on all equipment. ||    	“Replies according to the result”.
12)	 | ‘z’    ||        	Used to turn off all equipment.||    	“Replies according to the result”.
13)	 | ‘x’    ||        	access requesting code 'x'.    ||    	Access granted!

this uploaded code and design are only for simulation purpose for real hardware design changes need to be made on both hardware and code.
for hardware you just need connect gsm Tx to arduino Rx and gsm Rx to arduino Tx directly. from code things that need to be changed are those AT commands need to un commented in latest_code.ino file provided. 
