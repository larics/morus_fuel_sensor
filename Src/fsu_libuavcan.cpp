#include <fsu_libuavcan.h>
#include <gpio.h>

/*uint32_t usedBlocks = 0;
uint32_t freeBlocks = 0;
uint32_t peakUsedBlocks = 0;*/

fsu_libuavcan::fsu_libuavcan(void)
{ 
	fuel_sensor_status.sensor_id = 0;
	fuel_sensor_status.fuel_level = 0;
	
	sw_version.major = SW_VERSION_MAJOR;
	sw_version.minor = SW_VERSION_MINOR;
	hw_version.major = HW_VERSION_MAJOR;
	hw_version.minor = HW_VERSION_MINOR;
}

void fsu_libuavcan::can_init(void)
{
		GPIO_InitTypeDef GPIO_InitStruct;
	
		__GPIOA_CLK_ENABLE();
	
		GPIO_InitStruct.Pin = CAN_RX_Pin|CAN_TX_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_CAN;
    HAL_GPIO_Init(CAN_RX_GPIO_Port, &GPIO_InitStruct);
}

void fsu_libuavcan::fsu_libuavcan_Init(int uavcanNodeID)
{
		node_ = &getNode();
    node_->setNodeID(uavcanNodeID);
		node_->setName(UAVCAN_NODE_NAME);
		node_->setSoftwareVersion(sw_version);
		node_->setHardwareVersion(hw_version);
		node_->start();
	
		static uavcan::Publisher<morus_uavcan_msgs::sensors::fuel_sensor::Status> fuel_sensor_status_pub_(*node_);
		fuel_sensor_status_pub = &fuel_sensor_status_pub_;
		fuel_sensor_status_pub->init();
	  fuel_sensor_status_pub->setPriority(uavcan::TransferPriority::MiddleLower);
	
		static uavcan::ParamServer parameter_server(*node_);
		parameter_server_ = &parameter_server;
		parameter_server_->start(&param_manager);
			
		static uavcan::GlobalTimeSyncSlave time_sync_slave_can(*node_);
		time_sync_slave_can_=&time_sync_slave_can;
		time_sync_slave_can_->start();
		
		//uavcan_stm32::clock::adjustUtc(uavcan::UtcDuration::fromUSec(xTaskGetTickCount()));
}

void fsu_libuavcan::fuel_sensor_status_publish(void)
{
	fuel_sensor_status.timestamp.usec = node_->getUtcTime().toUSec();
	fuel_sensor_status_pub->broadcast(fuel_sensor_status);
}

void fsu_libuavcan::start(void)
{
	node_->setModeOperational();
}

void fsu_libuavcan::spin(uint32_t msec)
{
	/*usedBlocks = node_->getAllocator().getNumUsedBlocks();
  freeBlocks = node_->getAllocator().getNumFreeBlocks();
  peakUsedBlocks = node_->getAllocator().getPeakNumUsedBlocks();*/

	node_->spin(uavcan::MonotonicDuration::fromMSec(msec));
}

void fsu_libuavcan::set_fuel_sensorID(uint8_t fsu_id)
{
	fuel_sensor_status.sensor_id = fsu_id;
}

void fsu_libuavcan::set_fuel_level(uint8_t level)
{
	fuel_sensor_status.fuel_level = level;
}

static Node& getNode()
{
    static Node node(getCanDriver(), getSystemClock());
    return node;
}
