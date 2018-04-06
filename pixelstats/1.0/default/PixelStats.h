#ifndef HARDWARE_GOOGLE_PIXELSTATS_V1_0_PIXELSTATS_H
#define HARDWARE_GOOGLE_PIXELSTATS_V1_0_PIXELSTATS_H

#include <hardware/google/pixelstats/1.0/IPixelStats.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>

namespace hardware {
namespace google {
namespace pixelstats {
namespace V1_0 {
namespace implementation {

using ::android::hardware::hidl_array;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;

struct PixelStats : public IPixelStats {
    // Methods from ::hardware::google::pixelstats::V1_0::IPixelStats follow.
    Return<void> reportUsbConnectorStateChanged(bool connected) override;
    Return<void> reportSpeakerImpedence(int32_t speakerLocation, int32_t milliOhms) override;
    Return<void> reportHardwareFailed(int32_t hardwareType, int32_t hardwareLocation, HardwareErrorCode errorCode) override;
    Return<void> reportPhysicalDropDetected(int32_t confidence, int32_t accelPeak, int32_t freefallDurationMs) override;
    Return<void> reportChargeCycles(const hidl_array<int32_t, 8>& buckets);
    Return<void> reportUsbDeviceAttached(int32_t vid, int32_t pid, bool hasAudio, bool hasHid, bool hasStorage) override;

    // Methods from ::android::hidl::base::V1_0::IBase follow.

};

}  // namespace implementation
}  // namespace V1_0
}  // namespace pixelstats
}  // namespace google
}  // namespace hardware

#endif  // HARDWARE_GOOGLE_PIXELSTATS_V1_0_PIXELSTATS_H
