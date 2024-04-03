#ifndef _CONFIG_MODE_SELECTION_HPP
#define _CONFIG_MODE_SELECTION_HPP

#include "core/state.hpp"
#include "modes/DefaultKeyboardMode.hpp"
#include "modes/FgcMode.hpp"
#include "modes/Melee21Button.hpp"
#include "modes/ProjectM.hpp"
#include "modes/RivalsOfAether.hpp"
#include "modes/Ultimate.hpp"

extern KeyboardMode *current_kb_mode;

void set_mode(CommunicationBackend *backend, ControllerMode *mode) {
    // Delete keyboard mode in case one is set, so we don't end up getting both controller and
    // keyboard inputs.
    delete current_kb_mode;
    current_kb_mode = nullptr;

    // Set new controller mode.
    backend->SetGameMode(mode);
}

void set_mode(CommunicationBackend *backend, KeyboardMode *mode) {
    // Delete and reassign current keyboard mode.
    delete current_kb_mode;
    current_kb_mode = mode;

    // Unset the current controller mode so backend only gives neutral inputs.
    backend->SetGameMode(nullptr);
}

void select_mode(CommunicationBackend *backend) {
    InputState &inputs = backend->GetInputs();
    if (inputs.mod_x && !inputs.mod_y && !inputs.mod_z && inputs.start) {
        if (inputs.l) {
            set_mode(
                backend,
                new Melee21Button(socd::SOCD_NEUTRAL, { .crouch_walk_os = inputs.up, .mod_z_dpad_left = false, .pairwise_modifiers = true })
            );
        } else if (inputs.r) {
            set_mode(
                backend,
                new Melee21Button(socd::SOCD_NEUTRAL, { .crouch_walk_os = inputs.up, .mod_z_dpad_left = false, .pairwise_modifiers = false })
            );
        } else if (inputs.left) {
            set_mode(
                backend,
                new ProjectM(
                    socd::SOCD_2IP_NO_REAC,
                    { .true_z_press = false, .ledgedash_max_jump_traj = true, .mod_z_dpad_left = false }
                )
            );
        } else if (inputs.down) {
            set_mode(backend, new Ultimate(socd::SOCD_2IP, { .mod_z_dpad_left = false } ));
        } else if (inputs.right) {
            set_mode(backend, new FgcMode(socd::SOCD_NEUTRAL, socd::SOCD_NEUTRAL));
        } else if (inputs.b) {
            set_mode(backend, new RivalsOfAether(socd::SOCD_2IP, { .mod_z_dpad_left = false } ));
        }
    } else if (inputs.mod_y && !inputs.mod_x && !inputs.mod_z && inputs.start) {
        if (inputs.l) {
            set_mode(backend, new DefaultKeyboardMode(socd::SOCD_2IP));
        }
    }
}

#endif
