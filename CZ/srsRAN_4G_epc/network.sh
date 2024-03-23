cd srsepc
sudo ./srsepc_if_masq.sh wlp0s20f3
sudo sysctl net.ipv4.conf.all.forwarding=1
sudo iptables -P FORWARD ACCEPT
sudo iptables -t nat -A POSTROUTING -o wlp0s20f3 -j MASQUERADE
