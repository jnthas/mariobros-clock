set (SRC_DIRS)
set (INCLUDE_DIRS)

# ezTime
# This can be removed if https://github.com/ropg/ezTime/pull/157 is merged in.
set (SRC_DIRS ${SRC_DIRS} "${PROJECT_DIR}/components/ezTime/src")
set (INCLUDE_DIRS ${INCLUDE_DIRS} "${PROJECT_DIR}/components/ezTime/src")

idf_component_register(
			SRC_DIRS "." ${PROJECT_DIR} ${SRC_DIRS}
			INCLUDE_DIRS ${PROJECT_DIR} ${INCLUDE_DIRS}
			# Add ezTime after https://github.com/ropg/ezTime/pull/157 is merged in.
			REQUIRES arduino ESP32-HUB75-MatrixPanel-I2S-DMA WiFiManager
                       )
