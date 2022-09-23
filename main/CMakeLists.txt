set (SRC_DIRS)
set (INCLUDE_DIRS)

# ezTime
# This can be removed if https://github.com/ropg/ezTime/pull/157 is merged in.
set (SRC_DIRS ${SRC_DIRS} "${PROJECT_DIR}/components/ezTime/src")
set (INCLUDE_DIRS ${INCLUDE_DIRS} "${PROJECT_DIR}/components/ezTime/src")

# WiFiManager
# This can be removed if https://github.com/tzapu/WiFiManager/pull/1489 is merged in.
set (SRC_DIRS ${SRC_DIRS} "${PROJECT_DIR}/components/WiFiManager")
set (INCLUDE_DIRS ${INCLUDE_DIRS} "${PROJECT_DIR}/components/WiFiManager")

idf_component_register(
			SRC_DIRS "." ${PROJECT_DIR} ${SRC_DIRS}
			INCLUDE_DIRS ${PROJECT_DIR} ${INCLUDE_DIRS}
			# Add ezTime and WiFiManager once they are merged.
			REQUIRES arduino ESP32-HUB75-MatrixPanel-I2S-DMA
                       )
