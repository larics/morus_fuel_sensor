#include <FuelSensorRestartRequestHandler.h>

bool FuelSensorRestartRequestHandler::handleRestartRequest(uavcan::NodeID request_source)
{
	system_reset_flag = true;
	return true;	
}