In order to use this app, you need follow [this](https://www.instructables.com/member/jnthas/) tutorial

### Mario Bros. version
To upload the firmware, connect your ESP32 board in the USB port and use the P-Switch!

<esp-web-install-button manifest="static/firmware_build/v1/manifest.json">
  
  <input class="btn" type="button" slot="activate"/>
  <span slot="unsupported">Ah snap, your browser does not support WebSerial API! If you are using a mobile browser, this is expected. Please, move to the desktop version.</span>
  <span slot="not-allowed">Ah snap, you are not allowed to use this on HTTP!</span>
</esp-web-install-button>

<script>
  // preload bg images
  var img1 = new Image();
  var img2 = new Image();
  img1.src="pswitch_h.png";
  img2.src="pswitch_p.png";
</script>
