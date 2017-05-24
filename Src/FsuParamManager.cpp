#include <FsuParamManager.h>
#include <flash.h>

void FsuParamManager::getParamNameByIndex(Index index, Name& out_name) const
{
	if (index == 1 ) { out_name = "FSU_ID"; }
}

void FsuParamManager::assignParamValue(const Name& name, const Value& value)
{
	
	if (name == "FSU_ID")
	{
		if (value.is(uavcan::protocol::param::Value::Tag::boolean_value))
		{
			fsu_parameters.fsu_id = 
				(uint8_t)*value.as<uavcan::protocol::param::Value::Tag::boolean_value>();
		}
	}
	
}

void FsuParamManager::readParamValue(const Name& name, Value& out_value) const
{
	
	if (name == "FSU_ID")
	{
		out_value.to<uavcan::protocol::param::Value::Tag::boolean_value>() =
			fsu_parameters.fsu_id;
	}

}

void FsuParamManager::readParamDefaultMaxMin(const Name& name, Value& out_def,
		NumericValue& out_max, NumericValue& out_min) const
{
	
	if (name == "FSU_ID")
	{
		out_def.to<uavcan::protocol::param::Value::Tag::boolean_value>() =
			FSU_ID;
    out_max.to<uavcan::protocol::param::NumericValue::Tag::integer_value>() = 255;
    out_min.to<uavcan::protocol::param::NumericValue::Tag::integer_value>() = 0;
	}
	
}

int FsuParamManager::eraseAllParams()
{
	readDefaultParameters(&fsu_parameters);
	return 0;
}

int FsuParamManager::saveAllParams()
{
	writeParams2Flash(&fsu_parameters);
	return 0;
}

	