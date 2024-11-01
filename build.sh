#!/usr/bin/env bash

# Make sure ~/qmk_firmware exists to be usable

[ -d ~/qmk_firmware ] || exit 1

# all the custom keyboard needs to be copied/overwrite to ~/qmk_firmware/keyboards/
for keyboard in ./custom/*; do
    rsync -av --delete "$keyboard" ~/qmk_firmware/keyboards/
done
