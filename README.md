# PicoLisp/8110

This is a port of PicoLisp distribution to Nokia 8110 4G and other Qualcomm 205 based phones.

Note this only reflects the initial state of the repo and should be used to compile binary part. CSS part will be updated as part of Pris System repo.

## Building

1. Get Android NDK **Revision 15c** (nothing newer!!!) for your platform [from here](https://developer.android.com/ndk/downloads/older_releases).
2. Unpack and modify lines 156 and 157 in the `build/tools/make_standalone_toolchain.sh` in the unpacked `android-ndk-r15c` directory to this:
```
run python `dirname $0`/make_standalone_toolchain.py \
    --deprecated-headers --arch $ARCH $PLATFORM_ARG --stl $STL $INSTALL_ARG $FORCE_ARG
```
(essentially adding the `--deprecated-headers` string)
3. Build the toolchain (I used `~/Downloads/toolchain15` as the target directory):
```
cd android-ndk-r15c
build/tools/make-standalone-toolchain.sh --toolchain=arm-linux-androideabi-4.8 --platform=android-21 --install-dir=../toolchain15
```
4. Modify the `src/Makefile` in the PicoLisp project to have `CC` and `CCLD` equal to your toolchain gcc path (in this example, it's `~/Downloads/toolchain15/bin/arm-linux-androideabi-gcc`).
5. Copy libcrypto and libssl from your device:
```
adb pull /system/lib/libcrypto.so ~/Downloads/toolchain15/sysroot/usr/lib/
adb pull /system/lib/libssl.so ~/Downloads/toolchain15/sysroot/usr/lib/
```
6. Enter the `src` directory and run `make`.
7. Verify the `bin/picolisp` file type with `file ../bin/picolisp`. It should say: `ELF 32-bit LSB pie executable ARM, EABI5 version 1 (SYSV), dynamically linked, interpreter /system/bin/linker, stripped`
8. Copy the entire distribution (except `src` directory) to `/vendor/picolisp` directory on the device. Place `bin/pil` to `/vendor/bin/pil` and make both it and `/vendor/picolisp/bin/picolisp` files executable. If you copy it to another place, adjust `pil` launcher accordingly.
