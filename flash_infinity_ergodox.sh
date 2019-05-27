set -e
# Setup left
echo "Get sudo password saved"
sudo ls

echo "Plug in LEFT"
echo "PUT LEFT SIDE INTO FLASH MODE"
sleep 12

# Flash left!
make ergodox_infinity:${1}
sudo make ergodox_infinity:${1}:dfu-util
echo "Unplug, LEFT, plugin in RIGHT"
echo "PUT RIGHT SIDE INTO FLASH MODE"

# Flash right!
make ergodox_infinity:${1} MASTER=right
sudo make ergodox_infinity:${1}:dfu-util MASTER=right
