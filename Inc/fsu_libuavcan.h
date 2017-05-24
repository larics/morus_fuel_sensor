#ifndef FSU_LIBUAVCAN_H
#define FSU_LIBUAVCAN_H

#include <fsu_libuavcanSTM32.h>
#include <uavcan/uavcan.hpp>
#include <uavcan/protocol/global_time_sync_slave.hpp>

#include <uavcan/protocol/HardwareVersion.hpp>
#include <uavcan/protocol/SoftwareVersion.hpp>

#include <morus_uavcan_msgs/sensors/fuel_sensor/Status.hpp>

#include <FsuParamManager.h>

#define UAVCAN_NODE_NAME		"fuel.sensor.unit"

static const unsigned NodeMemoryPoolSize = 1024;
typedef uavcan::Node<NodeMemoryPoolSize> Node;

static Node& getNode();
		
class fsu_libuavcan{
	private:
		uavcan::ParamServer *parameter_server_;
		uavcan::GlobalTimeSyncSlave *time_sync_slave_can_;
	
		morus_uavcan_msgs::sensors::fuel_sensor::Status fuel_sensor_status;
	
		uavcan::Publisher<morus_uavcan_msgs::sensors::fuel_sensor::Status> *fuel_sensor_status_pub;
		
		Node *node_;
		
		FsuParamManager param_manager;
		
		uavcan::protocol::SoftwareVersion sw_version;
		uavcan::protocol::HardwareVersion hw_version;
		
	public:
		fsu_libuavcan();
		void can_init(void);
		void fuel_sensor_status_publish(void);
		void fsu_libuavcan_Init(int uavcanNodeID);
		void start(void);
		void spin(uint32_t msec);
		void set_fuel_sensorID(uint8_t fsu_id);
		void set_fuel_level(uint8_t level);
};

#endif
