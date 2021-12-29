### submodule init
git submodule update --init --recursive


### Linux

First build dependencies on linux
```
# Could not find OpenGL
sudo apt-get install libgl1-mesa-dev

# X11 Xi library is required
sudo apt-get install xorg-dev
```


### Mac
First build dependencies on mac
```
No dependency needed
```


```
mkdir build
cd build

cmake ..
make -j6

cd src
./kuro3d
```


### Windows



### TODO: NOTE
build one specific target e.g.: cmake --build . --target atom