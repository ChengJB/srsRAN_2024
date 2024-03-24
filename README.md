# srsRAN UDP(待更新）

## UDP文件（可进行独立测试）

### 编译

```
cd srsRAN_2024
g++ test_send.cc -o send
g++ test_route.cc -o route
g++ test_route_2.cc -o route_2
g++ test_receive.cc -o rec
```



### 运行（4个终端）

```
cd srsRAN_2024
./send
./route
./route_2
./rec
```



## srsRAN+UDP

### 编译srsRAN(第一次编译需新建build）

```
cd srsRAN_2024
bash ./complie.sh
```



### 编译UDP route

```
cd srsRAN_2024
g++ test_route.cc -o route
g++ test_route_2.cc -o route_2
```



### 首先要运行UDP route

```
cd srsRAN_2024
./route
```



### 第二个终端

```
cd srsRAN_2024
./route_2
```



### 再运行srsRAN

```
cd srsRAN_2024
sudo bash ./go.sh 
```



### 手机连接上后，新开终端

```
cd srsRAN_2024
bash ./network.sh
```

