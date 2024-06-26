# Leme Tech One User Guide

* [QuickStart](#quickstart)
* [Playing with 3 modifiers](#playing-with-3-modifiers)
* [2-modifier mode](#2-modifier-mode)
* [Dolphin setup](#dolphin-setup)
* [Controller Behavior](#controller-behavior)
	* [Backends](backends)
	* [Game logic](#game-logic)
* [Layout Reference](#layout-reference)
* [Remapping](#remapping)
* [Reprogramming](#reprogramming)
* [Art layer](#art-layer)

## QuickStart
Your Leme Tech One will automatically work when plugged into any compatible console (GameCube, Wii, Switch, PC), defaulting to Melee-style behavior, as described in [Playing with 3 modifiers](#playing-with-3-modifiers). When plugging into PC for the first time, you will need to do the initial [Dolphin setup](#dolphin-setup) If you wish to play with the 2-modifier layout typical of other controllers with a similar layout, hold ModX and ModY when plugging in.

In either case, hold Up when plugging in to activate the crouch-walk option select coordinates on down-left and down-right.

One addition smashers may enjoy: ModX+ModY+ModZ+Start is mapped to L+R+A+Start. No more awkwardly reaching all across your controller when the T.O. calls for friendlies to stop!

After plugging in, you can change modes without unplugging. This gives access to games modes besides Melee. To change modes, hold the following button combinations.

| Button Hold             | Mode                            |
| ----------------------- | ------------------------------- |
| ModX + Start + L        | Melee (3-mod) (default)         |
| ModX + Start + R        | Melee (2-mod)                   |
| ModX + Start + L/R + Up | Melee 3-mod/2-mod + Crouch Walk |
| ModX + Start + Left     | Project+ / ProjectM             |
| ModX + Start + Down     | Ultimate                        |
| ModX + Start + Right    | FGC Mode (Hitbox-style)         |
| ModX + Start + B        | Rivals of Aether                |

Your Leme Tech One is also compatible with Brook's [Wingman FGC](https://www.brookaccessory.com/products/wingmanfgc/index.html)! To use it, hold Mod X when plugging in, and play your favorite FGC games with the same controller!

See [Controller Behavior](#controller-behavior) for more details about different backends and game modes. 

## Playing with 3 modifiers
Most similar style controllers use only 2 modifiers keys, ModX and ModY. The Leme Tech One has 3, adding ModZ. What's up with that?

Our goal was to simplify angle access for techniques like Firefox while at the same time opening up more options for techniques like wavedashing. To accomplish this, Mod Z was added, and angles are now selected by using one or two modifiers in combination. Contrast this with other similar controllers, where you use one modifier along with a C-stick button.

This results in 7 levels of granularity per quadrant, all of which are easily accessible at all times. Compare this to other controllers, which provide 11 levels of granularity per quadrant with the C-stick, and 3 without it. We believe that using the C-stick for many techniques such as wavedash, while not impossible, is both awkward and more difficult than necessary, and find that the trade-off of a reasonable range of static options is preferable to more options in some situations and fewer options in others.

<p align="center">
    <img src="/img/angles.gif" alt="Angle Helper"/>
</p>

Note that in 3-mod mode, all 3 modifiers should be pressed to access the d-pad layer.

## 2-modifier mode
While this controller offers a new way to play Melee using 3 modifiers with pairwise interaction, some players may wish to use the 2-modifier layout more typical of this style of controller. To achieve this in Melee mode, hold both ModX and ModY when plugging in. You will then find yourself with default 2-modifier behaviour, with ModZ now acting as a dedicated d-pad toggle. This means that ModX and ModY remain availble for use while the d-pad layer is active.

If you are already plugged in and wish to switch to 2-modifier Melee mode, hold ModX + Start + R. See [Game Logic](#Game-logic) for a full table of mode selection options.

Note that if you want to use 2-modifier mode, Mod Z can be used as an additional button for whatever you want! For example, you could put one of your jump buttons on the thumb to help with techniques like Peach's hyperfloats. See [Remapping](#remapping) for more information.

Additionally, any 2-modifier players that are also avid UnclePunch users may be happy to know that holding all 3 modifiers when plugging in will result in 2-modifier behaviour with ModZ acting as a dedicate D-pad left. In this mode, press all 3 modifiers to access the D-pad layer, like you would in 3-mod mode.

## Dolphin setup
Your Leme Tech One, being based on HayBox, needs a Dolphin controller profile to be setup for use. These profiles can be found in the dolphin folder in this repo or along with the latest release. The profile files are named to indicate what communication backend and operating system they are for. You should use XInput if possible, only using DInput if XInput doesn't work for your game or system:

* For Windows:
    * HayBox_XInput.ini
    * HayBox_DInput.ini
* For Linux:
    * HayBox_XInput_Linux.ini
    * HayBox_DInput_Linux.ini
* For macOS (unsupported\*):
    * HayBox_DInput_macOS.ini

To install the profile:

1) Copy the appropriate .ini file to the folder <YourDolphinInstallation>\User\Config\Profiles\GCPad\ (create it if it does not exist)
* For Slippi this should be
    * On Windows: %appdata%\Slippi Launcher\netplay\User\Config\Profiles\GCPad\
    * On Linux: ~/.config/SlippiOnline/Config/Profiles/GCPad/
    * On Mac: Cmd + Shift + G and enter the path /Users/<USER>/Library/Application Support/Slippi Launcher/netplay/Slippi Dolphin.app/Contents/Resources/Sys/Config/Profiles/GCPad
* For vanilla Dolphin:
    * On Windows: %userprofile%\Documents\Dolphin Emulator\Config\Profiles\GCPad\
    * On Linux: ~/.config/dolphin-emu/Profiles/GCPad/
2) Plug in your controller, and configure a "Standard Controller" in Dolphin
3) Click Refresh next to the Device dropdown
4) Select the HayBox profile from the profile dropdown, and click Load (NOT Save)
5) Make sure the correct device is selected in the device dropdown
6) Click Close
* macOS only supports DInput (and not very well), so you will have to force DInput mode by holding Z on plugin, and even then it may not work. It may work, but this will be considered unsupported usage.

## Controller behavior
There are multiple modes in which the controller can be used, as well as various options within many of the modes. There are two aspects to this:
1) Game logic. This determines the kinds of outputs your controller will send. e.g. Melee vs. P+ vs. Ultimate vs. FGC (hitbox-style) vs. keyboard outputs
2) Backend. This determines how your controller will send its inputs to the console.
### Backends
In most cases, your controller will automatically determine which backend mode to use. See the table below for full information on the backend your controller will use in various scenarios, and when you might want to override it.

| Console                       | Button Hold | Backend         | Reason                                                                        |
| ----------------------------- | ----------- | --------------- | ----------------------------------------------------------------------------- |
| Wii                           | -           | GameCube        | default, best in most cases                                                   |
| GameCube                      | -           | GameCube        | default, best in most cases                                                   |
| Switch (adapter)              | -           | GameCube        | default, best in most cases                                                   |
| Switch<br>(direct USB)        | X           | Switch USB mode | Plugging directly into Switch USB (also sets controller behavior to Ultimate) |
| N64                           | -           | N64             | default, best in most cases                                                   |
| PC                            | -           | XInput          | default, best for most games                                                  |
| PC                            | Z           | DInput          | XInput doesn't work for your game                                             |
| PS5/PS4/etc.<br>(Wingman FGC) | Mod X       | Switch USB mode | Using Wingman FGC to play on other consoles (sets the controller to FGC mode) |

### Game logic
Your Leme Tech One will automatically work when plugged into any compatible console (GameCube, Wii, Switch, PC), defaulting to Melee-style behavior, as described in [Playing with 3 modifiers](#playing-with-3-modifiers). If you wish to play with the 2-modifier layout typical of other controllers with a similar layout, hold ModX and ModY when plugging in.

In either case, hold Up when plugging in to activate the crouch-walk option select coordinates on down-left and down-right.

After plugging in the controller, use the following button holds to switch between game modes.

| Button Hold             | Mode                                         |
| ----------------------- | -------------------------------------------- |
| ModX + Start + L        | Melee (3-mod) (default)                      |
| ModX + Start + R        | Melee (2-mod)                                |
| ModX + Start + L/R + Up | Melee 3-mod/2-mod + Crouch Walk              |
| ModX + Start + Left     | Project+ / ProjectM                          |
| ModX + Start + Down     | Ultimate                                     |
| ModX + Start + Right    | FGC Mode (Hitbox-style)                      |
| ModX + Start + B        | Rivals of Aether                             |
| ModY + Start            | Keyboard (controller must be in DInput mode) |

## Layout Reference
Standard:
<p align="center">
    <img src="/img/lemetechonelayout.png" alt="Standard Layout" width="480"/>
</p>
FGC:
<p align="center">
    <img src="/img/lemetechonelayoutFGC.png" alt="FGC Layout" width="480"/>
</p>

## Remapping
Remapping can be achieved by downloading the code, changing the mappings in `config/lemetechone/config.cpp`, building the firmware, and then following the instructions in [Reprogramming](#reprogramming). Instructions for building the firmware can be found [in the README](README.md#building-from-source).

If you do not feel comfortable doing this, please reach out and we will assist to the best of our ability, up to and including building you a custom version of the firmware with your preferred layout. We intend to improve this experience in the future.

## Reprogramming

Your Leme Tech One is compatible with other open source firmware, including Arte's [pico-rectangle](https://github.com/JulienBernard3383279/pico-rectangle) and Haystack's [Haybox](https://github.com/JonnyHaystack/HayBox). The [Leme Tech One firmware](https://github.com/prilosac/LemeTechOne-Firmware) is based on Haybox.

To reprogram your controller, hold Start when plugging in. This will put your device in bootsel mode, ready to accept a file. On a Windows PC, drag your preferred .uf2 file to the RPI-RP2 device that appears. Your controller should disconnect and reconnect, and then you're done!

Make sure you know what you are uploading to your controller to prevent any unexpected issues. If you do encounter any issues, please reach out via our contact form on our website and we will help to the best of our ability.

# Art layer

<p align="center">
    <img src="/img/artandglossymattedisplay.png" alt="Art Example" width="480"/>
</p>

Your Leme Tech Zero features a clear top insert that can optionally act as a customizable art layer! Loosen the 5 bolts with a 3mm hex wrench, lift the clear panel, and place any art you desire under it before completing the steps in reverse to put it back.

Be aware that the bolts go all the way through to the bottom of the case and connect with nuts to hold the bottom plate in place too, so don't be alarmed if the bottom panel shifts slightly while you do this. Make sure to slot the nuts back through the bottom panel to ensure a snug fit before re-tightening.

The following templates can be used to help plan out artwork without having to do so on the controller itself. If printed full-size on a sheet of 8.5" x 11" paper, these templates will line up real-size with the controller. Unfortunately this means the template had to be split in two since the controller is a bit larger than regular printer paper. We recommend one of two options:
1) Since each template still covers the majority of the controller, fit all your art within one of the templates and use just that one
2) Print both templates and line them up as best you can to get a full view of the controller

Once you have your printed template(s), use it to plan your art before placing it under your controller's art layer

<p align="center">
    <img src="/img/arttemplate1.png" alt="Art Template 1" />
</p>
<p align="center">
    <img src="/img/arttemplate2.png" alt="Art Template 2" />
</p>

