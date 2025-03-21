#ifndef CLIENT_SERIALIZE_HPP
#define CLIENT_SERIALIZE_HPP

#include <cJSON.h>
#include <stdint.h>

#define SENSOR 1
#define CAMERA 2

// Set the MCU type here
#define MCU_TYPE SENSOR  // Change to SENSOR if needed

#if MCU_TYPE == CAMERA
namespace Client
{
    /*
     * @brief Serialize data from the camera MCU for API interaction.
     *
     * JSON object format:
     * {
     *   "bin_id": 18838586676582,
     *   "mcu_type": "Camera",
     *   "message": string,
     *   "img_str": Image base64 string
     * }
     *
     * @return cJSON* root of a JSON object containing camera data. 
     *         Make sure to free this after use.
     */
    cJSON *serialize(char* message, const void* img_str, size_t buffer_length);
}

#elif MCU_TYPE == SENSOR
namespace Client
{
    /*
     * @brief Serialize data from the sensor MCU for API interaction.
     *
     * JSON object format:
     * {
     *   "bin_id": 18838586676582,
     *   "mcu_type": "Sensor",
     *   "message": string,
     *   "fullness": 0.5,
     *   "overflow": false,
     *   "weight": 50
     * }
     *
     * @return cJSON* root of a JSON object containing sensor data. 
     *         Make sure to free this after use.
     */
    cJSON *serialize(char* message, float fullness, bool overflow, int32_t weight);
}

#endif // MCU_TYPE

#endif // CLIENT_SERIALIZE_HPP
