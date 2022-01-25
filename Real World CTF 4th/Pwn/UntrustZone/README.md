Pwn, difficulty:normal

It is clearly not worth your trust.

The default username is root.

nc 47.243.205.105 8899
attachment

The start script of challenge

qemu-system-aarch64 \
        -nographic \
        -smp 2 \
        -machine virt,secure=on,gic-version=3,virtualization=false \
        -cpu cortex-a57 \
        -d unimp -semihosting-config enable=on,target=native \
        -m 1024 \
        -bios bl1.bin \
        -initrd rootfs.cpio.gz \
        -kernel Image -no-acpi \
        -append console="ttyAMA0,38400 keep_bootcon root=/dev/vda2  -object rng-random,filename=/dev/urandom,id=rng0 -device virtio-rng-pci,rng=rng0,max-bytes=1024,period=1000" \
        -netdev user,id=vmnic -device virtio-net-device,netdev=vmnic \
        -no-reboot \
        -monitor null