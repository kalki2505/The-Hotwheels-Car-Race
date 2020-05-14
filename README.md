# The-Hotwheels-Car-Race
Kids, teens or adults; the people of all ages find the fast and furious HotWheels Cars fascinating to play with. The center motive of the kids while playing is “whose car is the fastest among the group” . To solve the problem, we decided to make a setup and an embedded system that basically helps two kids to race their cars and decide the winner. Our main focus is making the system with fun parts like LCD display, buzzer, lighting on the declaration of winner, etc so as to make the kids enjoy the race in their real time.

For the course "Embedded System Design" I had decided to make a project named "The Hotwheels Car Race". The project aimed at making an interactive environment for the kids to play with Hotwheels cars. 

For a car race between 2 Hotwheels cars (which are the fastest toy cars and measuring their speed efficiently is quite a difficult topic) and their speed will be compared. Also, both cars will start at the same time.

There are 3 modules in this project:

1. Before the race: The timer count down starts from 3.. 2.. 1.. 0 using a 7-segment display. A buzzer rings to indicate that start the race (here it is not implemented). If the car is before the starting line the Ultrasonic sensor will sense it and the race will be aborted when the buzzer will ring at high intensity.

2. During the race: The 2 IR sensor sensors kept at a fixed distance will note the time instance and using the distance formula Arduino code will calculate the speed of both the cars. 

3. After the race: The speed will be displayed on the LCD screen (here serial monitor) along with the winner.

Only these 3 modules were implemented though we had tried to make a complete design and have mentioned in the report due to unavailability of lab resources during COVID-19 lockdown period.
