# loopever
Just loop forever, with sleep for specified time

# Build & Install
```
$ mkdkir build
$ cd build
$ cmake ..
$ make
$ make install
```

# Run
```
$ loopever # Just loop forever. No sleep.
$ loopever 0 # Sleep for 0 second per loop
$ loopever 1 # Sleep for 1 second per loop
$ loopever 0 1 # Sleep for 1 nano second per loop
```
