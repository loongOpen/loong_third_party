#!/bin/bash
mv /usr/aarch64-linux-gnu/lib/ld-linux-aarch64.so.1 /usr/aarch64-linux-gnu/lib/ld-linux-aarch64.so.1.bak
mv /usr/aarch64-linux-gnu/lib/libc.so.6 /usr/aarch64-linux-gnu/lib/libc.so.6.bak
mv /usr/aarch64-linux-gnu/lib/libstdc++.so.6 /usr/aarch64-linux-gnu/lib/libstdc++.so.6.bak
mv /usr/aarch64-linux-gnu/lib/libpthread.so.0 /usr/aarch64-linux-gnu/lib/libpthread.so.0.bak
cp *so* /usr/aarch64-linux-gnu/lib/