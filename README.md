srsRAN UDP
1.ԭ��
��IP:����IPv4��ifconfig�� PORT��1111-8888


2.UDP�ļ����ɽ��ж������ԣ�
����
cd srsRAN_2024
g++ test_send.cc -o send
g++ test_route.cc -o route
g++ test_route_2.cc -o route_2
g++ test_receive.cc -o rec
���У�4���նˣ�
cd srsRAN_2024
./send
./route
./route_2
./rec

3.srsRAN+UDP
����srsRAN(��һ�α������½�build��
cd srsRAN_2024
bash ./complie.sh

����UDP route
cd srsRAN_2024
g++ test_route.cc -o route
g++ test_route_2.cc -o route_2

����Ҫ����UDP route
cd srsRAN_2024
./route
�ڶ����ն�
cd srsRAN_2024
./route_2

������srsRAN����Ȼ�Ῠס
cd srsRAN_2024
sudo bash ./go.sh 

�ֻ������Ϻ��¿��ն�
cd srsRAN_2024
bash ./network.sh

���н�ͼ
srsepc

srsenb


route01


route02


