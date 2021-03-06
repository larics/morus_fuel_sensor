/*
 * UAVCAN data structure definition for libuavcan.
 *
 * Autogenerated, do not edit.
 *
 * Source file: C:\Users\Marko\Documents\Development\morus_fuel_sensor\morus_uavcan_msgs\actuator\gas_motor\2013.ElectricStarter.uavcan
 */

#ifndef MORUS_UAVCAN_MSGS_ACTUATOR_GAS_MOTOR_ELECTRICSTARTER_HPP_INCLUDED
#define MORUS_UAVCAN_MSGS_ACTUATOR_GAS_MOTOR_ELECTRICSTARTER_HPP_INCLUDED

#include <uavcan/build_config.hpp>
#include <uavcan/node/global_data_type_registry.hpp>
#include <uavcan/marshal/types.hpp>

/******************************* Source text **********************************
#
# Message for controlling ppm value of the electric starter
#

#
# Motor ID defines
#
uint8 FRONT = 1
uint8 RIGHT = 2
uint8 BACK = 3
uint8 LEFT = 4
uint8 ALL = 0

uint8 motor_id	# id of the electric starter 1-front, 2-right, 3-back, 4-left, 0 - all starters
uint16 ppm		# ppm in range [1000-1900]
******************************************************************************/

/********************* DSDL signature source definition ***********************
morus_uavcan_msgs.actuator.gas_motor.ElectricStarter
saturated uint8 motor_id
saturated uint16 ppm
******************************************************************************/

#undef motor_id
#undef ppm
#undef FRONT
#undef RIGHT
#undef BACK
#undef LEFT
#undef ALL

namespace morus_uavcan_msgs
{
namespace actuator
{
namespace gas_motor
{

template <int _tmpl>
struct UAVCAN_EXPORT ElectricStarter_
{
    typedef const ElectricStarter_<_tmpl>& ParameterType;
    typedef ElectricStarter_<_tmpl>& ReferenceType;

    struct ConstantTypes
    {
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > FRONT;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > RIGHT;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > BACK;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > LEFT;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > ALL;
    };

    struct FieldTypes
    {
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > motor_id;
        typedef ::uavcan::IntegerSpec< 16, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > ppm;
    };

    enum
    {
        MinBitLen
            = FieldTypes::motor_id::MinBitLen
            + FieldTypes::ppm::MinBitLen
    };

    enum
    {
        MaxBitLen
            = FieldTypes::motor_id::MaxBitLen
            + FieldTypes::ppm::MaxBitLen
    };

    // Constants
    static const typename ::uavcan::StorageType< typename ConstantTypes::FRONT >::Type FRONT; // 1
    static const typename ::uavcan::StorageType< typename ConstantTypes::RIGHT >::Type RIGHT; // 2
    static const typename ::uavcan::StorageType< typename ConstantTypes::BACK >::Type BACK; // 3
    static const typename ::uavcan::StorageType< typename ConstantTypes::LEFT >::Type LEFT; // 4
    static const typename ::uavcan::StorageType< typename ConstantTypes::ALL >::Type ALL; // 0

    // Fields
    typename ::uavcan::StorageType< typename FieldTypes::motor_id >::Type motor_id;
    typename ::uavcan::StorageType< typename FieldTypes::ppm >::Type ppm;

    ElectricStarter_()
        : motor_id()
        , ppm()
    {
        ::uavcan::StaticAssert<_tmpl == 0>::check();  // Usage check

#if UAVCAN_DEBUG
        /*
         * Cross-checking MaxBitLen provided by the DSDL compiler.
         * This check shall never be performed in user code because MaxBitLen value
         * actually depends on the nested types, thus it is not invariant.
         */
        ::uavcan::StaticAssert<24 == MaxBitLen>::check();
#endif
    }

    bool operator==(ParameterType rhs) const;
    bool operator!=(ParameterType rhs) const { return !operator==(rhs); }

    /**
     * This comparison is based on @ref uavcan::areClose(), which ensures proper comparison of
     * floating point fields at any depth.
     */
    bool isClose(ParameterType rhs) const;

    static int encode(ParameterType self, ::uavcan::ScalarCodec& codec,
                      ::uavcan::TailArrayOptimizationMode tao_mode = ::uavcan::TailArrayOptEnabled);

    static int decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
                      ::uavcan::TailArrayOptimizationMode tao_mode = ::uavcan::TailArrayOptEnabled);

    /*
     * Static type info
     */
    enum { DataTypeKind = ::uavcan::DataTypeKindMessage };
    enum { DefaultDataTypeID = 2013 };

    static const char* getDataTypeFullName()
    {
        return "morus_uavcan_msgs.actuator.gas_motor.ElectricStarter";
    }

    static void extendDataTypeSignature(::uavcan::DataTypeSignature& signature)
    {
        signature.extend(getDataTypeSignature());
    }

    static ::uavcan::DataTypeSignature getDataTypeSignature();

};

/*
 * Out of line struct method definitions
 */

template <int _tmpl>
bool ElectricStarter_<_tmpl>::operator==(ParameterType rhs) const
{
    return
        motor_id == rhs.motor_id &&
        ppm == rhs.ppm;
}

template <int _tmpl>
bool ElectricStarter_<_tmpl>::isClose(ParameterType rhs) const
{
    return
        ::uavcan::areClose(motor_id, rhs.motor_id) &&
        ::uavcan::areClose(ppm, rhs.ppm);
}

template <int _tmpl>
int ElectricStarter_<_tmpl>::encode(ParameterType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::motor_id::encode(self.motor_id, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::ppm::encode(self.ppm, codec,  tao_mode);
    return res;
}

template <int _tmpl>
int ElectricStarter_<_tmpl>::decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::motor_id::decode(self.motor_id, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::ppm::decode(self.ppm, codec,  tao_mode);
    return res;
}

/*
 * Out of line type method definitions
 */
template <int _tmpl>
::uavcan::DataTypeSignature ElectricStarter_<_tmpl>::getDataTypeSignature()
{
    ::uavcan::DataTypeSignature signature(0xF00942226F04CA49ULL);

    FieldTypes::motor_id::extendDataTypeSignature(signature);
    FieldTypes::ppm::extendDataTypeSignature(signature);

    return signature;
}

/*
 * Out of line constant definitions
 */

template <int _tmpl>
const typename ::uavcan::StorageType< typename ElectricStarter_<_tmpl>::ConstantTypes::FRONT >::Type
    ElectricStarter_<_tmpl>::FRONT = 1U; // 1

template <int _tmpl>
const typename ::uavcan::StorageType< typename ElectricStarter_<_tmpl>::ConstantTypes::RIGHT >::Type
    ElectricStarter_<_tmpl>::RIGHT = 2U; // 2

template <int _tmpl>
const typename ::uavcan::StorageType< typename ElectricStarter_<_tmpl>::ConstantTypes::BACK >::Type
    ElectricStarter_<_tmpl>::BACK = 3U; // 3

template <int _tmpl>
const typename ::uavcan::StorageType< typename ElectricStarter_<_tmpl>::ConstantTypes::LEFT >::Type
    ElectricStarter_<_tmpl>::LEFT = 4U; // 4

template <int _tmpl>
const typename ::uavcan::StorageType< typename ElectricStarter_<_tmpl>::ConstantTypes::ALL >::Type
    ElectricStarter_<_tmpl>::ALL = 0U; // 0

/*
 * Final typedef
 */
typedef ElectricStarter_<0> ElectricStarter;

namespace
{

const ::uavcan::DefaultDataTypeRegistrator< ::morus_uavcan_msgs::actuator::gas_motor::ElectricStarter > _uavcan_gdtr_registrator_ElectricStarter;

}

} // Namespace gas_motor
} // Namespace actuator
} // Namespace morus_uavcan_msgs

/*
 * YAML streamer specialization
 */
namespace uavcan
{

template <>
class UAVCAN_EXPORT YamlStreamer< ::morus_uavcan_msgs::actuator::gas_motor::ElectricStarter >
{
public:
    template <typename Stream>
    static void stream(Stream& s, ::morus_uavcan_msgs::actuator::gas_motor::ElectricStarter::ParameterType obj, const int level);
};

template <typename Stream>
void YamlStreamer< ::morus_uavcan_msgs::actuator::gas_motor::ElectricStarter >::stream(Stream& s, ::morus_uavcan_msgs::actuator::gas_motor::ElectricStarter::ParameterType obj, const int level)
{
    (void)s;
    (void)obj;
    (void)level;
    if (level > 0)
    {
        s << '\n';
        for (int pos = 0; pos < level; pos++)
        {
            s << "  ";
        }
    }
    s << "motor_id: ";
    YamlStreamer< ::morus_uavcan_msgs::actuator::gas_motor::ElectricStarter::FieldTypes::motor_id >::stream(s, obj.motor_id, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "ppm: ";
    YamlStreamer< ::morus_uavcan_msgs::actuator::gas_motor::ElectricStarter::FieldTypes::ppm >::stream(s, obj.ppm, level + 1);
}

}

namespace morus_uavcan_msgs
{
namespace actuator
{
namespace gas_motor
{

template <typename Stream>
inline Stream& operator<<(Stream& s, ::morus_uavcan_msgs::actuator::gas_motor::ElectricStarter::ParameterType obj)
{
    ::uavcan::YamlStreamer< ::morus_uavcan_msgs::actuator::gas_motor::ElectricStarter >::stream(s, obj, 0);
    return s;
}

} // Namespace gas_motor
} // Namespace actuator
} // Namespace morus_uavcan_msgs

#endif // MORUS_UAVCAN_MSGS_ACTUATOR_GAS_MOTOR_ELECTRICSTARTER_HPP_INCLUDED