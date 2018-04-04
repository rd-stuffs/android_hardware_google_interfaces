#include "PixelStats.h"

#include "statslog.h"

namespace hardware {
namespace google {
namespace pixelstats {
namespace V1_0 {
namespace implementation {

// Methods from ::hardware::google::pixelstats::V1_0::IPixelStats follow.
Return<void> PixelStats::reportUsbConnectorStateChanged(bool connected) {
    stats_write(android::util::USB_CONNECTOR_STATE_CHANGED, connected);
    return Void();
}

Return<void> PixelStats::reportSpeakerImpedence(int32_t speakerLocation, int32_t milliOhms) {
    stats_write(android::util::SPEAKER_IMPEDANCE_REPORTED, speakerLocation,
                milliOhms);
    return Void();
}

Return<void> PixelStats::reportHardwareFailed(int32_t hardwareType, int32_t hardwareLocation, HardwareErrorCode errorCode) {
    stats_write(android::util::HARDWARE_FAILED, 1, hardwareType,
                hardwareLocation, (int32_t) errorCode);
    return Void();
}

Return<void> PixelStats::reportPhysicalDropDetected(int32_t confidencePctg, int32_t accelPeak, int32_t freefallDurationMs) {
    stats_write(android::util::PHYSICAL_DROP_DETECTED, confidencePctg,
                accelPeak, freefallDurationMs);
    return Void();
}

Return<void> PixelStats::reportChargeCycles(const hidl_array<int32_t, 8>& buckets) {
    stats_write(android::util::CHARGE_CYCLES_REPORTED, buckets[0], buckets[1],
                buckets[2], buckets[3], buckets[4], buckets[5], buckets[6],
                buckets[7]);
    return Void();
}

Return<void> PixelStats::reportUsbDeviceAttached(int32_t vid, int32_t pid, bool hasAudio, bool hasHid, bool hasStorage) {
    stats_write(android::util::USB_DEVICE_ATTACHED, vid, pid, hasAudio,
                hasHid, hasStorage);
    return Void();
}

// Methods from ::android::hidl::base::V1_0::IBase follow.

//IPixelStats* HIDL_FETCH_IPixelStats(const char* /* name */) {
//    return new PixelStats();
//}

}  // namespace implementation
}  // namespace V1_0
}  // namespace pixelstats
}  // namespace google
}  // namespace hardware
