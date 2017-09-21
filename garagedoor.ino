int openDoorButton = D0;
int doorSensor = D2;
bool state = 0;

/*
    The value property of CurrentDoorState must be one of the following:
    Characteristic.CurrentDoorState.OPEN = 0;
    Characteristic.CurrentDoorState.CLOSED = 1;
    Characteristic.CurrentDoorState.OPENING = 2;
    Characteristic.CurrentDoorState.CLOSING = 3;
    Characteristic.CurrentDoorState.STOPPED = 4;
*/

void setup() {
    pinMode(doorSensor, INPUT_PULLUP);
    pinMode(openDoorButton, OUTPUT);
    digitalWrite(openDoorButton, LOW);
    /* Register Particle functions */
    Particle.function("onoff", onoff);
    Particle.function("doorState", doorState);
}

void loop() {
    // LOW = closed, HIGH = open
    state = digitalRead(doorSensor);
    delay(1000);
}

void pushDoorButton() {
    Particle.publish("pushDoorButton", "true");

    digitalWrite(openDoorButton, HIGH);
    delay(500);
    digitalWrite(openDoorButton, LOW);
}

int onoff(String command) {
    /* Particle.functions always take a string as an argument and return an integer.*/

    if (command == "state=0") {
        pushDoorButton();
        return 0;
    }
    else if (command == "state=1") {
        pushDoorButton();
        return 1;
    }
    else {
        return -1;
    }
}

int doorState(String command) {
    /* Particle.functions always take a string as an argument and return an integer.*/

    if (state == LOW) {
        Particle.publish("getDoorState", "closed");
        return 1;
    } else {
        Particle.publish("getDoorState", "open");
        return 0;
    }
}
