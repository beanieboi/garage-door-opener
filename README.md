# Automated garage door

We started the project with the goal to open the garage door 2 minutes before arriving at home by saying "Hey Siri, open the garage door!" while riding the bicycle.

## Hardware

* Photon board with wi-fi chip [buy here](https://store.particle.io/#photon)
* Marantec M3-2312 garage door opener remote (we have Marantec garage door)
* magnetic sensor
* Adafruit breadboard to assemble electronics
* wires, resistor
* optocoupler

## Software

### Photon

The Photon handles sensor data and triggers the door remote.

* garagedoor.ino
* use the Particle IDE to upload directly to your Photon [on particle.io](https://build.particle.io/build)

### Server

The server runs the homebridge framework and adds the garage door as Accessories.
Homebridge is a lightweight NodeJS server you can run on your home network that emulates the iOS HomeKit API.

* homebridge framework [on GitHub](https://github.com/nfarina/homebridge)

## Images

![Image](https://raw.githubusercontent.com/beanieboi/garage-door-opener/master/photos/IMG_4709.jpg)
![Image](https://raw.githubusercontent.com/beanieboi/garage-door-opener/master/photos/IMG_4712.jpg)
![Image](https://raw.githubusercontent.com/beanieboi/garage-door-opener/master/photos/IMG_4713.jpg)
![Image](https://raw.githubusercontent.com/beanieboi/garage-door-opener/master/photos/IMG_4768.jpg)
![Image](https://raw.githubusercontent.com/beanieboi/garage-door-opener/master/photos/IMG_4770.jpg)
