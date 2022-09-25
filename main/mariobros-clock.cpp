/*
   This stub file is required because esp-idf does not recognize .ino files,
   so get around this limitation we create a .cpp file which includes the .ino file.
*/

// Include the project configuration.
// See https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/kconfig.html for details.
#include <sdkconfig.h>

#define HUB75_BLUE_GREEN_SWAP CONFIG_HUB75_BLUE_GREEN_SWAP

#include "../mariobros-clock.ino"
