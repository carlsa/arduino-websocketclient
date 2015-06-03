## Websocket Client for Arduino for ESP8266

This library implements a websocket client for the [ESP8266 arduino project](https://github.com/esp8266/Arduino).
This library supports Sec-WebSocket-Version: 13 and binary **multiple** binary frame messaging.

### Limitations

This library:
  * Supporting Binary Data Framing & compliant with RFC6455 sections 5.6 / 5.7

### Getting started

Install the library to "libraries" folder in your Arduino sketchbook folder. 


### Example

An example sketch that communicates with echo.websocket.org is included in the library.


### Credits
Thank you to:
  - github user djsb for the websocet client for arduino that I could adapt for ESP8266
  - developers of the third party libraries included by this websocket client library: MD5, sha1 & Base64
