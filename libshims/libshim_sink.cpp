/*
 * Copyright (C) 2023 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <media/AudioTrack.h>

#include <new>
#include <string>

using namespace android;

extern "C" {
/*
 * Stock libsink.so was built against the pre-Android-17 AudioTrack
 * constructor (16 args, no codecProvenance). Android 17 only exports the
 * 17-arg constructor, so provide the old symbol and forward to it.
 */
void _ZN7android10AudioTrackC1E19audio_stream_type_tj14audio_format_t20audio_channel_mask_tm20audio_output_flags_tRKNS_2wpINS0_19IAudioTrackCallbackEEEi15audio_session_tNS0_13transfer_typeEPK20audio_offload_info_tRKNS_7content22AttributionSourceStateEPK18audio_attributes_tbfi(
    void *thisptr, audio_stream_type_t streamType, uint32_t sampleRate,
    audio_format_t format, audio_channel_mask_t channelMask, size_t frameCount,
    audio_output_flags_t flags,
    const wp<AudioTrack::IAudioTrackCallback> &callback,
    int32_t notificationFrames, audio_session_t sessionId,
    AudioTrack::transfer_type transferType,
    const audio_offload_info_t *offloadInfo,
    const AttributionSourceState &attributionSource,
    const audio_attributes_t *pAttributes, bool doNotReconnect,
    float maxRequiredSpeed, audio_port_handle_t selectedDeviceId) {
  new (thisptr) AudioTrack(
      streamType, sampleRate, format, channelMask, frameCount, flags,
      callback, notificationFrames, sessionId, transferType, offloadInfo,
      attributionSource, pAttributes, doNotReconnect, maxRequiredSpeed,
      selectedDeviceId, std::string());
}
}
