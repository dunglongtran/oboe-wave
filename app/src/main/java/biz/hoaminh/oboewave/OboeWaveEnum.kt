package biz.hoaminh.oboewave

import androidx.annotation.StringRes

enum class OboeWaveEnum {
    SINE {
        @StringRes
        override fun toResourceString(): Int {
            return R.string.sine
        }
    },

    TRIANGLE {
        @StringRes
        override fun toResourceString(): Int {
            return R.string.triangle
        }
    },

    SQUARE {
        @StringRes
        override fun toResourceString(): Int {
            return R.string.square
        }
    },

    SAW {
        @StringRes
        override fun toResourceString(): Int {
            return R.string.sawtooth
        }
    };

    @StringRes
    abstract fun toResourceString(): Int
}

interface WavetableSynthesizer {
    suspend fun play()
    suspend fun stop()
    suspend fun isPlaying() : Boolean
    suspend fun setFrequency(frequencyInHz: Float)
    suspend fun setVolume(volumeInDb: Float)
    suspend fun setWavetable(wavetable: OboeWaveEnum)
}