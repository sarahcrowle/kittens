#include <string>
#include "SynthBase.h"

#include <q_io/audio_file.hpp>

namespace q = cycfi::q;

#ifndef SYNTHWAVSAMPLE_H
#define SYNTHWAVSAMPLE_H

namespace Kittens::Instrument {
///
/// \brief The SynthWavSample class. A SynthBase that reads samples from a WAV file.
///
class SynthWavSample : public Core::SynthBase {
   public:
    SynthWavSample(std::string filename);  // filename: the path to load
    float get_sample();                    // return the next sample from the WAV
    std::string get_name();

    size_t get_sps();  // returns the samples per second of the WAV
    int get_channels();

    void restart();

    void play();
    void stop();

    size_t get_length();

   private:
    q::wav_memory wav;
    size_t sps;
    size_t length;
    size_t old_position = 0;
    int channels;
    bool playing = false;
    bool queue_playing = false;
};
}  // namespace Kittens::Instrument
#endif  // SYNTHWAVSAMPLE_H