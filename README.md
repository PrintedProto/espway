# ESPway

A segway-like balancing two-wheel robot built on ESP8266. It is controlled over WiFi via a HTML/JS GUI and a WebSocket.

This is a work in progress, but basic functionality now works.

The project takes advantage of the [ESP8266 Arduino core](https://github.com/esp8266/Arduino),
[PlatformIO](http://platformio.org/) and
[some](https://github.com/jrowberg/i2cdevlib/tree/master/Arduino/MPU6050)
[excellent](https://github.com/me-no-dev/ESPAsyncWebServer)
[libraries](https://github.com/Makuna/NeoPixelBus). Instead of Arduino's `analogWrite`,
StephanBruens's [ESP8266_new_pwm](https://github.com/StefanBruens/ESP8266_new_pwm) is used for running the motors.

## Building

Use [PlatformIO](http://platformio.org/) to build and upload the code.
The current code uses the ESP8266 staging platform. It has to be installed
separately following [these instructions](http://docs.platformio.org/en/stable/platforms/espressif8266.html#using-arduino-framework-with-staging-version).

### Uploading the code

In the root folder of the project, run
```
pio run -t upload
```
PlatformIO should autodetect the USB port the WEMOS D1 mini is connected to.

Then upload the filesystem:
```
pio run -t uploadfs
```
That will take a while because the filesystem is large.

## Schematic & BOM

See the `schematic` folder for the schematic. It is drawn with [KiCad](http://kicad-pcb.org/) and there's a [rendered PDF](https://github.com/flannelhead/espway/raw/master/schematic/espway.pdf) in the repo.

Tentative BOM (not including PCB, connectors, wire etc. materials):

* WEMOS D1 Mini board
* GY-521 (MPU6050 breakout board)
* L293D motor driver IC. **N.B.** this is what I used so far, but I'm intending to change to DRV8833 for a smaller voltage drop across the H-bridge
* 2x 6V 300rpm metal gear motor (search for "12ga 300rpm" or "n20 300rpm"), these should be $3-5 per piece
* 2x WS2812B neopixels for eyes and showing current state
* AMS1117 5V regulator
* 5x 100n ceramic capacitors
* 2x 1000u 10V electrolytic capacitor
* 470 ohm resistor
* 10 kohm resistor
* 680 kohm resistor

## Supported browsers

Please use the latest Firefox or Chrome if possible. The HTML/JS UI uses some
recent JavaScript features which might not be supported by older browsers.

I'm intending to setup JavaScript transpilation with `gulp` to support older browsers.
Before that is done, it might not make much sense to use any other than the
aforementioned browsers, as I have no means of testing the code on anything else.

## Deprecation

The code is being ported to the native ESP8266 SDK on the [master branch](https://github.com/flannelhead/espway/tree/master).
While that might be not yet ready for bigger audiences, new features will appear there.

I might still support this (Arduino/PIO) branch for a while by backporting bugfixes.

## TODO

Beware! There might be some nasty bugs or erratic behavior, although some major issues in the early code (watchdog resets, incorrect PID initialization) have been resolved.
Some things TODO:

* Gyro calibration
* PID tuning graphically via the browser

## License
The project is licensed under GPLv3.

