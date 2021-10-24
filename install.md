### submodule init
git submodule update --init --recursive


### Linux

First build dependencies
```
# Could not find OpenGL
sudo apt-get install libgl1-mesa-dev


# X11 Xi library is required
sudo apt-get install libx11-dev
sudo apt-get install xorg-dev libglu1-mesa-dev
```


```
mkdir build
cd build

cmake ..
make -j6

cd src
./kuro3d

```