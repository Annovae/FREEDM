////////////////////////////////////////////////////////////////////////////////
/// @file         CDeviceOmega.cpp
///
/// @author       
///
/// @project      FREEDM DGI
///
/// @description  Represents frequency in PSCAD.
///
/// These source code files were created at Missouri University of Science and
/// Technology, and are intended for use in teaching or research. They may be
/// freely copied, modified, and redistributed as long as modified versions are
/// clearly marked as such and this notice is not removed. Neither the authors
/// nor Missouri S&T make any warranty, express or implied, nor assume any legal
/// responsibility for the accuracy, completeness, or usefulness of these files
/// or any information distributed with these files.
///
/// Suggested modifications or questions about these files can be directed to
/// Dr. Bruce McMillin, Department of Computer Science, Missouri University of
/// Science and Technology, Rolla, MO 65409 <ff@mst.edu>.
////////////////////////////////////////////////////////////////////////////////

#include "CLogger.hpp"
#include "device/types/CDeviceOmega.hpp"

namespace freedm {
namespace broker {
namespace device {

namespace {

/// This file's logger.
CLocalLogger Logger(__FILE__);

}

////////////////////////////////////////////////////////////////////////////////
/// CDeviceOmega::CDeviceOmega(Identifier, IPhysicalAdapter::AdapterPtr)
///
/// @description Instantiates a device.
///
/// @param device The unique device identifier for the device.
/// @param adapter The adapter that implements operations for this device.
////////////////////////////////////////////////////////////////////////////////
CDeviceOmega::CDeviceOmega(const Identifier device,
        IPhysicalAdapter::Pointer adapter)
: IDevice(device, adapter)
{
    Logger.Trace << __PRETTY_FUNCTION__ << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
/// CDeviceOmega::~CDeviceOmega()
///
/// @description Virtual destructor for derived classes.
////////////////////////////////////////////////////////////////////////////////
CDeviceOmega::~CDeviceOmega()
{
    Logger.Trace << __PRETTY_FUNCTION__ << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
/// CDeviceOmega::GetFrequency() const
///
/// @description Retrieve the frequency value of this Omega.
///
/// @return The frequency of this Omega.
////////////////////////////////////////////////////////////////////////////////
SettingValue CDeviceOmega::GetFrequency() const
{
    Logger.Trace << __PRETTY_FUNCTION__ << std::endl;
    return Get("frequency");
}


}
}
}
