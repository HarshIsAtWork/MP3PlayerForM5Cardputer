# PlatformIO Layout

This firmware is now structured as a PlatformIO project.

## Tree

```text
.
|-- include/
|   `-- theme_manager.h
|-- src/
|   |-- main.cpp
|   `-- theme_manager.cpp
|-- legacy/
|   |-- MP3PlayerM5Cardputer.ino
|   `-- handlefile.h
`-- platformio.ini
```

## Notes

* `src/` contains the active firmware sources.
* `include/` contains shared headers used by the firmware.
* `legacy/` keeps the original Arduino sketch files for reference only.
* `platformio.ini` defaults to the `m5stack-stamps3` environment.

## Build

```bash
pio run -e m5stack-stamps3
```

## Output

After a successful build, the flashable image will be written to:

```text
.pio/build/m5stack-stamps3/firmware.bin
```
