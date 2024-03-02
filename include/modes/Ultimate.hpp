#ifndef _MODES_ULTIMATE_HPP
#define _MODES_ULTIMATE_HPP

#include "core/ControllerMode.hpp"
#include "core/socd.hpp"
#include "core/state.hpp"

typedef struct {
    bool mod_z_dpad_left = false;
} UltimateOptions;

class Ultimate : public ControllerMode {
  public:
    Ultimate(socd::SocdType socd_type, UltimateOptions options = {});

  private:
    UltimateOptions _options;
    void UpdateDigitalOutputs(InputState &inputs, OutputState &outputs);
    void UpdateAnalogOutputs(InputState &inputs, OutputState &outputs);
    bool isDPadLayerActive(InputState &inputs);
};

#endif
