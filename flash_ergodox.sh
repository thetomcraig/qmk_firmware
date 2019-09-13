set -e
# Setup left
echo "Get sudo password saved"
# sudo ls

echo "PUT KB INTO FLASH MODE"
make ergodox_ez:${1}
# sudo make ergodox_ez:${1}:teensy
# ./teensy_loader_cli -w --mcu atmega32u4 ergodox_ez_${1}.hex
