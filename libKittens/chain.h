
#include "Synth.h"
#include "Processor.h"

#ifndef CHAIN_H
#define CHAIN_H

///
/// \brief Chain. Contains exactly one synth and an arbitrary (possibly 0) number of EffectsProcessors.
///
class Chain {
public:
    Chain();

    float get_sample(); // get the next sample processed through the chain.

    Synth *synth; // the synth
    std::vector<EffectsProcessor*> processors; // processors
    float volume = 0.7f; // volume. FIXME: expose to script
};

#endif // CHAIN_H