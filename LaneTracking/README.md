### Prerequisites

g++>=7.5.0,C++17,cmake==3.10.2

## 🔧 Running the shell file <a name = "run.sh"></a>

cd to the directory of run.sh

bash run.sh

cd build/

./Inference

### data and model

model put in ./model

data put in ./data and end with ".jpg"

### install openCV3.2.0
sudo apt-get install libopencv-dev python-opencv

### if unable to install openCV, add source and try again

### open source.list
sudo vim /etc/apt/sources.list 

### add Tsinghua source:
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic main restricted universe multiverse
deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-updates main restricted universe multiverse
deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-updates main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-backports main restricted universe multiverse
deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-backports main restricted universe ultiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-security main restricted universe multiverse
deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-security main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-proposed main restricted universe multiverse
deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-proposed main restricted universe ultiverse

### update
apt-get update
apt-get upgrade

