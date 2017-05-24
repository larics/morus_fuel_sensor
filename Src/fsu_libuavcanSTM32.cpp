#include <fsu_libuavcanSTM32.h>

static const int RxQueueSize = 128;
static const std::uint32_t BitRate = 1000000;

uavcan::ISystemClock& getSystemClock()
{
    return uavcan_stm32::SystemClock::instance();
}

uavcan::ICanDriver& getCanDriver()
{
    static uavcan_stm32::CanInitHelper<RxQueueSize> can;
    static bool initialized = false;
    int res;
    
    if (!initialized)
    {
        initialized = true;
        res = can.init(BitRate);
        if (res < 0)
        {
            // Handle the error
        }
    }
    return can.driver;
}
