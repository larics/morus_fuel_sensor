#ifndef FUEL_SENSOR_RESTART_REQUEST_HANDLER_H
#define FUEL_SENSOR_RESTART_REQUEST_HANDLER_H

#include <uavcan/uavcan.hpp>

class FuelSensorRestartRequestHandler: public uavcan::IRestartRequestHandler
{
	bool handleRestartRequest(uavcan::NodeID request_source);
	
	public:
		bool system_reset_flag;
};

#endif
