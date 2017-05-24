#ifndef FSUPARAMMANAGER_H
#define FSUPARAMMANAGER_H

#include <uavcan/uavcan.hpp>

#include <uavcan/protocol/param_server.hpp>

class FsuParamManager: public uavcan::IParamManager
{
	void getParamNameByIndex(Index index, Name& out_name) const;
	void assignParamValue(const Name& name, const Value& value);
	void readParamValue(const Name& name, Value& out_value) const;
	void readParamDefaultMaxMin(const Name& name, Value& out_def,
		NumericValue& out_max, NumericValue& out_min) const;
	int eraseAllParams();
	int saveAllParams();
};

#endif
