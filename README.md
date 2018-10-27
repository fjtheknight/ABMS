# AutomaticBroilerMonitoringSystem
An automatic monitoring system to raise broiler (with web app)

**PLEASE NOTE:
This was my first arduino/web project ever (built between 2016 and 2017), and my first project that involves coding (other than simple "projects" I've done to learn arduino basics). So, you will probably find every form of bad coding habits. The code is also very poorly commented. Therefore, I recommend reading this file and watching the videos to understand what this project is about. Thanks.**

## Story behind the project

We are a family of farmers and we were breeding some broiler. But the way we were breeding broiler was not efficient. Qualified workforce and equipment were lacking. The farm is located far from where we live.

Broiler farming is a very demanding activity and requires rigorous control of breeding parameters. Among these parameters there is:

* Temperature
* Humidity
* Circulating air speed
* Pressure
* Gas rates in the air (CO2, O2, H2S, CO...)

So I thought I should find a means to control these parameters. This means must be autonomous, user-friendly, available and not expensive

I also thought I must find a way to check the status of the farm anywhere and anytime, quickly and reliably, and make the project work in different conditions (no internet connection, no computer available) ...

So I made this automatic monitoring system to control the farm.

## How it works

### Arduino part

To build this project, I used an arduino mega board, temperature / humidity / pressure / gas sensors, an ethernet shield, an sd card, 3.2 inch LCD screen, 3g modem and a bunch of other stuff, and stored the necessary data in the sd card.

Basically, the user sets a new breeding cycle with necessary data (broiler age, number...). The system loads the optimal parameter values for given breeding cycle and compares them to current environment data given by sensors each time cycle, and then tries to correct environmental condition by activating correction systems to a certain degree.

Data is stored on an sd card in the current breeding cycle folder, and on an online database accessible through a web app so that you can access data whenever and wherever you are.

### Web app part

The web app part of the project was hosted on a free hosting service and is not currently used, so I faked some data for testing purposes

link: http://mmppmmll.getenjoyment.net/

data: available between 01-06-2017 and 07-06-2017 (dd-mm-yy)

## Videos

### ATB Challenge

[![Watch the video](https://i.imgur.com/wbUykqo.png)](https://drive.google.com/file/d/0B91kiFx_kgWJdTdoYWR2SUlKM0U/view?usp=sharing)

### Arduino

[![Watch the video](https://i.imgur.com/zzffxRV.png)](https://drive.google.com/file/d/0B91kiFx_kgWJSWZLVi1pZ1I2TGs/view?usp=sharing)

### Web app

[![Watch the video](https://i.imgur.com/MGfixGZ.png)](https://drive.google.com/file/d/0B91kiFx_kgWJZmZOQWNjTXkyVHc/view?usp=sharing)



