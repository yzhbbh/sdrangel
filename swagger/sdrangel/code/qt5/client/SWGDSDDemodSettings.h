/**
 * SDRangel
 * This is the web REST/JSON API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube    ---   Limitations and specifcities:    * In SDRangel GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /sdrangel/deviceset with DELETE method.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV and DATV demodulators, Channel Analyzer NG, LoRa demodulator   * The device settings and report structures contains only the sub-structure corresponding to the device type. The DeviceSettings and DeviceReport structures documented here shows all of them but only one will be or should be present at a time   * The channel settings and report structures contains only the sub-structure corresponding to the channel type. The ChannelSettings and ChannelReport structures documented here shows all of them but only one will be or should be present at a time    --- 
 *
 * OpenAPI spec version: 4.12.5
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */

/*
 * SWGDSDDemodSettings.h
 *
 * DSDDemod
 */

#ifndef SWGDSDDemodSettings_H_
#define SWGDSDDemodSettings_H_

#include <QJsonObject>


#include <QString>

#include "SWGObject.h"
#include "export.h"

namespace SWGSDRangel {

class SWG_API SWGDSDDemodSettings: public SWGObject {
public:
    SWGDSDDemodSettings();
    SWGDSDDemodSettings(QString* json);
    virtual ~SWGDSDDemodSettings();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGDSDDemodSettings* fromJson(QString &jsonString) override;

    qint64 getInputFrequencyOffset();
    void setInputFrequencyOffset(qint64 input_frequency_offset);

    float getRfBandwidth();
    void setRfBandwidth(float rf_bandwidth);

    float getFmDeviation();
    void setFmDeviation(float fm_deviation);

    float getDemodGain();
    void setDemodGain(float demod_gain);

    float getVolume();
    void setVolume(float volume);

    qint32 getBaudRate();
    void setBaudRate(qint32 baud_rate);

    qint32 getSquelchGate();
    void setSquelchGate(qint32 squelch_gate);

    float getSquelch();
    void setSquelch(float squelch);

    qint32 getAudioMute();
    void setAudioMute(qint32 audio_mute);

    qint32 getEnableCosineFiltering();
    void setEnableCosineFiltering(qint32 enable_cosine_filtering);

    qint32 getSyncOrConstellation();
    void setSyncOrConstellation(qint32 sync_or_constellation);

    qint32 getSlot1On();
    void setSlot1On(qint32 slot1_on);

    qint32 getSlot2On();
    void setSlot2On(qint32 slot2_on);

    qint32 getTdmaStereo();
    void setTdmaStereo(qint32 tdma_stereo);

    qint32 getPllLock();
    void setPllLock(qint32 pll_lock);

    qint32 getRgbColor();
    void setRgbColor(qint32 rgb_color);

    QString* getTitle();
    void setTitle(QString* title);

    QString* getAudioDeviceName();
    void setAudioDeviceName(QString* audio_device_name);

    qint32 getHighPassFilter();
    void setHighPassFilter(qint32 high_pass_filter);

    qint32 getTraceLengthMutliplier();
    void setTraceLengthMutliplier(qint32 trace_length_mutliplier);

    qint32 getTraceStroke();
    void setTraceStroke(qint32 trace_stroke);

    qint32 getTraceDecay();
    void setTraceDecay(qint32 trace_decay);

    qint32 getStreamIndex();
    void setStreamIndex(qint32 stream_index);

    qint32 getUseReverseApi();
    void setUseReverseApi(qint32 use_reverse_api);

    QString* getReverseApiAddress();
    void setReverseApiAddress(QString* reverse_api_address);

    qint32 getReverseApiPort();
    void setReverseApiPort(qint32 reverse_api_port);

    qint32 getReverseApiDeviceIndex();
    void setReverseApiDeviceIndex(qint32 reverse_api_device_index);

    qint32 getReverseApiChannelIndex();
    void setReverseApiChannelIndex(qint32 reverse_api_channel_index);


    virtual bool isSet() override;

private:
    qint64 input_frequency_offset;
    bool m_input_frequency_offset_isSet;

    float rf_bandwidth;
    bool m_rf_bandwidth_isSet;

    float fm_deviation;
    bool m_fm_deviation_isSet;

    float demod_gain;
    bool m_demod_gain_isSet;

    float volume;
    bool m_volume_isSet;

    qint32 baud_rate;
    bool m_baud_rate_isSet;

    qint32 squelch_gate;
    bool m_squelch_gate_isSet;

    float squelch;
    bool m_squelch_isSet;

    qint32 audio_mute;
    bool m_audio_mute_isSet;

    qint32 enable_cosine_filtering;
    bool m_enable_cosine_filtering_isSet;

    qint32 sync_or_constellation;
    bool m_sync_or_constellation_isSet;

    qint32 slot1_on;
    bool m_slot1_on_isSet;

    qint32 slot2_on;
    bool m_slot2_on_isSet;

    qint32 tdma_stereo;
    bool m_tdma_stereo_isSet;

    qint32 pll_lock;
    bool m_pll_lock_isSet;

    qint32 rgb_color;
    bool m_rgb_color_isSet;

    QString* title;
    bool m_title_isSet;

    QString* audio_device_name;
    bool m_audio_device_name_isSet;

    qint32 high_pass_filter;
    bool m_high_pass_filter_isSet;

    qint32 trace_length_mutliplier;
    bool m_trace_length_mutliplier_isSet;

    qint32 trace_stroke;
    bool m_trace_stroke_isSet;

    qint32 trace_decay;
    bool m_trace_decay_isSet;

    qint32 stream_index;
    bool m_stream_index_isSet;

    qint32 use_reverse_api;
    bool m_use_reverse_api_isSet;

    QString* reverse_api_address;
    bool m_reverse_api_address_isSet;

    qint32 reverse_api_port;
    bool m_reverse_api_port_isSet;

    qint32 reverse_api_device_index;
    bool m_reverse_api_device_index_isSet;

    qint32 reverse_api_channel_index;
    bool m_reverse_api_channel_index_isSet;

};

}

#endif /* SWGDSDDemodSettings_H_ */
