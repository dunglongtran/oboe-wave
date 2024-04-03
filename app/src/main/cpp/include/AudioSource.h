#pragma once

namespace oboewave {
    class AudioSource {
    public:
        virtual ~AudioSource() = default;

        virtual float getSample() = 0;

        virtual void onPlaybackStopped() = 0;
    };
}