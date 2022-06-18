In order to use this web app, follow [this](https://www.instructables.com/Mario-Bros-Clock/) tutorial.

### Mario Bros. version
To upload the firmware, connect your ESP32 board in the USB port and use the P-Switch!

<esp-web-install-button manifest="static/firmware_build/v1/manifest.json">
  
  <input class="btn" type="button" slot="activate"/>
  <span slot="unsupported">Ah snap, your browser does not support WebSerial API! If you are using a mobile browser, this is expected. Please, move to the desktop version.</span>
  <span slot="not-allowed">Ah snap, you are not allowed to use this on HTTP!</span>
</esp-web-install-button>



#### Configuring WiFi

The first time you run it, you need to configure the WiFi, for that connect to the **"Clockwise-Wifi"** access point with the password _12345678_ via your smartphone or laptop, click "Configure WiFi" and select your AP, put in your password and your timezone and save. The timezone must be one of the listed [here](https://en.wikipedia.org/wiki/List_of_tz_database_time_zones) e.g. America/New_York, America/Sao_Paulo, Europe/Paris, Asia/Dubai, etc. so that the clock can connect to an NTP server to get the correct time. It is important to use a 2.4GHz WiFi, it will not work on 5G.

<script>
  // preload bg images
  var img1 = new Image();
  var img2 = new Image();
  img1.src="pswitch_h.png";
  img2.src="pswitch_p.png";
</script>
