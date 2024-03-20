gnome-terminal -t "srsepc" -x bash -c "cd srsepc;sudo srsepc epc.conf;exec bash;"
gnome-terminal -t "srsenb" -x bash -c "cd srsenb;sudo srsenb enb.conf;exec bash;"


