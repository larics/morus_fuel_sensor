#ifndef FUEL_SENSOR_LIBUAVCANSTM32_H
#define FUEL_SENSOR_LIBUAVCANSTM32_H

#include <uavcan_stm32/uavcan_stm32.hpp>

uavcan::ICanDriver& getCanDriver();

uavcan::ISystemClock& getSystemClock();

#endif
