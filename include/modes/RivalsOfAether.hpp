#ifndef _MODES_RIVALSOFAETHER_HPP
#define _MODES_RIVALSOFAETHER_HPP

#include "core/ControllerMode.hpp"
#include "core/socd.hpp"
#include "core/state.hpp"

typedef struct {
    bool mod_z_dpad_left = false;
} RivalsOfAetherOptions;

class RivalsOfAether : public ControllerMode {
  public:
    RivalsOfAether(socd::SocdType socd_type, RivalsOfAetherOptions options = {});

  private:
    RivalsOfAetherOptions _options;

    void UpdateDigitalOutputs(InputState &inputs, OutputState &outputs);
    void UpdateAnalogOutputs(InputState &inputs, OutputState &outputs);
    bool isDPadLayerActive(InputState &inputs);
};

#endif
