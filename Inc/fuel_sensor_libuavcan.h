#ifndef FUEL_SENSOR_LIBUAVCAN_H
#define FUEL_SENSOR_LIBUAVCAN_H

#include <fuel_sensor_libuavcanSTM32.h>
#include <uavcan/uavcan.hpp>
#include <uavcan/protocol/global_time_sync_slave.hpp>


#include <uavcan/protocol/HardwareVersion.hpp>
#include <uavcan/protocol/SoftwareVersion.hpp>
#include <uavcan/protocol/RestartNode.hpp>

#include <FuelSensorRestartRequestHandler.h>

#define UAVCAN_NODE_NAME		"fuel.sensor"

static const unsigned NodeMemoryPoolSize = 8192;
typedef uavcan::Node<NodeMemoryPoolSize> Node;

static Node& getNode();
		
class fuel_sensor_libuavcan{
	private:		
		uavcan::GlobalTimeSyncSlave *time_sync_slave_can_;
		
		Node *node_;
		
		FuelSensorRestartRequestHandler restart_request_handler;
		
		uavcan::protocol::SoftwareVersion sw_version;
		uavcan::protocol::HardwareVersion hw_version;
		
	public:
		fuel_sensor_libuavcan();
		void can_init(void);
		void fuel_sensor_libuavcan_Init(int uavcanNodeID);
		void start(void);
		void spinOnce(void);
		void spin(uint32_t msec);
		void setModeSoftwareUpdate();
		bool get_system_reset_flag(void);
};

#endif
