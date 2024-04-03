#include <jni.h>
#include <memory>
#include "Log.h"
#include "WavetableSynthesizer.h"


extern "C"
JNIEXPORT jlong JNICALL
Java_biz_hoaminh_oboewave_NativeOboeWave_create(JNIEnv *env, jobject thiz) {
    auto synthesizer =
            std::make_unique<oboewave::WavetableSynthesizer>();

    if (not synthesizer) {
        LOGD("Failed to create the synthesizer.");
        synthesizer.reset(nullptr);
    }

    return reinterpret_cast<jlong>(synthesizer.release());
}
extern "C"
JNIEXPORT void JNICALL
Java_biz_hoaminh_oboewave_NativeOboeWave_delete(JNIEnv *env, jobject thiz,
                                                jlong synthesizerHandle) {
    auto *synthesizer =
            reinterpret_cast<oboewave::WavetableSynthesizer *>(
                    synthesizerHandle);

    if (not synthesizer) {
        LOGD("Attempt to destroy an unitialized synthesizer.");
        return;
    }

    delete synthesizer;
}
extern "C"
JNIEXPORT void JNICALL
Java_biz_hoaminh_oboewave_NativeOboeWave_play(JNIEnv *env, jobject thiz, jlong synthesizerHandle) {
    auto *synthesizer =
            reinterpret_cast<oboewave::WavetableSynthesizer *>(
                    synthesizerHandle);

    if (synthesizer) {
        synthesizer->play();
    } else {
        LOGD(
                "Synthesizer not created. Please, create the synthesizer first by "
                "calling create().");
    }
}
extern "C"
JNIEXPORT void JNICALL
Java_biz_hoaminh_oboewave_NativeOboeWave_stop(JNIEnv *env, jobject thiz, jlong synthesizerHandle) {
    auto *synthesizer =
            reinterpret_cast<oboewave::WavetableSynthesizer *>(
                    synthesizerHandle);

    if (synthesizer) {
        synthesizer->stop();
    } else {
        LOGD(
                "Synthesizer not created. Please, create the synthesizer first by "
                "calling create().");
    }
}
extern "C"
JNIEXPORT jboolean JNICALL
Java_biz_hoaminh_oboewave_NativeOboeWave_isPlaying(JNIEnv *env, jobject thiz,
                                                   jlong synthesizerHandle) {
    auto *synthesizer =
            reinterpret_cast<oboewave::WavetableSynthesizer *>(
                    synthesizerHandle);

    if (not synthesizer) {
        LOGD(
                "Synthesizer not created. Please, create the synthesizer first by "
                "calling create().");
        return false;
    }

    return synthesizer->isPlaying();
}
extern "C"
JNIEXPORT void JNICALL
Java_biz_hoaminh_oboewave_NativeOboeWave_setFrequency(JNIEnv *env, jobject thiz,
                                                      jlong synthesizerHandle,
                                                      jfloat frequencyInHz) {
    auto *synthesizer =
            reinterpret_cast<oboewave::WavetableSynthesizer *>(
                    synthesizerHandle);
    const auto nativeFrequency = static_cast<float>(frequencyInHz);

    if (synthesizer) {
        synthesizer->setFrequency(nativeFrequency);
    } else {
        LOGD(
                "Synthesizer not created. Please, create the synthesizer first by "
                "calling create().");
    }
}
extern "C"
JNIEXPORT void JNICALL
Java_biz_hoaminh_oboewave_NativeOboeWave_setVolume(JNIEnv *env, jobject thiz,
                                                   jlong synthesizerHandle,
                                                   jfloat volumeInDb) {
    auto *synthesizer =
            reinterpret_cast<oboewave::WavetableSynthesizer *>(
                    synthesizerHandle);
    const auto nativeVolume = static_cast<float>(volumeInDb);

    if (synthesizer) {
        synthesizer->setVolume(nativeVolume);
    } else {
        LOGD(
                "Synthesizer not created. Please, create the synthesizer first by "
                "calling create().");
    }
}
extern "C"
JNIEXPORT void JNICALL
Java_biz_hoaminh_oboewave_NativeOboeWave_setWavetable(JNIEnv *env, jobject thiz,
                                                      jlong synthesizerHandle, jint wavetable) {
    auto *synthesizer = reinterpret_cast<oboewave::WavetableSynthesizer *>(
            synthesizerHandle);
    const auto nativeWavetable = static_cast<oboewave::Wavetable>(wavetable);

    if (synthesizer) {
        synthesizer->setWavetable(nativeWavetable);
    } else {
        LOGD(
                "Synthesizer not created. Please, create the synthesizer first by "
                "calling create().");
    }
}